#include <bits/stdc++.h>
#include<iostream>
#include<string> 
using namespace std;

int room[10] = { 0, };

int main() 
{
	string n;//방 번호 숫자를 문자열로 생각한다. 
	cin >> n;

	for (int i = 0; i < n.length(); i++)
	{
		room[n[i] - 48]++; // 48 = 아스키코드 0 / 배열에 0~9까지 각 숫자의 카운트 값을 저장한다.

	}

	int same = (room[6] + room[9] + 1) / 2; // 6번과 9번은 뒤집어서 사용 가능하므로 반쪽으로 친다. +1은 반올림
	room[6] = same;
	room[9] = same;

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < room[i])//1~10까지 돌면서 가장 큰 값을 찾는다.
			max = room[i];
	}

	cout << max;
}