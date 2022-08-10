#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
int main(int n, char ** s)
{
   // size of key and iv must be 256 bit for aes256
   unsigned char key[32];
   unsigned char iv[32];
   memset(key, 'k', 32);
   memset(iv, 'i', 32);
   char strbio[] = "BIO – Basic Input Output, crypto";
   char filename[] = "biotextcrypt.txt";
   BIO * out = BIO_new_file(filename, "w");
   BIO * cipher = BIO_new(BIO_f_cipher());
   BIO_set_cipher(cipher, EVP_aes_256_cbc(), key, iv, 1);
   BIO_push(cipher, out);
   if(!out)
      printf("Cannot create file – %s\n", filename);
   else {
      BIO_write(cipher, strbio, strlen(strbio));
      BIO_flush(cipher);
      BIO_free_all(cipher);
   }
   return 0;
}
