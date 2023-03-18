#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long N; // 에너지 드링크 수

int main(void) {
	double result = 0;
	cin >> N;
	vector<double> X(N);
	
	for (long unsigned int i = 0; i < X.size(); i++) { //에너지 드링크 양
		cin >> X[i];
	}
	sort(X.begin(), X.end()); //오름차순
	for (long unsigned int i = 0; i < X.size(); i++) {
		if (i == X.size() - 1) result += X[i];	
		else result += X[i] / 2;
	}
	cout << result;
	return 0;
}