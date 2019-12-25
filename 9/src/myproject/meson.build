src_8 = files([
    '8/main.cpp' # список исходных файлов
])

python = dependency('python')
threads = dependency('threads')

executable(
    'task_8', #название исполняемого файла
    include_directories: src, # список исходных файлов
    sources: src_8,
    dependencies: [python,threads], # завистиости проекта
    install: true, # устанавливать ли файлы
)
