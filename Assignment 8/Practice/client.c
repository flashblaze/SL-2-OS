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

     shmid = shmget(key, size, 0666);
     if(shmid < 0){
          printf("Error in shmget() client...\n");
          return;
     }

     shm = shmat(shmid, NULL, 0);
     if(shm == (char*)-1){
          printf("Error in shmat() server...\n");
          return;
     }

     printf("The string is....\n");
     for(s=shm; *s != NULL; s++){
          putchar(*s);
     }
     // mark as read
     *shm = '*';
     exit(0);
}
