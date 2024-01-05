#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{

  int numtasks, rank, rc, dest, source, count, tag = 1;
  int inmsg, outmsg;
  MPI_Status Stat; 

  int n = 4;

  rc = MPI_Init(&argc, &argv);
  if (rc != MPI_SUCCESS)
  {
    printf("Erro ao iniciar o programa MPI. Encerrando programa.\n");
    MPI_Abort(MPI_COMM_WORLD, rc);
  }
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  if(rank==0){
    printf("teste\n");
    outmsg = 12;
    
    MPI_Send(&outmsg, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    MPI_Recv(&inmsg, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &Stat);
  }
  else if(rank == (n-1)) {
      printf("Teste\n");
      outmsg=inmsg+rank;
      
      MPI_Send(&outmsg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
      MPI_Recv(&inmsg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
  }
  else{
      printf("TESTE\n");
      dest = rank+1;
      source = rank+1;
      outmsg = inmsg+rank;
      
      MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
      MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
      
      MPI_Send(&outmsg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
      MPI_Recv(&inmsg, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &Stat);
  }

  MPI_Get_count(&Stat, MPI_INT, &count);
  printf("count = %d\n",count);
  printf("Task %d: Recebeu %d char(s) da task %d with tag %d outmsg = %d inmsg = %d\n", rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, outmsg, inmsg);
  MPI_Finalize();
  return 0;
}
