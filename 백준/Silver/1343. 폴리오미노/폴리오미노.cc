#include <bits/stdc++.h>
using namespace std;

string s; //보드판

int main(void) {
	cin >> s;

	s = regex_replace(s, regex("XXXX"), "AAAA"); //특정문자 변환 XXXX->AAAA
	s = regex_replace(s, regex("XX"), "BB"); //특정문자 변환 XX->BB
	if (s.find("X")!= std::string::npos) { // 변환 후 X가 있으면 -1출력
		cout << "-1";
	}
	else { //X가 없으면 그대로 출력
		cout << s;
	}
	return 0;
}
