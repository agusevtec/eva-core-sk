#!/bin/bash

tools/clone_repo.sh "https://github.com/bxparks/EpoxyDuino.git" || exit 1
tools/clone_repo.sh "https://github.com/bxparks/AUnit.git" || exit 1

echo "All repositories cloned successfully!"
