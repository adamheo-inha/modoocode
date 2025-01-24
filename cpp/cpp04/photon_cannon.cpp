#include <string.h>
#include <iostream>

class Photon_Cannon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;

  public:
  Photon_Cannon(int x, int y);
  //Photon_Cannon(const Photon_Cannon& pc);

  void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "생성자 호출 !" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}
/* 
// 복사 생성자
                                    //Photon_Cannon& 를 모르겠으면 C++ 2단원 Reference, 참조자 참고
                //cpp02>reference_argument.cpp의 주석 참고
                              //<pc>들어오는 값은 상수(리터럴)이고
                              //상수를 참조할려면 const를 사용해 '상수 참조자'로 사용해야한다. 
                                    //P_C타임의 레퍼런스를 받아서 <pc>이름으로 하겠다.
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}
 */

void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2; //== Photon_Cannon pc3(pc2);

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
}