iptables -F
iptables -P INPUT ACCEPT
iptables -P OUTPUT ACCEPT
iptables -P FORWARD ACCEPT
iptables -A INPUT -j ACCEPT -i lo -p tcp -m multiport --dports 10000,10050
