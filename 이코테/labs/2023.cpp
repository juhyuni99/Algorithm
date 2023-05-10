#include <iostream>
#include <string>

using namespace std;


int main() {
  
  //Please Enter Your Code Here
  int days[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string day[8] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
  int M, D; //월, 일
  cin >> M >> D;
  
  for(int i = 1; i<M; i++){
    D += days[i];
  }
  cout << day[D%7];
  return 0;
}

// 31 + 29 + 30 + 31 + 30
