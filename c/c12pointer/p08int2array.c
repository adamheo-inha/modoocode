#include <stdio.h>
int main() {
    int arr[3] = {1,2,3};
    int *parr;

    parr = arr;
    // parr = &arr[0];

    printf("%d \n", arr[1]);
    printf("%d \n", parr[1]);
    return 0;
}