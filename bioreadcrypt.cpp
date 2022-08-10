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
   char strbio[256];
   memset(strbio, 0, 256);
   char filename[] = "biotextcrypt.txt";
   BIO * in = BIO_new_file(filename, "r");
   BIO * cipher = BIO_new(BIO_f_cipher());
   BIO_set_cipher(cipher, EVP_aes_256_cbc(), key, iv, 0);
   BIO_push(cipher, in);
   if(!in)
      printf("Open file – %s\n", filename);
   else {
      BIO_read(cipher, strbio, sizeof(strbio));
      BIO_free_all(cipher);
      printf("%s\n", strbio);
   }
   return 0;
}

