#include<stdio.h>
int main(int argc, char *argv[]){
    FILE *f1;
    char ch;
    int lines = 0, chars = 0, tabs = 0, spaces = 0;
    if(argc != 2){
        printf("please enter file name");
        return -1;
    }
    f1 = fopen(argv[1], "r");
    if(f1 == NULL){
        printf("cannot open the file");
        return -1;
    }
    while(!feof(f1)){
        ch = getc(f1);
        switch(ch){
            case '\n':
                lines++;
                break;
            case '\t':
                tabs++;
                break;
            case ' ':
                spaces++;
                break;
            default:
                chars++;
        }
        ch = getc(f1);
    }
    printf("number of lines: %d\n", lines);
    printf("number of tabs: %d\n", tabs);
    printf("number of spaces: %d\n", spaces);
    printf("number of characters: %d\n", chars);
    return 0;
}