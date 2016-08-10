#include <iostream>
#include <cstring>
using namespace std;

int a[16][16];
int d[(1<<16)+1];
int main(){
	int n ;
	cin >> n ;
	for (int i =0 ; i<n ;i++)
		for (int j=0 ;j<n ;j++)
			scanf("%d",&a[i][j]);

	string s;
	cin >> s;
	int visit = 0 ;
	for (int i = 0 ; i<s.size(); ++i){
		if (s[i]=='Y'){
			visit = (visit|(1<<i));
		}
	}
	memset(d,-1,sizeof(d));
	d[visit ]= 0;		
	for (int i = 0 ; i< (1<<n) ;i++ ){
		if (d[i]==-1) continue; //존재 x
		for (int j= 0 ;j<n; j++){
			if ( (1<<j) & i ) { //j 가 존재
				for (int k = 0 ; k<n; k++){
					if ( ((1<<k) & i)==0 ){ //불꺼져있는 k
						if (d[i|(1<<k)] ==-1 || d[i|(1<<k)] > d[i] + a[j][k] ){
							d[i|(1<<k)] = d[i] + a[j][k];
						}
					}
				
				}
			}
		}
	
	}

	int p ;
	scanf("%d",&p);
	int ans = -1; 
	for (int i = 0 ; i< (1<<n) ;++i){
		if (d[i]==-1) continue;
		int cnt = 0 ;
		for (int j= 0 ;j<n; j++){
			if ( (1<<j) & i ) 
				cnt++;
		}
		if (cnt >=p){
			if ( ans == -1 || ans > d[i] ) {
				ans = d[i];
			}
		}
	}
	printf("%d\n",ans);


}
