#include <iostream>

class Date {
    private:
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 31 까지.
    
 public:
    int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthcheck = 0;
    //함수 내부 초기화 
    void SetDate(int year = 0, int month = 0, int day = 0) {
        year_ = year;
        month_ = month;
        day_ = day;
        int maxday_ = 0;
        std::cout << "원하시는 년도를 숫자만 입력하세요. ";
        std::cin >> year_;
        std::cout << "원하시는 달을 숫자만 입력하세요. ";
        std::cin >> month_;
        while (1) {
            // 달이 1부터 12사이에 들어왔는지 확인
            if(1 <= month_ && month_ <= 12) {
                break;
                //조건이 성립해서 while exit
            // 달이 1부터 12이외에 입력값이 들어와 재입력 요청과 값 입력과 수정
            } else {
                std::cout << "달을 다시 입력해줘요." << std::endl;
                std::cin >> month_;
            }
        }//while 


        monthcheck = Month[month_ - 1];
        std::cout << monthcheck << " " << month_ << std::endl; ///////////////////////////////////////////////        

        std::cout << "원하시는 날짜를 숫자만 입력하세요. ";
        std::cin >> day_;
        // 해당 달에 넘는 날짜가 들어왔는지 확인
        // 들어왔으면 while문을 탈출하고 넘었으면 재입력을 요청
        while (1) {
            // 입력될 달에 해당하는지 확인
            if (monthcheck == 31) {
                // 달에 맞는 날안에 들어오면 while문 탈출
                if (1 <= day_ && day_ <= 31) {
                    break;
                // 들어오지 못하면 넘었다는 문구 출력과 최대날 변수에 입력
                } else {
                    std::cout << "31일을 넘지마세요." << std::endl;
                    maxday_ = 31;
                }
            } else if (monthcheck == 30) {
                if (1 <= day_ && day_ <= 30) {
                    break;
                } else {                    
                    std::cout << "30일을 넘지마세요." << std::endl;
                    maxday_ = 30;                                                                                    
                }
            } else if (monthcheck == 28) {
                if (1 <= day_ && day_ <= 28) {
                    break;
                } else {                    
                    std::cout << "28일을 넘지마세요." << std::endl;
                    maxday_ = 28;
                }
            }
            // 재입력 요청
            std::cout << maxday_ << "일을 넘지 않는 날짜를 숫자만 입력하세요. ";
            std::cin >> day_;
        }//while
    }//SetDate()


    // 날짜 더하기
    void AddDay(int inc) {
        day_ += inc;
        if (monthcheck == 31) {
            while(day_ > 31) {
                day_ -= 31;
                AddMonth(1);
            }
        } else if (monthcheck == 30) {
            while(day_ > 30) {
                day_ -= 30;
                AddMonth(1);
            }
        } else if (monthcheck == 28) {
            while(day_ > 28) {
                day_ -= 28;
                AddMonth(1);
            }
        } else {
            std::cout << "월정 정정 해주세요." << std::endl;
        }
        std::cout << "3 " << monthcheck << " " << month_ << std::endl;////////////////////////////////////////////
    }//AddDay()

    void AddMonth(int inc) {
        month_ += inc;
        if(month_ > 11) {
            month_ -= 12;
            AddYear(1);
        }
        monthcheck = Month[month_ - 1];
        std::cout << "AddMonth 함수후" << monthcheck << " " << month_ << std::endl;////////////////////////////////////////////
    }//AddMonth()

    void AddYear(int inc){
        year_ += inc;
    }//AddYear()

    //날짜 출력
    void ShowDate() {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
        std::cout << monthcheck << std::endl;
    }//ShowDate()
};

int main() {
    int state = 0;
    int inc = 0;
    int theend = 0;
    Date date;

    date.SetDate();
    // 추가 및 결과 출력
    while(1) {
        //while 탈출 종료
        if (theend == 1) break;
        std::cout << "원하시는 기능을 입력하세요." << std::endl << "1번 년도 추가" << std::endl << "2번 월 추가" << std::endl << "3번 일 추가" << std::endl << "4번 날짜보기" << std::endl << "5번 종료" << std::endl;
        std::cin >> state;
        switch (state) {
            case 1:
                std::cout << "몇 년 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddYear(inc);
                date.ShowDate();
                break;
            case 2:
                std::cout << "몇 달 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddMonth(inc);
                date.ShowDate();
                break;
            case 3:
                std::cout << "몇 일 추가 하시겠습니까? : ";
                std::cin >> inc;
                date.AddDay(inc);
                date.ShowDate();
                break;
            case 4:
                 date.ShowDate();
                break;
            case 5:
                theend = 1;
                break;
    
        default:
            break;
        }
    }



    return 0;
}