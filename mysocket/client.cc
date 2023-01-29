#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) { 
    std::cout << "socket start failed" << std::endl;
    return -1; 
  }
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(8999);
  if (connect(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr)) != 0) { 
    cout << "connect server failed!" << endl;
    close(sockfd); 
    return -1; 
  }

  char buffer[1024];
  strcpy(buffer, "client_send,\n");
  while(true) {
    int iret;
    // memset(buffer, 0, sizeof(buffer));
    // strcpy(buffer, "client_send");
    // cin >> buffer;
    iret = send(sockfd, buffer, sizeof(buffer), 0);
    if (iret < 0) {
      cout << "send failed!" << endl;
      break;
    }
    // memset(buffer,0,sizeof(buffer));
    // iret = recv(sockfd, buffer, sizeof(buffer), 0);
    // if ( iret <= 0) {
    //    cout << "recv failed!" << endl; 
    //    break;
    // }
    // cout << "RECV: " << buffer << endl;
  }
  close(sockfd);
  return 0;
}
