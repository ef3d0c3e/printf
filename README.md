# A small printf replacement

**Supported formatting**
 - Flags: All flags are supported, except `'`:
    - `-` Aligns to the left (instead of the right)
    - `0` Aligns to the left and pads with `0`, only for integer types
    - `+` Always shows the `+` sign for positive integers
    - ` ` Shows a blank as the sign of positive values
    - `#` Use the alternate formatting mode
 - Width and precision are supported, both use `int` for their field width

The following length modifier/conversions are supported:
 - **Decimal conversions**:
    - `hhd` and `hhi` converts the `int` parameter to a `signed char`
    - `hd` and `hi` converts the `int` parameter to a `signed short`
    - `d` and `i` displays the `int` parameter
    - `ld` and `li` displays the `long int` parameter
    - `lld` and `lli` displays the `long long int` parameter
    - `jd` and `ji` displays the `intmax_t` parameter
    - `zd` and `zi` displays the `ssize_t` parameter
    - `hhu` converts the `unsigned int` parameter to an `unsigned char`
    - `hu` converts the `unsigned int` parameter to an `unsigned short`
    - `u` displays the `unsigned int` parameter
    - `lu` displays the `unsigned long int` parameter
    - `llu` displays the `unsigned long long int` parameter
    - `ju` displays the `uintmax_t` parameter
    - `zu` displays the `size_t` parameter
 - **Hexadecimal conversions**:
    - `hhx` and `hhX` converts the `unsigned int` parameter to an `unsigned char`
    - `hx` and `hX` converts the `unsigned int` parameter to an `unsigned short`
    - `x` and `X` displays the `unsigned int` parameter
    - `lx` and `lX` displays the `unsigned long int` parameter
    - `llx` and `llX` displays the `unsigned long long int` parameter
    - `jx` and `jX` displays the `uintmax_t` parameter
    - `zx` and `zX` displays the `size_t` parameter
 - **Octal conversions**:
    - `hho` converts the `unsigned int` parameter to an `unsigned char`
    - `ho` converts the `unsigned int` parameter to an `unsigned short`
    - `o` displays the `unsigned int` parameter
    - `lo` displays the `unsigned long int` parameter
    - `llo` displays the `unsigned long long int` parameter
    - `jo` displays the `uintmax_t` parameter
    - `zo` displays the `size_t` parameter
 - **Pointers**: `p` is used to format pointers, note that null pointers will
 be formatted as `(nil)`, following glibc convention.
 - **Characters**: `c` is used to format a character
 - **Strings**: `s` is used to format a string, note that the precision can be
 used to truncate the output. A `NULL` string will be formatted as `(null)`,
 following glibc convention.
 - **Other**: 
    - `m` is used to display the current errno via `strerror`. If alternate
 mode is set, `strerrorname_np` will be used instead. This option takes no parameters.
    - `n` Stores the number of bytes written in the corresponding parameter expressed as `int *`.


**Missing features**:
 - Float formatting
 - Localization support (`'` flag)
 - Wide character support (`wint_t`/`wchar_t`)

# Building

You can create a statically linked library by building the default target: `make`.

To build and run tests, use the following command: `make printf-tests && ./printf-tests`.

# License

This project is licensed under the MIT license. See [LICENSE.md](./LICENSE.md)
for more informations.
