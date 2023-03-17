#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N; // 인원수

int main(void) {
    long result = 0;
    cin >> N;
    vector<int> arr(N);// 팁

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬
    for (int i = 0; i < N; i++) {
        arr[i] -= i; // 팁 최댓값
        if (arr[i] < 0) arr[i] = 0;
        result += arr[i];
    }
    cout << result;
    return 0;
}
