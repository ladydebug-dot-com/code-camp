#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
int main(int n, char ** s)
{
   char strbio[] = "BIO – Basic Input Output, base64";
   char filename[] = "biotext64.txt";
   BIO * out = BIO_new_file(filename, "w");
   BIO * base64 = BIO_new(BIO_f_base64());
   BIO_push(base64, out);
   if(!out)
      printf("Cannot create file – %s\n", filename);
   else {
      BIO_write(base64, strbio, strlen(strbio));
      BIO_flush(base64);
      BIO_free_all(base64);
   }
   return 0;
}

