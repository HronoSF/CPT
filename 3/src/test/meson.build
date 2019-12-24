gtest = dependency('gtest', main: true)
test(
    'MyMessage',
    executable(
        'MyMessage_test',
        sources: ['MyMessageTest.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'MyCat',
    executable(
        'MyCat_test',
        sources: ['MyCatTest.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'MyTie',
    executable(
        'MyTie_test',
        sources: ['MyTieTest.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)