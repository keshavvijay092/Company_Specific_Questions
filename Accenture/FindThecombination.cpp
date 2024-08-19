#include<iostream>
using namespace std;
int fact(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;

    return n * fact(n-1);
}
int main()
{
    string s = "";
    cin>>s;
    int n = s.size();
    int len = n;
    for(int i=0;i<n;i++){
      if(s[i] == 'a'|| s[i] == 'e'||s[i] == 'i' ||s[i] == 'o' || s[i] == 'u')
      {
        len--;
      }

    }
int ans = fact(len);
    cout<<"enter the positon"<<ans;
    return 0;
}