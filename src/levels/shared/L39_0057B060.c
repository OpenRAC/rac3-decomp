#include "common.h"

/* localdecomp:start func_L39_0057B060 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 pad20[896 - 32];
    f32 c[3];
    f32 pad38C;
    f32 a[3];
    f32 pad39C;
    f32 b[3];
    f32 pad3AC;
    f32 m[3][4];
    u128_t pos2;
    u8 pad3F0[1064 - 1008];
    f32 fov;
    u8 pad42C[1081 - 1068];
    u8 mode;
    u8 pad43A[1120 - 1082];
} Cam_0057A0B8;

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 unk20[48];
} View_0057A0B8;

extern s32 *D_L39_00241120;
extern Cam_0057A0B8 D_L39_0024DE80[];
extern View_0057A0B8 D_L39_0024DE00;
extern f32 D_L39_0025D770[];
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CD28(void *, void *, s32);

void func_L39_0057B060(s32 idx)
{
    Cam_0057A0B8 *e;
    f32 h;

    if (*D_L39_00241120 >= 2) {
        if (D_L39_0024DE80[idx].mode == 1) {
            h = D_L39_0024DE80[idx].fov * 0.5f;
            D_L39_0025D770[0] = func_0038D0B0(h) / func_0038D098(h);
        } else {
            D_L39_0025D770[0] = 0.62f;
        }
    }
    e = &D_L39_0024DE80[idx];
    e->m[0][0] = -e->a[0];
    e->m[1][0] = -e->a[1];
    e->m[2][0] = -e->a[2];
    e->m[0][1] = -e->b[0];
    e->m[1][1] = -e->b[1];
    e->m[2][1] = -e->b[2];
    e->m[0][2] = e->c[0];
    e->m[1][2] = e->c[1];
    e->m[2][2] = e->c[2];
    e->pos2 = e->pos;
    D_L39_0024DE00.pos = e->pos;
    D_L39_0024DE00.unk10 = D_L39_0024DE80[idx].unk10;
    func_0038CD28(D_L39_0024DE00.unk20, D_L39_0024DE80[idx].c, 48);
}
/* localdecomp:end func_L39_0057B060 */

/* localdecomp:start func_L39_0057B1C0 */
#include "vu0.h"
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[3]; void *f24; u8 p28[0x98 - 0x28]; s32 f98; } P_0057B1C0;
typedef struct { u128_t q0, q10, q20, q30; } Src_0057B1C0;
typedef struct {
    u128_t pos;
    u8 p10[0x50 - 0x10];
    Src_0057B1C0 *f50;
    s32 f54;
    u8 p58[0x2A0 - 0x58];
    s16 h2A0;
    u8 p2A2[0x380 - 0x2A2];
    u128_t c380;
    u128_t c390;
    u128_t c3A0;
    u8 p3B0[0x410 - 0x3B0];
    u128_t q410;
    u8 p420[0x454 - 0x420];
    s32 f454;
    s32 f458;
    u8 p45C[0x460 - 0x45C];
} E_0057B1C0;
typedef struct { u8 p0[0xF4]; P_0057B1C0 *fF4; s32 pF8[2]; s32 f100; } R_0057B1C0;
extern P_0057B1C0 *D_L39_0024B940[16] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B940, 64");
extern u128_t D_L39_0024B900_0057B1C0[] __attribute__((section(".sdata")));
extern s32 D_L39_00242914;
extern s32 D_L39_00243200;
extern s32 D_001D7AE8_sda;
extern void func_00384AC8(s32);
extern void func_00384BB8(s32);
extern void func_00384498(s32, s32);
extern void func_00383830(s32);
extern void func_003841B8(void *);
extern void func_003C48A8(void *, void *);
extern void func_00384260(s32, void *, s32);
extern void func_00384778(s32);
extern void func_00385EF0(void *);
extern void func_0038CAD0(void *);
extern void func_L01_004B14C8(s32);
extern void func_L39_0057AC28(s32);
extern s32 func_L39_005796D0(s32);
extern void func_L39_00578AA8(s32);
void func_L39_0057B060(s32);

void func_L39_0057B1C0(void)
{
    s32 saved[16];
    s32 k;
    s32 j;
    s32 i;
    E_0057B1C0 *e;
    R_0057B1C0 *r;
    Src_0057B1C0 *src;
    P_0057B1C0 *p;

    for (k = 0; k < 16; k++) {
        p = D_L39_0024B940[k];
        if (p != 0) {
            if (p->f20 == 0xFE) {
                D_L39_0024B940[k] = 0;
            } else if (p->f20 == 0xFD) {
                D_L39_0024B940[k] = 0;
            } else {
                saved[k] = p->f98;
                p->f98 = 0;
            }
        }
    }
    for (i = 0; i < *D_L39_00241120; i++) {
        e = (E_0057B1C0 *)(i * 0x460 + (s32)D_L39_0024DE80);
        r = (R_0057B1C0 *)((u8 *)e + 0x150);
        if (r->f100 == 0x31) {
            if (r->fF4 != 0) {
                r->fF4->f98 = 0;
            }
        }
        e->f454 = e->f454 + 1;
        func_00384AC8(i);
        func_00384BB8(i);
        func_L39_0057AC28(i);
        func_00384498(i, 0);
        func_L39_005796D0(i);
        src = e->f50;
        if (e->f458 > 0) {
            e->h2A0 = 0;
        }
        if ((u16)(e->h2A0 - 1) < 2) {
            func_00383830(e->f54);
        }
        if (e->h2A0 == 3) {
            func_003841B8(src);
        } else {
            e->pos = src->q30;
            e->c380 = src->q0;
            e->c390 = src->q10;
            e->c3A0 = src->q20;
        }
        func_003C48A8(&e->c380, (u8 *)e + 0x10);
        func_00384260(i, (u8 *)e + 0x20, 0);
        func_00384260(i, (u8 *)e + 0x30, 1);
        func_00384260(i, (u8 *)e + 0x40, 2);
        func_00384778(i);
        func_00385EF0(e);
        func_L39_00578AA8(i);
        qzero(&e->q410);
        if (r->f100 == 0x31) {
            if (r->fF4 != 0) {
                r->fF4->f98 = *(s32 *)((u8 *)r->fF4->f24 + 0x10);
            }
        }
        D_L39_0024B900_0057B1C0[i] = e->pos;
        func_0038CAD0(&e->f458);
    }
    if (D_L39_00242914 == 0 || (((E_0057B1C0 *)D_L39_0024DE80)->f50 != 0 && *(s16 *)((u8 *)((E_0057B1C0 *)D_L39_0024DE80)->f50 + 0x86) == 0x21)) {
        D_001D7AE8_sda = D_L39_00243200;
        func_L01_004B14C8(0);
        func_L39_0057B060(0);
    }
    for (j = 0; j < 16; j++) {
        p = D_L39_0024B940[j];
        if (p != 0) {
            p->f98 = saved[j];
        }
    }
}
/* localdecomp:end func_L39_0057B1C0 */
