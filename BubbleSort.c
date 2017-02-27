#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);

int main(int argc, char *argv[])
{

	if(argc != 2)
    {
		fprintf(stderr, "FORMAT: ./BubbleSort ARRAY_SIZE \n");
		exit(-1);
   	}
	
	int ARRAY_SIZE = atoi(argv[1]);
	int array[ARRAY_SIZE], c, d, swap;
	
	struct timespec start1, finish1;
    double elapsed1;
 
	for (c = 0; c < ARRAY_SIZE; c++)
		array[c] = (c+5)*9;
		
	clock_gettime(CLOCK_MONOTONIC, &start1);
 
	for (c = 0; c < (ARRAY_SIZE - 1); c++)
	  {
	    for (d = 0; d < ARRAY_SIZE - c - 1; d++)
		   {
      			if (array[d] > array[d+1]) 
      			{
        			swap = array[d];
        			array[d] = array[d+1];
        			array[d+1] = swap;
      			}	
    		}
  	  }	
  	  
 	clock_gettime(CLOCK_MONOTONIC, &finish1);
    elapsed1 = (finish1.tv_sec - start1.tv_sec);
    elapsed1 += (finish1.tv_nsec - start1.tv_nsec)/1000000000.0;
	double perIter = (double) (elapsed1);
	
//	printf("Sorted list in ascending order:\n");


//	for ( c = 0 ; c < ARRAY_SIZE; c++ )
//    	 printf("%d\n", array[c]);
    	 
    printf("Total time taken: %lf \n", perIter);
 
  return 0;
}
