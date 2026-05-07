#!/bin/bash
# Regression tests for gregory_newton

BIN="${1:-./build/gregory_newton}"
PASS=0
FAIL=0

run_test() {
    local name="$1"
    local input="$2"
    local expected="$3"
    local output
    output=$(echo "$input" | "$BIN" 2>&1)
    if echo "$output" | grep -qF "$expected"; then
        echo "  PASS: $name"
        ((PASS++))
    else
        echo "  FAIL: $name"
        echo "    expected to contain: $expected"
        echo "    got: $output"
        ((FAIL++))
    fi
}

echo "=== gregory_newton tests ==="

# Quadratic: n^2 - 8  (2nd diff should be constant 2)
run_test "quadratic n^2-8" \
    "-7, -2, 5, 14, 25, 38, 53, 70" \
    "f(n) := -7 + 5 * n + (n * (n - 1) * 2) / 2!;"

# Linear: constant difference of 3
run_test "linear 2+3n" \
    "2, 5, 8, 11, 14" \
    "f(n) := 2 + 3 * n;"

# Cubes: n^3
run_test "cubes n^3" \
    "0, 1, 8, 27, 64, 125, 216" \
    "f(n) := 0 + n + (n * (n - 1) * 6) / 2! + (n * (n - 1) * (n - 2) * 6) / 3!;"

# Single number
run_test "single value" \
    "42" \
    "f(n) := 42;"

# Error case: no input
output=$(echo "" | "$BIN" 2>&1)
if echo "$output" | grep -q "Error: no valid numbers"; then
    echo "  PASS: empty input error"
    ((PASS++))
else
    echo "  FAIL: empty input error (got: $output)"
    ((FAIL++))
fi

echo ""
echo "=== $PASS passed, $FAIL failed ==="
[ "$FAIL" -eq 0 ] && exit 0 || exit 1
