# netwhat42 (Netwhat 모의시험 프로그램)

## 1. What is the network address of a host with an IP address of 116.45.224.50 / 8?
- Class A이고, Subnet 부분이 8자리이므로 서브넷 마스크는 255.0.0.0 (11111111.00000000.00000000.00000000)
- 따라서 Subnet 주소는 첫 번째 옥텟만 and연산을 취한 **116.0.0.0**

## 2. Which of the following IP address is a private address?
- private address 범위 :
	- Class A : 10.0.0.0 ~ 10.255.255.255
	- Class B : 172.16.0.0 ~ 172.31.255.255
	- Class C : 192.168.0.0 ~ 192.168.255.255
- 따라서 해당 범위에 속하는 **172.16.0.2**가 private address에 해당한다.

## Which IP address class has more host addresses available by default?
- Class A는 첫 번째 옥텟만이 네트워크 주소로 사용되고, 나머지 세 개가 전부 호스트 주소로 사용될 수 있으므로 인듯?
- **FIRST = A**

## ________ translates Internet domain names and host names into IP addresses
- 인터넷 도메인과 호스트명을 IP주소로 변환하는 역할은 DNS (**Domain Name System**) 이 수행

## What type of address is supported by DHCP?
- DHCP는 IPv4, IPv6 둘 다 지원한다 (2003년 버전에서부터 IPv6 지원을 시작함)
- => **IPv4 and IPv6**

## What is the subnet mask of /24?
- /24는 24개 비트를 Subnet에 사용하겠다는 의미이므로, 마지막 옥텟 제외 3개가 전부 1로 채워진다
- 11111111.11111111.11111111.00000000 = **255.255.255.0**

## What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.128.0 subnet mask?
- 255.255.128.0 => 11111111.11111111.10000000.00000000
- 128개 (3번째 옥텟) * 256개 (4번째 옥텟) - 2 = **32766**

## Which of the following IP addresses is a private address?
- 192.168.0.0 ~ 192.168.255.255 범위에 속하는 **192.168.20.253**

## Which of the following propositions is not true?
1. TCP is a connection-oriented protocol
	- TCP는 연결지향 프로토콜이 맞다
2. TCP does not support broadcasting
	- TCP는 연결지향 프로토콜으로, 1:1 연결 상태를 유지한다는 특성이 있으므로 브로드캐스팅을 지원하지 않는다
	- 브로드캐스팅을 지원하는 것은 비연결형 프로토콜인 UDP
3. TCP provides extended error checking mechanisms. This is because it provides flow control and data acknowledgement
	- Segment에 체크섬 및 시퀀스 넘버 할당 등으로 데이터 순서나 에러 등을 체크할 수 있는 기능을 제공하므로, (또한 이러한 Segment 특성은 flow control과 data acknowledgement에 사용되므로) 확장된 에러 검출 기능을 제공한다고 볼 수 있다
4. Data sequencing is a TCP feature (this means that packets arrive in order in the recipient)
	- 패킷이 수신자에게 순서대로 제대로 도착하는 것은 TCP만이 구현해주므로, TCP의 특성이 맞다
5. **The delivery of data to the destination cannot be guaranteed in TCP**
	- TCP는 데이터의 제대로 된 수신을 보장하고, 에러 체크 및 재전송 요청 등을 담당하므로 해당 답안은 틀렸다
6. TCP is reliable because it guarantees the delivery of data to the router of the destination
	- TCP는 데이터가 제대로 되지 않았을 경우 등, 재전송 및 오류 체크를 진행하므로 라우터에 데이터가 제대로 도착할 것을 보장한다

## What is the CIDR notation of the 255.255.128.0 subnet mask?
- 255.255.128.0 => 11111111.11111111.10000000.00000000 => **/17** (총 17개 비트가 1이므로)

## What DHCP protocol does it use at the transport layer level?
- DHCP는 UDP 패킷을 이용하는 비연결형 서비스 모델을 기반으로 하므로, **UDP**

