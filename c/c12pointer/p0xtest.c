/*
#include <stdio.h>
int main() {
    int arr[3][2][2] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int * parr;
    int i, j, k;
    parr = &arr[0][0][0];

    for (j=0;j<3; j++) {
        for (i=0; i<2; i++) {
            for (k=0; k<2; k++) {
                printf("aar[%d][%d][%d]의 값 : %2d |",j,i,k, arr[j][i][k]);
                printf("aar[%d][%d][%d]의 주소값 : %p |",j,i,k, &arr[j][i][k]);
                int x=j;
                int y=x+i;
                int z=x+y+k;
                printf("(parr + %d+%d+%d)의 주소값 : %p",x,y,z, (parr+x+y+z));

                if (&arr[j][i][k] == (parr+x+y+z)) {
                    printf(" --> 일치 \n");
                } else{
                    printf(" --> 불일치 \n");
                }
            }
        }
    }
    return 0;
}
*/
/*
#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int b[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };

    // a[x][y]
    printf("%d\n", a[1][2]);             // 6
    printf("%d\n", *(*(a + 1) + 2));     // 6

    // b[x][y][z]
    printf("%d\n", b[1][1][0]);          // 7
    printf("%d\n", *(*(*(b + 1) + 1) + 0)); // 7

    return 0;
}
*/
#include <stdio.h>

int main() {
    // 4차원 배열 생성 (2x3x4x5)
    int arr[2][3][4][5];

    // 배열 초기화
    int value = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 5; l++) {
                    arr[i][j][k][l] = value++;
                }
            }
        }
    }

    // 1. 4차원 배열을 가리키는 포인터
    int (*p4d)[3][4][5] = arr;  // 크기 3x4x5의 배열을 가리키는 포인터
    printf("%d\n", p4d[1][2][3][4]);  // arr[1][2][3][4]

    // 2. 3차원 배열을 가리키는 포인터
    int (*p3d)[4][5] = arr[1];  // 크기 4x5의 배열을 가리키는 포인터
    printf("%d\n", p3d[2][3][4]);  // arr[1][2][3][4]

    // 3. 2차원 배열을 가리키는 포인터
    int (*p2d)[5] = arr[1][2];  // 크기 5의 배열을 가리키는 포인터
    printf("%d\n", p2d[3][4]);  // arr[1][2][3][4]

    // 4. 1차원 배열을 가리키는 포인터
    int *p1d = arr[1][2][3];  // 1차원 배열을 가리키는 포인터
    printf("%d\n", p1d[4]);  // arr[1][2][3][4]

    return 0;
}
