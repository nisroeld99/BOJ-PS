#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
vector<ii> g[11111];
int n, m;
int d1[11111], d2[11111];
priority_queue<ii, vector<ii>, greater<ii> >pq;
void dijk() {
	for (int i = 0; i < 11111; i++)
		d1[i] = 987654321;
	while (!pq.empty()) {
		ii temp =pq.top(); pq.pop();
		int now_cost = temp.first;
		int now = temp.second;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].second;
			int next_cost = g[now][i].first + now_cost;
			
			if (d1[next] > next_cost) {
				d1[next] = next_cost;
				pq.push(ii(next_cost, next));
			}
		}
	}
}

void dijk2() {
	for (int i = 0; i < 11111; i++)
		d2[i] = 987654321;
	while (!pq.empty()) {
		ii temp = pq.top(); pq.pop();
		int now_cost = temp.first;
		int now = temp.second;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].second;
			int next_cost = g[now][i].first + now_cost;

			if (d2[next] > next_cost) {
				d2[next] = next_cost;
				pq.push(ii(next_cost, next));
			}
		}
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		g[from].push_back(ii(cost,to));
		g[to].push_back(ii(cost, from));
	}
	int mn, mcost;
	cin >> mn >> mcost;
	bool check[11111];
	memset(check, 0, sizeof(check));
	for (int i = 0; i < mn; i++) {
		int sc; scanf("%d",&sc);
		pq.push(ii(0, sc));
		d1[sc] = 0;
		check[sc] = true; 
	}
	
	dijk();


	int sn, scost; 
	cin >> sn >> scost;
	for (int i =  0; i < sn; i++) {
		int sc; scanf("%d",&sc);
		pq.push(ii(0, sc));
		d2[sc] = 0;
		check[sc] = true;
	}
	
	dijk2();
	const int inf = 9867654321;
	int sum_max = inf;
	for (int i = 1; i <= n; i++) {
		if (d1[i] > mcost || d2[i] > scost|| check[i] ) continue;
		int temp_sum=d1[i] + d2[i];
		if (temp_sum < sum_max) {
			sum_max= temp_sum;
		}
	}

	if (sum_max == inf)cout << -1 << endl;
	else cout<< sum_max << endl;
}
