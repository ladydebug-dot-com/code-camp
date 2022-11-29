#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
int main(int n, char ** s)
{
        char md5hex[EVP_MAX_MD_SIZE * 2 + 1];
        if(n<2)
        {
                printf("Please specify argument string to calculate MD5 checksup\n");
                return -1;
        }
        EVP_MD_CTX    *  pEvpContext;
        pEvpContext = EVP_MD_CTX_create();

        unsigned char   unMdValue[EVP_MAX_MD_SIZE];
        unsigned int    uiMdLength;

        // Initialization
        EVP_MD_CTX_init    ( pEvpContext );
        EVP_DigestInit_ex  ( pEvpContext, EVP_md5(), NULL );

        // Calculate MD5 for given string
        EVP_DigestUpdate   ( pEvpContext, s[1], strlen(s[1]) );

        // Save MD5 into temp variable
        EVP_DigestFinal_ex ( pEvpContext, unMdValue, &uiMdLength );

        EVP_MD_CTX_destroy(pEvpContext);


        // Copy the digest from the temp variable into the return value
        unsigned int md5hexSize = sizeof(md5hex);
        memset(md5hex, '\0', md5hexSize);

        // if the size is bigger than the return buffer size, just exit
        if ( 2*uiMdLength > md5hexSize) {
                return false;
        }

        for ( unsigned int i = 0; i < uiMdLength; i++ )
        {
                sprintf(&md5hex[i*2], "%02x", unMdValue[i] );
        }
        printf("Line: %s\nIts MD5: %s\n", s[1], md5hex);
        return 0;
}

