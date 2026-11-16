/* NTSC-U draft (Claude wave K): C of func_L01_0032F3D8, the NTSC-U twin of func_L01_0032F8E8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 129 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L01_0032F3D8", whose code is not the PAL one).
 * Worker's note: 129 diff: complete spawner (func_003BCFB0(0x1367,0xC0); quad copies from pos/vel; func_00388BD0(o+0xC0, D_001A71A0[0]+0xF0); func_L01_004C41E8(o+0x10,&v0); func_00388830(&v1,o+0xE0,1.0); func_00388758; func_00388730*0.5 -> func_00388978/func_00388960 into ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0032F800 (src/levels/shared/L01_0032F800.c) */
/* localdecomp:start func_L01_0032F3D8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_001A71A0[];
extern s32 D_001DCF08_sda;
__asm__(".extern D_001DCF08_sda, 4");
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388960(f32);
extern void func_003890D8(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 func_L01_004C4548(void *, s32);
extern s32 func_L01_004C4A18(void *, s32, f32, f32, f32);
extern void func_003C26C8(void *);
extern void func_003BD360(void *);

u8 *func_L01_0032F3D8(u8 *owner, u8 *pos, u8 *vel) {
    u8 *o;
    u8 *s4;
    u128_t d;
    u128_t c;
    u128_t b;
    u128_t a1;
    u128_t a0;
    f32 f;
    s32 r;
    s32 v;

    o = func_003BCFB0(0x1367, 0xC0);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x20] = 0;
        s4 = *(u8 **)(o + 0x68);
        *(u128_t *)(o + 0x10) = *(u128_t *)pos;
        *(u128_t *)s4 = *(u128_t *)vel;
        func_00388BD0(o + 0xC0, D_001A71A0[0] + 0xF0);
        func_L01_004C41E8(o + 0x10, &a0);
        func_00388830(&a1, o + 0xE0, 1.0f);
        func_00388758(&c, &a1, &a0);
        f = func_00388730(&a1, &a0) * 0.5f;
        func_003886E8(&b, &c, func_00388978(f));
        ((f32 *)&b)[3] = func_00388960(f);
        func_003890D8(&b, &d);
        func_00388EB8(o + 0xC0, &d, o + 0xC0);
        *(u128_t *)(s4 + 0x10) = 0;
        *(f32 *)(s4 + 0x10) = 1.0f;
        *(u8 **)(s4 + 0x68) = owner;
        *(s32 *)(s4 + 0x64) = 0;
        *(s32 *)(s4 + 0x50) = 0;
        *(s32 *)(s4 + 0x44) = 0;
        *(s16 *)(s4 + 0x92) = 0;
        *(s32 *)(s4 + 0x60) = 0xD;
        *(s16 *)(s4 + 0x4C) = 1;
        *(s32 *)(s4 + 0x40) = D_001DCF08_sda;
        *(u128_t *)(s4 + 0x20) = *(u128_t *)(s4 + 0x10);
        *(f32 *)(s4 + 0x58) = 0.0261f;
        *(u128_t *)(s4 + 0x30) = *(u128_t *)(s4 + 0x10);
        r = func_L01_004C4548(o, 0);
        *(s32 *)(s4 + 0x48) = r;
        if (r == -1) {
            func_003BD360(o);
            return 0;
        }
        v = func_L01_004C4A18(o, 0, 1.0f, 1.0f, 1.0f);
        s4[0x4E] = -1;
        *(s32 *)(s4 + 0x70) = 0;
        s4[0x4F] = v;
        func_003C26C8(o);
    }
    return o;
}
/* localdecomp:end func_L01_0032F3D8 */
