#include "headers/Shell.hxx"

int main(int argc, char **argv) {
    Shell my_shell;
    bool usr_prompt = true;
    int i = 0;
    while (argv[i] != nullptr) {
        i++;
    }
    my_shell.execute(usr_prompt);
}