# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start_server.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 15:59:20 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/06 16:42:17 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

source ~/Documents/42c/50_pythonpiscine/django_venv/bin/activate
./init_docker.sh
docker ps
docker pull debian:buster
docker run -it -p 80:80 -p 443:443 debian:buster
apt-get -y update
apt-get -y install nginx python3 vim
service nginx start
service nginx status
apt install build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev libsqlite3-dev libreadline-dev libffi-dev curl libbz2-dev
apt install wget build-essential libreadline-gplv2-dev libncursesw5-dev
wget https://www.python.org/ftp/python/3.9.1/Python-3.9.1.tgz
tar xzf Python-3.9.1.tgz
cd Python-3.9.1
./configure --enable-optimizations
make -j 2
