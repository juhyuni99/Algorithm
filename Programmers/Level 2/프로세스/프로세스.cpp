#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {    
    queue<int> q;
    //vector의 인자들을 변경하지 않을거기 때문에 const를 사용한것이고 
    // 복사하지 않기 위해 &를 사용
    for(const auto& a : priorities) q.emplace(a); //emplace는 push_back과 비슷한 데이터를 추가하는 명령어
    sort(priorities.begin(), priorities.end(), greater<int>()); //내림차순 정렬
    int answer = 0; //location 해당 프로세스가 몇 번째로 실행
    while(true){
        if(q.front() == priorities[0]){//우선순위가 높은 수와 queue값이 같을 때
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            if(location == 0) return answer; //location이 0이 되었을때 answer값 반환
            else location--;
        }
        else{//우선순위가 높은 수와 queue값이 다를 때
            q.emplace(q.front());
            q.pop();
            location--;
            if(location < 0) location = q.size() - 1; //2번째 테스트케이스 경우 location이 음수가 되버리면 q에 다시 push가 되어 q사이즈-1번째 인덱스로 변한다.
        }
    }
}
