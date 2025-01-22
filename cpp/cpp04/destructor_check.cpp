// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
    char c;

    public:
    //생성자
    Test(char _c) {
        c = _c;
        std::cout << "생성자 호출" << c << std::endl;
    }
    //소멸자
    ~Test() { std::cout << "소멸자 호출" << c << std::endl; }
};

void simple_function() { Test b('b'); }

int main() {
    //생성자 a 생성
    Test a('a');
    //함수로 생성자 b 가 생성된지만
    // 함수가 끝나게되면 b가 함수의 }를 벗어나므로 b의 소멸자가 자동실행되어 b 소멸
    simple_function();
}
// 생성자 a가 생성됐던 구역을 벗어났으므로 a의 소멸자 자동실행 및 a 소멸