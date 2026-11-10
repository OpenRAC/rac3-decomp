/* Level 02 (Florana), PAL. 208 diff with check.py --target level_02 --as ps2as. about 208 differences, most of them one instruction shift: retail fills the `beqz` delay slot after `func_00382380(..., p->f1C, 0)` with `lhu $v0, lo(D_001A7C10)($s2)`, this C with `lui $v0`; in about seven bit-test blocks retail keeps the shift index in `$a1` and the word in `$v1` (this C `$v0`/`$a0`); near the end retail hoists `addiu $s1,$s5,lo(D_001A4BE0)` into a `bnez` delay slot. Structure, calls, frame (0x60) and constants (501.0f is 0x43FA8000) match. Needs `@ps2as` for L02_00313B38.c. */
#include "common.h"

typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0xF]; u8 f30; u8 pad31[0x37]; void *p; } A_313B38;
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34; f32 f38; s32 f3C, f40, f44, f48, f4C, f50, f54, f58; } P_313B38;
typedef int u128_t __attribute__((mode(TI)));

typedef struct { u16 h0; u8 pad2[0x16]; u16 h18; u8 pad1A[0x16]; u16 h30; u8 pad32[0xA]; u16 h3C; u8 pad3E[0x15A]; u16 h198; u8 pad19A[0x3A]; u16 h1D4; } T7C10_313B38;
typedef struct { u8 pad0[0xD8]; u16 hD8; u8 padDA[0x6]; u32 wE0; u8 padE4[0x24]; u16 h108; u8 pad10A[0x2]; u32 w10C; u8 pad110[0x60]; u32 w170; u8 pad174[0x30]; u16 h1A4; u8 pad1A6[0x12]; u32 w1B8; u8 pad1BC[0x8]; u32 w1C4; u16 h1C8; u8 pad1CA[0xA]; u16 h1D4; u8 pad1D6[0x12]; u32 w1E8; u8 pad1EC[0x4]; u32 w1F0; u8 pad1F4[0x478]; u16 h66C; u8 pad66E[0xA]; u16 h678; u8 pad67A[0x9A]; u16 h714; u8 pad716[0x556]; u16 hC6C; u8 padC6E[0x6]; u32 wC74; u8 padC78[0x3E0]; u32 w1058; } T7E18_313B38;
typedef struct { u8 pad0[0x1298]; s32 w1298; u8 pad129C[0x12A8]; s32 w2544; } T4C60_313B38;
typedef struct { u8 pad0[0x25C4]; s32 w25C4; u8 pad25C8[0x288]; s32 w2850; } T4BE0_313B38;
extern T7C10_313B38 D_001A7C10;
__asm__(".extern D_001A7C10, 16");
extern T4C60_313B38 D_001A4C60;
__asm__(".extern D_001A4C60, 16");
extern T7E18_313B38 D_001A7E18;
__asm__(".extern D_001A7E18, 16");
extern T4BE0_313B38 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern s32 D_001C5290[][16];
__asm__(".extern D_001C5290, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D4C38;
__asm__(".extern D_001D4C38, 16");
extern s32 D_001D4C38_sda;
__asm__(".extern D_001D4C38_sda, 4");
extern u8 D_001D5573[];
__asm__(".extern D_001D5573, 16");
extern f32 D_L02_001DFAC0;
__asm__(".extern D_L02_001DFAC0, 16");
extern f32 D_L02_001DFAC0_sda;
__asm__(".extern D_L02_001DFAC0_sda, 4");

extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00513EF0(void);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L02_003E71A8(void *, void *, f32);
extern void func_L01_00459C50(s32);




void func_L02_00313B38(A_313B38 *a) {
    P_313B38 *p = a->p;
    s32 n;
    u32 v;
    f32 fv;
    f32 vec[4] __attribute__((aligned(16)));
    f32 lim;

    switch (a->state) {
    case 0:
        a->f30 = 0xFF;
        p->f3C = 0;
        p->f54 = 0;
        p->f4C = 100;
        p->f50 = 150;
        p->f58 = 100;
        func_L01_004450F0(a, 1, -1);
        break;
    case 1:

    if (D_001A7C10.h3C < 2 && func_00382380(&D_001A4C60, p->f0, 0)) {
        if (p->f18 < 100) p->f18++;
        if (p->f18 > 0x32) {
            if (func_L01_00513EF0()) {
                if (D_001A7E18.h66C == 0) func_L01_0041A5B0(0xCE0, 0x89);
            } else {
                if (D_001A7E18.h1C8 == 0) func_L01_0041A5B0(0xB83, 0x26);
            }
        }
    }
    if (D_001A7C10.h30 < 2 && func_00382380(&D_001A4C60, p->f4, 0)) {
        if (func_L01_00513EF0()) {
            if (D_001A7E18.h678 == 0) func_L01_0041A5B0(0xCE1, 0x8A);
        } else {
            if (D_001A7E18.h1D4 == 0) func_L01_0041A5B0(0xB84, 0x27);
        }
    }
    if (D_001A7C10.h18 < 2 && func_00382380(&D_001A4C60, p->fC, 0)) {
        T7E18_313B38 *e = &D_001A7E18;
        if (D_001A4C60.w1298 == 3) {
            if (!(e->w1058 & (1 << D_001D545C))) func_L01_0041A5B0(0x1863, 0x15C);
        } else {
            if (!(e->w1E8 & (1 << D_001D545C))) func_L01_0041A5B0(0xB85, 0x28);
        }
    }
    if (func_00382380(&D_001A4C60, p->f8, 0)) {
        if (func_0038CAD0(&p->f54)) {
            n = (D_001D4C38_sda * 5 + 2) / 6;
            v = D_001A7E18.w10C;
            if ((u32)(n - v) > 0x384 || v == 0) func_L01_0041A5B0(0xB42, 0x16);
            else if (v < n) D_001A7E18.w10C = n;
        }
    }
    if (func_00382380(&D_001A4C60, p->f10, 0)) {
        D_001A7E18.h108 = 0xFFFF;
        if (func_0038CAD0(&p->f4C)) {
            if (!(D_001A7E18.wE0 & (1 << D_001D545C_sda))) func_L01_0041A5B0(0xA49, 0x12);
        }
    }
    if (D_001A4BE0.w25C4 == 0x76) D_001A7E18.hD8 = 0xFFFF;
    if (func_00382380((u8 *)&D_001A4BE0 + 0x80, p->f28, 0)) {
        if (func_0038CAD0(&p->f50)) {
            if (!(D_001A7E18.wC74 & (1 << D_001D545C))) func_L01_0041A5B0(0x1407, 0x109);
        }
    }
    if (func_00382380(&D_001A4C60, p->fC, 0)) D_001A7E18.hC6C = 0xFFFF;
    func_00382380(&D_001A4C60, p->f40, 0);
    func_00382380(&D_001A4C60, p->f14, 0);
    if (D_001A7E18.h1A4 == 0 && D_001A4C60.w2544 != 0x65) func_0038CAD0(&p->f58);
    if (func_00382380(&D_001A4C60, p->f1C, 0) && D_001D5573[0] == 0) {
        n = (D_001D4C38 * 5 + 2) / 6;
        v = D_001A7E18.w1F0;
        if ((u32)(n - v) > 0x384 || v == 0) func_L01_0041A5B0(0xB86, 0x29);
        else if (v < n) D_001A7E18.w1F0 = n;
    }
    if (D_001A7C10.h0 < 2 && func_00382380(&D_001A4C60, p->f20, 0)) {
        if (!(D_001A7E18.w1C4 & (1 << D_001D545C))) func_L01_0041A5B0(0xB82, 0x25);
    }
    if (D_001A7C10.h198 < 3 && func_00382380(&D_001A4C60, p->f24, 0) && !func_L01_00513EF0()) {
        if (!(D_001A7E18.w1B8 & (1 << D_001D545C))) func_L01_0041A5B0(0xB81, 0x24);
    }
    if (D_001C5290[D_001D545C][p->f44] == 2 || D_001C5290[D_001D545C][p->f48] == 2) {
        if (!(D_001A7E18.w170 & (1 << D_001D545C))) func_L01_0041A5B0(0xB7B, 0x1E);
    }
    *(u128_t *)vec = 0;
    vec[0] = 501.0f;
    vec[1] = 553.89f;
    vec[2] = 315.4f;
    if (func_L02_003E71A8(vec, &D_001A4C60, 7.0f)) {
        if (D_001A7E18.h714 == 0) {
            if (D_001A7C10.h1D4 == 0) {
                func_L01_0041A5B0(0xCF0, 0x97);
            } else {
                fv = D_L02_001DFAC0_sda;
                goto skip;
            }
        }
    }
    fv = D_L02_001DFAC0;
skip:
    lim = (f32)D_001A4BE0.w2850 + fv;
    if (!func_00382380((u8 *)&D_001A4BE0 + 0x80, p->f34, 0)) p->f3C = 0;
    if (p->f3C == 0) {
        if (func_00382380((u8 *)&D_001A4BE0 + 0x80, p->f2C, 0)) {
            p->f3C = 1;
            p->f38 = (f32)D_001A4BE0.w2850;
        }
    }
    if (p->f3C == 1) {
        if (p->f38 < lim) p->f38 = lim;
        else if (lim < p->f38) p->f3C = -1;
        if (p->f3C == 1) {
            if (func_00382380(&D_001A4C60, p->f30, 0)) func_L01_00459C50(1);
        }
    }
    }
}
