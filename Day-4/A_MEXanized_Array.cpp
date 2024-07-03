#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long int
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


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; cin>>t; 

    while(t--){
        int n, k, x; 
        cin>>n>>k>>x; 

        vi v; 

        if(k > x and abs(x-k) > 1 || n < k){
            cout << - 1 << endl; 
            continue;
        }
       
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i == k){
                break;
            }
            v.pub(i);
            cnt++;
        }

        if(x == k){
            for(int i = 0; i < n - cnt; i++){
                v.pub(x-1);
            }
        }
        else{
            for(int i = 0; i < n - cnt; i++){
                v.pub(x);
            }
        }

        int sum = 0;

        for(int i = 0; i < n; i++){
            sum +=v[i];
        }

        cout << sum << endl; 
        // range(v);

    }
    return 0; 
}