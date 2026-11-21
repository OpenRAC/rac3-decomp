#include "common.h"

/* NTSC-U counterpart of func_L12_003D4B18 (src/levels/shared/L12_003D4B18.c) */
/* localdecomp:start func_L12_003D2EB0 */
#include "vu0.h"

extern f32 D_L12_001DEF90_003D2EB0;
__asm__(".extern D_L12_001DEF90_003D2EB0, 4");
extern f32 D_L12_001DEF94_003D2EB0;
__asm__(".extern D_L12_001DEF94_003D2EB0, 4");
extern f32 D_L12_001DEF98_003D2EB0;
__asm__(".extern D_L12_001DEF98_003D2EB0, 4");
extern f32 D_L12_001DEF9C_003D2EB0;
__asm__(".extern D_L12_001DEF9C_003D2EB0, 4");
extern f32 D_L12_001DEFA0_003D2EB0;
__asm__(".extern D_L12_001DEFA0_003D2EB0, 4");
extern f32 D_L12_001DEFA4;
__asm__(".extern D_L12_001DEFA4, 4");
extern f32 D_L12_001DEFA8;
__asm__(".extern D_L12_001DEFA8, 4");
extern f32 D_L12_001DEFB0_003D2EB0;
__asm__(".extern D_L12_001DEFB0_003D2EB0, 4");
extern f32 D_L12_001DEFC4_003D2EB0;
__asm__(".extern D_L12_001DEFC4_003D2EB0, 4");
extern f32 D_L12_001DEFD0_003D2EB0;
__asm__(".extern D_L12_001DEFD0_003D2EB0, 4");
extern u8 D_001A30B0[];
typedef struct {
    u8 pad_0000[0x19E0];
    u8 *target;
} Hero_003D4B18;
extern Hero_003D4B18 D_001A4BE0;
extern u8 D_L12_001E2800[];
extern u8 *D_L12_001EA7D8[];
extern u8 *D_L12_001EE840[];

extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L12_003D46D0(u8 *, u8 *);
extern void func_L12_003D3DA0(u8 *, u8 *);
extern void func_L12_003D38C0(u8 *, u8 *);
extern void func_L12_003D3578(u8 *, u8 *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(f32, void *, s32, u8 *);
extern s32 func_00388398(void *);
extern s32 func_003CF790(void *, s32, f32, void *, s32);
extern void func_L01_00443840(void *, void *);
extern s32 func_L01_0032FE90_003D2EB0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern s32 func_L01_0046CA58(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);

static __inline__ s32 hit_003D4B18(u8 *from, vu0_v4 *to, u8 *ignore) {
    s32 hit;
    u8 *o2;

    func_L01_004C76B8();
    hit = func_003CE740(from, to, 0, ignore, 0);
    if (hit != 0) {
        o2 = D_L12_001EA7D8[0];
        if (o2 != 0 && *(s16 *)(o2 + 0xAA) == 0x186D) {
            if (o2[0x20] != 2 && o2[0x20] != 5) {
                o2[0x20] = 4;
            }
        }
    }
    func_L01_004C76F0();
    return hit;
}

void func_L12_003D2EB0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    vu0_v4 v90;
    vu0_v4 vA0;
    u8 blk[0x30];
    vu0_v4 vE0;
    f32 lim;
    f32 cur;
    f32 nw;
    s32 id;
    s32 id2;
    s32 cnt;
    s32 k;
    s32 hit;
    u8 *e;
    u8 *e2;
    u8 *tgt;

    if (obj[0x20] == 4) {
        id = *(s32 *)(s + 0x3C);
        if (id != -1) {
            e = D_001A30B0 + (id << 7);
            if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) {
                func_0039FB08(id);
            }
        }
        *(s32 *)(s + 0x3C) = -1;
        func_L12_003D46D0(obj, s);
        return;
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L12_001E2800, obj + 0x10) < 576.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x16;
        }
    }
    if (func_L01_00444358(obj, 0x10000, 0) != 0) {
        obj[0xA8] = 0xFF;
        func_L12_003D3DA0(obj, s);
        return;
    }
    id2 = *(s32 *)(s + 0x3C);
    if (id2 == -1 || (e2 = D_001A30B0 + (id2 << 7), *(u8 **)(e2 + 0xDC) != obj) || e2[0xD0] == 0) {
        *(s32 *)(s + 0x3C) = func_0039FE80(0, 4, obj);
    }
    if (obj[0x20] == 2) {
        lim = D_L12_001DEFC4_003D2EB0;
    } else if (obj[0x20] == 3) {
        lim = D_L12_001DEFD0_003D2EB0;
    } else {
        lim = D_L12_001DEF90_003D2EB0;
    }
    cur = *(f32 *)(s + 0x38);
    if (cur < lim) {
        nw = cur + D_L12_001DEF94_003D2EB0;
        *(f32 *)(s + 0x38) = nw;
        if (lim < nw) {
            *(f32 *)(s + 0x38) = lim;
        }
    } else if (lim < cur) {
        nw = cur - D_L12_001DEF98_003D2EB0;
        *(f32 *)(s + 0x38) = nw;
        if (nw < lim) {
            *(f32 *)(s + 0x38) = lim;
        }
    }
    if (*(u16 *)(obj + 0xB2) & 1) {
        *(f32 *)(obj + 0xF0) = func_00389380(*(f32 *)(obj + 0xF0), D_L12_001DEFB0_003D2EB0);
    } else {
        *(f32 *)(obj + 0xF0) = func_003893C8(*(f32 *)(obj + 0xF0), D_L12_001DEFB0_003D2EB0);
    }
    func_L12_003D38C0(obj, s);
    vec_add_ba(&v90, obj + 0x10, s);
    tgt = D_001A4BE0.target;
    if (tgt != 0 && *(s16 *)(tgt + 0xAA) == 0x107E) {
        func_00388830(&vA0, obj + 0xC0, D_L12_001DEF9C_003D2EB0 * 0.25f);
    } else {
        func_00388830(&vA0, obj + 0xC0, D_L12_001DEF9C_003D2EB0);
    }
    vec_add_ab(&vA0, &vA0, &v90);
    func_L01_00443628(blk, *(u8 **)(obj + 0xB8), 1, s, *(f32 *)(s + 0x20));
    *(u16 *)(blk + 0x1A) = *(u16 *)(obj + 0xAA);
    blk[0x18] = 3;
    *(s32 *)(obj + 0x98) = 0;
    hit = hit_003D4B18(obj + 0x10, &vA0, *(u8 **)(obj + 0xB8));
    if (hit != 0 ||
        ((u32)(obj[0x20] - 2) >= 2 && func_L01_003F9498(D_L12_001DEF9C_003D2EB0, &vA0, 1, *(u8 **)(obj + 0xB8)) != 0) ||
        func_00388398(s + 0x24) != 0) {
        cnt = func_003CF790(&v90, 0x11, D_L12_001DEFA0_003D2EB0, *(u8 **)(obj + 0xB8), 0);
        for (k = 0; k < cnt; k++) {
            if (!(D_L12_001DEFA4 < fabs_asm(*(f32 *)(D_L12_001EE840[k] + 0x18) - v90.z + D_L12_001DEFA8))) {
                func_L01_00443840(D_L12_001EE840[k], blk);
            }
        }
        tgt = D_001A4BE0.target;
        if (tgt != 0 && *(s16 *)(tgt + 0xAA) == 0x107E) {
            func_L01_0032FE90_003D2EB0(obj + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.625f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(obj);
        } else {
            func_L12_003D3DA0(obj, s);
        }
        return;
    }
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    if (*(s32 *)(s + 0x2C) == 0) {
        qzero(&vE0);
        vE0.x = -1.2f;
        *(s32 *)(s + 0x2C) = func_L01_0046CA58(&vE0, obj, 0x7F20407F, -1, 1, -1, 0, *(s16 *)(obj + 0x32),
                                               315000.0f, 0.6f, 1.0f, 0, 0);
    }
    func_L12_003D3578(obj, s, &v90);
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)&v90;
}
/* localdecomp:end func_L12_003D2EB0 */
