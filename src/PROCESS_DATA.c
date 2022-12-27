#include<stdio.h>
#include<string.h>
#include "PRINT_SEARCH.C"
void processing();
void processData(){
//printf("\n\033[33;31m ");
int c;
printf("\n##########################################################################################\n");
l:
printf("\n1.PROCESS CDR FILE \n2.PRINT AND SEARCH BILLING INFORMATION \n3.LOGOUT\n");
scanf("%d",&c);
switch(c){
case 1:
printf("\n##########################################################################################\n");
processing();
printf("\n##########################################################################################\n");
break;
case 2:
printf("\n##########################################################################################\n");
printSearch();
printf("\n##########################################################################################\n");
break;
case 3:
printf("\n##########################################################################################\n");
printf("\nLogout Successfull\n");
printf("\n##########################################################################################\n");
//Welcome_screen();
//userlogin(); 
 //  exit(0);
break;
printf("\n##########################################################################################\n");
default: printf("Invalid choice\n");
printf("\n##########################################################################################\n");
//processData();
//break;
goto l;
}

}
void processing(){
FILE *filep;
char ch;
printf("PLEASE WAIT DATA IS PROCESSING\n");
for(int i=0;i<5;i++){
sleep(1);
printf(".");
}
filep=fopen("cdr.txt","r");
printf("text on the file");
while((ch=getc(filep))!=EOF){
if(ch=='|')
printf("\t\t");
else
printf("%c",ch);
}
fclose(filep);
printf("YOUR DATA IS PROCESSED\n");
//return 0;
processData();
}
