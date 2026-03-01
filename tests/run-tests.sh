#!/bin/bash

echo "=========================================="
echo "Starting Arduino unit tests for eva-core-sk"
echo "=========================================="

TEST_SKETCH=${TEST_SKETCH:-test_runner.ino}
echo "Test sketch: $TEST_SKETCH"

BUILD_DIR=/tmp/test
mkdir -p $BUILD_DIR
cd $BUILD_DIR

cp /sketch/* ./
echo "Test sketch copied"

echo "Compiling sketch..."
echo "----------------------------------------"
if ! arduino-cli compile --fqbn arduino:avr:uno --libraries /libraries ./test.ino; then
    echo "Compilation failed!"
    exit 1
fi
echo "----------------------------------------"
echo "Compilation successful!"
echo ""

# Create virtual serial port with socat
echo "Creating virtual serial port with socat..."
socat -d -d pty,raw,echo=0,link=/tmp/virtualavr0 tcp-listen:55555,reuseaddr,fork &
SOCAT_PID=$!

sleep 2

if [ ! -e "/tmp/virtualavr0" ]; then
    echo "Failed to create virtual serial port"
    kill $SOCAT_PID 2>/dev/null || true
    exit 1
fi

echo "Virtual serial port created at /tmp/virtualavr0"

# Start reading serial output
cat /tmp/virtualavr0 &
CAT_PID=$!

echo "=========================================="
echo "Running tests on virtual AVR..."
echo "=========================================="

# Upload and run
arduino-cli upload -p /tmp/virtualavr0 --fqbn arduino:avr:uno --input-dir $BUILD_DIR

# Wait for tests
sleep 30

# Cleanup
kill $SOCAT_PID $CAT_PID 2>/dev/null || true

echo "=========================================="
echo "Tests completed"
echo "=========================================="
exit 0