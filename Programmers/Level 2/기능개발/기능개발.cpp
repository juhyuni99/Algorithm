#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> cnt;
    int res = 0; 
    for(int i=0; i<progresses.size(); i++){
        res = 100 - progresses[i];
        if(res/speeds[i]==0){
            cnt.push_back(res/speeds[i]);
        }
        else{
            cnt.push_back(res/speeds[i]+1);
        }
    }
    answer.push_back(1);
    int cnt1=0;
    for(int i=1; i<cnt.size(); i++){
        if(cnt[i-1]<cnt[i]){
            answer.push_back(1);
            cnt1++;
        }
        else{
            answer[cnt1]++;
        }
    }
    return answer;
}
