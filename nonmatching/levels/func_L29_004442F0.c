/* near miss (level 29: 50 diff, moby pool allocator) */
#include "common.h"

/* localdecomp:start func_L29_004442F0 */
typedef struct {
    char _p0[0x20];
    u8 f20;
    char _p21[0x68 - 0x21];
    void *f68;
    char _p6C[0xA0 - 0x6C];
    u32 fA0;
    char _pA4[0x100 - 0xA4];
} M_4442F0;

extern M_4442F0 *D_L29_001DFB20 __attribute__((section(".data")));
extern M_4442F0 *D_L29_001DFB24 __attribute__((section(".data")));
extern u32 D_L29_001DF6C0 __attribute__((section(".data")));
extern s32 D_L29_001DFA40 __attribute__((section(".data")));
extern u8 D_L29_001D8058;
extern void *func_003C7310(void *);
extern void func_003C25D8(void *, void *);
extern void func_0038CB78(void *, s32, void *);
extern void func_003C38E0(void);

M_4442F0 *func_L29_004442F0(void *a0, void *a1) {
    M_4442F0 *m;
    M_4442F0 *end = D_L29_001DFB24;
    void *r;

    m = D_L29_001DFB20;
    if (m < end) {
        do {
            if (m->f20 < 0xFE) {
                m++;
                continue;
            }
            if (m->fA0 > D_L29_001DF6C0) {
                m++;
                continue;
            }
            r = 0;
            if (a1 != 0) {
                r = func_003C7310(a1);
            }
            if (r == 0 && a1 != 0) {
                break;
            }
            if (m->f20 == 0xFF) {
                *((u8 *)m + 0x120) = m->f20;
            }
            func_003C25D8(m, a0);
            m->f68 = r;
            if (a1 != 0) {
                func_0038CB78(r, 0, a1);
            }
            if (D_L29_001DFA40 != 0) {
                D_L29_001DFA40--;
            }
            return m;
        } while (m < end);
    }
    if (D_L29_001D8058 != 0) {
        func_003C38E0();
    }
    return 0;
}
/* localdecomp:end func_L29_004442F0 */
