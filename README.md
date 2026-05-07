# Gregory Newton Calculator

This application reads a sequence of numbers and applies the Gregory-Newton formula to create an equation for that sequence.

Also includes a Chicken Scheme prototype (`gnewton.csc`).

## Build

```bash
mkdir -p build && cd build
cmake ..
make
```

## Usage

```bash
echo "-7, -2, 5, 14, 25, 38, 53, 70" | ./build/gregory_newton
```

Output:

```
Parsed numbers:
-7, -2, 5, 14, 25, 38, 53, 70

Differences table:
-7 -2 5 14 25 38 53 70
  5 7 9 11 13 15 17
    2 2 2 2 2 2

Gregory Newton Formula: (maxima definition)
f(n) := -7 + 5 * n + (n * (n - 1) * 2) / 2!;
```

## Test

```bash
./test.sh
```
