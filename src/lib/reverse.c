void reverse(char *s){

		char c;

		for (int i = 1; i-1 < s[256]-i; i++){
			c = s[s[256]-i];
				s[s[256]-i] = s[i-1];
				s[i-1] = c;
		}

}