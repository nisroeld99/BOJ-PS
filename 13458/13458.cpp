#include<cstdio>
#include<vector>
#include <cstring>
#include <iostream>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,ii> iiii ;
typedef pair<ii,int> iii ;
typedef pair<long,long >lili;
typedef pair<double,double> dd;
const int inf = 987654321;
int a[1000001];
int main(){
 //   freopen("input.txt", "r", stdin);
    int n ;
    int A, B;
    scanf("%d",&n);
    for (int i =0 ; i<n ;i++){
        scanf("%d",&a[i]);
    }
    cin >> A >> B;
    for (int i =0 ; i<n ;i++){
        a[i]-=A;
        if ( a[i] < 0 ) a[i]= 0 ;
    }
    long long sum = n ; // 총감독관 수 ,
    for (int i =0 ; i<n ;i++){
        sum+= a[i]/B;
        if ( a[i] % B != 0 ){
            sum+=1 ;
        }
    }
    cout << sum << endl ;
    
    
}

