/* 더하기 1 을 하는 방법  */
#include <stdio.h>
int main() {
  int a = 1, b = 1, c = 1, d = 1;

  a = a + 1;
  printf("a : %d \n", a);
  b += 1;
  printf("b : %d \n", b);
  ++c;  // prefix전위형
  printf("c : %d \n", c);
  d++;  // postfix후위형
  printf("d : %d \n", d);
  return 0;
}