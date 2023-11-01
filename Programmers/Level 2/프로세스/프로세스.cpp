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
    sort(priorities.begin(), priorities.end(), greater<int>());
    int answer = 0;
    while(!q.empty()){
        if(priorities[0]!=q.front()){
            location--;
            q.push(q.front());
            q.pop();
            if(location<0) location = priorities.size()-1;
        }
        else{
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            if(location==0) return answer;                                       
            else location--;
        }
    }
}
