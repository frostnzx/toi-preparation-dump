#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5 ; 

int n , arr[maxN] ; 
multiset<int> tw ; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ; 
    for(int i=0;i<n;i++){
        cin >> arr[i] ; 
    }
    for(int i=0;i<n;i++){
        auto idx = upper_bound(tw.begin(),tw.end(),arr[i]);
        if(idx!=tw.end()){
            tw.erase(idx);
        }
        tw.insert(arr[i]);
    }
    cout << tw.size() ;
}