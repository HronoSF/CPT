#include "../headers/Shell.hxx"

std::vector<pid_t> pids;

void handle(int signals) {
    int status;
    pid_t pid;
    assert (signals == SIGCHLD);
    pid = waitpid(-1, &status, WNOHANG);
    pids.erase(remove(pids.begin(), pids.end(), pid), pids.end());
}

void Shell::execute(bool usr_prompt) {
    while (run) {
        size = 8;
        cmd = new char *[size];
        cmd_num = 0;
        in = dup(0);
        out = dup(1);
        isPipe = false;
        redirect = false;
        bg_process = false;

        for (int i = 0; i < size; i++) {
            cmd[i] = nullptr;
        }

        time_t curr_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string dir = getcwd(curr_dir, 255);
        cout << "\033[1;31m[ " + usr + "@" + " ] " + ctime(&curr_time) + ">> \033[0m";

        getline(cin, input_command);
        tokens = tokenizer.tokenize(input_command);
        if (tokens[0] == "exit") {
            cout << "Quitting shell...\n";
            run = false;
        } else if (tokens[0] == "cd") {
            change_dir(tokens);
        }
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "<") {
                redirect_input(i);
            } else if (tokens[i] == ">") {
                redirect_output(i);
            } else if (tokens[i] == "&") {
                bg_process = true;
            } else {
                char *seg = line_to_char_array(tokens[i]);
                cmd[cmd_num++] = seg;
            }
        }
        cmd[cmd_num] = nullptr;
        dup2(out, 1);
        if (close(out) < 0) {
            perror("close");
        }
        pid = fork();
        if (pid == 0) {
            execvp(cmd[0], cmd);
        } else if (pid < 0) {
            perror("fork");
        } else {
            bg_handler();
            if (isPipe || redirect) {
                if (close(pipefd[0]) < 0) {
                    perror("close");
                }
            }
            cmd_num = 0;
            delete[] cmd;
        }
        dup2(in, 0);
        if (close(in) < 0) {
            perror("close");
        }
    }
}

void Shell::redirect_input(int i) {
    cmd[cmd_num] = nullptr;
    if (cmd_num < tokens.size() - 2) {
        pipe(pipefd);
    }
    pid = fork();
    if (pid == 0) {
        int fds = open(tokens[++i].c_str(), O_RDONLY, 0);
        dup2(fds, STDIN_FILENO);
        if (close(fds) < 0) {
            perror("close");
        }
        if (i < tokens.size() - 2) {
            dup2(pipefd[1], 1);
            if (close(pipefd[0]) < 0) {
                perror("close");
            }
        }
        execvp(cmd[0], cmd);
    } else if (pid < 0) {
        perror("fork");
    } else {
        status = waitpid(pid, nullptr, WUNTRACED);
        if (i < tokens.size() - 2) {
            if (close(pipefd[1]) < 0) {
                perror("close");
            }
            dup2(pipefd[0], 0);
        }
    }
    redirect = true;
    clear(cmd, cmd_num);
}

void Shell::redirect_output(int i) {
    if (close(1) < 0) {
        perror("close");
    }
    cmd[cmd_num] = nullptr;
    FILE *file;
    file = fopen(tokens[++i].c_str(), "w");
    pid = fork();
    if (pid == 0) {
        execvp(cmd[0], cmd);
    } else if (pid < 0) {
        perror("fork");
    } else {
        bg_handler();
    }
    fclose(file);
    clear(cmd, cmd_num);
}

void Shell::change_dir(vector<string> command) {
    current_dir = getcwd(curr_dir, 255);
    if (command.size() == 1) {
        return;
    } else if (command[1] == "..") {
        if (current_dir.find_last_of('/') != '\0') {
            current_dir = string(curr_dir).substr(0, current_dir.find_last_of('/'));
        }
    } else if (command[1].find('/') == 0) {
        current_dir = command[1];
    } else {
        current_dir = current_dir + "/" + command[1];
    }
    chdir(current_dir.c_str());
}

void Shell::bg_handler() {
    if (!bg_process) {
        status = waitpid(pid, nullptr, WUNTRACED);
    } else {
        pids.push_back(pid);
        signal(SIGCHLD, handle);
    }
}

void Shell::clear(char **&cmd, int &cmd_num) {
    char **temp = new char *[size];
    delete[] cmd;
    cmd_num = 0;
    cmd = temp;
}

char *Shell::line_to_char_array(string line) {
    char *arr = new char[line.size() + 1];
    for (int i = 0; i < line.size(); i++) {
        arr[i] = line[i];
    }
    arr[line.size()] = '\0';
    return arr;
}
