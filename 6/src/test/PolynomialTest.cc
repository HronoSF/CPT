#include "gtest/gtest.h"
#include "../myproject/Polynomial.h"
#include <complex>

TEST(POLYNOMIAL, CONSTRUCTOR_TEST) {
    Polynomial<int> p(1, 2);

    EXPECT_EQ(1, p.getArg(0));
    EXPECT_EQ(2, p.getArg(1));
}

TEST(POLYNOMIAL, MULTIPLY_TEST) {
    Polynomial<int> p(1, 2);
    p.multiply(2);

    EXPECT_EQ(2, p.getArg(0));
    EXPECT_EQ(4, p.getArg(1));
}

TEST(POLYNOMIAL, SCHUR_TEST) {
    Polynomial<int> p(1, 2, 3);

    Polynomial<int> schurPoly = schurTransform(std::move(p));

    EXPECT_EQ(schurPoly.getArg(0), 0);
    EXPECT_EQ(schurPoly.getArg(1), 4);
    EXPECT_EQ(schurPoly.getArg(2), 8);
}

TEST(POLYNOMIAL, COMPLEX_NUMBERS_TEST) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);

    std::complex<double> conjFirst = std::conj(first);
    std::complex<double> conjSecond = std::conj(second);

    EXPECT_EQ(std::real(conjFirst), std::real(first));
    EXPECT_EQ(std::imag(conjFirst), -1 * std::imag(first));
    EXPECT_EQ(std::real(conjSecond), std::real(second));
    EXPECT_EQ(std::imag(conjSecond), -1 * std::imag(second));

    std::complex<double> multi = first * second;
    EXPECT_EQ(std::real(multi), 0);
    EXPECT_EQ(std::imag(multi), 4);
}

TEST(POLYNOMIAL, SCHUR_2COMPLEX_TEST) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);

    Polynomial<std::complex<double>> p =
            Polynomial<std::complex<double>>(first, second);

    Polynomial<std::complex<double>> schurPoly = schurTransform(p);

    EXPECT_EQ(std::real(schurPoly.getArg(0)), 0);
    EXPECT_EQ(std::imag(schurPoly.getArg(0)), 0);
    EXPECT_EQ(std::real(schurPoly.getArg(1)), 6);
    EXPECT_EQ(std::imag(schurPoly.getArg(1)), 0);
}

TEST(POLYNOMIAL, SCHUR_3COMPLEX_TEST) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);
    std::complex<double> third = std::complex<double>(3, 3);

    Polynomial<std::complex<double>> p =
            Polynomial<std::complex<double>>(first, second, third);

    Polynomial<std::complex<double>> schurPoly = schurTransform(p);

    EXPECT_EQ(std::real(schurPoly.getArg(0)), 0);
    EXPECT_EQ(std::imag(schurPoly.getArg(0)), 0);
    EXPECT_EQ(std::real(schurPoly.getArg(1)), 8);
    EXPECT_EQ(std::imag(schurPoly.getArg(1)), 0);
    EXPECT_EQ(std::real(schurPoly.getArg(2)), 16);
    EXPECT_EQ(std::imag(schurPoly.getArg(2)), 0);
}
