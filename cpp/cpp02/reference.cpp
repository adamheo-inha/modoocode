#include <iostream>
// This is function that changes a value.
//When a memory address is recived, assign 3 to the velue of that address.
/* 
//pointer
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
  int& another_a = a;

  another_a = 5;
  std::cout << "a : " << a << std::endl;
  std::cout << "another_a : " << another_a << std::endl;

  return 0;
}