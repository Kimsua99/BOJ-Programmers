#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int n;

int binarysearch(int target)
{
    int st = 0;
    int en = n - 1;
    while (st <= en)//시작점이 끝점보다 앞에 있거나 같을 경우 반복
    {
        int mid = (st + en) / 2;
        if (a[mid] < target)//중간보다 목표가 뒤에 있으면 중간 앞부분은 안봐도 됨
            st = mid + 1; //시작 지점을 중간 바로 다음으로 잡아서 탐색
        else if (a[mid] > target)//중간보다 목표가 앞에 있으면 중간 뒷부분은 안봐도 됨
            en = mid - 1; //끝 지점을 중간 바로 이전으로 잡아서 탐색
        else
            return 1;//중간 지점이 목표인 경우이므로 1 반환
    }
    return 0;//st > en 인 경우이므로 while문 탈출, 0 반환
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int m;
    cin >> m;
    while (m--)
    {
        int t;
        cin >> t;
        cout << binarysearch(t) << '\n';
    }
     
}