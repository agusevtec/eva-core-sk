FROM pfichtner/virtualavr:latest
RUN apk add --no-cache dos2unix jq
RUN arduino-cli lib install AUnit
ADD entrypoint.sh virtualavr-compile-arduino /usr/local/bin/
RUN dos2unix /usr/local/bin/entrypoint.sh /usr/local/bin/virtualavr-compile-arduino
ENTRYPOINT ["bash", "/usr/local/bin/entrypoint.sh"]
