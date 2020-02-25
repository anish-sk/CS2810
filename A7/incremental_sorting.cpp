#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
#define ll long long
using namespace __gnu_pbds;
using namespace std;
class Student{
    public:
    int id,m1,m2,m3,m4,m5;
    ll skill;
    friend bool operator<(const Student& l, const Student& r)
    {
        Student c;
       return c.comp(l,r);
    }
    // bool operator<(Student b){
    //     return compare(*this,b);
    // }
    // bool operator==(Student b){
    //     return (this->id==b.id) ;
    // }
    friend bool operator>(const Student& a, const Student &b){
        return b<a;
     }
    friend bool operator==(const Student& a, const Student &b){
        return a.id==b.id;
    }
//     inline bool operator< (const Student& lhs, const Student& rhs){ /* do actual comparison */ }
// inline bool operator> (const Student& lhs, const Student& rhs){ return rhs < lhs; }
// inline bool operator<=(const Student& lhs, const Student& rhs){ return !(lhs > rhs); }
// inline bool operator>=(const Student& lhs, const STudent& rhs){ return !(lhs < rhs); }
    bool comp(const Student &a, const Student &b){
        return (a.m1 < b.m1) || ((a.m1==b.m1)&&(a.m2<b.m2)) || ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3<b.m3)) || ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3==b.m3)&&(a.m4<b.m4)) ||  ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3==b.m3)&&(a.m4==b.m4)&&(a.m5<b.m4));    
    }
};
class compare{
    public:
    bool operator()(Student a, Student b){
        return (a.m1 < b.m1) || ((a.m1==b.m1)&&(a.m2<b.m2)) || ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3<b.m3)) || ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3==b.m3)&&(a.m4<b.m4)) ||  ((a.m1==b.m1)&&(a.m2==b.m2)&&(a.m3==b.m3)&&(a.m4==b.m4)&&(a.m5<b.m4));          
    }
};
unordered_map<int, Student> stu;
class compared{
    public:
    bool operator()(int a, int b){
        compare c;
        return c(stu[a],stu[b]);        
    }
};
// class stud{
//     public:
//     int id;ll skill;
//     friend
// }
template <typename T> using ordered_set =  tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using less_ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ordered_set<Student> tr;
    less_ordered_set<ll> co;
    string s;
    while(cin>>s){
        if(s=="ADD"){
            Student st;
            cin>>st.id>>st.m1>>st.m2>>st.m3>>st.m4>>st.m5>>st.skill;
            tr.insert(st);
            stu[st.id]=st;
            co.insert(st.skill);
        }
        else if(s=="PRINT"){
            for(auto i: tr){
                cout<<i.id<<" ";
            }
            cout<<"\n";
        }
        else if(s=="FIND"){
            int c,d;
            cin>>c>>d;
            cout<<abs((ll)(tr.order_of_key(stu[c]) - tr.order_of_key(stu[d])))<<"\n"; 
        }
        else if(s=="COUNT"){
                int id;ll d;
            cin>>id>>d;
            int a = (int)co.order_of_key(stu[id].skill+d);
            int b = (int)co.order_of_key(stu[id].skill-d);
            cout<<co.size()-a+b<<"\n";
        }
    }
    return 0;
}