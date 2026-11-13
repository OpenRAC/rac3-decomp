#include "common.h"

/* localdecomp:start func_L39_006D4ED8 */
typedef struct G_006D4ED8 {
    char names[8][16];
    char tags[8][8];
    s16 sC0[8];
    s16 sD0[8];
    s16 ids[8];
    s16 sF0[8];
} G_006D4ED8;

typedef struct H_006D4ED8 {
    u8 pad0[4];
    s32 w4;
    s32 w8;
    u8 padC[0x16C - 0xC];
    s32 w16C;
} H_006D4ED8;

typedef struct M_006D4ED8 {
    s32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    char name[16];
    char tag[5];
} M_006D4ED8;

typedef struct E_006D4ED8 {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
} E_006D4ED8;

extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
__asm__(".extern D_L39_00241640, 16");
extern G_006D4ED8 *D_L39_00241640;
__asm__(".extern D_L39_00240640, 16");
extern s32 D_L39_00240640;
s32 func_0019B788(void);
void *func_00120D28(void *, void *, s32);
void func_0014AD08(s32, s32, s32, s32, s32, void *);

s32 func_L39_006D4ED8(void *arg0, s32 n, char *name, s32 a3, s32 a4, s32 a5, char *tag)
{
    M_006D4ED8 m;
    E_006D4ED8 *e;
    s32 idx;
    s32 k;
    s32 i;

    idx = -1;
    k = 0;
    e = (E_006D4ED8 *)D_L39_0024D760;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->ids[i] == ((H_006D4ED8 *)D_001A5CD0)->w8) {
            if (k++ == n) {
                idx = i;
                break;
            }
        }
    }
    if (idx < 0) {
        e->f10 = 0x30;
        if (e->f14 == 0) {
            e->f14 = 0x30;
        }
        return 0;
    }
    if (func_0019B788() != 0) {
        func_00120D28(D_L39_00241640->names[idx], name, 0x10);
        D_L39_00241640->names[idx][15] = 0;
        if (tag != 0) {
            func_00120D28(D_L39_00241640->tags[idx], tag, 4);
            D_L39_00241640->tags[idx][4] = 0;
        } else {
            D_L39_00241640->tags[idx][0] = 0;
        }
        D_L39_00241640->sD0[idx] = a4;
        D_L39_00241640->sC0[idx] = a3;
        D_L39_00241640->sF0[idx] = a5;
    } else {
        m.b6 = a5;
        m.f0 = n;
        m.b5 = a3;
        m.b4 = a4;
        func_00120D28(m.name, name, 0x10);
        m.name[15] = 0;
        func_00120D28(m.tag, tag, 4);
        m.tag[4] = 0;
        func_0014AD08(0x50, ((H_006D4ED8 *)D_001A5CD0)->w4, ((H_006D4ED8 *)D_001A5CD0)->w16C, D_L39_00240640, 0x20, &m);
    }
    return 1;
}
/* localdecomp:end func_L39_006D4ED8 */

/* localdecomp:start func_L39_006D50F0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006D50F0_L;
typedef struct {
    s8 f0;
    u8 pad1[7];
    s8 f8;
    u8 pad9[7];
    s8 f10;
    u8 pad11[3];
    s32 f14;
    s32 f18;
    s8 f1C;
    u8 pad1D[3];
    s32 f20;
    s32 f24;
    s32 f28;
    S_006D50F0_L f2C;
    S_006D50F0_L f38;
    s32 f44;
    s32 f48;
} S_006D50F0;
s32 func_L39_006E16A0(s32, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32 *, s32, s32);

s32 func_L39_006D50F0(s32 arg0, s32 arg1, s32 arg2) {
    S_006D50F0 *p = (S_006D50F0 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    u32 b;
    s32 n;
    S_006D50F0_L *l;
    S_006D50F0_L *l2;

    p->f0 = 0;
    p->f8 = 0;
    p->f10 = 0;
    p->f14 = 10000;
    p->f18 = -1;
    p->f1C = 0;
    p->f24 = p->f20 = -1;
    p->f28 = arg2;
    b = arg0 + 0x4C;
    m = 4;
    rem = b % m;
    if (rem != 0) {
        b += m - rem;
    }
    r = b;
    n = func_L39_006E16A0(r, arg2 * 2, 400, 4);
    p->f44 = func_L39_006E1648(r, n, 400, 4);
    r += n;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    p->f48 = r;
    l = &p->f2C;
    l2 = &p->f38;
    func_0011D534((s32 *)r, 0, p->f28 * 8);
    l->f0 = 0;
    l->f8 = p->f48;
    l->f4 = 0;
    l2->f0 = 0;
    l2->f8 = p->f28 * 4 + p->f48;
    l2->f4 = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D50F0 */
