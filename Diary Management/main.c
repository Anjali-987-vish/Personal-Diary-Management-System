#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void diary();
int insert();
int add();
int view();

int main()
{
    FILE *fp;
    char press;
    int num;
First:
    printf("\n\n**Press The Key**\n\n");
    printf("     'w' ------ write note     \n");
    printf("     'a' ------ add new note     \n");
    printf("     'v' ------ View Previous     \n");
    printf("     'e' ------ Exit Program     \n\n");
    printf("-------------------------------\n\n");
while(1)
{
    scanf("%c",&press);
    if (press == 'w'){
        insert();
        printf("Press '1' for continue\n'0' for Exit\n");
        scanf("%d", &num);
        if(num == 1){
            goto First;
        }
        else{
            break;
        }
    }
    else if (press == 'a'){
        add();
        printf("Press '1' for continue\n'0' for Exit\n");
        scanf("%d", &num);
        if (num == 1){
            goto First;
        }
        else{
            break;
        }
    }
    else if (press == 'v'){
        view();
        printf("Press '1' for continue\n'0' for Exit\n");
        scanf("%d", &num);
        if (num == 1){
            goto First;
        }
        else{
            break;
        }
    }
    else if (press == 'e'){
        return 0;
    }
    else{
        printf("Please press correct key.\n");
    }
}
    return 0;
}

void diary() {
   printf("<--     Welcome to my Diary    -->\n\n");
}

int insert(){
    FILE *fp;
    char note[2000], date[20] ;
    diary();
    printf("Enter date : ");
    scanf("%s", date);
    printf("\n");
    printf("write notes from here....\n");
    scanf(" %[^\n]s",note);
    fp = fopen("diary.txt", "w");
    fprintf(fp, date);
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nStored)\n");
    fclose(fp);
    return 0;
}

int add() {
    FILE *fp;
    char note[2000], date[20] ;
    diary();
    printf("Enter date : ");
    scanf("%s", date);
    printf("\n");
    printf("write note from here....\n");
    scanf(" %[^\n]s", note);
    fp = fopen("diary.txt", "a");
    fprintf(fp, date);
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nStored:)\n");
    fclose(fp);
    return 0;
}

int view() {
    FILE *fp;
    char ch;
    fp = fopen("diary.txt", "r");
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nYour previous note : \n\n");
    printf("===============================================================================\n");

    while( ( ch = fgetc(fp) ) != EOF ){
        printf("%c", ch);
    }
    printf("\n");
    printf("===============================================================================\n");
    fclose(fp);
    return 0;
}
