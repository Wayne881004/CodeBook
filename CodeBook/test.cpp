#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
	while(b)
	  b ^= a ^= b ^= a %= b;

	return a;
}
int main(int argc, char const *argv[])
{
	double L;
	while(~scanf("%lf",&L) && L){
		long long rp = L,rq = 1,tmp;

		while(L != (long long)L){
			L *= 10;
			rp = (long long)L;
			rq *= 10;
		}
		tmp = gcd(rp,rq);
		rp /= tmp;
		rq /= tmp;
		printf("%lld/%lld\n",rp,rq);		
	}
	
	return 0;
}
// unsigned   int   0～4294967295   
// int   2147483648～2147483647 
// unsigned long 0～4294967295
// long   2147483648～2147483647
// long long的最大值：9223372036854775807
// long long的最小值：-9223372036854775808
// unsigned long long的最大值：1844674407370955161
// float的最大值和最小值分别为3.40282e+038（10的38次方），1.17549e-038（10的38次方）
// double的最大值和最小值分别为1.79769e+308（10的308次方），2.22507e-308（10的308次方）

//INPUT 3 3.14 1.234567890123456 0
//OUTPUT 3/1 157/50 19290123283179/15625000000000 
