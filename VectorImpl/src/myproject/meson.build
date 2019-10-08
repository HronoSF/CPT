myproject_src = files([
    'Vector.h',
    'Vector.hxx',
    'TestWithStreams.cpp'
])
executable(
    'myproject',
    include_directories: src, # где ищутся заголовочные файлы
    sources: myproject_src, # список исходный файлов
    dependencies: [], # зависимости проекта (если имеются)
    install: true # устанавливать ли файл
)