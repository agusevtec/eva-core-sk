#!/bin/bash

# Create libraries directory if it doesn't exist
mkdir -p libraries || {
    echo "Error: Failed to create 'libraries' directory"
    exit 1
}

cd libraries

# Clone EpoxyDuino
echo "Cloning EpoxyDuino..."
if git clone https://github.com/bxparks/EpoxyDuino.git; then
    cd EpoxyDuino
    git checkout master
    cd ..
else
    echo "Error: Failed to clone EpoxyDuino repository"
    exit 1
fi

# Clone AUnit
echo "Cloning AUnit..."
if git clone https://github.com/bxparks/AUnit.git; then
    cd AUnit
    git checkout master
    cd ..
else
    echo "Error: Failed to clone AUnit repository"
    exit 1
fi

cd ..

echo "Done"
