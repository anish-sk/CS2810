#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int M,N;
class Coordinator{
    public:
    int age;
    char gender;
    string mother_tongue;
    int cgpa;
    int id;
    Coordinator(int age, char gender, string &lang, int cgpa, int id){
        this->age = age;
        this->gender = gender;
        this->mother_tongue = lang;
        this->cgpa=cgpa;
        this->id=id;
    }
    Coordinator(){}
};
bool compare(Coordinator &a, Coordinator &b){
    return !((abs(a.age-b.age)<=2)&&(a.gender!=b.gender)&&(a.cgpa!=b.cgpa)&&(a.mother_tongue==b.mother_tongue));    
}
#define NIL 0 
#define INF INT_MAX 
  
class Max_Bipartite_Match {
    vector<vector<int> > &G;
    public:

    vector<int> match, mark;
    int max_match, stamp;

    Max_Bipartite_Match(vector<vector<int> > &bipartite_graph, int v): G(bipartite_graph){
        match.resize(v);
        mark.resize(v);
        for (int i = 0; i < v; i++) {
            match[i] = -1;
            mark[i] = -1;
        }
        stamp = 0;
    }

    bool augment_path(int vertex){
        for (int i = 0; i < G[vertex].size(); i++) {
            int v = G[vertex][i];
            if (mark[v] == stamp)
                continue;
            mark[v] = stamp;
            if (match[v] == -1 || augment_path(match[v])) {
                match[v] = vertex;
                return true;
            }
        }
        return false;
    }

    int max_matching(){
        max_match = 0;
        for (int i = 0; i < G.size(); i++) {
            stamp++;
            if (augment_path(i)) max_match++;
        }
        return max_match;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;cin>>t;while(t--){
        int n1;cin>>n1;int i=0;vector<Coordinator> coords;vector<Coordinator>males,females;
        while(i<n1){
            Coordinator c;
            cin>>c.age>>c.gender>>c.mother_tongue>>c.cgpa;c.id=i;coords.push_back(c);
            if(c.gender=='M') males.push_back(c);
            else females.push_back(c);
            i++;
        }
       
        M = males.size();N=females.size();
         vector<vector<int>> adj(M,vector<int>());
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(!compare(males[i],females[j])){
                   adj[i].push_back(j);
                }
            }
        }
        Max_Bipartite_Match g(adj,N);
        cout<<n1-g.max_matching()<<"\n";
        
    }
    return 0;
}

