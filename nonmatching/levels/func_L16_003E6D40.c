/* PAL port of func_L16_003E6D40 (from the NTSC-U draft of func_L16_003E4E20): 7 words differ. Needs its own file with
 * `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (cut at 0x003E6D40..0x003E7280; the rest of
 * L16_003E6C48.c keeps its line) and the divs row `func_L16_003E6D40 1` in config/levels/divs_nops.txt.
 * PAL differences from the NTSC-U draft: the gp slots are level data (D_L16_001DF4E4.. instead of D_001DF524_sda..),
 * 0x19 and the rescale ((n * 5 + 2) / 6) of the random particle count, 0.009966777f, D_001A71A0 as section(".data").
 * Left: retail keeps the constant 6 (divisor) in $s3 and &a (sp+0x20) in $s4 inside the particle loop; ours swaps them
 * (the two argument moves around it follow). Tried: local count, declaration order of i/j and of a/b/c (17 diffs).
 */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L16_003E6D40 */
typedef union { f32 f[0xA80]; u8 *ptr[0xA80]; u8 b[0x2A00]; } Hero_E4E20;
extern Hero_E4E20 D_001A4BE0;
extern s32 D_001A71A0 __attribute__((section(".data")));
__asm__(".extern D_001A71A0, 16");
extern s32 D_L16_001E98D8[];
extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern u8 *D_L16_001ED940[];
extern f32 D_L16_001DF4E4;
__asm__(".extern D_L16_001DF4E4, 4");
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
extern f32 D_L16_001DF4E8;
__asm__(".extern D_L16_001DF4E8, 4");
extern f32 D_L16_001DF4EC;
__asm__(".extern D_L16_001DF4EC, 4");
extern f32 D_L16_001DF4E0;
__asm__(".extern D_L16_001DF4E0, 4");
extern s32 D_L16_001DF4DC;
__asm__(".extern D_L16_001DF4DC, 4");
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L16_003E7350(void *, void *, s32);
extern u8 *func_003C4D58(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, s32, s32);
extern void func_L01_003C39A8(void *);
extern void func_L16_003E7C00(void);
extern void func_L01_00404808(void (*)(void), void *);

void func_L16_003E6D40(u8 *o) {
    vu0_v4 pos0;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *s;
    u8 *pos;
    u8 *hp;
    u8 *m;
    s32 i;
    s32 j;
    s32 n;
    f32 x;
    f32 y;
    f32 t;
    f32 t1;
    f32 tr;
    f32 td;
    f32 tf;
    f32 f20;
    f32 z0;

    pos = o + 0x10;
    s = *(u8 **)(o + 0x68);
    *(u128_t *)&pos0 = *(u128_t *)(o + 0x10);
    switch (o[0x20]) {
    case 0:
        vec_add_ba(o + 0x10, o + 0x10, s + 0x20);
        break;
    case 1:
        vec_add_ab(o + 0x10, o + 0x10, s + 0x20);
        if (func_L01_003FB640(pos, 0, o, *(f32 *)(s + 0x18)) != 0) {
            if (D_L16_001E98D8[0] == D_001A71A0) {
                *(f32 *)(o + 0x18) = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_L16_001DF4E4;
                func_L01_004450F0(o, 2, -1);
            }
        }
        t1 = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_L16_001DF4E4;
        if (*(f32 *)(o + 0x18) <= t1) {
            *(f32 *)(o + 0x18) = t1;
            func_L01_004450F0(o, 2, -1);
        }
        for (i = 0; i < D_L16_001DF5E0; i++) {
            x = func_00382538();
            y = func_00382538();
            tr = func_003824E0(0.0f, *(f32 *)(s + 0x18) * *(f32 *)s * D_L16_001DF5E4);
            func_00382760(&a, tr, x, y);
            vec_add_ba(&a, o + 0x10, &a);
            qzero(&b);
            b.w = D_L16_001DF5E8;
            vec_add_ab(&b, &b, s + 0x30);
            qzero(&c);
            vec_add_ab(&c, &c, s + 0x30);
            func_L01_00463378(&a, &b, &c, D_L16_001DF5F0, D_L16_001DF5F0, 1, 0x19, (func_00382498(0xA, 0x14) * 5 + 2) / 6, D_L16_001DF5EC);
        }
        if (!(D_L16_001DFC40 < *(s32 *)(s + 8))) {
            func_003C4138((f32 *)s, 0.0f, 0.009966777f);
        }
        if (*(f32 *)s <= 0.0f) {
            func_003C2880(o);
            return;
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            *(f32 *)s = *(f32 *)(s + 0x18);
            qzero(s + 0x20);
            *(f32 *)(o + 0x18) = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_L16_001DF4E4;
            o[0x23] = 0x80;
            func_L01_004AAC98(0xB, 0, o, 0x1A0A);
            func_L16_003E7350(o, s + 0x30, 1);
        }
        f20 = *(f32 *)s * D_L16_001DF4E8;
        func_003C4138((f32 *)(s + 0x18), f20, D_L16_001DF4EC);
        if (*(u8 **)(s + 0x10) != 0) {
            *(u128_t *)(s + 0x30) = *(u128_t *)(func_003C4D58(*(u8 **)(s + 0x10)) + 0x10);
        }
        vec_add_ab(o + 0x10, o + 0x10, s + 0x30);
        z0 = 0.0f;
        if (z0 < *(f32 *)(s + 0x14)) {
            hp = (u8 *)&D_001A4BE0 + 0x80;
            td = func_0038CF38(pos, hp);
            if (td < *(f32 *)(s + 0x18) && *(f32 *)(s + 0x18) - D_L16_001DF4E0 < td) {
                if (D_001A4BE0.f[0x88 / 4] < *(f32 *)(o + 0x18)) {
                    qzero(&a);
                    qzero(&b);
                    func_L01_00446A70(D_001A4BE0.ptr[0x25C0 / 4], *(u8 **)(s + 4), D_L16_001DF4DC, &a, &b, *(f32 *)(s + 0x14));
                    *(f32 *)(s + 0x14) = z0;
                }
            }
        }
        n = func_003D4D00(o + 0x10, 1, 1.5f + *(f32 *)(s + 0x18), D_001A71A0, 0);
        for (j = 0; j < n; j++) {
            m = D_L16_001ED940[j];
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x1ADA) {
                func_L01_003C39A8(m);
            }
        }
        if (f20 * 0.9f < *(f32 *)(s + 0x18)) {
            tf = (f20 - *(f32 *)(s + 0x18)) / (f20 * 0.1f);
            if (1.0f < tf) {
                tf = 1.0f;
            } else if (tf < 0.0f) {
                tf = 0.0f;
            }
            o[0x23] = (s32)(tf * 128.0f);
        }
        if (o[0x23] == 0) {
            func_003C2880(o);
            return;
        }
        break;
    }
    vec_sub_ba(&a, o + 0x10, &pos0);
    func_L16_003E7350(o, &a, 0);
    func_L01_00404808(func_L16_003E7C00, o);
}
/* localdecomp:end func_L16_003E6D40 */
