#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>

int Socket(const char* host, int port){
    int sock; 
    unsigned long inaddr;
    struct sockaddr_in ad;
    struct hostent *hp; 

    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;
    
    inaddr = inet_addr(host);
    if (inaddr != INADDR_NONE) {
        memcpy(&ad.sin_addr, &inaddr, sizeof(inaddr)); 
    } else {
        hp = gethostbyname(host); 
        if(hp == NULL) return -1;  
        memcpy(&ad.sin_addr, hp->h_addr, hp->h_length); 
    }
    
    ad.sin_port = htons(port);

    sock = socket(AF_INET, SOCK_STREAM, 0);  
    
    if(sock < 0) {
        return sock;
    }
    
    if(connect(sock, (struct sockaddr *)&ad, sizeof(ad)) < 0) {
        return -1;
    }
    
    return sock;
}
