# Primrose

[![License](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://raw.githubusercontent.com/EnKrypt/Primrose/master/LICENSE)

A basic attempt at an optimized prime factorization tool.

## Details

Just something I thought I'd try my hand at after reading up on [RSA](<https://en.wikipedia.org/wiki/RSA_(cryptosystem)>), [Shor's algorithm](https://en.wikipedia.org/wiki/Shor's_algorithm), etc.

The factorization algorithm is my own, using a `lower_limit` and an `upper_limit` to reduce the number of iterations required to narrow down a prime factor.

This also means that there is probably scope for a lot more further optimizations.

## Usage

Compile yourself or download the [latest release](https://github.com/EnKrypt/Primrose/releases/latest).

```bash
$ primrose [number]
```

![Sample result](https://github.com/EnKrypt/Primrose/raw/master/assets/result.png)

## TODO

My competence with C++ is questionable, so there are a few things that can be improved.

-   Replace `long long` with a proper datatype that can handle bigger integers
-   Attempt to further optimize `isPrime` algorithm
-   Attempt to further optimize `factorize` algorithm
