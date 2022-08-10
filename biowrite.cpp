#include <openssl/bio.h>
#include <string.h>
int main(int n, char ** s)
{
   char strbio[] = "BIO – Basic Input Output";
   char filename[] = "biotext.txt";
   BIO * out = BIO_new_file(filename, "w");
   if(!out)
      printf("Cannot create file – %s\n", filename);
   else {
      BIO_write(out, strbio, strlen(strbio));
      BIO_free(out);
   }
   return 0;
}
