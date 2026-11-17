/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003C42B0, the NTSC-U twin of func_L05_003C63A8, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 8 words differ with its file's flags.
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L05_003C42B0 */
struct V_3C42B0;
typedef struct {
    u8 pad0[0x68];
    struct V_3C42B0 *v68;
    u8 pad6C[0x10];
    s16 h7C;
} O_3C42B0;
typedef struct V_3C42B0 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x3];
    u8 b39;
    u8 pad3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x9];
    u8 b64;
    u8 pad65[0xB];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    union { f32 f; s32 i; } u9C;
    f32 fA0;
    u8 padA4[0x4];
    s32 wA8;
    u8 padAC[0xC4];
    u8 b170;
    u8 pad171[0x1F];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 b1A8;
    u8 pad1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 pad1DC[0x244];
    s32 w420;
    s32 w424;
    s16 h428;
} V_3C42B0;
extern s32 D_L05_001D673C;
extern s32 D_L05_001DF740;
extern s32 D_L05_001D67BC;
extern vu0_v4 D_L05_001EA760;
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

s32 func_L05_003C42B0(u8 *o) {
    V_3C42B0 *v = ((O_3C42B0 *)o)->v68;
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];
    vu0_q qp, qa, qb;

    ((O_3C42B0 *)o)->h7C = 0x7F;
    if (D_L05_001D673C != 0) {
        *(s16 *)(o + 0x32) = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        func_003BFC18(o + 0x10, m, 0);
        func_L01_0044E358(o + 0xC0, &m[0], &m[1]);
        func_00388830(&a, o + 0xE0, 0.5f);
        func_00388830(&b, o + 0xE0, -4.0f);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qb));
        if (func_003CE740(&a, &b, 2, o, 0) != 0) {
            *(vu0_v4 *)(o + 0x10) = D_L05_001EA760;
            func_003BFC18(o + 0x10, m2, 0);
            func_L01_0044E358(o + 0xC0, &m2[0], &m2[1]);
        }
        v->h428 = 0;
    }
    v->b170 = 0xA;
    v->b1A8 = 3;
    v->b1D7 = 1;
    v->b1DB = 0xFF;
    v->b1D8 = 0;
    v->b1D9 = 0;
    v->b1DA = 0;
    v->f19C = 0.15f;
    v->f70 = 0.7f;
    v->f78 = 0.5f;
    v->f7C = 1.0f;
    v->f80 = 0.7853982f;
    v->fA0 = 0.34906584f;
    v->u9C.f = 0.0027222224f;
    v->f194 = 0.5f;
    v->f74 = 0.5f;
    v->f190 = 0.5f;
    if (D_L05_001D673C != 0) {
        v->u9C.i = 0;
    }
    v->wA8 |= 4;
    if (D_L05_001D673C == 0) {
        v->wA8 |= 0x14;
    }
    func_L01_00458A70(o, 0.008333334f, 0.16666667f, 0.0069813174f, 0.20943953f);
    v->b58 = 0x14;
    v->b5A = 0xE;
    if (v->h34 == 0) {
        v->h34 = 0x64;
        v->f30 = 100.0f;
    }
    v->b39 = 1;
    v->b3E = 1;
    v->b3F = 0;
    v->b64 = 0;
    v->w420 = -1;
    v->f40 = 2.0f;
    func_L01_00441FB8(o, 1, 0);
    if (o[0x43] != 0) {
        func_003BE4F0(o, 0, 0, 0);
    }
    if (v->w424 != 0) {
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(o, 1);
    }
    if (v->h428 != 0) {
        v->wA8 |= 4;
        *(u16 *)(o + 0x34) |= 0x100;
        v->f80 = 12.566371f;
        v->wA8 |= 1;
    }
    if (D_L05_001DF740 == 0) {
        D_L05_001D67BC = 0;
    }
    return 0;
}
/* localdecomp:end func_L05_003C42B0 */
