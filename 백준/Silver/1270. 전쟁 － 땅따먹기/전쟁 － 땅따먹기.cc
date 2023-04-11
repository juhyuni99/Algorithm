#include <iostream>
#include <map>

using namespace std;

long int N, T, num,ans,idx;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int a = 0; a < N; a++) {

		map <long int, int> arr;

		cin >> T;
		for (int b = 0; b < T; b++) {
			cin >> num;
			
			if (++arr[num] > T/2) {
				ans = arr[num];
				idx = num;
			}

		}

		if (ans > T / 2) {
			cout << idx << "\n";
		}

		else {
			cout << "SYJKGW"<<"\n";
		}

	
		ans = 0;
		idx = 0;
		arr.clear();

	}





}