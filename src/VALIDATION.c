#include<stdio.h>
#include<regex.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
//#include "LOGIN_PAGE.c"
void validName( int value){
if(value==0){
//printf("continue");
}
else if(value==REG_NOMATCH){
//userlogin();
printf("Only characters are allowed \n");
}
else{
printf("Oops Something went wrong !\n");
}
}

void validPwd(int value){

if(value==1){
//printf("continue");
}
else if(value!=1){
//printf("%d",value);
printf("\nPassword should contain one upercase one lower case number and special character\n");
//userlogin();
}
else{
printf("Oops Something went wrong !");
}
}
static void checkPwd(const char *password) {
    const char *p = password;
    char c;
    int nupper = 0;
    int nlower = 0;
    int ndigit = 0;
    int nspecial = 0;
int n=strlen(p);
//printf("%d",n);
if(n>8 && n<20){ 
   while (*p) {
        c = *p++;
        if (isupper(c)) ++nupper;
        else if (islower(c)) ++nlower;
        else if (isdigit(c)) ++ndigit;
        else if (ispunct(c)) ++nspecial;
        else continue; // space character
   }
//   return 
   int v=(nupper && nlower && ndigit && nspecial);
validPwd(v);
}
else{
printf("Password length must be 8 or more than it and less than 20\n");
//userlogin();
}
}
