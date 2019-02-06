FROM golang:alpine

RUN apk add --no-cache \
      bash \
      bc \
      bridge \
      ca-certificates \
      coreutils \
      drill \
      git \
      iperf3 \
      iproute2 \
      iproute2-doc \
      iputils \
      man \
      tcpdump \
      tshark \
      util-linux

RUN apk add hping3 --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing --update-cache

RUN pwd
RUN pwd

RUN update-ca-certificates

RUN go get -u github.com/buehlert/netem-pub/netem \
              github.com/buehlert/netem-pub/netemd \
              github.com/buehlert/netem-pub/plus \
              github.com/spf13/viper \
              github.com/spf13/cobra

# Compile and install netemd
RUN cd /go/src/github.com/buehlert/netem-pub/netemd && go install

# Manually fix traffic control distributions.  They are actually installed
# but not in the location tc expects to find them.
RUN ln -s /usr/lib/tc /lib/tc

# Install PLUS
RUN go get github.com/lucas-clemente/quic-go
RUN cd src/github.com/lucas-clemente/quic-go/ && go get -t -u ./...
RUN cd src/github.com && mkdir mami-project && cd mami-project && git clone https://github.com/mami-project/plus-lib.git -b latency_spin_signal
RUN cd src/github.com/lucas-clemente && rm -r quic-go && git clone https://github.com/mami-project/puic-go.git && mv puic-go/ quic-go/
RUN go get github.com/lucas-clemente/quic-go-certificates
RUN go get github.com/lucas-clemente/aes12
RUN go get github.com/hashicorp/golang-lru
RUN cd src/github.com/lucas-clemente/quic-go/example/puic-poll && mkdir tmp && go build
RUN cd src/github.com/lucas-clemente/quic-go/example/wwwsrv && go build
