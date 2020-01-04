#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <system_error>

#define CHECK(fun) \
    if((fun) == -1) { \
        throw std::system_error(errno, std::generic_category()); \
    }

class my_thread {
protected:
    pid_t pid;
    size_t stackSize;
    char *childStack;
    void *childStackEnd;

public:

    my_thread(int (*fun)(void *args)) {
        stackSize = 1024 * 10;
        childStack = new char[stackSize];
        childStackEnd = childStack + stackSize;;
        CHECK(pid = clone(fun, childStackEnd, CLONE_VM | CLONE_FS | CLONE_FILES
                                              | CLONE_SIGHAND | SIGCHLD, nullptr));
    }

    pid_t get_id() { return pid; }

    bool joinable() {
        return pid > 0 && kill(pid, 0) == 0;
    }

    void join() {
        int status = 0;
        CHECK(waitpid(pid, &status, 0));
    }

    my_thread &operator=(my_thread &&thd) noexcept {
        this->swap(thd);
        return *this;
    }

    void swap(my_thread &thd) {
        pid_t newPid = thd.pid;
        thd.pid = pid;
        pid = newPid;
    }

    ~my_thread() {
        kill(pid, SIGTERM);
        delete[] childStack;
    }

};