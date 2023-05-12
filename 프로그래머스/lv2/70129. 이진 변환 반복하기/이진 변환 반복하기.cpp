#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer(2, 0);
    int zero = 0, round = 0;//제거된 0의 개수, 회차
    
    while(s != "1")//1이되면 종료
    {
        string tmp = "";//임시 문자열
        int size = 0, num;
        round++;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')//0 나오면 제거 0 개수 증가
                zero++;
            else//1이 나오면 임시 문자열에 1 추가
                tmp += "1";
        }
        
        num = tmp.size();//0 제거된 문자열의 길이
        s = "";
        while(num > 0)//10진수 -> 2진수
        {
            s += to_string(num % 2);//나머지인 1이나 0을 문자열로 바꿔서 새로운 문자열에 추가해줌
            num /= 2;//2로 나눠서 몫만 취함
        }
    }
    
    answer[0] = round;//회차
    answer[1] = zero;//0개수
    return answer;
}