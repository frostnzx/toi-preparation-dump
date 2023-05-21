#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+10 ;

ll n , a , b , x[N] ;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b ;
    for(int i=1;i<=n;i++){
        cin >> x[i] ;
        x[i] += x[i-1] ;
    }

    deque<pii> dq ;
    ll ans = x[a] ;

    dq.push_back({0 , 0});


    // start at a to maintain window size > a
    for(int i=a;i<=n;i++){
        // maintain window size <= b
        while(!dq.empty() && dq.front().second < i - b){
            dq.pop_front();
        }
        if(!dq.empty()){
            ans = max(ans , x[i] - dq.front().first);
        }

        // maintain window size >= a
        // only consider pushing 1->i-a+1
        while(!dq.empty() && dq.back().first >= x[i - a + 1]){
            dq.pop_back();
        }
        dq.push_back({x[i-a+1] , i-a+1});
    }

    cout << ans ;
}

// tricks : no need to worry about position that too close because
// we only consider pushing 1->i-a+1 so as long as we move through right
// it the size of subarray would never be too small

