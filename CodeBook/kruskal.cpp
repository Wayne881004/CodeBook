//依題目：eMAX、nMAX

#define eMAX 205
#define nMAX 105
#define INF 1000000000

//n 點數量，e 邊數量，ise 紀錄幾號邊使用過
int n, e, ise[eMAX];
int father[nMAX];

struct Edge
{
    int from, to, dist;
}edge[eMAX];

bool cmp(Edge a, Edge b)
{
    return a.dist < b.dist;
}

//find：找尋是否為同個set
int find(int i)
{
    if(father[i] == i)  return i;
    return find(father[i]);
}

int Kruskal()
{
    int ans = 0, num = 0, id = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        father[i] = i;
    }
    for(int i = 0 ; i < e ; i++)
    {
        int n1 = edge[i].from;
        int n2 = edge[i].to;
        int n1f = find(n1);
        int n2f = find(n2);
        if(n1f != n2f)
        {
            ise[id] = i;
            id++;
            father[n1f] = n2f;
            ans = ans + edge[i].dist;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(i == find(i))
        {
            num++;
        }
    }
    if(num > 1)
    {
        return INF; //no solution
    }
    else
    {
        return ans; //min spanning tree cost
    }
}