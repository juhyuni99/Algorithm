#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> cnt;
    int res = 0; 
    for(int i=0; i<progresses.size(); i++){
        res = 100 - progresses[i];
        if(res/speeds[i] ==0){
            cnt[i]=res/speeds[i];
        }
        else{
            cnt[i]=res/speeds[i]+1;
        }
    }
    answer.push_back(1);
    int cnt1=0;
    for(int i=1; i<cnt.size(); i++){
        if(cnt[i-1]<cnt[i]){
            cnt1=0;
            answer[i]++;
        }
        else{
            cnt1++;
            answer[i-cnt1]++;
        }
    }
    return answer;
}
