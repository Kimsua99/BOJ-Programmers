#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{

    for(int i = 0; i < lost.size();i++)
    {
        for(int j = 0; j<reserve.size();j++)
        {
            if(lost[i] == reserve[j])//원소가 같은 경우
            {
                lost.erase(lost.begin()+i);//해당 인덱스 값 삭제
                reserve.erase(reserve.begin()+j);//해당 인덱스 값 삭제
                i = -1;//삭제했으니까 한칸 앞으로 이동
                break;//반복문 탈출
            }
        }
    }

    int answer = n-lost.size();//잃어버리지 않은 학생의 수

    sort(lost.begin(),lost.end());//정렬
    sort(reserve.begin(),reserve.end());//정렬
    for(int i = 0; i < lost.size();i++)
    {
        for(int j = 0; j < reserve.size();j++)
        {
            if(lost[i] - 1 == reserve[j]|| lost[i] + 1 == reserve[j])//잃어버린 학생이 빌려줄 수 있는 학생의 바로 앞번호나 뒷번호일 경우
            {
                answer++;//빌려줬기 때문에 체육 들을 수 있어서 증가
                reserve.erase(reserve.begin()+j);//빌릴 수 있는 학생 수에서 해당 인덱스 삭제
                break;
            }
        }
    }

    return answer;
}