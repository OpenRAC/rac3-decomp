#include "common.h"

/* NTSC-U counterpart of func_L35_003A3D10 (src/levels/35_vidcomic_5/L35_003A3D10.c) */
extern s32 func_0037E208(s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L35_003A2460(u8 *);

/* localdecomp:start func_L35_003A2460 */
#include "vu0.h"

extern s32 func_0037E208(s32, s32);
extern void func_003BDA38(void *, s32, void *);

extern f32 func_L30_0034BB18(void *);
extern u8 *D_L35_001DFA00;

typedef struct {
    s32 a;
    s32 b;
    f32 da;
    f32 db;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
} E_003A3D10;

void func_L35_003A2460(u8 *m) {
    u8 *v;
    E_003A3D10 *e;
    vu0_v4 d;

    v = *(u8 **)(m + 0x68);
    if (*(s32 *)(v + 0x184) != 0) {
        *(s32 *)(v + 0x180) = func_0037E208(0, *(s32 *)(v + 0x188) - 1);
    } else {
        *(s32 *)(v + 0x180) = (*(s32 *)(v + 0x180) + 1) % *(s32 *)(v + 0x188);
    }
    e = (E_003A3D10 *)(v + 0x100) + *(s32 *)(v + 0x180);
    if (e->f1C != 2) {
        func_003BDA38(m, 2, &d);
        vec_sub_ba(&d, D_L35_001DFA00 + e->a * 128 + 0x30, &d);
        e->da = func_L30_0034BB18(&d);
        func_003BDA38(m, 2, &d);
        vec_sub_ba(&d, D_L35_001DFA00 + e->b * 128 + 0x30, &d);
        e->db = func_L30_0034BB18(&d);
    }
    *(s32 *)(v + 0x19C) = e->f18;
}
/* localdecomp:end func_L35_003A2460 */
