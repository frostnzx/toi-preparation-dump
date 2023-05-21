#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long ;
const int N = 2e5+5 ; 

ll n , x , t[N] ;

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x ; 

    ll mx = -1e18 ; 
    for(int i=1;i<=n;i++)
        cin >> t[i] , mx = max(mx,t[i]) ;
    ll l=1 , r = mx*x , ans ; 
    while(l<=r){
        ll mid = (l+r)/2 , sum = 0 ;
        for(int i=1;i<=n;i++)
            sum += (mid)/t[i] ; 
        if(sum >= x){
            ans = mid ; 
            r = mid-1 ; 
        }
        else l = mid+1 ;
    }
    cout << ans ;
}