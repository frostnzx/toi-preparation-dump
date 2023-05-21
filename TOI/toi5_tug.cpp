#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 5e5+5 ;

int n ; vector<ll> a , b ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 ,x;i<=n;i++){
        cin >> x ; a.push_back(x) ;
    }
    for(int i=1 ,x;i<=n;i++){
        cin >> x ; b.push_back(x) ;
    }
    sort(a.begin() , a.end()); sort(b.begin() , b.end()) ;


    ll ans = 0 ;
    for(int i=0;i<n;i++){
        ans += abs(a[i] - b[i]) ;
    }

    cout << ans ;
}
