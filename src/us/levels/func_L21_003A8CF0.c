#include "common.h"

/* NTSC-U counterpart of func_L21_003AA740 (src/levels/21_obani_draco/L21_003AA740.c) */
/* localdecomp:start func_L21_003A8CF0 */
extern s32 func_L01_00452EC8(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00442050(u8 *, u8);
extern s32 func_0037E1D8(s32);
extern s32 func_00388398(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L21_003A90F0(void *);
extern s32 D_L21_001DE150[] __attribute__((section(".sdata")));
__asm__(".extern D_L21_001DE150, 4");
extern s32 D_L21_001D6694_003A8CF0;

typedef struct {
    s32 timer;
    s32 pad4;
    f32 f8;
    s32 count;
    s32 anim;
    f32 f14;
    f32 f18;
} S_003AA740;

typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x31 - 0x21];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    S_003AA740 *p68;
    u8 pad6C[0x96 - 0x6C];
    u16 h96;
    u8 pad98[0xBC - 0x98];
    u8 sub;
} M_003AA740;

void func_L21_003A8CF0(M_003AA740 *m) {
    u8 *a = (u8 *)m;
    S_003AA740 *p = m->p68;
    s32 r;

    switch (m->state) {
    case 0:
        if (func_L01_00452EC8(a) != 0) {
            func_L01_00441FB8(a, func_0037E208(1, 5), -1);
            p->f8 = func_0037E250(0.4f, 0.01f);
            p->timer = 0;
            func_L01_00442050(a, 0);
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            func_L01_00452EC8(a);
        }
        break;
    case 1:
    case 2:
        if (func_L01_00452EC8(a) != 0) {
            p->timer = func_0037E1D8(0x5A);
        }
        if (func_00388398(p) != 0) {
            p->anim = -6;
            p->f18 = 0.81f;
            p->f14 = 0.0f;
        }
        break;
    case 3:
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            p->timer = func_0037E1D8(0x5A);
        }
        if (func_00388398(p) != 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            p->anim = (m->state == 3) ? 0x67 : 0x68;
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            p->timer = func_0037E1D8(0x5A);
            func_L01_00442050(a, 0);
        }
        if (m->sub == 0) {
            if (func_00388398(p) != 0) {
                p->f14 = 0.0f;
                p->f18 = 1.0f;
                p->anim = 0x69;
                p->timer = 0x96;
                p->count = 0;
                func_L01_00442050(a, 1);
            }
        } else if (m->sub == 1) {
            if (func_00388398(p) != 0) {
                p->anim = 0x6A;
                p->timer = 10;
                func_L01_00442050(a, 2);
            }
        } else if (m->sub == 2) {
            if (func_00388398(p) != 0) {
                p->anim = (p->anim == 0x69) ? 0x6A : 0x69;
                p->timer = 10;
                p->count++;
                if (p->count >= 11) {
                    p->anim = 0x6A;
                    p->timer = 0x12C;
                    func_L01_00442050(a, 3);
                }
            }
        } else if (m->sub == 3) {
            if (func_00388398(p) != 0) {
                p->f14 = 0.0f;
                p->f18 = 0.81f;
                p->anim = -6;
                p->timer = 0x258;
                func_L01_00442050(a, 4);
            }
        } else {
            if (func_00388398(p) != 0) {
                func_L01_00441FB8(a, 5, -1);
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
        }
        do {
            r = func_0037E208(0x6B, 0x6D);
        } while (r == p->anim);
        p->f14 = func_0037E250(0.0f, 0.2f);
        p->f18 = func_0037E250(0.8f, 1.0f);
        p->anim = r;
        break;
    case 7:
        if (m->h96 == 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            p->anim = D_L21_001DE150[func_0037E1D8(7)];
            m->h96 = func_0037E1D8(0x28) + 0x28;
        }
        m->h96 -= 1;
        if (D_L21_001D6694_003A8CF0 == 0) {
            func_L01_00441FB8(a, 0, -1);
        }
        break;
    }
    if (m->b31 != 0) {
        func_L01_004026A0(func_L21_003A90F0, a);
    }
}
/* localdecomp:end func_L21_003A8CF0 */
