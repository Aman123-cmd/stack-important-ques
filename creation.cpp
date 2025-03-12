#include<iostream>
#include<vector>
using namespace std;
class Stack{
public:
int top;
int *arr;
int size;
Stack(int x){
   this->size=x;
   arr = new int[size];
   this->top = -1;
}
void push(int x){
    if(top==size){
        cout<<"Stack overflow"<<endl;
    }
    else{
        top++;
        arr[top] = x;
    }
}
void pop(){
    int a = -1;
    if(top==-1){
        cout<<"Stack underflow"<<endl;

    }
    else{
        a = arr[top];
        top--;
       
        cout<<"Delted item is ->"<<a<<endl;
    }
 
    
}
void display(int n){
    for(int i = n;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}

};
int main(){
Stack st(7);
st.push(10);
st.push(89);
st.pop();
st.display(st.top);
}