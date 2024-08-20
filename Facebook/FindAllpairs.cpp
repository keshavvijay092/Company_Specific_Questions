class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int x, vector<int> &arr1, vector<int> &arr2) {
       set<int>st(arr2.begin(),arr2.end());
       vector<pair<int,int>>ans;
       
       for(auto i:arr1)
       {
           int finds = x-i;
           if(st.find(finds) != st.end())
           {
                ans.emplace_back(i, finds);
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};