	
#include <iostream>
#include <ctime>
using namespace std;
 
int main(void) {
 
 srand((unsigned int)time(NULL));
 
 int correctNumbers[6];
 int userNumbers[6];
 
 int correctCount = 0;
 
 for (int i = 0; i < 6; i++) {
  correctNumbers[i] = 0;
 }
 
 for (int i = 0; i < 6; i++) {
  userNumbers[i] = 0;
 }
 
 for (int i = 0; i < 6; i++) {  
  bool isLoop = true;
  while ( isLoop ) {
   int num = rand();  // 실제 랜덤 숫자를 가져오는 부분
   int tempNumber = num % 25 + 1;
   for (int j = 0; j < 6; j++ ) {
    if (correctNumbers[j] == tempNumber) {
     isLoop = true;
    }
    else {
     isLoop = false;
     correctNumbers[i] = tempNumber;
     break;
    }
   }
  }
 }
 
 cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다. " << endl;
 for (int i = 0; i < 6; i++) {
  cout << i + 1 << "번째 번호를 입력하세요: ";
  int tempInput;
  while (true) {
   cin >> tempInput;
   if (tempInput > 25 || tempInput < 1 ) {
    cout << "잘못된 숫자입니다. 다시 입력해주세요. " << endl;
    cout << i + 1 << "번째 번호를 입력하세요: ";
   }
   else {
    bool isExist = false;
    for (int j = 0; j < 6; j++) {
     if (tempInput == userNumbers[j]) {
      cout << "이미 입력된 숫자입니다. " << endl;
      cout << i + 1 << "번째 번호를 입력하세요: ";
      isExist = true;
      break;
     }
    }
    if (!isExist) {
     userNumbers[i] = tempInput;
     break;
    }
   }
  }
  
 }
 
 for (int i = 0; i < 6; i++) {
  for (int j = 0; j < 6; j++) {
   if (correctNumbers[i] == userNumbers[j]) {
    correctCount++;
    break;
   }
  }
 }
 
 cout << "--------------------------" << endl;
 cout << "당첨번호 공개! " << endl;
 for (int i = 0; i < 6; i++) {
  cout << correctNumbers[i] << " ";
 }
 cout << endl;
 cout << "1 ~ 7등까지 결과가 나올 수 있습니다." << endl;
 cout << "결과 : " << 7 - correctCount << "등입니다! " << endl;
 
 return 0;
 
}