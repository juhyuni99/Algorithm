#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 문자열 뒤집어 꺼내기
void reverse(stack<char>& s) {
	while (!s.empty()) {// 스택 빌때까지
		cout << s.top();
		s.pop();
	}
}

int main(void) {
	string str;
	getline(cin, str);

	bool tag = false; // <> 내부 글자인지 확인
	stack <char> s;

	for (char ch : str) {
		if (ch == '<') {
			//< c>tag<rule>
			reverse(s);
			tag = true;
			cout << ch;
		}
		else if (ch == '>') {
			tag = false;
			cout << ch;
		}
		else if (tag) { // 괄호 내부 글자
			cout << ch;
		}
		else { // 괄호 외부 글자
			if (ch == ' ') {
				////tag tag
				reverse(s);
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	//마지막에 공백이 없으므로, 남은 문자열을 스택에서 꺼내주기
	//tag tag
	reverse(s);
	cout << '\n';
	return 0;
}
