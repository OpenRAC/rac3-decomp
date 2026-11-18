#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BD078 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_L05_003BB120;

extern u16 D_L05_002A64C0[][4];
extern u16 D_L05_002A6510[][4];
extern s16 D_L05_002A6560[][4];
extern u8 D_L05_002A4BC0[];
extern f32 D_L05_001DEAE8;
__asm__(".extern D_L05_001DEAE8, 4");
extern f32 D_L05_001DEAEC;
__asm__(".extern D_L05_001DEAEC, 4");

extern s32 func_0038CB00(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L05_003BD078(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V4_L05_003BB120 tmp0;
    V4_L05_003BB120 tmp1;
    V4_L05_003BB120 tmp2;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (n = 0; n < 4; n++) {
        if (func_0038CB00(&D_L05_002A64C0[*(s32 *)(p + 0x60)][n]) != 0) {
            D_L05_002A6510[*(s32 *)(p + 0x60)][n] = 0;
            D_L05_002A64C0[*(s32 *)(p + 0x60)][n] = (D_L05_002A6560[*(s32 *)(p + 0x60)][n] * 5 + 2) / 6;
            tmp0 = *(V4_L05_003BB120 *)(p + 0x30);
            vec_sub_ba(&tmp1, &tmp0, obj + 0x10);
            func_0038CF68(&tmp1, &tmp1, D_L05_001DEAE8);
            vec_add_ab(&tmp1, &tmp0, &tmp1);
            for (i = 0; i < 10; i++) {
                s32 off;
                f32 t = (f32)i * 0.1f;
                if (i == 9) {
                    t = 1.0f;
                }
                func_L01_00445208(&tmp2, obj + 0x10, &tmp0, p + 0x40, &tmp1, t);
                off = *(s32 *)(p + 0x60) * 0x280;
                *(V4_L05_003BB120 *)(D_L05_002A4BC0 + off + n * 0xA0 + i * 16) = tmp2;
            }
        }
        for (j = 2; j < 10; j++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + j * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0xA0 + *(s32 *)(p + 0x60) * 0x280 + j * 16) = tmp0;
        }
        for (k = 2; k < 10; k++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + k * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0x140 + *(s32 *)(p + 0x60) * 0x280 + k * 16) = tmp0;
        }
        for (l = 2; l < 10; l++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + l * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0x1E0 + *(s32 *)(p + 0x60) * 0x280 + l * 16) = tmp0;
        }
    }
}
/* localdecomp:end func_L05_003BD078 */

/* localdecomp:start func_L05_003BD448 */
typedef int u128_3BD448 __attribute__((mode(TI)));
typedef struct { s16 h[4]; } Row_3BD448;
typedef struct { u8 pad[0x32]; s16 h32; } M_3BD448;
typedef struct { u8 pad[0x20]; u8 b20; } M20_3BD448;

extern Row_3BD448 D_L05_002A64C0_003BD448[];
extern Row_3BD448 D_L05_002A6560_003BD448[];
extern s32 D_L05_001DEAE0;
__asm__(".extern D_L05_001DEAE0, 4");
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);

u8 *func_L05_003BD448(u8 *a0, u8 *a1, s32 a2, u8 *a3, s32 t0, s32 t1) {
    u8 *m;
    u8 *s;
    s32 i;
    s32 v;

    m = func_003C24B0(0x1B6F, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        *(s32 *)(s + 0x60) = t1;
        m[0x30] = 0xFF;
        ((M20_3BD448 *)m)->b20 = 0;
        ((M_3BD448 *)m)->h32 = 0xFF;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a1;
        *(u128_3BD448 *)(s + 0x30) = *(u128_3BD448 *)a3;
        *(u128_3BD448 *)(m + 0x10) = *(u128_3BD448 *)a0;
        v = (D_L05_001DEAE0 * 5 + 2) / 6;
        *(s32 *)(s + 0x10) = v;
        if (*(s16 *)(a1 + 0xAA) == 0x1BF6) {
            *(s32 *)(s + 0x10) = v * 10;
        }
        *(s32 *)(s + 0x1C) = t0;
        *(f32 *)(s + 0x14) = 1.0f / (f32)*(s32 *)(s + 0x10);
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF4) = func_00382538();
        *(f32 *)(m + 0xF8) = func_00382538();
        *(f32 *)(s + 0x0) = func_00382538();
        *(f32 *)(s + 0x4) = func_00382538();
        *(f32 *)(s + 0x8) = func_00382538();
        for (i = 0; i < 3; i++) {
            D_L05_002A64C0_003BD448[*(s32 *)(s + 0x60)].h[i] = -1;
            D_L05_002A6560_003BD448[*(s32 *)(s + 0x60)].h[i] = 5;
        }
        m[0x20] = 0;
    }
    return m;
}
/* localdecomp:end func_L05_003BD448 */

INCLUDE_ASM("asm/levels", func_L05_003BD5E0);

/* localdecomp:start func_L05_003BDB68 */
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x60 - 0x14];
    s32 x60;
} M_003BBBC8;

typedef struct {
    u8 pad0[0x68];
    M_003BBBC8 *x68;
    u8 pad6C[0xB8 - 0x6C];
    u8 *xB8;
} O_003BBBC8;

extern void func_L05_003BE190(void *, s32, s32, f32, f32, f32, s32, s32, s32);

void func_L05_003BDB68(O_003BBBC8 *o) {
    s32 c1 = 0xFF1010;
    s32 c2 = 0xFF2020;
    f32 half = 0.5f;
    M_003BBBC8 *m;
    s32 kind;
    s32 n;

    kind = *(s16 *)(o->xB8 + 0xAA);
    m = o->x68;
    if (kind == 0x1BF6 || kind == 0x1BDC || kind == 0x1B6C) {
        c1 = 0x1010FF;
        c2 = 0x2020FF;
    }
    if (m->x10 < 8) {
        n = m->x10 * 3;
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), n, n, half * 0.12f, half * 0.22f, 0.2f, 10, 0x7F7F7F, c2);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), m->x10 * 2, m->x10 * 2, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        return;
    }
    if (*(s16 *)(o->xB8 + 0xAA) == 0x1BF6) {
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), 0x80, 0x80, 0.2f, 0.4f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
    } else {
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), 0x32, 0x32, 0.04f, 0.15f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
    }
}
/* localdecomp:end func_L05_003BDB68 */

INCLUDE_ASM("asm/levels", func_L05_003BDFA8);

INCLUDE_ASM("asm/levels", func_L05_003BE190);
