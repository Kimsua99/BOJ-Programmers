#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &a, int &b) //내림차순 정렬 함수
{
    return a>b;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    vector<int> count(10000001);//중복 값 개수 세어주기 위한 벡터
    
    for(int i=0; i<tangerine.size(); i++) //for문 돌면서 중복값 개수 세주기. ex) 1111 -> 4개
    {
        count[tangerine[i]] += 1;
    }
    
    sort(count.begin(), count.end(), cmp);//내림차순 정렬해서 값이 큰 순으로 정렬
    
    int i=0; 
    
    while(k > 0) //한 상자에 담으려는 귤의 개수 k개
    {
        k -= count[i];//가장 많이 있는 숫자의 개수에서 k를 뺌
        i += 1;//해당 숫자 끝나면 다음 숫자 확인
        answer += 1;//다음 숫자 확인 -> 다른 종류로 넘어가므로 결과에 +1 해줌
    }
    
    return answer;
}