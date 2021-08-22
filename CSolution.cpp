#include<iostream>
#include<vector>
#include "BigInteger/BigInteger.hpp"
#include "Heap/MinHeap.hpp"
#include "Heap/MaxHeap.hpp"
using namespace std;

int main(){
    // BigInteger sum;
    // sum.initialize(1);
    // cout<<sum<<endl;
    // for(int i=0;i<3;i++){
    //     BigInteger b;
    //     cin>>b;
    //     cout<<b<<endl;
    //     sum=sum*b;
    // }
    // BigInteger b2;
    // b2.initialize(11);
    // cout<<int(sum%b2)<<endl;
    // BigInteger b10=-5;
    // BigInteger b20=-5;
    // cout<<"Checking == "<<(b10==b20)<<endl;
    // cout<<"Checking >  "<<(b10>b20)<<endl;
    // cout<<"Checking <  "<<(b10<b20)<<endl;
    // cout<<"Checking <= "<<(b10<=b20)<<endl;
    // cout<<"Checking >= "<<(b10>=b20)<<endl;
    // b20=b20*BigInteger(-1);
    // cout<<b20<<endl;
    // return 0;
    vector<int> v={12,45,3,7,90,1,0,55};
    MaxHeap mh(v);
    for(int i=0;i<mh.size;i++)
        cout<<mh.heap[i]<<" ";
    cout<<endl;
    mh.insert(8);
    for(int i=0;i<mh.size;i++)
        cout<<mh.heap[i]<<" ";
    cout<<endl;
    cout<<"Maximum element -"<<mh.extractMax()<<endl;
    for(int i=0;i<mh.size;i++)
        cout<<mh.heap[i]<<" ";
    cout<<endl;
    return 0;
}