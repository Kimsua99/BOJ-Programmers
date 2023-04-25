#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
        answer += arr[i];
    answer = answer / arr.size();
    return answer;
}
int main()
{
    vector<int> arr;

    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    cout << solution(arr);
}