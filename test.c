#include <stdio.h>
//#include <string.h>
#include <stdint.h>

// Enable both ECB and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -c aes.c -DCBC=0 -DECB=1
#define CBC 1
#define ECB 1

#include "aes.h"


static void phex(uint8_t* str);


int main(void)
{
  uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
  //uint8_t out[] = {0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97}; expected encrpytion result
  uint8_t in[]  = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a};
  uint8_t buffer1[16];
  uint8_t buffer2[16];

  printf("\nUnencrypted input data: ");
  phex(in);

  AES_ECB_encrypt(in, key, buffer1, 16);

  printf("\nECB encrypt data: ");
  phex(buffer1);

  AES_ECB_decrypt(buffer1, key, buffer2, 16);
  printf("\nECB decrypted data: ");
  phex(buffer2);

  return 0;
}

// prints string as hex
static void phex(uint8_t* str)
{

#ifdef AES128
    uint8_t len = 16;
#elif defined(AES192)
    uint8_t len = 24;
#elif defined(AES256)
    uint8_t len = 32;
#endif

    unsigned char i;
    for(i = 0; i < len; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}

