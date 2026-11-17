#include "common.h"

/* localdecomp:start func_L21_003AA740 */
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00445188(u8 *, u8);
extern s32 func_00382468(s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L21_003AABA0(void *);
extern s32 D_L21_001DE120[] __attribute__((section(".sdata")));
__asm__(".extern D_L21_001DE120, 4");
extern s32 D_L21_001D6694;

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

void func_L21_003AA740(M_003AA740 *m) {
    u8 *a = (u8 *)m;
    S_003AA740 *p = m->p68;
    s32 r;

    switch (m->state) {
    case 0:
        if (func_L01_004561B8(a) != 0) {
            func_L01_004450F0(a, func_00382498(1, 5), -1);
            p->f8 = func_003824E0(0.4f, 0.01f);
            p->timer = 0;
            func_L01_00445188(a, 0);
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            func_L01_004561B8(a);
        }
        break;
    case 1:
    case 2:
        if (func_L01_004561B8(a) != 0) {
            p->timer = (func_00382468(0x5A) * 5 + 2) / 6;
        }
        if (func_0038CAD0(p) != 0) {
            p->anim = -6;
            p->f18 = 0.81f;
            p->f14 = 0.0f;
        }
        break;
    case 3:
    case 4:
        if (func_L01_004561B8(a) != 0) {
            p->timer = (func_00382468(0x5A) * 5 + 2) / 6;
        }
        if (func_0038CAD0(p) != 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            p->anim = (m->state == 3) ? 0x67 : 0x68;
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            p->timer = (func_00382468(0x5A) * 5 + 2) / 6;
            func_L01_00445188(a, 0);
        }
        if (m->sub == 0) {
            if (func_0038CAD0(p) != 0) {
                p->f14 = 0.0f;
                p->f18 = 1.0f;
                p->anim = 0x69;
                p->timer = 0x7D;
                p->count = 0;
                func_L01_00445188(a, 1);
            }
        } else if (m->sub == 1) {
            if (func_0038CAD0(p) != 0) {
                p->anim = 0x6A;
                p->timer = 8;
                func_L01_00445188(a, 2);
            }
        } else if (m->sub == 2) {
            if (func_0038CAD0(p) != 0) {
                p->anim = (p->anim == 0x69) ? 0x6A : 0x69;
                p->timer = 8;
                p->count++;
                if (p->count >= 11) {
                    p->anim = 0x6A;
                    p->timer = 0xFA;
                    func_L01_00445188(a, 3);
                }
            }
        } else if (m->sub == 3) {
            if (func_0038CAD0(p) != 0) {
                p->f14 = 0.0f;
                p->f18 = 0.81f;
                p->anim = -6;
                p->timer = 0x1F4;
                func_L01_00445188(a, 4);
            }
        } else {
            if (func_0038CAD0(p) != 0) {
                func_L01_004450F0(a, 5, -1);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
        }
        do {
            r = func_00382498(0x6B, 0x6D);
        } while (r == p->anim);
        p->f14 = func_003824E0(0.0f, 0.2f);
        p->f18 = func_003824E0(0.8f, 1.0f);
        p->anim = r;
        break;
    case 7:
        if (m->h96 == 0) {
            p->f14 = 0.0f;
            p->f18 = 1.0f;
            p->anim = D_L21_001DE120[func_00382468(7)];
            m->h96 = ((func_00382468(0x28) + 0x28) * 5 + 2) / 6;
        }
        m->h96 -= 1;
        if (D_L21_001D6694 == 0) {
            func_L01_004450F0(a, 0, -1);
        }
        break;
    }
    if (m->b31 != 0) {
        func_L01_00404A10(func_L21_003AABA0, a);
    }
}
/* localdecomp:end func_L21_003AA740 */
