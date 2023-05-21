#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll,ll,ll> ;

const int N = 2e5+5 ;

ll n , dp[N] ;

struct DATA{
    ll s , e , w ;

    bool operator<(const DATA &other) const {
        return e < other.e ;
    }
};

vector<DATA> vec ;
int ed[N] ;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n ;
	for(int i=1;i<=n;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        vec.push_back({u , v , w});
	}
	sort(vec.begin() , vec.end());
	for(int i=0;i<n;i++){
        ed[i] = vec[i].e ;
	}


    dp[0] = vec[0].w ;
	for(int i=1;i<n;i++){
        int idx = lower_bound(ed , ed+n , vec[i].s) - ed ;
        if(idx == 0){ // if you select job i you can't select any job anymore
            dp[i] = max(dp[i-1] , vec[i].w) ; // don't select job i / select job i as the last job
            continue;
        }
        dp[i] = max(dp[i-1] , dp[idx - 1] + vec[i].w) ;
	}

	cout << dp[n-1] ;
}
