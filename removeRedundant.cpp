#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool removeRedundant(stack<char>&st,string &s){
    int opCount = 0;
    for(auto it:s){
        char ch= it;
     
        if(ch=='('|| ch=='+' || ch=='*' || ch=='-'|| ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            int opCount = 0;
            while(!st.empty() && st.top()!='('){
                char temp = st.top();
              
                if(  temp=='+' || temp=='*' || temp=='-'|| temp=='/'){
                   opCount++;
                }
                st.pop();
            }
            st.pop();
            if(opCount==0) return true;
        }
       
}
return false;
}
int main(){
    string s = "((a)+(b))";
    stack<char>st;
    bool ans = removeRedundant(st,s);
    cout<<" Ans = "<<ans;
}