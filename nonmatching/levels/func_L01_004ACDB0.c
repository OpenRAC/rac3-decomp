/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004A93C0, the NTSC-U twin of func_L01_004ACDB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_004AC1C0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L01_004A93C0 */
/* Needs @ps2as (float immediates) beyond the PAL file's flags. */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004A93C0;
typedef struct {
    u8 pad0[0x2A];
    s16 h2A;
    u8 pad2C[0x70 - 0x2C];
    u8 b70[0x10];
    V4_004A93C0 v80;
} S_004A93C0;
typedef struct {
    u8 pad0[0x25E5];
    u8 b25E5;
} Hero_004A93C0;

extern Hero_004A93C0 D_001A4BE0;
extern S_004A93C0 D_0016C580;
extern s32 D_L01_001D673C;
extern s32 D_001D673C_sda;
__asm__(".extern D_001D673C_sda, 4");
extern u8 D_001439F4[];

extern void func_0039CC78(void);
extern void func_L01_0050CAF8(void);
extern void func_L01_00500F10(s32);
extern void func_L01_0050ED60(void);
extern void func_L01_003F32F0(s32, f32);
extern void func_L01_0045D318(s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_004F12C0(void *, void *, s32, s32);

void func_L01_004A93C0(void) {
    V4_004A93C0 pos;
    u8 *a;
    S_004A93C0 *s;
    u8 m;

    func_0039CC78();
    D_001A4BE0.b25E5 = 0;
    func_L01_0050CAF8();
    s = &D_0016C580;
    if (s->h2A != 0) {
        func_L01_00500F10(1);
        D_001A4BE0.b25E5 = 0;
        func_L01_0050CAF8();
        if (D_L01_001D673C == 0) {
            func_L01_0050ED60();
        }
        func_L01_003F32F0(0, 8.0f);
        func_L01_0045D318(0);
        return;
    }
    if (D_001D673C_sda == 0) {
        *(u128_t *)&pos = *(u128_t *)&s->v80;
        m = D_001439F4[0];
        if (m == 0) {
            a = s->b70;
            pos.z = func_00389380(s->v80.z, -1.08f);
            func_L01_004F12C0(a, &pos, 0, 1);
            pos.z = func_00389380(s->v80.z, 1.22f);
            func_L01_004F12C0(a, &pos, 0, 0);
        } else {
            if (m == 2) {
                pos.z = func_00389380(s->v80.z, -0.15f);
            } else {
                pos.z = func_00389380(s->v80.z, -0.95f);
            }
            func_L01_004F12C0(s->b70, &pos, 0, 1);
        }
    } else {
        func_L01_004F12C0(s->b70, &s->v80, 0, 1);
    }
    func_L01_003F32F0(0, 8.0f);
    func_L01_0045D318(0);
}
/* localdecomp:end func_L01_004A93C0 */
