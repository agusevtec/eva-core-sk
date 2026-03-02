#!/usr/bin/env bash
HEXFILE="$(mktemp /tmp/virtualavr-hex-XXXXXX).hex"
FIRST_DIR=$(find . -maxdepth 1 -type d ! -path "." | head -1)
virtualavr-compile-arduino /sketch/"$FIRST_DIR" "$HEXFILE" || exit 1
socat EXEC:"node /app/virtualavr.js $HEXFILE",pty,rawer,fdin=3,fdout=4 STDIO | tee >(grep -q "TestRunner summary:" && kill -- -$$)

PID=$!
wait $PID
