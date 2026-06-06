//给定一个 N*M 的矩阵，每个位置 (i, j) 上有一个正整数 v[i][j]。
//初始时玩家位于固定位置 (sx, sy)，拥有长度为 L 的大刀。
//若当前位置 (i, j) 与起点 (sx, sy) 的距离 d(i,j) <= 当前刀长，则该格子可以被大刀触及，
//触及后刀长增加 v[i][j]。
//每个格子最多触及一次，求最终刀长的最大值

#include <bits/stdc++.h>
using namespace std

struct cell {
  long distance; //到起点（大刀所在位置）距离
  long value; //格子的数值
};

int main() {
  int N,M;
  cin >> N >> M;

  int sx, sy;
    long long L;
    cin >> sx >> sy >> L;

  vector<Cell> cells;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long v;
            cin >> v;

            long long dist = llabs(i - sx) + llabs(j - sy);

            cells.push_back({dist, v});
        }
    }

    sort(cells.begin(), cells.end(), [](const Cell& a, const Cell& b) {
        return a.dist < b.dist;
    });

    long long cur = L;

    for (const Cell& cell : cells) {
        if (cell.dist <= cur) {
            cur += cell.val;
        }
    }

    cout << cur << '\n';

    return 0;
}
