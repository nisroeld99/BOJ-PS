#include <iostream>

using namespace std;


int d[21][21][21];
int go(int a,int b,int c){
    if (a<=0  || b<=0 || c<=0  ) return 1;
    if (a>20 || b>20 ||c > 20 ) return go(20,20,20);
    int & ret = d[a][b][c];
    if (ret != -1 ) return ret;
    ret = 0;
    if (a< b && b<c ){
        ret+= go (a ,b, c-1) + go( a, b-1,c-1) -go(a, b-1, c);
    }
    else {
        ret+= go (a-1 ,b, c) + go (a-1 ,b-1,c) + go (a-1,b,c-1) -go(a-1,b-1,c-1);
    }
    
    return ret;
}

int main(){
    int a,b,c;
    
    for (int i =0 ; i<=20;i++)
        for (int j=0 ;j<=20 ;j++)
            for (int k = 0 ; k<=20 ;k++)
                d[i][j][k] = -1;
    
    while (true){
        
        scanf("%d%d%d",&a,&b,&c);
        if (a==-1 && b== -1 && c==-1)break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,go(a,b,c));
        
    }
    
}
