/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003AB138, the NTSC-U twin of func_L01_003AC8C0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_003AC8C0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_003AC8C0 (src/levels/shared/L01_003AC8C0.c) */
/* localdecomp:start func_L01_003AB138 */
typedef struct { s32 key; f32 f4; s32 w8; u8 pC[4]; vu0_v4 pos; } Ent_3AB138;
typedef struct { u8 p0[0x48]; s32 n; Ent_3AB138 *ents; s32 w50; f32 f54; f32 f58; f32 f5C; f32 f60; } St_3AB138;
extern f32 D_001DE408_sda;
__asm__(".extern D_001DE408_sda, 4");
extern u8 D_L01_001E2AC0[];
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L01_0044B5C8(void *, void *, f32, f32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_L01_0046A9C8(s32, void *, void *, s32, s32);

void func_L01_003AB138(u8 *obj, u8 *other, void *pos) {
    St_3AB138 *st;
    Ent_3AB138 *p;
    f32 tmp[4] __attribute__((aligned(16)));
    f32 l10[4] __attribute__((aligned(16)));
    f32 l20[4] __attribute__((aligned(16)));
    f32 l30[4] __attribute__((aligned(16)));
    u8 pad[0x30];
    f32 f;
    s32 i;
    s32 key;
    s32 r;

    st = *(St_3AB138 **)(other + 0x68);
    if (st->w50 >= 0) {
        vec_sub_ba(tmp, obj + 0x10, pos);
        func_003886E8(tmp, tmp, 60.0f);
        f = func_00388730(tmp, obj + 0xC0) * (1.0f / D_001DE408_sda) * st->f54;
        if (st->f5C < f) {
            f = st->f5C;
        } else if (f < st->f58) {
            f = st->f58;
        }
        f = func_00389380(f, st->f60);
        f = func_003893C8(f, *(f32 *)(obj + 0xF4) * 1.25f);
        qzero(other + 0xC00);
        *(f32 *)(other + 0xC04) = f;
        func_L01_0044B5C8(*(void **)(other + 0x64), other + 0xBA0, 0.03f, 0.3f, st->w50);
    }
    f = func_L01_0040C018(D_L01_001E2AC0, *(u8 **)(other + 0x64) + 0x10);
    r = *(s16 *)(*(u8 **)(other + 0x64) + 0x32);
    if ((f32)(r * r) < f) {
        return;
    }
    if (st->ents != 0 && st->n != 0) {
        p = st->ents;
        key = -1;
        for (i = 0; i < st->n; i++) {
            if (p->key != key) {
                func_003BD9A0(*(void **)(other + 0x64), p->key, l30);
                key = p->key;
            }
            func_003888F0(l10, &p->pos, l30);
            func_003886E8(l20, l30, p->f4);
            func_L01_0046A9C8(0, l10, l20, p->w8, 1);
            p++;
        }
    }
}
/* localdecomp:end func_L01_003AB138 */
