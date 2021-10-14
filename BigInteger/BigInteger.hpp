#include<iostream>
#include<stdlib.h>
#include "CSIConversions.hpp"
#include "stringArithmetics.hpp"
#define MAX_BIGLENGTH 100
using namespace std;


// ********************************Class BigInteger****************************************
class BigInteger{
    private:
        // Private data members
        string number;
        string magnitude;
        char sign;
        void checkInitialized(void)const;
        void checkLength(string)const;
    public:
        // Fiend functions to carry out string atithmetic operations
        friend string trimLeft(string);
        friend string add(string,string);
        friend string substract(string,string);
        friend string multiply(string,string);
        friend string divide(string,string);
        friend string mod(string,string);
        friend bool greaterThan(string,string);
        // Constructors
        BigInteger(void);
        BigInteger(string s);
        BigInteger(int n);
        BigInteger(const BigInteger&);
        // Initializing member functions
        void initialize(int);
        void initialize(string);
        // Relational operator overloaded member functions
        bool operator==(BigInteger);
        bool operator>(BigInteger);
        bool operator<(BigInteger);
        bool operator>=(BigInteger);
        bool operator<=(BigInteger);
        // Arithmetic operation overloaded member functions
        BigInteger operator+(BigInteger);
        BigInteger operator-(BigInteger);
        BigInteger operator*(BigInteger);
        BigInteger operator/(BigInteger);
        BigInteger operator%(BigInteger);
        // I/O overloaded member functions
        friend istream & operator>>(istream &,BigInteger &);
        friend ostream & operator<<(ostream &,BigInteger &);
        // Data Conversion member functions
        operator string();
        operator int();
};

// *****************************Constructors Definations***********************************
BigInteger::BigInteger(){
    this->number="_";
    this->magnitude="_";
    this->sign='_';
}

BigInteger::BigInteger(string s){
    this->checkLength(s);
    if(s[0]=='+')
        s=s.substr(1,s.length()-1);
    this->checkLength(s);
    if(s[0]=='-'){
        this->number='-'+trimLeft(s.substr(1,s.length()-1));
        this->magnitude=trimLeft(s.substr(1,s.length()-1));
        this->sign='-';
    }
    else{
        this->number=trimLeft(s);
        this->magnitude=trimLeft(s);
        this->sign='+';
    }
    this->checkLength(this->magnitude);
    int l=this->magnitude.length();
    for(int i=0;i<l;i++){
        try{
            if(magnitude[i]!='1' && magnitude[i]!='2' && magnitude[i]!='3' && magnitude[i]!='4' && magnitude[i]!='5' && magnitude[i]!='6' && magnitude[i]!='7' && magnitude[i]!='8' && magnitude[i]!='9' && magnitude[i]!='0')
                throw(magnitude[i]);
        }
        catch(char c){
            cout<<"fatal!!! invalid input during initializing"<<endl;
            exit(0);
        }
    }
}

BigInteger::BigInteger(int n){
    if(n<0)
        this->sign='-';
    else
        this->sign='+';
    this->number=itos(n);
    if(this->sign=='-')
        this->magnitude=this->number.substr(1,this->number.length()-1);
    else
        this->magnitude=this->number;
}

BigInteger::BigInteger(const BigInteger& B){
    B.checkInitialized();
    this->number=B.number;
    this->magnitude=B.magnitude;
    this->sign=B.sign;
}

// **************************************Member functions Definations**************************************
void BigInteger::checkInitialized()const{
    try{
        if(this->number=="_" && this->magnitude=="_" && this->sign=='_')
            throw(this->number);
    }
    catch(string number){
        cout<<"fatal!!! BigInteger not initialized"<<endl;
        exit(0);
    }
}

void BigInteger::checkLength(string s)const{
    int i=10;
    double d=10.1;
    try{
        if(s.length()>MAX_BIGLENGTH)
            throw(i);
        else if(s.length()==0)
            throw(d);
    }
    catch(int ii){
        cout<<"fatal!! max length of BigInteger exceeded"<<endl;
        exit(0);
    }
    catch(double dd){
        cout<<"fatal!! invalid input for BinInteger"<<endl;
        exit(0);
    }
}

void BigInteger::initialize(string s){
    this->checkLength(s);
    if(s[0]=='+')
        s=s.substr(1,s.length()-1);
    this->checkLength(s);
    if(s[0]=='-'){
        this->number='-'+trimLeft(s.substr(1,s.length()-1));
        this->magnitude=trimLeft(s.substr(1,s.length()-1));
        this->sign='-';
    }
    else{
        this->number=trimLeft(s);
        this->magnitude=trimLeft(s);
        this->sign='+';
    }
    this->checkLength(this->magnitude);
    int l=this->magnitude.length();
    for(int i=0;i<l;i++){
        try{
            if(magnitude[i]!='1' && magnitude[i]!='2' && magnitude[i]!='3' && magnitude[i]!='4' && magnitude[i]!='5' && magnitude[i]!='6' && magnitude[i]!='7' && magnitude[i]!='8' && magnitude[i]!='9' && magnitude[i]!='0')
                throw(magnitude[i]);
        }
        catch(char c){
            cout<<"fatal!!! invalid input during initializing"<<endl;
            exit(0);
        }
    }
}

