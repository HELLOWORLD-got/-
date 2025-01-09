//二分查找
// #include <iostream>
// using namespace std;

// int a[1000];
// int n;

// int search (int left ,int right ,int k)
// {
//     int mid = (left + right)/2;
//     if (left <=right)
//     {
//         if (k==a[mid])
//         {
//             return 1;
//         }
//         else if (k<a[mid])
//         {
//             return search(left ,mid-1 ,k);
//         }
//         else if (k>a[mid])
//         {
//             return search (mid+1,right ,k);
//         }
//     } 
//     return 0;
// }

// int main ()
// {
//    cin >> n;
//    for (int i=0;i<n;i++)
//    {
//       cin >> a[i];
//    }
//    int m;
//    cin >> m;
//    while (m--)
//    {
//      int k;
//      cin >> k;
//      int answer =  search (0,n-1,k);
//      if (answer)
//      {
//         cout << "Yes" << endl;
//      }
//      else 
//      {
//         cout << "No" << endl;
//      }
//     }
// 走迷宫
// #include <iostream>
// #include <cstring>
// using namespace std;

// int em,en;
// int m,n;
// int a[200][200];
// int dp[200][200];

// void dfs (int im,int in)
// {
//     if (im<0||im >=m||in<0||in>=n)
//     {
//         return ;
//     }
//     if (a[im][in]==1)
//     {
//         return ;
//     }
//     if (dp [im][in]==1)
//     {
//         return ;
//     }
//     if (im == em && in==en)
//     {
//         cout << "Yes";
//         exit (0);
//     }
//     dp[im][in]=1;
//     dfs (im+1,in);
//     dfs (im-1,in);
//     dfs (im,in+1);
//     dfs (im,in-1);
// }

// int main ()
// {
//    cin >> m >> n;
//    int in,im;
//    cin >> im >> in;
//    cin >> em >> en;
//    for (int i=0;i<m;i++)
//    {
//     for (int j=0;j<n;j++)
//     {
//         cin >> a[i][j];
//     }
//    }
//    memset (dp,0,sizeof(dp));
//    dfs (im,in);
//    cout << "No";  
// }

//穷尽所有排列
// #include <iostream>
// using namespace std;

// int n;
// char a[200];

// void output()
// {
//     for (int j=0;j<n;j++)
//     {
//         cout << a[j];
//     }
//     cout << endl;
// } 

// void dfs (int t)
// {
//     if (t==n)
//     {
//         output ();
//     }
//     for (int i=t;i<n;i++)
//     {
//         swap (a[i],a[t]);
//         dfs (t+1); //表示从第t+1位开始排列
//         swap (a[i],a[t]);
//     }
// }

// int main ()
// {
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         a[i]='a'+i;
//     }
//     dfs (0); //刚开始从第0位开始排列
// }

//第k小数
// #include <iostream>
// using namespace std;

// int Partition (int a[],int low,int high)
// {
//    int temp=a[low];
//    int i=low,j=high;
//    while (i!=j)
//    {
//      while (a[j]>=temp&&j>i)
//      {
//         j--;
//      }
//      a[i]=a[j];
//      while (a[i]<=temp&&i<j)
//      {
//         i++;
//      }
//      a[j]=a[i];
//    }
//    a[i]=temp;
//    return i;
// }

// void QuickSort (int a[],int low,int high)
// {
//   if (low<high)
//   {
//     int t=Partition (a,low,high);
//     QuickSort(a,low,t-1);
//     QuickSort(a,t+1,high);
//   }

// }

// int main ()
// {
//     int n;
//     cin >> n;
//     int a[10001];
//     for (int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     QuickSort (a,0,n-1);
//     int k;
//     cin >> k;
//     cout << a[k-1];
// }

//八皇后
// #include<iostream>
// #include<math.h> 
// #include<cmath> 
// using namespace std;

// int chessboard[8];//记录每一行皇后的列数
// int cnt;//可行解个数
 
// void dfs(int m);//一行一行搜索
// void output(int n);//输出第n组解 
// bool canplace(int sx,int sy);//该坐标能否放置皇后

// int main()
// {
// 	dfs(0);
// 	return 0;
//  } 
 
