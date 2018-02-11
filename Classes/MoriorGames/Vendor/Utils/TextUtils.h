#ifndef MORIOR_GAMES_VENDOR_UTILS_TEXT_UTILS_H
#define MORIOR_GAMES_VENDOR_UTILS_TEXT_UTILS_H

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <locale.h>

template<class T>
std::string float_to_string(const T &t)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << t;

    return stream.str();
}

template<class T>
std::string to_string(const T &t)
{
    std::ostringstream os;
    os << t;

    return os.str();
}

template<class T>
const char *string_to_const_char(const T &t)
{
    const char *c = t.c_str();

    return c;
}

template<class T>
std::string to_roman(const T value)
{
    std::string result;
    int val = (int) value;

    struct romandata_t
    {
        unsigned int value;
        char const *numeral;
    };
    const struct romandata_t romandata[] =
        {
            {1000, "M"}, {900, "CM"},
            {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"},
            {1, "I"},
            {0, NULL} // end marker
        };

    for (const romandata_t *current = romandata; current->value > 0; ++current) {
        while (val >= current->value) {
            result += current->numeral;
            val -= current->value;
        }
    }
    return result;
}

template<class T>
std::string to_upper(const T &t)
{
    std::string toUpper = to_string(t);
    std::transform(toUpper.begin(), toUpper.end(), toUpper.begin(), ::toupper);

    return toUpper;
}

#endif
