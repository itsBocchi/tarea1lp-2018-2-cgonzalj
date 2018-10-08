#include<stdio.h>
#include<stdlib.h>
#include <dlfcn.h>


void (*permuta) ();
void (*rot13) ();
void (*pascal) ();
void (*backward) ();
void (*reverse) ();



int main ()
{
        char str[257];
        char c;
        int size = 0;
        int hsize = 10;
        int largo = 0;
        for(int i = 0; i < 256; i++) {
                c = getchar();
                if (c == '\n') {
                        i=256;
                } else {
                        str[i] = c;
                        size++;
                }
        }

        hsize = sizeof(char) * hsize;
        char *hash = malloc(hsize);
        int i = 0;
        while(1) {
                c=getchar();
                if (c == '\n' || c == '\0') {
                        hash[i] = '\0';
                        break;
                } else {
                        hash[i] = c;
                }
                largo++;
                i++;
                if(i>hsize) {
                        hsize *= 2;
                        hash = realloc(hash, hsize);

                        if(hash == NULL) {
                                printf("no hay mas memoria");
                                break;
                        }
                }
        }
        str[256] = size;
        i = 0;
        
        while(i < largo) {

                if(hash[i] == 'M') {
                        void *handle1;
                        handle1 = dlopen ("..//sym/libpermuta.so", RTLD_LAZY);
                        permuta = dlsym(handle1, "permuta");
                        (*permuta)(str);
                        dlclose(handle1);
                }

                else if(hash[i] == 'O') {
                        void *handle2;
                        handle2 = dlopen ("..//sym/librot13.so", RTLD_LAZY);
                        rot13 = dlsym(handle2, "rot13");
                        (*rot13)(str);
                        dlclose(handle2);
                }

                else if(hash[i] == 'V') {
                        void *handle3;
                        handle3 = dlopen ("..//sym/libpascal.so", RTLD_LAZY);
                        pascal = dlsym(handle3, "pascal");
                        (*pascal)(str);
                        dlclose(handle3);
                }

                else if(hash[i] == 'I') {
                        void *handle4;
                        handle4 = dlopen ("..//sym/libbackward.so", RTLD_LAZY);
                        backward = dlsym(handle4, "backward");
                        (*backward)(str);
                        dlclose(handle4);
                }

                else if(hash[i] == 'L') {
                        void *handle5;
                        handle5 = dlopen ("..//sym/libreverse.so", RTLD_LAZY);
                        reverse = dlsym(handle5, "reverse");
                        (*reverse)(str);
                        dlclose(handle5);
                }

                i++;
        }
        
        for(int j = 0; j < size; j++)
                printf("%c", str[j]);

        free(hash);

        return 0;
}