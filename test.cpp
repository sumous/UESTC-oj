#include<iostream>
#include<string.h>
using namespace std;
const int Max=205;
int n,m,map[Max][Max],path[Max];


bool TopSort() //�Ӵ�С�ҳ�������
{
   int i,j,k,outdegree[Max];
   for(i=1;i<=n;i++)
      for(outdegree[i]=0,j=1;j<=n;j++)
		 outdegree[i] += map[i][j]; //����
   for(k=n;k>0;k--)  //�����Ӵ�С
   {
      for(i=n;i>0 && outdegree[i];i--); //��ǩ�Ӵ�С
      if(i==0)  //�л�
		 return false;
	 outdegree[i]=-1; //��Ϊ-1
	 path[i]=k;
	 //��ĿҪ�����������ǩ������������path[i]=k;
	 //����Ҫ������������ı�ǩ����Ϊpath[k]=i;
	 for(j=1;j<=n;j++)
		 outdegree[j] -= map[j][i]; //���³���
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