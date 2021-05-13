import os

def calc_host_num(subnet):
	return 1

def calc_host_addr(network_addr, broadcast_addr):
	return 1

def calc_broadcast_addr(ip, subnet, cidr_code):
	return 1


def calc_network_addr(ip, subnet):
	lst_ip = list(map(int, ip.split('.')))
	lst_subnet = list(map(int, subnet.split('.')))
	lst_network = [
		lst_ip[0] & lst_subnet[0],
		lst_ip[1] & lst_subnet[1],
		lst_ip[2] & lst_subnet[2],
		lst_ip[3] & lst_subnet[3]
	]
	return '.'.join(list(map(str, lst_network)))

def get_subnet(cidr):
	cidr_code = int(cidr)
	else :
		sn_large = 4294967295
		subnet = sn_large << (32 - cidr_code)
		lst_subnet = [
			subnet >> 24 & 255,
			subnet >> 16 & 255,
			subnet >> 8 & 255,
			subnet & 255
		]
		return '.'.join(list(map(str, lst_subnet)))

def get_ip(s):
	c = '/'
	if c in s:
		lst_str = s.split('/')
		ip = lst_str[0]
		cidr_code = lst_str[1]
	else:
		ip = s
		cidr_code = '-1'
	return [ip, cidr_code]

def check_ip(s):
	c = '/'
	if c in s:
		lst_s_1 = s.split('/')
		lst_s = lst_s_1[0].split('.')
		cidr = int(lst_s_1[1])
		if (len(lst_s) != 4 or cidr > 32 or cidr < 0):
			return (0)
		else :
			return (1)
	else:
		lst_s = s.split('.')
		if (len(lst_s) != 4):
			return (0)
		else :
			return (1)
