//permutar

void permuta(char *s)
{
		char c;
		for(int i = 0; i < s[256]; i = i+2) {
				if (s[256]-i != 1){
						c = s[i];
						s[i] = s[i+1];
						s[i+1] = c;
				}
		}
}
