#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
int N;

void ifGirl(int n) {
	int left = n - 1;
	int right = n + 1;
	arr[n] = !arr[n];
	while (left >= 1 && right <= N) {
		if (arr[left] != arr[right]) {
			break;
		}
		arr[left] = !arr[left];
		arr[right] = !arr[right];
		left--;
		right++;
	}
}

void ifBoy(int n) {
	for (int i = n; i <= N; i += n) {
		arr[i] = !arr[i];
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int type;
	cin >> type;
	for (int i = 0; i < type; i++) {
		int sex, n;
		cin >> sex >> n;
		if (sex == 1) {

			ifBoy(n);
		}
		else ifGirl(n);
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	return 0;
}
