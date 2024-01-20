#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> cmp;
    cmp.push({3,1});
    cmp.push({2,0});
    while(!cmp.empty())
    {
    	cout << cmp.top().first << ' ' << cmp.top().second << "\n";
    	cmp.pop();
	}
}
