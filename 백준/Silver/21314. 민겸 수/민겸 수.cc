#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <regex>
#include <cmath>

using namespace std;
string MK; // 민겸수

//최댓값 구하기
string MAX() {
	stack<char> mk; //M데이터를 모아야 하므로 stack 사용
	int M = 0;
	int K = 0;
	int result = 0;
	string temp = ""; //최댓값

	//민겸수 확인
	for (int i = 0; i < MK.size(); i++) {
		if (mk.empty()) { // stack 비어있으면
			if (MK[i] == 'K') { //K이면 temp에 추가
				temp.append(to_string(5)); //숫자 5 -> 문자열 변환 후 추가
			}
			else if (MK[i] == 'M') { //M이면 stack에 넣어주기
				mk.push(MK[i]);
			}

		}
		else { // stack 비어있지 않으면
			if (mk.top() == 'M' && MK[i] == 'K') { //stack 상단에 있는 수가 M이고 MK[i]가 K이면
				temp.append(to_string(5));
				for (int i = 0; i < mk.size(); i++) { //stack에 있는 크기만큼 temp에 0 추가(50, 500, 5000 만들어줘야함)
					temp.append(to_string(0));
				}
				while (!mk.empty()) { //stack 빌때까지 상단 값 pop(삭제)
					mk.pop();
				}
			}
			else {// 상단 값이 M이고 MK[i]가 M
				mk.push(MK[i]);
			}
		}
	}
	if (!mk.empty()) {//stack이 비어있지 않을 경우 -> 마지막 값이 M으로 끝날 경우 
		//stack에는 M만 남아 있음. 그러므로 temp에 1 추가 (11, 111, 1111로 끝내줌)
		for (int i = 0; i < mk.size(); i++) { 
			temp.append(to_string(1)); 
		}
	}
	return temp; //최댓값 출력
}

//최솟값 구하기
string MIN() {
	vector<char> mk;
	string temp = "";//최솟값

	for (int i = 0; i < MK.size(); i++) {
		if (MK[i] == 'K') { //K이면
			if (!mk.empty()) { // vector 비어있지 않으면
				temp.append(to_string(1)); //temp에 '1' 추가
				for (int i = 0; i < mk.size() - 1; i++) { //M개수-1만큼 0을 붙여주어야 함
					temp.append(to_string(0)); //temp에 '0' 추가
				}
				temp.append(to_string(5)); //K따로 분리하여 계산(K = 5)
				mk.clear();
			}
			else {// vector 비어있으면
				temp.append(to_string(5)); //K = 5 값 추가
			}
		}
		else if (MK[i] == 'M') { //M이면
			mk.push_back('M'); //M 추가
		}
	}
	if (!mk.empty()) { //vector 비어있지 않을 경우 -> M만 남아있을 경우
		temp.append(to_string(1)); // MM,MMM,MMMM 10,100,1000
		for (int i = 0; i < mk.size() - 1; i++) { //M개수-1만큼 0을 붙여주기
			temp.append(to_string(0));
		}
	}
	return temp; //최솟값 출력
}

int main(void) {
	cin >> MK;
	cout << MAX() << '\n';
	cout << MIN();
}