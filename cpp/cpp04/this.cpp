#include <iostream>

class Marine {
    //변수
    static int total_marine_num;
    const static int i = 0;         // 상수로 클래스내 초기화

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    public:
    //생성자
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    //함수 정의
    int attack();
    void move(int x, int y);
    // 참조자 함수 정의
    Marine& be_attacked(int damage_earn);

    void show_status();
    static void show_total_marine();
    //소멸자
    ~Marine() { total_marine_num--; }
};

// static 초기화
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

//생성자 초기화 목록 { 기능구현 }
Marine::Marine() : 
    hp(50), 
    coord_x(0), 
    coord_y(0), 
    default_damage(5), 
    is_dead(false) {
    total_marine_num++;
}
Marine::Marine(int x, int y) : 
    coord_x(x),
    coord_y(y),
    
    hp(50),
    default_damage(5),
    is_dead(false) {
  total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage) : 
    coord_x(x),
    coord_y(y),
    is_dead(false),

    hp(50),
    default_damage(default_damage) {
  total_marine_num++;
}

//함수 기능구현
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
// 참조자 함수 기능구현
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;

    return *this;
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
    //<--이분이 먼저 실행되고 marine2를 반환-->
                                //marine2.be_attacked(marine1.attack()); 가 됨
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}