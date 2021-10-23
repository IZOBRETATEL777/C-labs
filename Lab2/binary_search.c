#include "binary_search.h"
#include <stddef.h> // for NULL

int* binarySearch(int* array, int size, int numberToSearch) {
   int l = -1, r = size, m;
   while (r - l > 1) {
      m = l + (r - l) / 2;
      if (array[m] < numberToSearch) {
          l = m;
      }
      else {
          r = m;
      }
   }
   if (r < size && array[r] == numberToSearch) {
       return &array[r];
   }
   else {
       return NULL;
   }
}
