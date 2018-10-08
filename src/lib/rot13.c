void rot13(char *s){
	
    //rot13
	for(int i = 0; i<=s[256]; i++){
        if (i > s[256]){
            i=256;
        }else{
            if(s[i] >= 97 && s[i] <= 122){
                if (s[i] + 13 > 122){
                    s[i] = s[i] - 13;
                }else
                s[i] = s[i] + 13;
            }
            if(s[i] >= 65 && s[i] <= 90){
                if (s[i] + 13 > 90){
                    s[i] = s[i] - 13;
                }else
                s[i] = s[i] + 13;
            }
        }
    }
}