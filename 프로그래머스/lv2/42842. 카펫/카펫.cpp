#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    vector<int> y;

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
            y.push_back(i);
    }

    for (int i = 0; i < y.size(); i++)
    {
        int y2 = yellow / y[i];
        if ((y[i] + 2) * (y2 + 2) == brown + yellow)
        {
            answer.push_back(y2 + 2);
            answer.push_back(y[i] + 2);
            break;
        }
    }

    return answer;
}