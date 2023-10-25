#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int res = 0; 
    for(int i=0; i<progresses.size(); i++){
        res = 100 - progresses[i];
        if(res%speeds[i]==0){
            q.push(res/speeds[i]);
        }
        else{
            q.push(res/speeds[i]+1);
        }
    }
    while(!q.empty()){
        int cnt =1;
        int current = q.front();
        q.pop();
        while(!q.empty()&&q.front()<=current){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}
