#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

// ******************************************String helper functions***********************************
bool equalTo(string num1,string num2){
    if(num1==num2)
        return true;
    else
        return false;
}

bool greaterThan(string num1,string num2){
    int l1=num1.length();
    int l2=num2.length();
    if(l1>l2){
        return true;
    }
    else{
        if(l1==l2){
            if(num1>num2)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}

string trimLeft(string s){
    int l=s.length(),i;
    for(i=0;i<l-1;i++){
        if(s[i]!='0')
            break;
    }
    s=s.substr(i,s.length()-i);
    return s;
}

string add(string num1,string num2){
    string tmpnum1=num1;
    string tmpnum2=num2;
    int l1=tmpnum1.length();
    int l2=tmpnum2.length();
    string ans="";
    int carry=0;
    reverse(tmpnum1.begin(),tmpnum1.end());
    reverse(tmpnum2.begin(),tmpnum2.end());
    for(int i=0;i<max(l1,l2);i++){
        int d1=0,d2=0;
        if(i<l1)
            d1=ctoi(tmpnum1[i]);
        if(i<l2)
            d2=ctoi(tmpnum2[i]);
        int sum=d1+d2+carry;
        ans+=itoc(sum%10);
        carry=sum/10;
    }
    if(carry!=0)
        ans+=itoc(carry);
    reverse(ans.begin(),ans.end());
    return ans;
}

string substract(string num1,string num2){
    string tmpnum1=num1;
    string tmpnum2=num2;
    int l1=tmpnum1.length();
    int l2=tmpnum2.length();
    int borrow=0;
    string ans="";
    reverse(tmpnum1.begin(),tmpnum1.end());
    reverse(tmpnum2.begin(),tmpnum2.end());
    for(int i=0;i<max(l1,l2);i++){
        int d1=0,d2=0;
        int sub=0;
        if(i<l1)
            d1=ctoi(tmpnum1[i]);
        if(i<l2)
            d2=ctoi(tmpnum2[i]);
        if(d1<d2){
            sub=10+d1-d2-borrow;
            borrow=1;
        }
        else if(d1==d2 && borrow==1){
            sub=10+d1-d2-borrow;
            borrow=1;
        }
        else{
            sub=d1-d2-borrow;
            borrow=0;
        }
        ans+=itoc(sub);
    }
    int i=ans.length()-1;
    for(;i>0;i--){
        if(ans[i]!='0')
            break;
    }
    ans=ans.substr(0,i+1);
    reverse(ans.begin(),ans.end());
    return ans;
}

string multiply(string num1,string num2){
    int l1=num1.length();
    int l2=num2.length();
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    vector<string> temporaries;
    string counter="";
    for(int i=0;i<l1;i++){
        int d1=ctoi(num1[i]);
        string tmp="";
        int carry=0;
        for(int j=0;j<l2;j++){
            int d2=ctoi(num2[j]);
            int mul=d1*d2+carry;
            tmp=itoc(mul%10)+tmp;
            carry=mul/10;
        }
        if(carry!=0)
            tmp=itoc(carry)+tmp;
        tmp+=counter;
        temporaries.push_back(tmp);
        counter+='0';
    }
    string ans="0";
    int tl=temporaries.size();
    for(int i=0;i<tl;i++){
        ans=add(ans,temporaries[i]);
    }
    return ans;
}

string divide(string num1,string num2){
    if(trimLeft(num2)=="0")
        cout<<"fatal!!! divide by zero error(Ctrl+C to terminate)"<<endl;
    int l1=num1.length();
    int l2=num2.length();
    string divisor=num2;
    string divident=num1.substr(0,l2);
    string quotient="";
    string reminder="0";
    int pointer=l2;
    while(pointer<l1){
        if(greaterThan(divisor,divident)){
            quotient+='0';
            divident+=num1[pointer];
            pointer++;
            continue;
        }
        int factor=0;
        while(greaterThan(divident,divisor) || equalTo(divident,divisor)){
            factor++;
            divident=substract(divident,divisor);
        }
        quotient+=itoc(factor);
        reminder=divident;
        divident=reminder+num1[pointer];
        divident=trimLeft(divident);
        pointer++;
    }
    int factor=0;
    while(greaterThan(divident,divisor) || equalTo(divident,divisor)){
        factor++;
        divident=substract(divident,divisor);
    }
    quotient+=itoc(factor);
    reminder=divident;
    quotient=trimLeft(quotient);
    return quotient;
}

string mod(string num1, string num2){
    if(trimLeft(num2)=="0")
        cout<<"fatal!!! divide by zero error(Ctrl+C to terminate)"<<endl;
    int l1=num1.length();
    int l2=num2.length();
    string divisor=num2;
    string divident=num1.substr(0,l2);
    string quotient="";
    string reminder="0";
    int pointer=l2;
    while(pointer<l1){
        if(greaterThan(divisor,divident)){
            quotient+='0';
            divident+=num1[pointer];
            pointer++;
            continue;
        }
        int factor=0;
        while(greaterThan(divident,divisor) || equalTo(divident,divisor)){
            factor++;
            divident=substract(divident,divisor);
        }
        quotient+=itoc(factor);
        reminder=divident;
        divident=reminder+num1[pointer];
        divident=trimLeft(divident);
        pointer++;
    }
    int factor=0;
    while(greaterThan(divident,divisor) || equalTo(divident,divisor)){
        factor++;
        divident=substract(divident,divisor);
    }
    quotient+=itoc(factor);
    reminder=divident;
    quotient=trimLeft(quotient);
    return reminder;
}