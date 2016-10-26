/*
 *  1509   
 */
#include <iostream>
#include <cstring>
using namespace std;
string s;
int d[2555];
int p[2555][2555];


int isPal (int f,int l){
    int & ret = p[f][l];
    if (ret != -1 ) return ret ;
    if ( f +1 == l ) {
        if ( s[f] == s[l]){
            return ret= 2;
        }
        else
            return ret= 1;
    }
    if ( f == l ){
        return ret= 2;
    }
    
    if ( s[f] == s[l]){
        ret= isPal(f+1 , l-1);
    }
    else {
        ret = 1;
    }
    return ret ;

}



int main(){
    
    memset (p , -1 ,sizeof(p));
    cin >> s;
    int size = (int)s.size();
    s= " "+ s;
   
    
    
    for (int i =1 ; i<=size ; i++){
        d[i]= 987654321;
        for (int j= 1; j<=i ; j++){
            if ( isPal(j,i) == 2 )
                d[i] = min ( d[i] , d[j-1] +1 );
        }
    
    }
    cout << d[size]<<endl;
}
