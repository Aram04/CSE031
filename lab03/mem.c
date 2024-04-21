#include <stdio.h>
#include <stdlib.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *) malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **) malloc(1 * sizeof(int *));
	*handle = ptr;

	printf("Address of Num Variable %u\n",&num);
	printf("Address of ptr variable %u\n", &ptr);
	printf("ptr pointer variable contains %u\n", ptr);
	printf("\nThe value stored at the pointer variable points to memory is %d",*ptr);
	printf("\nAddress of handle Variable %u",&handle);
	printf("\nhandle variable contains %u",handle);
	printf("\nhandle variable points to memory which contains %u",*handle);
	printf("\nThe value stored at the handle points to ptr variable is %d",**handle);	

	return 0;
} 

