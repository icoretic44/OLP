#include<bits/stdc++.h>

using namespace std;

struct cord {
    int x, y;
    int aim, cur;
    cord() {};
    cord(pair<int,int> t, int aim, int cur) {
        this -> x = t.first;
        this -> y = t.second;
        this -> aim = aim;
        this -> cur = cur;
    }
};

const int N = 30;
queue<cord> q;
int n, nn;
int a[N][N];
pair<int,int> d[N*N][N*N][4];
pair<int,int> pos[N*N];
vector<int> X[4], Y[4];

bool inbound(int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}

void BFS() {
    while (!q.empty()) {
        cord tmp = q.front(); q.pop();
        int u = tmp.x, v = tmp.y;
        int aim = tmp.aim, cur = tmp.cur;
        int c1 = d[a[u][v]][aim][cur].first;
        int c2 = d[a[u][v]][aim][cur].second;

        for (int k=0; k < X[cur].size(); k++){
            int nu=u+X[cur][k];
            int nv=v+Y[cur][k];
            if (!inbound(nu,nv)) continue;
            if (a[nu][nv] == aim){
                if (d[aim][aim+1][cur] > make_pair(c1+1,c2)){
                    d[aim][aim+1][cur]=make_pair(c1+1,c2);
                    if (aim < nn) q.push(cord(make_pair(nu,nv),aim+1,cur));
                }
            }
            else{
                if (d[a[nu][nv]][aim][cur] > make_pair(c1+1,c2)){
                    d[a[nu][nv]][aim][cur]=make_pair(c1+1,c2);
                    q.push(cord(make_pair(nu,nv),aim,cur));
                }
            }
        }
        for (int ncur=0; ncur < 3; ncur++)
            if (ncur != cur)
                if (d[a[u][v]][aim][ncur] > make_pair(c1+1,c2+1)) {
                    d[a[u][v]][aim][ncur]=make_pair(c1+1,c2+1);
                    q.push(cord(make_pair(u,v),aim,ncur));
                }
    }
}

int main() {
    freopen("input.inp","r",stdin);
    cin >> n;
    for (int len=1; len <= n; len++){
        X[0].push_back(len), X[0].push_back(-len);
        Y[0].push_back(len), Y[0].push_back(-len);

        X[0].push_back(len), X[0].push_back(-len);
        Y[0].push_back(-len), Y[0].push_back(len);
    }

    X[1].push_back(-2), X[1].push_back(-2);
    Y[1].push_back(-1), Y[1].push_back(1);
    X[1].push_back(-1), X[1].push_back(-1);
    Y[1].push_back(-2), Y[1].push_back(2);

    X[1].push_back(2), X[1].push_back(2);
    Y[1].push_back(-1), Y[1].push_back(1);
    X[1].push_back(1), X[1].push_back(1);
    Y[1].push_back(-2), Y[1].push_back(2);

    for (int len=1; len <= n; len++){
        X[2].push_back(len), X[2].push_back(-len);
        Y[2].push_back(0), Y[2].push_back(0);

        X[2].push_back(0), X[2].push_back(0);
        Y[2].push_back(len), Y[2].push_back(-len);
    }

    nn = n*n;
    for (int i=1; i <= n; i++)
        for (int j=1; j <= n; j++){
            cin>>a[i][j];
            pos[a[i][j]]=make_pair(i,j);
        }

    for (int i=1; i <= nn; i++)
        for (int j=1; j <= nn+1; j++)
            for (int c=0; c < 3; c++)
                d[i][j][c]=make_pair(N*N*N,N*N*N);

    for (int i=0; i < 3; i++){
        d[1][2][i]=make_pair(0,0);
        q.push(cord(pos[1],2,i));
    }
    //cout << "HERE";
    BFS();
    int rs1=d[nn][nn+1][0].first, rs2=d[nn][nn+1][0].second;
    for (int i=1; i < 3; i++){
        if (rs1 == d[nn][nn+1][i].first)
            rs2=min(rs2,d[nn][nn+1][i].second);
        if (rs1 > d[nn][nn+1][i].first)
            rs1=d[nn][nn+1][i].first,
            rs2=d[nn][nn+1][i].second;
    }
    cout<<rs1<<' '<<rs2;
    return 0;
}

/*
    j != k remain because its changed the chess which also a move.
*/

/*
input:
3
7 3 1
4 2 8
9 5 6
*/
