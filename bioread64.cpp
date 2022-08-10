#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
int main(int n, char ** s)
{
   char strbio[256];
   char filename[] = "biotext64.txt";
   memset(strbio, 0, 256);
   BIO * in = BIO_new_file(filename, "r");
   BIO_METHOD* bm = BIO_f_base64();
   BIO * base64 = BIO_new(bm);
   BIO_push(base64, in);
   if(!in)
      printf("Cannot open file – %s\n", filename);
   else {
      BIO_read(base64, strbio, sizeof(strbio));
      BIO_free_all(base64);
      printf("%s\n", strbio);
   }
   return 0;
}

