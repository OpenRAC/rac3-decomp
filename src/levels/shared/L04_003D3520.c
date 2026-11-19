#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L04_003D3520);

/* localdecomp:start func_L04_003D37F8 */
typedef int Q_003D37F8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D37F8;
extern s32 D_L04_001DF940;
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);

void func_L04_003D37F8(u8 *self, u8 *p) {
    V_003D37F8 pos, vel, tmp;
    s32 c, color;
    f32 size;
    V_003D37F8 *vp;
    if (!(D_L04_001DF940 & 1)) {
        *(f32 *)(p + 0x9C) = func_0038DAB8(*(f32 *)(p + 0x9C), func_L01_00443A18(0.052359879f, 0.104719758f));
        *(Q_003D37F8 *)&pos = *(Q_003D37F8 *)(self + 0x10);
        pos.z += 1.0f;
        pos.x += func_0038D098(*(f32 *)(p + 0x9C)) * func_L01_00443A18(0.5f, 1.0f);
        pos.y += func_0038D0B0(*(f32 *)(p + 0x9C)) * func_L01_00443A18(0.5f, 1.0f);
        if (*(s32 *)(p + 0x90)) {
            func_0038CE20(&tmp, self + 0xC0, 3.0f);
            vec_add_ab(&pos, &tmp, &pos);
        }
        vel.x = func_0038D098(*(f32 *)(p + 0x9C)) * (func_003824E0(0.5f, 2.0f) * 0.020000001f);
        vel.y = func_0038D0B0(*(f32 *)(p + 0x9C)) * (func_003824E0(0.5f, 2.0f) * 0.020000001f);
        vel.z = 0.0f;
        vel.z = func_003824E0(0.040000003f, 0.100000009f);
        c = func_00382498(0x10, 0x20);
        color = (c << 16) | 0x80000000 | (c << 8) | c;
        vp = &vel;
        size = func_003824E0(3.0f, 5.0f) * 210000.0f;
        func_L01_004668A0(&pos, vp, color, 0x101010, (func_00382498(0x50, 0x78) * 5 + 2) / 6, size);
    }
}
/* localdecomp:end func_L04_003D37F8 */

INCLUDE_ASM("asm/levels", func_L04_003D3A30);

/* localdecomp:start func_L04_003D3AC8 */
typedef void (*Fn_003CF2A0)(u8 *);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);
typedef struct { u8 pad0[0x10]; s32 w10; } Q_3D3AC8;
typedef struct { u8 pad0[0x24]; Q_3D3AC8 *w24; u8 pad28[0x98 - 0x28]; s32 w98; } R_3D3AC8;
typedef struct {
    u8 pad0[0x19E0];
    s32 w19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    R_3D3AC8 *w25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_3D3AC8;
typedef struct { u8 pad0[0x20]; u8 b20; u8 padBC[0xBC - 0x21]; u8 bBC; } M_3D3AC8;
extern G_3D3AC8 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern void func_L01_003EB5E0(s32, s32);
extern void func_L04_003D3EE0(void);
extern void func_L04_0050CB28(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
void func_L04_003D3AC8(M_3D3AC8 *m) {
    u8 t = m->b20;
    if (t == 2) {
        func_L01_003EB5E0(0, 0);
        func_L04_003D3EE0();
        D_001A4BE0.w25C0->w98 = D_001A4BE0.w25C0->w24->w10;
        D_001A4BE0.b25E5 = 0;
        func_L04_0050CB28(0, 1);
        D_001A4BE0.w19E0 = 0;
        m->bBC = t;
        func_L01_004450F0(m, 1, -1);
        func_L01_00456230(m, 0);
        func_003C3A10(m, 0, 0, 1);
    }
    (*func_L01_0043B548(0x19E1, 0x6C))((u8 *)m);
}
/* localdecomp:end func_L04_003D3AC8 */

INCLUDE_ASM("asm/levels", func_L04_003D3B90);

/* localdecomp:start func_L04_003D3EE0 */
extern void func_L01_00517918(s32);
void func_L04_003D3EE0(void) {
    func_L01_00517918(13);
}
/* localdecomp:end func_L04_003D3EE0 */

/* localdecomp:start func_L04_003D3F00 */
__asm__(".extern D_L04_001DEC04, 4");
extern f32 D_L04_001DEC04;
__asm__(".extern D_L04_001DEBF8, 4");
extern f32 D_L04_001DEBF8;
extern void func_L01_00517538(s32 a0, f32 a1, f32 a2);

void func_L04_003D3F00(void *a0, u8 *a1)
{
    f32 t = *(f32 *)(a1 + 48) / (f32)*(s16 *)(a1 + 52);

    func_L01_00517538(0x490004, D_L04_001DEC04 * t, D_L04_001DEBF8);
    func_L01_00517538(0x490005, D_L04_001DEC04 * t, D_L04_001DEBF8);
}
/* localdecomp:end func_L04_003D3F00 */

INCLUDE_ASM("asm/levels", func_L04_003D3F68);
