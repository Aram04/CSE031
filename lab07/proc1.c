#include <stdio.h>

int Sum(int a, int b) {
    return a + b;
}

int main(int argc, char** argv) {
    int m = 10;
    int n = 5;

    int x = Sum(m, n);

    printf("%d\n", x);

    return 1;
}
