#include<bits/stdc++.h>
 
#define ll long long
#define pii pair<ll,int>
 
using namespace std;
 
const int mxN = 2e5+5 ; 
const ll INF = 1e9+7 ; 
 
stack<ll> stk ; 
 
ll n , h[mxN] , ansR[mxN] , ansL[mxN] ; 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n ; 
    for(int i=0;i<n;i++){
        cin >> h[i] ; 
        ansR[i] = -INF ; 
        ansL[i] = -INF ; 
    }
    
    stack<pii> stk ; // <val , pos>
    for(int i=0;i<n;i++){
        while(!stk.empty() && h[i]<stk.top().first){
            ansR[stk.top().second] = i-1 ; 
            stk.pop();
        }
        stk.push({h[i],i});
    }
    while(!stk.empty())stk.pop();
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && h[i]<stk.top().first){
            ansL[stk.top().second] = i+1 ; 
            stk.pop();
        }
        stk.push({h[i],i});
    }
 
    ll ans = -INF ; 
    for(int i=0;i<n;i++){
        //if that position doesn't have lesser element
        if(ansR[i]==-INF)ansR[i] = n-1 ; 
        if(ansL[i]==-INF)ansL[i] = 0 ;
        
        ans = max((ansR[i]-ansL[i]+1)*h[i],ans);
    }
    cout << ans ; 
    
}