FROM pfichtner/virtualavr:latest
ADD entrypoint.sh /usr/local/bin/
ADD virtualavr-compile-arduino /usr/local/bin/
ENTRYPOINT ["bash", "/usr/local/bin/entrypoint.sh"]
#ENTRYPOINT ["ls","-l","/usr/local/bin"]
