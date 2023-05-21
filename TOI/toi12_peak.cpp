#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 5e6+5 ;

int n , k , arr[N] ;

vector<int> vec , ans ;
unordered_map<int , bool> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;
    for(int i=1;i<=n;i++){
        cin >> arr[i] ;
    }

    for(int i=1;i<=n;i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            vec.emplace_back(arr[i]);
        }
    }
    if(vec.empty()){
        cout << "-1" ;
        return 0 ;
    }

    sort(vec.begin() , vec.end() , greater<int>()) ;
    vec.resize(unique(vec.begin() , vec.end()) - vec.begin()) ; // ***


    for(int i=0;i<k && i<vec.size();i++){
        ans.emplace_back(vec[i]);
    }

    if(ans.size() < k){
        reverse(ans.begin() , ans.end());
    }

    for(int x : ans){
        cout << x << "\n" ;
    }
}

//keypoint : unordered_map is slower than using resize + unique