// void dfs(int m)
// {
// 	if(m==8)
// 	{
// 		cnt++;
// 		output(cnt); 
// 	}
// 	else
// 	{
// 		for(int i=1;i<=8;i++)
// 		{
// 			if(canplace(m,i))
// 			{
// 				chessboard[m]=i;
// 				dfs(m+1);
// 				chessboard[m]=0;
// 			}
// 		}
// 	}
//  } 
 
//  void output(int n)  //输出序号为n的一组解
// {
//     cout<<"No "<<n<<":"<<endl;
//     for(int i=0; i<8; i++)
//     {
//         for(int j=1; j<=8; j++)
//         {
//             if(chessboard[i]==j) cout<<'A';
//             else cout<<'.';  
//         }
//         cout<<endl;
//     }
// }
//  bool canplace(int sx,int sy)
//  {
//  	for(int i=0;i<sx;i++)
//  	{
//  		if(chessboard[i]==sy) return false;
//  		if(fabs(sx-i)==fabs(sy-chessboard[i])) return false;
// 	 }
// 	 return true;
//  }

//图的着色问题
// #include<iostream>

// using namespace std;

// int n;//n个顶点 
// int r;//r条边 
// int m;//m种颜色 
// int side[20][20];//记录边，且相连的边值为1
// int color[20];//记录顶点的颜色
// int plan=0;//着色方案的个数
 
// void dfs(int k);
// bool canpaint(int k,int c);//顶点k是否能涂颜色c
 
// int main()
// {
// 	int i,u,v;
// 	cin>>n>>r>>m;
// 	for(i=0;i<r;i++)
// 	{
// 		cin>>u>>v;
// 		side[u][v]=side[v][u]=1;//进行比较的时候不能因为顶点的顺序不同值有影响 
// 	}
// 	dfs(0);//从第零个顶点开始搜索 
// 	cout<<plan<<endl;
// 	return 0;
// }

// void dfs(int k)
// {
// 	if(k==n)//一条线搜索到叶子节点 
// 	{
// 		plan++;
// 	}
// 	else
// 	{
// 		for(int c=1;c<=m;c++)//试遍所有的颜色 
// 		{
// 			if(canpaint(k,c))
// 			{
// 				color[k]=c;
// 				dfs(k+1);
// 			}
// 		}
// 	}
// }

// bool canpaint(int k,int c)
// {
// 	for(int i=0;i<k;i++)//与之前上过色的顶点进行比较 
// 	{
// 		if(side[k][i]==1&&color[i]==c)//相连的顶点上颜色相同 
// 		return false;
// 	}
// 	return true;
// }


//跳马
// #include<iostream>
// #include<queue>
// using namespace std;
// struct node{
// 	int x;
// 	int y;
// };
// queue<node>q;
// node start;
// int n;
// int sx,sy,tx,ty;
// int maze[200][200];
// int step[200][200];
// int used[200][200];
// int walk[8][2]={
// 	-1,2,
// 	-2,1,
// 	-2,-1,
// 	-1,-2,
// 	1,2,
// 	1,-2,
// 	2,1,
// 	2,-1,
// };
// int bfs();
// bool istarget(node now,node next);
// void update();
// int main()
// {
// 	cin>>n;
// 	while(n--)
// 	{	
// 		cin>>sx>>sy>>tx>>ty;
//         update();
// 	    cout<<bfs()<<endl;
// 	}
// 	return 0;
// }
// void update()
// {
// 	while(!q.empty()) q.pop();
// 	for(int i=0;i<200;i++)
// 	{
// 		for(int j=0;j<200;j++)
// 		{
// 			used[i][j]=step[i][j]=0;
// 		}
// 	}
// 	sx=sx-1;
// 	sy=sy-1;
// 	tx=tx-1;
// 	ty=ty-1;
// 	start.x=sx;
// 	start.y=sy;
// 	used[start.x][start.y]=1;
// 	q.push(start);
// }
// int bfs()
// {
// 	node now,next;
// 	while(!q.empty())
// 		{
// 		    now=q.front();
// 			q.pop();
// 			for(int i=0;i<8;i++)
// 			{
// 				next.x=now.x+walk[i][0];
// 				next.y=now.y+walk[i][1];
// 				if(istarget(now,next))
// 				{
// 					return step[next.x][next.y];
// 				}
// 			}
// 		}
// }
	

