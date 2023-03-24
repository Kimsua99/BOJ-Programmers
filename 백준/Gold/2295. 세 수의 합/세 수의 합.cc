#include <bits/stdc++.h>
using namespace std;

//1. 3개의 수 중에 2개의 수를 골라 이의 합을 모두 구한 배열 two를 생성
//2. two의 원소 합과 나머지 한 수의 원소 합의 결과가 되는 배열에서 결과 - 나머지 한 수의 원소 = two의 원소로 식을 바꿈
//3. two에 뺀 값이 있는지 이분탐색으로 확인함
int n;//n개의 자연수들
int a[1005];//자연수들이 입력될 배열 a
vector<int> two;//자연수 집합에서 뽑은 3개의 수 중 2개의 수들의 합이 담길 벡터배열 two

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;//집합에 담길 자연수 개수 입력받음
    for (int i = 0; i < n; i++) 
        cin >> a[i];//a배열에 자연수 개수만큼 자연수 담김

    sort(a, a + n);//해당 a 배열을 정렬함

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++)
            two.push_back(a[i] + a[j]);//이중 for문 돌면서 3개 중 2개의 원소 합을 two 배열에 넣음
    }

    sort(two.begin(), two.end());//two 배열 정렬

    for (int i = n - 1; i > 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (binary_search(two.begin(), two.end(), a[i] - a[j])) //세개 수 값의 합에서 a 배열의 3개 수 중 합에 사용된 2개를 제외한 1개의 수를 제외한 값이 two 배열에 있는지 이분탐색으로 확인
            {
                cout << a[i];//two 배열에 해당 값이 있으면 바로 그 값 출력(큰 수부터 정렬되었기 떄문에 바로 출력해도 최댓값 나옴)
                return 0;
            }
        }
    }
}