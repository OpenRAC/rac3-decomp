#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_00350EE0);

/* localdecomp:start func_L11_003510D0 */
#include "vu0.h"
typedef struct { u8 pad0[0x18]; u8 *m; u8 pad1C[4]; vu0_v4 pos; } H_3510D0;
typedef struct { u8 pad0[0x80]; vu0_v4 pos; u8 pad90[0x1200 - 0x90]; u8 *gadget; u8 pad1204[0x25C0 - 0x1204]; u8 *hero; } G_3510D0;
extern H_3510D0 D_L11_001E84C0;
extern u8 D_L11_001D66B0[8];
extern u8 *D_L11_0021E558[];
extern G_3510D0 D_001A4BE0;
extern vu0_v4 D_001A4C60;
extern u8 *D_001D52FC;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern u8 *func_L11_00351528();
extern void func_L01_00456230(void *, s32);
extern u8 *func_L01_00472F58(void *, void *, s32, f32);
extern u8 *func_L01_00472560(void *, void *, s32, s32, f32);
extern void func_L01_00471BF0(void *, void *, s32);

void func_L11_003510D0(u8 *a0)
{
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 hit;
    vu0_v4 mtx[4];
    vu0_v4 p;
    s32 color = 0x3F2020FF;
    s32 n = 0;
    u8 *m;
    u8 *r;
    vu0_v4 *pp;
    s16 id;

    from = *(vu0_v4 *)(a0 + 0x10);
    to = *(vu0_v4 *)(*(u8 **)(a0 + 0x68) + 0x100);
    do {
        if (func_003D3CB0(&from, &to, 0, a0, 0) == 0) {
            goto miss;
        }
        pp = &D_L11_001E84C0.pos;
        hit = *pp;
        func_L01_0040A8C0(&from, &hit, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
        m = ((u8 **)pp)[-2];
        if (m == 0) {
            goto sparks;
        }
        if (m == D_001A4BE0.hero && color != 0x3FFF2020) {
            if ((*(s32 *)(D_001D52FC + 0x1A8) & 0x20) || (*(s32 *)(D_001D52FC + 0x1B0) & 0x20)) {
                if (D_001A4BE0.gadget != 0) {
                    func_003C2EC0(D_001A4BE0.gadget, 0, mtx);
                    from = mtx[3];
                    func_0038CF68(&hit, &mtx[1], -100.0f);
                    vec_add_ab(&to, &hit, &from);
                    if (*(s32 *)(D_001D52FC + 0x1A8) & 0x20) {
                        p = D_001A4BE0.pos;
                        p.z += 2.0f;
                        func_L01_004F50C8(&p, (u8 *)&D_001A4BE0 + 0x90, 0, 1);
                        func_L11_00351528((void *)mtx, (void *)&from, (void *)&to);
                    }
                    goto next;
                }
            }
            vec_sub_ab(&hit, &D_001A4C60, &D_L11_001E84C0.pos);
            func_0038CF68(&hit, &hit, 1.0f);
            return;
        }
        m = D_L11_001E84C0.m;
        id = *(s16 *)(m + 0xAA);
        if (id == 0x168D) {
            from = D_L11_001E84C0.pos;
            func_0038CF68(&hit, m + 0xC0, 100.0f);
            color = 0x3F2020FF;
        } else if (id == 0x1695) {
            u8 *q = *(u8 **)(m + 0x68);
            color = 0x3FFF2020;
            from = *(vu0_v4 *)(q + 0x40);
            to = *(vu0_v4 *)(q + 0x50);
            goto next;
        } else if (id == 0x1682) {
            if (*(s32 *)(D_001D52FC + 0x1B0) & 0x20) {
                goto next;
            }
            func_L01_00456230(m, 1);
            return;
        } else {
            from = D_L11_001E84C0.pos;
            func_0038CF68(&hit, m + 0xC0, 100.0f);
        }
        vec_add_ab(&to, &hit, &from);
        goto next;
sparks:
            hit = *(vu0_v4 *)D_L11_001D66B0;
            hit.z = 0.015000001f;
            r = func_L01_00472F58(pp, &hit, 0x44, 0.1f);
            if (r != 0) {
                r[2] = *D_L11_0021E558[0x170 / 4];
            }
            r = func_L01_00472560(pp, D_L11_001D66B0, 0x44, 0x2A, 0.3f);
            if (r != 0) {
                r[2] = *D_L11_0021E558[0x170 / 4];
            }
            hit = *(vu0_v4 *)D_L11_001D66B0;
            hit.z = -0.030000001f;
            func_L01_00471BF0(pp, &hit, 0x19);
            return;
miss:
    func_L01_0040A8C0(&from, &to, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
    return;
next:
        n++;
    } while (n < 16);
}
/* localdecomp:end func_L11_003510D0 */

/* localdecomp:start func_L11_003514D8 */
extern char D_001A4CC0[];
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003514D8(void) {
    func_003D9508(D_001A4CC0, 5, 0x3FFF2020, 1, 1.2f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003514D8 */

/* localdecomp:start func_L11_00351528 */
typedef int u128_351528 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
__asm__(".extern D_L11_001DD3A0, 4");
extern s32 D_L11_001DD3A0;

u8 *func_L11_00351528(u128_351528 *m, u128_351528 *a, u128_351528 *b)
{
    u128_351528 s[6];
    u8 *moby;
    u128_351528 *v;

    s[0] = m[0];
    s[1] = m[1];
    s[2] = m[2];
    s[3] = m[3];
    s[4] = *a;
    s[5] = *b;
    moby = func_003C24B0(0x1695, 0x80);
    if (moby != 0) {
        moby[0x30] = 0xFF;
        *(u16 *)(moby + 0x32) = 0x40;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u128_351528 *)(moby + 0x10) = *(u128_351528 *)D_001A4CC0;
        v = *(u128_351528 **)(moby + 0x68);
        v[0] = s[0];
        v[4] = s[4];
        v[5] = s[5];
        D_L11_001DD3A0++;
    }
    return moby;
}
/* localdecomp:end func_L11_00351528 */

/* localdecomp:start func_L11_003515E0 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L11_0034F0F0(void *, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L11_003515E0(u8 *a0) {
    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        func_L11_0034F0F0(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 2.0f, 1, 1, 0x3FFF2020);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L11_003515E0 */
