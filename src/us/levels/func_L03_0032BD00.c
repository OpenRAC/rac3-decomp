#include "common.h"

/* NTSC-U counterpart of func_L03_0032C3A8 (src/levels/03_starship_phoenix/L03_0032C3A8.c) */
typedef struct Ext_0032C3A8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x60 - 0x1C];
    s32 q60[8];
    u8 pad2[0xCC - 0x80];
    s32 fCC;
    u8 pad3[0xDC - 0xD0];
    s32 fDC;
    u8 pad4[0xEC - 0xE0];
    u8 bEC[4];
    u8 bF0;
    u8 bF1;
    u16 hF2;
    u8 bF4;
    u8 pad5;
    u8 bF6;
    u8 pad6;
    s32 fF8;
    u8 pad7[0x104 - 0xFC];
    s32 f104;
} Ext_0032C3A8;
typedef struct Act_0032C3A8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x20 - 0x1C];
    u8 b20;
    u8 pad2[0x68 - 0x21];
    Ext_0032C3A8 *p68;
    u8 pad3[0x100 - 0x6C];
} Act_0032C3A8;
typedef struct Ent_0032C3A8 {
    s16 h0;
    u8 pad2[2];
    u32 *p4;
    u8 b8;
    u8 pad9[0x28 - 9];
} Ent_0032C3A8;
typedef struct Glob_0032C3A8 {
    u8 pad[0x2824];
    f32 f2824;
    u8 pad1[0x2850 - 0x2828];
    s32 f2850;
} Glob_0032C3A8;

/* localdecomp:start func_L03_0032BD00 */
extern f32 D_L03_001DF350;
extern Act_0032C3A8 *D_L03_001DFA1C;
__asm__(".extern D_L03_001DD14A, 1");
extern u8 D_L03_001DD14A;
extern Ent_0032C3A8 D_L03_002AE550[];
extern Glob_0032C3A8 D_001A4BE0[];
extern s32 D_00142660[];
extern u8 D_L03_00235A90[];
extern u8 D_001BBB30[];

extern void func_L03_0032C270(Act_0032C3A8 *);
extern void func_L03_0032C530(Act_0032C3A8 *);
extern void func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(Act_0032C3A8 *, s32, s32);
extern s32 func_003883C8(void *);
extern s32 func_00388398(void *);
extern void func_L03_0032FC00(Act_0032C3A8 *);
extern void func_L03_0032E218(Act_0032C3A8 *, s32);
extern void func_L03_0032E240(Act_0032C3A8 *);
extern void func_L03_0032E470(Act_0032C3A8 *);
extern s32 func_L03_0032E978(Act_0032C3A8 *);
extern s32 func_L03_00398640(void *);
extern s32 func_L03_0032CC18(Act_0032C3A8 *);
extern void func_L03_0032D8A0(Act_0032C3A8 *);
extern void func_L03_0032FCB0(Act_0032C3A8 *);
extern s32 func_L03_0032E030(Act_0032C3A8 *, s32);
extern void func_L03_0032CB68(Act_0032C3A8 *);
extern void func_L01_00402768(void *, void *);
extern void func_L03_0032FE60(void);
extern void func_0039FB08(s32);
extern void func_L03_0032E530(Act_0032C3A8 *);
extern void func_L03_0032EE50(void);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_004563F8(s32, s32);
extern s32 func_L01_004335E8(s32);
extern s32 func_L01_00452EC8(Act_0032C3A8 *);
extern void func_L03_0032C828(Act_0032C3A8 *);
extern void func_L03_003A0388(void *, s32);

