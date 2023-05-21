#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll maxN = 1e5+5 ; 
const ll INF = 1e18+7 ; 

int n ; 

vector<pair<int,int>> N ; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ; 
    for(int i=1;i<=n;i++){
        int a,b ; 
        cin >> a >> b ; 
        N.push_back({a,1});
        N.push_back({b,-1});
    }
    sort(N.begin(),N.end());

    ll s = 0 , ans = -INF ; 
    for(auto i : N){
        s+=i.second ;
        ans = max(ans,s);
    }
    cout << ans ;
}