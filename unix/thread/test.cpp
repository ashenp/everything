#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

void *thread(void *vargp);

char** ptr;

int main(int argc, char** argv) {
    int i;
    pthread_t tid;
    char *msgs[2] = {
        "Hello from foo",
        "Hello from bar"
    };
    
    ptr = msgs;
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&tid, NULL, thread, (void *)i);
    }
    
    pthread_exit(NULL);
        
    return 0;
}


void *thread(void *vargp) {
    long myid = (long)vargp;
    static int cnt = 0;
    printf("[%ld] : %s (cnt = %d)\n", myid, ptr[myid], ++cnt);
    return NULL;
}
