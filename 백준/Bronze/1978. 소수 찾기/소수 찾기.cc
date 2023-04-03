#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // 수의 개수
    int cnt = 0;
    cin >> N;
    vector<int> number(N);

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        number[i] = input;
        if (number[i] == 1) continue;
        bool is_prime = true;
        for (int j = 2; j * j <= number[i]; j++) {
            if (number[i] % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}


