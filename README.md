
`numeris_romanis.hpp` is a single-header C++17 library for dealing with roman numerals.

## Features ##

 * Literal operators so you too can embed film copyright dates in your source code!
 * Seamless interoperability with *numeris arabicis*!
 * Type safety!
 * Compile-time operations!
 * Conversion to and from strings!
 * Output streaming!
 * Really, really bad Latin! [*](#disclaimer)
 
## Translations ##

* ab filo = to string
* ad filum = from string
* numerus = number
* numeris romanis = roman numbers
* numeris arabicis = arabic numbers

## Functions ##

* constructor
    * Takes either Arabic or Roman numerals as parameter
* numerus ab_filo(std::string_view str)
    * Converts passed Roman numeral into a numerus object
    * Helper function used in user-defined Roman literals
* std::string ad_filum()
    * Converts numerus' value to a string of it's Roman numeral counterpart
* Printing a numerus object will display the Roman numeral


## Examples ##

```cpp
using namespace rom::literals_numerorum;
static_assert("MCMLXXXVIII"_r + "XII"_r == "MM"_r); // 1988 + 12 == 2000
```

```cpp
void foo()
{
    std::cout << rom::numerus{742} << '\n'; // prints DCCXLII
    std::cout << rom::numerus{"DCCXLII"_r} << '\n'; // prints DCCXLII
}
```

```cpp
void bar()
{
    const rom::numerus r{444};
    std::string str = r.ad_filum();
    assert(str == "CDXLIV");
}
```

```cpp
void bax()
{
    const rom::numerus x{ "MCMLXXXVIII"_r }; 
    const rom::numerus y{ "XII"_r }; 
    const rom::numerus z = x + y;
    std::cout << z << '\n'; // prints MM
}
```

## Acknowledgements ##

Inspired by Tim Sweeney on Twitter:

<blockquote class="twitter-tweet" data-lang="en"><p lang="en" dir="ltr">Breaking: Roman numeral constant support proposed for C++0rMMXXIII.</p>&mdash; Tim Sweeney (@TimSweeneyEpic) <a href="https://twitter.com/TimSweeneyEpic/status/1047872948944683008?ref_src=twsrc%5Etfw">October 4, 2018</a></blockquote>



---


<a name="disclaimer">*</a>: All translations provided by [Google Translate](https://translate.google.com). Please don't [make me write it out a hundred times](https://youtu.be/KAfKFKBlZbM).