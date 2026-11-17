/* NTSC-U draft (Claude wave K): C of func_L01_0039E5D8, the NTSC-U twin of func_L01_0039FBD0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L01_0039E5D8", whose code is not the PAL one).
 * Worker's note: 65 aligned words (first draft; @ps2as needed beyond the PAL line = flags at best): full body decoded and written (spawner 0x189B/0xC0, state byte 0x20 = D_L01_001D673C ? 0xA : 4, hero vector via func_00388E38/func_003BF360 or func_00388A28, table ...
 */
#include "common.h"

/* localdecomp:start func_L01_0039E5D8 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct E_0039E5D8 {
    u8 b0;
    u8 b1;
    u8 pad2[0xEE];
} E_0039E5D8;

extern s32 D_L01_001D6740[];
extern s32 D_L01_001D673C[];
extern s32 D_L01_001D67B0[];
extern s32 D_001D67B0_sda;
__asm__(".extern D_001D67B0_sda, 4");
extern u8 D_001425C0[];
extern E_0039E5D8 D_L01_002C5640[];
extern f32 D_001A4BE0[];
extern s32 D_001D545C[];

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_00388E38(void *, void *);
extern void func_003BF360(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_003D2D28(void *);
extern u8 *func_0037E0B8(void *);
extern void func_L01_00456960(s32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_003BD360(void *);
extern void func_003C26C8(void *);

u8 *func_L01_0039E5D8(u8 *o) {
    u8 *obj;
    u8 *p;
    u8 *t;
    u128_t tmp;
    s32 v;
    f32 f;

    obj = func_003BCFB0(0x189B, 0xC0);
    if (obj != 0) {
        obj[0x31] = 1;
        obj[0x30] = 0x7F;
        *(s16 *)(obj + 0x32) = 0x7F;
        p = *(u8 **)(obj + 0x68);
        *(f32 *)(obj + 0x48) = func_0037E250(0.85f, 1.15f);
        *(u16 *)(obj + 0x34) |= 0x20;
        func_L01_00438908(obj, 0x40, 0x10, 0x10);
        *(u128_t *)(obj + 0x10) = *(u128_t *)(o + 0x10);
        if (D_L01_001D6740[0] != 0 || D_L01_001D673C[0] != 0) {
            func_00388E38(&tmp, o + 0xC0);
            func_003BF360(&tmp, obj + 0xF0);
            v = 1;
        } else {
            *(u128_t *)(obj + 0xF0) = 0;
            *(f32 *)(obj + 0xF8) = func_00388A28(*(f32 *)(obj + 0x10) - D_001A4BE0[0x80 / 4], *(f32 *)(obj + 0x14) - D_001A4BE0[0x84 / 4]);
            v = 1;
        }
        obj[0x20] = v;
        *(s16 *)(p + 0x76) = 0;
        *(s16 *)(p + 0x74) = func_0037E208(0x78, 0x12C);
        *(s32 *)(p + 0x90) = 0x258;
        *(s32 *)(p + 0x94) = 0xF;
        *(s32 *)(p + 0x7C) = 0;
        *(s32 *)(p + 0x98) = 0;
        if (D_L01_002C5640[D_001425C0[0x8F]].b1 < 4) {
            *(s32 *)(p + 0xA4) = 0;
        } else {
            *(s32 *)(p + 0xA4) = 1;
        }
        obj[0x20] = (D_L01_001D673C[0] != 0) ? 0xA : 4;
        *(u8 **)p = p + 0x30;
        p[0x39] = 1;
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        func_L01_003D2D28(obj);
        *(s32 *)(p + 0xA8) = func_0037E208(0x64, 0x15E);
        f = 1.0f;
        if (D_L01_002C5640[D_001425C0[0x8F]].b1 != 0) {
            f = 4.0f;
        }
        *(f32 *)(p + 0x88) = f;
        *(s32 *)(p + 0x80) = -1;
        t = func_0037E0B8(o);
        if (t != 0) {
            t[0x17] = 0x8F;
        }
        if (D_001D545C[0] == 5 && *(s16 *)(o + 0xAA) == 0x19DB) {
            D_001D67B0_sda = D_L01_001D67B0[0] + 1;
            if (D_001D67B0_sda >= 0xF) {
                func_L01_00456960(7);
            }
        }
        if ((*(u16 *)(obj + 0x34) & 0x1000) != 0) {
            func_L01_004412D0(o, 0, 3);
        }
        if (t != 0 && t[0xE] == 1) {
            t[0xE] = 2;
        } else {
            func_003BD360(o);
        }
        func_003C26C8(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_0039E5D8 */
