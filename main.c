#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <string.h>
#include <windows.h>



void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void welcome_page(void) {
	//system("color 70");
	hidecursor();
	
    printf("================================\n");
    printf("\t  Welcome to \n\tTYPEING FASTER\n");
    printf("================================\n");
   Sleep(2000);
   system("cls");
	
}

int show_menu(void) {
	
	char array[5]={'>',' ',' ',' ',' '};
	
	int i=0;
	//array[i]='>';
	int x=0;
	while(1){
		system("cls");
		printf("Use up and down arrow to move and enter to select and Esc to exit.\n");
		printf("%c  1.Practice\n", array[0]);
		printf("%c  2.Registration\n", array[1]);
		printf("%c  3.Statistic\n", array[2]);
		printf("%c  4.Quick Test\n", array[3]);
		printf("%c  5.About\n", array[4]);
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
	printf("User: %s\n", name);
	printf("Lession: %s\n", doc);
	
	time_t t1,t2;	   struct tm *area;
	int mistake, wpm;
	float accuracy;
	system("cls");
	printf("%s", text);
	t1=time(0);
	int i=0;
	int nchar=0;
	int nword=0;
	mistake=0;
	
	int a;
	char b;
	while(i<len) {
		char c=getch();
		if(c==text[i]) {
			i++;
			putch(c);
			nchar++;
			if(c==32){nword++;}
			
		}else{
			nchar++;
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
	printf("Press any key to go back.\n");
	printf("\n\r [ R E S U L T ]");
	printf("\n\rName: %s",name);
        printf("\n\rLesson title: %s",doc);
	printf("\n\rDuration: %.2f seconds",difftime(t2,t1));
        printf("\n\rGross Speed : %d WPM",wpm);
        printf("\n\rAccuracy : %.0f%%",accuracy);
        printf("\n\rScore: %.0f",accuracy*wpm);
        
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
	printf("username: ");
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
				printf("Please select a paragraph to practice: \n");
				FILE *list=fopen("paragraph_list.txt", "r");
				char buffer[3][8];
				int j=0;
				int i=1;
				while(fgets(buffer[j], 8, list)){
					printf("%d.%s\n",i, buffer[j]);
					i++;
					j++;
				}
				fclose(list);
				printf(": ");
				int sel;
				scanf("%d", &sel);
				
				char text[1000];
				char file_name[20];
				buffer[sel-1][strlen(buffer[sel-1])-1]='\0';
				sprintf(file_name,"./paragraph/%s",buffer[sel-1]);
				//printf("%s", file_name);
				//printf("%s", buffer[sel-1]);
				//strcpy(file_name, buffer[sel-1]);
				
				
				FILE *r=fopen(file_name, "r");
				if(r==NULL){printf("Faild to open file.");}else{
				
				
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
				printf("no user found. please registration first");
			}
	}
	getch();
}

void reg() {
	char name[15];
	
	FILE *fp;
	fp=fopen("usr.txt", "a+");
	if(fp==NULL) {
		printf("Faield to open usrlist.\n");
	}else{
		
		printf("Enter your user name: ");
		scanf("%s", name);
		char buffer[15];
			while(fgets(buffer, 15, fp)){
				buffer[strlen(buffer)-1]='\0';
				if(strcmp(name, buffer) == 0) {
					printf("Username already taken.\n");
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
					printf("Usr created");
					Sleep(2);
					return;
				}else{
					printf("Failed");
				}
				
			
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
		
		while(fread(&usr, sizeof(usr), 1,fp)) {
			printf("%s %s %.2f %d %.2f %d\n", usr.uname, usr.less,usr.dur,usr.wp,usr.acc,usr.scr); 
		}
		
		
	}
	}else{printf("Failed to open");}
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
	printf("Press any key to start.\n");
	
	for(int i=0; i<5; i++) {
	
		printf(" __________________________________\n");
		printf("|      |      |      |      |      |\n");
		printf("|  %c   |   %c  |   %c  |   %c  |   %c  |\n", list[i][0], list[i][1],list[i][2],list[i][3],list[i][4]);
		printf("|______|______|______|______|______|\n");
		
	}
	
	
	int i=0;
	int a=0;
	int b=0;
	
	int mistake=0;
	int nchar=0;
	
	
	getch();
	printf("\n->");
	t1=time(0);
	while(i<25){
		char c=getch();
		putch(c);
		//b++;
		if(c-32 == list[a][b]){
			b++;nchar++;
		}else{
			b++;nchar++;
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
   	//printf("%lld\n\n\n", difftime(t2, t1));
   	printf("Press any key to go back.\n");
	printf("\n\r [ R E S U L T ]");
	printf("\n\rDuration: %.2f seconds",difftime(t2,t1));
        printf("\n\rGross Speed : %.2f Alphabet Per Second",wpm);
        printf("\n\rAccuracy : %.0f%%",accuracy);
	
	getch();
}

void about() {
	printf("About this app:\n");
	printf("Typeing  practiceing program for first year project.\n");
	printf("BY: Md. Sohan Reza, Nadeer Fahmi, Md. Rezwan Ahmed\n");
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
   	return 0;
   }
    system("cls");
    go(select);
    
}    
    
return 0;

}
