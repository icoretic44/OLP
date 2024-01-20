#include<stdio.h>
#include<string.h>
struct sinhvien
{
    char fullname[100];
    int student_code;
    int number_oder;
    int admission_day;
    int graduate_day;
    int credit_sign;
    int credit_accu;
    double medium_score;
};
void input(struct sinhvien* Sinhvien)
{
    getchar();
    gets(Sinhvien->fullname);
    scanf("%d",&(Sinhvien->student_code));
    scanf("%d",&(Sinhvien->number_oder));
    scanf("%d",&(Sinhvien->admission_day));
    scanf("%d",&(Sinhvien->graduate_day));
    scanf("%d",&(Sinhvien->credit_sign));
    scanf("%d",&(Sinhvien->credit_accu));
    scanf("%lf",&(Sinhvien->medium_score));
    return;
}
void output(struct sinhvien* Sinhvien)
{
    puts(Sinhvien->fullname);
    printf("%d\n",Sinhvien->student_code);
    printf("%d\n",Sinhvien->number_oder);
    printf("%d\n",Sinhvien->admission_day);
    printf("%d\n",Sinhvien->graduate_day);
    printf("%d\n",Sinhvien->credit_sign);
    printf("%d\n",Sinhvien->credit_accu);
    printf("%.2lf\n",Sinhvien->medium_score);
    return;
}
int compare_struct(struct sinhvien* a,struct sinhvien* b,int k)
{
    if(k==1) return strcmp(a->fullname,b->fullname);
    if(k==2) return a->student_code > b->student_code;
    if(k==3) return a->medium_score > b->medium_score;
}
void swap(struct sinhvien* a,struct sinhvien* b)
{
    struct sinhvien tmp;
    memcpy(&tmp,a,sizeof(struct sinhvien));
    memcpy(a,b,sizeof(struct sinhvien));
    memcpy(b,&tmp,sizeof(struct sinhvien));
    return;
}
int main()
{
    struct sinhvien Sinhvien[100];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        input(&Sinhvien[i]);
    }
    int index_remove;
    scanf("%d",&index_remove);
    for(int i=index_remove;i<n;++i) // xoa
    {
        swap(&Sinhvien[i],&Sinhvien[i+1]);
    }
    input(&Sinhvien[n]); // them
    // sorting by string
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-1;++j)
        {
            if(compare_struct(&Sinhvien[i],&Sinhvien[j],1)>0)
                swap(&Sinhvien[i],&Sinhvien[j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        output(&Sinhvien[i]);
    }
    printf("\n");
    // sorting by student_code
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-1;++j)
        {
            if(compare_struct(&Sinhvien[i],&Sinhvien[j],2)==1)
                swap(&Sinhvien[i],&Sinhvien[j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        output(&Sinhvien[i]);
    }
    printf("\n");
    // sorting by medium_score
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-1;++j)
        {
            if(compare_struct(&Sinhvien[i],&Sinhvien[j],3)==1)
                swap(&Sinhvien[i],&Sinhvien[j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        output(&Sinhvien[i]);
    }
    return 0;
}
