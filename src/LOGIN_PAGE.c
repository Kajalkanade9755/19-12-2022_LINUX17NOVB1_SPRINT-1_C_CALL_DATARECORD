#include<regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VALIDATION.c"
#include "PROCESS_DATA.c"
int value,value2;
int validUser(char *);
void userlogin(void);
regex_t rx1,rx2;
struct user{
    char username[100];
    char password[20];
}*pUser;
char uu[50];
void userlogin(void){
    FILE *fp;FILE *userfile;
    char uName[100],name[100],pass[20],pwd[20], confirmPwd[20],buff[1024];int i;char c;
char ch;
    pUser=(struct user *)malloc(sizeof(struct user));
printf("\n-------===========================================================================================================\n");
box:
    printf("1. Login Through An Existing Account\n2. Create New account\n3.Exit\n");
    scanf("%d",& i);
    switch(i){
        case 1:
            if ( ( fp=fopen("user.txt", "r+")) == NULL) {
                if ( ( fp=fopen("user.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%s",uName);
            printf("Password: ");
            scanf("%s",pwd);
while( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
              //     printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                            processData();   system("clear");
                    }else{printf("incorrect password\n");
                    goto box;  }}

}
break;
        case 2:
 printf("\n*********************************************************************************\n");
            do
            {
                if ( ( fp=fopen("user.txt", "a+")) == NULL) {
                    if ( ( fp=fopen("user.txt", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%s",pUser->username);
               value=regcomp(&rx1,"^[a-zA-Z]*$",REG_EXTENDED);
                value=regexec(&rx1,pUser->username,0,NULL,0);
               validName(value);
  printf("Choose A Password: ");
                scanf("%s",pUser->password);
               checkPwd(pUser->password);
               printf("Confirm Password");
               scanf("%s",confirmPwd);
    // strcpy( uu,pUser->username);
     // printf("%d", validUser(uu));
          // if(validUser(uu)==1){
          //   printf("USER ALREADY EXits");}else{
             if(strcmp(pUser->password,confirmPwd)==0){
             fwrite(pUser, sizeof(struct user), 1, fp);
            printf("Registered SuccessFully!\n");
               printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
                goto box;
               }
             else{
              printf("Please try again password not match\n");
              goto box; 
  //              }
            }
            }while(c=='Y'||c=='y');
            break;
            case 3:
             exit(0); 
            break;
            default:
          printf("INVALID INPUT PLEASE TRY AGAIN\n");
           goto box;
           break;
    }
    free ( pUser);//free allocated memory
    fclose(fp);
//  system("clear");
   }

int validUser(char *input){
char p[100];
strcpy(p,input);
int f=0;
  pUser=(struct user *)malloc(sizeof(struct user));
    FILE *fp; 
    if ( ( fp=fopen("user.txt", "r+")) == NULL) {
                if ( ( fp=fopen("user.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
           }

       while( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, p) == 0) {
                          f=1;break;
                          }
}
//printf("%d",f);
fclose(fp);
return f;
}
