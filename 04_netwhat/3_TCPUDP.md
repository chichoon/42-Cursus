# netwhat

## Connection-Oriented Protocol
- 연결지향 프로토콜
- TCP, SCTP, RTP가 속해 있음
- Connectionless Protocol에 기반을 두고 있음
- 1:1로 연결 상태를 유지하여 통신함
	- 연결을 유지하기 위한 비용이 들기 때문에 더 비싸다
	- 연결이 되어있는 상태라서 누가 어떤 데이터를 보냈는지 연결을 통해 알 수 있다
	- 대신 추가적인 자원 할당 및 연결 설정이 필요함
- 송신자와 수신자 사이에 먼저 연결이 설정된 후, 데이터가 전송되기 시작
- 길고 안정적인 통신에 적합하다
- Connection Oriented Protocol에서 사용하는 주된 기능
	- Connection Management
	- Connection Multiplexing
	- Segmentation
	- Reliable Delivery
	- Flow Control, Congestion Control

## Connectionless Protocol
- 비연결 프로토콜
- UDP 등이 속해 있음
- 수신 컴퓨터에 단방향 데이터그램을 보내고, 데이터가 제대로 전송되었는지는 알리지 않음
	- 당연히 수신 컴퓨터 측에서도 송신 컴퓨터에 데이터의 상태 정보를 반환하지 않음

## TCP
- Transmission Control Protocol, 전송 제어 프로토콜
- 전송계층의 통신 프로토콜 중 하나
- 프로세스 상호간 신뢰적인 연결지향성 서비스 제공
	- 신뢰적이라 함은, 패킷 손실, 중복, 순서바뀜 등이 없도록 보장한다는 뜻 (Ack 이용)
	- TCP 하위계층인 (3계층) IP계층의 신뢰성 없는 서비스에 대해 보완함으로써 신뢰성 제공
	- 연결지향적이라 함은, UDP와 달리 느슨한 연결을 가지므로 연결 관리를 위한 설정 및 해제가 필요
- 신뢰적인 전송을 보장하기 때문에, 어플리케이션 구현이 쉬워짐
	- Segment라 불리는 패킷을 전송하며, 세그먼트 내에 Checksum 및 각 바이트마다 일정한 Sequence Number를 할당함으로써 데이터가 순서대로 도착하지 않았을 때나 데이터 손상 등을 바로 잡아낼 수 있다
	- 모든 세그먼트가 잘 도착하였는지 알기 위해 Acknowledgement & Retransmission 매커니즘 사용
- 그 외에, Flow control, Congestion Control, Connection Service 등의 특징을 가짐
	- Flow control (흐름 제어)
		- TCP 데이터의 세그먼트를 송수신하는 컴퓨터는 CPU차이, 네트워크 대역폭 차이 등의 이유로 속도 차이가 있을 수 있다
		- 이때 송신 측의 속도가 너무 빠르면 수신 측이 받을 때 수용 가능한 용량을 초과해서 과도한 데이터를 보낼 수 있고, 이러한 이유로 데이터가 손실될 수 있기 떄문에 데이터 전송량을 수신 측에 따라 조절해야 함
		- 송신 측의 데이터 양을 제어하는 기능이 Flow Control이다
		- 내부적으론 Stop and wait, Sliding Window 등의 방식 사용
	- Congestion Control (혼잡 제어)
		- 네트워크 부하가 늘어나면서 생긴 매커니즘
		- 송신 측이 100만큼의 데이터를 받고 싶다면, 처음엔 5씩 보내면서 수신 측의 상태를 체크하고 잘 수신된다 싶으면 점점 양을 늘려가면서 데이터를 전송함
		- 이때 수신 측에서 수신이 잘 안된다고 판단되면 데이터의 양을 다시 줄여가면서 송신함
		- 내부적으론 AIMD (Addictive Increase / Multicative Decrease) 방식을 사용
	- Connection Service (연결형 서비스)
		- TCP를 사용하여 데이터를 보내려면 수신 측과 연결 설정을 완료해야 하기 때문에, 3-way Handshaking 이용하여 연결을 설정한다.
- 헤더는 20바이트
- 웹 브라우저로부터 월드 와이드 웹 서버에 연결할 때나, 이메일 전송, 파일 전송 등에 사용됨

### 3-way Handshaking
- 수신 측과 송신 측 간의 연결 설정을 하는 방식
1. Client는 Server에게 통신 요청을 개시하는 SYN과 첫 번째 세그먼트를 알리는 Seq(100) 전송
2. SYN을 수신한 Server는 이에 대한 응답으로 Client에게 Ack(101)와 Seq(200)을 전송, 자기 자신도 Client에게 통신요청을 개시하는 SYN 전송
3. SYN 수신한 Client는 이에 대한 응답으로 Server에 Ack(201)을 전송함으로써 통신 연결 성립

## UDP
- User Datagram Protocol, 사용자 데이터그램 프로토콜
- 전송계층의 통신 프로토콜 중 하나
- 신뢰성이 낮은 프로토콜으로 완전성을 보장 X
- 기본 IP 서비스에 선택적인 Checksum과 Port 기능을 추가함
	- Checksum은 TCP와 마찬가지로 고유 헤더와 데이터를 보호하기 위해 사용됨
	- Port는 데이터를 올바른 목적지 애플리케이션에 보내기 위해 필요
	- TCP와 달리, Ack 부분이 빠졌다고 생각하면 됨
- 또한, TCP와 달리 패킷에 Datagram 형식의 데이터가 들어감 (TCP는 세그먼트)
- 하지만 가상회선을 설정할 필요가 없고 유연하며 효율적인 데이터 전송에 사용됨
	- 신뢰성이 낮다 함은,
		- 메시지가 제대로 도착했는지 확인 X (확인응답 없음)
		- 수신된 메시지의 순서 맞추지 않음 (순서제어 없음)
		- 흐름제어를 위한 피드백을 제공하지 않음 (흐름제어 없음)
		- 검사합을 제외한 오류검출 및 제어 없음 (오류제어 거의 없음)
- 하지만 헤더가 단순하여 (8바이트) 헤더 처리에 많은 시간을 요하지 않고, 멀티태스킹 및 실시간 응용에 적합
- 1대 다수 통신에 적합하고, 빠른 요청과 응답이 필요한 경우에 사용하기 좋음 (예시: 실시간 스트리밍 등)
