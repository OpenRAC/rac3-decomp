#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_0044CCC0);

/* localdecomp:start func_L01_0044CCC8 */
extern u8 D_001D5530[] __attribute__((section(".sdata")));
extern s32 D_00143050[];

void func_L01_0044CCC8(s32 id) {
    s32 i;
    s32 n;

    if (D_001D5530[id] == 0) {
        s32 t = 0;
        do {
            t++;
            if (t >= 60) {
                break;
            }
        } while (1);
        D_001D5530[id] = 1;
        if (id < 30 && id != 24) {
            n = 0;
            for (i = 0; i < 60; i++) {
                if (D_00143050[i] != 0) {
                    n++;
                }
            }
            D_00143050[n] = id;
        }
    }
}
/* localdecomp:end func_L01_0044CCC8 */

/* localdecomp:start func_L01_0044CD60 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[4];
    s32 w10;
    u8 pad14[0xF0 - 0x14];
} S_449AE8;

extern u8 D_001425C0[];
extern S_449AE8 D_L01_002C5600[];
extern s16 D_001CCFD4[];
extern s32 D_001A71D8[];
extern s32 D_001A71DC[];
extern s32 D_001A71E0[];
extern s32 D_001A71E4[];
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_L01_005078C0(s32);

s32 func_L01_0044CD60(s32 id) {
    s32 ret;
    s32 st;
    u8 *ip;
    S_449AE8 *tbl;
    S_449AE8 *e;

    ip = D_001425C0 + id;
    tbl = D_L01_002C5600;
    ret = 0;
    e = tbl + *ip;
    st = e->w8;
    if (st == 0) {
        if (func_0039AC08(e->w10) != 0 || D_001CCFD4[0] == 0) {
            D_001A71D8[0] = id;
            func_L01_005078C0(id);
            if (func_0039AC08((tbl + *ip)->w10) == 0) {
                func_0039AA38((tbl + *ip)->w10);
            }
            ret = 1;
        }
    } else if (st == 3) {
        D_001A71E4[0] = id;
        ret = 1;
    } else if (st == 2) {
        D_001A71E0[0] = id;
        ret = 1;
    } else if (st == 1) {
        D_001A71DC[0] = id;
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L01_0044CD60 */

/* localdecomp:start func_L01_0044CE88 */
#include "structs/moby.h"

typedef struct {
    u8 pad0[0x1200];
    struct Moby *hand_moby;        /* 0x1200 */
    u8 pad1204[0x1228 - 0x1204];
    s32 held_item;                 /* 0x1228 */
} Hero_0044CE88;

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0x10 - 2];
    s32 oclass;
    u8 pad14[0xF0 - 0x14];
} Item_0044CE88;

extern Hero_0044CE88 D_001A4BE0;
extern Item_0044CE88 D_L01_002C5600_0044CE88[];

s32 func_L01_0044CE88(struct Moby *m) {
    struct Moby *hand;
    s32 i;
    s32 cls;

    if (m == 0) {
        return 0xFF;
    }
    if (D_001A4BE0.held_item == 0x87 && m->oclass == 0x1893) {
        return 0x87;
    }
    if (D_001A4BE0.held_item == 0x57 && m->oclass == 0x1893) {
        return 0x57;
    }
    if (D_001A4BE0.held_item == 0x77 && D_L01_002C5600_0044CE88[D_001425C0[0x77]].b1 >= 4 && m->oclass == 0x1855) {
        return 0x77;
    }
    if (D_001A4BE0.held_item == 0x11 && (m->oclass == 0xC59 || m->oclass == 0x5C9)) {
        return 0x11;
    }
    if (D_001A4BE0.held_item == 0x7F && m->oclass == 0x47) {
        return 0x7F;
    }
    if (D_001A4BE0.held_item == 0x47 && m->oclass == 0x1195) {
        return 0x47;
    }
    switch (m->oclass) {
    case 0x1195:
        return 0x16;
    case 0x1869:
    case 0x186D:
        return 0x67;
    case 0x1870:
    case 0x189B:
    case 0x1C59:
        return 0x8F;
    case 0x1871:
    case 0x1873:
        return 0x97;
    case 0x186A:
    case 0x186B:
        return 0x5F;
    case 0x1866:
    case 0x1867:
        return 0x4F;
    case 0xA65:
    case 0xA66:
    case 0xA82:
    case 0xC5A:
    case 0x1366:
        return 0x15;
    case 0xE64:
    case 0xECE:
        return 0x13;
    case 0x1864:
    case 0x1887:
    case 0x1894:
        return 0x3F;
    case 0x9A9:
    case 0xA9B:
        return 0x10;
    case 0x185B:
    case 0x1872:
    case 0x1892:
        return 0x87;
    case 0x1852:
    case 0x1853:
    case 0x1854:
    case 0x1855:
    case 0x188F:
    case 0x1893:
    case 0x1ADA:
    case 0x1AEC:
        return 0x57;
    case 0x1858:
    case 0x185A:
    case 0x1865:
    case 0x1885:
    case 0x1888:
    case 0x1898:
        return 0x77;
    case 0x5C9:
    case 0xB2E:
    case 0xC59:
        return 0x11;
    case 0x1843:
    case 0x1890:
    case 0x1CB8:
        return 0x7F;
    }
    hand = D_001A4BE0.hand_moby;
    if (m == hand) {
        return D_001A4BE0.held_item;
    }
    if (m->parent != 0 && m->parent == hand) {
        return D_001A4BE0.held_item;
    }
    cls = m->oclass;
    for (i = 0; i < 156; i++) {
        Item_0044CE88 *e = &D_L01_002C5600_0044CE88[D_001425C0[i]];
        if (cls == e->oclass) {
            return i;
        }
        if (m->parent != 0 && m->parent->oclass == e->oclass) {
            return i;
        }
    }
    return 0xFF;
}
/* localdecomp:end func_L01_0044CE88 */

INCLUDE_ASM("asm/levels", func_L01_0044D360);

/* localdecomp:start func_L01_0044DF00 */
extern s32 D_00143950[];
extern f32 D_001D5308;
extern f32 D_001D530C;
extern f32 D_001D5310;
extern f32 D_001D5314;
extern f32 D_001D5318;
extern f32 D_001D531C;
extern s32 D_001D5320;
extern f32 D_001D5324;

void func_L01_0044DF00(s32 a0) {
    if (a0 == 0) {
        D_00143950[0] = 0;
        D_001D5308 = 1.0f;
        D_001D530C = 1.0f;
        D_001D5310 = 1.0f;
        D_001D5314 = 0.0166666675f;
        D_001D5318 = 0.000277777785f;
        D_001D531C = 4.62962953e-06f;
        D_001D5320 = 5;
        D_001D5324 = 0.0166666675f;
    } else {
        D_00143950[0] = 1;
        D_001D5308 = 1.20000005f;
        D_001D530C = 1.44000006f;
        D_001D5310 = 0.833333313f;
        D_001D5314 = 0.0200000014f;
        D_001D5318 = 0.000400000019f;
        D_001D531C = 7.99999998e-06f;
        D_001D5320 = 6;
        D_001D5324 = 0.0199999996f;
    }
}
/* localdecomp:end func_L01_0044DF00 */

LINKER_REMNANT("asm/levels", func_L01_0044E020);
