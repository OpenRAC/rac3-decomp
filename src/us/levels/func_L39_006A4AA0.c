#include "common.h"

/* NTSC-U counterpart of func_L39_006A72B0 (src/levels/39_multiplayer_menu/L39_006A61A0.c) */
/* localdecomp:start func_L39_006A4AA0 */
typedef struct { u8 pad0[0x170]; s32 f170; } G_006A72B0;
extern G_006A72B0 D_001A5E50_006A4AA0;
extern u8 D_L39_002405A0;
extern u8 D_L39_00240598;
extern u8 D_L39_00241240;
extern u32 D_L39_0024BAC8;
extern void func_L39_0067C5E0(s32);
extern void func_L39_00687F10(void *);
extern void func_L39_00687E10(s32);
extern void func_L39_006A5108(void *);
extern void func_L39_006A5AA0_006A4AA0(void *);
extern void func_L39_006DDFD8(void);
extern void func_0019CB68(s32);
extern void func_001962F8(void);

void func_L39_006A4AA0(u8 *arg0) {
    u8 buf[8];
    G_006A72B0 *g;
    u32 a;
    u32 w0;
    u32 w1;
    u32 t;
    u32 x;
    s32 i;
    s32 j;
    u8 *d;
    u8 *e;
    u8 r;
    u8 v;
    u32 k;
    u32 k2;
    u32 s;

    func_L39_0067C5E0(0x330000);
    func_L39_00687F10(arg0);
    func_L39_00687E10(0);
    func_L39_006A5108(arg0);
    g = &D_001A5E50_006A4AA0;
    if (g->f170 == 0) {
        func_0019CB68(1);
    }
    func_L39_006A5AA0_006A4AA0(arg0);
    if (g->f170 == 0) {
        func_L39_006DDFD8();
    }
    a = (u32)&D_L39_002405A0;
    if (D_L39_002405A0 == 0) {
        r = 0;
    } else {
        v = D_L39_002405A0;
        k = v + 1;
        d = buf;
        for (i = 0; i < 24; i += 3) {
            *d++ = (&D_L39_00241240)[k + (((((a - v) & 7) + i) & 7) << 2)];
        }
        w0 = ((u32 *)buf)[0] ^ a;
        w1 = ((u32 *)buf)[1] ^ w0;
        ((u32 *)buf)[0] = w0;
        t = w1 >> 16;
        x = ((w1 ^ t) << 16) + 1;
        ((u32 *)buf)[1] = t / x;
        r = buf[4];
    }
    if (r != 0) {
        u32 m;
        u32 b;
        u32 p;
        p = (u32)&D_L39_00240598;
        if (D_L39_00240598 == 0) {
            D_L39_00240598 = D_L39_00241240 = D_L39_00241240 + 1;
        } else {
            u8 old = D_L39_00240598;
            D_L39_00240598 = (&D_L39_00241240)[1];
            (&D_L39_00241240)[1] = old;
        }
        m = p * D_L39_0024BAC8;
        b = *(u8 *)p;
        k2 = b + 1;
        s = ((u32 *)&D_L39_00241240)[m & 7];
        ((u32 *)buf)[0] = p ^ s;
        ((u32 *)buf)[1] = ~s;
        e = buf;
        for (j = 0; j < 40; j += 5) {
            (&D_L39_00241240)[k2 + (((((p - *(u8 *)p) & 7) + j) & 7) << 2)] = *e++;
        }
        func_001962F8();
    }
    *(s32 *)(arg0 + 0x48C) = 0;
    *(s32 *)(arg0 + 0x478) = -1;
    *(s32 *)(arg0 + 0x47C) = -1;
    *(s32 *)(arg0 + 0x470) = -1;
}
/* localdecomp:end func_L39_006A4AA0 */
