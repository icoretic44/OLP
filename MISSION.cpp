/*                           _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
                        `=--=-'                    */
#include<bits/stdc++.h>
using namespace std;
const int N = 300000;
int n;
int move_for_i[9] ={0,-2,-1,+1,+2,+2,+1,-1,-2};
int move_for_j[9] ={0,1,2,2,1,-1,-2,-2,-1};
vector<pair<int,int>> pos(N,{0,0});
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q_xe;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q_tuong;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q_ma;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> cmp;
/*bool oke(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n) return false;
    else return true;
}*/
void push_to_queue(int opf,int ops,int npf,int nps,int val,int cost,int flag,int j1,int j2,int j3)
{
    int k1,k2,k3 = 0;
    if(flag==1)
    {
        k2 = 1;
        k3 = 1;
    }
    else if(flag==2)
    {
        k1 = 1;
        k3 = 1;
    }
    else if(flag==3)
    {
        k1 = 1;
        k2 = 1;
    }
    for(int k=1;k<=3;++k)
                {
                    if(k==1) // di kieu xe
                    {
                        int value = val;
                        int cost_tmp = cost;
                        value += (opf!=npf) + (ops!=nps) + k1 +j1;
                        cost_tmp += k1 + j1;
                        //cout << value << ' ' << cost_tmp << "\n";
                        Q_xe.push({value,cost_tmp});
                    }
                    if(k==2)
                    {
                        int tmp1 = abs(opf-npf);
                        int tmp2 = abs(nps-ops);
                        int tmp3 = abs(tmp1-tmp2);
                        //cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << "\n";
                        if(tmp3==0)
                        {
                            int value = val;
                            int cost_tmp = cost;
                            value += k2 + j2+1;
                            cost_tmp += k2 + j2;
                            //cout << value << ' ' << cost_tmp << "\n";
                            Q_tuong.push({value,cost_tmp});
                        }
                        else if(tmp3!=0 && tmp3%2==0)
                        {
                            int value = val;
                            int cost_tmp = cost;
                            value += k2 +2+ j2;
                            cost_tmp += k2 + j2;
                            cout << value << ' ' << cost_tmp << "\n";
                            Q_tuong.push({value,cost_tmp});
                        }
                    }
                    if(k==3)
                    {
                        for(int o=1;o<=8;++o)
                        {
                            int new_x = opf + move_for_i[o];
                            int new_y = ops + move_for_j[o];
                            if(new_x==npf && new_y==nps)
                            {
                                int value = val;
                                int cost_tmp = cost;
                                value += k3+1 +j3;
                                cost_tmp += k3 +j3;
                                Q_ma.push({value,cost_tmp});
                            }
                        }
                    }
                }
}
int main()
{
    freopen("input.inp","r",stdin);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x;
            cin >> x;
            pos[x] ={i,j};
        }
    }
    Q_xe.push({0,0});
    Q_tuong.push({0,0});
    Q_ma.push({0,0});
    for(int i=2;i<=n*n;++i)
    {
        int opf = pos[i-1].first;
        int ops = pos[i-1].second;
        int npf = pos[i].first;
        int nps = pos[i].second;
            int j1,j2,j3 = 0;
            if(!Q_xe.empty()) j1=0;
            else j1=1;
            if(!Q_tuong.empty()) j2=0;
            else j2=1;
            if(!Q_ma.empty()) j3=0;
            else j3=1;
            int calu_val;
            int cachuoi_cost;
            //cout << Q_xe.top().first << ' ' << Q_xe.top().second << "\n";
                if(j1!=1)
                {
                    cmp.push({Q_xe.top().first,Q_xe.top().second});
                    //cout << Q_xe.top().first << ' ' << Q_xe.top().second << ' ' << "XE" << ' ' << i-2 << "-->" << i << "\n";
                }
                if(j2!=1)
                {
                    cmp.push({Q_tuong.top().first,Q_tuong.top().second});
                    //cout << Q_tuong.top().first << ' ' << Q_tuong.top().second << ' ' << "TUONG" << ' ' << i-2 << "-->" << i-1 <<  "\n";
                }
                if(j3!=1)
                {
                    cmp.push({Q_ma.top().first,Q_ma.top().second});
                    //cout << Q_ma.top().first << ' ' << Q_ma.top().second << ' ' << "MA" << ' ' << i-2 << "-->" << i-1 << "\n";
                }
                //cout << cmp.top().first << ' ' << cmp.top().second << endl;
            if(!cmp.empty())
            {
                calu_val = cmp.top().first;
                cachuoi_cost = cmp.top().second;
                while(!cmp.empty())
                {
                    cmp.pop();
                }
                if(j1==1) Q_xe.push({calu_val,cachuoi_cost});
                if(j2==1) Q_tuong.push({calu_val,cachuoi_cost});
                if(j3==1) Q_ma.push({calu_val,cachuoi_cost});
            }
            int val_xe = Q_xe.top().first;
            int cost_xe = Q_xe.top().second;
            //cout << val_xe << ' ' << cost_xe << "\n";
            //
            int val_tuong = Q_tuong.top().first;
            int cost_tuong = Q_tuong.top().second;
            //cout << val_tuong << ' ' << cost_tuong << "\n";
            //
            int val_ma = Q_ma.top().first;
            int cost_ma = Q_ma.top().second;
            //
            while(!Q_xe.empty()) Q_xe.pop();
            while(!Q_tuong.empty()) Q_tuong.pop();
            while(!Q_ma.empty()) Q_ma.pop();
            push_to_queue(opf,ops,npf,nps,val_xe,cost_xe,1,j1,j2,j3);
            push_to_queue(opf,ops,npf,nps,val_tuong,cost_tuong,2,j1,j2,j3);
            push_to_queue(opf,ops,npf,nps,val_ma,cost_ma,3,j1,j2,j3);
        /*for(int j=1;j<=3;++j)
        {
            if(j==1) // check queue_xe
            {
                int val = Q_xe.top().first;
                int cost = Q_xe.top().second;
                Q_xe = priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>(); // reset queue
                push_to_queue(opf,ops,npf,nps,val,cost,j,j1,j2,j3);
            }
            else if(j==2) // check queue_tuong
            {
                int val = Q_tuong.top().first;
                int cost = Q_tuong.top().second;
                Q_tuong = priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
                push_to_queue(opf,ops,npf,nps,val,cost,j,j1,j2,j3);
            }
            else if(j==3) // check quan ma
            {
                int val = Q_ma.top().first;
                int cost = Q_ma.top().second;
                Q_ma = priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
                push_to_queue(opf,ops,npf,nps,val,cost,j,j1,j2,j3);
            }
        }*/
    }
    int j1,j2,j3 = 0;
            if(!Q_xe.empty()) j1=0;
            else j1=1;
            if(!Q_tuong.empty()) j2=0;
            else j2=1;
            if(!Q_ma.empty()) j3=0;
            else j3=1;
            int calu_val;
            int cachuoi_cost;
                if(j1!=1)
                {
                    cmp.push({Q_xe.top().first,Q_xe.top().second});
                }
                if(j2!=1)
                {
                    cmp.push({Q_tuong.top().first,Q_tuong.top().second});
                }
                if(j3!=1)
                {
                    cmp.push({Q_ma.top().first,Q_ma.top().second});
                }
                //assert(cmp.top().first < N);
                //assert(cmp.top().second < N);
            calu_val = cmp.top().first;
            cachuoi_cost = cmp.top().second;
    cout << calu_val << ' ' << cachuoi_cost;
}
