#!/bin/bash

echo "======================================"
echo "MINISHELL BONUS FEATURES TEST"
echo "======================================"
echo ""

PASS=0
FAIL=0

# Test 1: Wildcard - simple
echo -n "Testing: Wildcard *.md ... "
result=$(printf 'echo *.md\n' | ./minishell | grep -c "README.md")
if [ "$result" -ge 1 ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 2: Wildcard - no match
echo -n "Testing: Wildcard no match ... "
result=$(printf 'echo *.nonexistent\n' | ./minishell | grep "*.nonexistent")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 3: Wildcard in quotes (should not expand)
echo -n "Testing: Wildcard in quotes ... "
result=$(printf 'echo "*.md"\n' | ./minishell | grep "\*.md")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 4: Simple parenthesis
echo -n "Testing: Simple parenthesis ... "
result=$(printf '(echo test)\n' | ./minishell | grep "test")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 5: Parenthesis with AND
echo -n "Testing: (cmd1 && cmd2) ... "
result=$(printf '(echo A && echo B)\n' | ./minishell | grep -c "A")
if [ "$result" -ge 1 ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 6: Parenthesis priority with OR
echo -n "Testing: false || (echo A && echo B) ... "
result=$(printf 'false || (echo A && echo B)\n' | ./minishell | grep -c "B")
if [ "$result" -ge 1 ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 7: Parenthesis priority with AND
echo -n "Testing: true && (echo X || echo Y) ... "
result=$(printf 'true && (echo X || echo Y)\n' | ./minishell | grep "X")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 8: Complex parenthesis
echo -n "Testing: (false || true) && echo OK ... "
result=$(printf '(false || true) && echo OK\n' | ./minishell | grep "OK")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 9: Nested logic
echo -n "Testing: Nested logic ... "
result=$(printf 'true && (false || echo WIN)\n' | ./minishell | grep "WIN")
if [ -n "$result" ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

# Test 10: Wildcard with command
echo -n "Testing: ls *.md (files exist) ... "
result=$(printf 'ls *.md\nexit\n' | ./minishell | grep -c "README.md")
if [ "$result" -ge 1 ]; then
    echo "✓ PASS"
    ((PASS++))
else
    echo "✗ FAIL"
    ((FAIL++))
fi

echo ""
echo "======================================"
echo "TEST RESULTS"
echo "======================================"
echo "Passed: $PASS"
echo "Failed: $FAIL"
echo "Total: $((PASS + FAIL))"
echo ""

if [ $FAIL -eq 0 ]; then
    echo "All tests passed! ✅"
    exit 0
else
    echo "Some tests failed!"
    exit 1
fi
