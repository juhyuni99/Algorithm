#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){ //string으로 비교 수행
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i=0; i<numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    sort(temp.begin(), temp.end(), cmp); //cmp함수 기준으로 정렬 수행
    for(int i=0; i<temp.size(); i++){
        answer+=temp[i];
    }
    if (answer[0] == '0') return "0"; //answer[0]가 0이면 가장 큰 수가 0이라는 뜻이므로 0리턴
    return answer;
}
