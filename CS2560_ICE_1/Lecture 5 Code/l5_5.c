//Arrays -- allocate one contiguous block of memory holding declaring multiple of one data type
//name of array used is an address of memory.
//Declaration with Assignment -- declaring 10 doubles
//double balance[10] = {1000.0, 2.0, 3.4, 7.0, 50.0};
//when using in calculation or assignment below recall always start at 0
//balance[0] = 1000.0 , balance[3] = 7.0, balance[7] = 0, balance[10] = error out of bounds
//Also acceptable because size will be known. Size will be 5 hence --> double balance[5]
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
//code example
#include <stdio.h>
int main () {
   int n[ 10 ]; /* n is an array of 10 integers */
   int i,j;
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < 10; i++ ) {
      n[ i ] = i + 100; /* set element at location i to i + 100 */
   }
   /* output each array element's value */
   for (j = 0; j < 10; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }
   return 0;
}
