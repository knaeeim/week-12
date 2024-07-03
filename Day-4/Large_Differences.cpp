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

int CalculateTheDiffertentSum(vector <int> &v){
    int sum = 0; 
    for(int i = 0; i < v.size() - 1; i++){
        sum += abs(v[i] - v[i+1]);
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    int t; cin>>t;

    while(t--){
        int n, k; cin>>n>>k; 

        vi v(n); 
     
        for(int i = 0; i < n; i++){
            cin>>v[i]; 
        }

        int initial_sum = CalculateTheDiffertentSum(v);

        for(int i = 0; i < n; i++){
            int original = v[i]; 

            v[i] = 1; 
            initial_sum = max(initial_sum, CalculateTheDiffertentSum(v));
            v[i] = k;
            initial_sum = max(initial_sum, CalculateTheDiffertentSum(v));

            v[i] = original;
        }

        cout << initial_sum << endl; 

    } 
    return 0; 
}