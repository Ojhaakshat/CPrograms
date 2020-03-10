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

int powerBetter(int n,int p){
	if(p==0){
		return 1;
	}

	int powernby2 = powerBetter(n,p/2);

	int powern=1;
	if(p&1){
		powern = powernby2*powernby2*n;
	}else{
		powern = powernby2*powernby2;
	}

	return powern;
}

// 3 approach
// bitmasking

