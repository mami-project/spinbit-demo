sudo docker-compose exec client tc qdisc del root dev eth0 
sudo docker-compose exec client tc qdisc add dev eth0 root netem delay 25ms loss 15% 25%

sudo docker-compose exec server tc qdisc del root dev eth0 
sudo docker-compose exec server tc qdisc add dev eth0 root netem delay 25ms loss 15% 25%

