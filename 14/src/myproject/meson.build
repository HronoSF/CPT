myproject_src = files([
    'main.cpp',
    'sources/Shell.cpp',
    'sources/Tokenizer.cpp',
    'headers/Shell.hxx',
    'headers/Tokenizer.hxx'
])
executable(
    'myproject',
    include_directories: src, # где ищутся заголовочные файлы
    sources: myproject_src, # список исходный файлов
    dependencies: [], # зависимости проекта (если имеются)
    install: true # устанавливать ли файл
)