#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

struct player {
	int  att;
	int  def;
	int  hp;
	char name [100];
};

int attack (a){
	int upper=20;
   	int lower=1;
   	return (rand() % (upper - lower + 1)) + lower;
}

int defense (a){
	int upper=16;
   	int lower=6;
   	return (rand() % (upper - lower + 1)) + lower;
}

int damage (a,b){
	if (a<b){
		return 0;
	}
	else if (a==b){
		return 0;
	}
	else{
		return a-b;
	}
	
}

void reset () {
  printf("\033[0m");
}

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void purple () {
  printf("\033[0;35m");
}

int main() {
	
	struct player p1;
	struct player p2;
	bool run=false;
	int menu_option =0;
    int i;
	char temp[50];	
	int dmg=0;
	int ac=0;
	  	   	
	  	   		p1.hp= 20;
	  	   		p2.hp= 20;
	do{
		i=0;
		red();
		printf("Main Menu\n");
		reset();
		printf("1. Input.\n");
    	printf("2. Start.\n");
    	printf("3. Exit.\n");
    	scanf("%d",&menu_option);

    	if (menu_option==1) { 
        	if (run==false){
			printf("Give player 1 name\n");
			scanf ("%s",&p1.name);
        	printf("Give player 2 name\n");
        	scanf ("%s",&p2.name);
        	run=true;
        	}
        else {
        	red();
        	printf("You've already given names\n\n");
			reset();
			}
		}
     	else if (menu_option==2) { 
			if (run==true){
				do{ 
	   				i++;
					purple();
					printf("~Round %d~\n",i);
					reset();
					if(i % 2 == 0){
						printf("It's %s's turn\n", p2.name);
    					printf("%s attacks, with:%d\n",p2.name,p2.att=attack());
    					printf("%s defeds with:%d\n",p1.name,p1.def=defense());
						dmg= damage(p2.att,p1.def);
						printf("%s loses %d hit points. Current Hit Points:%d\n",p1.name,dmg,p1.hp=p1.hp-dmg);
					}
					else{
        				printf("It's %s's turn\n", p1.name);
        				printf("%s attacks, with:%d\n",p1.name,p1.att=attack());
						printf("%s defeds with:%d\n",p2.name,p2.def=defense());
						dmg= damage(p1.att,p2.def);
						printf("%s loses %d hit points. Current Hit Points:%d\n",p2.name,dmg,p2.hp=p2.hp-dmg);
					}
					printf("Press any hey to continue...\n");
					scanf ("%s",temp);
				if (p1.hp==0 || p2.hp==0 || p1.hp<0 || p2.hp<0){
						if (p1.hp==0){
						red();
						printf("Game over!\n");
						green();
						printf("%s wins!\n",p2.name);
						red();
						printf("%s loses!\n\n",p1.name);
						reset();
	  					}
	  					else {
	  					red();
	  					printf("Game over!\n");
						green();
						printf("%s wins!\n",p1.name);
						red();
						printf("%s loses!\n\n",p2.name);
						reset();
						}
					}		  
				}while (p1.hp>0 && p2.hp>0);
			}
			else {
			red();
        	printf("You have to give names first!\n\n");
			reset();
		}
       }
		else if( menu_option==3) {
			printf("Exiting....\n");
			break;
		}
   		else{
			printf("invalid input");
		}
	}while(menu_option !='e');        
return 0;
}
