void backward(char *s){

    char c;
    int count;
    for(int i = 0; i < s[256]; i++){
    	if(i%2 == 0){
    		count = 0;
    		c = s[i];
    		while(i-count > 0){
    			s[i-count] = s[i-count-1];
    			count++;
    		}
    		s[0] = c;
    	}
    }
    
}