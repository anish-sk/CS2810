#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
class Disjoint_Set {
    private:
        vector<int> P;
        vector<int> rank;
    public:
        Disjoint_Set(int n){
            P.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; i++) {
                P[i] = i;
            }
        }
        
        void merge(int node_x, int node_y){
            int rep_x = find(node_x);
            int rep_y = find(node_y);
            if (rank[rep_x] > rank[rep_y]) {
                P[rep_y] = rep_x;
            } else {
                P[rep_x] = rep_y;
                if (rank[rep_x] == rank[rep_y]){
                    rank[rep_y]++;
                }
            }
        }
        
        int find(int node){
            while (node != P[node]) {
                node = P[node];
            }
            return node;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> type0,type1;
    int city1,city2,roadtype;
    Disjoint_Set Forest(n);
    for(int i=0;i<m;i++){
        cin>>city1>>city2>>roadtype;
        if(roadtype == 2){
            int c1 = Forest.find(city1);
            int c2 = Forest.find(city2);
            if(c1!=c2){
                Forest.merge(c1,c2);
            }
        }
        else if(roadtype == 1){
            type1.push_back({city1,city2});
        }
        else{
            type0.push_back({city1,city2});
        }
    }
    unordered_set<int> components;
    unordered_map<int, vector<int>> members;
    for(int i=0;i<n;i++){
        components.insert(Forest.find(i));
        members[Forest.find(i)].push_back(i);
    }
    int number_of_components = components.size();
    unordered_map<int,int> comps;
    int j=0;
    for(auto i: components){
        comps[i]=j;
        j++;
    }
    //vector<vector<int>> v0(number_of_components,vector<int>()),v1(number_of_components,vector<int>());
    Disjoint_Set v0(number_of_components),v1(number_of_components);
    for(auto i: type0){
        v0.merge(comps[Forest.find(i.first)],comps[Forest.find(i.second)]);
    }
    for(auto i: type1){
        v1.merge(comps[Forest.find(i.first)],comps[Forest.find(i.second)]);
    }
    unordered_set<int> c0,c1;
    for(int i=0;i<number_of_components;i++){
        c0.insert(v0.find(i));
        c1.insert(v1.find(i));
    }
    int size0 = c0.size();
    int size1 = c1.size();
    if(size0 > 1  || size1 > 1){
        cout<<"-1\n";
    }
    else{
        int required = 0;
        for(auto i: members){
            required += i.second.size()-1;
        }
        cout<<m-required-2*(number_of_components-1)<<"\n";
    }
    return 0;
}

