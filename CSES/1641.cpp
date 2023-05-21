#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ; 

const int N = 5005 ; 

int n , x ; 
vector<pii> a ; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x ;
    if(n < 3){
        cout << "IMPOSSIBLE" ; 
        return 0 ; 
    }
    for(int i=1,b;i<=n;i++)
        cin >> b , a.push_back({b , i});
    sort(a.begin() , a.end());

    for(auto i : a){ // set first pointer
        int first_pos = i.second , l=0 , r=n-1 , val = x - i.first ; 
        // find others two using two pointer
        while(l < r){
            if(a[l].second == first_pos)
                l++;
            if(a[r].second == first_pos)
                r--;
            if(a[l].first + a[r].first < val)
                l++;
            else if(a[l].first + a[r].first > val)
                r--;
            else {
                cout << a[l].second << " " << a[r].second << " " << first_pos ;
                return 0 ; 
            }
        }
    }
    cout << "IMPOSSIBLE" ; 
}

// this method of fixing 1 position and other two use pointer take O(N^2)
// better than naive approach which take O(N^3) due to each loop represent each pointer