#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity. Do not change these variables.
int avgNum;
int minNum;
int maxNum;

// Functions' declaration. Definition is at the bottom. Do not change the declaration of these functions.
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char* argv[])
{
 
 /* Create thread IDs */


/* Create thread attributes */


/* Initialize thread attributes */


/* Create threads */


/* Wait for threads to exit */


// Printing the results. Do not change this line
printf("%d %d %d", avgNum, minNum, maxNum);
}

void *avgfunc(void *param)
{
    /* Write the code to calculate the average value and store it in avgNum variable. */
    /* Hint: the numbers supplied on the command line as arguments are passed to this function through the pointer param. You need to find a way to access
    these numbers through the pointer param */ 

}

void *minfunc(void *param)
{  
    /* Write the code to calculate the minimum value and store it in minNum variable */
    /* Hint: the numbers supplied on the command line as arguments are passed to this function through the pointer param. You need to find a way to access
    these numbers through the pointer param */ 
 
 
}

void *maxfunc(void *param)
{
    /* Write the code to calculate the maximum value and store it in maxNum variable */
    /* Hint: the numbers supplied on the command line as arguments are passed to this function through the pointer param. You need to find a way to access
    these numbers through the pointer param */ 
 
 
}
