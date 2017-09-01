#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Point
{
	int ry, rx ,by, bx, cnt;
	Point() {}
	Point(int _ry, int _rx, int _by ,int _bx,int _cnt) {
		ry = _ry;
		rx = _rx;
		by = _by;
		bx = _bx; 
		cnt = _cnt; 
	}

};
int n, m;
char g[11][11];
bool visit[11][11][11][11]; 
int ry, rx, by, bx;
queue<Point>q;
const int inf = 987654321;
int dy[4] = { 0,-1,1,0 }, dx[4] = { 1,0,0,-1 };
int bfs() {
	q.push(Point(ry, rx, by, bx, 0));
	visit[ry][rx][by][bx] = true; 
	int cnt = inf;
	while (!q.empty()) {
		Point now = q.front(); q.pop();
		//printf("%d %d %d %d %d\n", now.ry, now.rx, now.by, now.bx, now.cnt);
		if (now.cnt > 10) continue;
		if (g[now.ry][now.rx] == 'O') {
			cnt = min(cnt, now.cnt);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nby = now.by;
			int nbx = now.bx;
			int nry = now.ry;
			int nrx = now.rx;
			
			// 파란공 이동시키자.

			bool noo = false; 
			while (true) {
				nby += dy[i];
				nbx += dx[i];
				if (g[nby][nbx] == '#') {
					nby -= dy[i], nbx -= dx[i];
					break; 
				}
				if (g[nby][nbx] == 'O') {
					break;
				}
				if (nby == nry && nbx == nrx) {  // 부딪친 경우
					noo = true;
					nby -= dy[i], nbx -= dx[i];
					break;
				}
				
			}


			// 빨간공 이동시키자.
			while (true) {
				nry += dy[i];
				nrx += dx[i];
				if (g[nry][nrx] == '#') {
					nry -= dy[i], nrx -= dx[i];
					break;
				}
				if (g[nry][nrx] == 'O') {
					break;
				}
				if (nby == nry && nbx == nrx) {  // 부딪친 경우
					nry -= dy[i], nrx -= dx[i];
					break; 
				}
				
			}

			if (noo == true) { //파란공 끝까지 이동 시켜야 한다.
				while (true) {
					nby += dy[i];
					nbx += dx[i];
					if (g[nby][nbx] == '#') {
						nby -= dy[i], nbx -= dx[i];
						break;
					}
					if (g[nby][nbx] == 'O') {
						break;
					}
					if (nby == nry && nbx == nrx) {  // 부딪친 경우
						nby -= dy[i], nbx -= dx[i];
						break;
					}
					
				}
			}

			if (g[nby][nbx] == 'O') {
				continue;
			}
			else {
				if (visit[nry][nrx][nby][nbx]) continue;
				visit[nry][nrx][nby][nbx] = true;
				q.push(Point(nry, nrx, nby, nbx, now.cnt + 1));
			}
		}

	}
	if (cnt == inf)return -1;
	else return cnt;

}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'R') {
				ry = i, rx = j;
				g[i][j] = '.';
			}
			else if (g[i][j] == 'B') {
				by = i, bx = j;
				g[i][j] = '.';
			}
		}
	}
	
	cout<<bfs()<<endl;
	

}
