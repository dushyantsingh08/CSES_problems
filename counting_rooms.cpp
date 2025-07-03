#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
    pair<int, int> cell = q.front(); q.pop();
    int x = cell.first;
    int y = cell.second;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
            !visited[nx][ny] && grid[nx][ny] == '.') {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int roomCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] == '.') {
                bfs(i, j);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
