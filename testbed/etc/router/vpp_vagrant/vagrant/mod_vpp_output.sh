#!/bin/sh
tail -n 100 spinbit_plus_printf.out > /root/share/vpp_vagrant/vagrant/rtt_data.out
sed -i $'s/[^[:print:]\t]//g' /root/share/vpp_vagrant/vagrant/rtt_data.out
sed -i $'s/\t//g' /root/share/vpp_vagrant/vagrant/rtt_data.out
sed -i '/^time/ d' /root/share/vpp_vagrant/vagrant/rtt_data.out

tail -n 2 spinbit_plus_counters.out > /root/share/vpp_vagrant/vagrant/rtt_counters.out
sed -i $'s/[^[:print:]\t]//g' /root/share/vpp_vagrant/vagrant/rtt_counters.out
sed -i $'s/\t//g' /root/share/vpp_vagrant/vagrant/rtt_counters.out
sed -i '/^time/ d' /root/share/vpp_vagrant/vagrant/rtt_counters.out
