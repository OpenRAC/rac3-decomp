#include "common.h"

/* NTSC-U counterpart of func_L39_006DB750 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;
extern Obj_006DA090 *D_L39_0024D860;
extern Obj_006DA090 *D_L39_0024D860;
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
s32 func_001206F4(void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern void func_00195500(void);
extern s32 func_L39_006D5F80(void *);

/* localdecomp:start func_L39_006D8BF8 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    u8 pad2C[4];
} Loc_006DB750;
typedef struct {
    u8 pad00[0xF4];
    u8 fF4;
    u8 padF5[3];
    u8 fF8[0x18];
    s32 f110;
} Obj_006DB750;
typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[6];
    s32 f08;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} P_006DB750;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} G_006DB750;

extern s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_0017EC28(void *, void *, s32);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern u16 D_L39_0024A050[];
extern u8 D_00197EE8[];
extern G_006DB750 D_001A5E50;
extern Obj_006DA090 *D_L39_0024D860 __attribute__((section(".data")));

void *func_L39_006D8BF8(Obj_006DB750 *arg0, s32 arg1) {
    Loc_006DB750 loc;
    P_006DB750 *p = (P_006DB750 *)D_L39_0024D860;
    s32 ok;
    s32 x;
    void *r;

    x = p->f50;
    loc.f00 = D_L39_0024A050[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg1;
    arg0->fF4 = 1;
    p->f01 = 1;
    ok = 1;
    p->f08 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EC28(&loc, D_00197EE8, 0));
    while (arg0->fF4 != 0) {
        if (func_001962E8() != 0 || D_001A5E50.f2DC != 0) {
            p->f10 = 0x4A;
            if (p->f14 == 0) {
                p->f14 = 0x4A;
            }
            ok = 0;
            break;
        }
        p->f1C = 1;
        func_00195500();
        p->f1C = 0;
        if (func_L39_006D5F80(p) == 0) {
            ok = 0;
            break;
        }
    }
    p->f01 = 0;
    arg0->fF4 = 0;
    r = 0;
    if (ok != 0) {
        r = arg0->f110 != 0 ? 0 : arg0->fF8;
    }
    return r;
}
/* localdecomp:end func_L39_006D8BF8 */
