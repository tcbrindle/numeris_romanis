
`numeris_romanis.hpp` is a single-header C++17 library for dealing with roman numerals.

## Features ##

 * Literal operators so you too can embed film copyright dates in your source code!
 * Seamless interoperability with *numeris arabicis*!
 * Type safety!
 * Compile-time operations!
 * Conversion to and from strings!
 * Output streaming!
 * Really, really bad Latin! [*](#disclaimer)

## Examples ##

```cpp
using namespace rom::literals_numerorum;
static_assert("MCMLXXXVIII"_r + "XII"_r == "MM"_r);
```

```cpp
void foo()
{
    std::cout << rom::numerus{742} << '\n'; // prints DCCXLII
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


## Acknowledgements ##

Inspired by Tim Sweeney on Twitter:

<blockquote class="twitter-tweet" data-lang="en"><p lang="en" dir="ltr">Breaking: Roman numeral constant support proposed for C++0rMMXXIII.</p>&mdash; Tim Sweeney (@TimSweeneyEpic) <a href="https://twitter.com/TimSweeneyEpic/status/1047872948944683008?ref_src=twsrc%5Etfw">October 4, 2018</a></blockquote>



---


<a name="disclaimer">*</a>: All translations provided by [Google Translate](https://translate.google.com). Please don't [make me write it out a hundred times](https://youtu.be/KAfKFKBlZbM).