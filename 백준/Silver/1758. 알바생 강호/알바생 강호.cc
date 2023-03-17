#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <functional>

using namespace std;

int main(void) {

	int n, tip;
	long temp = 0;
	cin >> n;

	std::vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		if (num[i] - i > 0) {
			temp += num[i] - i;
		}
	}
	cout << temp << "\n";
}