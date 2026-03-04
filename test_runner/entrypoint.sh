#!/bin/bash

for builddir in $(ls -d */ 2>/dev/null); do
    HEXFILE="$(mktemp /tmp/virtualavr-hex-XXXXXX).hex"
    
    virtualavr-compile-arduino "/sketch/$builddir" "$HEXFILE" || exit 1
    
    socat EXEC:"node /app/virtualavr.js $HEXFILE",pty,rawer,fdin=3,fdout=4 STDIO | tee >(grep -q "TestRunner summary:" && kill -- -$$) | sed "s|/sketch/$builddir||g"
done