#include <iostream>
#include <string.h>

class Marine {
    int hp;                 //체력
    int coord_x, coord_y;   //위치
    int damage;             //공격력
    bool is_dead;           //생사?
    char * name;            //이름

    public:
    Marine();                                       //기본생성자
    Marine(int x, int y, const char* marine_name);  //이름까지 지정
    Marine(int x, int y);   //x,y 좌표에 마린 생성
    ~Marine();

    int attack();                       //데미지를 리턴한다.
    void be_attacked(int damage_earn);   //입는 데미지
    void move(int x, int y);            //새로운 위치

    void show_status();                 //상태를 보여준다.
};
//생성자1
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
//생성자2
                            //const로 marine_name에 직접 접근하여 값을 변경하는 것을 막음
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
//생성자3
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine : " << name << " *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y  << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
//소멸자 Destructor
Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 !" << std::endl;
    //동적으로 할당이 되어었을 경우
    if (name != NULL) {
        delete[] name;
    }
}

/* 
int main() {
    Marine marine1(2,3);
    Marine marine2(3,5);
    
    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
 */

int main() {
    Marine * marine[100];    //marine이라는 이름의 100개의 포인터를 갖는 배열를 생성
    
    marine[0] = new Marine(2, 3, "Marine 2");   // T variable = new T : T에 맞는 메모리를 확보해 첫 메모리 주소르 변수에 대입
    marine[1] = new Marine(3, 5, "Marine 1");

    marine[0]->show_status(); //(*marine[0]).show_status(); 와 같다.
    marine[1]->show_status();

    std::cout << std::endl << "마린1이 마린2를 공격! " << std::endl;

    marine[0]->be_attacked(marine[1]->attack());

    marine[0]->show_status();
    marine[1]->show_status();

    delete marine[0];
    delete marine[1];
}