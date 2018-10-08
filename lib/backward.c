//backward

void backward(char *s)
{
        char c;
        int k;
        for(int i = 0; i < s[256]; i++){
                if(i%2 == 0){
                        k = 0;
    				    c = s[i];
    				    while(i-k > 0){
    					       s[i-k] = s[i-k-1];
    					       k++;
    				    }
    				    s[0] = c;
                }
        }
    
}