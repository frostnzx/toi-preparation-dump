#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll,ll,ll> ;

const int N = 1e5+5 ;

ll n , m , k , v[N] , cnt , sum ;
priority_queue<ll , vector<ll> , greater<ll>> pq ;

bool solve(ll mid){
    cnt = 0 , sum = 0 ;

    for(int i=1;i<=n;i++){
        if(pq.size() + 1 <= k){
            sum += v[i] ;
            pq.push(v[i]);
        }
        else {
            if(v[i] > pq.top()){
                sum = sum + v[i] - pq.top(); // switch k-th best
                pq.pop();
                pq.push(v[i]);
            }
        }

        if(sum >= mid && pq.size() == k){
            cnt++;
            sum = 0 ;
            while(!pq.empty()) pq.pop();
        }
    }
    while(!pq.empty()) pq.pop();

    return (cnt >= m) ;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k ;
	for(int i=1;i<=n;i++){
        cin >> v[i] ;
	}

	ll l = 0 , r = 1e12 , ans ;
	while(l<=r){
        ll mid = (l+r)/2 ;

        if(solve(mid)){
            l = mid+1 ;
            ans = mid ;
        } else {
            r = mid-1 ;
        }
	}

	cout << ans ;
}

//warning : ยังไงแต่ละร้านก็ต้องเลิอก k ช่องน้อยกว่าไม่ได้
