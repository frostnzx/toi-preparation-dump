#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+5 ; 
int n,q ; 
int arr[N] , ans = 1; 
unordered_map<int,int> mp ; 


void solve(int a,int b){
    set<pair<int,int>> update ; 

    if(arr[a]-1 >= 1)
        update.insert({arr[a]-1 , arr[a]});
    if(arr[a]+1 <= n)
        update.insert({arr[a] , arr[a]+1});
    if(arr[b]-1 >= 1)
        update.insert({arr[b]-1 , arr[b]});
    if(arr[b]+1 <= n)
        update.insert({arr[b] , arr[b]+1});

    for(auto i : update)
        if(mp[i.first] > mp[i.second])
            ans--;


    swap(arr[a],arr[b]);
    mp[arr[a]] = a ; 
    mp[arr[b]] = b ; 

    if(arr[a]-1 >= 1)
        update.insert({arr[a]-1 , arr[a]});
    if(arr[a]+1 <= n)
        update.insert({arr[a] , arr[a]+1});
    if(arr[b]-1 >= 1)
        update.insert({arr[b]-1 , arr[b]});
    if(arr[b]+1 <= n)
        update.insert({arr[b] , arr[b]+1});

    for(auto i : update)
        if(mp[i.first] > mp[i.second])
            ans++;

    cout << ans << "\n" ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q ;

    for(int i=1;i<=n;i++)
        cin >> arr[i] , mp[arr[i]] = i ; 
    
    for(int i=1;i<n;i++)
        if(mp[i] > mp[i+1])
            ans++;

    while(q--){
        int a,b ; 
        cin >> a >> b ;
        solve(a,b);
    }
}