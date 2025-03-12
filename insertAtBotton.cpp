#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st,int x){
    if(st.size()==0){
          st.push(x);
          return ;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st,x);
     st.push(temp);
}
void display(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    insertAtBottom(st,90);
    display(st);
}