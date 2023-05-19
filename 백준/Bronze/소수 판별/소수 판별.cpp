#include <iostream>
#include <cmath>
using namespace std;

bool num(int n){
  for(int j = 2; j<=sqrt(n); j++){
      if(n%j==0){
        return false;
      }
  }
  return true;
}
int main() {
  
  //Please Enter Your Code Here
  int n,m;
  cin >> n >> m;
  for(int i = n; i<m; i++){
    num(i);
    if(i==1){
      continue;
    }
    if(num(i)){
      cout << i << " ";
    }
  }
  return 0;
}
