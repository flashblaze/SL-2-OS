#include "stdio.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "sys/types.h"

main(){
     
     int shmid,size;
     key_t key;
     char *shm, *s;

     key = 1234;
     size = 30;

     shmid = shmget(key, size, IPC_CREAT|0666);
     if(shmid < 0){
          printf("Error in shmget() server...%d\n",shmid);
          return;
     }

     shm = shmat(shmid, NULL, 0);
     if(shm == (char*)-1){
          printf("Error in shmat() server...\n");
          return;
     }

     s = shm;
     printf("Enter a message to client -> ");
     scanf("%s", s);


     // Wait for client to recieve
     while(*shm != '*')
          sleep(1);

     exit(0);
}
