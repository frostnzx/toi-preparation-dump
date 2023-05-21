#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll n ; 
vector<pair<ll,ll>> vec ; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ; 
    ll a,b ; 
    for(int i=0;i<n;i++){
        cin >> a >> b ; 
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    ll ans = 0 , sum = 0 ;
    for(auto i : vec){
        sum += i.first ; 
        ans += (i.second-sum) ; 
    }
    cout << ans ; 
}