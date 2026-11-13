#include "common.h"

/* NTSC-U counterpart of func_L39_006DB5D0 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
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
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
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

/* localdecomp:start func_L39_006D8A78 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    s32 f28;
    s32 f2C;
} Loc_006DB5D0;
typedef struct {
    u8 pad00[0xEC];
    u8 fEC;
    u8 padED[3];
    s32 fF0;
} Obj_006DB5D0;
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
} P_006DB5D0;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} G_006DB5D0;

extern void *func_0017FCB8(void *, void *, s32);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern u8 D_00197E98[];
extern G_006DB5D0 D_001A5E50_006D8A78;
extern Obj_006DA090 *D_L39_0024D860 __attribute__((section(".data")));

s32 func_L39_006D8A78(Obj_006DB5D0 *o) {
    Loc_006DB5D0 loc;
    P_006DB5D0 *p = (P_006DB5D0 *)D_L39_0024D860;
    s32 ok;

    loc.f00 = D_L39_0024A050[0];
    loc.f18 = 0xFFFFFFFF;
    loc.f1C = 0xFFFFFFFF;
    loc.f20 = 0xFFFFFFFF;
    loc.f24 = 0xFFFFFFFF;
    loc.f28 = 0;
    loc.f2C = 0x20;
    o->fEC = 1;
    p->f01 = 1;
    p->f08 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017FCB8(&loc, D_00197E98, 0));
    ok = 1;
    while (o->fEC != 0) {
        if (func_001962E8() != 0 || D_001A5E50_006D8A78.f2DC != 0) {
            p->f10 = 0x47;
            if (p->f14 == 0) {
                p->f14 = 0x47;
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
    o->fEC = 0;
    if (ok != 0 && o->fF0 != 0) {
        p->f10 = 0x47;
        if (p->f14 == 0) {
            p->f14 = 0x47;
        }
        ok = 0;
    }
    return ok;
}
/* localdecomp:end func_L39_006D8A78 */
