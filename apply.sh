iptables -F
iptables -P INPUT ACCEPT
iptables -P OUTPUT ACCEPT
iptables -P FORWARD ACCEPT
iptables -A INPUT -j ACCEPT -s jnb03s08-in-f4.1e100.net
iptables -A INPUT -j ACCEPT -s jnb03s08-in-f4.1e100.net
iptables -A INPUT -j ACCEPT -m mac --mac-source 24:0a:64:d1:8e:0b
iptables -A INPUT -j ACCEPT -p tcp