// bool istarget(node now,node next)
// {
// 	if(next.x>=0&&next.x<200&&next.y>=0&&next.y<200)
// 	{
// 		if(!used[next.x][next.y])
// 		{
// 			used[next.x][next.y]=1;
// 			step[next.x][next.y]=step[now.x][now.y]+1;
// 			if(next.x==tx&&next.y==ty)
// 			{
// 				return true;
// 			}
// 			else q.push(next);
// 		}
// 	}
// 	return false;
// }

// 0—1背包
// #include <iostream>
// using namespace std;

// int n,c;
// int w[20];
// int p[20];
// int maxp ;
// int ans [20];

// void dfs (int t, int sumw, int sump)
// {
//     if (t==n)
//     {
//         maxp = max (sump,maxp);
//     }
//     else 
//     {
//         dfs (t+1,sumw,sump);
//         if (sumw+w[t]<=c)
//         {
//            dfs (t+1,sumw+w[t],sump+p[t]);
//         }
//     }
// }
// int main ()
// {
//     int k=0;
//     while (1)
//     {
//         maxp=0;
//         cin >> n >> c;
//         if  (n==0 && c==0)
//         {
//             break;
//         }
//         for (int i=0;i<n;i++)
//         {
//            cin >> w[i];
//         }
//         for (int j=0;j<n;j++)
//         {
//            cin >> p[j];
//         }
//         dfs (0,0,0);  
//         ans [k++] = maxp;
//     }
//     for (int c=0;c<k;c++)
//     {
//         cout << ans [c] << endl;
//     }
// }
// 
// 
// 分酒问题
// #include <iostream>
// #include <queue>
// using namespace std;
 
// struct node {
// 	int x;
// 	int y;
//     int z;
// };
// int m,n,k;
// node start,target;
 
// queue <node> q1; //广搜所用队列
 
// int used[10][10][10]; //判重数组
// int step[10][10][10];  //步数数组
// // int bottle[3] = {8,5,3}
// // int walk[8][3]={{-8,+5,+3},
// //                 {-5,+5,0},
// //                 {-3,0,+3},
// //                 {+5,-5,0},
// //                 {+2,-5,+3},
// //                 {0,-3,+3},
// //                 {+3,0,-3},
// //                 {0,+3,-3}};
 
 
// void input();   //输入
// void init(node start);  //初始化
// node moveto(node u,int diret);  //移动算法
// int bfs();   //主算法
// bool effective(node v);  //是否有效
// bool istarget(node v);  //是否达到目标
 
// int main()
// {
//     cin>>m>>n>>k;
//     cin.get();
//     input();
//     init(start);
//     cout<<bfs()<<endl;
//     return 0;
// }
 
// void input()
// {
//     start.x = m;
//     start.y = 0;
//     start.z = 0;
//     target.x = m/2;
//     target.y = m/2;
//     target.z = 0;
// }
 
 
// void init(node start)
// {
//     used[start.x][start.y][start.z] = 1;
//     step[start.x][start.y][start.z] = 0;
//     q1.push(start);
// }
 
// node moveto(node u,int i) //x倒入y中
// {
//     node v;
//     switch (i)
//     {
//     case 1:
//         v.x = u.x-(n-u.y);
//         if(v.x>=0&&v.x<=m)
//         {
//             v.y = n;
//         }
//         else
//         {
//             v.x = 0;
//             v.y = u.x+u.y;
//         }
//         v.z = u.z;
//         break;
//     case 2:
//         v.x = u.x-(k-u.z);
//         if(v.x>=0&&v.x<=m)
//         {
//             v.z = k;
//         }
//         else
//         {
//             v.x = 0;
//             v.z = u.x+u.z;
//         }
//         v.y = u.y;
//         break;
//     case 3:
//         v.y = 0;
//         v.x = u.x + u.y;
//         v.z = u.z;
//         break;
//     case 4:
//         v.y = u.y-(k-u.z);
//         if(v.y>=0&&v.y<=n)
//         {
//             v.z = k;
//         }
//         else
//         {
//             v.y = 0;
//             v.z = u.y+u.z;
//         }
//         v.x = u.x;
//         break;
//     case 5:
//         v.z = 0;
//         v.x = u.x+u.z;
//         v.y = u.y;
//         break;
//     case 6:
//         v.z = u.z-(n-u.y);
//         if(v.z>=0&&v.z<=k)
//         {
//             v.y = n;
//         }
//         else
//         {
//             v.z = 0;
//             v.y = u.y+u.z;
//         }
//         v.x = u.x;
//         break;
//     default:
//         break;
//     }
//     return v;
// }
 
