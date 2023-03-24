#include <bits/stdc++.h>
using namespace std;

// 1. sort를 이용해 먼저 정렬을 한다
// 2. 중복 값을 제거한다
// 2_1. 이는 각 원소에 대해 자신의 전 원소와 자신이 다른 경우 새 배열에 넣어주는 식으로 구현한다.
// 3. 이분탐색을 해서 자기보다 작은 원소의 개수를 구해 출력한다.

int n;
int x[1000005];
vector<int> tmp, uni; // tmp = x를 정렬할 결과를 저장할 배열, uni는 unique라는 의미로 tmp에서 중복 제거된 결과 저장할 배열.

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;//n개의 좌표
    for (int i = 0; i < n; i++) 
    {
        cin >> x[i];
        tmp.push_back(x[i]);//입력받은 원소를 벡터에 끝에 넣어줌.
    }
    sort(tmp.begin(), tmp.end());//벡터 전체를 돌면서 정렬함. 

    for (int i = 0; i < n; i++) //중복 제거를 수행하는 부분 
    {
        if (i == 0 || tmp[i - 1] != tmp[i])//만약 원소가 맨 앞에 있거나 본인과 본인 이전의 원소가 다른 경우 
            uni.push_back(tmp[i]);//uni 벡터에 해당 값을 넣어준다.
    }

    for (int i = 0; i < n; i++)//n개의 좌표를 반복
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    // itetator(반복자)사용 -> 배열의 요소를 가리키는 포인터라고 생각하면 됨. 
    // lower_bound(가장 왼쪽꺼 인덱스 반환)를 사용해 iterator를 찾아서 uni.begin()을 빼줌. = 찾으려는 값 인덱스에서 배열 전체의 첫번째 인덱스 빼주면 해당 인덱스가 몇번째에 있는지 알 수 있음 = 자기보다 작은 값의 개수 
}