# ft_server
ft_server is to create a web server with Nginx capable of running a WordPress website, phpMyAdmin, and a MySQL database.

This server will run in only one Docker container, under Debian Buster.

## How to use
1) Build Docker image
```
docker build -t ft_server .
```
2) Run the container
```
docker run --name ft_server -d -p 443:443 -p 80:80 ft_server
```
Option) Autoindex OFF

Default AUTOINDEX is on. If you want to run the container setting autoindex off:
```
docker run --env AUTOINDEX=off --name ft_server -d -p 443:443 -p 80:80 ft_server
```

## Check startup using a browser
- http://localhost/
- http://localhost/phpmyadmin
- http://localhost/wordpress
