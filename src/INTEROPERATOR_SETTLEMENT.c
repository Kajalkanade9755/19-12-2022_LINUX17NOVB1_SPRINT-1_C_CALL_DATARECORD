#include<stdio.h>
#include<stdlib.h>
void searchMMc();
void printFile();
void interOperator(){
printf("\n\033[30m\033[101m ");
box:
printf("\n1. Search for Data \n2. Print In Text File\n3.Exit\n");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
searchMMc();
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
break;
case 2:
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printFile();
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
break;
case 3:
break;
default:
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\nInavalid Input\n");
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
goto box;
}

}
void searchMMc(){

char str1[100];
 char const *fname = "newcdr.txt";
FILE *fptr = fopen (fname, "r");
int  osum=0,isum=0,mosum=0,misum=0,internetu=0,internetd=0,SearchId;
printf("enter operator id to be searched for\n");
scanf("%d",&SearchId);
char ch;
int uniqueId;
    char operato[100];
    int MMc;
    char type[100];
int duration;
int downloading;
int uploading;
int calleId;
int MNc,f=0;
//for(int i=0;i<100000;i++){
while((ch=getc(fptr))!=EOF){
    while(fscanf(fptr, "%d|%100[^|]|%d|%100[^|]|%d|%d|%d|%d|%d%*[\n]", &uniqueId,operato,&MMc,type,&duration,&downloading,&uploading,&calleId,&MNc) == 9) {
// printf("type %s\n",type);  
      if (SearchId == MMc) {
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

}
//printf("\n Operator Brand : %s (%d) \n",str1,SearchId);
//printf("\nIncoming voice call duration : %d ",osum);
//printf("\nOutgoing voice call duration :%d ",isum);
//printf("\nIncoming SMS message: %d ",misum);
//printf("\nOutgoing SMS message: %d",mosum);
//printf("\nMB Download: %d ",internetd);
//printf("\nMB Uploaded : %d\n",internetu);
//break;
// }
//printf("\n type %s \n",type);

}}
fclose(fptr);


//--=========================


//-==============================
if(f==1){
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\n Operator Brand : %s (%d) \n",str1,SearchId);
printf("\nIncoming voice call duration : %d ",osum);
printf("\nOutgoing voice call duration :%d ",isum);
printf("\nIncoming SMS message: %d ",misum);
printf("\nOutgoing SMS message: %d",mosum);
printf("\nMB Download: %d ",internetd);
printf("\nMB Uploaded : %d\n",internetu);
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}else{
printf("OPerator does not exist :%d \n",SearchId);
}

interOperator();
}
void printFile(){


char str1[100];
 char const *fname = "cdr.txt";
FILE *fptr = fopen (fname, "r");
int  osum=0,isum=0,mosum=0,misum=0,internetu=0,internetd=0,SearchId;
printf("enter operator id to be searched for\n");
scanf("%d",&SearchId);
char ch;
int uniqueId;
    char operato[100];
    int MMc;
    char type[100];
int duration;
int downloading;
int uploading;
int calleId;
int MNc,f=0;
//for(int i=0;i<100000;i++){
while((ch=getc(fptr))!=EOF){
    while(fscanf(fptr, "%d|%100[^|]|%d|%100[^|]|%d|%d|%d|%d|%d%*[\n]", &uniqueId,operato,&MMc,type,&duration,&downloading,&uploading,&calleId,&MNc) == 9) {
// printf("type %s\n",type);
      if (SearchId == MMc) {
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

}}} fclose(fptr);
FILE *out_file = fopen("IOSB.txt", "w"); // write only 
           
          // test for files not existing. 
          if (out_file == NULL) 
            {   
              printf("Error! Could not open file\n"); 
              exit(-1); // must include stdlib.h 
            } 
if(f==1){
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
fprintf(out_file,"\n Operator Brand : %s (%d) \n",str1,SearchId);
fprintf(out_file,"\nIncoming voice call duration : %d ",osum);
fprintf(out_file,"\nOutgoing voice call duration :%d ",isum);
fprintf(out_file,"\nIncoming SMS message: %d ",misum);
fprintf(out_file,"\nOutgoing SMS message: %d",mosum);
fprintf(out_file,"\nMB Download: %d ",internetd);
fprintf(out_file,"\nMB Uploaded : %d\n",internetu);
printf("\n Data is printed!! \n");
printf("\n-~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}else{
printf("OPerator does not exist :%d \n",SearchId);
}
interOperator();
}

