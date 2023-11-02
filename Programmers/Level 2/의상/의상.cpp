#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    //옷을 종류별로 구별하기
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    //입지않는 경우를 추가하여 모든 조합 계산하기
    for(auto &a:m){
        answer *= a.second+1;
    }
    //아무 종류의 옷도 입지 않는 경우 제외하기
    return answer-1;
}
