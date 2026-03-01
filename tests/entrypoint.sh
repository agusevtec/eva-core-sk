#!/usr/bin/env bash
HEXFILE="$(mktemp /tmp/virtualavr-hex-XXXXXX)"
HEXFILE="$HEXFILE.hex"
virtualavr-compile-arduino "/sketch/$FILENAME" "$HEXFILE" || exit 1
#socat EXEC:"node /app/virtualavr.js $HEXFILE",pty,rawer,fdin=3,fdout=4 STDIO

# Создаем именованные пайпы (FIFO) для двунаправленной связи
#mkfifo /tmp/socat_in /tmp/socat_out

# Запускаем socat, который связывает процесс и наши пайпы
#socat EXEC:"node /app/virtualavr.js $HEXFILE",pty,rawer,fdin=3,fdout=4 \
#    SYSTEM:"tee /tmp/socat_out > >(grep -q 'END' && kill \$PPID) >&2; cat > /tmp/socat_in" &

# Теперь работаем через пайпы как через STDIO
#cat /tmp/socat_out | tee >(grep -q "END" && kill $!) | cat &
#cat > /tmp/socat_in

# Очистка
#rm -f /tmp/socat_in /tmp/socat_out


PID=$!
wait $PID
