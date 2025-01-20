#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int SizeOfArray;    //정수 변수
    int *arr;           //정수 포인터
    // scanf는 입력값을 주소값을 통해 변수에 저장한다. 
    scanf("%d", &SizeOfArray);
            //형 변환 : malloc가 void로 반환하기 때문에 
                    //바이트 크기만큼 메모리를 할당
                        //시스템에 맞는 int의 크기를 확인하기 위해 sizeof 사용
                                        //배열 크기(갯수)
                        //원하는 갯수의 배열을 만들기위한 총 바이트 수
    arr = (int *)malloc(sizeof(int) * SizeOfArray);

    free(arr);
    return 0;
}