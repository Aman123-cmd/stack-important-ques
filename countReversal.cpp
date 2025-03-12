#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
int countReversal(string &s){
    if(s.length()&1) return -1;
 int ans = 0;
 stack<char>st;
 for(auto it:s){
    if(it=='('){
        st.push(it);
    }
    else {
        if(!st.empty() && st.top()=='('){
            st.pop();
        }
        else st.push(it);
    }
    
 }
 while(!st.empty()){
    char a = st.top();
    st.pop();
    char b = st.top();
    st.pop();
    if(a==b) ans++;
     else ans+=2;
}
return ans;
}
int main(){
    string s = "(())(";
    cout<<"Ans ->"<<countReversal(s);

}