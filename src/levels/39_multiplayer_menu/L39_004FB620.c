#include "common.h"

/* declared by functions of L39_004F9B38.c, which this file was cut from */
extern void func_L39_004BC6C8(int, int, int, int, int);

/* localdecomp:start func_L39_004FB620 */
/* OpenSSL ASN1_TYPE_free: free the contents, then the object; sibling call j func_004BEF28 = ee-gcc 2.9 library code */
extern void func_L39_004FB668(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004FB620(void *a) {
    if (a != 0) {
        func_L39_004FB668(a);
        func_L39_004BEF28(a);
    }
}
/* localdecomp:end func_L39_004FB620 */
