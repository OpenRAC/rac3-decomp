#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L16_003E6C48.c, which this file was cut from */
extern void func_L16_003E7350(u8 *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L16_003E6D40 */
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern u8 *func_003C4D58(u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446A70(s32, s32, s32, void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_003C39A8(u8 *);
extern void func_003C2880(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L16_003E7C00(void *);

extern u8 *D_001A71A0[];
extern u8 D_001A4C60[];
extern u8 *D_L16_001E98D8 __attribute__((section(".data")));
extern u8 *D_L16_001ED940[];
extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern s32 D_L16_001DF4DC;
__asm__(".extern D_L16_001DF4DC, 4");
extern f32 D_L16_001DF4E0;
__asm__(".extern D_L16_001DF4E0, 4");
extern f32 D_L16_001DF4E4;
__asm__(".extern D_L16_001DF4E4, 4");
extern f32 D_L16_001DF4E8;
__asm__(".extern D_L16_001DF4E8, 4");
extern f32 D_L16_001DF4EC;
__asm__(".extern D_L16_001DF4EC, 4");
extern s32 D_L16_001DF5E0;
__asm__(".extern D_L16_001DF5E0, 4");
extern f32 D_L16_001DF5E4;
__asm__(".extern D_L16_001DF5E4, 4");
extern f32 D_L16_001DF5E8;
__asm__(".extern D_L16_001DF5E8, 4");
extern s32 D_L16_001DF5EC;
__asm__(".extern D_L16_001DF5EC, 4");
extern s32 D_L16_001DF5F0;
__asm__(".extern D_L16_001DF5F0, 4");

typedef struct {
    f32 unk0;
    s32 unk4;
    s32 unk8;
    u8 padC[4];
    u8 *unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
    u128_t unk20;
    u128_t unk30;
} V_003E6D40;

/* a random offset vector: length random in [0, size), random yaw and pitch (func_00382760) */
static __inline__ void dir_003E6D40(vu0_v4 *p, V_003E6D40 *v) {
    f32 r1 = func_00382538();
    f32 r2 = func_00382538();
    func_00382760(p, func_003824E0(0.0f, v->unk18 * v->unk0 * D_L16_001DF5E4), r1, r2);
}

void func_L16_003E6D40(u8 *m) {
    V_003E6D40 *v;
    u8 *p;
    u8 *h;
    vu0_v4 old;
    vu0_v4 pos;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 *pp;
    f32 r1;
    f32 r2;
    f32 lim;
    f32 d;
    f32 t;
    s32 i;
    s32 n;
    s32 j;
    f32 f;

    p = m + 0x10;
    old = *(vu0_v4 *)(m + 0x10);
    v = *(V_003E6D40 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        vec_add_ba(m + 0x10, m + 0x10, &v->unk20);
        break;
    case 1:
        vec_add_ab(m + 0x10, m + 0x10, &v->unk20);
        if (func_L01_003FB640(p, 0, m, v->unk18) != 0 && D_L16_001E98D8 == D_001A71A0[0]) {
            *(f32 *)(m + 0x18) = *(f32 *)(v->unk10 + 0x18) + 1.618f + D_L16_001DF4E4;
            func_L01_004450F0(m, 2, -1);
        }
        lim = *(f32 *)(v->unk10 + 0x18) + 1.618f + D_L16_001DF4E4;
        if (*(f32 *)(m + 0x18) <= lim) {
            *(f32 *)(m + 0x18) = lim;
            func_L01_004450F0(m, 2, -1);
        }
        for (i = 0; i < D_L16_001DF5E0; i++) {
            dir_003E6D40(&pos, v);
            vec_add_ba(&pos, m + 0x10, &pos);
            pp = &pos;
            qzero(&a);
            a.w = D_L16_001DF5E8;
            vec_add_ab(&a, &a, &v->unk30);
            qzero(&b);
            vec_add_ab(&b, &b, &v->unk30);
            func_L01_00463378(pp, &a, &b, D_L16_001DF5F0, D_L16_001DF5F0, 1, 0x19,
                              (func_00382498(10, 20) * 5 + 2) / 6, D_L16_001DF5EC);
        }
        if (D_L16_001DFC40 >= v->unk8) {
            func_003C4138((f32 *)v, 0.0f, 0.0099667767f);
        }
        if (v->unk0 <= 0.0f) {
            func_003C2880(m);
            return;
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            qzero(&v->unk20);
            v->unk0 = v->unk18;
            *(f32 *)(m + 0x18) = *(f32 *)(v->unk10 + 0x18) + 1.618f + D_L16_001DF4E4;
            m[0x23] = 0x80;
            func_L01_004AAC98(0xB, 0, m, 0x1A0A);
            func_L16_003E7350(m, &v->unk30, 1);
        }
        t = v->unk0 * D_L16_001DF4E8;
        func_003C4138(&v->unk18, t, D_L16_001DF4EC);
        if (v->unk10 != 0) {
            v->unk30 = *(u128_t *)(func_003C4D58(v->unk10) + 0x10);
        }
        vec_add_ab(m + 0x10, m + 0x10, &v->unk30);
        if (0.0f < v->unk14) {
            d = func_0038CF38(p, D_001A4C60);
            if (d < v->unk18 && v->unk18 - D_L16_001DF4E0 < d) {
                h = D_001A4C60 - 0x80;
                if (*(f32 *)(h + 0x88) < *(f32 *)(m + 0x18)) {
                    qzero(&pos);
                    qzero(&a);
                    func_L01_00446A70(*(s32 *)(h + 0x25C0), v->unk4, D_L16_001DF4DC, &pos, &a, v->unk14);
                    v->unk14 = 0.0f;
                }
            }
        }
        n = func_003D4D00(m + 0x10, 1, D_001A71A0[0], 0, v->unk18 + 1.5f);
        for (j = 0; j < n; j++) {
            u8 *e = D_L16_001ED940[j];
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x1ADA) {
                func_L01_003C39A8(e);
            }
        }
        if (t * 0.9f < v->unk18) {
            f = (t - v->unk18) / (t * 0.1f);
            if (1.0f < f) {
                f = 1.0f;
            } else if (f < 0.0f) {
                f = 0.0f;
            }
            m[0x23] = f * 128.0f;
        }
        if (m[0x23] == 0) {
            func_003C2880(m);
            return;
        }
        break;
    }
    vec_sub_ba(&pos, m + 0x10, &old);
    func_L16_003E7350(m, &pos, 0);
    func_L01_00404808(func_L16_003E7C00, m);
}
/* localdecomp:end func_L16_003E6D40 */
