#include "common.h"

typedef struct S_003B4630_1 { u8 p0[0x1C]; s32 f1C; } S_003B4630_1;
typedef struct S_003B4630_0 { u8 p0[0x20]; u8 f20; u8 p21[0x47]; S_003B4630_1 *f68; } S_003B4630_0;
typedef struct S_1CCFD0_003B4630 { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[0x24]; s32 f94; } S_1CCFD0_003B4630;

typedef struct {
    u8 pad0[0x70];
    s16 h70;
    u8 pad72[4];
    s16 h76;
    u8 pad78[0x98 - 0x78];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} S_1CCFD0_003B46E0;

extern s32 func_003A1798(void);

/* localdecomp:start func_L31_003B4630 */
extern S_1CCFD0_003B4630 D_001CCFD0;
extern void func_L31_003B46C8();
extern void func_L01_004450F0(S_003B4630_0 *, s32, s32);
extern void func_L31_003B4768(S_003B4630_0 *);
extern void func_L31_003B46E0(S_003B4630_0 *);

void func_L31_003B4630(S_003B4630_0 *p) {
    S_003B4630_1 *q = p->f68;
    S_1CCFD0_003B4630 *g;

    if (p->f20 == 0) {
        func_L31_003B46C8();
        func_L01_004450F0(p, 1, -1);
    }
    g = &D_001CCFD0;
    if (g->f6C == 0 && g->f24 == -1 && g->f94 == 0 && q->f1C == 0) {
        func_L31_003B4768(p);
    }
    func_L31_003B46E0(p);
}
/* localdecomp:end func_L31_003B4630 */

/* localdecomp:start func_L31_003B46C8 */
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[4]; s32 f18; } S_003B46C8_1;
typedef struct { u8 p0[0x30]; u8 f30; u8 p31[0x37]; S_003B46C8_1 *f68; } S_003B46C8_0;
void func_L31_003B46C8(S_003B46C8_0 *a0) {
    S_003B46C8_1 *p = a0->f68;
    a0->f30 = 0xFF;
    p->f18 = 0;
    p->f10 = 0;
}
/* localdecomp:end func_L31_003B46C8 */

/* localdecomp:start func_L31_003B46E0 */
void func_L31_003B46E0(S_003B4630_0 *a0) {
    S_003B4630_1 *p = a0->f68;

    if ((*(S_1CCFD0_003B46E0 *)&D_001CCFD0).h70 >= 7000) {
        if (p->f1C != 0) {
            p->f1C = 0;
        }
    }
    if ((*(S_1CCFD0_003B46E0 *)&D_001CCFD0).h76 == 0 && (*(S_1CCFD0_003B46E0 *)&D_001CCFD0).h9E == 3 && (*(S_1CCFD0_003B46E0 *)&D_001CCFD0).h98 < 7000) {
        func_003A1798();
        p->f1C = 0;
    }
}
/* localdecomp:end func_L31_003B46E0 */

/* localdecomp:start func_L31_003B4768 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} S_003B4768;
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad1[0x1B04 - 0x90];
    s32 f1B04;
    u8 pad2[0x1B38 - 0x1B08];
    u32 f1B38;
} S_Hero_003B4768;
typedef struct { u8 p0[0x30]; f32 f30; u8 p34[0x80 - 0x34]; } S_Row_003B4768;
extern S_Hero_003B4768 D_001A4BE0;
extern s32 D_L31_001DF340; __asm__(".extern D_L31_001DF340, 16");
extern S_Row_003B4768 *D_L31_001DF880; __asm__(".extern D_L31_001DF880, 16");
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(s32, s32);

void func_L31_003B4768(S_003B4630_0 *m) {
    S_003B4768 *s = (S_003B4768 *)m->f68;

    if (D_001A4BE0.f1B04 != 0 && !(D_001A4BE0.f1B38 & 2)) {
        D_001A4BE0.f1B38 |= 2;
        if (D_L31_001DF340 >= 0xB) {
            func_003A2B68((s->f4 & 0x3FFF) + 0x7D0, 0);
            s->f1C = 1;
            return;
        }
    }
    if (s->f24 != -1) {
        if ((func_00382380(D_001A4BE0.pos, s->f24, 0) != 0 || D_L31_001DF880[s->f24].f30 < D_001A4BE0.pos[0]) &&
            (((u8)D_001A4BE0.f1B38 ^ 1) & 1) && s->f18 == 0) {
            s->f18 = 1;
            if (D_L31_001DF340 >= 0xB) {
                func_003A2B68((s->f0 & 0x3FFF) + 0x7D0, 0);
                s->f1C = 1;
                return;
            }
        }
    }
    if (s->f20 != -1) {
        if (func_00382380(D_001A4BE0.pos, s->f20, 0) != 0 || D_L31_001DF880[s->f20].f30 < D_001A4BE0.pos[0]) {
            if (s->f10 == 0) {
                s->f10 = 1;
                func_003A2B68((s->f8 & 0x3FFF) + 0x7D0, 0);
                s->f1C = 1;
            }
        }
    }
}
/* localdecomp:end func_L31_003B4768 */
