#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity. Do not change these variables.
int avgNum;
int minNum;
int maxNum;

// Define a struct to pass multiple arguments to the thread functions
struct ThreadParams {
    int argc;
    char** argv;
};

// Functions' declaration. Definition is at the bottom. Do not change the declaration of these functions.
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char* argv[])
{
    // Create thread IDs
    pthread_t avgThread, minThread, maxThread;

    // Create thread attributes
    pthread_attr_t attr;

    // Initialize thread attributes
    pthread_attr_init(&attr);

    // Create threads and pass argc and argv as arguments
    struct ThreadParams params;
    params.argc = argc;
    params.argv = argv;

    pthread_create(&avgThread, &attr, avgfunc, &params);
    pthread_create(&minThread, &attr, minfunc, &params);
    pthread_create(&maxThread, &attr, maxfunc, &params);

    // Wait for threads to exit
    pthread_join(avgThread, NULL);
    pthread_join(minThread, NULL);
    pthread_join(maxThread, NULL);

    // Destroy thread attributes
    pthread_attr_destroy(&attr);

    // Printing the results. Do not change this line
    printf("Average: %d\nMinimum: %d\nMaximum: %d\n", avgNum, minNum, maxNum);

    return 0;
}

void *avgfunc(void *param)
{
    struct ThreadParams* params = (struct ThreadParams*)param;
    char** args = params->argv;

    // Initialize variables for calculating the average
    int sum = 0;
    int count = 0;

    // Loop through the arguments and calculate the sum and count
    for (int i = 1; i < params->argc; i++) {
        sum += atoi(args[i]);
        count++;
    }

    // Calculate and store the average if count is not zero
    if (count != 0) {
        avgNum = sum / count;
    }

    pthread_exit(NULL);
}

void *minfunc(void *param)
{  
    struct ThreadParams* params = (struct ThreadParams*)param;
    char** args = params->argv;

    // Initialize variable for storing the minimum value
    minNum = atoi(args[1]); // Initialize with the first argument

    // Loop through the arguments and find the minimum
    for (int i = 1; i < params->argc; i++) {
        int num = atoi(args[i]);
        if (num < minNum) {
            minNum = num;
        }
    }

    pthread_exit(NULL);
}

void *maxfunc(void *param)
{
    struct ThreadParams* params = (struct ThreadParams*)param;
    char** args = params->argv;

    // Initialize variable for storing the maximum value
    maxNum = atoi(args[1]); // Initialize with the first argument

    // Loop through the arguments and find the maximum
    for (int i = 1; i < params->argc; i++) {
        int num = atoi(args[i]);
        if (num > maxNum) {
            maxNum = num;
        }
    }

    pthread_exit(NULL);
}

