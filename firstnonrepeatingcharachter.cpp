void firstNonRepeatingCharacter(){

	queue<char> q;
	int freq[256] = {0};

	char ch;
	cin>>ch;

	while(ch!='!'){

		q.push(ch);
		freq[ch]++;

		while(!q.empty()){
			char check = q.front();

			if(freq[check] > 1){
				q.pop();
			}else{
				cout<<check<<" ";
				break;
			}
		}

		if(q.empty()){
			cout<<(-1)<<" ";
		}

		cin>>ch;
	}

	cout<<endl;
}
