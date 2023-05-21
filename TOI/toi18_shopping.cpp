#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 5e5+5 ;
const int MOD = 1e9+7 ;

int n , q , qsP[N] , qsN[N] ;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        if(x > 0){
            qsP[i] = x ;
        }
        else {
            qsN[i] = -x ;
        }
        qsP[i] += qsP[i-1] , qsN[i] += qsN[i-1] ;
    }

    while(q--){
        int s , m  ;
        cin >> s >> m ;

        s++;

        int l = 1 , r = n-1 , stop = n ;
        while(l <= r){
            int mid = (l+r)/2 ;
            if(qsN[mid] - qsN[s - 1] >= m){
                stop = mid ;
                r = mid-1 ;
            }
            else {
                l = mid+1 ;
            }
        }
        cout << qsP[stop] - qsP[s - 1] << "\n" ;
    }

}

