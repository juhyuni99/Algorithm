#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> card;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Card;
		cin >> Card;
		card.push_back(Card);
	}
	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int Card1;
		cin >> Card1;
		cout << upper_bound(card.begin(), card.end(), Card1)-lower_bound(card.begin(), card.end(), Card1)<<' ';
	}
}