#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}
void numberOftriplets(int s, int e, vector<ll> &count1, vector<vector<ll>> &adj, ll &c, vector<ll> &d) 
{ 
    ll b = c;
    for (auto u: adj[s]) { 
        if (u == e) 
            {
                c+= (count1[s]-(ll)1)* ((ll)adj.size() - count1[s]);
                continue;
            }
        if(count1[u]!= adj.size())
        c += count1[u]*((ll)adj.size()-count1[u]-(ll)1);
        //cout<<c<<" ";
        numberOftriplets(u, s, count1, adj, c, d); 
    } 
    d[s]=c-b;
} 
void numberOfNodes(int s, int e, vector<ll> &count1, vector<vector<ll>> &adj) 
{ 
    count1[s] = 1; 
    for (auto u: adj[s]) { 
        if (u == e) 
            continue; 
        numberOfNodes(u, s, count1, adj); 
        count1[s] += count1[u]; 
    } 
} 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n,m; cin>>n; vector<vector<ll>> adj(n,vector<ll>());
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> count1(n,0), wt(n,1);
    numberOfNodes(0,0,count1,adj);
    //cout<<count1;
    ll c = 0;
    vector<ll>contri(n,0);
    numberOftriplets(0,0,count1,adj,c,contri);
    cout<<contri;
    cout<<c<<"\n";
    return 0;
}