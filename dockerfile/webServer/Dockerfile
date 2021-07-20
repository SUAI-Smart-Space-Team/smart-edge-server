FROM ubuntu:18.04 
ENV DEBIAN_FRONTEND noninteractive
RUN echo "Acquire::Check-Valid-Until \"false\";\nAcquire::Check-Date \"false\";" | cat > /etc/apt/apt.conf.d/10no--check-valid-until
RUN apt-get update && \
    apt-get upgrade -y
RUN apt-get -y install supervisor \
    apache2
RUN yes | apt install php
RUN yes | apt-get install php libapache2-mod-php php-mysql
RUN echo "ServerName chupr.iotfox.ru" >> /etc/apache2/apache2.conf
RUN yes | apt install curl && apt install unzip
RUN cd /var/www/html && curl -L -o site.zip https://github.com/SUAI-Smart-Space-Team/smart-edge-server/archive/dev.zip && unzip site.zip && mv /var/www/html/smart-edge-server-dev/* /var/www/html && rm -rf /var/www/html/smart-edge-server-dev index.html site.zip
EXPOSE 80
CMD  apache2ctl -D FOREGROUND
