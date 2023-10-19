#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m; //map함수 이용
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]++; //value값 증가
    }
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]--; //value값 감소
    }
    for(auto iter:m){ // map함수 key확인
        if(iter.second==1){ //value값이 1이면 
            answer = iter.first;
        }
    }
    
    return answer;
}
