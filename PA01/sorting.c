#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include "strings.h"

long *Load_File(char *Filename, int *Size){
  FILE *inputfile = fopen(Filename, "r");
  fseek(inputfile, 0, SEEK_SET);
  int nelements = 0;

  fscanf(inputfile, "%d", &nelements);
  long *Array = malloc(sizeof(long) * nelements);
  int i = 0;
  //printf("nelements is %d",nelements);
  for(i = 0; i < nelements; i++){
    fscanf(inputfile, "%ld", &(Array[i]));
  }

  *Size = i; 

  fclose(inputfile);
  return Array;
}

int Save_File(char *Filename, long *Array, int Size){
  FILE *outputfile = fopen(Filename, "w");
  fseek(outputfile, 0, SEEK_SET);

  fprintf(outputfile, "%d\n", Size);
  int i = 0;

  for(i = 0; i < Size; i++){
    fprintf(outputfile, "%ld\n", Array[i]);
  }

  fclose(outputfile);
  return 1;
}

void Shell_Insertion_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move){
  int i = 0; 
  int j = 0;
  int k = 0; 
  int temp = 0;
  //int num_comp = 0;
  //int num_move = 0;
  int nelements = 0;
  int kval = 0;
  while(pow(2, nelements) < Size){
    nelements++;
  }
  int num[nelements - 1];
  int b = 0;
  int c = 0;

  for(i = 1; i < Size; i = i * 2 + 1){
    num[b] = i; 
    b++;
  }
  
  for(k = b - 1; k >= 0; k--){
    kval = num[k];
    //printf("%d\n", kval);
    for(j = kval; j < Size; j++){   
      temp = Array[j];
      (*N_Move)++;
      //num_move++;
      c = j; 
      while(c >= kval && (Array[c - kval] > temp)){
	(*N_Comp)++;
	//num_comp++;
	Array[c] = Array[c - kval];
	(*N_Move)++;
	//num_move++;
	c = c - kval;
      }
      Array[c] = temp;
      (*N_Move)++;
      //num_move++;
    }
  }   
  //*N_Comp = num_comp;
  //*N_Move = num_move;
}

void Shell_Bubble_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move){
  int i = 0; 
  int j = 0;
  int k = 0; 
  int temp = 0; 
  //int num_comp = 0;
  //int num_move = 0;
  int nelements = 0;
  int kval = 0;
  while(pow(2, nelements) < Size){
    nelements++;
  }
  int num[nelements - 1];
  int b = 0;
  int c = 0;
  int d = 0;

  for(i = 1; i < Size; i = i * 2 + 1){
    num[b] = i; 
    b++;
  }
  
  for(k = b - 1; k >= 0; k--){
    kval = num[k];
    for(d = 0; d < Size; d++){
      //for(y = 0; y < Size; y++){
      for(j = kval; j < Size; j++){  
	(*N_Comp)++;
	//num_comp++;
	c = j;
	if(Array[c] < Array[c - kval]){
	  temp = Array[c - kval];
	  (*N_Move)++;
	  //num_move++;
	  Array[c - kval] = Array[c];
	  (*N_Move)++;
	  //num_move++;
	  Array[c] = temp;
	  (*N_Move)++;
	  //num_move++;
	}
      }      
    }
  }
  //*N_Comp = num_comp;
  //*N_Move = num_move;  
}

void Shell_Insertion_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move){
  int j = 0;
  int kval = 0; 
  int k = 0;
  int temp = 0; 
  //int num_comp = 0;
  //int num_move = 0;

  int p = 0;
  int q = 0;
  int bigval = 0;
  int n = log(Size)/log(3);
  int ktotal = ((n+2)*(n+1))/2;
  int two = 0;
  int three = 0;
  int total = 0;
  int seq[ktotal]; 
  int counter = 0;
  int c = 0;

  while(p < n+1){
    q = 0;
    while(q <= bigval){
      two = pow(2, p);
      three = pow(3, q);
      total = two * three; 
      seq[counter] = total;
      p--;
      q++;
      counter++;
    }
    bigval++;
    p = bigval;
  }

  for(k = counter - 1; k >= 0; k--){
    kval = seq[k];
    //printf("%d\n", kval);
    for(j = kval; j < Size; j++){   
      temp = Array[j];
      (*N_Move)++;
      //num_move++;
      c = j; 
      while(c >= kval && (Array[c - kval] > temp)){
	(*N_Comp)++;
	//num_comp++;
	Array[c] = Array[c - kval];
	(*N_Move)++;
	//num_move++;
	c = c - kval;
      }
      Array[c] = temp;
      (*N_Move)++;
      //num_move++;
    }
  }   
  //*N_Comp = num_comp;
  //*N_Move = num_move;
}

void Shell_Bubble_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move){
  int j = 0;
  int kval = 0; 
  int k = 0;
  int temp = 0; 
  //int num_comp = 0;
  //int num_move = 0; 
  int p = 0;
  int q = 0;
  int bigval = 0;
  int n = log(Size)/log(3);
  int ktotal = ((n+2)*(n+1))/2;
  int two = 0;
  int three = 0;
  int total = 0;
  int seq[ktotal]; 
  int counter = 0;
  int c = 0;
  int d = 0;
  
  while(p < n+1){
    q = 0;
    while(q <= bigval){
      two = pow(2, p);
      three = pow(3, q);
      total = two * three; 
      seq[counter] = total;
      p--;
      q++;
      counter++;
    }
    bigval++;
    p = bigval;
  }

  for(k = counter - 1; k >= 0; k--){
    kval = seq[k];
    for(d = 0; d < Size; d++){
      //for(y = 0; y < Size; y++){
      for(j = kval; j < Size; j++){   
	//num_comp++;
	(*N_Comp)++;
	c = j;
	if(Array[c] < Array[c - kval]){
	  temp = Array[c - kval];
	  (*N_Move)++;
	  //num_move++;
	  Array[c - kval] = Array[c];
	  (*N_Move)++;
	  //num_move++;
	  Array[c] = temp;
	  (*N_Move)++;
	  //num_move++;
	}
      }      
    }
  } 
  //*N_Comp = num_comp;
  //*N_Move = num_move;
} 

int Print_Seq_1(char *Filename, int Size){
  FILE *seqfile = fopen(Filename, "w");
  fseek(seqfile, 0, SEEK_SET);
  
  if(seqfile == NULL){
    return EXIT_FAILURE;
  }

  int i = 1;
  int sizeseq = 0;
  for(i = 1; i <= Size; i = i*2+1){
    sizeseq++;
  }
  fprintf(seqfile, "%d\n", sizeseq);
  for(i = 1; i <= Size; i = i*2+1){
    fprintf(seqfile, "%d\n", i);
  }

  fclose(seqfile);
  return sizeseq;
}

int Print_Seq_2(char *Filename, int Size){
  FILE *seqfile = fopen(Filename, "w");
  fseek(seqfile, 0, SEEK_SET);
  int p = 0;
  int q = 0;
  int bigval = 0;
  int n = log(Size)/log(3);
  int ktotal = ((n+2)*(n+1))/2;
  fprintf(seqfile, "%d\n", ktotal);
  int two = 0;
  int three = 0;
  int total = 0;
  
  while(p < n+1){
    q = 0;
    while(q <= bigval){
      two = pow(2, p);
      three = pow(3, q);
      total = two * three; 
      fprintf(seqfile, "%d\n", total);
      p--;
      q++;
    }
    bigval++;
    p = bigval;
  }
  
  fclose(seqfile);
  return ktotal;
}

