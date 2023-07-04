#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int cur) //전위 : 정, 왼, 오
{
    cout << char(cur + 'A' - 1);//정점 출력
    if (lc[cur] != 0) //왼쪽 노드 있으면
        preorder(lc[cur]);//왼쪽 노드를 정점으로 해서 재귀
    if (rc[cur] != 0)//오른쪽 있으면
        preorder(rc[cur]);//오른쪽 노드를 정점으로 해서 재귀
}

void inorder(int cur) //중위 : 왼, 정, 오
{
    if (lc[cur] != 0) //왼쪽 있으면
        inorder(lc[cur]);//왼쪽을 기준으로 중위 재귀
    cout << char(cur + 'A' - 1);//가장 왼쪽 노드부터 출력
    if (rc[cur] != 0) //오른쪽 있으면
        inorder(rc[cur]);//오른쪽을 기준으로 중위 재귀
}

void postorder(int cur) //후위 : 왼, 오, 정
{
    if (lc[cur] != 0) //왼쪽 있으면
        postorder(lc[cur]);//왼쪽을 기준으로 후위 재귀
    if (rc[cur] != 0) //오른쪽 있으면
        postorder(rc[cur]);//오른쪽을 기준으로 후위 재귀
    cout << char(cur + 'A' - 1);//리프 노드 출력
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        char c, l, r; // cur, left, right
        cin >> c >> l >> r;
        if (l != '.')//자식 노드가 있는 경우
            lc[c - 'A' + 1] = l - 'A' + 1;//char(문자) to int
        if (r != '.') //자식 노드가 있는 경우
            rc[c - 'A' + 1] = r - 'A' + 1;
    }

    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
}