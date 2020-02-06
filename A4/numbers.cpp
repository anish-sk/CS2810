#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
vector<bool> prime((int)(1e7),true) ;
void SieveOfEratosthenes(int n=1e7) 
{    
    for (int p=2; p*p<=n; p++) 
    {        
        if (prime[p] == true) 
        {             
            for (int i=p*2; i<n; i += p) 
                prime[i] = false; 
        } 
    }   
    
} 
class Complex{
public:
    double a,b;
    Complex(){}
    Complex(double a, double b): a(a), b(b){}
    void add(Complex c){
        a+=c.a;
        b+=c.b;
    }
    void sub(Complex c){
        a-=c.a;
        b-=c.b;
    }
    void mult(Complex c){
        double d = a,e = b;
        a = d*(c.a) - e*(c.b);
        b = d*(c.b) + e*(c.a);
    }
    void print(){
        cout<<a<<" "<<b<<"\n";
    }
};

class Rational: public Complex{
public:
    double p,q;
    Rational(int a, int b){
        p=a;q=b;        
    }
    void add(Rational c){
        p=p/q + (c.p)/(c.q);
        q=1;
    }
    void sub(Rational c){
        p=p/q - (c.p)/(c.q);
        q=1;
    }
    void mult(Rational c){
        p*=c.p;
        q*=c.q;
    }
    void reduce(){
        int g = __gcd((int)abs(p),(int)abs(q));
        p/=g;
        q/=g;
        if(p*q < 0){
            cout<<"-"<<(int)abs(p)<<" "<<(int)abs(q)<<"\n";
        }else{
        cout<<(int)abs(p)<<" "<<(int)abs(q)<<"\n";
        }
    }
    void print(){
        cout<<p/q<<"\n";
    }
};
class Natural{
    ll a;
public:
    Natural(ll a): a(a){

    }
    ll power(ll x, ll y, ll m = 1e9+7) { 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
    } 
    bool isprime(){
        //return prime[a]; 
        ll j = sqrt(a);
        for(ll i=2;i<=j;i++){
            if(a%i == 0) return false;
        }
        return true;
    }
    void inverse(long p=1e9+7){
        cout << (power(a,p-2,p))%p<<"\n";
    }
    void print(){
        cout<<a<<"\n";
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::cout.precision(3); std::cout << std::fixed;
    //SieveOfEratosthenes();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime[1]=false;
    int n;cin>>n;
    while(n--){
        string type,operation;
        cin>>type>>operation;
        if(type=="complex"){
            if(operation=="add"){
                double a1,b1;cin>>a1>>b1;
                Complex a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Complex b(a2,b2);
                a.add(b);
                a.print();
            }
            else if(operation=="sub"){
                double a1,b1;cin>>a1>>b1;
                Complex a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Complex b(a2,b2);
                a.sub(b);
                a.print();
            } 
            else if(operation=="mult"){
                double a1,b1;cin>>a1>>b1;
                Complex a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Complex b(a2,b2);
                a.mult(b);
                a.print();
            }
        }
        else if(type=="rational"){
            if(operation=="add"){
                double a1,b1;cin>>a1>>b1;
                Rational a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Rational b(a2,b2);
                a.add(b);
                a.print();
            }
            else if(operation=="sub"){
                double a1,b1;cin>>a1>>b1;
                Rational a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Rational b(a2,b2);
                a.sub(b);
                a.print();
            } 
            else if(operation=="mult"){
                double a1,b1;cin>>a1>>b1;
                Rational a(a1,b1);
                double a2,b2;cin>>a2>>b2;
                Rational b(a2,b2);
                a.mult(b);
                a.print();
            }
            else if(operation=="reduce"){
                double a1,b1;cin>>a1>>b1;
                Rational a(a1,b1);
                a.reduce();
            }
        }
        else if(type=="natural"){
            if(operation=="isprime"){
                ll a;cin>>a;
                Natural b(a);
                if(b.isprime()){
                    cout<<"1\n";
                }
                else{
                    cout<<"0\n";
                }
                    
            }
            else{
                ll a;cin>>a;
                Natural b(a);
                b.inverse();
            }
        }
        
    }
    
    return 0;
}