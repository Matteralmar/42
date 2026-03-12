#!/bin/bash

echo "=== Testing heredoc with unquoted delimiter (should expand) ==="
echo "cat << EOF
\$USER
EOF" | ./minishell

echo ""
echo "=== Testing heredoc with double-quoted delimiter (should NOT expand) ==="
echo 'cat << "EOF"
$USER
EOF' | ./minishell

echo ""
echo "=== Testing heredoc with single-quoted delimiter (should NOT expand) ==="
echo "cat << 'EOF'
\$USER
EOF" | ./minishell

echo ""
echo "=== Comparing with zsh (should expand) ==="
cat << EOF
$USER
EOF

echo ""
echo "All tests completed!"

