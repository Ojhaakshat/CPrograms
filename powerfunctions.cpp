int power(int n,int p){
	if(p==0){
		return 1;
	}

	// if(p==1){
	// 	return n;
	// }

	int powern1 = power(n,p-1);
	int powern = powern1*n;
	return powern;
}

int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}
//With Modulo(for big numbers)
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

// 3 approach
// bitmasking

