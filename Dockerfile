FROM gcc:latest
WORKDIR /usr/src/app
COPY numberguessing.c .
RUN gcc -o numberguessing numberguessing.c -lm
CMD ["./numberguessing"]