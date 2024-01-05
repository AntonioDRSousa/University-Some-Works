/*
 * The Game of Life
 *
 * a cell is born, if it has exactly three neighbours 
 * a cell dies of loneliness, if it has less than two neighbours 
 * a cell dies of overcrowding, if it has more than three neighbours 
 * a cell survives to the next generation, if it does not die of loneliness 
 * or overcrowding 
 *
 * In this version, a 2D array of ints is used.  A 1 cell is on, a 0 cell is off.
 * The game plays a number of steps (given by the input), printing to the screen each time.  'x' printed
 * means on, space means off.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include<mpi.h>


typedef unsigned char cell_t; 

cell_t ** allocate_board (int size) {
	cell_t ** board = (cell_t **) malloc(sizeof(cell_t*)*size);
	int	i;

	for (i=0; i<size; i++)
		board[i] = (cell_t *) malloc(sizeof(cell_t)*size);
	return board;
}

void free_board (cell_t ** board, int size) {
        int     i;

        for (i=0; i<size; i++)
                free(board[i]);
	free(board);
}

void free_board (cell_t ** board, int size) {
        int     i;

        for (i=0; i<size; i++)
                free(board[i]);
	free(board);
}


/* return the number of on cells adjacent to the i,j cell */
int adjacent_to (cell_t ** board, int size, int i, int j) {
	int	k, l, count=0;
	
	int sk = (i>0) ? i-1 : i;
	int ek = (i+1 < size) ? i+1 : i;
	int sl = (j>0) ? j-1 : j;
        int el = (j+1 < size) ? j+1 : j;

	for (k=sk; k<=ek; k++)
		for (l=sl; l<=el; l++)
			count+=board[k][l];
	count-=board[i][j];
	
	return count;
}

/* print the life board */
void print (cell_t ** board, int size) {
	int	i, j;
	/* for each row */

	for (j=0; j<size; j++) {
		/* print each column position... */
		for (i=0; i<size; i++) 
			printf ("%c", board[i][j] ? 'x' : ' ');
		/* followed by a carriage return */
		printf ("\n");
	}
}

void play (cell_t ** board, cell_t ** newboard, int size,int argc, char *argv[]) {
	/* for each cell, apply the rules of Life */
	int numtasks, rank = 0;
	int initialized, finalized;
	MPI_Initialized(&initialized);
    if (!initialized){
       MPI_Init(NULL, NULL);
    }


    MPI_Status Stat;
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    	
	
	
	if(rank==0){
	    int	i, j, a;
	    int q = size/numtasks;
	    int r = size % numtasks;
	    int dest, source;
	    dest = 1;
	    source = numtasks - 1 ;
	    
	    
	    for(i=1;i<numtasks;i++){
	        MPI_Send(&(board[0][0]), size*size, MPI_UNSIGNED_CHAR, i, 0 , MPI_COMM_WORLD);
	    }
	    
	    
	    for(i=0;i<((rank+1)*q);i++){
	        for (j=0; j<size; j++) {
                a = adjacent_to (board, size, i, j);
                if (a == 2) newboard[i][j] = board[i][j];
	            if (a == 3) newboard[i][j] = 1;
	            if (a < 2) newboard[i][j] = 0;
	            if (a > 3) newboard[i][j] = 0;
	            
	            printf("--------------------------------------\n");
                fprintf(stdout,"rank %d : (%d,%d)\n",rank,i,j);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (board,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (newboard,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            printf("--------------------------------------\n");
		    }
	    }
	    
	    MPI_Send(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, dest, 1 , MPI_COMM_WORLD);
	    MPI_Recv(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, source, 1, MPI_COMM_WORLD, &Stat);
	}
	else if(rank==(numtasks-1)){
	    int	i, j, a;
	    int q = size/numtasks;
	    int r = size % numtasks;
	    int dest, source;
	    dest = 0;
	    source = rank-1 ; 
	    

	    MPI_Recv(&(board[0][0]), size*size, MPI_UNSIGNED_CHAR, 0, 0, MPI_COMM_WORLD, &Stat);
	    MPI_Recv(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, source, 1, MPI_COMM_WORLD, &Stat);

	    for(i=rank*q;i<((rank+1)*q+r);i++){
	        for (j=0; j<size; j++) {
                a = adjacent_to (board, size, i, j);
                if (a == 2) newboard[i][j] = board[i][j];
	            if (a == 3) newboard[i][j] = 1;
	            if (a < 2) newboard[i][j] = 0;
	            if (a > 3) newboard[i][j] = 0;
	            
	            printf("--------------------------------------\n");
                fprintf(stdout,"rank %d : (%d,%d)\n",rank,i,j);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (board,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (newboard,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            printf("--------------------------------------\n");
		    }
	    }
	    
	    MPI_Send(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, 0, 1, MPI_COMM_WORLD);
	}
	else{
	    int	i, j, a;
	    int q = size/numtasks;
	    int r = size % numtasks;
	    int dest, source;
	    dest = rank+1;
	    source = rank-1 ;

	    MPI_Recv(&(board[0][0]), size*size, MPI_UNSIGNED_CHAR, source, 0, MPI_COMM_WORLD, &Stat);
	    MPI_Recv(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, source, 1, MPI_COMM_WORLD, &Stat);
	    MPI_Send(&(board[0][0]), size*size, MPI_UNSIGNED_CHAR, dest, 0, MPI_COMM_WORLD);
	    for(i=rank*q;i<((rank+1)*q);i++){
	        for (j=0; j<size; j++) {
                a = adjacent_to (board, size, i, j);
                if (a == 2) newboard[i][j] = board[i][j];
	            if (a == 3) newboard[i][j] = 1;
	            if (a < 2) newboard[i][j] = 0;
	            if (a > 3) newboard[i][j] = 0;
	            
	            printf("--------------------------------------\n");
                fprintf(stdout,"rank %d : (%d,%d)\n",rank,i,j);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (board,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            print (newboard,size);
	            printf("$$$$$$$$$$$$$$$$$\n");
	            printf("--------------------------------------\n");
		    }
	    }

	    MPI_Send(&(newboard[0][0]), size*size, MPI_UNSIGNED_CHAR, dest, 1, MPI_COMM_WORLD);
	}
	

	
	MPI_Finalized(&finalized);
if (!finalized)
   MPI_Finalize();
	
	
}


/* read a file into the life board */
void read_file (FILE * f, cell_t ** board, int size) {
	int	i, j;
	char	*s = (char *) malloc(size+10);
	char c;
    
	for (j=0; j<size; j++) {
		/* get a string */
		fgets (s, size+10,f);
		/* copy the string to the life board */
		for (i=0; i<size; i++)
		{
		 	//c=fgetc(f);
			//putchar(c);
			board[i][j] = s[i] == 'x';
		}
		//fscanf(f,"\n");
	}
}

int main (int argc, char *argv[]) {
	int size, steps;
	FILE    *f;
    f = stdin;
	fscanf(f,"%d %d", &size, &steps);
	cell_t ** prev = allocate_board (size);
	read_file (f, prev,size);
	fclose(f);
	cell_t ** next = allocate_board (size);
	cell_t ** tmp;
	int i;
	#ifdef DEBUG
	printf("Initial \n");
	print(prev,size);
	printf("----------\n");
	#endif  
	 


	//for (i=0; i<steps; i++) {
	
		play (prev,next,size,argc,argv);
		
		
		
        #ifdef DEBUG
		printf("%d ----------\n", i);
		print (next,size);
		#endif
		tmp = next;
		next = prev;
		prev = tmp;
	//}

 

	print (prev,size);
	free_board(prev,size);
	free_board(next,size);
}
