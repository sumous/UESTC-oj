#include<stdio.h>
#include<string.h>

struct node
{
	long left,right;
	long long sum;
	long long inc;
};
struct node tree[1000001];
long num[1000001];

void build(long l, long r, long k)//建立线段树 
{
	tree[k].left = l;tree[k].right = r;
	if(l == r)
	{
		tree[k].sum = num[l];
		return;
	}
	else
	{
		long mid = (l+r)/2;
		build(l, mid, 2*k);
		build(mid+1, r, 2*k+1);
		tree[k].sum = tree[k*2].sum + tree[k*2+1].sum;
	}//printf("test");
	
}

void update(long k, long l, long r, long c)
{//更新区间信息 
	if(tree[k].right == r && tree[k].left == l)
	{
		 tree[k].inc += c;
		 return;
	}
	else
	{
		long mid = (tree[k].left+tree[k].right)/2;
		if(mid < l)
			update(k*2+1, l, r, c);
		else if(mid >= r)
				update(k*2, l, r, c);
			else
			{
				update(k*2, l, mid, c);
				update(k*2+1, mid+1 , r, c);
			}
	}
	tree[k].sum += (long long)(r-l+1)*c;
} 
 
long long query(long l, long r, long k)
{
	long long cur = tree[k].inc*(r-l+1);
	//long long cur = 0;
	if (tree[k].left == l && tree[k].right == r)
		return tree[k].sum;
	else
	{
		long mid = (tree[k].left + tree[k].right)/2;
		if (l>mid) return query(l,r,k*2+1) + cur;
		else if (r<=mid) return query(l,r,k*2) + cur;
		return query(l,mid,k*2)+query(mid+1,r,k*2+1 )+ cur;
	}
}

int main()
{
	freopen("data.txt", "r", stdin);
	long N, Q, i;
	char com[10];
	scanf("%ld%ld", &N, &Q);
//	memset(tree,0,sizeof(tree));
	for(i = 1;i <= N;i ++)
		scanf("%ld", &num[i]);
	build(1, N, 1);
	for(i = 1;i <= Q;i++)
	{
		long a, b, c;
		scanf("%s", com);
		if(strcmp(com, "Q") == 0)
		{
		//	getchar();
			scanf("%ld%ld", &a, &b);
			printf("%lld\n", query(a, b, 1));
		}	
		if(strcmp(com, "C") == 0)
		{
		//	getchar();
			scanf("%ld%ld%ld", &a, &b, &c);
			update(1, a, b, c);
		}
	}
	return 0;
}