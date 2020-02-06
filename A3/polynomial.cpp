#include <bits/stdc++.h>
using namespace std;
const int maximum_degree = 22;
class polynomial{    
public:
    vector<double> coefficents;
    polynomial(){
        coefficents = vector<double>(maximum_degree,0);
    }
    polynomial(int n){
        coefficents = vector<double>(maximum_degree,0);
        for(int i=0;i<n;i++){
            int x;double y;
            cin>>x>>y;
            //cout<<x<<" "<<y<<"\n";            
            coefficents[x]=y;
            //cout<<flush;
        }
    }
    void operator+(polynomial b){
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]+=b.coefficents[i];
        }
        print();        
    }
    void operator-(polynomial b){
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]-=b.coefficents[i];
        }
        print();        
    }
    void operator*(polynomial b){
        polynomial p;
        for(int i=0;i<maximum_degree;i++){
            for(int j=0;j<=i;j++){
                p.coefficents[i]+=coefficents[j]*b.coefficents[i-j];
            }
        }
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]=p.coefficents[i];
        }        
        print();
    }    
    double evaluate(double x){
        double ans = 0;
        for(int i=maximum_degree-1;i>=0;i--){
            ans = ans*x + coefficents[i];
        }
        return ans;
    }
    void print(){
        int f =1;
        for(int i=0;i<maximum_degree;i++){
            if(coefficents[i]!=0){
                if(f==1){
                    cout<<coefficents[i]<<"x^"<<i<<" ";
                    f=0;
                }
                else{
                    if(coefficents[i]>0){
                        cout<<"+ ";
                    }
                    else{
                        cout<<"- ";
                    }
                    cout<<abs(coefficents[i])<<"x^"<<i<<" ";                    
                }
            }
        }
        cout<<"\n";
    }    
};
int main(){
    cout.precision(3);
    cout<<std::fixed;
    int n;
    cin>>n;
    while(n--){
        char op;
        cin>>op;
        if(op=='a'){
            int a,b;
            cin>>a;
            polynomial p1 = polynomial(a);
            cin>>b;
            polynomial p2 = polynomial(b);
            p1+p2;            
        }
        else if(op=='s'){
            int a,b;
            cin>>a;
            polynomial p1 = polynomial(a);
            cin>>b;
            polynomial p2 = polynomial(b);
            p1-p2;            
        }
        else if(op=='m'){
            int a,b;
            cin>>a;
            polynomial p1 = polynomial(a);
            cin>>b;
            polynomial p2 = polynomial(b);
            p1*p2;
        }
        else if(op=='e'){
            double a;
            cin>>a;
            polynomial p1 = polynomial(a);
            cin>>a;
            //p1.print();
            cout<<p1.evaluate(a)<<"\n";                        
        }
    }
    return 0;
}