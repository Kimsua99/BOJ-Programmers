#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    if(s.size() % 2 == 0)
    {
       answer = s[s.size() / 2 - 1];
        answer += s[s.size() / 2]; 
    }
    else
    {
       int n = s.size() / 2;
       answer = s[n];
    }
    return answer;
}