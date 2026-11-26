FROM debian:bookworm-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends g++ make && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make clean && make

CMD ["./a3"]