// int bfs()
// {
//     while (!q1.empty())
//     {
//         //取出u
//         node u,v;
//         u = q1.front();
//         q1.pop();
//         for(int i=1;i<7;i++)
//         {
//             v = moveto(u,i);
//             if(effective(v))
//             {
//                 if(istarget(v))
//                 {
//                     return step[u.x][u.y][u.z]+1;
//                 }
//                 used[v.x][v.y][v.z] = 1;
//                 step[v.x][v.y][v.z] = step[u.x][u.y][u.z]+1;
//                 q1.push(v);
//             }
//         }
//     }
//     return -1;
 
// }
 
 
// bool effective(node v)
// {
//     if(v.x>=0&&v.x<=m&&v.y>=0&&v.y<=n&&v.z>=0&&v.z<=k&&used[v.x][v.y][v.z]==0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
 
// bool istarget(node v)
// {
//     if(v.x == target.x&&v.y==target.y &&v.z == target.z)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// 最长公共子序列（动态规划）
#include<iostream>
#include<cstring>
using namespace std;
 
const int N = 210;
char a[N], b[N];
int f[N][N];
 
int main()
{
    cin >> a + 1 >> b + 1;
    a[0] = ' ', b[0] = ' ';
    int la = strlen(a) - 1, lb = strlen(b) - 1;
    for(int i = 1; i <= la; i ++ )
    	for(int j = 1; j <= lb; j ++ )
        {
            if(a[i] == b[j])    f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);        	
		}
    cout << f[la][lb] << endl;
    return 0;
}
// 迷宫问题
// #include <iostream>
// using namespace std;
// #include <string.h>
// int k=0;
// int x1,x2,x3,x4;
// char a [21][21];
// int dp[21][21];
// int ans[10] ={ 0 };
// void  dfs (int r,int c)
// {
//     if (r<0||r>=20||c<0||c>=20)
//     {
//         return ;
//     }
//     if (r==x3&&c==x4)
//     {
//         k=1;
//         return;
//     }
//     if (a[r][c]=='X'||dp[r][c]==1)
//     {
//         return;
//     }
//     dp[r][c]=1;
    
//     dfs (r+1,c);
//     dfs (r-1,c);
//     dfs (r,c+1);
//     dfs (r,c-1);
// }

// int main ()
// {
//     int n;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         k=0;
//         memset(dp,0,sizeof(dp));
//         cin >> x1 >> x2 >> x3 >> x4;
//         for (int i=0;i<20;i++)
//         {
//             for (int j=0;j<20;j++)
//             {
//                 cin >> a[i][j];
//             }
//         }
//         dfs (x1,x2);
//         if (k==1)
//         {
//             ans[i]=1;
//         }
//         else 
//         {
//             ans[i]=0;
//         }
//     }
  
//     for (int i=0;i<n;i++)
//     {
//         if (ans [i]==1)
//         {
//             cout << "Yes" << endl;
//         }
//         else 
//         {
//             cout << "No" << endl;
//         }
//     }
// }
// 矩阵连乘
// #include <iostream>
// using namespace std;

// int n;
// int m[11][11], s[10][10], p[11];

// void matrixchain()
// {
//     for(int i = 1; i <= n; i++)
//     {
//         m[i][i] = 0;
//     }
//     for(int r = 2; r <= n; r++)
//     {
//         for(int i = 1; i <= n - r + 1; i++)
//         {
//             int j = i + r - 1;
//             m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
//             s[i][j] = i;
//             for(int k = i + 1; k < j; k ++)
//             {
//                 int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                 if(t < m[i][j])
//                 {
//                     m[i][j] = t;
//                     s[i][j] = k;
//                 }
//             }
//         }
//     }
//     cout << m[1][n] << endl;
// }

