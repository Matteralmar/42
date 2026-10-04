#!/bin/bash

# Comprehensive Test Suite for Minishell Mandatory Features
# Run this to verify all requirements are met

echo "======================================"
echo "MINISHELL MANDATORY FEATURES TEST"
echo "======================================"
echo ""

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

pass=0
fail=0

test_feature() {
    echo -n "Testing: $1 ... "
}

test_pass() {
    echo -e "${GREEN}✓ PASS${NC}"
    ((pass++))
}

test_fail() {
    echo -e "${RED}✗ FAIL${NC}"
    ((fail++))
}

# Test 1: Basic echo
test_feature "echo command"
result=$(echo "echo hello world" | ./minishell | grep "hello world")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 2: echo with -n
test_feature "echo -n (no newline)"
result=$(printf 'echo -n test\n' | ./minishell | tail -n 1)
if [[ "$result" == *"test"* ]]; then
    test_pass
else
    test_fail
fi

# Test 3: pwd
test_feature "pwd command"
expected=$(pwd)
result=$(echo "pwd" | ./minishell | grep "$expected")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 4: cd
test_feature "cd command"
result=$(printf 'cd /tmp\npwd\n' | ./minishell | grep "/tmp")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 5: env
test_feature "env command"
result=$(echo "env" | ./minishell | grep "USER")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 6: export
test_feature "export command"
result=$(printf 'export TESTVAR=hello\nenv\n' | ./minishell | grep "TESTVAR=hello")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 7: unset
test_feature "unset command"
result=$(printf 'export TESTVAR=hello\nunset TESTVAR\nenv\nexit\n' | ./minishell | grep "^TESTVAR=")
if [ -z "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 8: Variable expansion
test_feature "Variable expansion \$USER"
result=$(echo 'echo $USER' | ./minishell | grep "$USER")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 9: Exit status $?
test_feature "Exit status \$?"
result=$(printf 'true\necho $?\n' | ./minishell | grep "^0$")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 10: Single quotes (no expansion)
test_feature "Single quotes (no expansion)"
result=$(echo "echo '\$USER'" | ./minishell | grep '\$USER')
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 11: Double quotes (with expansion)
test_feature "Double quotes (with expansion)"
result=$(echo 'echo "$USER"' | ./minishell | grep "$USER")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 12: Pipe
test_feature "Pipe |"
result=$(echo "echo test | cat" | ./minishell | grep "test")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 13: Output redirection >
test_feature "Output redirection >"
echo "echo test > /tmp/minishell_test.txt" | ./minishell > /dev/null 2>&1
if [ -f /tmp/minishell_test.txt ] && grep -q "test" /tmp/minishell_test.txt; then
    test_pass
    rm -f /tmp/minishell_test.txt
else
    test_fail
fi

# Test 14: Input redirection <
test_feature "Input redirection <"
echo "test input" > /tmp/minishell_input.txt
result=$(echo "cat < /tmp/minishell_input.txt" | ./minishell | grep "test input")
rm -f /tmp/minishell_input.txt
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 15: Append redirection >>
test_feature "Append redirection >>"
echo "echo line1 > /tmp/minishell_append.txt" | ./minishell > /dev/null 2>&1
echo "echo line2 >> /tmp/minishell_append.txt" | ./minishell > /dev/null 2>&1
if [ -f /tmp/minishell_append.txt ] && grep -q "line1" /tmp/minishell_append.txt && grep -q "line2" /tmp/minishell_append.txt; then
    test_pass
    rm -f /tmp/minishell_append.txt
else
    test_fail
fi

# Test 16: Heredoc <<
test_feature "Heredoc <<"
result=$(printf 'cat << EOF\nline1\nline2\nEOF\n' | ./minishell 2>&1 | grep "^line" | wc -l)
if [ "$result" -eq 2 ]; then
    test_pass
else
    test_fail
fi

# Test 17: Multiple pipes
test_feature "Multiple pipes"
result=$(echo "echo test | cat | cat" | ./minishell | grep "test")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 18: Command not found
test_feature "Command not found error"
result=$(echo "nonexistentcommand" | ./minishell 2>&1 | grep -i "not found")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 19: Logical AND (bonus)
test_feature "Logical AND &&"
result=$(echo "true && echo success" | ./minishell | grep "success")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

# Test 20: Logical OR (bonus)
test_feature "Logical OR ||"
result=$(echo "false || echo failed" | ./minishell | grep "failed")
if [ -n "$result" ]; then
    test_pass
else
    test_fail
fi

echo ""
echo "======================================"
echo "TEST RESULTS"
echo "======================================"
echo -e "${GREEN}Passed: $pass${NC}"
echo -e "${RED}Failed: $fail${NC}"
echo "Total: $((pass + fail))"
echo ""

if [ $fail -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed!${NC}"
    exit 1
fi
