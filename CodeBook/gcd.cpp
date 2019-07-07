int gcd(int a, int b)
{
	while(b)
	  b ^= a ^= b ^= a %= b;

	return a;
}
// gcd(a,b) ⋅ lcm(a,b) = ab 
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b){d=extgcd(b,a%b,y,x),y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}//ax+by=1 ax同餘 1 mod b
