#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034DAB8);

/* localdecomp:start func_L24_0034E250 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_L01_00445F40(u8 *, s32);
extern u8 *D_001A71A0[];

u8 *func_L24_0034E250(s32 a0, void *a1, void *a2, void *a3, s32 a4, f32 f12, f32 f13) {
    u8 *o = func_003C24B0(0x15AF, 0x80);
    u8 *s;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(long *)(o + 0x38) = *(long *)(D_001A71A0[0] + 0x38);
        *(u128_t *)(o + 0x10) = *(u128_t *)a2;
        *(u128_t *)(o + 0xF0) = *(u128_t *)a3;
        *(u128_t *)s = *(u128_t *)a1;
        *(s32 *)(s + 0x10) = a0;
        *(f32 *)(s + 0xC) = f12;
        *(f32 *)(s + 0x14) = f13;
        *(f32 *)(s + 0x20) = 0.15f;
        *(s32 *)(s + 0x2C) = 0x10001;
        *(s32 *)(s + 0x24) = 0;
        func_003C7C38(o);
    }
    func_L01_00445F40(o, a4);
    func_003C7C38(o);
    *(s32 *)(o + 0x98) = 0;
    return o;
}
/* localdecomp:end func_L24_0034E250 */

/* localdecomp:start func_L24_0034E370 */
typedef struct { s32 a, b; } P8_34E370;
typedef struct { u8 pad[0x19E0]; u8 *o; u8 pad2[8]; f32 f19EC; f32 f19F0; } S_34E370;
extern S_34E370 D_001A4BE0;
__asm__(".extern D_L24_001DD4E8, 4");
__asm__(".extern D_L24_001DD4EC, 4");
__asm__(".extern D_L24_001DD4F0, 4");
__asm__(".extern D_L24_001DD4F4, 4");
__asm__(".extern D_L24_001DD4F8, 4");
__asm__(".extern D_L24_001DD4FC, 4");
extern f32 D_L24_001DD4E8;
extern f32 D_L24_001DD4EC;
extern f32 D_L24_001DD4F0;
extern f32 D_L24_001DD4F4;
extern s32 D_L24_001DD4F8;
extern s32 D_L24_001DD4FC;
extern P8_34E370 D_L24_001DD500[];
extern s32 D_L24_001E06A0;
extern f32 D_L24_001E06A4;
extern s32 D_001D4BC4;
extern void func_L24_0041CE48(s32, s32, s32);
extern s32 func_L24_00402798(void);
extern void func_L24_00402808(void);
extern void func_L24_004027C8(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038C310(s32, s32, s32, s32, s32, void *);

static inline s32 sy_34E370(f32 v, f32 o) {
    return (s32)(v * D_L24_001E06A4 + 0.5f + (D_L24_001E06A0 == 1 ? o : 0.0f));
}

s32 func_L24_0034E370(void) {
    S_34E370 *b = &D_001A4BE0;
    u8 *s;
    f32 d;
    f32 t;
    s32 ca;
    s32 cb;

    if (b->o == 0) {
        func_L24_0041CE48(0, 0, 1);
        return 0;
    }
    s = *(u8 **)(b->o + 0x68);
    func_L24_00402798();
    func_L24_00402808();
    d = (b->f19EC - *(f32 *)(s + 0x16C)) * 0.2f;
    if (__builtin_fabsf(d) > 1.0f) {
        d = d / __builtin_fabsf(d);
    }
    ca = D_L24_001DD4F8;
    cb = D_L24_001DD4FC;
    *(f32 *)(s + 0x16C) += d;
    t = *(f32 *)(s + 0x16C) / b->f19F0;
    {
    P8_34E370 col;
    P8_34E370 c0 = { ca, cb };
    col = c0;
    c0 = D_L24_001DD500[0];
    col.b = func_0038DBD8(ca, cb, t);
    func_0038C310((s32)D_L24_001DD4E8, D_001D4BC4 - sy_34E370(D_L24_001DD4EC, -4.0f),
                  (s32)(D_L24_001DD4E8 + D_L24_001DD4F0),
                  D_001D4BC4 - sy_34E370(D_L24_001DD4EC, -4.0f) + sy_34E370(D_L24_001DD4F4, 0.0f),
                  0xFFFFF1, &c0);
    func_0038C310((s32)D_L24_001DD4E8, D_001D4BC4 - sy_34E370(D_L24_001DD4EC, -4.0f),
                  (s32)(D_L24_001DD4E8 + D_L24_001DD4F0 * t),
                  D_001D4BC4 - sy_34E370(D_L24_001DD4EC, -4.0f) + sy_34E370(D_L24_001DD4F4, 0.0f),
                  0xFFFFF1, &col);
    }
    func_L24_004027C8();
    return 1;
}
/* localdecomp:end func_L24_0034E370 */

/* localdecomp:start func_L24_0034E6B0 */
extern void func_L01_004C70A8(char *, char *, unsigned int *, float, int);
void func_L24_0034E6B0(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    unsigned int c;
    if (((unsigned char *)s)[0x1A4] != 0) {
        c = 0x80008000;
        func_L01_004C70A8(s + 0x170, s + 0x180, &c, 1.0f, 1);
    }
}
/* localdecomp:end func_L24_0034E6B0 */

INCLUDE_ASM("asm/levels", func_L24_0034E6F8);

/* localdecomp:start func_L24_0034EBF8 */
void func_L01_003EB5E0(s32, s32);
void func_L01_003F2AF8(s32, s32);

void func_L24_0034EBF8(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = *(s32 *)((u8 *)temp_s0 + 0x158);
    if (temp_a1 != 0) {
        func_L01_003F2AF8(0, temp_a1);
        *(s32 *)((u8 *)temp_s0 + 0x158) = 0;
        return;
    }
    func_L01_003EB5E0(0, 3);
}
/* localdecomp:end func_L24_0034EBF8 */

INCLUDE_ASM("asm/levels", func_L24_0034EC40);

INCLUDE_ASM("asm/levels", func_L24_0034ED28);
