# Dependencies

Make sure you have the following installed:

- GNU make (>=3.81)
- [Docker Community Edition (CE)](https://docs.docker.com/install/) (>=17.12.0-ce)
- [Docker Compose](https://docs.docker.com/compose/install) (>= 1.11.1)
- Bash (>=3.2.57)
- cURL (>=7.52.1)
- jq (>=1.5)
- GIT (>=2.14.3)
- VirtualBox
- Vagrant

# Install instructions

After installing the required dependencies:

```
cd spinbit-testbed/testbed

# create bridges (only once or after make remove-br)
sudo make bridge

# create base images
sudo make -C baseimg

# container up (after changes)
sudo make build-up
```

## Start demo
```
cd spinbit-testbed/testbed

# bring containers up
sudo make up

# create the dashboard
sudo make dash

# start the traffic and VPP
sudo make traffic
```

## Stop demo
```
cd spinbit-testbed/testbed

# bring containers down
sudo make down

# halt VPP VM
sudo make vpp-down

# removes bridges (if no longer used)
sudo make remove-br
```

## Dashboard access (local)
```
# port forwarding
ssh -L 18888:localhost:9999 <server>

# in local browser
http://localhost:18888/sources/0/dashboards/1
```

## Change demo parameters
```
cd spinbit-testbed/testbed

# after starting the demo, it will already load the parameters for demo 1
./demo_1_normal_50ms.sh
./demo_2_higher_delay_200ms.sh
./demo_3_50ms_with_loss.sh
```
## Example demo run

![Alt text](testbed/pics/example_demo_run.png?raw=true "example demo run")
