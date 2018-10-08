void pascal(char *s){

	//pascal
    int count = 0;
    char der[256];
    char izq[256];
    int mid;
    char c;

    //si el total es impar
    if(s[256]%2){
        mid = (s[256]-1)/2;
        izq[0] = s[mid-1];
    	count++;
    	der[0] = s[mid+1];
    	count++;
    }else{
        mid = s[256]/2;
    	izq[0] = s[mid-1];
    	count++;
   		der[0] = s[mid];
    	count++;
    }
    for(int i = 1; count < s[256]; i++){
    	if (i%2){
    		izq[i] = s[s[256]-i];
        	count++;
        	der[i] = s[i-1];
        	count++;
    	}else{
        	izq[i] = s[i-1];
        	count++;
        	der[i] = s[s[256]-i];
        	count++;
    	}
    }

    //invertir
    for (int i = 1; i-1 < mid-i+1; i++){
    	c = izq[mid-i];
    	izq[mid-i] = izq[i-1];
    	izq[i-1] = c;
    }

    for (int i = 0 ; i < s[256]; i++){
    	if(s[256]%2){
    		if(i < mid){
    			s[i] = izq[i];
    		}
    		if(i > mid){
    			s[i] = der[i-mid-1];
    		}
    	}else{
    		if(i < mid){
    			s[i] = izq[i];
    		}
    		if(i > mid){
    			s[i] = der[i-mid];
    		}
    	}
    }
}