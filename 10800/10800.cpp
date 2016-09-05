#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int main() {
    int n ;
    scanf("%d",&n);
    vector<ii> a[2001];
    for (int i = 1 ; i<=n ; i++ ) {
        int color, size ;
        scanf("%d%d",&color,&size);
        a[size].push_back({ color,i});
    }
    vector<int> c(n+1,0);
    vector<int> dab(n+1,0);
    int sum = 0 ;
    for (int i = 2;  i<= 2000; i++ ) {
        sum += a[i-1].size() * (i-1);
        for (int j= 0 ; j< a[i-1].size() ; j++ )
            c[ a[i-1][j].first  ] += i-1;
        for (int j= 0 ; j< a[i].size() ;j++ )
            dab[ a[i][j].second ] = sum-c[ a[i][j].first  ];
    }
    for (int i =1 ; i<=n; i++)
        printf("%d\n",dab[i]);
}
