#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, h, w;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];

int dx[4] = { 0, 0, 1, -1 };

int dy[4] = { 1, -1, 0, 0 };
int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool escape = false;

        queue<pair<int, int>> Qf;
        queue<pair<int, int>> Qs;

        cin >> w >> h;

        for (int i = 0; i < h; i++) 
        {
            fill(visF[i], visF[i] + w, 0);
            fill(visS[i], visS[i] + w, 0);
        }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) 
            {
                char c;
                cin >> c;
                if (c == '#') 
                    board[i][j] = -1;
                else {
                    if (c == '@') {
                        Qs.push({ i, j });
                        visS[i][j] = 1;
                    }
                    else if (c == '*') {
                        Qf.push({ i, j });
                        visF[i][j] = 1;
                    }
                    board[i][j] = 0;
                }
            }
        while (!Qf.empty()) 
        {
            auto v = Qf.front();
            Qf.pop();

            for (int k = 0; k < 4; k++) 
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];

                if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
                if (board[nx][ny] == -1) continue;
                if (visF[nx][ny]) continue;

                visF[nx][ny] = visF[v.X][v.Y] + 1;
                Qf.push({ nx, ny });
            }
        }
        while ((!Qs.empty()) && (!escape)) 
        {
            auto v = Qs.front();
            Qs.pop();

            for (int k = 0; k < 4; k++) 
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || h <= nx || ny < 0 || w <= ny) 
                {
                    cout << visS[v.X][v.Y] << '\n';
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1) continue;
                if (visS[nx][ny]) continue;
                if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
                visS[nx][ny] = visS[v.X][v.Y] + 1;
                Qs.push({ nx, ny });
            }
        }
        if (!escape) cout << "IMPOSSIBLE" << '\n';
    }
}