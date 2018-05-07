#include <stdio.h>
#include <stdlib.h>

#define PERM(x,y) {int t = (x); (x) = (y); (y) = t; }

int heap[1000000], size = 0;

void heapify() {
   int i = size-1;
   while(1) {
      int m = (i-1)/2;
      if(heap[m] < heap[i]) PERM(heap[m], heap[i]);
      if(!(i = m)) break;
   }
}

void insert(int v) {
   heap[size++] = v;
   heapify();
}

void remove_max() {
   size--;
   PERM(heap[0], heap[size]);
   int i=0;
   while(1) {
      int m1 = 2*i + 1;
      int m2 = 2*i + 2;
      int v1 = -1, v2 = -1;
      int res;
      
      if(m1 < size) { v1 = heap[m1]; }
      if(m2 < size) { v2 = heap[m2]; }
      if(v1 < 0 && v2 < 0) break;
      
      if(v1 > v2) res = m1;
      else res = m2;
      
      if(heap[i] > heap[res]) break;
      PERM(heap[i], heap[res]);
      
      i = res;
   }
}

int get_max() { return size ? heap[0] : -1; } // -1 significa que nao ha elemento

int elems[17] = {1, 2, 6, 4, 9, 10, 14, 16, 13, 12, 8, 20, 17, 3, 5, 11, 25};

int main() {
   for(int i=0; i<17; i++) insert(elems[i]);
   while(size) {
      printf("MAX: %d\n", get_max());
      printf("agora removendo o max...\n");
      remove_max();
   }
   return 0;
}