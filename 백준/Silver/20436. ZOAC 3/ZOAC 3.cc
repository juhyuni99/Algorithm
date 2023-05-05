#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
//알파벳 키의 위치정보
int arr[26][2] = {
	{1,0}, //a
	{2,4}, //b
	{2,2}, //c
	{1,2}, //d
	{0,2}, //e
	{1,3}, //f
	{1,4}, //g
	{1,5}, //h
	{0,7}, //i
	{1,6}, //j
	{1,7}, //k
	{1,8}, //l
	{2,6}, //m
	{2,5}, //n
	{0,8}, //o
	{0,9}, //p
	{0,0}, //q
	{0,3}, //r
	{1,1}, //s
	{0,4}, //t
	{0,6}, //u
	{2,3}, //v
	{0,1}, //w
	{2,1}, //x
	{0,5}, //y
	{2,0}, //z
};


//set 자료구조 : 이진 검색 트리, 중복 허용x, 원소들을 삽입한 순서대로 저장
set<int> lft;
//초기화된 왼쪽 손(자음)으로 눌러지는 키들의 집합
void init(void) {
	lft.insert('q' - 'a'); //숫자로 변경된 값 원소에 저장
	lft.insert('w' - 'a');
	lft.insert('e' - 'a');
	lft.insert('r' - 'a');
	lft.insert('t' - 'a');
	lft.insert('a' - 'a');
	lft.insert('s' - 'a');
	lft.insert('d' - 'a');
	lft.insert('f' - 'a');
	lft.insert('g' - 'a');
	lft.insert('z' - 'a');
	lft.insert('x' - 'a');
	lft.insert('c' - 'a');
	lft.insert('v' - 'a');
}

int main(void) {
	init();
	char l, r;
	cin >> l >> r;

	string str;
	cin >> str;

	int res = 0; // 현재 위치에서 현재 입력해야 하는 문자까지 이동하는 데 걸리는 최소 이동거리
	//문자열의 모든 문자에 대해서 반복적으로 작업을 수행하는 루프 코드
	for (auto& i : str) {
		//lft set에 i - 'a' 값이 있다면 해당 값의 반복자(iterator)를 반환,
		// 그렇지 않은 경우에는 lft.end()를 반환
		if (lft.find(i - 'a') != lft.end()) { //set에 속한 문자임을 확인
			res += (abs(arr[l - 'a'][0] - arr[i - 'a'][0]) + abs(arr[l - 'a'][1] - arr[i - 'a'][1]));
			res += 1; // 이동시간 1초 더해주기
			l = i;
		}
		else {
			res += (abs(arr[r - 'a'][0] - arr[i - 'a'][0]) + abs(arr[r - 'a'][1] - arr[i - 'a'][1]));
			res += 1;
			r = i;
		}
	}
	cout << res;
	return 0;
}
