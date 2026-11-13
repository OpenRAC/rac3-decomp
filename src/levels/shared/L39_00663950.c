#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00663950 */
#include "vu0.h"
extern s32 D_001D5A1C_sda;
extern u8 D_L39_004997E0[];
extern void func_L39_005BA418(void *, void *);
extern void func_0038D308(f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_00663950(u8 *o) {
    u8 *a = *(u8 **)(o + 0x2558);
    u8 *q = *(u8 **)(a + 0xC44);
    u8 *t = 0;
    s32 x1, x2, x3;
    f32 s, s2;

    if (q != 0 && (a[0xC42] == 0 || D_001D5A1C_sda - *(s32 *)(a + 0xC3C) >= *(s8 *)(a + 0xC41))) {
        t = q;
    }
    if (t == 0) {
        return;
    }
    {
        u8 idx = (*(u8 **)(o + 0x2558))[0xC31];
        if ((*(u32 *)(t + 0x14) & 0xC000000) != 0x4000000) {
            func_L39_005BA418(o + 0x23B0, (s32 *)t + idx);
        }
    }
    *(s32 *)(o + 0x23BC) = 0;
    func_0038D308((f32 *)(o + 0x23C0), (f32 *)(o + 0x23B0));
    if (*(u32 *)(o + 0x1310) < 2) {
        s = 2.0f;
        s2 = -3.0f;
    } else {
        {
            u32 buf[4];
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x1 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x1 = buf[1];
            }
        }
        if ((x1 ^ 4) == 0) {
            goto chk;
        }
        {
            u32 buf[4];
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x2 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x2 = buf[1];
            }
        }
        if ((x2 ^ 0x15) == 0) {
chk:
            if (*(s32 *)(o + 0x1310) == 2) {
                goto small;
            }
        }
        if (o[0x24FD] != 0) {
small:
            s = 0.6f;
        } else {
            s = 1.15f;
        }
        {
            u32 buf[4];
            u8 *p = o + 0x19E6;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x3 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x3 = buf[1];
            }
        }
        if ((x3 ^ 3) == 0) {
            s = 1.75f;
        }
        s2 = 0.0f;
    }
    func_0038CF68(o + 0x23A0, o + 0x40, s);
    vec_add_ab(o + 0x23A0, o + 0x23A0, o + 0xA0);
    if (s2 != 0.0f) {
        vu0_v4 v;
        func_0038CF68(&v, o + 0x23C0, s2);
        vec_add_ab(o + 0x23A0, o + 0x23A0, &v);
    }
    *(vu0_q *)(*(u8 **)(o + 0x2530) + 0x10) = *(vu0_q *)(o + 0x23B0);
    *(vu0_q *)(*(u8 **)(o + 0x2530)) = *(vu0_q *)(o + 0x23A0);
}
/* localdecomp:end func_L39_00663950 */

INCLUDE_ASM("asm/levels", func_L39_00663C80);

INCLUDE_ASM("asm/levels", func_L39_00663DA8);

INCLUDE_ASM("asm/levels", func_L39_00664760);

INCLUDE_ASM("asm/levels", func_L39_00665568);
