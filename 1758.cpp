#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	    int n ;scanf("%d",&n);
			    int a[100001];
					    for (int i =1 ; i<=n ;i++)
								        scanf("%d",&a[i]);
							    
							    sort(a+1, a+n+1 ,greater<int>() );
									    long long dab = 0;
											    for (int i =1 ;i<=n; i++){
														        if ( i-1 > a[i] ){
																			            break;
																									        }
																		        dab+=a[i] -  ((i-1));
																						    }
													    cout<< dab<<endl;
															    
															    
															    
															    
}
