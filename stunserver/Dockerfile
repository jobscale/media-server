FROM debian:bookworm-slim
USER root
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ Asia/Tokyo
RUN set -ex \
 && apt-get update \
 && apt-get install -y --no-install-recommends build-essential libboost-all-dev libssl-dev \
    g++ make git \
 && apt-get clean -y \
 && rm -rf /var/lib/apt/lists/*

RUN cd /opt && git clone https://github.com/jselbie/stunserver.git && cd stunserver && make

WORKDIR /opt/stunserver
HEALTHCHECK CMD /opt/stunserver/stunclient 127.0.0.1
EXPOSE 3478/tcp 3478/udp
ENTRYPOINT ["/opt/stunserver/stunserver"]
