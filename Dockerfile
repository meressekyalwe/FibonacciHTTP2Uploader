FROM debian

RUN apt-get update && apt-get install -y cmake build-essential libsqlite3-dev git libssl-dev pkg-config groff-base libssh2-1-dev libjsoncpp-dev

WORKDIR /project
COPY . .

WORKDIR /project/build

RUN cmake -G "Unix Makefiles" .. && make

CMD ./FibonacciHTTP2Uploader

