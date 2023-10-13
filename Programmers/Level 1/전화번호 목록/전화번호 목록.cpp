#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end()); //오름차순 정렬
    for(int i=0; i<phone_book.size()-1; i++){ //substr이용해서 문자열 쪼개기
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())){
            answer = false;
        }
    }
    
    return answer;
}
