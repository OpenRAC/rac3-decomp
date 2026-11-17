#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

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

/* localdecomp:start func_L03_0032C3A8 */
extern f32 D_L03_001DF2D0;
extern Act_0032C3A8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DD10A, 1");
extern u8 D_L03_001DD10A;
extern Ent_0032C3A8 D_L03_002AE4D0[];
extern Glob_0032C3A8 D_1A4BE0[];
extern s32 D_142660[];
extern u8 D_L03_00235A10[];
extern u8 D_001BBB30[];

extern void func_L03_0032C918(Act_0032C3A8 *);
extern void func_L03_0032CBD8(Act_0032C3A8 *);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L01_004450F0(Act_0032C3A8 *, s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_L03_003302D0(Act_0032C3A8 *);
extern void func_L03_0032E8D8(Act_0032C3A8 *, s32);
extern void func_L03_0032E900(Act_0032C3A8 *);
extern void func_L03_0032EB30(Act_0032C3A8 *);
extern s32 func_L03_0032F038(Act_0032C3A8 *);
extern s32 func_L03_00399D20(void *);
extern s32 func_L03_0032D2D8(Act_0032C3A8 *);
extern void func_L03_0032DF60(Act_0032C3A8 *);
extern void func_L03_00330380(Act_0032C3A8 *);
extern s32 func_L03_0032E6F0(Act_0032C3A8 *, s32);
extern void func_L03_0032D228(Act_0032C3A8 *);
extern void func_L01_00404AD8(void *, void *);
extern void func_L03_00330530(void);
extern void func_003A4F28(s32);
extern void func_L03_0032EBF0(Act_0032C3A8 *);
extern void func_L03_0032F520(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004596E8(s32, s32);
extern s32 func_L01_00436620(s32);
extern s32 func_L01_004561B8(Act_0032C3A8 *);
extern void func_L03_0032CED0(Act_0032C3A8 *);
extern void func_L03_003A1B70(void *, s32);

void func_L03_0032C3A8(Act_0032C3A8 *self) {
    Ext_0032C3A8 *p;
    f32 f;
    s32 ok;
    s32 z;
    Act_0032C3A8 *g;

    func_L03_0032C918(self);
    func_L03_0032CBD8(self);
    p = self->p68;
    switch (self->b20) {
    case 2:
        D_L03_001DF2D0 = D_L03_001DF2D0 - 0.1200000048f;
        if (D_L03_001DF2D0 <= 0.0f) {
            func_003A0EC0(3, 1, 0x11, 0, 0);
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 4:
        if (func_0038CB00(&p->hF2)) {
            func_L03_003302D0(self);
            func_L01_004450F0(self, 5, -1);
        }
        break;
    case 5: {
        s32 i = p->bF1;
        s32 j = p->bF0 << 2;
        Ent_0032C3A8 *e = &D_L03_002AE4D0[i];
        func_L03_0032E8D8(self, *((u8 *)e->p4 + j));
        func_L03_0032E900(self);
        if (e->b8) {
            func_L03_0032EB30(self);
        }
        func_L01_004450F0(self, 6, -1);
        break;
    }
    case 6: {
        s32 i;
        z = func_L03_0032F038(self) == 0;
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (!func_L03_00399D20((u8 *)D_L03_001DF99C + (p->q60[i] << 8))) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            func_L03_0032D2D8(self);
            if (z) {
                func_L01_004450F0(self, 7, -1);
            }
        }
        break;
    }
    case 7:
        func_L03_0032DF60(self);
        if (func_L03_0032D2D8(self) == 0) {
            func_L01_004450F0(self, 8, -1);
        }
        break;
    case 8: {
        s32 i = p->bF1;
        s32 j = p->bF0;
        Ent_0032C3A8 *e = &D_L03_002AE4D0[i];
        if (j < e->h0 - 1) {
            p->fF8 = 0;
            p->bF0 = j + 1;
            func_L03_00330380(self);
            func_L01_004450F0(self, 5, -1);
        } else {
            p->bF4 = 1;
            if (func_L03_0032E6F0(self, p->bF1)) {
                func_L01_004450F0(self, 10, -1);
            } else {
                func_L03_0032D228(self);
            }
        }
        break;
    }
    case 9:
        D_1A4BE0[0].f2824 = 200.0f;
        func_L01_00404AD8(func_L03_00330530, self);
        if (func_0038CAD0(&p->bEC)) {
            if (p->f104 != -1) {
                func_003A4F28(p->f104);
                p->f104 = -1;
            }
        }
        if (func_0038CB00(&p->hF2)) {
            D_1A4BE0[0].f2850 = D_142660[2];
            func_L03_0032EBF0(self);
            if (p->bF1 > 8) {
                func_L03_0032F520();
                if (D_L03_001DD10A) {
                    func_L01_004450F0(self, 11, -1);
                } else {
                    func_L01_004F50C8(D_L03_00235A10, D_L03_00235A10 + 0x10, 0, 1);
                    func_L01_004596E8(0, 0);
                    func_L01_004450F0(self, 1, -1);
                }
            } else {
                func_L01_004450F0(self, 11, -1);
            }
            D_1A4BE0[0].f2850 = D_142660[2];
        }
        break;
    case 10:
        if (D_001BBB30[0]) {
            if (func_L01_00436620(0) == 0) {
                func_L03_0032D228(self);
            }
        } else {
            if (func_L01_004561B8(self)) {
                p->bF6 = 0;
            }
            func_L03_0032F038(self);
            g = &D_L03_001DF99C[p->fDC];
            f = self->f18;
            if (g->f18 - f > 1.0f) {
                g->p68->f18 = f * 0.01f + g->p68->f18 * 0.99f;
            }
        }
        break;
    case 11:
        D_L03_001DF2D0 = D_L03_001DF2D0 + 0.1200000048f;
        if (1.0f <= D_L03_001DF2D0) {
            D_L03_001DF2D0 = 1.0f;
            func_L01_004596E8(0, 0);
            func_L03_0032CED0(self);
        }
        break;
    case 12:
        D_L03_001DF2D0 = D_L03_001DF2D0 + 0.1200000048f;
        if (1.0f <= D_L03_001DF2D0) {
            D_L03_001DF2D0 = 1.0f;
            func_L03_003A1B70(D_L03_001DF99C + *(s32 *)((u8 *)p + 0xCC), 0);
            func_L01_004450F0(self, 1, -1);
        }
        break;
    case 1:
    case 3:
    case 13:
    default:
        break;
    }
}
/* localdecomp:end func_L03_0032C3A8 */
