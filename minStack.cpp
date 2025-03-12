#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<pair<int,int>> st;
class MinStack{
public:

MinStack(){

}
void push(int val){
pair<int,int> p;
if(st.empty()){
    p.first = val;
    p.second =val;
    st.push_back(p);
}
else {
    int puranamin = st.back().second;
    p.second = min(puranamin,val);
    p.first = val;
    st.push_back(p);
}
}
void pop(){
    st.pop_back();
}
int getMin(){
    pair<int,int> rightmostpair = st.back();
    return rightmostpair.second;
}
};
int main(){

}