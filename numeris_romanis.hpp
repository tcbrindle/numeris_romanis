/*
Copyright MMXIX Tristan Brindle

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in the
Software without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef NUMERIS_ROMANIS_HPP_INCLUDED
#define NUMERIS_ROMANIS_HPP_INCLUDED

#include <iosfwd>
#include <string>
#include <string_view>

namespace rom {

struct numerus {
private:
    static inline constexpr struct {
        unsigned value; std::string_view symbol;
    } symbol_table[] {
        { 1000, "M" },
        { 900, "CM" },
        { 500, "D" },
        { 400, "CD" },
        { 100, "C" },
        { 90, "XC" },
        { 50, "L" },
        { 40, "XL" },
        { 10, "X" },
        { 9, "IX" },
        { 5, "V" },
        { 4, "IV" },
        { 1, "I"}
    };

public:
    constexpr numerus(unsigned long long value)
        : val_(value)
    {}

    constexpr numerus& operator+=(numerus n) { val_ += n.val_; return *this; }
    constexpr numerus& operator-=(numerus n) { val_ -= n.val_; return *this; }
    constexpr numerus& operator*=(numerus n) { val_ *= n.val_; return *this; }
    constexpr numerus& operator/=(numerus n) { val_ /= n.val_; return *this; }
    constexpr numerus& operator%=(numerus n) { val_ %= n.val_; return *this; }

    static constexpr numerus ab_filum(std::string_view str)
    {
        unsigned long long val = 0;

        constexpr auto starts_with = [](std::string_view str1, std::string_view str2) {
            return str1.size() >= str2.size() && str1.compare(0, str2.size(), str2) == 0;
        };

        while (!str.empty()) {
            for (const auto& [value, symbol] : symbol_table) {
                if (starts_with(str, symbol)) {
                    val += value;
                    str.remove_prefix(symbol.size());
                    break;
                }
            }
        }
        return {val};
    }

    std::string ad_filum() const
    {
        std::string out{};
        auto i = val_;
        while (i > 0) {
            for (const auto& [value, symbol] : symbol_table) {
                if (i >= value) {
                    out += symbol;
                    i -= value;
                    break;
                }
            }
        }
        return out;
    }

    explicit operator std::string() const { return ad_filum(); }

    constexpr explicit operator unsigned long long() const { return val_; }

private:
    friend constexpr bool operator==(numerus lhs, numerus rhs) { return lhs.val_ == rhs.val_; }
    friend constexpr bool operator!=(numerus lhs, numerus rhs) { return !(lhs == rhs); }
    friend constexpr bool operator<(numerus lhs, numerus rhs) { return lhs.val_ < rhs.val_; }
    friend constexpr bool operator>(numerus lhs, numerus rhs) { return lhs.val_ > rhs.val_; }
    friend constexpr bool operator<=(numerus lhs, numerus rhs) { return lhs.val_ <= rhs.val_; }
    friend constexpr bool operator>=(numerus lhs, numerus rhs) { return lhs.val_ >= rhs.val_; }

    friend constexpr numerus operator+(numerus n) { return n; }
    friend constexpr numerus operator+(numerus lhs, numerus rhs) { return lhs += rhs; }
    friend constexpr numerus operator-(numerus lhs, numerus rhs) { return lhs -= rhs; }
    friend constexpr numerus operator*(numerus lhs, numerus rhs) { return lhs *= rhs; }
    friend constexpr numerus operator/(numerus lhs, numerus rhs) { return lhs /= rhs; }
    friend constexpr numerus operator%(numerus lhs, numerus rhs) { return lhs %= rhs; }

    friend std::ostream& operator<<(std::ostream& os, numerus n)
    {
        os << n.ad_filum();
        return os;
    }

    unsigned long long val_;
};

inline namespace literals_numerorum {

    constexpr numerus operator"" _r(unsigned long long value)
    {
        return {value};
    }

    constexpr numerus operator"" _r(const char* str, std::size_t n)
    {
        return numerus::ab_filum({str, n});
    }
}

} // namespace rom

#endif
