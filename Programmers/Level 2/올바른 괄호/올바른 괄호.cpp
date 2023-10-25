#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){ //카운트 증가
            cnt++;
        }
        else if(s[i]==')'){ //카운트 감소
            cnt--;
        }
        if(cnt<0){ //')'이 먼저 나오거나 '('보다 더 많이 나온 경우 false
            answer = false;
            return answer;
        }
    }
    
    if(cnt==0){ // 올바른 괄호일 경우 true
        answer = true;
    }
    else answer = false;
    return answer;
    
}
