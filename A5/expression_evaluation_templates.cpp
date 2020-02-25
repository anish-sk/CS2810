#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#define ll long long
const int maximum_degree = 3002;
using namespace std;
template<class T>
class Stack{
public:
    vector<T> st;
    Stack(){
        st=vector<T>();
    }
    void pop();// pops the element on top of the stack
    void push(T val);// inserts an element on the top of the stack
    T top();// returns the element present on the top of the stack
    int size();// returns the size of the stack
    bool empty();//tells whether the stack is empty or not
};
template<class T>
void Stack<T>::pop(){
    st.pop_back();
}
template<class T>
void Stack<T>::push(T val){
    st.push_back(val);
}
template<class T>
T Stack<T>::top(){
 return st.back();   
}
template<class T>
int Stack<T>::size(){
    return st.size();
}
template<class T>
bool Stack<T>::empty(){
    return st.size()==0 ;
}
class polynomial{    
public:
    vector<ll> coefficents;
    polynomial(){
        coefficents = vector<ll>(maximum_degree,0);
    }
    polynomial(int n){
        coefficents = vector<ll>(maximum_degree,0);
        for(int i=0;i<n;i++){
            int x;int y;
            cin>>x>>y;
            //cout<<x<<" "<<y<<"\n";            
            coefficents[x]=y;
            //cout<<flush;
        }
    }
    polynomial operator+(polynomial b){
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]+=b.coefficents[i];
        }
        //print();
        return *this;
    }
    polynomial operator-(polynomial b){
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]-=b.coefficents[i];
        }
        //print();
        return *this;
    }
    polynomial operator*(polynomial b){
        polynomial p;
        for(int i=0;i<maximum_degree;i++){
            for(int j=0;j<=i;j++){
                p.coefficents[i]+=coefficents[j]*b.coefficents[i-j];
            }
        }
        for(int i=0;i<maximum_degree;i++){
            coefficents[i]=p.coefficents[i];
        }        
        //print();
        return *this;
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
int precedence(string s){
    if(s=="*") return 3;
    else if(s=="+" || s=="-") return 2;
    else return 1;
}
template<class T>
void process(Stack<T> &operand, Stack<string> &op){
    T a = operand.top();
    operand.pop();
    T b = operand.top();
    operand.pop();
    string o = op.top();
    op.pop();
    if(o=="+"){
        operand.push(a+b);
    }
    else if(o=="-"){
        operand.push(b-a);
    }
    else if(o=="*"){
        operand.push(a*b);
    }  
    //cout<<operand.top()<<" ";cout<<flush;
}
void takeIntInput() {

    string line, token;
    cin.ignore();
    getline(cin, line);
    //cout<<line;cout<<flush;
    stringstream ss(line);
    
    Stack<ll> operand;
    Stack<string> op;
    while(ss >> token) {
        //cout<<token<<" ";cout<<flush;
        // process each token
        // this will either be an operator, a parenthesis or an integer
        if(token=="+" || token=="-" || token=="*"){
            if(op.empty()){
                op.push(token);
            }
            else{
                if(precedence(token)>precedence(op.top())){
                    op.push(token);
                }
                else{
                    while(op.size() && operand.size() && (precedence(token)<=precedence(op.top()))){
                        process(operand,op);//out<<"hi ";
                    }
                    op.push(token);
                }
            }
        }
        else if(token=="("){
            op.push(token);        
        }
        else if(token==")"){
            while(op.top()!="("){
               process(operand,op); //cout<<"hi ";cout<<flush;
            }
            op.pop();
        }
        else{
            operand.push(stoll(token));
        }          
        
    }
    while(op.size()){
        process(operand,op);
    }
    cout<<operand.top()<<"\n";
    
}

void takePolyInput() {
    int num;
    std::cin >> num;

    std::string line;

    std::cin.ignore();
    
    Stack<polynomial> operand;
    Stack<string> op;
    for(int i = 0; i < num; i++) {
        std::getline(std::cin, line);

        if(line.size() == 1) {
            string token = line;
            // process the line
            // this will be either an operator or a parenthesis
             if(token=="+" || token=="-" || token=="*"){
            if(op.empty()){
                op.push(token);
            }
            else{
                if(precedence(token)>precedence(op.top())){
                    op.push(token);
                }
                else{
                    while(op.size() && operand.size() && (precedence(token)<=precedence(op.top()))){
                        process(operand,op);
                    }
                    op.push(token);
                }
            }
        }
        else if(token=="("){
            op.push(token);        
        }
        else if(token==")"){
            while(op.top()!="("){
               process(operand,op); 
            }
            op.pop();
        }
            
        }
        else {
            // this will be a polynomial
            std::stringstream ss(line);

            int exponent;
            long long coeff;
            polynomial p;
            while(ss >> exponent, ss >> coeff) {
                // process the exponent and coefficient appropriately                
                p.coefficents[exponent]=coeff;                                
            }
            operand.push(p);        
            

        }
    }
     while(op.size()){
        process(operand,op);
    }
    (operand.top()).print();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="int"){
            takeIntInput();
        }
        else{
            takePolyInput();
        }
    }
    return 0;
}