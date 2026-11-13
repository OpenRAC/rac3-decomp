#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005FF958);

/* localdecomp:start func_L39_005FFB48 */
typedef int u128_t __attribute__((mode(TI)));

void func_L39_005FFB48(u128_t *dst, u128_t *src) {
    *dst = *src;
}
/* localdecomp:end func_L39_005FFB48 */

LINKER_REMNANT("asm/levels", func_L39_005FFB58);

/* localdecomp:start func_L39_005FFB60 */
/* the file already declares u128_t (above func_L39_005FFB48); the candidate's own typedef clashed */
void func_L39_005FFB60(u128_t *dst, u128_t *src) {
    *dst = *src;
}
/* localdecomp:end func_L39_005FFB60 */
