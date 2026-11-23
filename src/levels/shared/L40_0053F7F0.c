#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_0053F7F0 */
typedef struct {
    u8 pad0[0x8];
    s32 w8;
    u8 padC[0x12C - 0xC];
    s32 w12C;
} S_0053F7F0;

extern S_0053F7F0 D_001A5CD0;
extern s32 func_L39_0061CF78(s32);
extern s32 func_L39_0066C4D8(s32);

s32 func_L40_0053F7F0(s32 arg0) {
    s32 r = arg0 % D_001A5CD0.w12C;

    if (r == D_001A5CD0.w8) {
        return 1;
    }
    if (func_L39_0061CF78(r) != 0) {
        return 0;
    }
    return func_L39_0066C4D8(r);
}
/* localdecomp:end func_L40_0053F7F0 */

/* Adapted from the NTSC decomp draft for the PAL timings and multiplayer bindings. */
/* localdecomp:start func_L40_0053F850 */
__asm__(".extern D_L40_0024845C, 4");
__asm__(".extern D_001D5A1C_sda, 4");
extern u8 *D_L40_0024845C;
extern s32 D_001D5A1C_sda;
extern s32 D_L40_0024112C;
__asm__(".extern D_L40_00248600, 32");
extern u8 *D_L40_00248600;
extern s32 D_L40_002905F8[][0x9C];
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00452E60(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void *func_L39_005C1018(void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_00452F30(void *, void *);
extern void func_L01_00455E18(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_0067FAA8_0053F850(void);

s32 func_L40_0053F850(u8 *obj, u8 *r, s32 flag) {
    s32 lvl = 0;
    u8 *a = *(u8 **)(obj + 0x90);
    u8 *s;
    u8 *h;
    u8 *t21;
    u8 *hit;
    f32 dmg;
    f32 base;
    f32 hp;
    s32 thr;
    s32 i;
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
    func_L01_0044ABD0(obj, r);
    base = 0.0f;
    func_L01_00452E60(obj, r);
    hit = func_L01_00447490(obj, 0x10000, 0);
    if (func_0038CB00(h + 6) == 0) {
        hit = 0;
    }
    if (hit != 0) {
        u8 *p = *(u8 **)(hit + 0x20);
        if (p != 0 && a != 0) {
            u8 *q = p;
            u8 *x;
            while (*(u8 **)(q + 0xB8) != 0) {
                q = *(u8 **)(q + 0xB8);
            }
            x = (*(u8 *(**)(void *))((u8 *)func_L39_005C1018(q) + 4))(q);
            if (x != 0 && (*(s32 (**)(void *, s32))(*(u8 **)(x + 0x14) + 0x1C))(x, *(s32 *)(a + 0x18)) != 0) {
                hit = 0;
                obj[0xA8] = 0xFF;
            }
        }
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
    if (*(s16 *)(h + 0x1C) == 8) {
        *(s16 *)(h + 0x1C) = 10;
    }
    dmg = func_L01_004474E8(obj, hit);
    obj[0xA8] = 0xFF;
    if (func_L01_00452F30(obj, r) != 0 || *(f32 *)(obj + 0x18) < *(f32 *)(r + 0x40)) {
        dmg = *(f32 *)h;
        hit = 0;
    }
    *(f32 *)h = *(f32 *)h - dmg;
    if (t21 != 0) {
        func_L01_00455E18(obj, t21, h);
    }
    if (dmg == 0.0f) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if ((&D_L40_00248600)[i] == obj) {
            D_L40_002905F8[i][h[0x17]] += (s32)(dmg * 32.0f);
        }
    }
    *(s16 *)(r + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(r + 0x70) = (*(u8 **)(hit + 0x20) - D_L40_0024845C) >> 8;
    }
    thr = 300;
    hp = (f32)*(s16 *)(h + 4) * *(f32 *)(r + 0x58);
    if (hp <= 0.0f) {
        thr = 90;
    }
    if (r[0x77] == 0 && (thr * 5 + 2) / 6 < abs_asm(D_L40_0024112C - *(s32 *)(r + 0x44)) && dmg < hp) {
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
        func_0038CE20(dir, obj + 0xC0, -1.0f);
        dir[2] = 1.0f;
        dir[3] = 5627.925f;
    }
    if (func_003C56E0(obj, r, dir, lvl, -1) != 0) {
        *(s32 *)(r + 0x44) = D_001D5A1C_sda;
        if (r[0x48] != 0xFF && r[0x48] != 0) {
            func_L01_004450F0(obj, r[0x10], r[0x48]);
        } else if (r[0x10] != 0xFF && r[0x10] != 0) {
            func_L01_004450F0(obj, r[0x10], -1);
        }
        r[0x1A] = 0;
    }
    func_L39_0067FAA8_0053F850();
    return lvl;
}
/* localdecomp:end func_L40_0053F850 */
