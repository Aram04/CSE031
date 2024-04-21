#include <stdio.h>
#include <stdlib.h>


int* bubbleSort(int arr[], int n){

int temp, i = 0, j = 0;

int *s_arr = (int*)malloc(n * sizeof(int));

// Copy arr to s_arr

for(i=0; i<n; i++)

s_arr[i] = arr[i];

// Actual sorting using array notations

// Comment this when implementing pointer version.
/*
for (i=0;i<n-1;i++){

for(j=0;j<n-1;j++){

if(s_arr[j] > s_arr[j+1]){

temp = s_arr[j+1];

s_arr[j+1] = s_arr[j];

s_arr[j] = temp;

}

}

}*/
for (i=0;i<n-1;i++){

for(j=0;j<n-1;j++){

if((*(s_arr+j)) > (*(s_arr+j+1))){//*(s_arr+j)=s_arr[j]& *(s_arr+j+1)=s_arr[j+1]

temp = *(s_arr+j+1);

*(s_arr+j+1) = *(s_arr+j);

*(s_arr+j) = temp;

}

}

}

// Actually sorting using pointer notations. i.e. you cannot use "[]"!

// Your code goes here...

return s_arr;

}

void printArray(int arr[], int n){

int i = 0;

printf("[");

for(i=0; i<n; i++)

printf("%d ", arr[i]);

printf("] ");

}

int bSearch(int *arr, int a, int b, int key){
if(a>b)return -1;
int mid=(a+b)/2;
if((*(arr+mid))==key)return mid;
if(key<(*(arr+mid))) return bSearch(arr,a,mid-1,key);
return bSearch(arr,mid+1,b,key);

}

int main() {

int i = 0, size = 0, key = 0, result = 0;

int *array, *sorted;

printf("How big is your array? ");

scanf("%d", &size);

array = (int*)malloc(size * sizeof(int));

for(i=0; i<size; i++){

printf("Please enter array[%d]: ", i);

scanf("%d", &array[i]);

}

printf("Please wait while I sort your numbers... ");

sorted = bubbleSort(array, size);

printf("Here is your original array: ");

printArray(array, size);

printf("Here is your SORTED array: ");

printArray(sorted, size);

printf("What number are you looking for? ");

scanf("%d", &key);

printf("OK, let me see if I can find a %d in the array... ",key);

result = bSearch(sorted, 0, size-1, key);

if(result != -1)

printf("Got it! A %d is at index %d. ", key, result);

else

printf("I'm sorry, a %d cannot be found in the array. ",
key);

return 0;

}

