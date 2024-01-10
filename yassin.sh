#!/bin/bash

# Set your GitHub username and repository name
USERNAME="your_username"
REPO_NAME="your_repository"

# Create 33 files
for i in {1..14}
do
    touch "file${i}.t"
    echo "// This is file ${i}" >> "file${i}.t"
done

# Add, commit, and push each file
for i in {1..140}
do
    git add "file${i}.t"
    git commit -m "Add file${i}.t"
    git push origin main
done
