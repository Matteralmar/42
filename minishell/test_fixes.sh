#!/bin/bash

# Comprehensive test script for minishell fixes
# Tests all the issues that were fixed

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  Minishell Fixes Comprehensive Tests  ${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Helper function to print test results
print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓ PASS${NC}: $2"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC}: $2"
        ((FAILED++))
    fi
}

# Test 1: Compilation Test
echo -e "\n${YELLOW}[Test 1]${NC} Checking compilation..."
make re > /dev/null 2>&1
if [ $? -eq 0 ]; then
    print_result 0 "Project compiles without errors"
else
    print_result 1 "Compilation failed"
fi

# Test 2: Check for magic numbers in code
echo -e "\n${YELLOW}[Test 2]${NC} Checking for replaced magic numbers..."
if grep -q "EXIT_CMD_NOT_FOUND\|EXIT_SIGINT\|EXIT_CMD_NOT_EXEC" include/minishell.h; then
    print_result 0 "Exit code constants defined"
else
    print_result 1 "Exit code constants missing"
fi

if grep -q "FILE_PERM_HEREDOC" include/minishell.h; then
    print_result 0 "File permission constants defined"
else
    print_result 1 "File permission constants missing"
fi

# Test 3: Check for standardized error messages
echo -e "\n${YELLOW}[Test 3]${NC} Checking error message standardization..."
ERROR_COUNT=$(grep -r "minishell:" src/ | grep "dprintf\|printf" | wc -l)
if [ $ERROR_COUNT -gt 10 ]; then
    print_result 0 "Error messages standardized (found $ERROR_COUNT instances)"
else
    print_result 1 "Not enough standardized error messages (found $ERROR_COUNT)"
fi

# Test 4: Check for TODO comments resolved
echo -e "\n${YELLOW}[Test 4]${NC} Checking for resolved TODO comments..."
TODO_IN_SIGNALS=$(grep "#TODO" src/signals/signals.c 2>/dev/null | wc -l)
if [ "$TODO_IN_SIGNALS" -eq 0 ]; then
    print_result 0 "Signal handling TODO resolved"
else
    print_result 1 "Signal handling TODO still present"
fi

# Test 5: Check heredoc counter fix
echo -e "\n${YELLOW}[Test 5]${NC} Checking heredoc counter initialization..."
if grep -q "static int.*counter = 0" src/exec/heredoc/heredoc.c; then
    print_result 0 "Heredoc counter properly initialized"
else
    print_result 1 "Heredoc counter not properly initialized"
fi

# Test 6: Check FALSE/TRUE enum
echo -e "\n${YELLOW}[Test 6]${NC} Checking FALSE/TRUE enum..."
if grep -q "FALSE = 0" include/minishell.h && grep -q "TRUE = 1" include/minishell.h; then
    print_result 0 "FALSE/TRUE enum properly defined"
else
    print_result 1 "FALSE/TRUE enum not found"
fi

if grep -q "FALSE\|TRUE" src/main/expan.c; then
    print_result 0 "FALSE/TRUE used in expan.c"
else
    print_result 1 "FALSE/TRUE not used in expan.c"
fi

# Test 7: Check signal exit status handling
echo -e "\n${YELLOW}[Test 7]${NC} Checking signal exit status handling..."
if grep -q "g_last_signal == SIGINT" src/main/main.c; then
    print_result 0 "Signal handling check present in main"
else
    print_result 1 "Signal handling check missing"
fi

if grep -q "EXIT_SIGINT" src/main/main.c; then
    print_result 0 "EXIT_SIGINT constant used"
else
    print_result 1 "EXIT_SIGINT constant not used"
fi

# Test 8: Check pipeline exit status handling
echo -e "\n${YELLOW}[Test 8]${NC} Checking pipeline exit status..."
if grep -q "WIFSIGNALED" src/exec/execute/exec_pipeline.c; then
    print_result 0 "Pipeline handles WIFSIGNALED"
else
    print_result 1 "Pipeline doesn't handle WIFSIGNALED"
fi

if grep -q "EXIT_SIGNAL_BASE" src/exec/execute/exec_pipeline.c; then
    print_result 0 "Pipeline uses EXIT_SIGNAL_BASE constant"
else
    print_result 1 "Pipeline doesn't use EXIT_SIGNAL_BASE"
fi

# Test 9: Check subshell signal handling
echo -e "\n${YELLOW}[Test 9]${NC} Checking subshell signal handling..."
if grep -q "WIFSIGNALED" src/exec/execute/exec_ast.c; then
    print_result 0 "Subshell handles WIFSIGNALED"
else
    print_result 1 "Subshell doesn't handle WIFSIGNALED"
fi

# Test 10: Runtime test - Command not found
echo -e "\n${YELLOW}[Test 10]${NC} Runtime test: Command not found error..."
OUTPUT=$(echo "nonexistent_command_12345" | ./minishell 2>&1)
if echo "$OUTPUT" | grep -q "minishell:.*command not found"; then
    print_result 0 "Command not found error properly formatted"
else
    print_result 1 "Command not found error not properly formatted"
fi

# Test 11: Check for EXIT_GENERAL_ERROR usage
echo -e "\n${YELLOW}[Test 11]${NC} Checking EXIT_GENERAL_ERROR usage..."
if grep -q "EXIT_GENERAL_ERROR" src/main/main.c; then
    print_result 0 "EXIT_GENERAL_ERROR used in main.c"
else
    print_result 1 "EXIT_GENERAL_ERROR not used"
fi

# Test 12: Check for proper errno usage
echo -e "\n${YELLOW}[Test 12]${NC} Checking errno usage in error messages..."
ERRNO_COUNT=$(grep -r "strerror(errno)" src/ | wc -l)
if [ $ERRNO_COUNT -gt 5 ]; then
    print_result 0 "Error messages include errno info (found $ERRNO_COUNT instances)"
else
    print_result 1 "Not enough errno usage in error messages"
fi

# Summary
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}           Test Summary                 ${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "${GREEN}Passed:${NC} $PASSED"
echo -e "${RED}Failed:${NC} $FAILED"
TOTAL=$((PASSED + FAILED))
PERCENTAGE=$((PASSED * 100 / TOTAL))
echo -e "Success Rate: ${PERCENTAGE}%"

if [ $FAILED -eq 0 ]; then
    echo -e "\n${GREEN}🎉 All tests passed! Great job!${NC}"
    exit 0
else
    echo -e "\n${YELLOW}⚠️  Some tests failed. Please review.${NC}"
    exit 1
fi

