#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int arr[9];
    int sum = 0;

    for (int i = 0; i < 9; i++)//배열에 9개 숫자 입력 받고 9개의 합 구함.
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr, arr + 9);//오름차순 정렬

    for(int i = 0; i < 8 ; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (arr[i] + arr[j]) == 100)//9개 수의 합에서 2개의 수 뺀 것이 100이면 그 두 수 제외
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)// 해당 i, j에서 위의 2개의 수가 발견된 것이므로 k가 i,j가 아니라면 숫자 출력
                    {
                        cout << arr[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
