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
        int n;
        cin>>n; 

        vi v(n),vPrime(n); 

        for(int i = 0; i < n; i++) cin>>v[i]; 
        for(int i = 0; i < n; i++) cin>>vPrime[i];

        int firstIndx = 0, SecondIndex = n - 1;

        while(v[firstIndx] == vPrime[firstIndx]){
            firstIndx++;
        }

        while(v[SecondIndex] == vPrime[SecondIndex]){
            SecondIndex--;
        }

        while(firstIndx > 0 and vPrime[firstIndx] >= vPrime[firstIndx - 1]){
            firstIndx--;
        }

        while(SecondIndex < n - 1 and vPrime[SecondIndex] <= vPrime[SecondIndex + 1]){
            SecondIndex++;
        }

        cout<< firstIndx + 1 << " " << SecondIndex + 1 << endl; 

    }
    return 0; 
}