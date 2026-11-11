/* near miss (level 11, Obani Moons): draft, about 220 differences (measured with --flags=-mvu0-use-vf0-vf2; in the file the u128_351528 typedef would have to move to the prelude, since func_L11_00351528 comes later): the beam bounce loop (up to 16 hits, laser colour 0x3F2020FF / 0x3FFF2020, func_L01_0040A8C0 per segment) with every call and constant retail's, but the block layout and saved-register assignment differ: retail keeps a0 in $s5, the hit count in $s6, &to in $s4 and &D_L11_001E84C0.pos in $s3, and places the no-moby sparks block after the moby cases. Not tuned further */
#include "common.h"

/* localdecomp:start func_L11_003510D0 */
#include "vu0.h"
typedef int u128_351528 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x18]; u8 *m; u8 pad1C[4]; vu0_v4 pos; } H_3510D0;
typedef struct { u8 pad0[0x80]; vu0_v4 pos; u8 pad90[0x1200 - 0x90]; u8 *gadget; u8 pad1204[0x25C0 - 0x1204]; u8 *hero; } G_3510D0;
extern H_3510D0 D_L11_001E84C0;
extern vu0_v4 D_L11_001D66B0;
extern u8 *D_L11_0021E558[];
extern G_3510D0 D_001A4BE0;
extern vu0_v4 D_001A4C60;
extern u8 *D_001D52FC;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern u8 *func_L11_00351528(u128_351528 *, u128_351528 *, u128_351528 *);
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
    s16 id;

    from = *(vu0_v4 *)(a0 + 0x10);
    to = *(vu0_v4 *)(*(u8 **)(a0 + 0x68) + 0x100);
    do {
        if (func_003D3CB0(&from, &to, 0, a0, 0) == 0) {
            goto miss;
        }
        hit = D_L11_001E84C0.pos;
        func_L01_0040A8C0(&from, &hit, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
        m = D_L11_001E84C0.m;
        if (m == 0) {
            hit = D_L11_001D66B0;
            hit.z = 0.015000001f;
            r = func_L01_00472F58(&D_L11_001E84C0.pos, &hit, 0x44, 0.1f);
            if (r != 0) {
                r[2] = *D_L11_0021E558[0x170 / 4];
            }
            r = func_L01_00472560(&D_L11_001E84C0.pos, &D_L11_001D66B0, 0x44, 0x2A, 0.3f);
            if (r != 0) {
                r[2] = *D_L11_0021E558[0x170 / 4];
            }
            hit = D_L11_001D66B0;
            hit.z = -0.030000001f;
            func_L01_00471BF0(&D_L11_001E84C0.pos, &hit, 0x19);
            return;
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
                        func_L11_00351528((u128_351528 *)mtx, (u128_351528 *)&from, (u128_351528 *)&to);
                    }
                    n++;
                    continue;
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
            r = *(u8 **)(m + 0x68);
            color = 0x3FFF2020;
            from = *(vu0_v4 *)(r + 0x40);
            to = *(vu0_v4 *)(r + 0x50);
            n++;
            continue;
        } else if (id == 0x1682) {
            if (*(s32 *)(D_001D52FC + 0x1B0) & 0x20) {
                n++;
                continue;
            }
            func_L01_00456230(m, 1);
            return;
        } else {
            from = D_L11_001E84C0.pos;
            func_0038CF68(&hit, m + 0xC0, 100.0f);
        }
        vec_add_ab(&to, &hit, &from);
        n++;
    } while (n < 16);
    return;
miss:
    func_L01_0040A8C0(&from, &to, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
}
/* localdecomp:end func_L11_003510D0 */
