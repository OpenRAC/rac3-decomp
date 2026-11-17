#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0040E918 */
extern vu0_v4 D_L14_001E20C0;
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L14_0040E918(u8 *p) {
    vu0_v4 off;
    vu0_v4 out;
    vu0_v4 a;
    vu0_v4 b;
    *(vu0_q *)&off = 0;
    off.y = 2.0f;
    off.z = 6.0f;
    if (p != 0) {
        a = D_L14_001E20C0;
        b = *(vu0_v4 *)(p + 0x10);
        func_003C4098(&out, &a, &b, 0.5f);
        vec_add_ab(&out, &out, &off);
        func_003D9508(&out, 0xB, 0x30406080, 1, 15.0f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L14_0040E918 */

/* localdecomp:start func_L14_0040E9D0 */
extern int D_L14_001EEC50[];

int func_L14_0040E9D0(void)
{
    int i;
    int *base = D_L14_001EEC50;
    int *p = base + 4;
    for (i = 0; i < 0x28; i++) {
        if (*p <= 0)
            return i;
        p += 8;
    }
    return -1;
}
/* localdecomp:end func_L14_0040E9D0 */

/* localdecomp:start func_L14_0040EA08 */
extern s32 D_L14_001E64B4[];
extern u8 D_L14_001EF150[];
void func_L14_0040EA08(void) {
    s32 i;
    u8 *p;
    u8 *base;
    if (D_L14_001E64B4[0] == 1) {
        p = (u8 *)D_L14_001EEC50;
        for (i = 39; i >= 0; i--) {
            qzero(p);
            *(s32 *)(p + 0x10) = 0;
            p += 0x20;
        }
        base = D_L14_001EF150;
        for (i = 0; i < 14; i++) {
            p = base + i * 0x30;
            qzero(p);
            qzero(p + 0x10);
            *(s32 *)(p + 0x24) = 0;
        }
    }
}
/* localdecomp:end func_L14_0040EA08 */

/* localdecomp:start func_L14_0040EA78 */
typedef struct {
    u8 pad[0x34];
    s32 f34;
} S_40EA78;
extern S_40EA78 D_L14_001E6480;
extern vu0_v4 D_L14_001D66B0 __attribute__((section(".sdata")));
extern vu0_v4 D_L14_001E20E0;
__asm__(".extern D_L14_001D6BC0, 4");
__asm__(".extern D_L14_001D6BC4, 4");
__asm__(".extern D_L14_001D6BC8, 4");
__asm__(".extern D_L14_001D6BD0, 4");
__asm__(".extern D_L14_001D6C18, 4");
extern s32 D_L14_001D6BC0;
extern s32 D_L14_001D6BC4;
extern s32 D_L14_001D6BC8;
extern f32 D_L14_001D6BD0;
extern s32 D_L14_001D6C18;
extern void func_0038D570(void *, void *);
extern void func_L14_003F9A10(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_L14_0040EA78(void) {
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    u8 *p;
    u8 *q;
    u8 *end;
    s32 i;
    s32 c;
    f32 t;
    p = (u8 *)D_L14_001EEC50;
    for (i = 39; i >= 0; i--) {
        if (*(s32 *)(p + 0x10) >= 0) {
            func_0038D570(m, &D_L14_001E20E0);
            m[3] = D_L14_001D66B0;
            func_L14_003F9A10(m, m, *(f32 *)(p + 0xC));
            c = D_L14_001D6BC4;
            t = (f32)*(s32 *)(p + 0x10) / (f32)D_L14_001D6BC8;
            m[3] = *(vu0_v4 *)p;
            func_003D9740(m, D_L14_001D6BC0, ((s32)(t * 0.6f * (f32)c) << 24) | (c << 16) | (c << 8) | c, 10, 1, 0.0f);
            *(f32 *)(p + 0xC) += t * D_L14_001D6BD0;
            *(s32 *)(p + 0x10) -= 1;
        }
        p += 0x20;
    }
    if (D_L14_001E6480.f34 < 0x466) {
        for (i = 0; i < 14; i++) {
            q = D_L14_001EF150 + i * 0x30;
            if (*(s32 *)(q + 0x24) >= 0) {
                a = *(vu0_v4 *)q;
                b = *(vu0_v4 *)(q + 0x10);
                func_L01_0040A8C0(&a, &b, 0x16, 1, D_L14_001D6C18, D_L14_001D6C18, 0, 0, *(f32 *)(q + 0x20), 2.0f, 0.0f);
                *(f32 *)(q + 0x20) += 0.008f;
            }
        }
    }
}
/* localdecomp:end func_L14_0040EA78 */

INCLUDE_ASM("asm/levels", func_L14_0040EC48);

/* localdecomp:start func_L14_0040EF88 */
/* PAL port of the NTSC-U match src/us/levels/func_L14_0040C0A8.c */
#include "vu0.h"

/* NTSC-U counterpart of func_L14_0040EF88 (src/levels/14_koros/L14_0040E918.c): queues one spark at a random
 * point on a cone around the centre, into the D_L14_001EEC50_0040C0A8 record list */

extern s32 D_001D6BE0_sda;
__asm__(".extern D_001D6BE0_sda, 4");
extern s32 D_001D6BF0_sda;
__asm__(".extern D_001D6BF0_sda, 4");
extern f32 D_001D6BBC_sda;
__asm__(".extern D_001D6BBC_sda, 4");
extern f32 D_001D6BB8_sda;
__asm__(".extern D_001D6BB8_sda, 4");
extern s32 D_001D6C00_sda;
__asm__(".extern D_001D6C00_sda, 4");
extern f32 D_001D6C08_sda;
__asm__(".extern D_001D6C08_sda, 4");
extern f32 D_001D6C10_sda;
__asm__(".extern D_001D6C10_sda, 4");
extern f32 D_001D6C14_sda;
__asm__(".extern D_001D6C14_sda, 4");
extern f32 D_001D6BD0_sda;
__asm__(".extern D_001D6BD0_sda, 4");
extern s32 D_001D6BCC_sda;
__asm__(".extern D_001D6BCC_sda, 4");
extern s32 D_001D6BC8_sda;
__asm__(".extern D_001D6BC8_sda, 4");

extern s32 D_L14_001E64B4_0040C0A8[];
extern u8 D_L14_001E20E0_0040C0A8[];
extern u8 D_L14_001D66B0_0040C0A8;
extern u8 D_L14_001EEC50_0040C0A8[];

extern void func_0038D570(void *, void *);
extern void func_L14_003F9A10(void *, void *, f32);
extern s32 func_L14_0040E9D0(void);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_003C4C18(void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L14_0040EC48(void *);

void func_L14_0040EF88(f32 a, f32 b, void *o, s32 base, s32 flag) {
    u8 vA[16] __attribute__((aligned(16)));
    u8 vB[16] __attribute__((aligned(16)));
    f32 dir[4];
    u8 sum[16] __attribute__((aligned(16)));
    f32 m[16];
    u8 ev[16] __attribute__((aligned(16)));
    s32 dt;
    s32 idx;
    f32 x;
    f32 y;
    f32 s;
    f32 c;
    u8 *e;

    dt = D_L14_001E64B4_0040C0A8[0] - (base * 5 + 2) / 6;
    *(vu0_q *)vA = *(vu0_q *)&D_001D6BE0_sda;
    x = a * 0.017453292f;
    vec_add_ab(vA, &D_001D6BE0_sda, &D_001D6BF0_sda);
    y = b * 0.017453292f;
    func_0038D570(m, D_L14_001E20E0_0040C0A8);
    *(vu0_q *)(m + 12) = *(vu0_q *)&D_L14_001D66B0_0040C0A8;
    func_L14_003F9A10(m, m, D_001D6BBC_sda);
    if (dt < D_001D6C00_sda) {
        idx = func_L14_0040E9D0();
        if (idx != -1) {
            *(vu0_q *)vB = *(vu0_q *)vA;
            if (flag != 0) {
                s = (f32)dt;
                x = func_0038DAB8(x, s * D_001D6C08_sda * 0.017453292f);
                s = s * D_001D6C10_sda;
                y = func_0038DAB8(y, s * 0.017453292f);
            } else {
                s = (f32)dt;
                x = func_0038DB00(x, s * D_001D6C08_sda * 0.017453292f);
                s = s * D_001D6C10_sda;
                y = func_0038DB00(y, s * 0.017453292f);
            }
            c = func_0038D0B0(y);
            dir[0] = D_001D6BB8_sda * c * func_0038D098(x);
            dir[1] = D_001D6BB8_sda * c * func_0038D0B0(x);
            dir[2] = D_001D6BB8_sda * func_0038D098(y);
            func_003C4C18(dir, D_001D6C14_sda);
            vec_add_ab(sum, vB, dir);
            e = D_L14_001EEC50_0040C0A8 + (idx << 5);
            *(vu0_q *)e = *(vu0_q *)sum;
            *(f32 *)(e + 0xC) = D_001D6BD0_sda;
            *(s32 *)(e + 0x10) = func_00382498(D_001D6BCC_sda, D_001D6BC8_sda);
            *(vu0_q *)ev = *(vu0_q *)e;
            func_L14_0040EC48(ev);
        }
    }
}
/* localdecomp:end func_L14_0040EF88 */

INCLUDE_ASM("asm/levels", func_L14_0040F1B8);