void BigInteger::initialize(int n){
    if(n<0)
        this->sign='-';
    else
        this->sign='+';
    this->number=itos(n);
    if(this->sign=='-')
        this->magnitude=this->number.substr(1,this->number.length()-1);
    else
        this->magnitude=this->number;   
}

bool BigInteger::operator==(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    if(this->sign==b2.sign){
        if(equalTo(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool BigInteger::operator>(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    if(this->sign=='+' && b2.sign=='+'){
        if(greaterThan(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else if(this->sign=='-' && b2.sign=='-'){
        if(!greaterThan(this->magnitude,b2.magnitude) && !equalTo(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else{
        if(this->sign=='-')
            return false;
        else
            return true;
    }
}

bool BigInteger::operator<(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    if(this->sign=='+' && b2.sign=='+'){
        if(!greaterThan(this->magnitude,b2.magnitude) && !equalTo(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else if(this->sign=='-' && b2.sign=='-'){
        if(greaterThan(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else{
        if(this->sign=='-')
            return true;
        else
            return false;
    }
}

bool BigInteger::operator>=(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    if(this->sign=='+' && b2.sign=='+'){
        if(greaterThan(this->magnitude,b2.magnitude) || equalTo(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else if(this->sign=='-' && b2.sign=='-'){
        if(!greaterThan(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else{
        if(this->sign=='-')
            return false;
        else
            return true;
    }
}

bool BigInteger::operator<=(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    if(this->sign=='+' && b2.sign=='+'){
        if(!greaterThan(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else if(this->sign=='-' && b2.sign=='-'){
        if(greaterThan(this->magnitude,b2.magnitude) || equalTo(this->magnitude,b2.magnitude))
            return true;
        else
            return false;
    }
    else{
        if(this->sign=='-')
            return true;
        else
            return false;
    }
}

BigInteger BigInteger::operator+(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    string ans="";
    if(this->sign=='-' && b2.sign=='-'){
        ans=add(this->magnitude,b2.magnitude);
        if(ans!="0")
            ans='-'+ans;
    }
    else if(this->sign=='+' && b2.sign=='+')
        ans=add(this->magnitude,b2.magnitude);
    else{
        if(greaterThan(this->magnitude,b2.magnitude)){
            ans=substract(this->magnitude,b2.magnitude);
            if(this->sign=='-' && ans!="0")
                ans='-'+ans;
        }
        else{
            ans=substract(b2.magnitude,this->magnitude);
            if(b2.sign=='-' && ans!="0")
                ans='-'+ans;
        }
    }
    return BigInteger(ans);
}

BigInteger BigInteger::operator-(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    string ans="";
    if((this->sign=='+' && b2.sign=='-') || (this->sign=='-' && b2.sign=='+')){
        ans=add(this->magnitude,b2.magnitude);
        if(this->sign=='-' && ans!="0")
            ans='-'+ans;
    }
    else{
        if(greaterThan(this->magnitude,b2.magnitude)){
            ans=substract(this->magnitude,b2.magnitude);
            if(this->sign=='-' && ans!="0")
                ans='-'+ans;
        }
        else{
            ans=substract(b2.magnitude,this->magnitude);
            if(this->sign=='+' && ans!="0")
                ans='-'+ans;
        }
    }
    return BigInteger(ans);
}

BigInteger BigInteger::operator*(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    string ans=multiply(this->magnitude,b2.magnitude);
    if((this->sign=='+' && b2.sign=='-') || (this->sign=='-' && b2.sign=='+')){
        if(ans!="0")
            ans='-'+ans;
    }
    return BigInteger(ans); 
}

BigInteger BigInteger::operator/(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    string ans=divide(this->magnitude,b2.magnitude);
    if((this->sign=='-' && b2.sign=='+') || (this->sign=='+' && b2.sign=='-'))
        ans='-'+ans;
    return BigInteger(ans);
}

BigInteger BigInteger::operator%(BigInteger b2){
    this->checkInitialized(); b2.checkInitialized();
    string ans=mod(this->magnitude,b2.magnitude);
    if(this->sign=='-'){
        if(ans!="0")
            ans='-'+ans;
    }
    return BigInteger(ans);
}

istream & operator>>(istream & din, BigInteger& B){
    string s;
    din>>s;
    B.initialize(s);
    return(din);
}

ostream & operator<<(ostream & dout,BigInteger& B){
    B.checkInitialized();
    dout<<B.number;
    return(dout);
}

BigInteger::operator string(){
    this->checkInitialized();
    return this->number;
}

BigInteger::operator int(){
    this->checkInitialized();
    return stoi(this->number);
}