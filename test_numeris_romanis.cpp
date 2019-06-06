
#include "numeris_romanis.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

using namespace rom::literals_numerorum;

// Addition
static_assert("MCMLXXXVIII"_r + "XII"_r == "MM"_r);

// Subtraction
static_assert("MCMLXXXVIII"_r - "XXIV"_r == "MCMLXIV"_r);

// Multiplication
static_assert("C"_r * "IV"_r == "CD"_r);

// Division
static_assert("CCCLX"_r / "XXIV"_r == "XV"_r);

// Modulus
static_assert("XV"_r % "IV"_r == "III"_r);

// Comparisons
static_assert("M"_r < "MI"_r);
static_assert("V"_r <= "VIII"_r);
static_assert("M"_r > "C"_r);
static_assert("X"_r >= "X"_r);
static_assert("MIII"_r != "M"_r);

// Conversion from arabic numerals
static_assert(2019_r == "MMXIX"_r);
static_assert("MMXIX"_r == 2019);

int main()
{
    constexpr auto r = 1985_r;
    std::ostringstream oss;
    oss << r;
    assert(oss.str() == "MCMLXXXV");
}