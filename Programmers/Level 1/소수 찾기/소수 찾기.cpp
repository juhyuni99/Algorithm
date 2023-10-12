#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 2; i<=n; i++){
        bool flag =  true;
        for (int j = 2; j <= sqrt(i); j++) {//2~n의 제곱근까지
		    if (i%j == 0) {//i가 n의 약수라면 소수가 아니므로 false 
		        flag = false;
            }
        }
        if(flag){ //2 ~ n-1까지 약수가 없다면 소수이므로, 개수 증가
            answer++;
        }
	}
    
    
	
    return answer;
}
