#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string str;
    cin>>str;
    bool dp[1000][1000];
    memset(dp,0,sizeof dp);
    for(int len=1;len<=str.size();len++) /**all size palindrome check**/
        for(int i=0;i<str.size();i++) /**iterate in string**/
        {
            int l=i,r=i+len-1;
            if(len==1)
                dp[l][r]=1;/**if len=1 then the substring is palindrome**/
            else if(len==2)
                dp[l][r]=(str[l]==str[r]);/**if len=2 then check 2 char in string**/
            else   
                dp[l][r]=dp[l+1][r-1] & (str[l]==str[r]);
        }
    for(int i=0;i<str.size();i++)
        for(int j=0;j<str.size();j++)
            if(dp[i][j]==1)
            {
                for(int k=i;k<=j;k++)
                    cout<<str[k];
                cout<<endl;
            }
    return 0;
}