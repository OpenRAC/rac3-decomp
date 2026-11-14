#include "common.h"

/* NTSC-U counterpart of func_L39_006D7018 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
/* localdecomp:start func_L39_006D4888 */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001206F4(void *, void *);
extern void *func_0017F5D8(void *, void *, s32);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_00249F40_006D4888[];
extern u8 D_00197E20[];

typedef struct {
    u16 h00;
    u8 pad02[0x13];
    u8 name[0x1B];
} Loc_006D4888;

typedef struct {
    u8 pad0[0xC];
    s32 wC;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
} Fl_006D4888;

typedef struct {
    s32 w0;
    s32 cnt;
    s32 *list;
} Q_006D4888;

typedef struct {
    u8 b0;
    u8 pad1[3];
    s32 w4;
    u8 pad8[5];
    u8 bD;
    u8 padE[6];
    Q_006D4888 q;
    s32 w20;
} Obj_006D4888;

typedef struct {
    u8 pad0[0x10];
    s32 w10;
    s32 w14;
    u8 pad18[0x38];
    u8 *w50;
} Dst_006D4888;

extern Dst_006D4888 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");

static __inline__ Q_006D4888 *GetQ_006D4888(Obj_006D4888 *o) {
    return &o->q;
}

s32 func_L39_006D4888(Obj_006D4888 *a0) {
    Loc_006D4888 loc;
    Dst_006D4888 *d = D_L39_0024D860;
    s32 ret;
    s32 i;

    {
        u8 *nm = d->w50;

        loc.h00 = D_L39_00249F40_006D4888[0];
        func_001206F4(loc.name, nm);
    }
    a0->b0 = 1;
    a0->w4 = func_00130760(func_0012DCB0(), 0x24000);
    a0->bD = 0;
    for (i = 0; i < GetQ_006D4888(a0)->cnt; i++) {
        Fl_006D4888 *f = (Fl_006D4888 *)a0->w20;
        s32 e = GetQ_006D4888(a0)->list[i];

        *(s32 *)(e + f->wC) = f->w1C;
        f->w1C = e;
        f->w18 = f->w18 + 1;
    }
    *(s32 *)((u8 *)a0 + 0x18) = 0;
    ret = 1;
    func_001962D8(func_0017F5D8(&loc, D_00197E20, 0));
    if (func_001962E8() != 0) {
        d->w10 = 0x3A;
        if (d->w14 == 0) {
            d->w14 = 0x3A;
        }
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D4888 */
