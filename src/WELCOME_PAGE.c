#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include "LOGIN_PAGE.c"
void Welcome_screen() {
//system("clear");
printf("\n\033[33;44m ");
printf("\n\n\n\n");
printf("\t\t\t\t\t\t\t\t LOADING.... \t\n   ");
 printf("\n\n\n\n");
printf("\n\t\t\t\t\t\t\t\t\t*");
int str1;
for(str1=1;str1<70; str1++) {
                printf("*");
        }
        printf("\n");
	char prjct[] = {"  CALL DATA RECORD PROJECT  "};

	for (int i = 0; prjct[i] != '\0'; i++) {
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
		sleep(1);
		printf("%c\n",prjct[i]);
	}

	printf("\n");
	printf("\n\t\t\t\t\t\t\t\t\t*");

	for (int str = 1; str < 70; str++) {
//	sleep(1);
		printf("*");
	}
	printf("\n");

	for (int i = 0; i < 120; i++)
		printf("_");

	printf("\n\n\n\n\t\t\t\t\t M");
	printf("a");
	printf("d");
	printf("e ");
	printf("- b");
	printf("y");
	char name[200][200] = {" 1.kajal\n\t\t\t\t\t\t2.sayani\n\t\t\t\t\t\t3.parveen\n\t\t\t\t\t\t4.divya\n\t\t\t\t\t\t5.bidipta\n\t\t\t\t\t\t6.shikha"};

	for (int i = 0; i < 6; i++) {
		printf("\n\t\t\t\t\t       ");
		for (int j = 0; name[i][j] != '\0'; j++) {
			printf("%c", name[i][j]);
		}
	}
printf("\n\n");
sleep(5);
system("clear");
userlogin();
}



