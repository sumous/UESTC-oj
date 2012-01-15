#include<iostream>
#include<string.h>
using namespace std;
const int Max=205;
int n,m,map[Max][Max],path[Max];


bool TopSort() //从大到小找出逆拓扑
{
   int i,j,k,outdegree[Max];
   for(i=1;i<=n;i++)
      for(outdegree[i]=0,j=1;j<=n;j++)
		 outdegree[i] += map[i][j]; //出度
   for(k=n;k>0;k--)  //重量从大到小
   {
      for(i=n;i>0 && outdegree[i];i--); //标签从大到小
      if(i==0)  //有环
		 return false;
	 outdegree[i]=-1; //置为-1
	 path[i]=k;
	 //题目要求输出各个标签的重量，所以path[i]=k;
	 //若是要输出各个重量的标签，则为path[k]=i;
	 for(j=1;j<=n;j++)
		 outdegree[j] -= map[j][i]; //更新出度
   }
   return true;
}


int main()
{
	freopen("data.txt","r",stdin);
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(map,0,sizeof(map));
		while(m--)
		{
                 cin>>i>>j;
		 map[i][j]=1;
		}
		if(!TopSort())
			cout<<-1<<endl;
               else
		{
			for(i=1;i<=n;i++)
				cout<<path[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}