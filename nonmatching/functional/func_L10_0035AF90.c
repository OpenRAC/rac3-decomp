/* functional: medium. From the PAL near-miss draft (needs -mvu0-use-vf0-vf2 on the file; 174 diff words are scheduling/regalloc and a div.s nop). The 29 callee addresses and their order match the retail asm exactly; the __asm__ .extern lines only size the sdata globals as the draft did and are not behaviour. */
/* localdecomp:start func_L10_0035AF90 */
#include "vu0.h"
/* plain-C stand-ins for the VU0 vector ops (xyz lanes, w from the first source) */
static __inline__ void vc_add(void *d, void *a, void *b) { float *D = (float *)d, *A = (float *)a, *B = (float *)b; float x = A[0] + B[0], y = A[1] + B[1], z = A[2] + B[2], w = A[3]; D[0] = x; D[1] = y; D[2] = z; D[3] = w; }
static __inline__ void vc_sub(void *d, void *a, void *b) { float *D = (float *)d, *A = (float *)a, *B = (float *)b; float x = A[0] - B[0], y = A[1] - B[1], z = A[2] - B[2], w = A[3]; D[0] = x; D[1] = y; D[2] = z; D[3] = w; }
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35AF90;
typedef struct T_35AF90 { s16 f0; s16 f2; s32 f4; } T_35AF90;
extern s32 D_L10_001D6694[] __attribute__((section(".sdata")));
extern u8 D_001D5471[] __attribute__((section(".sdata")));
extern void func_L10_0035AEA8(void *);
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");
extern T_35AF90 D_L10_001DF034;
__asm__(".extern D_L10_001DF034, 16");
extern u8 D_00142C38[];
extern u8 D_001A4CC0[];
extern u8 D_L10_001E86C0[];
extern u8 *D_L10_001DF298[2];
__asm__(".extern D_L10_001DF298, 16");
extern u8 *D_L10_001DF380[] __attribute__((section(".sdata")));
extern void fe_func_003C2F58(void *, s32, void *);
extern void func_L10_0042A4D0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L04_0046FFA0(void *, s32, f32);
extern void func_L01_0047F3B0(void *);
extern s32 fe_func_00392B20(void *, s32);
extern s32 fe_func_00392C78(void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void fe_func_003C2880(void *);
extern s32 fe_func_0038CAD0(void *);
extern f32 fe_func_003824E0(f32, f32);
extern void fe_func_003C3A10(u8 *, s32, s32, s32);
extern f32 fe_func_0038DAB8(f32, f32);
extern void fe_func_00382760(void *, f32, f32, f32);
extern f32 fe_func_0038D160(f32, f32);
extern f32 fe_func_0038DB00(f32, f32);
extern f32 fe_func_0038CED8(f32 *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L10_0035AF90(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_35AF90 a;
    V4_35AF90 tgt;
    V4_35AF90 c;
    V4_35AF90 d;
    s32 ok;
    s32 turn;
    u8 *e;
    u8 *gp;
    f32 r;
    f32 f;
    f32 g;
    f32 p;

    func_L10_0035AEA8((void *)m);
    fe_func_003C2F58(m, 2, &a);
    switch (m[0x20]) {
    case 0:
        func_L10_0042A4D0(m);
        if (*(u32 *)D_00142C38 & 0x4000000) {
            func_L01_004450F0(m, 7, -1);
        } else {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L04_0046FFA0(m, 0xA, 2.5f) != 0) {
            func_L01_0047F3B0(m);
            if (fe_func_00392B20(D_L10_001E86C0, 0x9A) != 0) {
                fe_func_00392C78(D_L10_001E86C0);
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 2:
        ok = 1;
        if (D_L10_001D6694[0] == 2) {
            m[0x31] = 0;
            *(u16 *)(m + 0x34) |= 1;
            if (D_L10_001D6694[0] == 2) {
                gp = D_L10_001DF298[1];
                e = gp + (*(s32 *)(v + 0x24C) << 8);
                *(u16 *)(e + 0x34) |= 1;
                (gp + (*(s32 *)(v + 0x24C) << 8))[0x31] = 0;
                ok = 1;
            }
        }
        D_L10_001DF034.f4 = ok;
        if (func_L01_004BA800() == 0) {
            e = D_L10_001DF380[0] + (*(s32 *)(v + 0x248) << 7);
            func_L01_004F50C8(e + 0x30, e + 0x70, 0, 1);
            D_L10_001DF034.f4 = 0;
            m[0x31] = ok;
            *(u16 *)(m + 0x34) &= 0xFFFE;
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        fe_func_003C2880(D_L10_001DF298[1] + (*(s32 *)(v + 0x24C) << 8));
        fe_func_003C2880(m);
        return;
    }
    if (m[0x20] != 0 && m[0x20] != 6) {
        if (m[0x43] == 0 && fe_func_0038CAD0(v + 0x23C) != 0) {
            *(s32 *)(v + 0x23C) = (fe_func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f;
            if (m[0x43] != 1) {
                fe_func_003C3A10(m, 1, 0, 8);
            }
        } else if (m[0x43] == 1 && (m[0x60] & 2)) {
            fe_func_003C3A10(m, 0, 0, 8);
        }
    }
    g = 0.019999999f;
    turn = 0;
    if (m[0x43] == 0 && m[0x20] != 6) {
        if (*(s32 *)(v + 0x234) != 0) {
            turn = 1;
            *(s32 *)(v + 0x234) = 0;
            *(V4_35AF90 *)(v + 0x220) = *(V4_35AF90 *)D_001A4CC0;
        }
        if (fe_func_0038CAD0(v + 0x238) != 0) {
            *(s32 *)(v + 0x238) = (fe_func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / 6.0f;
            f = fe_func_0038DAB8(*(f32 *)(m + 0xF8), fe_func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            p = fe_func_003824E0(0.0f, 30.0f) * 0.017453292f;
            fe_func_00382760(v + 0x220, 6.0f, f, p);
            vc_add(v + 0x220, v + 0x220, m + 0x10);
        }
        if (*(s32 *)(v + 0x234) != 0) {
            g = 0.039999999f;
            tgt = *(V4_35AF90 *)D_001A4CC0;
        } else {
            tgt = *(V4_35AF90 *)(v + 0x220);
        }
    }
    if (turn != 0) {
        c = *(V4_35AF90 *)(m + 0x10);
        c.z += 2.0f;
        vc_sub(&d, &tgt, &c);
        f = fe_func_0038DB00(fe_func_0038D160(d.x, d.y), *(f32 *)(m + 0xF8));
        p = -fe_func_0038D160(fe_func_0038CED8((f32 *)&d), d.z);
        if (1.5707964f < f) {
            f = 1.5707964f;
        } else if (f < -1.5707964f) {
            f = -1.5707964f;
        }
        if (0.5235988f < p) {
            p = 0.5235988f;
        } else if (p < -0.5235988f) {
            p = -0.5235988f;
        }
        *(f32 *)(v + 0x184) = p;
        *(f32 *)(v + 0x188) = f * 0.6f;
        *(f32 *)(v + 0x208) = f * 0.4f;
    }
    if ((&D_001D5470)[1] != 0) {
        *(f32 *)(v + 0x190) = 2.75f;
    }
    r = 1.44f;
    func_L01_0044E850(m, v + 0x120, 1, g * r, 0.3f * r);
    func_L01_0044E850(m, v + 0x1A0, 0, g * r, 0.3f * r);
}
/* localdecomp:end func_L10_0035AF90 */
