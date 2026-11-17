/* near miss (level 13: 99 diff, needs @ps2as) */
#include "common.h"

/* localdecomp:start func_L13_003B70E8 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} P_3B70E8;
typedef struct {
    char _p0[0x20];
    u8 f20;
    char _p21[0x68 - 0x21];
    P_3B70E8 *f68;
    char _p6C[0xB0 - 0x6C];
    u8 fB0;
} M_3B70E8;
typedef struct {
    char _p0[0x30];
    u8 f30;
} T_3B70E8;

extern s32 D_L13_001D6694 __attribute__((section(".data")));
extern s32 D_L13_001D6690 __attribute__((section(".data")));
extern u8 D_00142C44;
extern s32 D_001D545C;
extern char *D_L13_001DF59C __attribute__((section(".data")));
extern char *D_L13_001DF680 __attribute__((section(".data")));
extern u8 D_001BBC40[];
extern s16 D_001A7464;
extern u8 D_00142713;
extern void func_L01_00456230(void *, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0039EF28(void);

void func_L13_003B70E8(M_3B70E8 *m) {
    P_3B70E8 *p = m->f68;
    s32 st;

    if ((u32)(D_L13_001D6694 - 1) < 2) {
        return;
    }
    switch (D_L13_001D6690) {
    case 1:
    case 2:
        return;
    }
    st = m->f20;
    switch (st) {
    case 0:
        if (!((unsigned long)D_00142C44 >> 7)) {
            T_3B70E8 *t = (T_3B70E8 *)(D_L13_001DF59C + (p->f0 << 8));
            t->f30 = 0xFF;
            func_L01_00456230(t, 1);
        }
        if (D_001BBC40[m->fB0 + (D_001D545C << 4)] & 0x80) {
            char *e = D_L13_001DF680 + (p->f8 << 7);
            func_L01_004F50C8(e + 0x30, e + 0x70, 0, 1);
            func_L01_004450F0(m, 2, -1);
        } else {
            D_001A7464 = 1;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (D_001BBC40[m->fB0 + (D_001D545C << 4)] & 0x80) {
            T_3B70E8 *t = (T_3B70E8 *)(D_L13_001DF59C + (p->f4 << 8));
            func_L01_00456230(t, 1);
            t->f30 = 0xFF;
            D_001A7464 = 0;
            D_00142713 = st;
            func_0039EF28();
            func_L01_004450F0(m, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L13_003B70E8 */
