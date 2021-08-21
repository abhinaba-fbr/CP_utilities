#include<iostream>
#include "BigInteger/BigInteger.hpp"
using namespace std;

int main(){
    BigInteger sum;
    sum.initialize(1);
    cout<<sum<<endl;
    for(int i=0;i<3;i++){
        BigInteger b;
        cin>>b;
        cout<<b<<endl;
        sum=sum*b;
    }
    BigInteger b2;
    b2.initialize(11);
    cout<<int(sum%b2)<<endl;
    BigInteger b10=-5;
    BigInteger b20=-5;
    cout<<"Checking == "<<(b10==b20)<<endl;
    cout<<"Checking >  "<<(b10>b20)<<endl;
    cout<<"Checking <  "<<(b10<b20)<<endl;
    cout<<"Checking <= "<<(b10<=b20)<<endl;
    cout<<"Checking >= "<<(b10>=b20)<<endl;
    b20=b20*BigInteger(-1);
    cout<<b20<<endl;
    return 0;
}