#include<string>

char itoc(int n){
    return char(n+48);
}

int ctoi(char c){
    return int(c-48);
}

std::string itos(int n){
    return std::to_string(n);
}