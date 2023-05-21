#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;
const int MOD = 1e9+7 ;

ll n , k , v[N] , ans ;

unordered_map<ll , ll> cnt ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }
    ll l = 1 , r = 1 , distinct_cnt = 0 ;
    while(l <= n && r <= n){
        cnt[v[r]]++ ;
        if(cnt[v[r]] == 1){
            distinct_cnt++ ;
        }
        while(distinct_cnt > k && l <= r){
            cnt[v[l]]-- ;
            if(cnt[v[l]] == 0) {
                distinct_cnt -- ;
            }
            l++;
        }
        //cout << "distinct_cnt = " << distinct_cnt << "\n" ;
        //cout << "l = " << l << " r = " << r << "\n" ;
        ans += (r - l) + 1 ;
        r++;
    }
    cout << ans  ;
}
