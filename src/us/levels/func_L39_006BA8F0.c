#include "common.h"

/* NTSC-U counterpart of func_L39_006BD408 (src/levels/39_multiplayer_menu/L39_006BBD80.c): NTSC-U core and level addresses only */
/* localdecomp:start func_L39_006BA8F0 */
typedef struct {
    char _p0[0x2A8];
    s32 f2A8;
    char f2AC[0x2EB - 0x2AC];
    u8 f2EB;
    char _p2EC[0x2F0 - 0x2EC];
    s32 f2F0;
    s32 f2F4;
    char _p2F8[0x304 - 0x2F8];
    s32 f304;
    s32 f308;
    s32 f30C;
} S_006BA8F0;
typedef struct {
    s32 f0;
    s32 n;
    s32 **list;
} L_006BA8F0;
typedef struct {
    u8 f0;
    char _p1[0xD - 0x1];
    u8 fD;
    char _pE[0x14 - 0xE];
    L_006BA8F0 f14;
} N_006BA8F0;
typedef struct {
    s32 f0;
    char f4[1];
} M_006BA8F0;
typedef struct {
    char _p0[0x78];
    N_006BA8F0 *f78;
} G_006BA8F0;

__asm__(".extern D_L39_0024D860, 16");
extern u8 *D_L39_0024D860;
extern u8 D_001A5E50[];
extern G_006BA8F0 *D_001E1FD0_sda;
extern char D_L39_00249500[];
extern char D_L39_00249508[];
extern char D_L39_00249630[];
extern u8 *func_L39_006D8BF8(s32 *, s32);
extern s32 func_001200E0(void *, char *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_00195500(void);
extern s32 func_L39_006D4888(void *);
extern void func_L39_006D6030(void *);
extern void *func_00120D28(void *, void *, s32);
extern s32 func_L39_006CC290(void *, s32);
extern s32 func_L39_006D0790(void *, s32 *, s32 *);
extern u8 *func_L39_006D0A30(void *, s32, s32);
extern s32 func_00120884(char *);
extern void func_L39_00594648(char *, char *, s32);
extern s32 func_0011FFA8(char *, s32, const char *, ...);
extern s32 func_0037DF98(s32);

void func_L39_006BA8F0(void *arg0, s32 arg1) {
    S_006BA8F0 *a = (S_006BA8F0 *)arg0;
    char buf[0x40];
    s32 x;
    s32 y;
    s32 *px;
    s32 *py;
    u8 *p;
    u8 *q;
    s32 kind;

    a->f2A8 = arg1;
    if (*(s32 *)(D_001A5E50 + 0x2DC) != 0) {
        return;
    }
    p = func_L39_006D8BF8(*(s32 **)(D_L39_0024D860 + 0x4C), arg1);
    a->f2AC[0] = 0;
    a->f2F0 = 0;
    if (p == 0) {
        return;
    }
    q = p + 0x1C;
    px = &x;
    py = &y;
    kind = 8;
    if (q[0] == 'C') {
        if (q[1] == 'Y') {
            kind = 1;
            func_001200E0(p + 0x1E, D_L39_00249500, px, py);
        } else if (q[1] == 'R') {
            kind = 4;
            func_001200E0(p + 0x1E, D_L39_00249500, px, py);
        } else if (q[1] == 'C') {
            kind = 2;
            func_001200E0(p + 0x1E, D_L39_00249508, px, py);
        }
    } else if (q[0] == 'H') {
        kind = 6;
        func_001200E0(p + 0x1E, D_L39_00249500, px, py);
    }
    switch (kind) {
    case 1: {
        N_006BA8F0 *n = D_001E1FD0_sda->f78;
        s32 id = x + 0x28;
        L_006BA8F0 *l = n->fD ? &n->f14 : 0;
        s32 start = func_00130760(func_0012DCB0(), 0x24000);
        s32 i;
        s32 cnt;
        s32 *e;

        while (l == 0) {
            func_L39_006D4888(n);
            while (n->f0 != 0) {
                func_00195500();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 0x3A99) {
                    return;
                }
                if (D_001E1FD0_sda != 0) {
                    func_L39_006D6030(D_001E1FD0_sda);
                }
            }
            l = n->fD ? &n->f14 : 0;
        }
        for (i = 0; i < l->n; i++) {
            e = l->list[i];
            if (e[0x18 / 4] == id) {
                func_00120D28(a->f2AC, (u8 *)e + 0x1C, 0x40);
                a->f2F4 = id;
                a->f2F0 = 1;
                a->f2EB = 0;
                break;
            }
        }
        break;
    }
    case 2: {
        M_006BA8F0 *m = *(M_006BA8F0 **)(D_L39_0024D860 + 0x38);
        u8 *r;

        if (func_L39_006CC290(m, 0) == 0) {
            return;
        }
        a->f304 = m->f0;
        if (func_L39_006D0790(m, &a->f308, &a->f30C) != 0) {
            r = func_L39_006D0A30(m, a->f30C, a->f308);
            if (r != 0) {
                func_L39_00594648(buf, (char *)r + 0x20, func_00120884((char *)r + 0x20));
                func_0011FFA8(a->f2AC, 0x40, D_L39_00249630, m->f4, buf);
            } else {
                func_0011FFA8(a->f2AC, 0x40, m->f4);
            }
        } else {
            func_0011FFA8(a->f2AC, 0x40, m->f4);
        }
        a->f2EB = 0;
        a->f2F0 = 3;
        break;
    }
    case 4: {
        M_006BA8F0 *m = *(M_006BA8F0 **)(D_L39_0024D860 + 0x38);

        if (func_L39_006CC290(m, 0) == 0) {
            return;
        }
        if (m->f0 == -1) {
            return;
        }
        func_0011FFA8(a->f2AC, 0x40, (char *)func_0037DF98(0x14A0), m->f4);
        a->f2F0 = 2;
        a->f2EB = 0;
        break;
    }
    }
}
/* localdecomp:end func_L39_006BA8F0 */
