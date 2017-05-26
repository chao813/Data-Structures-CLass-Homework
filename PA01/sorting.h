#ifndef SORTING_H
#define SORTING_H

long *Load_File(char *Filename, int *Size);
int Save_File(char *Filename, long *Array, int Size);
void Shell_Insertion_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Bubble_Sort_Seq1(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Insertion_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Bubble_Sort_Seq2(long *Array, int Size, double *N_Comp, double *N_Move);
int Print_Seq_1(char *Filename, int Size);
int Print_Seq_2(char *Filename, int Size);


#endif
