#include<stdio.h>
#include<ctype.h>
int main(){
    int n, i, k, temp;
    char str[10][10], f;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter grammar\n");
    for(i = 0; i < n; i++){
        scanf("%s", &str[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        temp = i;
        f = str[i][0];
        if(isupper(str[i][3])){
            repeat:
            for(k = 0; k < n; k++){
                if(str[i][3] == str[k][0]){
                    if(isupper(str[k][3])){
                        i = k;
                        goto repeat;
                    }else{
                        printf("First(%c) = %c\n",f,str[k][3]);
                    }
                }
            }
        }else{
            printf("First(%c) = %c\n",f,str[i][3]);
        }
        i = temp;
    }
}