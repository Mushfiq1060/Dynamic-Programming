#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string str;
int dp[1010][1010];
int func(int i,int j)
{
    if(i>=j)
        return i==j;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int p;
    if(str[i]==str[j])
        p=func(i+1,j-1)+2;
    else  
        p=max(func(i,j-1),func(i+1,j));
    return dp[i][j]=p;
}
string sol(int i,int j)
{
    if(i>=j)
    {
        string s="";
        if(i==j)
            return str[i]+s;
        return "";
    }
    if(str[i]==str[j])
        return str[i]+sol(i+1,j-1)+str[j];
    if(dp[i][j-1]>dp[i+1][j])
        return sol(i,j-1);
    return sol(i+1,j);
}
int main()
{
    while(cin>>str)
    {
        memset(dp,-1,sizeof dp);
        cout<<func(0,str.size()-1)<<endl;
        cout<<sol(0,str.size()-1)<<endl;
    }
    return 0;
}