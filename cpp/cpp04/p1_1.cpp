#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date){
    std::cout << "year? : " << std::endl;
    std::cin >> year_;
    std::cout << "month? : " << std::endl;
    std::cin >> month_;
    std::cout << "day? : " << std::endl;
    std::cin >> day_;

    //이하 윤년과 월별 28(29),30,31일 오류확인

  }
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  void ShowDate() {
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
  }
  
};

int main() {
    // 날짜 초기화
    std::cout << "year? : " << std::endl;
    std::cin >> year_;
    std::cout << "month? : " << std::endl;
    std::cin >> month_;
    std::cout << "day? : " << std::endl;
    std::cin >> day_;
    Date date;
    date.SetDate();

    date.ShowDate();
}