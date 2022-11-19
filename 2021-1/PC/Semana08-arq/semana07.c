#include <stdio.h>
/*int main () {
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("This is tutorialspoint.com", fp);
  
   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Language", fp);
   fclose(fp);
   
   return(0);
}*/
/*
#include <stdio.h>

int main () {
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) {
         break;
      }
      printf("%c", c); 
   }
   fclose(fp);
   return(0);
}*/
/*
int main(){
	FILE * arquivo;
	int i,q;
	
	arquivo = fopen("questao01in.txt","w");
	
	q=0;
	while (fscanf(arquivo,"%d", &i) == 1){
		q++;
		printf("%d ",i);
	}
	printf("\ntotal: %d\n",q);
	fclose(arquivo);
	
	return 0;
}*//*
int main(){
FILE *pFile;
FILE *pFile2;
char buffer[256];

pFile=fopen("myfile.txt", "r");
pFile2=fopen("myfile2.txt", "a");
if(pFile==NULL) {
    perror("Error opening file.");
}
else {
    while(fgets(buffer, sizeof(buffer), pFile)) {
        fprintf(pFile2, "%s", buffer);
    }
}
fclose(pFile);
fclose(pFile2);
return 0;
}
*/

/*
int main(){
	struct __sFILE {
    unsigned char *_p;  /* (*) current position in (some) buffer */
    int _r;     /* (*) read space left for getc() */
    int _w;     /* (*) write space left for putc() */
    short   _flags;     /* (*) flags, below; this FILE is free if 0 */
    short   _file;      /* (*) fileno, if Unix descriptor, else -1 */
    struct  __sbuf _bf; /* (*) the buffer (at least 1 byte, if !NULL) */
    int _lbfsize;   /* (*) 0 or -_bf._size, for inline putc */
/* operations */
void    *_cookie;   /* (*) cookie passed to io functions */
int (*_close)(void *);
int (*_read)(void *, char *, int);
fpos_t  (*_seek)(void *, fpos_t, int);
int (*_write)(void *, const char *, int);

/* separate buffer for long sequences of ungetc() */
struct  __sbuf _ub; /* ungetc buffer */
unsigned char   *_up;   /* saved _p when _p is doing ungetc data */
int _ur;        /* saved _r when _r is counting ungetc data */

/* tricks to meet minimum requirements even when malloc() fails */
unsigned char _ubuf[3]; /* guarantee an ungetc() buffer */
unsigned char _nbuf[1]; /* guarantee a getc() buffer */

/* separate buffer for fgetln() when line crosses buffer boundary */
struct  __sbuf _lb; /* buffer for fgetln() */

/* Unix stdio files get aligned to block boundaries on fseek() */
int _blksize;   /* stat.st_blksize (may be != _bf._size) */
fpos_t  _offset;    /* current lseek offset */

struct pthread_mutex *_fl_mutex;    /* used for MT-safety */
struct pthread *_fl_owner;  /* current owner */
int _fl_count;  /* recursive lock count */
int _orientation;   /* orientation for fwide() */
__mbstate_t _mbstate;   /* multibyte conversion state */
int _flags2;    /* additional flags */
};
typedef struct __sFILE FILE;

return0;	
};
*/
