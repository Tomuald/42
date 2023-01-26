FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install nginx openssl

WORKDIR /tmp

COPY ./tools/* .

ARG DOMAIN_NAME=$DOMAIN_NAME
ARG CERT_CRT=$CERT_CRT
ARG CERT_KEY=$CERT_KEY

ENV DOMAIN_NAME=$DOMAIN_NAME
ENV CERT_CRT=$CERT_CRT
ENV CERT_KEY=$CERT_KEY

RUN ./generate_cert.sh

EXPOSE 443

ENTRYPOINT ["./entry.sh"]

CMD ["nginx", "-g", "daemon off;"]
