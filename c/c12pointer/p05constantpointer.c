/* 상수 포인터? 
#include <stdio.h>
int main() {
  int a;
  int b;
  const int * pa = &a;
  //*pa = 3;  // 올바르지 않은 문장
  pa = &b;  // 올바른 문장
  printf("%p\n",pa);
  pa = &b;
  printf("%p\n",pa);
  return 0;
}
*/


/* 상수 포인터? ㅍ*/
#include <stdio.h>
int main() {
  int a;
  int b;
  int* const pa = &a;

  *pa = 3;  // 올바른 문장
  pa = &b;  // 올바르지 않은 문장

  return 0;
}