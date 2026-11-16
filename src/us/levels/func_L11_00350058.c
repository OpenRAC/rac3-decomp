#include "common.h"

/* NTSC-U counterpart of func_L11_003510D0 (src/levels/11_obani_moons/L11_00350EE0.c) */
#include "vu0.h"
extern u8 *D_001D52FC;
extern void func_L11_00350058(u8 *);
extern void func_L01_00452F40(void *, s32);

/* localdecomp:start func_L11_00350058 */
#include "vu0.h"
typedef struct { u8 pad0[0x18]; u8 *m; u8 pad1C[4]; vu0_v4 pos; } H_3510D0;
typedef struct { u8 pad0[0x80]; vu0_v4 pos; u8 pad90[0x1200 - 0x90]; u8 *gadget; u8 pad1204[0x25C0 - 0x1204]; u8 *hero; } G_3510D0;
extern H_3510D0 D_L11_001E84C0_00350058;
extern u8 D_L11_001D66B0_00350058[8];
extern u8 *D_L11_0021E558_00350058[];
extern G_3510D0 D_001A4BE0;
extern vu0_v4 D_001A4C60;
extern u8 *D_001D52FC;
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_004084B0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern u8 *func_L11_003504B0();
extern void func_L01_00452F40(void *, s32);
extern u8 *func_L01_0046F808(void *, void *, s32, f32);
extern u8 *func_L01_0046EE10(void *, void *, s32, s32, f32);
extern void func_L01_0046E4D8(void *, void *, s32);

void func_L11_00350058(u8 *a0)
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
        if (func_003CE740(&from, &to, 0, a0, 0) == 0) {
            goto miss;
        }
        pp = &D_L11_001E84C0_00350058.pos;
        hit = *pp;
        func_L01_004084B0(&from, &hit, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
        m = ((u8 **)pp)[-2];
        if (m == 0) {
            goto sparks;
        }
        if (m == D_001A4BE0.hero && color != 0x3FFF2020) {
            if ((*(s32 *)(D_001D52FC + 0x1A8) & 0x20) || (*(s32 *)(D_001D52FC + 0x1B0) & 0x20)) {
                if (D_001A4BE0.gadget != 0) {
                    func_003BD9A0(D_001A4BE0.gadget, 0, mtx);
                    from = mtx[3];
                    func_00388830(&hit, &mtx[1], -100.0f);
                    vec_add_ab(&to, &hit, &from);
                    if (*(s32 *)(D_001D52FC + 0x1A8) & 0x20) {
                        p = D_001A4BE0.pos;
                        p.z += 2.0f;
                        func_L01_004F12C0(&p, (u8 *)&D_001A4BE0 + 0x90, 0, 1);
                        func_L11_003504B0((void *)mtx, (void *)&from, (void *)&to);
                    }
                    goto next;
                }
            }
            vec_sub_ab(&hit, &D_001A4C60, &D_L11_001E84C0_00350058.pos);
            func_00388830(&hit, &hit, 1.0f);
            return;
        }
        m = D_L11_001E84C0_00350058.m;
        id = *(s16 *)(m + 0xAA);
        if (id == 0x168D) {
            from = D_L11_001E84C0_00350058.pos;
            func_00388830(&hit, m + 0xC0, 100.0f);
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
            func_L01_00452F40(m, 1);
            return;
        } else {
            from = D_L11_001E84C0_00350058.pos;
            func_00388830(&hit, m + 0xC0, 100.0f);
        }
        vec_add_ab(&to, &hit, &from);
        goto next;
sparks:
            hit = *(vu0_v4 *)D_L11_001D66B0_00350058;
            hit.z = 0.01250000111758709f;
            r = func_L01_0046F808(pp, &hit, 0x44, 0.1f);
            if (r != 0) {
                r[2] = *D_L11_0021E558_00350058[0x170 / 4];
            }
            r = func_L01_0046EE10(pp, D_L11_001D66B0_00350058, 0x44, 0x32, 0.3f);
            if (r != 0) {
                r[2] = *D_L11_0021E558_00350058[0x170 / 4];
            }
            hit = *(vu0_v4 *)D_L11_001D66B0_00350058;
            hit.z = -0.02500000223517418f;
            func_L01_0046E4D8(pp, &hit, 0x19);
            return;
miss:
    func_L01_004084B0(&from, &to, 0xE, 1, color, color, color, color, 0.1f, 1.0f, 0.5f);
    return;
next:
        n++;
    } while (n < 16);
}
/* localdecomp:end func_L11_00350058 */
