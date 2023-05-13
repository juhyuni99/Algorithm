#include <iostream>
#include<stack>
#include<string>
using namespace std;

void Print(stack <char>& s) { // 스택에서 문자열 뒤집어 꺼내기
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	string str;
	getline(cin, str);

	bool tag = false;

	stack <char> s;

	for (char ch : str) {
		if (ch == '<')
		{
			Print(s);
			tag = true;
			cout << ch;
		}
		else if (ch == '>')
		{
			tag = false;
			cout << ch;
		}
		else if (tag) // < > 내부의 글자라면
		{
			cout << ch;
		}
		else // < > 내부의 글자가 아니라면
		{
			if (ch == ' ')
			{
				Print(s);
				cout << ch;
			}
			else
			{
				s.push(ch);
			}
		}
	}

	// 이 문자열에는 마지막에 공백이 없으므로, 남은 문자열을 스택에서 꺼내줘야함
	Print(s);
	cout << '\n';

	return 0;
}