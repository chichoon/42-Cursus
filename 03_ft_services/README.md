# kubernetes에 익숙해지기



# 평가
- 클러스터를 만드세요.
- 셋업해야 하는 것들
	- 쿠버네트 웹 대시보드
	- 로드 밸런서 (밖에서 클러스터에 접근하기 위한 툴)
	- 워드프레스 웹사이트 (mySQL 데이터베이스 사용)
	- phpMyAdmin (mySQL 데이터베이스와 연결하여 사용)
	- annginx를 사용한 컨테이너
	- FTPS 서버, 포트는 21
	- Grafana 플랫폼
	- 크래시나 서버 종료를 대비한 데이터 보존
	- 어느 한 부분에서 크래시나 중단이 일어날 경우 컨테이너는 다시 작동해야 합니다

# 평가 시트
Preliminaries
If cheating is suspected, the evaluation stops here. Use the "Cheat" flag of the scale. Please do this calmly, wisely and with caution.

Simple preliminaries
- Defense can only happen if the student being evaluated is present. This way everybody progresses: by exchanging ideas and sharing knowledge with each other.
- Nothing submitted (or wrong file or directory): 0, the evaluation is over.
- As soon as you come accross an exercise that isn't fully functional, the evaluation stops. The following exercises won't be evaluated.
- In order to grade your peer, you have to clone their git repository on their station.
General instructions
General instructions
- Check if all the necessary configuration files of your application are in the folder srcs.
- Check if the setup.sh file is at the root of the repository.
- Execute "setup.sh"
Mandatory part
This project consist of clusturing an application and deploying it with Kubernetes. Check if all the next points are respected. At the first error, you stop the correction and put a zero.

Services environment
- Verify if the application is deployed with all containers only with "setup.sh" script.
- Check using the dashboard if the evaluated has all the different containers.
They are nginx, ftps, wordpress, phpmyadmin, mysql, grafana, influxDB.
These containers must have the same name. If this is not the case or if a container is missing, the correction stops.
- Check if all containers are build with Alpine Linux. If not, the correction stops here.
- Also, check that each container has its Dockerfile, which was built using setup.sh.
The evaluated have to build himself the images that he will use. It is forbidden to take already build images
or use services like DockerHub.

If one is missing, or if one does not start with "FROM: alpine" or any other local image, the correction stops here.
Expose it !
- Check that redirections to your services are done with a Load Balancer.
To do that use "kubectl get services":
Grafana, ftps, Wordpress, phpmyadmin & nginx must be "LoadBalancer" type and EXTERNAL-IP field cannot be 127.0.0.1 or end with .0 or .255.
Influxdb & mysql must be "ClusterIP" type.
Other entry can appear, but none must be "NodePort" type.
Also, check that "setup.sh" file don't use any "kubectl port-forward" command.
Nginx
- Try to access http (port 80) and verify that you are automatically redirected to https (port 443).
Then, execute the command "curl -I (i) http://IP" and check if return code is a
"301 Moved Permanently" and the "Location" line is the same IP but in https.
Page displayed does not matter, as long it's not a web error (404, 503 etc).
SSL certificate are not necessarily recognized, certificate error on https is normal.
Check that nginx redirects on a /wordpress route with a "307 redirect" and on a /phpmyadmin route with a "reverse proxy".
If one point listed previously differ, the correction stops.
FTP(s) server
- Check if the FTPS server is listening on port 21. Make sure it is a FTPS server (s for secure)
and not a basic FTP server.
If the FTPS server does not work as it should, the correction stops here.
- Check if you can upload and download files without any errors.
Hello Word(Press), MySQL and PhpMyAdmin
- Check if the WordPress website works under port 5050. Connect to it using the administrator account,
check if several users is present, after leave a comment under post. Make sure your comment is added to the database entries.
For that, you can access PhpMyAdmin interface, must be under port 5000 and check the database ("wp_comments" table).
Wordpress and PhpMyAdmin needs its own nginx server.
The database must persist in case failure.
To test this, you can remove the MySQL container with the Kubernetes dashboard.
It must recreate itself automatically, after check if your comment is still in the database.
If something does not work as expected, the correction stops here.
Grafana and InfluxDB
- Check if grafana is running under port 3000. Connect to the interface.
You have to check if grafana is monitoring all containers. To do that search for the dashboard list,
click on the dashboards one by one.
Like MySQL database, after deleting the InfluxDB container, check that the data prior to deletion is still present in Grafana.
If something does not work as expected, the correction stops here.
Persistence!
- Check that in the event of a crash/shutdown of one of the services, the associated container relaunches correctly.
To do this, use "kubectl exec deploy/SERVICE -- pkill APP" (replacing SERVICE and APP of course).
Stop web containers (usually nginx or php-fpm APP) and stop grafana APP for this same container.
Stop the ftps server (usually vsftpd APP).
Stop mysqld and influxd APP for corresponding databases (recheck if the data persists).
If a container hasn't relaunched after several minutes, if the MySQL or InfluxDB data is lost
or if a service has restarted badly (in particular ftps), the correction stops here.
