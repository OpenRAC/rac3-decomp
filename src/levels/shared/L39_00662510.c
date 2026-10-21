#include "common.h"

/* localdecomp:start func_L39_00662510 */
extern u8 D_L39_0047AA10[];
void *func_L39_00662510(u8 *p) {
    *(void **)(p + 20) = D_L39_0047AA10;
    return p;
}
/* localdecomp:end func_L39_00662510 */

/* localdecomp:start func_L39_00662528 */
typedef struct S_65FC50 S_65FC50;

struct S_65FC50 {
    u8 pad[88];
    S_65FC50 *next;
};

extern S_65FC50 D_L39_0030C400[];
extern S_65FC50 *D_L39_001DAAE0;
extern void func_L39_00662A48(S_65FC50 *);

void func_L39_00662528(void) {
    s32 i;

    for (i = 0; i < 192; i++) {
        func_L39_00662A48(&D_L39_0030C400[i]);
    }
    for (i = 190; i >= 0; i--) {
        D_L39_0030C400[i].next = &D_L39_0030C400[i + 1];
    }
    D_L39_001DAAE0 = D_L39_0030C400;
}
/* localdecomp:end func_L39_00662528 */

INCLUDE_ASM("asm/levels", func_L39_006625A8);
