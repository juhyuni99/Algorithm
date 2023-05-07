#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		string target;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				target = s.substr(j + 1); // 지정한 위치 다음부터 마지막까지 문자열 취득
				//키 값 유무 확인
				if (m.find(target) != m.end()) {
					m[target]++;
				}
				else {
					m.insert(make_pair(target, 1));
				}
				break;
			}
		}
	}

	for (auto iter : m) {
		cout << iter.first << " " << iter.second << endl;
	}

}