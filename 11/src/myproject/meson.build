myproject_src = files([
    'main.cpp' # список исходных файлов
])

python = dependency('python')
threads = dependency('threads')

executable(
    'myproject', #название исполняемого файла
    include_directories: src, # список исходных файлов
    sources: myproject_src,
    dependencies: [python,threads], # завистиости проекта
    install: true, # устанавливать ли файлы
)