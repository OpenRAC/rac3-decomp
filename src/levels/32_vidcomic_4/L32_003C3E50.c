#include "common.h"

typedef struct {
    u8 pad0[0x34];
    s32 f34;
} S_Sub_003C3E50;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    S_Sub_003C3E50 *f68;
} S_Obj_003C3E50;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    s16 f70;
    u8 pad2[4];
    s16 f76;
    u8 pad3[0x1C];
    s32 f94;
    s16 f98;
    u8 pad4[4];
    s16 f9E;
} S_1CCFD0_003C3E50;

/* localdecomp:start func_L32_003C3E50 */
extern S_1CCFD0_003C3E50 D_001CCFD0;
extern void func_L32_003C3EE8(void *);
extern void func_L32_003C3F10(S_Obj_003C3E50 *);
extern void func_L32_003C4000(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L32_003C3E50(S_Obj_003C3E50 *a0) {
    S_Sub_003C3E50 *s1 = a0->f68;

    if (a0->f20 == 0) {
        func_L32_003C3EE8(a0);
        func_L01_004450F0((u8 *)a0, 1, -1);
    }
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0 && s1->f34 == 0) {
        func_L32_003C4000(a0);
    }
    func_L32_003C3F10(a0);
}
/* localdecomp:end func_L32_003C3E50 */

INCLUDE_ASM("asm/levels", func_L32_003C3EE8);

/* localdecomp:start func_L32_003C3F10 */
extern S_1CCFD0_003C3E50 D_001CCFD0;
extern void func_003A1798(void);

void func_L32_003C3F10(S_Obj_003C3E50 *p) {
    S_Sub_003C3E50 *q = p->f68;

    if (D_001CCFD0.f70 >= 7000) {
        if (q->f34 != 0) {
            q->f34 = 0;
        }
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 7000) {
        func_003A1798();
        q->f34 = 0;
    }
}
/* localdecomp:end func_L32_003C3F10 */

INCLUDE_ASM("asm/levels", func_L32_003C3F98);

INCLUDE_ASM("asm/levels", func_L32_003C4000);
