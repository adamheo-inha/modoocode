/* 포인터 이용하기 */
#include <stdio.h>
int main() {
  int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};

  int* parr = arr;
  printf("현재 parr의 arr 주소 : %p \n", parr);
  int sum = 0;

  while (parr - arr <= 9) {
    printf("parr-arr :%ld \n", parr-arr);
    printf("현재 *parr :%d \n", *parr);
    sum += (*parr);
    parr++;
    printf("현재 parr의 arr 주소 : %p \n", parr);
    printf("현재 점수 :%d \n", *parr);
    printf("--------------------\n");
  }

  printf("내 시험 점수 평균 : %d \n", sum / 10);
  return 0;
}