#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    map<string,int> m;

    for (int i = 0; i < phone_book.size(); i++) 
    {
        m[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string pn = "";
        for (int j = 0; j < phone_book[i].length() - 1; j++)
        {
            pn += phone_book[i][j];
            if (m[pn])
                return false;
        }
    }

    return answer;
}