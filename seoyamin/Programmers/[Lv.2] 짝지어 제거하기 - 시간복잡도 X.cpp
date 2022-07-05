#include <iostream>
#include<string>

using namespace std;

string deleteStr(string s) {
    string str = s;
    
    if(str.length() <= 1) {
        return str;
    }
        
    

    int i=1;
    while(i<str.size()) {
        if(str[i-1] == str[i]) {
            str.erase(i-1, 2);
            str = deleteStr(str);
            break;
        }
        i++;
    }
    
    return str;
    
}

int solution(string s)
{
    int answer = -1;
   
    
    if(deleteStr(s).length() == 0)
        answer = 1;
    else
        answer = 0;

    
    return answer;
}