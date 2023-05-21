#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5 ; 

int n ;
unordered_map<int,int> mp ; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ; 

    int a ; 
    for(int i=0;i<n;i++){
        cin >> a ; 
        mp[a] = i ; 
    }

    int rd = 1 ; 
    for(int i=1;i<n;i++){
        if(mp[i+1]<mp[i]){
            rd++;
        }
    }

    cout << rd ;

}