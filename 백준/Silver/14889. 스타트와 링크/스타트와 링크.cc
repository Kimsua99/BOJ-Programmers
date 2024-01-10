#include <iostream>
#include <cmath>
using namespace std;
int n, num;
int map[22][22];
int team1[12];
int team2[12];
bool visit[12] = {0};
int ans = -1;
void fc(int start, int cnt){
    if(cnt == num){
        int temp1 = 0;
        int temp2 = 0;
        for (int i = 0; i < n; i++){
            if(visit[i]){
                team1[temp1] = i; // 1번팀에 넣어줌
                temp1++;
            }else{
                team2[temp2] = i; // 2번 팀에 넣어줌
                temp2++;
            }
        }
        temp1 = 0;
        temp2 = 0;
        for (int j = 0; j < num - 1; j++)
        {
            for (int k = j + 1; k < num; k++)
            {
                temp1 += map[team1[j]][team1[k]] + map[team1[k]][team1[j]]; // 1번 팀 능력치
                temp2 += map[team2[j]][team2[k]] + map[team2[k]][team2[j]]; // 2번 팀 능력치
            }
        }
        int sub = abs(temp1 - temp2); // 절댓값
        if(ans > sub || ans == -1){ 
            // 더 작은 값 저장 -1일때는 처음일 경우
            ans = sub;
        }
    }else{ // 팀 구성하기
        for (int i = start; i < n;i++){ // 중복 고려해서 i=start
            if(!visit[i]){
                visit[i] = true;
                fc(i+1, cnt + 1);
                visit[i] = false;
            }
        }
    }
    
}
 
int main(){
    ios::sync_with_stdio(false);
    cin >>n;
    num = n / 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    fc(0, 0);
    cout << ans;
    return 0;
}