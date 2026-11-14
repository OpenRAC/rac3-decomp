#include "common.h"

/* localdecomp:start func_L39_004BEE70 */
/* OpenSSL 0.9.4's CRYPTO_set_mem_functions (mem.c: malloc_locked_func 0046489C, free_locked_func 004648A0,
   malloc_func 004648A4, realloc_func 004648A8, free_func 004648AC) */
extern char *(*D_L39_0046489C)(void) __attribute__((section(".data")));
extern void (*D_L39_004648A0)(void) __attribute__((section(".data")));
extern char *(*D_L39_004648A4)(void) __attribute__((section(".data")));
extern char *(*D_L39_004648A8[4])(void);
extern void (*D_L39_004648AC)(void) __attribute__((section(".data")));

void func_L39_004BEE70(char *(*m)(void), char *(*r)(void), void (*f)(void)) {
    if (m == 0 || r == 0 || f == 0) {
        return;
    }
    D_L39_004648A4 = m;
    D_L39_004648A8[0] = r;
    D_L39_004648AC = f;
    D_L39_0046489C = m;
    D_L39_004648A0 = f;
}
/* localdecomp:end func_L39_004BEE70 */

LINKER_REMNANT("asm/levels", func_L39_004BEEC8);

/* localdecomp:start func_L39_004BEED8 */
extern char *(*D_L39_004648A4)(void) __attribute__((section(".data")));

/* from rac2-decomp's func_00120420 */
char *func_L39_004BEED8(void) {
    return D_L39_004648A4();
}
/* localdecomp:end func_L39_004BEED8 */

/* localdecomp:start func_L39_004BEF00 */
extern char *(*D_L39_004648A8[4])(void);
/* from rac2-decomp's func_00120420 */
char *func_L39_004BEF00(void) {
    return D_L39_004648A8[0]();
}
/* localdecomp:end func_L39_004BEF00 */

INCLUDE_ASM("asm/levels", func_L39_004BEF28);

LINKER_REMNANT("asm/levels", func_L39_004BEF50);
