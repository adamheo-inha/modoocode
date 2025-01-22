#include <iostream>
// This is function that changes a value.
//When a memory address is recived, assign 3 to the velue of that address.
/* 
//pointer
//포인터로 변수의 주소를 인자로 받고 주소에 있는 값을 3으로 변경한다.
int change_val(int *p) {
  *p = 3;

  return 0;
}

int main() {
  int number = 5;

  std::cout << number << std::endl;
  change_val(&number);
  std::cout << number << std::endl;
}
 */

//referrence
int main() {
  int a = 3;
  // another_a은 a의 또 다른 이름이다.
  int& another_a = a;
  // another_a에 5를 대입했지만
  another_a = 5;
              //a을 출력하니 5가 나왔다.
  std::cout << "a : " << a << std::endl;
  std::cout << "another_a : " << another_a << std::endl;

  return 0;
}