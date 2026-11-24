#include "common.h"

/* NTSC-U counterpart of func_L20_003FA478. */

/* localdecomp:start func_L20_003F8218 */
#include "vu0.h"
typedef struct {
    u8 p0[0x30];
    f32 f30;
    u8 p34[0x1EC];
    vu0_v4 v220;
    u8 p230[4];
    s16 h234;
    u8 p236[10];
    s32 w240;
    u8 p244[0x9C];
    s32 w2E0;
    u8 p2E4[2];
    s16 h2E6;
    s32 w2E8;
    u8 *p2EC;
    s32 w2F0;
    s32 w2F4;
    s32 w2F8;
    u8 p2FC[4];
    vu0_v4 v300;
    u8 p310[4];
    s32 w314;
} S_3FA478;
extern s32 func_L20_003F8A48(u8 *);
extern void func_003BD360(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_003883C8(void *);
extern void func_L20_003F9018(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00407180(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern void func_L20_003F8E90(void *);
/* The four floats follow the first argument in the prototype: arguments are evaluated and
   moved in parameter order, and this puts retail's f12 move and constant registers where they are. */
extern s32 func_L01_0032FE90(u8 *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_0043C598(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_L06_00357C38(void *, void *, void *, s32, f32, f32);
extern u8 *func_L01_00467DA8(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);
extern void func_L01_00457440(void *, void *);
extern s32 func_L01_00453210(void *, s32);
extern void func_L20_003F8EF0(void *);
/* the sdata attribute makes gcc emit the address as one `la` (lui and addiu adjacent) */
extern u8 D_L20_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L20_001DFD40;
__asm__(".extern D_L20_001DEC2C, 4");
__asm__(".extern D_L20_001DEC30, 4");
extern s32 D_L20_001DEC2C;
extern s32 D_L20_001DEC30;

void func_L20_003F8218(u8 *obj) {
    S_3FA478 *s;
    vu0_v4 d;
    vu0_v4 w;
    u8 v[0x30];
    vu0_v4 e;
    s32 hit;
    s32 r;
    f32 f;
    f32 one;
    u8 *vp;
    vu0_v4 *ep;

    s = *(S_3FA478 **)(obj + 0x68);
    r = func_L20_003F8A48(obj);
    if (r != 0) {
        goto L225;
    }
    if (D_L20_001DEC2C == 0) {
        return;
    }
    if (D_L20_001DEC30 != 0) {
        func_003BD360(s->p2EC);
        s->w240 = 0;
        goto L225;
    }
    hit = 1;
    switch (obj[0x95]) {
    case 0:
        if (func_L01_00452EF0(obj) != 0) {
            s->h2E6 = func_0037E208(0, 0x1E);
        }
        if (s->h234 == 1) {
            if (func_003883C8(&s->h2E6) != 0) {
                func_L20_003F9018(obj, 1, 0, 10);
                func_L01_00441FB8(obj, 3, 2);
                if (s->w2F8 == 0) {
                    goto Lpost;
                }
                func_L01_00407180(obj, obj + 0x10, obj + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                func_L01_00407180(s->p2EC, s->p2EC + 0x10, s->p2EC + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                goto Lpost;
            }
        }
        if (s->w2E8 == 0) {
            goto Lpost;
        }
        if (func_003883C8(&s->h2E6) == 0) {
            goto Lpost;
        }
        func_L01_00441FB8(obj, 2, 1);
        s->w2E8 = 0;
        if (!(s->w2E0 < 0x12C)) {
            goto Lpost;
        }
        s->w2E0 = func_0037E208(0x1E0, 0x258);
        goto Lpost;
    case 1:
        if (s->h234 == 1) {
            goto L244;
        }
        if (s->w2E0 != 0) {
            goto Lpost;
        }
        func_L01_00441FB8(obj, 1, 0);
        goto Lpost;
    case 2:
        if (s->h234 == 1) {
            goto Lpost;
        }
        if (func_L01_00452EF0(obj) != 0) {
            goto Lpost;
        }
        goto L249;
    case 3:
        r = func_L01_00451078(obj, (u8 *)s + 0x160);
        if ((r & 1) == 0) {
            if (!(s->f30 <= 0.0f)) {
                goto L229;
            }
        }
        one = 1.0f;
        func_L20_003F8E90(obj);
        func_L01_0032FE90(obj + 0x10, one, 0.0f, 0.0f, 2.0f, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L03_0043C598((s32)obj, 0x7FFF, D_L20_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, one);
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) >= 2) {
            func_L01_00452E70(func_003BCFB0(0x1E09, 0x80), obj);
        }
L225:
        func_003BD360(obj);
        return;
L229:
        if ((r & 2) == 0) {
            goto Lpost;
        }
        if (s->h234 != 1) {
            goto L249;
        }
        func_L20_003F9018(obj, 0x14, 0, 10);
        func_003BE4F0(s->p2EC, 0xB, 0, 10);
L244:
        func_L01_00441FB8(obj, 4, 2);
        goto Lpost;
L249:
        func_L01_00441FB8(obj, 2, 1);
        s->w2E0 = func_0037E208(0x244, 0x258);
        goto Lpost;
    default:
        break;
    }
Lpost:
    if (s->p2EC[0x42] == 0xB) {
        if ((D_L20_001DFD40 & 3) == (((s32)obj >> 8) & 3)) {
            *(vu0_q *)&d = *(vu0_q *)&s->v300;
            *(vu0_q *)&w = *(vu0_q *)&s->v220;
            func_003BEB58(&s->v300, &d, &w, 0.075f);
            vp = v;
            func_003BD9A0(s->p2EC, s->w2F4, vp);
            vec_sub_ab(&d, &s->v300, &e);
            func_00388830(&d, &d, 0.58333337f);
            ep = &e;
            f = func_003887A0(vp);
            func_L06_00357C38(obj, ep, &d, 3, -func_00388A28(f, *(f32 *)(v + 8)), 10.0f);
            func_L01_00467DA8((f32 *)ep, 4.0f, 10, 5.0f, 0.0f, 0x5F005F00, 0, 2, (f32 *)D_L20_001D66B0, 0);
            s->w2F4 = s->w2F4 + 1;
            if (s->w2F4 >= 6) {
                s->w2F4 = 0;
            }
        }
        s->w2F0 = s->w2F0 + 1;
        if (s->w2F0 >= 0xF1) {
            func_003BE4F0(s->p2EC, 0x11, 0, 10);
        }
    }
    if (s->p2EC[0x42] == 0x11) {
        s->w2F0 = 0;
        if (s->p2EC[0x60] & 2) {
            *(vu0_q *)&s->v300 = *(vu0_q *)&s->v220;
            vec_sub_ab(&d, &s->v300, obj + 0x10);
            d.z = 0.0f;
            func_00388830(&d, &d, -8.0f);
            vec_add_ab(&s->v300, &s->v300, &d);
            func_003BE4F0(s->p2EC, 0xB, 0, 0xF);
        }
    }
    switch (obj[0x20]) {
    case 1:
    case 2:
        break;
    case 3:
        if ((obj[0x60] & 2) == 0) {
            goto Lend;
        }
        func_L20_003F9018(obj, 0x14, 0, 10);
        func_003BE4F0(s->p2EC, 0xB, 0, 10);
        func_L01_00441FB8(obj, 4, -1);
        break;
    case 4:
        if (func_L01_00452EC8(obj) != 0) {
            *(vu0_q *)&s->v300 = *(vu0_q *)&s->v220;
            vec_sub_ab(&d, &s->v300, obj + 0x10);
            d.z = 0.0f;
            func_00388830(&d, &d, -8.0f);
            vec_add_ab(&s->v300, &s->v300, &d);
        }
        if (obj[0x42] == 5) {
            func_L01_00457440(obj, (u8 *)s + 0x220);
        }
        hit = 1;
        if (s->w314 != -1) {
            if (func_L01_00453210((u8 *)s + 0x220, s->w314) != 0) {
                hit = 0;
            }
        }
        if (hit == 0) {
            goto L474;
        }
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) < 2) {
            goto L474;
        }
        if (!(func_00388800(obj + 0x10, (u8 *)s + 0x220) < 15.0f)) {
            goto L482;
        }
        if (!(func_00389468(*(f32 *)(obj + 0xF8), func_00388A28(s->v220.x - *(f32 *)(obj + 0x10), s->v220.y - *(f32 *)(obj + 0x14))) < 0.08726646f)) {
            goto L482;
        }
L474:
        if (obj[0x43] == 2) {
            goto L482;
        }
        func_003BE4F0(obj, 2, 0, 10);
L482:
        if (hit == 0) {
            goto L500;
        }
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) < 2) {
            goto L500;
        }
        if (20.0f < func_00388800(obj + 0x10, (u8 *)s + 0x220)) {
            goto L517;
        }
L500:
        if (!(0.7853982f < func_00389468(*(f32 *)(obj + 0xF8), func_00388A28(s->v220.x - *(f32 *)(obj + 0x10), s->v220.y - *(f32 *)(obj + 0x14))))) {
            goto Lend;
        }
L517:
        if (obj[0x43] == 5) {
            goto Lend;
        }
        func_003BE4F0(obj, 5, 0, 10);
        break;
    case 5:
        break;
    }
Lend:
    func_L20_003F8EF0(obj);
}
/* localdecomp:end func_L20_003F8218 */
