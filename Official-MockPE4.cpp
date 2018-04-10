#include <bits/stdc++.h>
using namespace std;

#define MAX_RC 1010

int i, j, R, C, F = 0, S = 0;
int dr[] = { 0, 1, 0,-1}; // E/S/W/N
int dc[] = { 1, 0,-1, 0};
string photo[MAX_RC];
bool isSmiling;

void floodFill(int r, int c) {
    if (photo[r][c] == '.') return;
    if (photo[r][c] == 'v') isSmiling = 1;
    photo[r][c] = '.';
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        floodFill(nr,nc);
    }
}

int main() {
    //freopen("in.txt","r",stdin);
  cin >> R >> C;
  cin.get();
  for (i = 0; i < R; i++) getline(cin,photo[i]);
    for (int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(photo[i][j] == '#') {
                isSmiling = 0;
                floodFill(i,j);
                F++;
                S += isSmiling;
            }
        }
    }

  printf("%d\n", F);
  printf("%d\n", S);
  return 0;
}
