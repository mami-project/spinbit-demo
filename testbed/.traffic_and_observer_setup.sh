#!/bin/bash

echo "router (VPP) setup"
cd etc/router/vpp_vagrant/vagrant
vagrant up
vagrant ssh -c "sudo service vpp restart"
sleep 2
vagrant ssh -c "sudo vppctl ex /home/vagrant/vpp-latency-mb/vpp_setup.conf"

cd ../../../../

echo "adding default delay"
./demo_1_normal_50ms.sh

echo "server setup"
sudo docker-compose exec -d server bash -c 'cd src/github.com/lucas-clemente/quic-go/example/wwwsrv/ && ./wwwsrv -cert=rootCACert.pem -key=rootCAKey.pem -laddr=192.168.51.2:6000 -prefix=/data/'

echo "client setup"
sudo docker-compose exec -d client bash -c 'cd src/github.com/lucas-clemente/quic-go/example/puic-poll/ && ./puic-poll -certs=rootCACert.pem -collect=100 -logfile="" -odir="./tmp/" -urls=https://192.168.51.2:6000/data/16MiB -wait-from=4 -wait-to=5 -runs=1000'

echo "router (reporter) setup"
sudo docker-compose exec -d router bash -c 'cd /root/share/vpp_vagrant/vagrant/ && ./repeat.sh'