## If the IP address 123.48.189.194/21 is assigned to an Ethernet port of a router, what host address could communicate with it?
- 123.48.189.194/21 은 CIDR notation에 의해 11111111.11111111.11111000.00000000 서브넷 마스크를 가짐
	- => 255.255.248.0
	- 따라서 123.48.189.194와 255.255.248.0을 and연산 취하면
	- 0111 1011.	0011 0000.		1011 1101.		1100 0010
	- 1111 1111.	1111 1111.		1111 1000.		0000 0000
	- 0111 1011.	0011 0000.		1011 1000.		0000 0000 => 123.48.184.0 ~ 123.48.191.255
	- 해당 범위에 속하는 **123.48.189.109**가 정답

## Which of the following IP addresses is a private address?
- 10.0.0.0 ~ 10.255.255.255 범위에 속하는 **10.166.25.20**

## Which of the following propositions is not true?
1. UDP is faster, simpler and more efficient than TCP
	- UDP는 에러 체크를 거의 다 스킵하는 대신 훨씬 빠르고 효율적인 통신을 지향하므로 맞는 정답
2. UDP only has the basic error control mechanism
	- UDP는 헤더 체크 등 간단한 에러 체크만 진행하므로 맞다
3. UDP is a datagram oriented protocol
	- TCP는 세그먼트, UDP는 이름에서부터 User Datagram Protocol이므로 맞다
4. **UDP does not support broadcasting**
	- UDP는 실시간 스트리밍 등 Broadcast 시에도 널리 사용되므로, 오답

## You want to implement a mechanism that automates IP configuration, including IP address, subnet mask, default gateway and DNS information. What protocol will you use to achieve this?
- IP 설정 (IP 주소, 서브넷마스크, 게이트웨이 및 DNS 설정) 을 자동화해주는 프로토콜은 **DHCP**

## You have an interface on a router with the IP address of 240.19.3.205/12. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?
- 240.19.3.205/12 => subnet mask : 11111111.11110000.00000000.00000000
- => 256 * 256 * 16 - 2 = 1048576 - 2 = **1048574**

## Which of the following proposals is the valid host range for the subnet on which the IP address 158.167.18.156/15 resides?
- 158.167.18.156/15 => subnet mask : 11111111.11111110.00000000.00000000
- => **158.166.0.1 ~ 158.167.255.254**까지의 호스트 주소를 가질 수 있음 (0.0과 255.255는 이미 지정된 주소이므로 사용 불가)

## Which of the following propositions is not true?
1. **TCP is a datagram oriented protocol**
	- TCP는 datagram이 아닌 segment를 사용하므로 오답
2. TCP does not support broadcasting
	- 브로드캐스팅을 지원하는 것은 UDP
3. TCP provides extended error checking mechanisms. This is because it provides flow control and data acknowledgement
	- ACK 사용하므로 정답 (위에도 있음)
4. Data sequencing is a TCP feature (this means that packets arrive in order in the recipient)
	- 데이터가 순서대로 도착하는 것을 보장하므로 정답
5. TCP is reliable because it guarantees the delivery of data to the router of the destination
	- 데이터가 안전하게 라우터에 도착하는 것을 보장하므로 정답
6. TCP is comparatively slower than UDP
	- 에러 체크 및 재전송 등의 작업이 더 들어가므로, 당연히 느리다

## Which of the following proposals is a private IP address?
- 172.16.0.1 ~ 172.31.255.254 범위 안에 포함된 **172.27.217.52**

## What is the network address of a host with an IP address of 107.212.146.212/25?
- 107.212.146.212/25 => subnet mask : 11111111.11111111.11111111.10000000
- => 107.212.146.129 ~ 107.212.146.254 까지의 호스트 주소를 가질 수 있음
- 이때 네트워크 주소는 앞의 25자리인 107.212.146.128

