/*
 * 10881.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii ;
const int inf  = 987654312;
ii swap_( ii a){
    return ii(a.second, a.first);
}
ii merge_ (ii a,ii b){ // 가로 기준으로 합침)
    return ii(a.first + b.first , max( a.second, b.second) );
}
int calSize ( ii a, ii b){
    return min ( (a.first + b.first )* max (a.second , b.second ),  (a.second +b.second) * max (a.first, b.first )  );
}
int main() {
    int tc;
    scanf("%d",&tc);
    while (tc -- ) {
        vector<ii> v;
        for (int i = 0 ; i<3 ; i++ ) {
            int a,b;
            scanf("%d%d",&a,&b) ;
            v.push_back (ii(a,b));
        }
        
        int dab = inf ;
        dab = min (dab, calSize (merge_(v[0] , v[1] ) ,v[2]  ));
        dab = min (dab, calSize (merge_(swap_(v[0]), v[1] ),v[2]  ));
        dab = min (dab , calSize (merge_ (swap_(v[0]) ,swap_( v[1] )) , v[2] ) ) ;
        dab = min (dab, calSize (merge_ (swap_(v[0]) ,v[1]) ,swap_(v[2]) )   );
        dab = min (dab ,calSize ( merge_ (swap_ (v[0]),swap_(v[1])  ) , swap_(v[2]) ));
        dab = min (dab ,calSize ( merge_ ( (v[0]),swap_(v[1])  ) , swap_(v[2]) ));
        dab = min (dab ,calSize ( merge_ ((v[0]),swap_(v[1])  ) ,(v[2]) ));
        dab = min (dab ,calSize ( merge_ ( (v[0]),(v[1])  ) , swap_(v[2]) ));
        
        dab = min (dab, calSize (merge_(v[0] , v[2] ) ,v[1]  ));
        dab = min (dab, calSize (merge_(swap_(v[0]), v[2] ),v[1]  ));
        dab = min (dab , calSize (merge_ (swap_(v[0]) ,swap_( v[2] )) , v[1] ) ) ;
        dab = min (dab, calSize (merge_ (swap_(v[0]) ,v[2]) ,swap_(v[1]) )   );
        dab = min (dab ,calSize ( merge_ (swap_ (v[0]),swap_(v[2])  ) , swap_(v[1]) ));
        dab = min (dab ,calSize ( merge_ ( (v[0]),swap_(v[2])  ) , swap_(v[1]) ));
        dab = min (dab ,calSize ( merge_ ((v[0]),swap_(v[2])  ) ,(v[1]) ));
        dab = min (dab ,calSize ( merge_ ( (v[0]),(v[2])  ) , swap_(v[1]) ));
        
        dab = min (dab, calSize (merge_(v[2] , v[1] ) ,v[0]  ));
        dab = min (dab, calSize (merge_(swap_(v[2]), v[1] ),v[0]  ));
        dab = min (dab , calSize (merge_ (swap_(v[2]) ,swap_( v[1] )) , v[0] ) ) ;
        dab = min (dab, calSize (merge_ (swap_(v[2]) ,v[1]) ,swap_(v[0]) )   );
        dab = min (dab ,calSize ( merge_ (swap_ (v[2]),swap_(v[1])  ) , swap_(v[0]) ));
        dab = min (dab ,calSize ( merge_ ( (v[2]),swap_(v[1])  ) , swap_(v[0]) ));
        dab = min (dab ,calSize ( merge_ ((v[2]),swap_(v[1])  ) ,(v[0]) ));
        dab = min (dab ,calSize ( merge_ ( (v[2]),(v[1])  ) , swap_(v[0]) ));
        
        printf("%d\n",dab);
    }
                                 
    return 0  ;
}

