#include <openssl/bio.h>
#include <string.h>
int main(int n, char ** s)
{
   char strbio[256];
   char filename[] = "biotext.txt";
   memset(strbio, 0, 256);
   BIO * in = BIO_new_file(filename, "r");
   if(!in)
      printf("Cannot open file – %s\n", filename);
   else {
      BIO_read(in, strbio, sizeof(strbio));
      BIO_free(in);
      printf("%s\n", strbio);
   }
   return 0;
}

