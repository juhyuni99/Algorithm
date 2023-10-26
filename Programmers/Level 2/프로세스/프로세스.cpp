#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {    
    queue<int> q;
    //vector의 인자들을 변경하지 않을거기 때문에 const를 사용한것이고 
    // 복사하지 않기 위해 &를 사용
    for(const auto& a : priorities) q.emplace(a);
    sort(priorities.begin(), priorities.end(), greater<int>());
    int answer = 0;
    while(true){
        if(q.front() == priorities[0]){
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            if(location == 0) return answer;
            else location--;
        }
        else{
            q.emplace(q.front());
            q.pop();
            location--;
            if(location < 0) location = q.size() - 1;
        }
    }
    return answer;
}
