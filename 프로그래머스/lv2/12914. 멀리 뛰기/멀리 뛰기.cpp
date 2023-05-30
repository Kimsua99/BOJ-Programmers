#include <string>
#include <vector>
 
using namespace std;
 
long long solution(int n) 
{
    vector<long long> DP(n + 1, 0);
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
        DP[i] = DP[i] % 1234567;
    }
    return DP[n] % 1234567;
}
