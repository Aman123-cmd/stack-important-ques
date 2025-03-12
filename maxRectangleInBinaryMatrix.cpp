#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> nextSmaller(vector<int> &nums){
    stack<int> st;
    vector<int>ans(nums.size(),0);
st.push(-1);
for(int i = nums.size()-1;i>=0;i--){
    while(st.top()!=-1 && nums[st.top()]>=nums[i]){
        st.pop();
    }
    ans[i] = st.top();
    st.push(i);
}
return ans;
}
vector<int> prevSmaller(vector<int> &nums){
    stack<int> st;
    vector<int>ans(nums.size(),0);
st.push(-1);
for(int i =0;i<nums.size();i++){
    while(st.top()!=-1 && nums[st.top()]>=nums[i]){
        st.pop();
    }
    ans[i] = st.top();
    st.push(i);
}
return ans;
}
int largestArea(vector<int>&nums){
    vector<int>prev = prevSmaller(nums);
    vector<int>next = nextSmaller(nums);
    for(int i = 0;i<next.size();i++){
        if(next[i]==-1){
            next[i] = next.size();
        }
    }
int maxArea = INT_MIN;
    for(int i = 0;i<nums.size();i++){
        int width = next[i]-prev[i]-1;
        int length = nums[i];
        int area = length*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int maxRectangle(vector<vector<char>> &matrix){
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0;i<n;i++){
        vector<int>t;
        for(int j = 0;j<m;j++){
           t.push_back(matrix[i][j]-'0');
        }
        v.push_back(t);
    }
    int area = largestArea(v[0]);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j]){
                v[i][j]+=v[i-1][j];
            }
            else v[i][j] =0;
        }
        area = max(area,largestArea(v[i]));
    }
    return area;

}
int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = maxRectangle(matrix);
    cout<<"ans->"<<ans;
}