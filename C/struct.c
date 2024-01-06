#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	struct coord{
		int x,y;
	};
	struct coord *map=NULL;
	register int i;
	if((map=(struct coord*) malloc(4*sizeof(struct coord)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	(*(map)).x=1;
	(*(map)).y=2;
	(*(map+1)).x=3;
	(*(map+1)).y=4;
	map[2].x=5;
	map[2].y=6;
	(map+3)->x=7;
	(map+3)->y=8;
	for(i=0;i<4;i++){
		printf("%d %d\n",(map+i)->x,(map+i)->y);
	}
	free(map);
	return 0;
}
	
	
