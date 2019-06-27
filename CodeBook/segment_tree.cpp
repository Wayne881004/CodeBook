

typedef vector <int> vi;
#define INF 1e18

vi ST;
vi A;

void st_build(vi &ST, const vi &A, int vertex, int L, int R)
{
    if(L == R)  ST[vertex] = L;
    else
    {
        int nL = 2*vertex, nR = 2*vertex+1;

        st_build(ST, A, nL, L, (L+R)/2);
        st_build(ST, A, nR, (L+R)/2+1, R);

        int lContent = ST[nL], rContent = ST[nR];
        int lValue = A[lContent], rValue = A[rContent];
        ST[vertex] = (lValue <= rValue) ? lContent : rContent;
    }
}

void st_create(vi &ST, const vi &A)
{
    int len = (int) 4*A.size();
    ST.assign(len, 0);
    st_build(ST, A, 1, 0, (int)A.size() - 1);
}

