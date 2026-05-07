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
Parsed numbers:<br/>
<pre>-7, -2, 5, 14, 25, 38, 53, 70</pre>

Differences table:</br>
<pre>-7 -2 5 14 25 38 53 70
  5 7 9 11 13 15 17
    2 2 2 2 2 2</pre>

Gregory Newton Formula: (maxima definition)<br/>
<pre>f(n) := -7 + 5 * n + (n * (n - 1) * 2) / 2!;</pre>
```

## Test

```bash
./test.sh
```
