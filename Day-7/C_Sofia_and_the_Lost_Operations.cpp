#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define int long long
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define sorta(arr) sort(arr.begin(), arr.end());
#define sortd(arr) sort(arr.begin(), arr.end(), greater<int>());
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique((X).begin(),(X).end()),(X).end())
#define range(arr) for(auto el: arr) cout<<el<<" ";


int32_t main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; cin>>t; 

    while(t--){
        int n; cin>>n; 

        vi a(n), b(n); 

        multiset<int> ml; 

        for(int i = 0; i < n; i++) cin>>a[i]; 

        for(int i = 0; i < n; i++){
            cin>>b[i]; 
            if(a[i] != b[i]) ml.insert(b[i]); 
        }

        int m; cin>>m; 

        vi operation(m); 
        bool found = false;

        for(int i = 0; i < m; i++) cin>>operation[i];

        for(int i = 0; i < n; i++){
            if(b[i] == operation[m-1]){
                found = true;
            }
        }

        if(found == false){
            no; 
            continue;
        }

        for(int i = m - 1; i >= 0; i--){
            int x = operation[i]; 
            if(ml.find(x) != ml.end()){
                ml.erase(ml.find(x));
            }
        }

        if(!ml.empty()) no; 
        else yes;
    }
    return 0; 
}