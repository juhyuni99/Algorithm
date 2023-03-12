#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
	cin >> s;

	s = regex_replace(s, regex("XXXX"), "AAAA");
	s = regex_replace(s, regex("XX"), "BB");
	if (s.find("X")!= std::string::npos) {
		cout << "-1";
	}
	else {
		cout << s;
	}
	return 0;
}