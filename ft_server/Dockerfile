# get image
FROM	debian:buster

#install tools
RUN	apt-get -y update &&\
	apt-get -y upgrade &&\
	apt-get -y --no-install-recommends -y install \
	nginx \
	openssl \
	supervisor \
	mariadb-server mariadb-client \
	php-cgi php-common php-fpm php-pear \
	php-mbstring php-zip php-net-socket \
	php-gd php-xml-util php-gettext php-mysql php-bcmath \
	unzip wget git ca-certificates;

# setting SSL
RUN	mkdir /etc/nginx/ssl &&\
	openssl genrsa -out /etc/nginx/ssl/nginx-ssl.key 2048 &&\
	openssl req -new -key /etc/nginx/ssl/nginx-ssl.key -out /etc/nginx/ssl/nginx-ssl.csr \
	-subj "/C=JP/ST=Tokyo/L=Minato/O=42Tokyo/OU=42Student/CN=localhost" &&\
	openssl x509 -days 3650 -req -signkey /etc/nginx/ssl/nginx-ssl.key \
	-in /etc/nginx/ssl/nginx-ssl.csr -out /etc/nginx/ssl/nginx-ssl.crt;

# set database
RUN	set -ex; \
				service mysql start; \
				mysql -e "CREATE DATABASE wpdb"; \
				mysql -e "GRANT ALL ON wpdb.* TO 'wpuser'@'localhost' IDENTIFIED BY 'dbpassword';"; \
				mysql -e "FLUSH PRIVILEGES";

# install WordPress
RUN	set -ex; \
				wget -O wordpress.tar.gz https://wordpress.org/latest.tar.gz; \
				tar -xvf wordpress.tar.gz -C /var/www/html/; \
				rm wordpress.tar.gz;
COPY	./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# install phpmyadmin
WORKDIR /tmp/
RUN	set -ex; \
				wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
				tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz; \
				rm phpMyAdmin-5.0.2-all-languages.tar.gz; \
				mv phpMyAdmin-5.0.2-all-languages phpmyadmin; \
				mv phpmyadmin /var/www/html/;
COPY	./srcs/config.inc.php /var/www/html/phpmyadmin/

# install entrykit
RUN	set -ex; \
				wget -O entrykit.tgz https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz; \
				tar -xvf entrykit.tgz -C /bin; \
				rm -rf entrykit.tgz; \
				chmod +x /bin/entrykit; \
				entrykit --symlink;

# change owner
RUN	set -ex; \
				chown -R www-data:www-data /var/www/html/*;

# set supervisord
COPY	./srcs/default.tmpl /etc/nginx/sites-available/
COPY	./srcs/supervisord.conf /etc/supervisor/conf.d/
RUN		chmod +x /etc/supervisor/conf.d/supervisord.conf;

# service start
ENTRYPOINT ["render", "/etc/nginx/sites-available/default", "--", "/usr/bin/supervisord"]

# expose
EXPOSE 80 443
