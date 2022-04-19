#include<cstdio>            
#include<cstdlib>            
#include<cstring>            
#include<iostream>          
    
using std::cin;      
using std::cout;      
using std::endl;      
struct node            
{            
    int x,y;            
};            
            
int m,n;       
int min=1000000+50;         
int map[105][105];            
int v[105][105];            
int fx[4][2]={-1,0,1,0,0,-1,0,1};            
node a[10005],b[10005];            
            
void dfs(int t,int x,int y)            
{            
    if(x==m-1 && y==n-1)            
    {            
        if(min>t)            
        {            
            min=t;            
            for(int i=0;i<t;i++)            
                b[i]=a[i];            
        }            
        return ;            
    }            
                
    for(int k=0;k<4;k++)            
    {            
        int px,py;            
        px=x+fx[k][0];            
        py=y+fx[k][1];            
                    
        if(px>=0 && px<m && py>=0 && py<n && v[px][py]==0 && map[px][py]==0)            
        {            
            v[px][py]=1;            
            a[t].x=px;            
            a[t].y=py;            
                        
            dfs(t+1,px,py);            
            v[px][py]=0;            
        }            
    }            
}            
          
int main()            
{            
    int i,j;            
    cin >> m >> n;            
                
    for(i=0;i<m;i++)            
        for(j=0;j<n;j++)            
            scanf("%d",&map[i][j]);            
                        
    memset(v,0,sizeof(v));            
    v[0][0]=1;            
    dfs(0,0,0);            
                
    if(min==1000050)            
    {            
        printf("There is no solution!\n");            
        return 0;            
    }            
                
    printf("<1,1> ");            
                
    for(i=0;i<min;i++)            
        printf("<%d,%d> ",b[i].x+1,b[i].y+1);            
                    
    printf("\n");            
    return 0;            
}
