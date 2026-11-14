#include "common.h"
#include "vu0.h"

typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x150];
    q128 unk150;
    char pad160[0x190 - 0x160];
    q128 unk190;
    char pad1A0[0x300 - 0x1A0];
    q128 unk300;
    char pad310[0x940 - 0x310];
    q128 unk940;
} Vars;

typedef struct {
    char pad0[0x10];
    q128 pos;
    char pad20[0x34 - 0x20];
    u16 flags;
    char pad36[0x68 - 0x36];
    Vars *vars;
    char pad6C[0xA8 - 0x6C];
    u8 unkA8;
    char padA9[0xAA - 0xA9];
    s16 oClass;
} Moby;

/* localdecomp:start func_L03_0034A2C0 */
extern void func_L01_004450F0(Moby *, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L03_0034A4B8(void *, s32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 D_001A4C60[];
__asm__(".extern D_L03_001DF4C0, 4");
extern s32 D_L03_001DF4C0;
__asm__(".extern D_L03_001DD610, 4");
extern s32 D_L03_001DD610;

void func_L03_0034A2C0(u8 *m) {
    u8 *v;
    f32 k;
    s32 c;

    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        *(s32 *)(v + 0x24) = 0;
        *(f32 *)(m + 0x14) = *(f32 *)(D_001A4C60 + 4);
        func_L01_004450F0((Moby *)m, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0((Moby *)m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (D_L03_001DF4C0 >= 0x1F) {
                func_003A52A0(0, 0, m);
            }
            func_L03_0034A4B8(m + 0x10, 10);
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
        }
        break;
    case 3:
        *(s32 *)(m + 0x48) = 0;
        k = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)(v + 0x2C), (f32)*(s32 *)(v + 0x28), 1.0f);
        m[0x23] = (s32)((1.0f - k) * 128.0f);
        if (D_L03_001DD610 != 0) {
            *(u16 *)(m + 0x34) |= 8;
        } else {
            *(u16 *)(m + 0x34) &= ~8;
        }
        *(f32 *)(m + 0x2C) = func_003C4088(*(f32 *)(v + 0x1C), *(f32 *)(v + 0x20), k);
        c = func_0038DBD8(*(s32 *)(v + 0x18), *(s32 *)(v + 0x14), k);
        vec_add_ab(m + 0x10, m + 0x10, v);
        func_L01_0043B9E8(m, c & 0xFF, (c >> 8) & 0xFF, (c >> 16) & 0xFF);
        if (func_0038CAD0(v + 0x2C) != 0) {
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L03_0034A2C0 */

INCLUDE_ASM("asm/levels", func_L03_0034A4B8);

/* localdecomp:start func_L03_0034A760 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
void func_L03_0034A760(u8 *a0) {
    u8 *p = func_L01_00447490(a0, 0x10000, 0);
    if (p != 0) {
        u8 *q = *(u8 **)(p + 32);
        if (q != 0) {
            s16 t = *(s16 *)(q + 170);
            if (t == 208 || t == 2085) {
                a0[188] = 1;
            }
        }
    }
    a0[168] = 255;
}
/* localdecomp:end func_L03_0034A760 */

LINKER_REMNANT("asm/levels", func_L03_0034A7C8);

INCLUDE_ASM("asm/levels", func_L03_0034A7D8);

/* localdecomp:start func_L03_0034AB60 */
extern void func_L01_004450F0(Moby *, s32, s32);
extern void func_L03_0034AF98(u8 *);
extern void func_L03_0034B008(u8 *);
extern void func_L03_0034AC40(u8 *);
extern u8 D_001426E0[];

void func_L03_0034AB60(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        func_L03_0034AF98(a0);
        break;
    case 1:
        if (D_001426E0[0xDB] == 1) {
            func_L01_004450F0((Moby *)a0, 2, -1);
        }
        if (D_001426E0[0xDB] == 2) {
            func_L01_004450F0((Moby *)a0, 3, -1);
        }
        break;
    case 2:
        func_L03_0034B008(a0);
        break;
    case 3:
        func_L03_0034AC40(a0);
        break;
    }
}
/* localdecomp:end func_L03_0034AB60 */

INCLUDE_ASM("asm/levels", func_L03_0034AC40);

/* localdecomp:start func_L03_0034AE68 */
typedef struct {
    u8 pad[32];
    u8 type;
    u8 pad2[223];
} E_0034A2A8;
extern E_0034A2A8 *D_L03_001DF99C;
s32 func_L03_0034AE68(u8 *a0, s32 a1) {
    s32 *q = (s32 *)(*(u8 **)(a0 + 104) + 16);
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (q[i] != -1) {
            u8 t = D_L03_001DF99C[q[i]].type;
            if (t != 3 && (a1 == 0 || t != 2)) {
                count++;
            }
        }
    }
    return count;
}
/* localdecomp:end func_L03_0034AE68 */

/* localdecomp:start func_L03_0034AED8 */
extern void func_L01_004450F0(Moby *, s32, s32);

void func_L03_0034AED8(void *arg0, Moby *m) {
    if (arg0 == 0 || m == 0) {
        return;
    }
    if (m->oClass == 7003) {
        m->pos = m->vars->unk940;
    }
    if (m->oClass == 7062) {
        m->pos = m->vars->unk150;
    }
    if (m->oClass == 7063) {
        m->pos = m->vars->unk300;
    }
    if (m->oClass == 7066) {
        m->pos = m->vars->unk190;
    }
    m->unkA8 = 255;
    m->flags &= ~2;
    func_L01_004450F0(m, 0, -1);
}
/* localdecomp:end func_L03_0034AED8 */
