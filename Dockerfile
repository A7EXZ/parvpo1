FROM alpine:latest

RUN apk update && apk add git g++

WORKDIR /app
RUN git clone https://github.com/A7EXZ/parvpo1.git .

RUN g++ -fopenmp -o lab1 lab1.cpp

VOLUME ["/output"]

CMD ["sh", "-c", "./lab1 > /output/res.txt"]
