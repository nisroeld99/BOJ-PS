/*
 * 10984.cpp
 *
 */
#include <iostream>

using namespace std;
int T;


int main(){
    cin>>T;
    
 
    while (T--){
        int n;
        cin>>n;
        double sum = 0.0; //  double 자료형으로 해야함 
        int numS= 0;
        for (int i = 0 ; i<n; i++){
            int sc1;
            double sc2;
            cin>>sc1>>sc2;
            sum+= sc1* sc2;
            numS+=sc1;
        
        }
        printf("%d %.1lf\n", numS,sum/numS);
    
    }
    
   
}
