/*
 *  1620_2   
 */
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

int n, m;
char inp[25];
string s[100005];
unordered_map<string, int> r;

void proc() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", inp);
		s[i].assign(inp);
		r[s[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s", inp);
		if ('0' <= inp[0] && inp[0] <= '9') {
			int v;
			sscanf(inp, "%d", &v);
			printf("%s\n", s[v].c_str());
		}
		else {
			printf("%d\n", r[inp]);
		}
	}
}

int main() {
	proc();
	return 0;
}
