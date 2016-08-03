#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ii ;
vector<ii> g[100001];
int main()
{
	int n , m ;
	scanf("%d%d",&n,&m);
	for (int i = 0 ; i< m ; ++i ) {
		int from ,to , cost; 
		scanf("%d%d%d",&from,&to,&cost);
		g[from].push_back(ii(cost, to));
		g[to].push_back(ii(cost,from)); 
	}
	

}
