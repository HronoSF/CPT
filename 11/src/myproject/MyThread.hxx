#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <csignal>
#include <system_error>
#include <functional>

#define STACK_SIZE 1024*1024
#define CHECK(fun) \
    if((fun) == -1) { \
        throw std::system_error(errno, std::generic_category()); \
    }

int thread_helper(void *ptr) {
    auto *fun = static_cast<std::function<int()> *>( ptr);
    (*fun)();
    return 0;
}

class my_thread {
protected:
    int pid;
    char *stack;
    char *stackTop;

public:
    my_thread() {
        pid = 0;
    };

    my_thread(int (*fun)(void *args)) {
        stack = new char[STACK_SIZE];
        stackTop = stack + STACK_SIZE;
        CHECK(pid = clone(fun, stackTop, CLONE_VM | CLONE_FS | CLONE_FILES
                                         | CLONE_SIGHAND | SIGCHLD, nullptr));
    }

    my_thread(std::function<int()> &&fun) {
        stack = new char[STACK_SIZE];
        stackTop = stack + STACK_SIZE;
        CHECK(pid = clone(thread_helper, stackTop, SIGCHLD, &fun));
    }


    pid_t get_id() { return pid; }

    bool joinable() {
        return pid != 0 && kill(pid, 0) == 0;
    }

    void join() {
        int status;
        CHECK(waitpid(pid, &status, 0));
    }

    my_thread &operator=(my_thread &&thd) noexcept {
        this->swap(thd);
        return *this;
    }

    void swap(my_thread &thd) {
        std::swap(this->pid, thd.pid);
        std::swap(this->stack, thd.stack);
    }

    ~my_thread() {
        if (pid != 0) {
            kill(pid, SIGTERM);
            delete[] stack;
        }
    }
};