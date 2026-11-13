#include "common.h"

/* NTSC-U counterpart of func_L39_006D4ED8 (src/levels/39_multiplayer_menu/L39_006D4ED8.c) */
/* localdecomp:start func_L39_006D2750 */
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

extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
__asm__(".extern D_L39_002417C0, 16");
extern G_006D4ED8 *D_L39_002417C0;
__asm__(".extern D_L39_002407C0, 16");
extern s32 D_L39_002407C0;
s32 func_0019B8C8(void);
void *func_00120D28(void *, void *, s32);
void func_0014AD08(s32, s32, s32, s32, s32, void *);

s32 func_L39_006D2750(void *arg0, s32 n, char *name, s32 a3, s32 a4, s32 a5, char *tag)
{
    M_006D4ED8 m;
    E_006D4ED8 *e;
    s32 idx;
    s32 k;
    s32 i;

    idx = -1;
    k = 0;
    e = (E_006D4ED8 *)D_L39_0024D860;
    for (i = 0; i < 8; i++) {
        if (D_L39_002417C0->ids[i] == ((H_006D4ED8 *)D_001A5E50)->w8) {
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
    if (func_0019B8C8() != 0) {
        func_00120D28(D_L39_002417C0->names[idx], name, 0x10);
        D_L39_002417C0->names[idx][15] = 0;
        D_L39_002417C0->tags[idx][0] = 0;
        if (tag != 0) {
            func_00120D28(D_L39_002417C0->tags[idx], tag, 4);
            D_L39_002417C0->tags[idx][4] = 0;
        }
        D_L39_002417C0->sD0[idx] = a4;
        D_L39_002417C0->sC0[idx] = a3;
        D_L39_002417C0->sF0[idx] = a5;
    } else {
        m.b6 = a5;
        m.f0 = n;
        m.b5 = a3;
        m.b4 = a4;
        func_00120D28(m.name, name, 0x10);
        m.name[15] = 0;
        func_00120D28(m.tag, tag, 4);
        m.tag[4] = 0;
        func_0014AD08(0x50, ((H_006D4ED8 *)D_001A5E50)->w4, ((H_006D4ED8 *)D_001A5E50)->w16C, D_L39_002407C0, 0x20, &m);
    }
    return 1;
}
/* localdecomp:end func_L39_006D2750 */
