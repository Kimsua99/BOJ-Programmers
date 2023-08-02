#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 진출 순서대로 정렬하기 위한 bool함수
bool comp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    // 0. 먼저 빨리 진출하는 순서대로 정렬한다. 그럼 지나갈 때 찍힐테니까!
    sort(routes.begin(), routes.end(), comp);
    // 1. 진출할 때까지 카메라에 찍히지 않은 경우 진출지점에 카메라를 설치한다.
    int camera = -30001; // 카메라가 설치된 위치를 담은 변수 / 초기값은 -30000보다 작아야한다!
    for (int i = 0; i < routes.size(); ++i){
        if(routes[i][0] > camera){ // 카메라 설치 위치가 진입 위치보다 앞이라면
            camera = routes[i][1]; // 새로운 routes 진출구간에 카메라 추가 설치
            ++answer; // 카메라 설치했으니 answer에 1 더함
        }
    }
    return answer;
}
