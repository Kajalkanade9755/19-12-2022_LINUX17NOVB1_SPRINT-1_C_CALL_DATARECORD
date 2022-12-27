#include<stdio.h>
#include<stdlib.h>
#include "INTEROPERATOR_SETTLEMENT.c"
void searchById();
void printData();
void customerSet();

void printSearch(){
printf("\n\033[97m\033[105m ");
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
g:
printf("\n1.CUSTOMER BILLING \n2.INTER-OPERATOR SETTLEMENT \n3.EXIT\n");
int c;
scanf("%d",&c);
switch(c){
case 1:
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
customerSet();
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
break;
case 2:
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
interOperator();
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
break;
case 3:
exit(0);
default:
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
printf("Invalid Input");
printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
goto g;
}
}

void customerSet(){
printf("\n1.Search By Id \n2. Print Data \n");
int input;
scanf("%d",&input);
switch(input){
case 1:
searchById();
break;
case 2:
printData();
break;
default:
printf("\ninvalid Input\n");
printSearch();
}
}

void searchById()
{
char str1[100];
 char const *fname = "newcdr.txt";
FILE *fptr = fopen (fname, "r");
int  SearchId;
printf("enter id to be searched for\n");
scanf("%d",&SearchId);
char ch;    
int uniqueId;
    char operato[50];
    int MMc;
    char type[100];
int duration;
int downloading;
int uploading;
int calleId;
int MNc;
int osum=0,isum=0,mosum=0,misum=0,internetu=0,internetd=0,f=0;
while((ch=getc(fptr))!=EOF)
{    while(fscanf(fptr, "%d|%100[^|]|%d|%100[^|]|%d|%d|%d|%d|%d%*[\n]", &uniqueId,operato,&MMc,type,&duration,&downloading,&uploading,&calleId,&MNc) == 9) {
        if (uniqueId == SearchId) {
f=1;
strcpy(str1,operato);
if(strcmp(type,"MOC")==0){
osum+=duration;
}
 if(strcmp(type,"MTC")==0){
isum+=duration;
}
if(type[5]=='O'){
   mosum+=duration;
}
if(type[5]=='T'){
misum+=duration;
}

if(type[0]=='G'){
internetu+=uploading;
internetd+=downloading;
}

printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CUSTOMER ID : %d(%s)",uniqueId,operato );
printf("\nServices within the mobile operator\n");
printf("\nIncoming voice call durations%d: \n",isum);
printf("\nOutgoing voice call durations %d:  \n",osum);
printf("\nIncoming SMS messages %d: \n",misum);
printf("\nOutgoing SMS messages %d: \n ",mosum);
//printf("Services Outside the mobile operator\n");
//printf("\nIncoming voice call durations: 0 \n Outgoing voice call durations: 312 \n Incoming SMS messages: 0\n Outgoing SMS messages: 0\n");
printf("*Internet Use*\n");
printf("MB Downloaded %d ",downloading);
printf(" | MB Uploaded %d \n",uploading);
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 break;
 }
}
    }
fclose(fptr);
if(f==1){}
else{
printf("ID DOES NOT EXITS : %d  \n ",SearchId);
}
//end:
//printf("Id not fount\n");
printSearch();
}
void printData(){


FILE *out_file = fopen("CB.txt", "w"); // write only

          // test for files not existing.
          if (out_file == NULL)
            {
              printf("Error! Could not open file\n");
              exit(-1); // must include stdlib.h
    
        }

char str1[100];
 char const *fname = "newcdr.txt";
FILE *fptr = fopen (fname, "r");
int  SearchId;
printf("enter id to be searched for\n");
scanf("%d",&SearchId);
char ch;
int uniqueId;
    char operato[50];
    int MMc;
    char type[100];
int duration;
int downloading;
int uploading;
int calleId;
int MNc;
//char str1;
int osum=0,isum=0,mosum=0,misum=0,internetu=0,internetd=0,f=0;
//for(int i=0;i<100000;i++){
while((ch=getc(fptr))!=EOF)
{    while(fscanf(fptr, "%d|%100[^|]|%d|%100[^|]|%d|%d|%d|%d|%d%*[\n]", &uniqueId,operato,&MMc,type,&duration,&downloading,&uploading,&calleId,&MNc) == 9) {
        if (uniqueId == SearchId) {
f=1;
strcpy(str1,operato);
if(strcmp(type,"MOC")==0){
osum+=duration;
}
 if(strcmp(type,"MTC")==0){
isum+=duration;
}
if(type[5]=='O'){
   mosum+=duration;
}
if(type[5]=='T'){
misum+=duration;
}

if(type[0]=='G'){
internetu+=uploading;
internetd+=downloading;
}
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CUSTOMER ID : %d(%s)",uniqueId,operato );
printf("\nServices within the mobile operator\n");
printf("\nIncoming voice call durations%d: \n",isum);
printf("\nOutgoing voice call durations %d:  \n",osum);
printf("\nIncoming SMS messages %d: \n",misum);
printf("\nOutgoing SMS messages %d: \n ",mosum);
//printf("Services Outside the mobile operator\n");
//printf("\nIncoming voice call durations: 0 \n Outgoing voice call durations: 312 \n Incoming SMS messages: 0\n Outgoing SMS messages: 0\n");
printf("*Internet Use*\n");
printf("MB Downloaded %d ",downloading);
printf(" | MB Uploaded %d \n",uploading);
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

 break;
 }
}
    }
fclose(fptr);
if(f==1){}
else{
printf("ID DOES NOT EXITS : %d  \n ",SearchId);
}
printSearch();
}




