/* near miss (level 29: 5 diff, register swap and the jr delay slot) */
#include "common.h"

/* localdecomp:start func_L29_00520050 */
typedef struct {
    char _p0[0x50];
    s32 zero[35];
    char _pDC[0x1C4 - 0xDC];
    char f1C4[0x21CC - 0x1C4];
    char f21CC[0x41DC - 0x21CC];
} O_520050;

extern O_520050 D_L29_00258B80[];
extern s32 D_L29_001E1020;
extern void func_L29_0051FFB0(void);
extern void func_003E6670(void *);
extern void func_00116FD0(void (*)(void));

O_520050 *func_L29_00520050(s32 idx) {
    O_520050 *o;
    O_520050 *next;
    s32 i;
    s32 j;

    if (D_L29_001E1020 == 0) {
        o = D_L29_00258B80;
        i = 4;
        do {
            next = o + 1;
            j = 0x22;
            do {
                o->zero[0x22 - j] = 0;
            } while (--j != -1);
            func_003E6670(o->f1C4);
            func_003E6670(o->f21CC);
            o = next;
        } while (--i != -1);
        D_L29_001E1020 = 1;
        func_00116FD0(func_L29_0051FFB0);
    }
    return &D_L29_00258B80[idx];
}
/* localdecomp:end func_L29_00520050 */
