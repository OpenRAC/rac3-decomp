#include "common.h"

/* NTSC-U counterpart of func_L24_00358860 (src/levels/24_insomniac_museum/L24_00356100.c) */
#include "vu0.h"
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L24_00357828 */
#include "vu0.h"
typedef struct { u8 pad[0x50]; f32 f50; u8 pad2[0x9C]; } T_358860;
__asm__(".extern D_L24_001DF51C_00357828, 4");
extern u8 *D_L24_001DF51C_00357828;
extern s32 D_L24_001DF0C0_00357828;
extern u8 D_001425C0[];
extern T_358860 D_L24_002C3580[];
extern u8 D_001A4C60[];
extern void func_L01_004479A8(void *, void *);
extern u8 *func_L01_00444358(void *, s32, s32);
extern s32 func_003883C8(void *);
extern f32 func_L01_004443B0(void *, void *);
extern void func_L01_00452B20(void *, void *, void *);
extern f32 func_L01_0044DE78(void *, void *, s32);
extern void func_L01_0044DDC8(void *, void *, void *, s32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern s32 func_L24_00356F38(void *, void *, void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

s32 func_L24_00357828(u8 *obj, u8 *r, s32 flag) {
    s32 lvl = 0;
    u8 *s;
    u8 *h;
    u8 *t21;
    u8 *hit;
    f32 dmg;
    f32 base;
    f32 hp;
    s32 thr;
    f32 dir[4];

    if (!(*(u16 *)(obj + 0x34) & 0x20)) {
        return 0;
    }
    s = *(u8 **)(obj + 0x68);
    h = *(u8 **)s;
    t21 = *(u8 **)(s + 0x20);
    if (r == 0) {
        return 0;
    }
    if (h == 0) {
        return 0;
    }
    func_L01_004479A8(obj, r);
    base = 0.0f;
    hit = func_L01_00444358(obj, 0x10000, 0);
    if (func_003883C8(h + 6) == 0) {
        hit = 0;
    }
    if (hit != 0) {
        base = *(f32 *)(hit + 0x2C);
        if (*(f32 *)(r + 0xA8) != 0.0f && *(u8 **)(hit + 0x20) != 0
            && *(s16 *)(obj + 0xAA) == *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA)) {
            *(f32 *)(hit + 0x2C) = base * *(f32 *)(r + 0xA8);
        }
        if (flag != 0) {
            *(f32 *)(hit + 0x2C) = *(f32 *)(hit + 0x2C) * *(f32 *)(r + 0xAC);
        }
    }
    dmg = func_L01_004443B0(obj, hit);
    obj[0xA8] = 0xFF;
    *(f32 *)h = *(f32 *)h - dmg;
    if (t21 != 0) {
        func_L01_00452B20(obj, t21, h);
    }
    if ((flag == 0 || hit == 0) && dmg == 0.0f) {
        return 0;
    }
    *(s16 *)(r + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(r + 0x70) = (*(u8 **)(hit + 0x20) - D_L24_001DF51C_00357828) >> 8;
    }
    {
        s32 ix = h[0x17];
        f32 k = ((T_358860 *)(D_001425C0[ix] * 0xF0 + (u8 *)D_L24_002C3580))->f50;
        thr = 300;
        hp = (f32)*(s16 *)(h + 4) * *(f32 *)(r + 0x58);
        if (hp <= dmg * k) {
            thr = 90;
        }
    }
    if (r[0x77] == 0 && thr < abs_asm(D_L24_001DF0C0_00357828 - *(s32 *)(r + 0x44)) && dmg < hp) {
        dmg = hp;
    }
    if (*(f32 *)h <= 0.0f) {
        lvl = 4;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x5C) <= dmg) {
        lvl = 3;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x58) <= dmg) {
        lvl = 2;
    } else if (dmg != 0.0f && r[0x77] == 0 && hit != 0 && *(u8 **)(hit + 0x20) != 0
               && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x47) {
        lvl = 2;
    } else if (base != 0.0f) {
        lvl = 1;
    }
    if (flag != 0 && (u32)(lvl - 1) <= 2) {
        lvl = 6;
    }
    if (lvl >= 2 && hit != 0 && h[0x17] == 9) {
        f32 f = func_L01_0044DE78(obj, hit + 0x10, 0);
        vec_sub_ab(hit + 0x10, obj + 0x10, D_001A4C60);
        func_L01_0044DDC8(obj, hit + 0x10, hit + 0x10, 0, f);
    }
    if (lvl == 0) {
        return 0;
    }
    if (*(u16 *)(r + 0x38) & 3) {
        return 0;
    }
    if (obj[0x95] == r[0x48] && lvl < 4) {
        if (r[0x75] != 0) {
            return 0;
        }
        if (r[0x1A] < 2) {
            return 0;
        }
    }
    if (hit != 0 && (*(s32 *)(hit + 0x30) & 1)) {
        *(vu0_q *)dir = *(vu0_q *)(hit + 0x10);
    } else {
        func_003886E8(dir, obj + 0xC0, -1.0f);
        dir[2] = 1.0f;
        dir[3] = 5627.925f;
    }
    if (func_L24_00356F38(obj, r, dir, lvl, -1) != 0) {
        *(s32 *)(r + 0x44) = D_L24_001DF0C0_00357828;
        if (flag == 0) {
            if (r[0x48] != 0xFF && r[0x48] != 0) {
                func_L01_00441FB8(obj, r[0x10], r[0x48]);
            } else if (r[0x10] != 0xFF && r[0x10] != 0) {
                func_L01_00441FB8(obj, r[0x10], -1);
            }
        }
        r[0x1A] = 0;
    }
    return lvl;
}
/* localdecomp:end func_L24_00357828 */
