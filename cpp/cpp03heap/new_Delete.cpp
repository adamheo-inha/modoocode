#include <iostream>

int main() {
    //[type]* {pointer} = new [Type];
            //new T(=Type)의 T에 맞는 메모리 크기를 heap의 할당
                    // int*가 있는데 new int로 한번더 타입을 알려주는이유, 명확한 의도 표현, 컴파일 효율성 증가.
    // 포인터 p에 정수크기로 heap에 할당되어있는 메모리의 주소를 저장
    int* p = new int;
    *p = 10;

    std::cout << *p << std::endl;

    delete p;
    /* p = nullptr;
    std::cout << *p << std::endl;
 */
    return 0;
}