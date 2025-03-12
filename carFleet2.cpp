#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<double> carFleet2(vector<vector<int>> &cars){
int n = cars.size();
stack<int> st;
vector<double>ans(n,-1);
for(int i = n-1;i>=0;i--){
    while(!st.empty() && cars[st.top()][1]>=cars[i][1]){
        st.pop();
    }
    while(!st.empty()){
        double colTime = (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
        if(ans[st.top()]==-1 || colTime<=ans[st.top()]){
            ans[i] = colTime;
            break;
        }
        st.pop();
    }
    st.push(i);
}
return ans;
}
int main(){
    vector<vector<int>> cars = {{3,4},{5,4},{6,3},{9,1}};
    vector<double> ans = carFleet2(cars);
    for(auto it:ans) cout<<it<<" ";
}
