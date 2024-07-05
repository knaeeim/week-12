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

        vi x(n), p(n);

        for(int i = 0; i < n; i++) cin>>x[i]; 
        for(int i = 0; i < n; i++) cin>>p[i];

        // one left and one right 
        int left =  0, right = n - 1;

        for(int i = 1; i < n; i++){
            int diff = x[i] - x[i-1];
            if(diff > p[i-1]) break;
            else left = i;
        }


        for(int i = n - 2; i >= 0; i--){
            int diff = x[i+1] - x[i];
            if(diff > p[i+1]) break;
            else right = i;
        }

        cout << "Left from 1st Part" << left << " " << right << endl; 

        if((right - left) <= 1) {
            yes;
            continue;
        }


        // one left and one right again but this time we will check only the current ball's power that it can reach to the previous ball or not 
        left = 0;
        right = n - 1;

        for(int i = 1; i < n; i++ ){
            int diff = x[i] - x[i-1];
            if(diff > p[i]) break;
            else left = i;
        }

        for(int i = n - 2; i >= 0; i--){
            int diff = x[i+1] - x[i]; 
            if(diff > p[i]) break;
            else right = i;
        }

        cout << "Left from 2nd Part" << left << " " << right << endl; 

        if((right - left) <= 1){
            yes;
            continue;
        }

        //only right
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            int diff = x[i+1] - x[i];
            if(diff > p[i]) cnt++;
        }

        cout << cnt << endl;

        if(cnt <= 1){
            yes;
            continue;
        }

        //only left

        cnt = 0;

        for(int i = n - 1; i > 0; i--){
            int diff = x[i] - x[i-1];
            if(diff > p[i]) cnt++;
        }

        cout << cnt << endl; 

        if(cnt <= 1){
            yes;
            continue;
        }

        no;
    }
    return 0; 
}