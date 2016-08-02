#include <cstdio>

using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = (n-n%100)  ; i<= n-n%100 + 99  ;i++) {
		if ( i%m == 0){
			if (i%100 < 10){
				printf("0%d\n", i%100);
			}else{
				printf("%d\n",i%100);
			}
			break;
		}
	} 
}
