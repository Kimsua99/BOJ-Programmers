#include <bits/stdc++.h>
using namespace std;

int parent[101];//부모 집합

int find(int x)
{
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;    
    
    for(int i = 0; i < n; i++)
        parent[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++)
    {
        int st = costs[i][0];
        int en = costs[i][1];
        int cost = costs[i][2];
        
        if(find(st) != find(en))
        {
            answer += cost;
            parent[find(en)] = find(st);
        }
    }
    return answer;
}