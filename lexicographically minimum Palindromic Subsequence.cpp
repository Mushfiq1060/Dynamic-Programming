#include<bits/stdc++.h>
#define ll long long  
using namespace std;
string str;
pair<int,string>dp[1010][1010];
pair<int,string> lex_mini(pair<int,string>a,pair<int,string>b)
{
    if(a.second.size()==b.second.size())
    {
        if(a.second<b.second)
            return a;
        return b;
    }
    if(a.second.size()>b.second.size())
        return a;
    return b;
}
pair<int,string> func(int i,int j)
{
    if(i>=j)
    {
        string s="";
        if(i==j)
            return {1,str[i]+s};
        return {0,""};
    }
    if(dp[i][j].first!=-1)
        return dp[i][j];
    if(str[i]==str[j])
    {
        int p=func(i+1,j-1).first+2;
        return dp[i][j]={p,str[i]+func(i+1,j-1).second+str[j]};     
    }
    return dp[i][j]=lex_mini(func(i+1,j),func(i,j-1));
}
int main()
{   
    while(cin>>str)
    {
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
            {
                dp[i][j].first=-1;
                dp[i][j].second="";
            }
        cout<<func(0,str.size()-1).second<<endl;
    }
    return 0;
}


/***Another Solution***/


#include<bits/stdc++.h>
#define ll long long  
using namespace std;
string str;
string dp[1010][1010];
string lex_mini(string a,string b)
{
    if(a.size()==b.size())
    {
        if(a<b)
            return a;
        return b;
    }
    if(a.size()>b.size())
        return a;
    return b;
}
string func(int i,int j)
{
    if(i>=j)
    {
        string s="";
        if(i==j)
            return str[i]+s;
        return "";
    }
    if(dp[i][j]!="")
        return dp[i][j];
    if(str[i]==str[j])
        return dp[i][j]=str[i]+func(i+1,j-1)+str[j];     
    return dp[i][j]=lex_mini(func(i+1,j),func(i,j-1));
}
int main()
{   
    while(cin>>str)
    {
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                dp[i][j]="";
        cout<<func(0,str.size()-1)<<endl;
    }
    return 0;
}
