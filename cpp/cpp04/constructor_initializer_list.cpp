#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;
  
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  //int damage;            // 공격력
  bool is_dead;

  const int default_damage;  // 상수 멤버 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage); // 위치, 데미지을 설정하여 생성

  int attack();                       // 데미지를 리턴한다.
        //& : reference 참조자
  Marine& be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();    // static member function
  ~Marine() { total_marine_num--; }
};
//---------------------------class_definition_end----------------------------------
int Marine::total_marine_num = 0;     // static variable initialization

void Marine::show_total_marine() {
  std::cout << "변수 마린 수 : " << total_marine_num << std::endl;
}
// 생성자{
/* 
Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}
 */
Marine::Marine() 
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}
//}생성자

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damage; }

Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
          // 객체 자신(Marine&)을 리턴함.
                      //Marine&은 어떤 변수의 별명
          // 별명(레퍼런스)을 리턴한다??
  return *this;
}
/* 위와 같다.
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) is_dead = true;

  return *this;
}
*/ 
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
/* 
void create_marine() {
  Marine marine3(10, 10, 4);
  marine3.show_total_marine();
}
 */
//------------------main_start-----------------------
int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  // create_marine();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}