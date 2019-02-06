#!/bin/bash

BRNAME="$(docker network create -d bridge --gateway=192.168.50.1 --subnet=192.168.50.1/24 client-br)"

BRSHORT=${BRNAME:0:12}

BRFULLC="br-"$BRSHORT""

BRNAME="$(docker network create -d bridge --gateway=192.168.51.1 --subnet=192.168.51.1/24 server-br)"

BRSHORT=${BRNAME:0:12}

BRFULLS="br-"$BRSHORT""

cat etc/router/vpp_vagrant/vagrant/Vagrantfile.in | sed -e "s/@BRIDGE_CLIENT@/${BRFULLC}/" \
        -e "s/@BRIDGE_SERVER@/${BRFULLS}/" \
        > etc/router/vpp_vagrant/vagrant/Vagrantfile
