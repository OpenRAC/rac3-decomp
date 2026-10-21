#include "common.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

INCLUDE_ASM("asm/levels", func_L08_003A16C8);

INCLUDE_ASM("asm/levels", func_L08_003A17C0);

INCLUDE_ASM("asm/levels", func_L08_003A1BE8);

INCLUDE_ASM("asm/levels", func_L08_003A1FA0);

/* localdecomp:start func_L08_003A3380 */


extern s32 func_L08_003A34C8(S_Moby3A1638 *);
extern s32 func_L01_00452FB0(S_Moby3A1638 *, void *, s32, s32, s32);
extern void func_L02_003A5138_003A3380(S_Moby3A1638 *);
extern s32 func_L01_00452860(S_Moby3A1638 *, void *, s32);
extern void func_L08_003A37A0(S_Moby3A1638 *);
extern void func_L01_00456BD0(S_Moby3A1638 *, s32);
extern void func_L01_00456C98(S_Moby3A1638 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_003A3380(S_Moby3A1638 *m) {
    S_Vars3A1638 *v = m->vars;

    if (m->state == 0) {
        if (func_L08_003A34C8(m) != 0) {
            return 1;
        }
    }
    if (v->b3E == 2) goto special;
    if (func_L01_00452FB0(m, v->v160, 0, 0, 0) != 0) {
        func_L02_003A5138_003A3380(m);
    }
    func_L01_00452860(m, v->v30, 0);
    if (v->b5E != 0) {
special:
        func_L08_003A37A0(m);
        return 1;
    }
    if (v->b5F != 0) {
        func_L01_00456BD0(m, 5);
        func_L01_00456C98(m, v->i304, 0, 0, 0, 0, 3, 0, 0, 0, v->f308, 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(m, 3);
        func_L01_00456C98(m, v->i304, 0, 0, 0, 0, 1, 0, 0, 0, v->f308, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L08_003A3380 */

INCLUDE_ASM("asm/levels", func_L08_003A34C8);

INCLUDE_ASM("asm/levels", func_L08_003A37A0);

/* localdecomp:start func_L08_003A3B20 */

extern u8 D_L08_001E1D40[];

extern void func_0038CAD0(void *p);
extern void func_0038CB00(void *p);
extern void func_L01_00451DF8(void *moby, void *p, s32 a, s32 b, f32 f);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_L01_004472C0(void *moby);

void func_L08_003A3B20(Moby_3A1DD8 *moby) {
    u8 *pvars = *(u8 **)((u8 *)moby + 104);
    func_0038CAD0(pvars + 780);
    func_0038CB00(pvars + 796);
    if (moby->h150 < 0xFFFF) {
        moby->h150++;
    }
    func_L01_00451DF8(moby, pvars + 576, 3, 1, 2.5f);
    if (moby->b49 != 0) {
        if (func_L01_0040E548(D_L08_001E1D40, moby->pos) < 1024.0f) {
            func_L01_004472C0(moby);
            moby->b111 = 30;
        }
    }
}
/* localdecomp:end func_L08_003A3B20 */
