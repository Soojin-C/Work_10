#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int randomInt(){

  int fd = open( "/dev/random", O_RDONLY );
  int * pointer = malloc(sizeof(int));
  read(fd, pointer, sizeof(int));

  //printf("%d\n", *pointer);
  close(fd);
  if (*pointer < 0){
    *pointer = randomInt();
  }
  return *pointer;

}


int main(){

  int array1[10];
  int * pointer = calloc(10, sizeof(int));
  pointer = array1;
  int counter = 0;
  printf("Generating numbers for array1\n");
  while (counter < 10){

    int rand = randomInt();
    array1[counter] = rand;
    printf("- %d -  random number : %d \n", counter, array1[counter]);
    array1[counter] = rand;
    counter += 1;
    
  }

  int fd = open("text.txt", O_CREAT | O_WRONLY, 0777);

  //printf("%d", *pointer);
  write(fd, pointer, sizeof(int) * 10);

  close(fd);

  fd = open("text.txt", O_RDONLY);

  printf("\n\nReading Numbers:\n");

  int arrayRet[10];
  int * pointerRet = arrayRet; 
  read (fd, pointerRet, sizeof(int ) * 10);

  counter = 0;

  while (counter < 10){

    printf("- %d -  random number : %d \n", counter, arrayRet[counter]);
    counter += 1;
    
  }

  close(fd);
  
  return 0;

}
