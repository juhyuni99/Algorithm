/*

using namespace std;
vector<pair<int, int>> v;
int sum;

int main() {
	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++) {
		int small_weight = min(w, v[i].second);
		sum += small_weight * v[i].first;
		w -= small_weight;
		if (w == 0) break;
	}
	cout << sum;
	return 0;
}
*/

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