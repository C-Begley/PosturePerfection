#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h> 
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h> 
#include <netinet/in.h> 

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting Pi Client.";
    int port = 51255;
    int client_fd = socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    int addrlen = sizeof(address);
    int server_connect = inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    int connection = connect(client_fd, (struct sockaddr *)&address, sizeof(address));
    if (connection != 0 ){ cerr << "Error connecting, Err Code : " << connection;}
    send(client_fd , "Hello" , sizeof("Hello") , 0 ); 
    char buffer[1024] ;
    int valread = read(client_fd , buffer, 1024); 
    cout << buffer;
    shutdown(client_fd, SHUT_RDWR);
    close(client_fd);
    return 0;
     
}