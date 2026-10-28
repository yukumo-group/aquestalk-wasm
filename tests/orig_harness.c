#include <stdio.h>
typedef struct { int bas,spd,vol,pit,acc,lmd,fsc; } V;
extern unsigned char *AquesTalk_Synthe_Utf8(const V*, const char*, int*);
extern void AquesTalk_FreeWave(unsigned char*);
int main(int argc,char**argv){
  V v={0,100,100,100,100,100,100};
  int n=0;
  unsigned char *w=AquesTalk_Synthe_Utf8(&v,argv[1],&n);
  fprintf(stderr,"wav=%p size=%d\n",(void*)w,n);
  if(w) AquesTalk_FreeWave(w);
  return 0;
}
