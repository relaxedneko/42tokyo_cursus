# ft_server

This subject is to create a web server with Nginx capable of running a WordPress website, phpMyAdmin, and a MySQL database.
This server will run in only one Docker container, under Debian Buster.

## How to use
Build Docker image
```
docker build -t ft_server .
```
Run the container
```
docker run --name ft_server -d -p 443:443 -p 80:80 ft_server
```

## How to checkthe operation
You can check it using a web browser at the following URLs.
```
http://localhost/
```
```
http://localhost/pypmyadmin
```
```
http://localhost/wordpress
```