// int main()
// {
//     cin >> n;
//     int temp;
//     cin >> p[0] >> p[1];
//     for(int i = 2; i <= n; i++)
//     {
//         cin >> temp >> p[i];
//     }
//     matrixchain();
//     return 0;
// }
// 旅游预算
// #include <iostream>
// #include <iomanip>
// using namespace std;

// double dis, box, mile, cost;
// int stanum;
// double station[50][2], dp[50];  //dp表示到达第i个加油站的最小耗费
// int pre[50], t[50];


// int main()
// {
//     cin >> dis >> box >> mile >> dp[0] >> stanum;
//     for(int i = 1; i <= stanum; i++)
//     {
//         cin >> station[i][0] >> station[i][1];
//         dp[i] = 1 << 30;
//     }
//     double road = box * mile;
//     for(int i = 1; i <= stanum; i++)
//     {
//         for(int j = 0; j <= i - 1; j++)
//         {
//             if((station[i][0] - station[j][0]) > road || (station[i][0] - station[j][0]) * 2 < road)
//                 continue;
//             double m = (station[i][0] - station[j][0]) / mile;
//             if(dp[i] > dp[j] + m * station[i][1] + 2)
//             {
//                 dp[i] = dp[j] + m * station[i][1] + 2;
//                 pre[i] = j;
//             }
//         }
//     }

//     double result = 1 << 30;
//     int last = 0, count = 0;
//     for(int i = 0; i <= stanum; i++)
//     {
//         if(road < dis - station[i][0])
//             continue;
//         if(result > dp[i])
//         {
//             result = dp[i];
//             last = i;
//         }
//     }
//     while(last)
//     {
//         t[++count] = last;
//         last = pre[last];
//     }
//     cout.setf(ios::fixed);
//     cout << setprecision(2) << result << " " << count << endl;
//     for(int i = count; i >= 1; i--)
//         cout << t[i] << " ";
    
//     return 0;
// }
// 花生米
// #include<iostream>
// #include <cmath>
// #include<algorithm>
// using namespace std;

// int n;
// int dp[1001][1001];


// int dfs(int res,int c){
//     if(res == 1)
//     {
//         dp[res][c] = 0;
//         return 0;
//     }
//     if(dp[res][c] != -1)
//         return dp[res][c];

//     int sign = 1;
//     for(int i = 1; i <= min(res, 2 * c); i++)
//     {
//         sign = sign & dfs(res-i, i);
//         if(sign == 0)
//             break;
//     }
//     dp[res][c] = 0;
//     if(sign == 0)
//         dp[res][c] = 1;
//     return dp[res][c];
// }
// int main(){
//     int i, j;
//     while(cin >> n, n)
//     {
//         if(n == 1)
//         {
//         	cout<< 0 <<endl;
//         	continue;
// 		}
//         for(i = 0; i <= 1000; i++)
//         {
//             for(j = 0; j <= 1000; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }
//         cout << 1 - dfs(n - 1, 1) << endl;
//     }
// }
//电子老老鼠闯迷宫
// #include <iostream>
// using namespace std;

// char a [12][12];
// int ans =144;
// int dp [12][12];
// int x2,y2;


// void dfs (int t,int row ,int col)
// {
//     if (row <0||row >=12||col <0||col>=12)
//     {
//         return ;
//     }
//     if (a[row][col]=='X')
//     {
//         return ;
//     }
//     if (row == (x2-1) && col == (y2-1))
//     {
//         ans = min (ans ,t);
//         return ;
//     }
//     if (t>=dp[row][col])
//     {
//         return;
//     }
//     dp[row][col]=t;
//     dfs (t+1,row+1,col);
//     dfs (t+1,row-1,col);
//     dfs (t+1,row,col+1);
//     dfs (t+1,row,col-1);
// }

