#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

int main(){
	map<string, int> d;
	vector<string> ans;
	string name;
	int cnt = 0;
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a+b; i++) {
		cin >> name;
		d[name]++;
	}
	for (auto i : d) {
		if (i.second >= 2) {
			ans.push_back(i.first);
		}
	}
	cout << ans.size() << '\n';
	for (int j = 0; j < ans.size(); j++) {
		cout << ans[j] << '\n';
	}
}
