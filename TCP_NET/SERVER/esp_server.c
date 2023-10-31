//lib_declare-----------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <inttypes.h>
//----------------------


/*
----------server_process----------
create_socket
|
bind_address
 |
listen_for_connection
  |
accept_connection
        |
Read_&_Write_process
|
Close/end_connection
*/


//declare_req
char ip[12]="127.0.0.1";
int port=2000,s_sock;
struct sockaddr_in s_addr;


//------------------START-------------------
int main(){

 //create_socket
 s_sock=socket(AF_INET,SOCK_STREAM,0);

        //net_properties
        s_addr.sin_family=AF_INET;
        s_addr.sin_port=htons(port);
        inet_aton(ip,&s_addr.sin_addr);

 //binding
 bind(s_sock,(struct sockaddr*)&s_addr,sizeof(s_addr));

 //listening
 listen(s_sock,3);


 //accepting
 int esp_sock=accept(s_sock,NULL,NULL);



 //R&W
 uint32_t count;

 //while(1){
        recv(esp_sock,&count,sizeof(count),0);
        fprintf(stdout,"%d\n",count);
//}

 close(s_sock);

 return 0;
//---------------------END---------------------
}
