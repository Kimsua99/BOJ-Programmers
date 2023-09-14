#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> pr, int location) 
{
    queue<int> q;                        
    vector<int> v;     
    
    for(int i = 0; i < pr.size(); i++) 
    {
        q.push(i);//순서 큐에 넣음, 0123..
    }
    
    while(!q.empty()) 
    {
        int tmp = q.front();
        q.pop();
        
        if(pr[tmp] != *max_element(pr.begin(),pr.end()))
        {
            q.push(tmp);
        } 
        else 
        {
            v.push_back(tmp);
            cout << tmp <<'\n'; 
            pr[tmp] = 0;
        }
    }
    
    for(int i=0; i<v.size(); i++) 
    {
        if(v[i] == location)
            return i+1;
    }
}