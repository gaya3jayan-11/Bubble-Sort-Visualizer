#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 1000000 //1second=1000000ms

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void delay(int microseconds){
    for(int i=0;i<microseconds*1000;i++); //gives delay of 1 sec approx, nanoseconds=microseconds*1000
}

void printArray(int arr[], int size, int highlight1, int highlight2){
    for(int i=0;i<size;i++){
        if(i==highlight1 || i==highlight2)
            printf("\x1b[32m%d \x1b[0m", arr[i]); //prints txt in green colour
        else
            printf("%d ",arr[i]);
    }
    printf("\r"); //carriage return char, takes cursor back to start of statement
    fflush(stdout); //flushing o/p to make it visible immediately; printf takes buffer time
}

void bubbleSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]); //user defined, sending address
                printArray(arr,size,j,j+1);
                delay(DELAY_MICROSECONDS); //user defined
            }
        }
    }
}


int main(){
    srand(time(NULL));
    int arr[ARRAY_SIZE];
    for (int i=0;i<ARRAY_SIZE;i++) //generates 10 random numbers in between 1 and 100
        arr[i]=rand() %100;
    printf("Original Array: ");
    printArray(arr,ARRAY_SIZE,-96,-96); //user defined
    printf("\n");
    printf("Sorting steps: \n");
    bubbleSort(arr,ARRAY_SIZE); //user defined
    printf("\nSorted array:\t");
    printArray(arr,ARRAY_SIZE,-96,-96);
    printf("\n");
    return 0;
}