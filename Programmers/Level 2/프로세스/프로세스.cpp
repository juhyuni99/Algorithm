#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {    
    queue<int> q;
    for(int i=0; i<priorities.size(); i++){
        q.push(priorities[i]);
    }
    sort(priorities.begin(), priorities.end(), greater<int>()); //내림차순 정렬
    int answer = 0; //location 해당 프로세스가 몇 번째로 실행
    while(!q.empty()){
        if(priorities[0]!=q.front()){ //우선순위가 높은 수와 queue값이 다를 때
            location--;
            q.push(q.front());
            q.pop();
            if(location<0) location = priorities.size()-1; //2번째 테스트케이스 경우 location이 음수가 되버리면 q에 다시 push가 되어 priorities사이즈-1번째 인덱스로 변한다.
        }
        else{ //우선순위가 높은 수와 queue값이 같을 때
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            if(location==0) return answer;//location이 0이 되었을때 answer값 반환                                      
            else location--;
        }
    }
}
