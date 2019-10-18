#include<bits/stdc++.h>
using namespace std;
int main()
{
int proc,res;
cout<<"Enter the no. of processes : ";
cin>>proc;
cout<<"Enter the no. of resources : ";
cin>>res;
int alloc[proc][res],max[proc][res],need[proc][res];
cout<<"ALLOCATION MATRIX "<<endl;
for(int i=0;i<proc;i++)
{
cout<<"P"<<i<<" ";
for(int j=0;j<res;j++)
cin>>alloc[i][j];
}
cout<<"\n MAX MATRIX "<<endl;
for(int i=0;i<proc;i++)
{
cout<<"P"<<i<<" ";
for(int j=0;j<res;j++)
{
cin>>max[i][j];
need[i][j]=max[i][j]-alloc[i][j];
}
}
int work[res];
cout<<"\n Available Resources : "<<endl;
for(int i=0;i<res;i++)
cin>>work[i];
int p=proc,i=0;
int initP=p;
int out[proc],it=0;
int flag[proc];
for(int r=0;r<proc;r++)
flag[r]=0;
while(p)
{
if(flag[i]==0)
{
int f=0;
for(int j=0;j<res;j++)
{
if(work[j]<need[i][j])
{
f=1;
break;
}

}
if(f==0)
{
// cout<<i<<" "<<work[0]<<endl;
out[it++]=i;
flag[i]=1;
for(int j=0;j<res;j++)
work[j]=work[j]+alloc[i][j];
p--;
}
}
if(i==proc-1)
{
if(initP==p)
{
cout<<"\n DEADLOCK ";
exit(0);
}
else
{
initP=p;
i=-1;
}
}
// cout<<i<<endl;
i++;
}
cout<<"\n SAFE SEQUENCE : ";
cout<<"\n P"<<out[0];
for(int i=1;i<proc;i++)
cout<<" -- "<<"P"<<out[i];
cout<<endl;
return 0;
}
