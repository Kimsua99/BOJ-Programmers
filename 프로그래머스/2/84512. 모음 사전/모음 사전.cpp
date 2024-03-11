#include <string>
#include <vector>
using namespace std;

string alpha = "AEIOU";
int answer = 0, cnt = 0;

void dfs(string str, string word)
{
    if (str.size() > 0)
    {//하나라도 골랐다면
        cnt++;
        if (str == word) 
            answer = cnt;//단어와 같다면
    }
    if (str.size() == 5) 
        return ;//5글자가 되었다면
    
    for(int i=0;i<5;i++)
    {//aeiou순으로 골라서 추가해 넘겨준다.
        string tmp(str);
        tmp.push_back(alpha[i]);
        dfs(tmp, word);
    }
}

int solution(string word) 
{
    dfs("", word);
    return answer;
}