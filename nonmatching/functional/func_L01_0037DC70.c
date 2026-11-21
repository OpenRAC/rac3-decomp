/* functional: medium. Written from the asm, no draft; all branches/constants cross-read; dead stack store at sp+0x60 omitted. */
/* localdecomp:start func_L01_0037DC70 */
#include "vu0.h"
extern u8 D_0014262F[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001EAA00[];
extern vu0_v4 D_001A52D0;
extern s32 D_L01_001E1DA0;
extern s32 D_L01_001E1D90;
extern s32 D_L01_001E1D94;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1DB8;
extern f32 D_L01_001E1DBC;
typedef struct { s32 mode, count, f8, color0, color1; f32 scale; } Beam_0037DC70;
extern Beam_0037DC70 D_L01_002B3AC0;
void func_L01_0037DC70(u8 *obj) {
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_003C2880(void *);
    extern void func_L01_0037E2E8(void);
    extern void func_L01_0037E620(void);
    extern void func_L01_0037E670(void);
    vu0_v4 old_pos;
    vu0_v4 hitpos;
    vu0_v4 dir;
    vu0_v4 hit[3];
    u8 *s;
    u8 *target;
    u8 *t7;
    f32 x, y, z, f0, f1;
    s32 j;
    s32 n;

    if (obj[0x20] != 0) return;
    s = *(u8 **)(obj + 0x68);
    *(vu0_q *)&old_pos = *(vu0_q *)(obj + 0x10);
    if (*(s32 *)(s + 0x48) != 0) {
        vec_add_ab(obj + 0x10, obj + 0x10, s + 0x10);
    } else {
        vec_add_ab(obj + 0x10, obj + 0x10, s);
    }
    *(s32 *)(s + 0x34) = *(s32 *)(s + 0x34) + 1;
    target = 0;
    if (D_L01_002C5600[D_0014262F[0] * 0xF0 + 1] == 0) {
        if (*(s32 *)(s + 0x4C) == 0) {
            x = *(f32 *)(obj + 0x10);
            y = *(f32 *)(obj + 0x14);
            z = *(f32 *)(obj + 0x18);
            if (!(x < 2.0f) && !(x > 1021.0f) && !(y < 2.0f) && !(y > 1021.0f) &&
                !(z < 2.0f) && !(z > 1021.0f)) {
                if (func_003D3CB0(&old_pos, obj + 0x10, 0, obj, 0) != 0) {
                    *(s32 *)(s + 0x4C) = 1;
                    *(vu0_q *)&hitpos = *(vu0_q *)(D_L01_001EAA00 + 0x20);
                    *(vu0_q *)&dir = *(vu0_q *)&D_001A52D0;
                    func_0038CE20(&dir, &dir, 1.0f);
                    dir.w = 5627.9248f;
                    func_L01_00446760(hit, obj, *(s32 *)(s + 0x40), &dir, *(f32 *)(s + 0x3C));
                    ((u8 *)hit)[0x18] = 0;
                    ((u8 *)hit)[0x19] = 1;
                    *(u16 *)((u8 *)hit + 0x1A) = *(u16 *)(obj + 0xAA);
                    func_003D4D00(&hitpos, 0, obj, hit, 0.6f);
                    if (*(s32 *)(s + 0x48) != 0) {
                        func_0038CF68(s + 0x10, s + 0x10, -0.2f);
                    } else {
                        func_0038CF68(s, s, -0.2f);
                    }
                }
            }
        }
    } else {
        for (j = 0; j < 6; j++) {
            x = *(f32 *)(obj + 0x10);
            if (x < 2.0f) continue;
            if (x > 1021.0f) continue;
            y = *(f32 *)(obj + 0x14);
            if (y < 2.0f) continue;
            if (y > 1021.0f) continue;
            z = *(f32 *)(obj + 0x18);
            if (z < 2.0f) continue;
            if (z > 1021.0f) continue;
            if (func_003D3CB0(&old_pos, obj + 0x10, 0, target, 0) == 0) continue;
            t7 = *(u8 **)(D_L01_001EAA00 + 0x18);
            if (t7 != 0 && *(s16 *)(t7 + 0xAA) == 0x1CF7) break;
            target = t7;
            *(vu0_q *)&hitpos = *(vu0_q *)(D_L01_001EAA00 + 0x20);
            *(vu0_q *)&dir = *(vu0_q *)&D_001A52D0;
            func_0038CE20(&dir, &dir, 1.75f);
            dir.w = 5627.9248f;
            func_L01_00446760(hit, obj, *(s32 *)(s + 0x40), &dir, *(f32 *)(s + 0x3C));
            ((u8 *)hit)[0x18] = 0;
            ((u8 *)hit)[0x19] = 1;
            *(u16 *)((u8 *)hit + 0x1A) = *(u16 *)(obj + 0xAA);
            if (D_L01_002C5600[D_0014262F[0] * 0xF0 + 1] < 3) {
                func_003D4D00(&hitpos, 0, obj, hit, 0.8f);
            } else {
                func_003D4D00(&hitpos, 0, obj, hit, 2.5f);
            }
            if (*(s32 *)(s + 0x48) != 0) {
                func_0038CF68(s + 0x10, s + 0x10, -0.2f);
            } else {
                func_0038CF68(s, s, -0.2f);
            }
        }
    }
    if (func_0038CAD0(&D_L01_001E1DA0) == 0) {
        if (D_L01_002C5600[D_0014262F[0] * 0xF0 + 1] >= 3) {
            if (D_L01_001E1DA0 >= 5) {
                f0 = D_L01_001E1DB8 + 0.05f;
                f1 = D_L01_001E1DBC + 0.05f;
            } else {
                f0 = D_L01_001E1DB8 - 0.05f;
                f1 = D_L01_001E1DBC - 0.05f;
            }
            D_L01_001E1DB8 = f0;
            D_L01_001E1DBC = f1;
            func_L01_00404A10(func_L01_0037E2E8, obj);
        }
    }
    if (*(s32 *)(s + 0x34) >= 22) {
        func_003C2880(obj);
        return;
    }
    if (*(s32 *)(s + 0x48) != 0) {
        if (*(s32 *)(s + 0x34) < 17) {
            func_L01_00404A10(func_L01_0037E620, obj);
            func_L01_00404A10(func_L01_0037E670, obj);
        }
        if (*(s32 *)(s + 0x34) == 8) {
            D_L01_001E1D90 = 2;
            D_L01_001E1D94 = D_L01_001DFB40;
        }
        return;
    }
    if (*(s32 *)(s + 0x34) < 8) {
        func_L01_00404A10(func_L01_0037E620, obj);
        func_L01_00404A10(func_L01_0037E670, obj);
    }
    if (*(s32 *)(s + 0x34) == 3) {
        D_L01_001E1D90 = 2;
        D_L01_001E1D94 = D_L01_001DFB40;
    }
    n = *(s32 *)(s + 0x34);
    D_L01_002B3AC0.color0 = ((0xBF - n * 15) << 24) | 0x808080;
    n = *(s32 *)(s + 0x34);
    D_L01_002B3AC0.color1 = ((0xBF - n * 15) << 24) | 0x8080B4;
}
/* localdecomp:end func_L01_0037DC70 */
