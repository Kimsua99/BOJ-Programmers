#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    vector<int> v;
    
    for(int i = 0; i < discount.size(); i++) // discount의 모든 인덱스에서 10일 카운트
    { 
        int idx = i; // idx는 시작위치 i로 초기화
        v = number; // v에 필요한 개수들을 초기화
        
        while(idx < discount.size() && idx < i+10) // idx는 discount를 넘을 수 없고, 시작 i부터 10일을 초과 불가
        { 
            for(int j = 0; j < want.size(); j++) // want의 모든 인덱스(j)를 비교하며 discount[idx]와 일치하는 제품 찾기
            { 
                if(want[j] == discount[idx]) // 일치하면
                { 
                    v[j]--; // 해당 제품의 원하는 개수 감소
                }
            }
            idx++; // 다음날로 이동
        }
        
        bool flag = false; // 필요한만큼 못산 제품이 있는지 판별
        
        for(int k = 0; k < v.size(); k++) // 벡터 v를 모두 탐색
        { 
            if(v[k] > 0) // 필요한 개수가 1이상이면 필요한만큼 모두 못산것임
                flag = true; // 못산 제품이 있다(true)로 갱신
        }
        
        if(flag == false) // 위의 반목문을 모두 돌았더니 false라면
            answer++; // 모든 제품을 필요한만큼 모두 산 것이니 답 추가
    }
    
    return answer;
}