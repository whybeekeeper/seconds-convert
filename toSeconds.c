/* toSeconds.c
* takes a txt file, converts from regular time
* to # of seconds, and then rewrites to the file
* author - soma hannon
* version - 09/27
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *inptr;
  FILE *outptr;
  char temp[7];
  int arr[2392];
  int *aptr;
  int seconds = 0;
  int x = 0;
  aptr = arr;

  // opens for reading file named "minutes.txt"
  inptr = fopen("minutes.txt", "r");

  // catches open error so the program won't freak out on compiling
  if (inptr == NULL) {
    printf("error opening file!\n");
    // exits if file pointer returns null
    exit(1);
  }

  while (fscanf(inptr, "%s", temp) != EOF) {
    //iterates thru string and calculates seconds from the minutes, stores it in variable seconds
    for(int i = 0; i < 7; i++) {
      x = atoi(&temp[i]);

      if(i == 0) {
        seconds += x*60*60;
      }

      if(i == 2) {
        seconds += x*60;
      }

      if(i == 5) {
        seconds += x;
      }
    }

    *aptr = seconds;
    aptr++;
    x = 0;
    seconds = 0;
  }

  fclose(inptr);
  // creates and opens for writing file named "seconds.txt"
  outptr = fopen("seconds.txt", "w");

  aptr = arr;
  for(int i = 0; i < 2392; i++) {
    fprintf(outptr, "%d\n", *aptr);
    aptr++;
  }

  return(0);
}
