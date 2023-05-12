#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++)
    {
        
        answer += A[i] * B[i];
    }


    return answer;
}