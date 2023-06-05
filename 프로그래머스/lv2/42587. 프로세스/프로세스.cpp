#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> pr, int location) 
{
    int i = 0;
    int answer = pr.size();
    while (true)
    {
        for (int j = i + 1; j < pr.size(); j++) 
        {
            if (pr[i] < pr[j]) 
            {
                pr.push_back(pr[i]);
                
                if (location == i) 
                {
                    location = pr.size() - 1;
                }
                break;
            }
        }
        if (i == location) 
        {
            return answer - (pr.size() - i) + 1;
        }
        i++;
    }
}