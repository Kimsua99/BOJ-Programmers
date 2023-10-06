//플로이드 알고리즘 경로 복원
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;//최대값
int d[105][105];//비용 담을 테이블
int nxt[105][105];//복원 경로 정보 담을 테이블
int n, m;//도시, 버스

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(d[i], d[i] + 1 + n, INF);//일단 모든 테이블 값 최대로 맞춰줌
	}

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;//시작 도시, 도착 도시, 비용
		d[a][b] = min(d[a][b], c);//비용이랑 기존 테이블 값 비교해서 수정
		nxt[a][b] = b; //초기 nxt 테이블. b가 최종 경로이므로 b로 테이블 채워줌.
	}

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;//자기 자신 값은 0으로 바꿈
	}

	for (int k = 1; k <= n; k++)//중간에 거쳐가는 부분은 반드시 제일 바깥에 있어야 함
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])//경유한 경우가 더 비용이 작은 경우
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//더 작은 값으로 수정
					nxt[i][j] = nxt[i][k];//경유한 지점 nxt에 저장
				}
			}
	//최소 비용 테이블 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == INF)//값이 최대면 0으로 수정 = i에서 j로 갈 수 없는 경우가 해당됨.
				cout << "0 ";
			else
				cout << d[i][j] << ' ';//아니면 해당 테이블 값 출력
		}
		cout << '\n';
	}
	//i에서 j로 가는 최소 비용에 포함된 도시의 개수, 경로 출력 (공백 구분)
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == 0 || d[i][j] == INF)//i에서 j로 갈 수 없는 경우
			{
				cout << "0\n";
				continue;
			}
			vector<int> path;//경로 담을 벡터 배열
			int st = i;//경유 지점

			while (st != j)//j가 되면 목적지 도달
			{
				path.push_back(st);//경로 벡터에 경유지 저장
				st = nxt[st][j];//다음 경유지 변경
			}
			path.push_back(j);//최종 목적지 저장

			cout << path.size() << ' ';//경유 도시 개수, 공백 출력

			for (auto x : path)
				cout << x << ' ';//경로 출력
			cout << '\n';
		}
	}
}