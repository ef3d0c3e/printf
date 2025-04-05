# A small printf replacement

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
