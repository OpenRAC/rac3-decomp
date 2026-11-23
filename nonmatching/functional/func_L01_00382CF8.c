/* functional: medium. Hand-written from asm, every branch read against it. Risk: callee prototypes for 0044AF78/00451FE0/00451E78/00443FB0 inferred from the register setup only, so the gate must cover the particle paths (state 1 kinds 0x1F4/0x1872/0x1FF, level<2 loop). */
#include "structs/weapon.h"
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_L01_001EAA00[];
extern u8 D_L01_001EAA20[];
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00457638(void *, void *, f32, f32, f32);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C8668(s32);
extern void func_L01_004CB128(void *, s32, s32);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_00383BA0(void *, void *, void *);
extern void func_L01_00446760(void *, s32, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern void func_L01_003837B8(void *);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern s32 func_L01_00443FB0(void *, void *);
extern void func_L01_0030F288(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                              f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_0044AF78(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
                             f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00463378(u8 *, f32 *, f32 *, u32, u32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_003C4C18(void *, f32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u32 func_0038DBD8(u32, u32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);

void func_L01_00382CF8(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);
    u8 stk[0xB0] __attribute__((aligned(16)));   /* the frame from sp+0x90 to sp+0x13F */
    u8 *p90 = stk;           /* sp+0x90 */
    u8 *pA0 = stk + 0x10;    /* sp+0xA0 */
    u8 *pB0 = stk + 0x20;    /* sp+0xB0 */
    u8 *pC0 = stk + 0x30;    /* sp+0xC0: hit info 1 */
    u8 *pD0 = stk + 0x40;    /* sp+0xD0 */
    u8 *pE0 = stk + 0x50;    /* sp+0xE0 */
    u8 *pF0 = stk + 0x60;    /* sp+0xF0 */
    u8 *p100 = stk + 0x70;   /* sp+0x100: hit info 2 */
    u8 *p130 = stk + 0xA0;   /* sp+0x130 */
    u8 *pos = obj + 0x10;
    u8 *cls;
    s32 state;

    *(s32 *)(d + 0x24) += 1;
    if (*(s32 *)(d + 0x24) >= 0x97) {
        func_L01_00446780(obj, pos, *(s32 *)(d + 0x2C), 0, 1, 0, 0.6000000238418579f, *(f32 *)(d + 0x14), 0.0f);
        func_L01_004450F0(obj, 1, -1);
    }
    cls = *(u8 **)(obj + 0x24);
    *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) + *(f32 *)(cls + 0x24) * 0.02500000037252903f;
    if (*(f32 *)(cls + 0x24) < *(f32 *)(obj + 0x2C)) *(f32 *)(obj + 0x2C) = *(f32 *)(cls + 0x24);

    state = obj[0x20];
    if (state == 0) {
        s32 hit;
        *(s32 *)(p90 + 0) = 0;
        *(s32 *)(p90 + 4) = 0;
        *(f32 *)(p90 + 8) = 0.5f;
        func_L01_00457638(obj, p90, 0.17399999499320984f, 0.20999999344348907f, 0.25100001692771908f);
        *(f32 *)(pA0 + 0) = *(f32 *)(obj + 0x10); *(f32 *)(pA0 + 4) = *(f32 *)(obj + 0x14);
        *(f32 *)(pA0 + 8) = *(f32 *)(obj + 0x18); *(f32 *)(pA0 + 12) = *(f32 *)(obj + 0x1C);
        func_L01_004C8688(*(s32 *)(d + 0x38), d, 0);
        /* vadd.xyz: B0 = obj.pos + d.vec */
        *(f32 *)(pB0 + 0) = *(f32 *)(obj + 0x10) + *(f32 *)(d + 0);
        *(f32 *)(pB0 + 4) = *(f32 *)(obj + 0x14) + *(f32 *)(d + 4);
        *(f32 *)(pB0 + 8) = *(f32 *)(obj + 0x18) + *(f32 *)(d + 8);
        *(f32 *)(pB0 + 12) = *(f32 *)(obj + 0x1C);
        if (*(s32 *)(d + 0x34) != 0) {
            func_L01_004CB128(pE0, *(s32 *)(d + 0x34), 0);
            *(f32 *)(pC0 + 0) = *(f32 *)(pE0 + 0) - *(f32 *)(pB0 + 0);
            *(f32 *)(pC0 + 4) = *(f32 *)(pE0 + 4) - *(f32 *)(pB0 + 4);
            *(f32 *)(pC0 + 8) = *(f32 *)(pE0 + 8) - *(f32 *)(pB0 + 8);
            *(f32 *)(pC0 + 12) = *(f32 *)(pE0 + 12);
            func_0038CF68(pD0, pC0, 0.30000001192092896f);
            *(f32 *)(pB0 + 0) = *(f32 *)(pB0 + 0) + *(f32 *)(pD0 + 0);
            *(f32 *)(pB0 + 4) = *(f32 *)(pB0 + 4) + *(f32 *)(pD0 + 4);
            *(f32 *)(pB0 + 8) = *(f32 *)(pB0 + 8) + *(f32 *)(pD0 + 8);
            func_0038CF68(d, d, func_0038CEA8(d));
        }
        func_L01_004CAB30(pos, pos);
        func_L01_00383BA0(obj, pB0, pA0);
        *(s32 *)(pD0 + 0) = *(s32 *)(d + 0x10);
        func_L01_00446760(pC0, *(s32 *)(d + 0x10), *(s32 *)(d + 0x2C), d, *(f32 *)(d + 0x14));
        *(s16 *)(pD0 + 0xA) = 0x1872;    /* sp+0xDA */
        hit = func_003D3CB0(pos, pB0, 0, obj, pC0);
        if (hit == 0) hit = (func_L01_003FB640(pos, 0, obj, 0.20000000298023224f) != 0);
        if (hit != 0) {
            u8 *rec = D_L01_001EAA00;
            u8 *hit_moby = *(u8 **)(rec + 0x18);
            if (hit_moby == 0) {
                s32 level = D_L01_002C5600[D_001425C0[0x87]].level;
                s32 kind = *(s32 *)(d + 0x3C);
                if (level == 0 || kind == 0x1F4 || kind == 0x1FF) {
                    *(f32 *)(pF0 + 0) = *(f32 *)(d + 0); *(f32 *)(pF0 + 4) = *(f32 *)(d + 4);
                    *(f32 *)(pF0 + 8) = *(f32 *)(d + 8); *(f32 *)(pF0 + 12) = *(f32 *)(d + 12);
                    func_0038CE20(pF0, pF0, 3.0f);
                    *(f32 *)(pF0 + 0xC) = 5627.9248046875f;
                    *(s32 *)(p100 + 0x10) = *(s32 *)(d + 0x10);
                    func_L01_00446760(p100, *(s32 *)(d + 0x10), *(s32 *)(d + 0x2C), pF0, *(f32 *)(d + 0x14));
                    p100[0x19] = 1;
                    *(s16 *)(p100 + 0x1A) = 0x1872;
                    p100[0x18] = 0;
                    func_003D4D00(D_L01_001EAA20, 1.0f, 0, obj, p100);
                    func_L01_004450F0(obj, 1, -1);
                    return;
                }
                func_L01_003837B8(pos);
                func_L01_0040E790(d, d, rec + 0x40);
            } else if (hit_moby != *(u8 **)(d + 0x10)) {
                if (*(s16 *)(hit_moby + 0xAA) != 0) {
                    *(f32 *)(pF0 + 0) = *(f32 *)(d + 0); *(f32 *)(pF0 + 4) = *(f32 *)(d + 4);
                    *(f32 *)(pF0 + 8) = *(f32 *)(d + 8); *(f32 *)(pF0 + 12) = *(f32 *)(d + 12);
                    func_0038CE20(pF0, pF0, 2.0f);
                    *(f32 *)(pF0 + 0xC) = 5627.9248046875f;
                    *(s32 *)(p100 + 0x10) = *(s32 *)(d + 0x10);
                    func_L01_00446760(p100, *(s32 *)(d + 0x10), *(s32 *)(d + 0x2C), pF0, *(f32 *)(d + 0x14));
                    p100[0x19] = 1;
                    *(s16 *)(p100 + 0x1A) = 0x1872;
                    p100[0x18] = 0;
                    func_003D4D00(rec + 0x20, 1.0f, 0, obj, p100);
                    func_L01_004450F0(obj, 1, -1);
                    return;
                }
            }
        }
        *(f32 *)(pos + 0) = *(f32 *)(pB0 + 0); *(f32 *)(pos + 4) = *(f32 *)(pB0 + 4);
        *(f32 *)(pos + 8) = *(f32 *)(pB0 + 8); *(f32 *)(pos + 12) = *(f32 *)(pB0 + 12);
        return;
    }
    if (state != 1) return;

    {
        s32 kind = *(s32 *)(d + 0x3C);
        if (kind == 0x1F4 || kind == 0x1872 || kind == 0x1FF) {
            /* two flares of 3 x 6 size, along and against the shot's heading */
            if (kind != 0x1FF) {
                s32 r;
                func_0038CF68(p90, d, -0.20000000298023224f);
                r = func_00382468(3);
                func_L01_00451E78(obj, r, 0.0f);
            } else {
                s32 n, k;
                func_0038CF68(p90, d, -0.20000000298023224f);
                func_L01_00443FB0(obj, p130);
                n = func_L01_00443FB0(obj, p130);
                for (k = n; k > 0; k--) func_L01_0030F288(pos, *(s32 *)p130, -1, 0);
            }
            func_L01_00451FE0(obj, 0x25, p90, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_0038CF68(p90, d, 0.20000000298023224f);
            func_L01_00451FE0(obj, 0x25, p90, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_003A52A0(0, 0, obj);
        } else if (D_L01_002C5600[D_001425C0[0x87]].level >= 2) {
            func_L01_003303B8(pos, 0, 10, 10, 10, 10, 10, 1,
                              0.699999988079071f, 0.0f, 0.0f, 0.0f,
                              1, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7,
                              0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        } else if (func_00382468(2) != 0) {
            s32 outer;
            func_L01_0044AF78(obj, d, 0, 4, 0, 0, -1, 0, 0, -1, 1, 0x1010001,
                              0.0f, 0.0f, 2.0f, 1.0f, 9.0f, 1.0f, 0.0f);
            for (outer = 0; outer < 20; ) {
                s32 inner;
                f32 ang, spd, up, jit;
                *(f32 *)(p90 + 0) = *(f32 *)(obj + 0x10); *(f32 *)(p90 + 4) = *(f32 *)(obj + 0x14);
                *(f32 *)(p90 + 8) = *(f32 *)(obj + 0x18); *(f32 *)(p90 + 12) = *(f32 *)(obj + 0x1C);
                func_003C4C18(p90, 0.25f);
                *(f32 *)(p90 + 8) = *(f32 *)(p90 + 8) + 0.25f;
                ang = func_00382538();
                spd = func_003824E0(1.0f, 8.0f) * 0.02000000141561031f;
                up = func_003824E0(2.0f, 6.0f);
                jit = func_003824E0(0.0f, 0.0f);
                func_0038CE20(pA0, d, jit * 0.02000000141561031f);
                *(f32 *)(pA0 + 0) = *(f32 *)(pA0 + 0) + func_0038D098(ang) * spd;
                *(f32 *)(pA0 + 4) = *(f32 *)(pA0 + 4) + func_0038D0B0(ang) * spd;
                up = up * 0.02000000141561031f;
                *(f32 *)(pA0 + 8) = *(f32 *)(pA0 + 8) + up;
                *(f32 *)(pB0 + 0) = *(f32 *)(pA0 + 0); *(f32 *)(pB0 + 4) = *(f32 *)(pA0 + 4);
                *(f32 *)(pB0 + 8) = *(f32 *)(pA0 + 8); *(f32 *)(pB0 + 12) = *(f32 *)(pA0 + 12);
                *(f32 *)(pB0 + 8) = *(f32 *)(pB0 + 8) - 0.20000000298023224f;
                outer = outer + 1;
                for (inner = 9; inner >= 0; ) {
                    f32 r = func_003824E0(0.5f, 1.5f);
                    u32 c1, c2;
                    f32 v;
                    s32 n;
                    inner--;
                    *(f32 *)(pB0 + 0xC) = r * 0.06499999761581421f;
                    *(f32 *)(pA0 + 0xC) = r * 0.125f;
                    func_003C4C18(p90, 0.125f);
                    func_003C4C18(pB0, 0.009999999776482582f);
                    c1 = func_0038DBD8(0x8000EEEE, 0x8000FF90, func_003824E0(0.0f, 1.0f));
                    c2 = func_0038DBD8(0xFFEE, 0xFFEE, func_003824E0(0.0f, 1.0f));
                    v = func_003824E0(5.0f, 25.0f);
                    n = (s32)((v * 5.0f + 2.0f) / 6.0f);
                    func_L01_00463378(p90, (f32 *)pA0, (f32 *)pB0, c1, c2, 8, 0x19, n, -1);
                }
            }
        } else {
            func_L01_003303B8(pos, 0, 10, 10, 10, 10, 10, 1,
                              0.699999988079071f, 0.0f, 0.0f, 0.0f,
                              1, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0xFF6340,
                              0xFF7F40, 0xFF2040, 0xFF8F40, 0x7F6440, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        }
    }
    func_L01_004C8668(*(s32 *)(d + 0x38));
    func_003C2880(obj);
}
