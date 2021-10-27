#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int np, i, j, k;
    char prods[10][10];
    printf("Enter no. of productions: ");
    scanf("%d", &np);
    printf("Enter Grammer\n");
    for(i = 0; i < np; i++){
        scanf("%s", &prods[i]);
    }
    // for each production rule
    for(i = 0; i < np; i++){
        // follow of start function is $
        if(i == 0){
            printf("Follow(%c) = $\n", prods[0][0]);
        }
        // right side of production rule
        for(j = 3; prods[i][j] != '\0'; j++){
            int temp2 = j;
            // considering only non-terminals. As Follow is done for only non-terminals 
            if(prods[i][j] >= 'A' && prods[i][j] <= 'Z'){
                // if its last then Follow(last) == Follow(first)
                if(strlen(prods[i]) - 1 == j){
                    printf("Follow(%c) = Follow(%c)\n", prods[i][j], prods[i][0]);
                }
                // storing i (as i varies in the middle while doing FIRST)
                int temp = i;
                char f = prods[i][j];
                // if the next char is terminal then Follow = next char 
                if(!isupper(prods[i][j+1]) && prods[i][j+1] != '\0'){
                    printf("Follow(%c) = %c\n", f, prods[i][j + 1]);
                }
                // if next char is not terminal then find FIRST(next Char)
                // simply finding FIRST(next char)
                if(isupper(prods[i][j + 1])){
                    repeat:
                        // for every production rule
                        for(k = 0; k < np; k++){
                            // if next char matches with left of any of the production rule
                            if(prods[k][0] == prods[i][j + 1]){
                                // if third char is terminal than print
                                if(!isupper(prods[k][3])){
                                    printf("Follow(%c) = %c\n", f, prods[k][3]);
                                }else{ // repeat and find First of that third char
                                    i = k;
                                    j = 2;
                                    goto repeat;
                                }
                            }
                        }
                }
                // we restore i as it changed in middle
                i = temp;
            }
            // we restore i as it changed in middle
            j = temp2;
        }
    }
    return 0;
}