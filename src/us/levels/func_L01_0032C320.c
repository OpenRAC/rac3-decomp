#include "common.h"

/* NTSC-U counterpart of func_L01_0032C7A0 (src/levels/shared/L01_0032C6B8.c) */
#include "vu0.h"

/* localdecomp:start func_L01_0032C320 */
#include "vu0.h"

typedef int s128_0032C7A0 __attribute__((mode(TI)));

extern s32 D_001A71A0[];
extern u8 D_001425C0[];
typedef struct { u8 pad0[0x54]; u16 x54; u8 pad56[0xF0 - 0x56]; } T_2C5600_0032C7A0;
extern T_2C5600_0032C7A0 D_L01_002C5640_0032C320[];
extern s32 D_L01_001DCE88_0032C320;
__asm__(".extern D_L01_001DCE88_0032C320, 4");
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_L01_004C41E8_0032C320(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388960(f32);
extern void func_003890D8(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 func_L01_004C4548_0032C320(s32, s32);
extern void func_003BD360(void *);
extern s32 func_L01_004C4A18_0032C320(u8 *, s32, f32, f32, f32);
extern void func_003C26C8(void *);

u8 *func_L01_0032C320(s128_0032C7A0 *pos, s128_0032C7A0 *rot) {
    f32 tmp[4];
    f32 a[4];
    f32 c[4];
    f32 b[4];
    f32 d[12];
    f32 h;
    u16 n;
    s32 cnt;
    u8 *v;
    u8 *p;
    u8 *m = func_003BCFB0(0x1366, 0x80);
    if (m != 0) {
        *(f32 *)(m + 0x2C) *= 0.75f;
        m[0x30] = *(s16 *)(m + 0x32) = 0xFF;
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x20] = 0;
        p = m + 0x10;
        v = *(u8 **)(m + 0x68);
        *(s128_0032C7A0 *)(m + 0x10) = *pos;
        *(s128_0032C7A0 *)v = *rot;
        func_00388BD0(m + 0xC0, D_001A71A0[0] + 0xF0);
        func_L01_004C41E8_0032C320(p, tmp);
        func_00388830(a, m + 0xE0, 1.0f);
        func_00388758(b, a, tmp);
        h = func_00388730(a, tmp) * 0.5f;
        func_003886E8(c, b, func_00388978(h));
        c[3] = func_00388960(h);
        func_003890D8(c, d);
        func_00388EB8(m + 0xC0, d, m + 0xC0);
        *(s32 *)(v + 0x68) = 0;
        n = (D_L01_002C5640_0032C320 + D_001425C0[0x15])->x54;
        cnt = D_L01_001DCE88_0032C320;
        qzero(v + 0x10);
        *(s16 *)(v + 0x66) = 0;
        *(f32 *)(v + 0x10) = 1.0f;
        *(s32 *)(v + 0x50) = 0;
        *(s128_0032C7A0 *)(v + 0x30) = *(s128_0032C7A0 *)(v + 0x10);
        *(s32 *)(v + 0x44) = 0;
        *(u16 *)(v + 0x64) = n;
        *(s16 *)(v + 0x4C) = 1;
        *(s32 *)(v + 0x40) = cnt;
        *(s128_0032C7A0 *)(v + 0x20) = *(s128_0032C7A0 *)(v + 0x10);
        *(f32 *)(v + 0x58) = 0.026179942f;
        *(s32 *)(v + 0x48) = func_L01_004C4548_0032C320((s32)m, 0);
        if (*(s32 *)(v + 0x48) == -1) {
            func_003BD360(m);
            return 0;
        }
        *(s8 *)(v + 0x4F) = func_L01_004C4A18_0032C320(m, 0, 1.0f, 1.0f, 1.0f);
        *(s8 *)(v + 0x4E) = -1;
        *(s32 *)(v + 0x70) = 0;
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L01_0032C320 */
