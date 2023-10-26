#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> ans; // 정렬된 수 저장
        for(int j=commands[i][0]-1; j<commands[i][1]; j++){ // 원하는 길이만큼 반복문을 이용하여 ans에 값 저장
            ans.push_back(array[j]);
        }
        sort(ans.begin(), ans.end());// 오름차순 정렬
        answer.push_back(ans[commands[i][2]-1]); // 원하는 인덱스의 값 넣기
        }
    return answer;
}
