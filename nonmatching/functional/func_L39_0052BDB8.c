/* functional: medium. Multiplayer vehicle-controller object state machine (switch on o->b20, 8 states; jump table: 0 init, 1/5 main, 2, 3, 4, 6/7/default only the final func_L39_0066A8C8). The gate tests (Dec(...) ^ 0x31 / ^ 0x14) are retail's table-decoded byte checks, written as the NTSC-U file's Dec helper over D_L39_004997E0. Raw offsets, no struct layout known; callee return types guessed from use */
#include "vu0.h"
extern void func_003C2880(void *);
extern s32 func_L39_0061BF68(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L39_00570200(s32, void *, void *, s32, s32, s32);
extern void func_L01_00412E70(void *, void *, void *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_004513A8(void *, void *, void *);
extern void func_L39_0061C1E0(void *, s32);
extern void func_L39_00668C90(s32, void *, void *, void *, void *, void *, void *, void *);
extern u8 *func_L39_00666FB8(s32, void *, s32, s32, s32, f32);
extern void func_L39_0052BD50(void *);
extern void func_003C41A0(void *, f32 *, f32, f32, f32, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern f32 func_L06_0042B660(f32, void *, void *);
extern f32 func_L01_00448728(f32 *, void *, s32, f32, f32, f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_005BE878(s32, void *, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L39_00667208(void *, u32, s32, s32);
extern void func_L39_0052CB90(void *);
extern void func_L39_0052CD40(void *);
extern void func_L39_0052D1C0(void *);
extern void func_L39_0052CF70(void *);
extern void func_L39_0052CA90(void *);
extern s32 func_L39_005F3088(s32);
extern void func_L39_0066A8C8(void *, void *);
extern void func_L39_00648258();
extern f32 func_0038CEA8(void *);
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern u8 D_L39_004997E0[];
extern u8 D_001A5810[];
extern u8 D_001FE020[];
extern u8 D_L39_0024AAF0[];
extern u8 D_L39_0024AB00[];
extern u8 D_L39_00242930[];
__asm__(".extern D_L39_0024AAB0, 16");
__asm__(".extern D_L39_0024AAC0, 16");
__asm__(".extern D_L39_0024AAD0, 4");
extern u8 D_L39_0024AAB0[];
extern u8 D_L39_0024AAC0[];
extern f32 D_L39_0024AAD0;

static u32 Dec_0052BDB8(u8 *q) {
    u32 buf[2];
    u8 *d = (u8 *)buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf[0] ^ (u32)q;
    b = buf[1] ^ a;
    buf[0] = a;
    buf[1] = b;
    return b;
}

static s32 GateA_0052BDB8(u8 *pl) {
    u8 *x = *(u8 **)(pl + 0x2530);
    if (x == 0 || x[0x27B] == 0) {
        return 0;
    }
    return (Dec_0052BDB8(pl + 0x19E4) ^ 0x31) == 0;
}

static s32 GateB_0052BDB8(u8 *pl) {
    return (Dec_0052BDB8(pl + 0x19E6) ^ 0x14) == 0;
}

void func_L39_0052BDB8(u8 *o) {
    u8 *S = *(u8 **)(o + 0x68);
    u8 *c = *(u8 **)(S + 0x1F8);
    u8 *pl;
    u8 *p;
    s32 t;
    s32 idx;
    s32 r;
    f32 f;
    f32 w;
    u32 col;
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));

    if (S[0xA2] == 1) {
        func_003C2880(o);
        return;
    }
    pl = 0;
    if (c != 0) {
        pl = *(u8 **)(c + 0x2D8);
        if (pl != 0) {
            *(u8 **)(S + 0xC0) = pl;
        }
    }
    if (*D_L39_00241120 >= 2) {
        o[0x62] = 1;
    }
    switch (o[0x20]) {
    case 0:
        *(u8 **)S = S + 0x70;
        *(u16 *)(o + 0x34) |= 0x5020;
        *(s16 *)(S + 0x74) = 0x32;
        S[0x7E] = 3;
        *(f32 *)(S + 0x70) = 50.0f;
        *(f32 *)(S + 0x80) = 2.0f;
        (*(u8 **)(o + 0x24))[0x46] = 5;
        func_L01_004513A8(o + 0x10, o, o + 0x10);
        o[0xBE] &= 0xE7;
        func_L39_0061C1E0(o, -1);
        func_L39_00668C90(2, func_L39_0052BD50, 0, 0, 0, 0, 0, 0);
        c = func_L39_00666FB8(2, o, -1, 0xBB8, 0x17100008, 2.0f);
        *(u8 **)(S + 0x1F8) = c;
        *(u8 **)(o + 0x90) = c;
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x32) = 0x1FF;
        func_L39_0052BD50(o);
        func_L01_004450F0(o, 1, -1);
        func_L39_0066A8C8(c, o);
        return;
    case 1:
    case 5:
        t = o[0x20];
        if (t == 1) {
            idx = func_L39_0061BF68(*(u8 **)(c + 0x2D8));
            if (idx >= 0) {
                func_0038D000(v10, D_L39_0024AAF0, o + 0xC0);
                ((f32 *)v10)[0] += *(f32 *)(o + 0x10);
                ((f32 *)v10)[1] += *(f32 *)(o + 0x14);
                ((f32 *)v10)[2] += *(f32 *)(o + 0x18);
                (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(pl + 0x14) + 0x34))(pl, 0x8F, 1, 0, 1);
                *(s32 *)(S + 0x1FC) = pl[0x24C9];
                func_L39_00570200(pl[0x24C9], *(u8 **)(pl + 0x2530), *(u8 **)(pl + 0x2530) + 0x10, 3, 0x3C, 0);
                func_0038D000(v20, D_L39_0024AAB0, o + 0xC0);
                v20[0] += *(f32 *)(o + 0x10);
                v20[1] += *(f32 *)(o + 0x14);
                v20[2] += *(f32 *)(o + 0x18);
                func_L01_00412E70(S + 0x200, v20, o, *(f32 *)(o + 0xF8), 0.0f);
                *(u16 *)(S + 0x2E0) = t;
                if (D_001A5810[*(s32 *)(*(u8 **)(c + 0x2D8) + 0x2544) + 0xA4] == 0) {
                    *(u16 *)(S + 0x2E0) = 9;
                }
                w = D_L39_0024AAD0;
                *(f32 *)(S + 0x2B4) = 1.04719758f;
                *(f32 *)(S + 0x2B8) = -0.872664630f;
                *(f32 *)(S + 0x2D4) = w * 0.0174532924f;
                *(f32 *)(S + 0x320) = 120.0f;
                *(f32 *)(S + 0x324) = func_0038CEA8(D_L39_0024AAC0);
                *(u16 *)(S + 0x2E2) = *(u16 *)(pl + 0x1282);
                *(s32 *)(S + 0x32C) = pl[0x24C9];
                *(void **)(S + 0x2E4) = func_L39_00648258;
                *(s32 *)(S + 0x338) = *(s32 *)(pl + 0x2544);
                *(u128_t *)(S + 0x2C0) = *(u128_t *)D_L39_0024AAC0;
                *(u128_t *)(S + 0x2D0) = *(u128_t *)D_L39_00242930;
                func_L01_004450F0(o, 2, -1);
                func_L39_0066A8C8(c, o);
                return;
            } else if (*(u8 **)(c + 0x2D8) != 0) {
                *(u128_t *)(c + 0x250) = *(u128_t *)(o + 0x10);
                func_0038D000(v10, D_L39_0024AB00, o + 0xC0);
                ((f32 *)(c + 0x250))[0] += v10[0];
                ((f32 *)(c + 0x250))[1] += v10[1];
                ((f32 *)(c + 0x250))[2] += v10[2];
                *(u128_t *)(c + 0x260) = *(u128_t *)(o + 0xF0);
                pl = *(u8 **)(c + 0x2D8);
                (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(pl + 0x14) + 0x34))(pl, 0x8F, 1, 0, 1);
                func_L01_004450F0(o, 3, -1);
            }
        }
        f = *(f32 *)(c + 0x298);
        w = *(f32 *)(o + 0x18) - f + 1.0f;
        if (fabs_asm(w) > 0.01f) {
            func_003C41A0(o + 0x18, (f32 *)(S + 0x1E8), f - 1.0f, 0.000800000038f, 0.000800000038f, 0.0400000028f);
        }
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            func_L39_005F33E0(3, 0, o);
            *(s32 *)(S + 0x1E0) = 0;
        }
        func_003C41A0(o + 0x18, (f32 *)(S + 0x1E8), *(f32 *)(c + 0x298), 0.00240000011f, 0.00240000011f, 0.120000005f);
        pl = *(u8 **)(c + 0x2D8);
        if (pl == 0) {
            goto done;
        }
        if (GateA_0052BDB8(pl)) {
            pl = *(u8 **)(c + 0x2D8);
            if (pl == 0) {
                goto done;
            }
            if (GateA_0052BDB8(pl)) {
                pl = *(u8 **)(c + 0x2D8);
                if (pl[0x1A14] != 0) {
                    func_L39_00667208(c, *(u32 *)pl, 4, -1);
                }
            }
            goto done;
        }
        func_L39_0052CD40(o);
        func_L39_0052D1C0(o);
        func_L39_0052CF70(o);
        func_L39_0052CA90(o);
        if (fabs_asm(*(f32 *)(o + 0x18) - *(f32 *)(c + 0x298)) <= *(f32 *)(S + 0x1E8)) {
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 3:
        func_L06_0042B660(0.0400000028f, o + 0x10, c + 0xB0);
        func_L01_00448728((f32 *)(o + 0xF8), c + 0x288, 0, *(f32 *)(c + 0x208), 0.0360000022f, 0.216000020f, 0.0628318563f);
        if (*(u8 **)(c + 0x2D8) == 0) {
            func_L01_004450F0(o, 1, -1);
        } else {
            func_0038D000(v10, D_L39_0024AAF0, o + 0xC0);
            v10[0] += *(f32 *)(o + 0x10);
            v10[1] += *(f32 *)(o + 0x14);
            v10[2] += *(f32 *)(o + 0x18);
            *(u128_t *)(c + 0x250) = *(u128_t *)v10;
            *(u128_t *)(*(u8 **)(c + 0x2D8) + 0xA0) = *(u128_t *)v10;
            *(u128_t *)(c + 0x260) = *(u128_t *)(o + 0xF0);
            *(u128_t *)(*(u8 **)(c + 0x2D8) + 0xB0) = *(u128_t *)(o + 0xF0);
        }
        *(f32 *)(S + 0x138) = *(f32 *)(c + 0x204);
        *(f32 *)(S + 0x1B8) = *(f32 *)(c + 0x204);
        func_L01_0044E850(o, S + 0xD0, 2, 0.0144000007f, 0.150000006f);
        func_L01_0044E850(o, S + 0x150, 3, 0.0144000007f, 0.150000006f);
        break;
    case 4:
        if ((*(u8 **)(c + 0x2D0))[0xBC] == 0xA) {
            break;
        }
        f = *(f32 *)(S + 0x2B0);
        if (0.9f <= f) {
            func_L01_003F6F20(*(s32 *)(S + 0x1FC), o, 0x600F0FFF, 0, 0x21, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            func_L39_005BE878(*(s32 *)(S + 0x28C), v10, 0);
            w = (*(f32 *)(S + 0x2B0) - 0.9f) / 0.100000024f;
            if (1.0f < w) {
                w = 1.0f;
            } else if (w < 0.0f) {
                w = 0.0f;
            }
            col = func_0038DBD8(0xFF0FFFFF, 0xFF0F0FFF, w);
            w = func_0038CF00(S + 0x230, v10) / 150.0f;
            func_L01_003F6F20(*(s32 *)(S + 0x1FC), o, col, v10, 0x26, -1, 4, fabs_asm(0.9f - w * 0.649999976f), 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        } else {
            func_L01_003F6F20(*(s32 *)(S + 0x1FC), o, 0x600FFF0F, 0, 0x21, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
        pl = *(u8 **)(c + 0x2D8);
        if (pl == 0) {
            goto done;
        }
        if (!GateA_0052BDB8(pl) && !GateB_0052BDB8(pl)) {
            func_L39_0052CD40(o);
            func_L39_0052D1C0(o);
            func_L39_0052CF70(o);
            func_L39_0052CA90(o);
            *(u128_t *)(c + 0x230) = *(u128_t *)(o + 0x10);
            *(s32 *)(c + 0x2F8) |= 0x800;
            *(f32 *)(c + 0x248) = *(f32 *)(o + 0xF8);
            *(f32 *)(c + 0x244) = *(f32 *)(S + 0x1E0);
            break;
        }
        pl = *(u8 **)(c + 0x2D8);
        if (pl == 0 || pl[0x1A14] == 0) {
            goto done;
        }
        if (GateA_0052BDB8(pl) || GateB_0052BDB8(pl)) {
            func_L39_00667208(c, *(u32 *)*(u8 **)(c + 0x2D8), 4, -1);
        }
    done:
        func_L39_0052CB90(o);
        func_L01_004450F0(o, 1, -1);
        r = *(s32 *)(S + 0x1F4);
        if (r != -1) {
            p = D_001FE020 + (r << 7);
            if (*(u8 **)(p + 0xDC) == o && p[0xD0] != 0) {
                func_L39_005F3088(r);
            }
        }
        *(s32 *)(S + 0x1F4) = -1;
        break;
    default:
        break;
    }
    func_L39_0066A8C8(c, o);
}
