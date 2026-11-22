#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_003E2B18 */
typedef int u128_t __attribute__((mode(TI)));

void func_L16_003E2C28(u8 *, u128_t *, s32);

void func_L16_003E2B18(void *arg0, s32 arg1) {
    vu0_v4 res;
    vu0_v4 tbl[3];

    *(u128_t *)&tbl[0] = 0;
    *(u128_t *)&tbl[1] = 0;
    *(u128_t *)&tbl[2] = 0;
    tbl[0].x = 0.799f;
    tbl[0].y = -0.011f;
    tbl[0].z = 1.179f;
    tbl[1].x = -0.852f;
    tbl[1].y = -0.001f;
    tbl[1].z = 1.174f;
    tbl[2].x = -0.147f;
    tbl[2].y = 0.009f;
    tbl[2].z = 1.185f;
    if (arg1 == 1) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[0]);
    }
    if (arg1 == 2) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[1]);
    }
    if (arg1 == 3) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[2]);
    }
    func_L16_003E2C28(arg0, (u128_t *)&res, 7);
}
/* localdecomp:end func_L16_003E2B18 */

/* localdecomp:start func_L16_003E2C28 */

void func_L16_003E2518(u8 *, u128_t *, s32, s32, s32, s32, s32, f32, f32);

void func_L16_003E2C28(u8 *arg0, u128_t *arg1, s32 arg2) {
    u128_t tmp;
    f32 *fp;

    tmp = *arg1;
    fp = (f32 *)&tmp;
    fp[2] = fp[2] + 0.5f;
    func_L16_003E2518(arg0, &tmp, 0x68, 0x69, arg2, 0, 2, 1.0f, 0.6f);
}
/* localdecomp:end func_L16_003E2C28 */

/* localdecomp:start func_L16_003E2C88 */
/* PAL port of the NTSC-U match src/us/levels/func_L16_003E0EB0.c */
#include "vu0.h"


extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *D_L16_002206D8[];

void func_L16_003E2C88(u8 *obj, u128_t *vec)
{
    f32 buf[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    s32 a2;
    u8 *r;

    *(u128_t *)pos = *vec;
    pos[2] = *(f32 *)(obj + 0x18) + 1.179f;
    for (i = 1; i >= 0; i--) {
        func_L01_00443B88(buf, 0.040000003f, 0.07000001f);
        f20 = fabs_asm(buf[2]);
        buf[2] = f20 + func_003824E0(1.0f, 2.5f) * 0.020000001f;
        f20 = func_003824E0(0.08f, 0.14f);
        a2 = (func_00382498(0x5A, 0x96) * 5 + 2) / 6;
        r = func_L01_004713C8(pos, buf, a2, 0x827770, -1, 0x7F, 0x7F, f20 * 210000.0f, f20 * 210000.0f, 0, 0.0038400004f);
        if (r != 0) {
            r[2] = D_L16_002206D8[0x61][func_00382468(3) + 0xA];
            r[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L16_003E2C88 */

/* localdecomp:start func_L16_003E2E30 */
extern u8 D_002206D8[];
extern s32 D_001DF3C0_sda;
__asm__(".extern D_001DF3C0_sda, 4");
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L16_003E2E30(u8 *a0, u128_t *a1) {
    f32 v[4];
    vu0_v4 pos;
    u8 *r;
    s32 i;

    *(u128_t *)&pos = *a1;
    pos.z = *(f32 *)(a0 + 0x18) + 1.179f;
    func_L01_00443B88(v, 0.0300000012f, 0.0500000045f);
    v[2] = fabs_asm(v[2]) + func_003824E0(0.7f, 1.5f) * 0.020000001f;
    r = func_L01_00475C60(&pos, v, (func_00382498(0x5A, 0x96) * 5 + 2) / 6, -1, D_001DF3C0_sda,
                          D_001DF3C0_sda & 0xFFFFFF, 16800.0f, 16800.0f, 5.6f, 0);
    if (r != 0) {
        r[2] = (*(u8 **)(D_002206D8 + 0x184))[func_00382468(3) + 0xA];
        r[3] = 0x44;
    }
    for (i = 0; i < 20; i++) {
        u8 *e;

        func_L01_00443B88(v, 0.004f, 0.007f);
        v[2] = fabs_asm(v[2]) + func_003824E0(0.3f, 1.1f) * 0.020000001f;
        e = func_L01_00475C60(&pos, v, 0x32, -1, D_001DF3C0_sda, D_001DF3C0_sda & 0xFFFFFF, 25200.0f, 48300.0f,
                              0.0f, 0);
        if (e != 0) {
            u8 *g = D_002206D8;

            e[2] = **(u8 **)(g + 0x10);
            e[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L16_003E2E30 */

/* localdecomp:start func_L16_003E3068 */
extern void func_L16_003E2B18(void *, s32);

void func_L16_003E3068(char *a, int bit)
{
    *(unsigned short *)(a + 0x7C) &= ~(1 << bit);
    (*(unsigned short **)(a + 0x68))[0x36 / 2]--;
    func_L16_003E2B18(a, bit);
}
/* localdecomp:end func_L16_003E3068 */
