#define N 100000
bool pr[N+5];
long long int i , a;
void buildPr()
{

	pr[0] = pr[1] = false;
	for( i = 2; i <= N; i++)
		pr[i] = true;

	for( i = 2; i <= N; i++)
		if(pr[i])
			for(  a = i*i; a < N; a += i)
				pr[a] = false;
}
