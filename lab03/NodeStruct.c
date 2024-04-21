#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
    
    // Insert extra code to print out the value of head,
    // addresses of head, iValue, fValue, and next pointed by head.
    printf("value of head: %p\n", head);
    printf("address of head: %p\n", &head);
    printf("address of iValue: %p\n", &head->iValue);
    printf("address of fValue: %p\n", &head->fValue);
    printf("next: %p\n", &head->next);
    
    return 0;
}