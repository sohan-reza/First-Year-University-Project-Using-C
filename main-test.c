#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#define fgRed "\e[31m"
#define fgWhite "\e[37;1m"
#define fgBlack "\e[30m"
#define fgGreen "\e[32;1m"
#define fgYellow "\e[33m"
#define bgbWhite "\e[47;1m"
void txtColor(char a[]){
printf("%s",a);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void welcome_page(void) {
	system("color 0F");
	hidecursor();
/*
    printf("\n");
    printf("                 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2     \xB2   \xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2  \xB2   \xB2     \xB2 \n");
    printf("                     \xB2      \xB2     \xB2   \xB2    \xB2      \xB2      \xB2  \xB2  \xB2   \xB2     \xB2  \n");
    printf("                     \xB2      \xB2\xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2\xB2      \xB2      \xB2  \xB2  \xB2   \xB2\xB2\xB2\xB2\xB2\xB2\xB2    \n");
    printf("                     \xB2         \xB2      \xB2           \xB2      \xB2  \xB2  \xB2      \xB2      \n");
    printf("                     \xB2         \xB2      \xB2        \xB2\xB2\xB2\xB2\xB2\xB2\xB2   \xB2  \xB2\xB2\xB2\xB2      \xB2      \n\n\n");

    Sleep(1000);

    printf("                                                          \xB2\xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2   \xB2   \xB2   \xB2\xB2\xB2\xB2\xB2\xB2\xB2                       \n");
    printf("                                                             \xB2      \xB2        \xB2 \xB2       \xB2                    \n");
    printf("                                                             \xB2      \xB2\xB2\xB2\xB2\xB2     \xB2        \xB2                    \n");
    printf("                                                             \xB2      \xB2        \xB2 \xB2       \xB2                    \n");
    printf("                                                             \xB2      \xB2\xB2\xB2\xB2\xB2   \xB2   \xB2      \xB2                    \n\n\n");

 Sleep(1000);
    printf("                 \xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2      \n");
    printf("                 \xB2        \xB2   \xB2   \xB2         \xB2     \xB2       \xB2   \xB2      \n");
    printf("                 \xB2\xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2     \xB2     \xB2\xB2\xB2\xB2\xB2   \xB2\xB2\xB2\xB2\xB2      \n");
    printf("                 \xB2        \xB2   \xB2       \xB2     \xB2     \xB2       \xB2   \xB2      \n");
    printf("                 \xB2        \xB2   \xB2   \xB2\xB2\xB2\xB2\xB2     \xB2     \xB2\xB2\xB2\xB2\xB2   \xB2   \xB2      \n");
   Sleep(1000);
   system("cls");
*/
}
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void intro()
{
    printf("            ======================================================================================  \n");
    printf("            =    |||||||||  |   |  |||||  |||||  ||| |  |   |    |||||||   |||||  | |   |||||    =  \n");
    printf("            =        |      |||||  |||||    |    | | |  |||||       |      |||     |      |      =  \n");
    printf("            =        |        |    |      |||||  | |||    |         |      |||||  | |     |      =  \n");
    printf("            ======================================================================================  \n");
}

int show_menu(void) {

	char array[5]={'>',' ',' ',' ',' '};

	int i=0;
	//array[i]='>';
	int x=0;
	while(1){
		system("cls");
		     printf("\n");
   intro();
    printf("                                              ==================    \n");
    printf("                                              =    MAIN MENU   =    \n");
    printf("                                              ==================    \n");

		gotoxy(25,10);
		printf("%c BEGIN THE TEST\n", array[0]);
		gotoxy(25,12);
		printf("%c REGISTRATION\n", array[1]);
		gotoxy(25,14);
		printf("%c STATISTICS\n", array[2]);
		gotoxy(25,16);
		printf("%c QUICK TEST\n", array[3]);
		gotoxy(25,18);
		printf("%c ABOUT\n", array[4]);
		gotoxy(25,23);
        printf("=====================");
		gotoxy(25,24);
		printf("USE UP OR DOWN ARROW\n");
		gotoxy(25,25);
		printf("USE ESC TO EXIT\n");
		gotoxy(25,26);
        printf("=====================");
		x= getch();
		if(x==27){
			return 27;
		}
		if(x==13){
			return i;
			break;

		}else{

			if(x==80) {
				//printf("down arrow");
				array[i]=' ';
				i++;
				//printf("%d", i);
				i=i%5;
				array[i]='>';


			}
			if(x==72){
				array[i]=' ';
				i--;
				//printf("%d", i);
				if(i==-1){
					i=4;
				}
				//i=i%5;
				array[i]='>';
			}
		}
	}


}

void start_session(char text[], int len, char name[], char doc[]) {


	len--;
	system("cls");
	time_t t1,t2;	   struct tm *area;
	int mistake, wpm,flag=0;
	float accuracy;
	gotoxy(20,10);
	printf("        %s", text);
	t1=time(0);
	int i=0;
	int nchar=0;
	int nword=0;
	mistake=0;

	int a;
	char b;
	printf("\n                         -> ");
	while(i<len) {

		char c=getch();
		if(c==8)
        {
            continue;
        }
		if(flag==1)
		{
		    printf("\b \b");
		}

		if(c==text[i]) {
			i++;
			flag=0;
			txtColor(fgGreen);
			putch(c);
			 txtColor(fgWhite);
			nchar++;
			if(c==32){nword++;}

		}else{
			nchar++;
			txtColor(fgRed);
			putch(c);
			flag=1;
            txtColor(fgWhite);
			mistake++;

		}
	}
	t2=time(NULL);
	if(difftime(t2,t1)!=0)
	   wpm = (nword*60)/difftime(t2,t1);	/*WARNING: time difference may be zero*/
	else wpm=0;


	//mistake--;


	if(nchar!=0)
		accuracy=(float)100*(nchar-mistake)/nchar;
   	else accuracy=0.0;
	system("cls");

	typedef struct {
		char uname[20];
		char less[10];
		float dur;
		int wp;
		float acc;
		int scr;
	}user_sta;

	user_sta new;
	strcpy(new.uname, name);
	strcpy(new.less, doc);
	new.dur=difftime(t2, t1);
	new.wp=wpm;
	new.acc=accuracy;
	new.scr= accuracy*wpm;
    txtColor(fgWhite);
    intro();

        printf("\n\n\n\r\t\t\t\t          RESULT");
        printf("\n\r\t\t\t\t=============================");
        printf("\n\r\t\t\t\t||NAME            :   %s",name);
        printf("\n\r\t\t\t\t||LESSON TITLE    :   %s",doc);
        printf("\n\r\t\t\t\t||DURATION        :   %.2f seconds",difftime(t2,t1));
        printf("\n\r\t\t\t\t||GROSS SPEED     :   %d WPM",wpm);
        printf("\n\r\t\t\t\t||ACCURACY        :   %.0f%%",accuracy);
        printf("\n\r\t\t\t\t||SCORE           :   %.0f",accuracy*wpm);
        printf("\n\r\t\t\t\t=============================");
        printf("\n\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE\n");
        FILE *fuser=fopen(name, "ab");

        fseek(fuser,0,SEEK_END);
   	fwrite(&new,sizeof(user_sta),1,fuser);	/*write current seesion*/
   	fclose(fuser);

	//getch();
}


void start() {
	int login=-1;
	FILE *fp=fopen("usr.txt", "r");
	if(fp!=NULL) {
	char name[15];
	intro();
	gotoxy(30,10);
	printf("USERNAME: ");
	scanf("%s", name);
		char buffer[15];
			while(fgets(buffer, 15, fp)){
				buffer[strlen(buffer)-1]='\0';
				if(strcmp(name, buffer) == 0) {
					login=1;
				}

			}
			fclose(fp);
			if(login==1) {
			    gotoxy(35,14);
			    txtColor(fgGreen);
                printf("USER FOUND");
                Sleep(1000);
                txtColor(fgWhite);
                system("cls");
                intro();
                gotoxy(30,10);
				printf("PLEASE SELECT A PARAGRAPH: \n\n");
				FILE *list=fopen("paragraph_list.txt", "r");
				char buffer[3][8];
				int j=0;
				int i=1;
				while(fgets(buffer[j], 8, list)){

					printf("                              %d.%s\n",i, buffer[j]);
					i++;
					j++;
				}
				fclose(list);
				int sel;
				gotoxy(30,20);
				printf("ENTER CHOICE: ");
				scanf("%d", &sel);

				char text[1000];
				char file_name[20];
				buffer[sel-1][strlen(buffer[sel-1])-1]='\0';
				sprintf(file_name,"./paragraph/%s",buffer[sel-1]);
				//printf("%s", file_name);
				//printf("%s", buffer[sel-1]);
				//strcpy(file_name, buffer[sel-1]);


				FILE *r=fopen(file_name, "r");
				if(r==NULL){printf("FAILED TO OPEN FILE");}else{


					int k=0;
					int c;
					fseek(r, 0, SEEK_END);
					long long int size=ftell(r);
					fseek(r, 0, SEEK_SET);
					fread(text, size, 1, r);
					fclose(r);

					start_session(text, (int)size, name, buffer[sel-1]);
				}

			}else{
			    txtColor(fgRed);
			    gotoxy(35,14);
				printf("NO USER FOUND");
				txtColor(fgWhite);

			}
	}
	getch();
}

void reg() {
	char name[15];
    intro();
	FILE *fp;
	fp=fopen("usr.txt", "a+");
	if(fp==NULL) {
		printf("FAILED TO OPEN usrlist.\n");
	}else{
        gotoxy(25,10);
		printf("ENTER YOUR USERNAME ");
		scanf("%s", name);
		char buffer[15];
			while(fgets(buffer, 15, fp)){
				buffer[strlen(buffer)-1]='\0';
				if(strcmp(name, buffer) == 0) {
                        gotoxy(34,15);
                    txtColor(fgRed);
					printf("USERNAME ALREADY TAKEN\n");
					txtColor(fgWhite);
					getch();
					return;
				}
			}
				rewind(fp);
				fputs(name, fp);
				fputs("\n", fp);
				fclose(fp);

				FILE *fp2=fopen(name, "a+");
				if(fp2!=NULL){
                    txtColor(fgGreen);
                gotoxy(34,15);
					printf("REGISTRATION SUCCESSFULL");
					txtColor(fgWhite);
					gotoxy(34,25);
					printf("PRESS ANY KEY TO CONTINUE\n");
					getch();
					return;
				}else{
					printf("FAILED TO REGISTER");
				}
getch();

	}

}

void sta() {

typedef struct {
		char uname[20];
		char less[10];
		float dur;
		int wp;
		float acc;
		int scr;
	}user_sta;
int k=2;
int p=5;
	user_sta usr;

	FILE *ul = fopen("usr.txt", "r");
	char lname[10];
	while(fgets(lname, 10, ul)){
	lname[strlen(lname)-1]=' ';
	FILE *fp=fopen(lname,"r");
	if(fp!=NULL){
	char text[100];
	fseek(fp, 0, SEEK_END);
	long long int size=ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if(size!=0) {
            gotoxy(2,2);
            printf("NAME ||");
            gotoxy(10,2);
            printf("LESSON TITLE ||");
            gotoxy(26,2);
            printf("DURATION ||");
            gotoxy(38,2);
            printf("SPEED(WP)|| ");
            gotoxy(50,2);
            printf("ACCURACY ||");
            gotoxy(62,2);
            printf("SCORE ||");

        printf("\n\n");
		while(fread(&usr, sizeof(usr), 1,fp)) {
                gotoxy(k,p);
            printf("%s", usr.uname);
            gotoxy(k+11,p);
            printf("%s",usr.less);
            gotoxy(k+25,p);
            printf("%.2f ",usr.dur);
            gotoxy(k+40,p);
            printf("%d ",usr.wp);
            gotoxy(k+51,p);
            printf("%.2f ",usr.acc);
            gotoxy(k+61,p);
            printf("%d ",usr.scr);
            p++;

			//printf("         %s       %.2f        %d      %.2f        %d\n", ,usr.dur,usr.wp,usr.acc,usr.scr);
		}


	}
	}else{printf("FAILED TO OPEN");}
	}
	fclose(ul);
	//printf("%s", user_sta.less);
	getch();
}

void quick_test() {
	char list[5][5];
	time_t t1,t2;
	srand(time(0));
	for(int i=0; i<5;i++) {
		for(int j=0;j<5;j++){
			int num= (rand()%(90-65+1)+65);
			list[i][j]=num;
		}
	}
	printf("PRESS ANY KEY TO START\n");

	for(int i=0; i<5; i++) {

		printf(" __________________________________\n");
		printf("|      |      |      |      |      |\n");
		printf("|  %c   |   %c  |   %c  |   %c  |   %c  |\n", list[i][0], list[i][1],list[i][2],list[i][3],list[i][4]);
		printf("|______|______|______|______|______|\n");

	}


	int i=0;
	int a=0;
	int b=0;
    int flag=0;
	int mistake=0;
	int nchar=0;


	getch();
	printf("\n->");
	t1=time(0);
	while(i<25){
		char c=getch();
		if(c==8)
        {
            continue;
        }
        if(flag==1)
        {   i--;
            printf("\b \b");
        }
		//b++;
		if(c-32 == list[a][b]){
			b++;nchar++;
			txtColor(fgGreen);
			flag=0;
		putch(c);
		 txtColor(fgWhite);
		}else{
		    txtColor(fgRed);
			putch(c);
			flag=1;
			  txtColor(fgWhite);
			mistake++;

		}
		if(b==5){
			b=0;
			a++;
		}
		i++;
	}
	t2=time(0);

	float wpm;

	if(difftime(t2,t1)!=0)
	   wpm = nchar/difftime(t2,t1);	/*WARNING: time difference may be zero*/
	else wpm=0;


	//mistake--;

	float accuracy;
	if(nchar!=0)
		accuracy=(float)100*(nchar-mistake)/nchar;
   	else accuracy=0.0;

   	system("cls");
   	intro();
   	//printf("%lld\n\n\n", difftime(t2, t1));
        printf("\n\n\n\r\t\t\t\t          RESULT");
        printf("\n\r\t\t\t\t=============================");
        printf("\n\r\t\t\t\t||DURATION        :   %.2f seconds",difftime(t2,t1));
        printf("\n\r\t\t\t\t||GROSS SPEED     :   %.2f WPM",wpm);
        printf("\n\r\t\t\t\t||ACCURACY        :   %.0f%%",accuracy);
        printf("\n\r\t\t\t\t=============================");
        printf("\n\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE\n");
	getch();
}

void about() {
    intro();
	gotoxy(25,10);
	printf("DEVELOPED BY:\n");
	gotoxy(40,11);
	printf("SOHAN REZA");
	gotoxy(40,12);
	printf("NADEER FAHMI");
	gotoxy(40,13);
	printf("MD.REZWAN AHMED");
	getch();
}

void go(int s) {
	switch(s){
		case 0:
			start();
			return;
		break;
		case 1:
			reg();
			return;
		break;
		case 2:
			sta();
			return;
		break;
		case 3:
			quick_test();
			return;
		break;
		case 4:
			about();
			return;
		break;


	};
}


int main(void) {
   welcome_page();
    int a;
while(1){
    int select=show_menu();
   if(select==27) {
       system("cls");
        intro();

        printf("\n\n\n\n\n\t\t\tTHANK YOU FOR USING THIS APPLICATION");Sleep(1000);
        printf("\n\t\t\tMAY ALLAH BLESS YOU");Sleep(1000);
        printf("\n\t\t\tALLAH HAFFEZ");Sleep(1000);
        Sleep(3000);
   	return 0;
   }
    system("cls");
    go(select);

}

return 0;

}

