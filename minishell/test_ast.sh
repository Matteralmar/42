#!/bin/bash

# AST Integration Test Script
# Tests various command structures to verify AST functionality

echo "=== Testing AST Integration ==="
echo ""

# Test 1: Simple command
echo "Test 1: Simple command"
echo "ls -l" | ./minishell 2>&1 | head -5
echo ""

# Test 2: Pipe
echo "Test 2: Pipe"
echo "echo hello world | cat" | ./minishell
echo ""

# Test 3: Multiple pipes
echo "Test 3: Multiple pipes"
echo "echo one two three | cat | cat" | ./minishell
echo ""

# Test 4: Logical AND (success case)
echo "Test 4: Logical AND (success)"
echo "echo test && echo success" | ./minishell
echo ""

# Test 5: Logical AND (failure case)
echo "Test 5: Logical AND (failure)"
echo "false && echo should not print" | ./minishell
echo ""

# Test 6: Logical OR (success case)
echo "Test 6: Logical OR (success)"
echo "true || echo should not print" | ./minishell
echo ""

# Test 7: Logical OR (failure case)
echo "Test 7: Logical OR (failure)"
echo "false || echo should print" | ./minishell
echo ""

# Test 8: Output redirection
echo "Test 8: Output redirection"
echo "echo test output > /tmp/minishell_test.txt" | ./minishell
cat /tmp/minishell_test.txt
rm -f /tmp/minishell_test.txt
echo ""

# Test 9: Input redirection
echo "Test 9: Input redirection"
echo "hello from file" > /tmp/minishell_input.txt
echo "cat < /tmp/minishell_input.txt" | ./minishell
rm -f /tmp/minishell_input.txt
echo ""

# Test 10: Append redirection
echo "Test 10: Append redirection"
echo "echo line1 > /tmp/minishell_append.txt" | ./minishell
echo "echo line2 >> /tmp/minishell_append.txt" | ./minishell
cat /tmp/minishell_append.txt
rm -f /tmp/minishell_append.txt
echo ""

# Test 11: Complex combination
echo "Test 11: Complex - pipe with logical AND"
echo "echo success | cat && echo completed" | ./minishell
echo ""

# Test 12: Builtins
echo "Test 12: Builtin commands"
echo "pwd" | ./minishell
echo ""

echo "=== All tests completed ==="