#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int SizeOfArray;    //정수 변수
    int *arr;           //정수 포인터

    printf("배열의 원소의 수 : ");
    // scanf는 입력값을 주소값을 통해 변수에 저장한다. 
    scanf("%d", &SizeOfArray);
    //인자의 주소를 가르키게됨
            //(Type){무언가}: 무언가를 Type으로 형변환
            //(malloc가 void를 반환, int*형으로 변환하기위해) 
                    //malloc(수) : 수 만큼 메모리 공간을 할당(바이트)
                    //할당한 메모리의 시작주소를 반환
                        //sizeof(T) : T가 차지하는 메모리 크기(바이트)를 반환
                                        //배열의 원소의 수
                        //메모리에 모든 원소를 할당하기위한 바이트 
    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    //할당받았던 메모리 영역을 반납.
    free(arr);
    return 0;
}