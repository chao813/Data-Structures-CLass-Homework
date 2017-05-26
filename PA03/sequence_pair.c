#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "sequence_pair.h"

int main(int argc, char *argv[]){
  FILE *inputfile = fopen(argv[1], "r");
  fseek(inputfile, 0, SEEK_SET);
  int nblocks = 0;
  fscanf(inputfile, "%d", &nblocks);
  Node *list = malloc(sizeof(Node) * nblocks);
  Nrect *array = malloc(sizeof(Nrect) * nblocks);

  int seq1[nblocks];
  int seq2[nblocks];
  int seq3[nblocks];
  int temp[nblocks];
  int i = 0;
  for(i = 0; i < nblocks; i++){
    fscanf(inputfile, "%d %lf %lf", &(array[i].numval), &(array[i].width), &(array[i].height));
  }
  for(i = 0; i < nblocks; i++){
    fscanf(inputfile, "%d", &(seq1[i]));
  }
  for(i = 0; i < nblocks; i++){
    temp[i] = seq1[i];
  }
  for(i = 0; i < nblocks; i++){
    fscanf(inputfile, "%d", &(seq2[i]));
  }

  Node nlist[nblocks];
  i = 0;
  while(i < nblocks){
    list[i].rect = &(array[seq1[i]-1]);
    i++;
  }
  int j = 0;
  //int k = 0;
  for(i = 0; i < nblocks; i++){
    for(j = 0; j < nblocks; j++){
      if((list[j].rect)->numval == seq2[i]){
	break;
      }
    }
    seq3[i] = j; 
    nlist[i].rect = list[j].rect;
    nlist[i].numval = seq2[i];
  }
  double maxh = 0;
  double fheight = 0;
  int source = 1;
  int tail = 1;
  i = 0;
  while(i < nblocks){
    if(seq3[0] < seq3[i]){
      source = 0;
    }
    if(seq3[i] < seq3[nblocks - 1]){
      tail = 0;
    }
    i++;
  }
  if(source == 1){
    maxh = (nlist[0].rect)->height;
  }
  else if(tail == 1){
    fheight = (nlist[nblocks - 1].rect)->height;
  }
    
  i = 0;
  int n_blocks = nblocks;
  if(tail != 0){
    n_blocks = nblocks - 1;
  }
  if(source != 0){
    i = 1;
  }
  int l, m = 0;

  double max_h = 0;
  double h = maxh;
  double width[n_blocks];
  double max_w = 0;
  double total_w = 0;
  Index indexs[nblocks + 1];

  while(i < n_blocks){ 
    if((source == 1) && (i == 1)){
      max_w = (nlist[0].rect)->width;
      indexs[nlist[0].numval -1].Xcord = 0;
      indexs[nlist[0].numval -1].Ycord = 0;
      indexs[nlist[0].numval -1].rect = nlist[0].rect;
    }
    if((tail == 1) && (i == 1)){
      if((nlist[nblocks - 1].rect)->width > max_w){
	max_w = (nlist[nblocks -1].rect)->width;
      }
    }
    while(l < n_blocks){ 
      indexs[nlist[i].numval -1].Xcord = total_w;
      indexs[nlist[i].numval -1].Ycord = maxh;
      indexs[nlist[i].numval -1].numval = i;
      indexs[nlist[i].numval -1].rect = nlist[i].rect;
      maxh = maxh + (nlist[i].rect)->height;
      if((nlist[i].rect)->width > max_w){
	max_w = (nlist[i].rect)->width;
      }
      i++;
      if(i == n_blocks){
	break;
      }
      if(seq3[i] > seq3[i-1]){
	break;
      }
      l++;
    }
    if((tail == 1)){
      maxh = maxh + fheight;
    }
    if(max_h < maxh){
      max_h = maxh;
    }
    width[m++] = max_w;
    total_w = total_w + max_w;
    if((tail != 0)){
      indexs[nlist[nblocks-1].numval-1].Xcord = 0;
      indexs[nlist[nblocks-1].numval-1].Ycord = max_h - fheight;
      indexs[nlist[nblocks-1].numval-1].rect = nlist[nblocks-1].rect;
    } 
    l = 0;
    max_w = 0;
    maxh = h;
  } 
  FILE *outputfile = fopen(argv[2], "w");
  fseek(outputfile, 0, SEEK_SET);
  fprintf(outputfile, "%d\n", nblocks);
  printf("Width: %le\nHeight: %le\nX-coordinate: %le\nY-coordinate: %le\n", total_w, max_h, indexs[i].Xcord, indexs[i].Ycord);
  for(i = 0; i < nblocks; i++){
    fprintf(outputfile, "%d %le %le %le %le\n", i+1, indexs[i].rect->width, indexs[i].rect->height, indexs[i].Xcord, indexs[i].Ycord);
  }

  fclose(inputfile);
  fclose(outputfile);
  free(list);
  free(array);
  return 0;
}

Node *createGraph(Node *node, int *seq1, int *seq2, int nblocks){
  int x = 0;
  int first = seq1[x];
  int rightnums[nblocks - 1];
  int rightnumss[nblocks -1];
  int h = 0;
  int i = 0;
  int y = 0;
  int z = 0;
  int w = 0;
  int p = 0;
  for(h = 0; h < nblocks - 1; h++){
    rightnums[h] = seq1[h + 1];
  }

  for(i = 0; i < nblocks; i++){
    if(seq2[i] == first){
      p = i;
      for(y = 0; y < nblocks - i; y++){
	rightnumss[y] = seq2[p];
	p++;
      }
    }
   }
  
  for(z = 0; z < nblocks - 1; z++){
    for(w = 0; w < p; w++){
      if(rightnums[z] == rightnumss[w]){
	rightnums[z] = rightnumss[w];
      }
    }
  }
  return node;
}


/*Node *Load_Sequence_File(char *Filename){
  FILE *inputfile = fopen(Filename, "r");
  fseek(inputfile, 0, SEEK_SET);

  int nblocks = 0; //specify number of rectangles
  fscanf(inputfile, "%d", &nblocks);

  int *seq1 = malloc(sizeof(int) * nblocks);
  int *seq2 = malloc(sizeof(int) * nblocks);
  //double *array = malloc(sizeof(double) * (nblocks * 3));
  double array[nblocks * 3];
  
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  for(i = 0; i < nblocks * 3; i++){
    fscanf(inputfile, "%lf", &(array[i]));
  }

  for(j = 0; j < nblocks; j++){
    fscanf(inputfile, "%d", &(seq1[j]));
  }
  for(k = 0; k < nblocks; k++){
    fscanf(inputfile, "%d", &(seq2[k]));
  }

  int m = 1;
  Node *node = createNodes(0,0,0);

  for(l = 0; l < nblocks; l++){
    node->numval = array[m-1];
    node->width = array[m];
    node->height = array[m+1];
    m = m + 3;
    printf("int=%lf, width=%lf, height=%lf", node->numval, node->width, node->height);
    node = node->next;
  }

  fclose(inputfile);
  return node;
  }*/
