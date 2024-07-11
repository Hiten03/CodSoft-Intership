#include<bits/stdc++.h>
using namespace std;
int main(){
    char op;
    float num1;
    float num2;
    cout<<"Enter operator: ";
    cin>>op;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    switch(op){

        case '+':
        cout<<num1+num2;
        break;

        case '-':
        cout<<num1-num2;
        break;

        case '*':
        cout<<num1*num2;
        break;

        case '/':
        cout<<num1/num2;
        break;

        default:
        cout<<"Error! Operator is not correct";
    }
    return 0;
}