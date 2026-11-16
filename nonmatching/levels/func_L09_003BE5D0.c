/* NTSC-U draft (Claude wave K): C of func_L09_003BCD58, the NTSC-U twin of func_L09_003BE5D0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L09_003BCD58", whose code is not the PAL one).
 * Worker's note: first draft (was skip): 49 aligned, 206 vs 207 words, fully decoded (pickup/aim state: obj table D_L09_001E011C[t->wCD0<<8], b43 in {3,4} -> func_L01_0044AF40(obj,1.0f), two func_003BDA38 vec fetches, b20==7 cos/sin(2.9670596f)*0.4666667f, b20==0x14 / ...
 */
#include "common.h"

/* NTSC-U counterpart of the L09 pickup/aim state (src/levels/09_tyhrranosis) */
#include "vu0.h"

/* localdecomp:start func_L09_003BCD58 */
typedef struct V_003BCD58 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003BCD58;

typedef struct T_003BCD58 {
    u8 p0[0xCD0];
    s32 wCD0;
    u8 pCD4[0x59];
    u8 bD2D;
    u8 pD2E[8];
    s16 hD36;
} T_003BCD58;

extern u8 *D_L09_001E011C;
extern f32 D_001A4CB0[];
extern s32 D_001A71A0;
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L09_003E5EE8(void *, void *, void *, s32, s32, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_003883C8(void *);

void func_L09_003BCD58(u8 *self, s32 flag, s32 a2, s32 a3, s32 e) {
    V_003BCD58 v0;
    V_003BCD58 v1;
    V_003BCD58 v2;
    T_003BCD58 *t;
    u8 *o;
    f32 ang;
    f32 d;
    f32 *tv;
    s32 x;

    t = *(T_003BCD58 **)(self + 0x68);
    o = D_L09_001E011C + (t->wCD0 << 8);
    if ((u8)(o[0x43] - 3) < 2) {
        if (func_L01_0044AF40(o, 1.0f) != 0) {
            func_003BDA38(o, o[0x43] == 3 ? 7 : 0xB, &v0);
            func_003BDA38(o, o[0x43] == 3 ? 8 : 0xC, &v1);
            if (e != 0) {
                if (self[0x20] == 7) {
                    v2.x = func_00388960(2.9670596f) * 0.4666667f;
                    v2.y = func_00388978(2.9670596f) * 0.4666667f;
                    *(s32 *)&v2.z = 0;
                    tv = &v2.x;
                    goto call;
                }
                if (self[0x20] == 0x14) {
                    ang = func_00388A28(v1.x - v0.x, v1.y - v0.y);
                    d = func_00388800(&v1, D_001A4CB0);
                    func_0037E4B8(&v2, 0.4666667f, ang, func_00388A28(d, D_001A4CB0[2] - v1.z));
                    tv = &v2.x;
                    goto call;
                }
            }
            if (flag != 0 || e != 0) {
                vec_sub_ab(&v2, &v1, &v0);
                func_00388830(&v2, &v2, 0.4666667f);
                tv = &v2.x;
            } else {
                ang = func_00388A28(v1.x - v0.x, v1.y - v0.y);
                d = func_00388800(&v1, D_001A4CB0);
                func_0037E4B8(&v2, 0.4666667f, ang, func_00388A28(d, D_001A4CB0[2] - v1.z));
                tv = &v2.x;
            }
        call:
            func_0039FE80(1, 0, o);
            func_L09_003E5EE8(self, &v1, tv, e != 0 ? 0 : D_001A71A0, ((u8 *)t)[0x45], flag, a2, a3);
        } else if (o[0x60] & 2) {
            func_003BE4F0(o, 0, 0, 5);
        }
    } else {
        if (func_003883C8(&t->hD36) != 0 || a3 != 0) {
            x = t->bD2D + 1;
            t->hD36 = 0x2D;
            t->bD2D = x;
            func_003BE4F0(o, (x & 1) ? 3 : 4, 0, 0xA);
        }
    }
}
/* localdecomp:end func_L09_003BCD58 */
