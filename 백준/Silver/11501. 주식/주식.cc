#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int T, N;
    cin >> T;
    vector<int> v;

    while (T--) 
    {
        cin >> N;
        long long result = 0;

        for (int i = 0; i < N; i++) 
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }


        int max = v.back();

        for (int i = v.size() - 2; i >= 0; i--) 
        {
            if (v[i] > max) 
            {
                max = v[i];
            }
            else {
                result += (max - v[i]);
            }
        }

        cout << result << '\n';
        v.clear();
	}
}