// int main ()
// { 
//     int x1,y1;
//     cin >> x1 >> y1 >> x2 >> y2;
//     for (int i=0;i<12;i++)
//     {
//         for (int j=0;j<12;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for (int i=0;i<12;i++)
//     {
//         for (int j=0;j<12;j++)
//         {
//            dp [i][j]=144;
//         }
//     }
//     dfs (0,x1-1,y1-1);
//     cout << ans;
// }

//八数码
// #include<iostream>
// #include<queue>
// #include<map>//用map来保存状态

// using namespace std;

// queue <int> q1;

// map <int, int> smap;//map是用来存放一组一一映射关系的，在map中，一个x只能对应一个y
// //移动的四个方向
// int dr[4] = {0, 1, 0, -1};
// int dc[4] = {-1, 0, 1, 0};

// int readdata();
// int bfs();
// void init(int s);
// int canmoveto(int u, int dire);
// int moveto(int u, int dire);

// int main()
// {
//     int s, num;
//     s = readdata();
//     init(s);
//     num = bfs();
//     cout << num << endl;
//     return (0);
// }

// int readdata()
// {
//     int i, s, num;

//     s = 0;
//     for(i = 0; i < 9; i++)//读取8数码的初始状态，变换成一串数保存
//     {
//         cin >> num;
//         s = s * 10 + num;
//     }
//     return(s);
// }

// void init(int s)
// {
//     q1.push(s);
//     smap[s] = 0;
// }

// int bfs()
// {
//     int i;
//     int u, v;

//     while(!q1.empty())
//     {
//         u = q1.front();
//         q1.pop();
//         for(i = 0; i < 4; i++)
//         {
//             if(canmoveto(u, i))
//             {
//                 v = moveto(u, i);
//                 if(v == 123456780)
//                 {
//                     return(smap[u] + 1);
//                 }
//                 if(smap.count(v) == 0)//也就是说在map/set中不存在等价的两个(以上)元素，
//                     //因此某个元素在map/set中出现的次数最多只能为1，用count得到的结果不是0就是
//                 {
//                     q1.push(v);
//                     smap[v] = smap[u] + 1;//记录该条路径下的步数
//                 }
//             }
//         }
//     }
//     return(-1);
// }

// int canmoveto(int u, int dire)//编码
// {
//     /*用一串数来记录当前8数码的放置状态
//     *在该函数中通过逆变换将8数码的位置复现在9宫格中
//     *dire中保存了对0的操作方式
//     *返回0移动后的合法性*/
//     int i, j;
//     int b[3][3];//构造9宫格
//     int row, col;
//     int r, c;
//     int v;

//     v = u;
//     for(i = 2; i >= 0; i--)
//     {
//         for(j = 2; j >= 0; j--)
//         {
//             b[i][j] = v % 10;//将表示数码的数串的各位数从右往左逐个放在宫格里
//             v = v / 10;
//             if(b[i][j] == 0)
//             {
//                 row = i;//记录空格的位置
//                 col = j;
//             }
//         }
//     }

//     r = row + dr[dire];//根据dire的值来移动空格
//     c = col + dc[dire];

//     if(r >= 0 && r < 3 && c >= 0 && c < 3)//约束空格移动的范围
//     {
//         return(1);
//     }
//     else
//     {
//         return(0);
//     }
// }

// int moveto(int u, int dire)//解码
// {
//     int i, j;
//     int b[3][3];
//     int row, col;
//     int r, c;
//     int v;

//     v = u;
//     for(i = 2; i >= 0; i--)
//     {
//         for(j = 2; j >= 0; j--)
//         {
//             b[i][j] = v % 10;
//             v = v / 10;
//             if(b[i][j] == 0)
//             {
//                 row = i;
//                 col = j;
//             }
//         }
//     }

//     r = row + dr[dire];
//     c = col + dc[dire];

//     b[row][col] = b[r][c];//交换 重新记录0在9宫格中的位置
//     b[r][c] = 0;//把该位置的数值置为0

//     v = 0;//将以9宫格状态存放的8数码复现成数串
//     for(i = 0; i < 3; i++)
//     {
//         for(j = 0; j < 3; j++)
//         {
//             v = v * 10 + b[i][j];
//         }
//     }

//     return(v);//返回变换后的8数码
// }

