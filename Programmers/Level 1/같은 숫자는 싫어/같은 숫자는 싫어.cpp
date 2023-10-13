#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]); // 첫번째 값을 먼저 넣어줌
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1]!=arr[i]){ //연속된 숫자가 아니면 삽입
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
