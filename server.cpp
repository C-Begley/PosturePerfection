#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h> 
#include <netinet/in.h> 
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting server \n";
    int port = 51255;
    int server_fd = socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    int addrlen = sizeof(address);
    int binding  = bind(server_fd, (struct sockaddr *)&address,  addrlen);
    int listening = listen(server_fd, 2);
    int pi_fd = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen);

    char buffer[1024] ;
    int posture_value = read(pi_fd, buffer, 1024); 
    string buff (buffer);
    string start ("notify-send \"");
    string end ("\" -u critical");
    system((start + buff + end).c_str());
    cout << buff; 
    close(server_fd);
    close(pi_fd);
    return 0;
}