#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>arr = {1,2,3,4,5};
    int n = arr.size();
    vector<string>ans(n);

    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            ans.push_back("Odd");
        }
        else
       {
        ans.push_back("Even");
       }
    }

    for(auto i:ans)
    {
        cout<<endl<<i<<" ";
    }
    return 0;
}