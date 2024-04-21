#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int n) //dеfinеs matrix mult function 
{
int i,j,k,temporary;
int** res;

//First create a 1D array
res = (int**) 
malloc
(n*sizeof(int*));

//Next create memory for each element
for (
i=0; 
i<n; 
i++)
res[i]= 
(int*)
 malloc
(n*sizeof(int));

//First create a 1D array
res = 
(int**) 
malloc(n*sizeof(int*));

//Next create memory for each element
for 
(i=0; 
i<n; 
i++)
res[i] =
 (int*) 
malloc
(n*sizeof(int));

//Iterating over rows
for
(i=0; 
i<n; 
i++)
{
//Iterating over columns
for
(j=0; 
j<n; 
j++)
{
temporary = 0;

for(
k=0; 
k<n; 
k++
)
{
temporary += ((*(*(a + i) + k)) * (*(*(b + k) + j)));
}
*(*(res+i)+j) = temporary;
}
}

return res;
}

void printArray(int **arr, int n){

int i, j;

printf("\n Matrix: \n\n");
//Iterating over rows
for
(i=0;
 i<n;
 i++)
{
//Iterating over columns
for(
j=0;
 j<n; 
j++)
{
printf(" %d ", *(*(arr+i)+j));
}
printf("\n");
}
}

//Main function
int main() {
int n = 0, i, j;
int **matA, **matB, **matC;

//Reading n value
printf("\nEnter n value: ");
scanf("%d", &n);

//First create a 1D array
matA = (int**) malloc(n*sizeof(int*));

//Next create memory for each element
for (
i=0; 
i<n; 
i++)
matA[i] = (int*) malloc(n*sizeof(int));

//First create a 1D array
matB = (int**) malloc(n*sizeof(int*));

//Next create memory for each element
for (
i=0; 
i<n; 
i++)
matB[i] = (int*) malloc(n*sizeof(int));

//First create a 1D array
matC = (int**) malloc(n*sizeof(int*));

//Next create memory for each element
for (
i=0; 
i<n; 
i++)
matC[i] = (int*) malloc(n*sizeof(int));

printf("\n Enter element %d elements: ", (n*n));

//Iterating over rows
for (
i=0; 
i<n; 
i++)
{
//Iterating over columns
for(j=0; 
j<n; 
j++)
{
scanf("%d", (*(matA+i)+j));
}
}

printf("\n Enter element %d elements: ", (n*n));

//Iterating over rows
for (
i=0; 
i<n; 
i++)
{
//Iterating over columns
for(j=0; 
j<n;
 j++)
{
scanf("%d", (*(matB+i)+j));
}
}

//Printing arrays
printArray(matA, n);
printArray(matB, n);

//Matrix multiplication
matC = matMult(matA, matB, n);

printArray(matC, n);
return 0;
}