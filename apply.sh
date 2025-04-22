iptables -F
iptables -P INPUT ACCEPT
iptables -P OUTPUT ACCEPT
iptables -P FORWARD DROP
iptables -A INPUT -j ACCEPT -i lo -p tcp -m multiport --dports 1,11
