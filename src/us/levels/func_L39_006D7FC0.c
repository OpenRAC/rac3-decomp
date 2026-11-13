#include "common.h"

/* NTSC-U counterpart of func_L39_006DAB18 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
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
typedef struct {
    s32 f0;
    u8 pad4[0x158];
    u8 f15C, f15D;
    u8 pad15E[2];
    s32 f160;
    u8 pad164[4];
    u8 f168;
    u8 pad169[3];
    s32 f16C;
    u8 pad170[0x28];
    u8 f198, f199;
    u8 pad19A[2];
    s32 f19C;
    u8 pad1A0[4];
    u8 f1A4;
    u8 pad1A5[3];
    s32 f1A8;
} S_006DA958;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006D7FC0(S_006DA958 *);
s32 func_L39_006DAFC8_006D7FC0();

/* localdecomp:start func_L39_006D7FC0 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    u8 pad1C[4];
    u8 f20[0x10];
} Loc_006DAB18;
typedef struct {
    s32 f00;
    u8 pad04[0x159];
    u8 f15D;
    u8 pad15E[2];
    s32 f160;
} Obj_006DAB18;
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
} Dst_006DAB18;

extern void func_0014B008(void *);
extern void *func_0017F948(void *, void *, s32);
extern void func_001962D8(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
extern u8 D_00197F38[];

/* follows func_L39_006DAFC8_006D7FC0 in this file */
s32 func_L39_006D7FC0(S_006DA958 *arg) {
    extern Dst_006DAB18 *D_001E1FD0_sda;
    Obj_006DAB18 *arg0 = (Obj_006DAB18 *)arg;
    Loc_006DAB18 loc;
    s32 ret = 1;
    Dst_006DAB18 *d = D_001E1FD0_sda;

    if (arg0->f00 >= 0) {
        if (arg0->f15D == 0) {
            loc.f18 = arg0->f00;
            loc.f00 = D_L39_0024A050[0];
            arg0->f15D = 1;
            arg0->f160 = func_00130760(func_0012DCB0(), 0x24000);
            func_0014B008(loc.f20);
            func_001962D8(func_0017F948(&loc, D_00197F38, 0));
            if (func_001962E8() != 0) {
                d->f10 = 0x44;
                if (d->f14 == 0) {
                    d->f14 = 0x44;
                }
                ret = 0;
            }
        }
    } else {
        d->f10 = 0x45;
        if (d->f14 == 0) {
            d->f14 = 0x45;
        }
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D7FC0 */
