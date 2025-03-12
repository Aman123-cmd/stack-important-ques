#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
string decode(string &s){
    stack<char> st;
    string ans="";
    for(auto ch:s){
        string stringToRepeat = "";
        if(ch!=']'){
            st.push(ch);
        }
        else{
            while(!st.empty() && st.top()!='['){
                stringToRepeat.push_back(st.top());
                st.pop();
            }
            st.pop();
            string howManyTimes = "";
            while(!st.empty() && st.top()>='0' && st.top()<='9'){
                howManyTimes.push_back(st.top());
                st.pop();
            }
            reverse(howManyTimes.begin(),howManyTimes.end());
            int num = stoi(howManyTimes);
            string decodeString = "";
            while(num--){     
                decodeString+=stringToRepeat;
            }
            reverse(decodeString.begin(),decodeString.end());
            for(auto ch2 :decodeString){
                st.push(ch2);
            }
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s = "3[a2[bc]]";
    string ans = decode(s);
 cout<<"Ans->"<<ans;
}