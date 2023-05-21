#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int maxN = 2e5+5 ; 

ll n , arr[maxN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ; 

    for(int i=0;i<n;i++){
        cin >> arr[i] ; 
    }
    sort(arr,arr+n);

    ll sum = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i] <= sum+1){
            sum+=arr[i];
        }
        else{
            break;
        }
    }
    cout << sum+1 ;
}