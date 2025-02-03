// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
    int x;

    public:
    //constructor initial list 생성자 초기화 목록
    A(int c) : x(c) {}

    int& access_x() { return x; }   //x의 레퍼런스를 return
    int get_x() { return x; }       //x의 value를 return
    void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();
    //레퍼런스를 받아 이름을 c 라 한다.
            //a의 access_x()의 return를 레퍼런스로 준다.
                //위 함수 참고.L11
    int& c = a.access_x();  //레퍼런스 c가 x의 레퍼런스를 별명으로 받음.
    c = 4;      //x의 값이 4로 변경
    a.show_x();

    //정수 형태인 변수 d에 x의 값을 대입한다.
    int d = a.access_x();
    d = 3;      //d의 값은 변하지만 x의 값은 변하지 않음
    a.show_x();

    // 아래는 오류
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();
    f = 1;      //값이 변하지 않음
    a.show_x();
}