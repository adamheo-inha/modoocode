#include <stdio.h>
int main() {
    int a;
    int*pa;
    pa = &a;

    printf("%p\n",pa);
    printf("%p\n",pa+1);
    return 0;
}