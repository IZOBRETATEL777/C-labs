#include <stdio.h> // for printf 
#include <stdlib.h> // for atoi
#include "sorting.h"

int main(int n, char** argv){ // ["./sort", "32", "12", "1", "4", "5","1", "-1"]

 if (n < 2) {
      printf("Data is insuffient! Please insert proper input at command line. \n");
			return 0;
 }

	int array[n-1];

	for (int i = 0; i < n-1; i++){ // argv[1] = "32"
	   array[i] = atoi(argv[i+1]); // array[0] = atoi("32")
  }
  
  sort(array, n-1);

  for (int i = 0; i < n-1; i++){
	   printf("%d ", array[i]);
  }  

  return 0;

}
