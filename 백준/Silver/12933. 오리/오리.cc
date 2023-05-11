#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
string target = "quack";
int res;

bool get_count()
{
	vector<int> duck;
	int s, e, i;
	int idx = 0;

	// 녹음한 소리 전체를 확인
	while (idx < str.size())
	{
		// 소리가 어디부터 시작하는지 찾기
		s = find(target.begin(), target.end(), str[idx]) - target.begin();
		e = s;
		// 이어지는 소리의 최대 길이 구하기
		while (idx < str.size() && e < target.size() && str[idx] == target[e])
		{
			idx++;
			e++;
		}
		// 소리의 처음부터 시작하는 경우
		if (s == 0)
		{
			// 새로운 오리이므로 duck에 추가 후 존재하는 오리의 수 갱신
			duck.push_back(e);
			res = max(res, (int)duck.size());
			// 소리가 끝났다면 duck에서 삭제
			if (e - s == target.size())
				duck.pop_back();
			continue;
		}
		// 소리의 중간부터 시작하는 경우 
		// 앞 부분의 소리가 duck에 존재하는지 확인
		i = find(duck.begin(), duck.end(), s) - duck.begin();
		// 존재하지 않으면 올바르지 않음 -> false를 리턴
		if (i == duck.size())
		{
			return false;
		}
		// 존재하면 누적된 소리의 길이를 갱신
		duck[i] = e;
		// 소리가 끝났다면 duck에서 삭제
		if (e == target.size())
		{
			duck.erase(duck.begin() + i);
		}
	}
	// 끝나지 않고 남은 소리가 있다면 올바르지 않음 -> false 리턴
	if (!duck.empty())
		return false;
	return true;
}

int main()
{
	cin >> str;
	// 녹음한 소리가 올바른 경우
	if (get_count())
		cout << res << endl;
	// 녹음한 소리가 올바르지 않은 경우
	else
		cout << -1 << endl;
	return 0;
}
