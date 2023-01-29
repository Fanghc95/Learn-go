/*
 * @Author: fanghaocheng 
 * @Date: 2023-01-28 21:51:20 
 * @Last Modified by: fanghaocheng
 * @Last Modified time: 2023-01-29 09:24:17
 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main() {
  int socket_fd = socket(AF_INET,SOCK_STREAM,0);
  if (socket_fd == -1) {
    std::cout << "error create socket fd!" << std::endl;
    return -1;
  }
  // 定义server地址
  sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(8999);
  // 绑定套接字到socket上
  if (bind(socket_fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) != 0) {
    std::cout << "bind failed" << std::endl;
    return -1;
  }
  // 开启监听
  if (listen(socket_fd, 10)) {
    std::cout << "Listen Failed!" << std::endl;
    close(socket_fd);
    return -1;
  }

  int client_fd;
  sockaddr_in clientaddr;
  int socklen = sizeof(struct sockaddr_in);
  client_fd = accept(socket_fd, (struct sockaddr*)&clientaddr, (socklen_t *)&socklen);
  if (client_fd == -1) {
    std::cout << "connected Failed!" << std::endl;
    return -1;
  }
  char buffer[1024];
  while(true) {
    memset(buffer, 0, sizeof(buffer));
    int iret = recv(client_fd, buffer, 1024, 0);
    if (iret < 0) {
      std::cout << "recv Failed!" << std::endl;
      break;
    }
    std::cout << "RECV: " << buffer << std::endl;
    // strcpy(buffer,"ok");
    // iret = send(client_fd, buffer, strlen(buffer), 0);
    // if (iret < 0) {
    //   std::cout << "send Failed!" << std::endl;
    //   break;
    // }
    // std::cout << "send OK!" << std::endl;
  }
  close(socket_fd);
  close(client_fd);
  return 0;
}

