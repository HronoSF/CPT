gtest = dependency('gtest', main: true)

test(
    'MyMatrixTestWhereMethodDataProvider',
    executable(
        'MyMatrixTestWhereMethodDataProvider',
        sources: ['MyMatrixTestWhereMethodDataProvider.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)

test(
    'MyMatrixTestIsSymmetricMethodDataProvider',
    executable(
        'MyMatrixTestIsSymmetricMethodDataProvider',
        sources: ['MyMatrixTestIsSymmetricMethodDataProvider.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)

test(
    'GuardTest',
    executable(
        'GuardTest',
        sources: ['GuardTest.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)