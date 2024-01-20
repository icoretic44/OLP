#include<bits/stdc++.h>
using namespace std;
int n,a,b,t,dd[3],f[101][101]={};
#define data pair<int,int>
#define u first
#define w second
/*struct data
{
	int u,w;
};*/
bool kt(int j)
{
	fill(&f[0][0],&f[0][0]+(101)*(101),0);
	queue<data> q;
	f[dd[1]][dd[0]]=1;
	q.push({dd[1],dd[0]});
	while (q.empty()!=1)
	{
		dd[1]=q.front().u,dd[0]=q.front().w;
		if (dd[1]==n)
			return true;
		q.pop();
		for (int k=0;k<=j;k++)
			if (dd[1]-(j-k)>=0&&dd[0]-k>=0)
			{
				int x=dd[1]-j+2*k,y=dd[0]-k+(j-k);
				if (f[x][y]==0)
				{
					f[x][y]=1;;
					q.push({x,y});
				}
			}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("vnoicup23_r3_b.inp","r",stdin);
	//freopen("vnoicup23_r3_b.out","w",stdout);
	cin>>t;
	for (int e=1;e<=t;e++)
	{
		cin>>n>>a>>b;
		dd[1]=dd[0]=0;
		string s;
		cin>>s;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0')
				dd[0]++;
			else
				dd[1]++;
		}
		if (a!=b)
			cout<<"YES"<<'\n';
		else
		{
			if (kt(a)==true)
				cout<<"YES"<<'\n';
			else
				cout<<"NO"<<'\n';
		}
	}
}

