#include "common.h"

/* NTSC-U counterpart of func_L39_006DAFC8 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_001962D8(void *);
s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006D8470();
extern void func_0014B008(void *);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_0024A050[];

/* localdecomp:start func_L39_006D8470 */
typedef struct {
    u16 f00;
    u8 pad02[0x14];
    u16 f16;
    u16 f18;
    u8 pad1A[6];
    u8 f20[0x10];
} Loc_006DAFC8;
typedef struct {
    u8 pad00[0x199];
    u8 f199;
    s32 f19C;
    u8 pad1A0[0x10];
    u16 f1B0;
} Obj_006DAFC8;
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
} Dst_006DAFC8;

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void *func_0017FA38(void *, void *, s32);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern u8 D_00197F60[];
extern Dst_006DAFC8 *D_001E1FD0_sda;

s32 func_L39_006D8470(Obj_006DAFC8 *arg0) {
    Loc_006DAFC8 loc;
    s32 ret = 1;
    Dst_006DAFC8 *d = D_001E1FD0_sda;

    if (arg0->f199 == 0) {
        loc.f00 = D_L39_0024A050[0];
        loc.f18 = arg0->f1B0;
        loc.f16 = 1;
        arg0->f199 = 1;
        arg0->f19C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(loc.f20);
        func_001962D8(func_0017FA38(&loc, D_00197F60, 0));
        if (func_001962E8() != 0) {
            d->f10 = 0x48;
            if (d->f14 == 0) {
                d->f14 = 0x48;
            }
            ret = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D8470 */
