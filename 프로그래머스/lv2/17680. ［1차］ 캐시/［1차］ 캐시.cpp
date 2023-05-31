#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;

    //캐시 크기가 0
    if (cacheSize == 0) 
    {
        answer = cities.size() * 5;
        return answer;
    }

    vector<string> cache;

    for (int i = 0; i < cities.size(); i++) 
    {
        string check = cities[i];
        transform(check.begin(), check.end(), check.begin(), ::tolower);  // 소문자 변환
        auto it = find(cache.begin(), cache.end(), check); //해당 벡터에 값이 있으면 인덱스 반환, 없으면 가장 뒤에 원소 인덱스 반환

        //캐시에 있음 -> 기존꺼 삭제하고 1 추가
        if (it != cache.end()) //값이 없는 경우 가장 뒤의 원소 인덱스 = end() 값
        {
            cache.erase(it);
            cache.push_back(check);
            answer++;

        }
        //캐시에 없음
        else 
        {
            //캐시에 빈자리 있음
            if (cache.size() < cacheSize)//꽉 차지 않은 경우 -> 그냥 뒤에 추가
                cache.push_back(check);

            //캐시에 빈자리 없음
            else //꽉 찬 경우 -> 맨 앞 삭제하고 뒤에 추가
            {
                cache.erase(cache.begin());
                cache.push_back(check);
            }
            answer += 5;
        }
    }

    return answer;
}