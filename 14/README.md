## Задания
Используя системные вызовы [fork](https://cmmshq.ru/repos/spc/man/man2/fork.2.html), [pipe](https://cmmshq.ru/repos/spc/man/man2/pipe.2.html), [dup](https://cmmshq.ru/repos/spc/man/man2/dup.2.html) и [execvp](https://cmmshq.ru/repos/spc/man/man3/execvp.3.html), напишите свою программуоболочку. Эта программа должна функционировать аналогично стандартной оболочке ```/bin/sh``` и позволять:
* запустить любую команду (исполняемый файл из файловой системы) и
* перенаправить вывод одной команды на вход другой.
Циклы, ветвления, переменные, функции и другие сложные конструкции делать не
нужно.



## Как запустить:
1. cd "/path_to_folder_with_choosen_task"
2. meason .build
3. cd .build
4. ninja
5. src/myproject/myproject
