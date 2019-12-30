 gtest = dependency('gtest', main: true)
test(
    'Geometry',
    executable(
        'Geometry_test',
        sources: ['GeometryFiguresTest.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'Polynomial',
    executable(
        'Polynomial_test',
        sources: ['PolynomialTest.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)