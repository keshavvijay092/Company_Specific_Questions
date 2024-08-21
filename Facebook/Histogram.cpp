class Solution {
public:
    void Prev(vector<int>& heights ,vector<int>&prev)
    {
        stack<int>st;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
             while(!st.empty() && heights[st.top()] >= heights[i])
             {
                st.pop();
             }
             if(!st.empty() && heights[st.top()] < heights[i])
             {
                prev[i] =st.top();
             }
             st.push(i);
        }
        return ;
    }

     void Next(vector<int>& heights ,vector<int>&next)
    {
        stack<int>st;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                next[st.top()]= i;
                st.pop();

            }
            st.push(i);
        }
        return ;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevSmaller(n,-1);
        vector<int>nextSmaller(n,n);

        Prev(heights,prevSmaller);
        Next(heights,nextSmaller);
 
        int ans = 0;
        int maxi =INT_MIN;
        for(int i=0;i<n;i++)
        {
            int length = heights[i];
           
            int width = nextSmaller[i]-prevSmaller[i]-1;
            ans = length * width;
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};