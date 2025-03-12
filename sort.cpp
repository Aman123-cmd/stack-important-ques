#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&st,int x){
    if(st.empty() || x<st.top()){
          st.push(x);
          return ;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st,x);
     st.push(temp);
}
