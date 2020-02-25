#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
bool flag=false;
using namespace std;
class student{
    public:
    string name;
    int rollno;
    int physics, chemistry, maths;double mean;
    student(string name,int rollno, int physics,int chemistry,int maths){
        this->name=name;
        this->rollno=rollno;
        this->physics=physics;
        this->chemistry=chemistry;
        this->maths=maths;
        this->mean=(physics + chemistry + maths)/3.0;
    }
    void print(){
        cout<<name<<" "<<rollno<<" "<<physics<<" "<<chemistry<<" "<<maths<<"\n";
    }
    void printav(){
        cout<<name<<" "<<rollno<<" "<<physics<<" "<<chemistry<<" "<<maths<<" "<<mean<<"\n";
    }
};
class search_roll{
    public:
    int to_be_found;   
    search_roll(int a){
        to_be_found=a;
        flag = false;
    }
    void operator()(student s){
        if(s.rollno == to_be_found){
            s.print();
            flag=true;
        }
    }
    
};
class search_name{
    public:
    string to_be_found;    
    
    search_name(string a){
        to_be_found=a;
        flag = false;
    }
    void operator()(student s){
        if(s.name == to_be_found){
            s.print();
            flag=true;
        }
    }
    
};
class find_average{
    public:
    void operator()(student s){
        s.mean = (s.physics + s.chemistry + s.maths)/3.0;
    }    
};
class sort_name{
    public:
    bool operator()(student a, student b){
        return a.rollno< b.rollno;
    }
};

class sort_average{
    public:
    bool operator()(student a, student b){
        return (a.mean > b.mean) || (a.mean==b.mean)&&(a.rollno < b.rollno);
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin>>n;
    string name;int p,c,m; int rollno;
    vector<student> studs;
    while(n--){
        cin>>name>>rollno>>p>>c>>m;
        studs.push_back(student(name,rollno,p,c,m));
    }
    int op;cin>>op;
        if(op==1){
            int r;cin>>r;
            search_roll roll(r);
            for_each(studs.begin(),studs.end(),roll);
            if(!flag){
                cout<<"Invalid Entry\n";
            }
        }
       else if(op==2){
           string input;cin>>input;
           search_name nam(input);
           sort(studs.begin(),studs.end(),sort_name());
           for_each(studs.begin(),studs.end(),nam);
           if(!(flag)){
                cout<<"Invalid Entry\n";
            }
       }
    else{cout.precision(4);cout<<fixed;
        //for_each(studs.begin(),studs.end(),find_average());
        sort(studs.begin(),studs.end(),sort_average());
        for(auto i: studs){
            i.printav();
        }
        
    }
        
    
    return 0;
}
