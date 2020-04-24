FROM ubuntu:16.04

WORKDIR /src

RUN apt-get -y update
RUN apt-get -y install build-essential

COPY . .

ENTRYPOINT [ "make" ]