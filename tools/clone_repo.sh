#!/bin/bash

# Проверка наличия аргумента
[ $# -eq 0 ] && { echo "Usage: $0 <git-url>"; exit 1; }

URL="$1"
REPO_NAME=$(basename "$URL" .git)

# Create libraries directory if it doesn't exist
mkdir -p libraries || { echo "Error: Failed to create 'libraries' directory"; exit 1; }

echo "Cloning $REPO_NAME..."
git clone "$URL" "libraries/$REPO_NAME" || { echo "Error: Failed to clone $REPO_NAME repository"; exit 1; }

cd "libraries/$REPO_NAME"
git checkout master || exit 1
cd - > /dev/null

echo "Successfully cloned $REPO_NAME"