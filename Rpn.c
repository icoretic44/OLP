#include<stdio.h>
#include<string.h>
int thaihoa = 0;
void them_0(char s[101],int index)
{
    int sz = strlen(s);
    for(int i=sz;i>index;--i)
    {
        s[i] = s[i-1];
    }
    s[index] = '0';
    return;
}
void xoa_khoang(char s[101])
{
    int cnt = -1;
    int sz = (int)strlen(s);
    //printf("%d ",sz);
    for(int i=0;i<sz;++i)
    {
        if(s[i]!=' ') s[++cnt] = s[i];
        //if(s[i]=='(' || s[i]==')') ++parentheses;
    }
    for(int i=cnt+1;i<100;++i)
    {
        s[i] = '\0';
    }
    sz = (int)strlen(s);
    for(int i=0;i<sz;++i)
    {
        if(s[i]=='-' && (s[i-1]<'0' || s[i-1]>'9') && s[i-1]!='x' && s[i-1]!=')')
        {
            them_0(s,i);
        }
    }
    return;
}
int oke(int i,char s[101])
{
    if(s[i]=='\0' || s[i]=='x' || s[i]=='^' || s[i]=='+' ||
       s[i]=='-') return 1;
    return 0;
}
int oke_simple(int i,char s[101])
{
    if(s[i]=='\0' || s[i]=='+' ||s[i]=='-') return 1;
    return 0;
}
void refresh(double ketqua[101])
{
    for(int i=100;i>=0;--i)
    {
        ketqua[i] = 0;
    }
    return;
}
int work(int start,int end,char s[101])
{
    int sum = 0;
    for(int j=start+1;j<end;++j)
    {
        sum = sum*10 + s[j]-'0';
    }
    if(s[start]=='-') sum*=-1;
    return sum;
}
void dem_he_so(char s[101],double heso[101])
{
    int a[101]= {0};
    int b[101]= {0};
    int cnt = 0; int cnt_a = 0;int cnt_b = 0;
    int sz = strlen(s);
    int bag[101];
    bag[0] = -1;
    for(int i=0;i<sz;++i)
    {
        if(oke(i,s)==1) bag[++cnt] = i;
    }
    bag[++cnt] = sz;
    for(int i=1;i<=cnt;++i)
    {
        int start = bag[i-1];
        int end = bag[i];
        if(end==start+1 && s[end]=='x') //x^
        {
            a[++cnt_a] = 1;
        }
        if(end-start>1 && s[end]=='x') // ...x^
        {
            a[++cnt_a] = work(start,end,s);
        }
        if(oke_simple(start,s)==1 && oke_simple(end,s)==1 && end-start>1) //he so tu do
        {
            a[++cnt_a] = work(start,end,s);
        }
        if(end-start>1 && s[start]=='^')
        {
            b[++cnt_b] = work(start,end,s);
        }
        if(end==start+1 && s[start]=='x' && s[end]!='^')
        {
            b[++cnt_b] = 1;
        }
    }
    for(int i=1;i<=cnt_a;++i)
    {
        heso[b[i]] += (double)a[i];
    }
    return;
}
void refresh_char(char c[101])
{
    for(int i=100;i>=0;--i)
    {
        c[i] = '\0';
    }
    return;
}
void cong_tru_dathuc(int k,double heso1[101],double heso2[101],double ketqua[101],int x)
{
    for(int i=100;i>=0;--i)
    {
        if(x==1)ketqua[i] += heso1[i] + heso2[i]*k;
        else ketqua[i] = heso1[i] + heso2[i]*k;
    }
    return;
}
void luythua(double heso1[101],double heso2[101],double ketqua[101])
{
    for(int i=100;i>=0;--i)
    {
        if(heso1[i]!=0)
        {
            int index = (int)heso2[0];
            ketqua[index] = heso1[i];
        }
    }
    return;
}
void nhandathuc(double heso1[101],double heso2[101],double ketqua[101],int x)
{
    for(int i=100;i>=0;--i)
    {
        for(int j=100;j>=0;--j)
        {
            if(heso1[i]!=0 && heso2[j]!=0)
            {
                if(x==1)ketqua[i+j] += heso1[i] * heso2[j];
                else ketqua[i+j] = heso1[i] * heso2[j];
            }
        }
    }
    return;
}
int finding(double heso1[101],double heso2[101],int j)
{
	for(int i=100;i>=0;--i)
	{
		if(heso1[i]!=0) return i;
	}
	return -1;
}
void chiadathuc(double heso1[101],double heso2[101],double ketqua1[101],double ketqua2[101],double ketquax[101])
{
    int a[101] = {0};
    int b[101] = {0};
    int cnt_a = 0;
    int cnt_b = 0;
    for(int i=100;i>=0;--i)
    {
        if(heso1[i]!=0) a[++cnt_a] = i;
        if(heso2[i]!=0) b[++cnt_b] = i;
    }
    if(a[1]<b[1])
    {
        ketquax[0] = 0;
        return;
    }
    int j = b[1];
    int i = finding(heso1,heso2,j);
    while(i>=j && i>-1)
    {
        ketqua1[i-j] += heso1[i]/heso2[j];
        nhandathuc(ketqua1,heso2,ketqua2,0);
        ketquax[i-j] += ketqua1[i-j];
        //printf("%.2f %d",ketquax[i-j],i);
        //printf("\n");
        refresh(ketqua1);
        cong_tru_dathuc(-1,heso1,ketqua2,heso1,0);
        refresh(ketqua2);
        i = finding(heso1,heso2,j);
    }
//    for(int i=100;i>=0;--i)
//    {
//        if(ketquax[i]!=0)
//            printf("%.2f ",ketquax[i]);
//    }
    return;
}
void cout(double ketqua[101])
{
    for(int i=100;i>=0;--i)
    {
        if(ketqua[i]!=0)
        {
            if(ketqua[i]==1e9)
            {
                ketqua[i] = 0;
                printf("0");
                return;
            }
            if(ketqua[i]>0) printf(" + %.2fx^%d",ketqua[i],i);
            else printf(" %.2fx^%d",ketqua[i],i);
        }
    }
    return;
}
void push_itp(char s[101],char stack[101][101],int cnt,int sz)
{
    for(int i=0;i<sz;++i)
    {
        stack[cnt][i] = s[i];
    }
    return;
}
char pop_itp(char stack[101][101],int cnt)
{
    char c = stack[cnt][0];
    for(int i=0;i<=100;++i)
    {
        stack[cnt][i] = '\0';
    }
    return c;
}
int priority(char c)
{
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    if(c=='(' || c==')') return 0;
    return -1;
}
void infix_to_posfix(char s[101],char pumpum[101][101])
{
    char output[101][101];
    int cnt_output = -1;
    char stack[101][101];
    int cnt_stack = -1;
    memset(output,'\0',sizeof(output));
    memset(stack,'\0',sizeof(stack));
    int sz = strlen(s);
    for(int i=0;i<sz;++i)
    {
        if(s[i]=='x')
        {
            if(s[i-1]<'0' || s[i-1]>'9')
            {
                char x[100];
                memset(x,'\0',sizeof(x));
                x[0] = '1';
                push_itp(x,output,++cnt_output,1);
                refresh_char(x);
            }
            /*while(cnt_stack!=-1 && priority('*')<=priority(stack[cnt_stack][0]))
            {
                char c[101];
                memset(c,'\0',sizeof(c));
                c[0] = pop_itp(stack,cnt_stack);
                //printf("%c\n",c[0]);
                --cnt_stack;
                push_itp(c,output,++cnt_output,1);
                refresh_char(c);
            }*/
            char c[101];
            memset(c,'\0',sizeof(c));
            c[0] = '*';
            push_itp(c,stack,++cnt_stack,1);
            refresh_char(c);

            char k[101];
            memset(k,'\0',sizeof(k));
            k[0] = 'x';
            push_itp(k,output,++cnt_output,1);
            refresh_char(k);
        }
        if(s[i]=='(')
        {
            char c[101];
            memset(c,'\0',sizeof(c));
            c[0] = '(';
            //printf("%c ",c[0]);
            push_itp(c,stack,++cnt_stack,1);
            refresh_char(c);
        }
        if(s[i]==')')
        {
            while(stack[cnt_stack][0]!='(')
            {
                char c[101];
                memset(c,'\0',sizeof(c));
                c[0] = pop_itp(stack,cnt_stack);
                //printf("%c\n",c[0]);
                --cnt_stack;
                push_itp(c,output,++cnt_output,1);
                refresh_char(c);
            }
            if(stack[cnt_stack][0]=='(')
            {
                //printf("%c ",stack[cnt_stack][0]);
                stack[cnt_stack][0] = '\0';
                --cnt_stack;
            }
        }
        if(priority(s[i])>0)
        {
            while(cnt_stack!=-1 && priority(s[i])<=priority(stack[cnt_stack][0]))
            {
                char c[101];
                memset(c,'\0',sizeof(c));
                c[0] = pop_itp(stack,cnt_stack);
                //printf("%c\n",c[0]);
                --cnt_stack;
                push_itp(c,output,++cnt_output,1);
                refresh_char(c);
            }
            char c[101];
            memset(c,'\0',sizeof(c));
            c[0] = s[i];
            //printf("%c\n",c[0]);
            push_itp(c,stack,++cnt_stack,1);
            refresh_char(c);
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            int cur = 0;
            char c[101];
            memset(c,'\0',sizeof(c));
            c[cur] = s[i];
            //printf("%c\n",c[cur]);
            for(int j=i+1;s[j]>='0' && s[j]<='9';++j)
            {
                c[++cur] = s[j];
            }
            i+=cur;
            push_itp(c,output,++cnt_output,cur+1);
            refresh_char(c);
        }
    }
    while(cnt_stack!=-1)
    {
        char c[101];
        memset(c,'\0',sizeof(c));
        c[0] = pop_itp(stack,cnt_stack);
        --cnt_stack;
        push_itp(c,output,++cnt_output,1);
        refresh_char(c);
    }
    for(int i=0;i<=cnt_output;++i)
    {
        for(int j=0;output[i][j]!='\0';++j)
        {
            pumpum[i][j] = output[i][j];
            //printf("%c ",pumpum[i][j]);
        }
        //printf("\n");
    }
    thaihoa = cnt_output;
    //printf("%d ",thaihoa);
    return;
}
void push_ketqua(double stack[101][101], double heso[101], int cnt) {
    if (cnt >= 0 && cnt < 100)
    {
        for (int i = 100; i >= 0; --i)
        {
            stack[cnt][i] = heso[i];
            //if(heso[i]!=0) printf("%.0f %d %d\n",heso[i],i,cnt);
        }
        //printf("\n");
    }
    return;
}
void pop_ketqua(double stack[101][101], double heso1[101], double heso2[101], int cnt) {
    if (cnt >= 1)
    {
        for (int i = 100; i >= 0; --i)
        {
            heso1[i] = stack[cnt][i];
            stack[cnt][i] = 0; // Gán giá trị 0 thay vì '\0'
        }
        //--cnt;
        for (int i = 100; i >= 0; --i)
        {
            heso2[i] = stack[cnt-1][i];
            stack[cnt-1][i] = 0;
        }
    }
    return;
}
void pop_1_ketqua(double stack[101][101], double heso[101], int cnt) {
    if (cnt >= 0)
    {
        for (int i = 100; i >= 0; --i)
        {
            heso[i] = stack[cnt][i];
            stack[cnt][i] = 0;
        }
    }
    return;
}
void test(double stack[101][101],int cnt)
{
    for(int i=0;i<=100;++i)
    {
        if(stack[cnt][i]!=0) printf("%.0f %d %d\n",stack[cnt][i],i,cnt);
    }
    printf("\n");
    return;
}
void thuchien(char output[101][101],double ketqua[101],int cnt_output)
{
    double stack[101][101] = {0};
    for(int i=100;i>=0;--i)
    {
        for(int j=100;j>=0;--j)
        {
            stack[i][j] = 0;
        }
    }
    int cnt_stack = -1;
    for(int i=0;i<=cnt_output;++i)
    {
        char c[101];
        memset(c,'\0',sizeof(c));
        refresh_char(c);
        for(int j=0;output[i][j]!='\0';++j)
        {
            c[j] = output[i][j];
        }
        if(c[0]=='x' || (c[0]>='0'&&c[0]<='9'))
        {
            double heso[101] = {0};
            dem_he_so(c,heso);
            push_ketqua(stack,heso,++cnt_stack);
            //test(stack,cnt_stack);
            refresh(heso);
        }
        if(c[0]=='+')
        {
            double heso1[101] = {0};
            double heso2[101] = {0};
            double heso3[101] = {0};
            pop_ketqua(stack,heso1,heso2,cnt_stack);
            cnt_stack-=2;
            cong_tru_dathuc(1,heso2,heso1,heso3,1);
            push_ketqua(stack,heso3,++cnt_stack);
            //test(stack,cnt_stack);
            refresh(heso1);
            refresh(heso2);
            refresh(heso3);
        }
        if(c[0]=='-')
        {
            double heso1[101] = {0};
            double heso2[101] = {0};
            double heso3[101] = {0};
            if(cnt_stack==0)
            {
                pop_1_ketqua(stack,heso1,cnt_stack);
                --cnt_stack;
                cong_tru_dathuc(-1,heso2,heso1,heso3,1);
                push_ketqua(stack,heso3,++cnt_stack);
                //test(stack,cnt_stack);
                refresh(heso1);
                refresh(heso2);
                refresh(heso3);
            }
            else if(cnt_stack>0)
            {
                pop_ketqua(stack,heso1,heso2,cnt_stack);
                cnt_stack-=2;
                cong_tru_dathuc(-1,heso2,heso1,heso3,1);
                push_ketqua(stack,heso3,++cnt_stack);
                //test(stack,cnt_stack);
                refresh(heso1);
                refresh(heso2);
                refresh(heso3);
            }
        }
        if(c[0]=='*')
        {
            double heso1[101] = {0};
            double heso2[101] = {0};
            double heso3[101] = {0};
            pop_ketqua(stack,heso1,heso2,cnt_stack);
            cnt_stack-=2;
            nhandathuc(heso2,heso1,heso3,1);
            push_ketqua(stack,heso3,++cnt_stack);
            //test(stack,cnt_stack);
            refresh(heso1);
            refresh(heso2);
            refresh(heso3);
        }
        if(c[0]=='/')
        {
            double heso1[101] = {0};
            double heso2[101] = {0};
            double ketqua1[101] = {0};
            double ketqua2[101] = {0};
            double ketquax[101] = {0};
            pop_ketqua(stack,heso1,heso2,cnt_stack);
            cnt_stack-=2;
            chiadathuc(heso2,heso1,ketqua1,ketqua2,ketquax);
            push_ketqua(stack,ketquax,++cnt_stack);
            //test(stack,cnt_stack);
            refresh(heso1);
            refresh(heso2);
            refresh(ketqua1);
            refresh(ketqua2);
            refresh(ketquax);
        }
        if(c[0]=='^')
        {
            double heso1[101] = {0};
            double heso2[101] = {0};
            double heso3[101] = {0};
            pop_ketqua(stack,heso1,heso2,cnt_stack);
            cnt_stack-=2;
            luythua(heso2,heso1,heso3);
            push_ketqua(stack,heso3,++cnt_stack);
            //test(stack,cnt_stack);
            refresh(heso1);
            refresh(heso2);
            refresh(heso3);
        }
        refresh_char(c);
    }
    for(int i=100;i>=0;--i)
    {
        ketqua[i] = stack[0][i];
        //if(ketqua[i]!=0) printf("%.0f %d\n",ketqua[i],i);
    }
    return;
}
int main()
{
    //freopen("thaihoa.inp","r",stdin);
    //freopen("thaihoa.out","w",stdout);
    char s[101];
    gets(s);
    xoa_khoang(s);
    char output1[101][101];
    infix_to_posfix(s,output1);
    double ketqua1[101] = {0};
    thuchien(output1,ketqua1,thaihoa);
    /*for(int i=100;i>=0;--i)
    {
        if(ketqua1[i]!=0) printf("%.2f %d\n",ketqua1[i],i);
    }*/
    printf(" ");
    char s1[101];
    gets(s1);
    xoa_khoang(s1);
    char output2[101][101];
    infix_to_posfix(s1,output2);
    double ketqua2[101] = {0};
    thuchien(output2,ketqua2,thaihoa);
    /*for(int i=100;i>=0;--i)
    {
        if(ketqua2[i]!=0) printf("%.2f %d\n",ketqua2[i],i);
    }*/
    double HESO1[101] = {0};
    double HESO2[101] = {0};
    for(int i=100;i>=0;--i)
    {
        HESO1[i] = ketqua1[i];
        HESO2[i] = ketqua2[i];
    }
    double KETQUA1[101] = {0};
    double KETQUA2[101] = {0};
    double KETQUAX[101] = {0};
    cong_tru_dathuc(1,HESO1,HESO2,KETQUA1,1);
    printf("tong : ");
    cout(KETQUA1);
    refresh(KETQUA1);

    printf("\n");

    cong_tru_dathuc(-1,HESO1,HESO2,KETQUA1,1);
    printf("hieu : ");
    cout(KETQUA1);
    refresh(KETQUA1);

    printf("\n");

    nhandathuc(HESO1,HESO2,KETQUA2,1);
    printf("tich : ");
    cout(KETQUA2);
    refresh(KETQUA2);

    printf("\n");

    chiadathuc(HESO1,HESO2,KETQUA1,KETQUA2,KETQUAX);
    printf("thuong : ");
    cout(KETQUAX);
    printf("\n");
    printf("du : ");
    cout(HESO1);
    refresh(HESO1);
    refresh(HESO2);
    refresh(KETQUA1);
    refresh(KETQUA2);
    refresh(KETQUAX);
    return 0;
}
