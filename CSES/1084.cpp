#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const int maxN = 2e5+7;
ll n,m,k ; 
ll cnt ;
multiset<ll> sz ;
ll ap[maxN] ;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m >> k ;
 
    for(int i=0;i<n;i++){
        cin >> ap[i] ;
    }
    sort(ap,ap+n);
 
    for(int i=0;i<m;i++){
        int x ; cin >> x ; sz.insert(x);
    }
    for(int i=0;i<n;i++){
        auto it = sz.lower_bound(ap[i]-k);
        if(it!=sz.end() && *it <= ap[i]+k){
            cnt++;
            sz.erase(sz.find(*it));
        }
    }
    cout << cnt ;
}

/*
Counter case if no sort : 
-------------------------
applicants : 15 9
apartments : 5 20
k = 10
-------------------------
*/