void func_L03_0032BD00(Act_0032C3A8 *self) {
    Ext_0032C3A8 *p;
    f32 f;
    s32 ok;
    s32 z;
    Act_0032C3A8 *g;

    func_L03_0032C270(self);
    func_L03_0032C530(self);
    p = self->p68;
    switch (self->b20) {
    case 2:
        D_L03_001DF350 = D_L03_001DF350 - 0.1f;
        if (D_L03_001DF350 <= 0.0f) {
            func_0039BEC0(3, 1, 0x11, 0, 0);
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 4:
        if (func_003883C8(&p->hF2)) {
            func_L03_0032FC00(self);
            func_L01_00441FB8(self, 5, -1);
        }
        break;
    case 5: {
        s32 i = p->bF1;
        s32 j = p->bF0 << 2;
        Ent_0032C3A8 *e = &D_L03_002AE550[i];
        func_L03_0032E218(self, *((u8 *)e->p4 + j));
        func_L03_0032E240(self);
        if (e->b8) {
            func_L03_0032E470(self);
        }
        func_L01_00441FB8(self, 6, -1);
        break;
    }
    case 6: {
        s32 i;
        z = func_L03_0032E978(self) == 0;
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (!func_L03_00398640((u8 *)D_L03_001DFA1C + (p->q60[i] << 8))) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            func_L03_0032CC18(self);
            if (z) {
                func_L01_00441FB8(self, 7, -1);
            }
        }
        break;
    }
    case 7:
        func_L03_0032D8A0(self);
        if (func_L03_0032CC18(self) == 0) {
            func_L01_00441FB8(self, 8, -1);
        }
        break;
    case 8: {
        s32 i = p->bF1;
        s32 j = p->bF0;
        Ent_0032C3A8 *e = &D_L03_002AE550[i];
        if (j < e->h0 - 1) {
            p->fF8 = 0;
            p->bF0 = j + 1;
            func_L03_0032FCB0(self);
            func_L01_00441FB8(self, 5, -1);
        } else {
            p->bF4 = 1;
            if (func_L03_0032E030(self, p->bF1)) {
                func_L01_00441FB8(self, 10, -1);
            } else {
                func_L03_0032CB68(self);
            }
        }
        break;
    }
    case 9:
        D_001A4BE0[0].f2824 = 200.0f;
        func_L01_00402768(func_L03_0032FE60, self);
        if (func_00388398(&p->bEC)) {
            if (p->f104 != -1) {
                func_0039FB08(p->f104);
                p->f104 = -1;
            }
        }
        if (func_003883C8(&p->hF2)) {
            D_001A4BE0[0].f2850 = D_00142660[2];
            func_L03_0032E530(self);
            if (p->bF1 > 8) {
                func_L03_0032EE50();
                if (D_L03_001DD14A) {
                    func_L01_00441FB8(self, 11, -1);
                } else {
                    func_L01_004F12C0(D_L03_00235A90, D_L03_00235A90 + 0x10, 0, 1);
                    func_L01_004563F8(0, 0);
                    func_L01_00441FB8(self, 1, -1);
                }
            } else {
                func_L01_00441FB8(self, 11, -1);
            }
            D_001A4BE0[0].f2850 = D_00142660[2];
        }
        break;
    case 10:
        if (D_001BBB30[0]) {
            if (func_L01_004335E8(0) == 0) {
                func_L03_0032CB68(self);
            }
        } else {
            if (func_L01_00452EC8(self)) {
                p->bF6 = 0;
            }
            func_L03_0032E978(self);
            g = &D_L03_001DFA1C[p->fDC];
            f = self->f18;
            if (g->f18 - f > 1.0f) {
                g->p68->f18 = f * 0.01f + g->p68->f18 * 0.99f;
            }
        }
        break;
    case 11:
        D_L03_001DF350 = D_L03_001DF350 + 0.1f;
        if (1.0f <= D_L03_001DF350) {
            D_L03_001DF350 = 1.0f;
            func_L01_004563F8(0, 0);
            func_L03_0032C828(self);
        }
        break;
    case 12:
        D_L03_001DF350 = D_L03_001DF350 + 0.1f;
        if (1.0f <= D_L03_001DF350) {
            D_L03_001DF350 = 1.0f;
            func_L03_003A0388(D_L03_001DFA1C + *(s32 *)((u8 *)p + 0xCC), 0);
            func_L01_00441FB8(self, 1, -1);
        }
        break;
    case 1:
    case 3:
    case 13:
    default:
        break;
    }
}
/* localdecomp:end func_L03_0032BD00 */