## What is the network address of a host with an IP address of 182.161.121.118/24?
- 182.161.121.118/24 => subnet mask : 11111111.11111111.11111111.00000000
- => 182.161.121.1 ~ 182.161.121.254까지의 호스트 주소를 가질 수 있음
- 이때 네트워크 주소는 앞의 24자리인 182.161.121.0

## What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.224.0.0 subnet mask?
- 255.224.0.0 => 11111111.11100000.00000000.00000000
- => 256 * 256 * 32 - 2 = 2097152 - 2 = 2097150

## Which of the following propositions is not true?
1. UDP is faster, simpler and more efficient than TCP
2. **UDP provides extended error checking mechanisms. This is because it provides flow control and data acknowledgement**
	- 추가적인 에러체크를 진행하는건 TCP
3. UDP is a datagram oriented protocol
4. UDP supports broadcasting

## What is the broadcast address of a host with an IP address of 51,254,122,100/24?
- 51.254.122.100/24 => subnet mask : 11111111.11111111.11111111.00000000
- => 51.254.122.1 ~ 51.254.122.254까지의 호스트 주소를 가질 수 있음
- 이때 브로드캐스트 주소는 맨 마지막 옥텟을 전부 1로 채워넣은 **51.254.122.255**

## Which of the following proposals is the valid host range for the subnet on which the IP address 233.249.146.36/21 resides?
- 233.249.146.36/21 => subnet mask : 11111111.11111111.11111000.00000000
- => **233.249.144.1 ~ 233.249.151.254**까지의 호스트 주소를 가질 수 있음

## Which of the following proposals is a private IP address?
- 10.0.0.0 ~ 10.255.255.255 범위에 속하는 **10.182.204.132**

## You have an interface on a router with the IP address of 124.144.156.248/21. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?
- 124.144.156.248/21 => subnet mask : 11111111.11111111.11111000.00000000
- => 8 * 256 - 2 = 2048 - 2 = 2046

## What are the different layers of the OSI model?
- 7계층 : Application
- 6계층 : Presentation
- 5계층 : Session
- 4계층 : Transport
- 3계층 : Network
- 2계층 : Data link
- 1계층 : Physical
- 7부터 1까지 순서대로 적힌 **Application - Presentation - Session - Transport - Network - Data Link - Physical**이 정답

## What is the network address of a host with an IP address of 45.195.37.187/16?
- 45.195.37.187/16 => subnet mask : 11111111.11111111.00000000.00000000
- => 45.195.0.1 ~ 45.195.255.254까지의 호스트 주소를 가질 수 있음
- 이때 네트워크 주소는 뒤의 두 옥텟을 전부 0으로 채워넣은 **45.195.0.0**

## What is the size of an IPV4 address?
- **32비트**

## What is the size of an IPV6 address?
- **128비트**

## Which protocol does Ping use?
- 핑 유틸리티는 **ICMP** 반향 패킷을 이용 (TCP/IP에서 패킷이 목적지에 도달했나만 체크하는 프로토콜)

## What is the CIDR notation of the 255.255.192.0 subnet mask?
- 255.255.192.0 => 11111111.11111111.11000000.00000000 => **/18**

## What is the default IP address class available?
- 디폴트는 클래스 **C**

## What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.255.128 subnet mask?
- 255.255.255.128 => 11111111.11111111.11111111.10000000
- => 128 - 2 = **126**

## What is the network address of a host with an IP address of 166.175.144.121/23?
- 166.175.144.121/23 => subnet mask : 11111111.11111111.11111110.00000000
- => 166.175.144.1 ~ 166.175.145.254까지의 호스트 주소를 가질 수 있음
- 이때 네트워크 주소는 뒤의 옥텟을 0으로 채워넣은 **166.175.144.0**

## Which of the following proposals is the valid host range for the subnet on which the IP address 1.93.149.6/17 resides?
- 1.93.149.6/17 => subnet mask : 11111111.11111111.10000000.00000000
- => **1.93.128.1 ~ 1.93.255.254**까지의 호스트 주소를 가질 수 있음
