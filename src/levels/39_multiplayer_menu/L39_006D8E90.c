#include "common.h"

typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;

INCLUDE_ASM("asm/levels", func_L39_006D8E90);

INCLUDE_ASM("asm/levels", func_L39_006D8EC0);

INCLUDE_ASM("asm/levels", func_L39_006D8EF0);

INCLUDE_ASM("asm/levels", func_L39_006D8F30);

INCLUDE_ASM("asm/levels", func_L39_006D8F58);

INCLUDE_ASM("asm/levels", func_L39_006D8F98);

INCLUDE_ASM("asm/levels", func_L39_006D8FC0);

INCLUDE_ASM("asm/levels", func_L39_006D9000);

INCLUDE_ASM("asm/levels", func_L39_006D9028);

INCLUDE_ASM("asm/levels", func_L39_006D9068);

INCLUDE_ASM("asm/levels", func_L39_006D9090);

INCLUDE_ASM("asm/levels", func_L39_006D90D0);

INCLUDE_ASM("asm/levels", func_L39_006D90F8);

INCLUDE_ASM("asm/levels", func_L39_006D9138);

INCLUDE_ASM("asm/levels", func_L39_006D9160);

INCLUDE_ASM("asm/levels", func_L39_006D91A0);

INCLUDE_ASM("asm/levels", func_L39_006D91C8);

INCLUDE_ASM("asm/levels", func_L39_006D9208);

INCLUDE_ASM("asm/levels", func_L39_006D9230);

INCLUDE_ASM("asm/levels", func_L39_006D9270);

INCLUDE_ASM("asm/levels", func_L39_006D9298);

INCLUDE_ASM("asm/levels", func_L39_006D92D8);

/* localdecomp:start func_L39_006D9300 */
void *func_L39_006D9300(void *arg0) {
    (*(s8 *)arg0) = 0;
    *(s8 *)((u8 *)arg0 + 0x14C) = 0;
    *(s8 *)((u8 *)arg0 + 0x1C0) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D9300 */

INCLUDE_ASM("asm/levels", func_L39_006D9318);

INCLUDE_ASM("asm/levels", func_L39_006D9328);

INCLUDE_ASM("asm/levels", func_L39_006D9808);

INCLUDE_ASM("asm/levels", func_L39_006D98C8);

INCLUDE_ASM("asm/levels", func_L39_006D9A40);

INCLUDE_ASM("asm/levels", func_L39_006D9BC0);

INCLUDE_ASM("asm/levels", func_L39_006D9C90);

INCLUDE_ASM("asm/levels", func_L39_006D9E10);

INCLUDE_ASM("asm/levels", func_L39_006D9E68);

/* localdecomp:start func_L39_006D9FD8 */
typedef struct {
 int f0; char f4; char pad5[0xBB]; char fC0; char padC1[0x23];
 char fE4; char padE5[7]; char fEC; char padED[7]; char fF4;
 char padF5[0x67]; char f15C, f15D; char pad15E[2]; int f160, f164;
 char f168; char pad169[3]; int f16C, f170; char pad174[0x24];
 char f198, f199; char pad19A[2]; int f19C, f1A0; char f1A4;
 char pad1A5[3]; int f1A8, f1AC;
} Type1;

/* from rac4-decomp's func_L00_007770F0, renamed */
Type1 *func_L39_006D9FD8(Type1 *p) {
 p->f0 = -1;
 p->f4 = 0; p->fC0 = 0; p->fE4 = 0; p->fEC = 0; p->fF4 = 0;
 p->f15C = 0; p->f15D = 0; p->f160 = -1; p->f164 = -1;
 p->f168 = 0; p->f16C = 10000; p->f170 = -1;
 p->f198 = 0; p->f199 = 0; p->f19C = -1; p->f1A0 = -1; p->f1A4 = 0; p->f1AC = -1; p->f1A8 = 10000;
 return p;
}
/* localdecomp:end func_L39_006D9FD8 */

INCLUDE_ASM("asm/levels", func_L39_006DA038);

/* localdecomp:start func_L39_006DA090 */
s32 func_L39_006DD608(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005958A0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001961E8(void *);
s32 func_001961F8(void);
__asm__(".extern D_L39_0024D760, 16");
extern Obj_006DA090 *D_L39_0024D760;
extern u16 D_L39_00249F40[];

s32 func_L39_006DA090(s32 a0, void *a1) {
    Loc_006DA090 loc;
    Obj_006DA090 *p;
    s32 r;
    s32 x;

    p = D_L39_0024D760;
    x = p->f50;
    r = func_L39_006DD608(p->f54, a1, 0);
    if (r != 0) {
        loc.f00 = D_L39_00249F40[0];
        func_001206F4((u8 *)&loc + 0x15, x);
        loc.f28 = 0;
        loc.f2C = -1;
        func_L39_005958A0(loc.f30, a1, 0x40);
        func_001961E8(func_0017EC38(&loc));
        if (func_001961F8() != 0) {
            p->f10 = 0x49;
            if (p->f14 == 0) {
                p->f14 = 0x49;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA090 */

INCLUDE_ASM("asm/levels", func_L39_006DA158);

INCLUDE_ASM("asm/levels", func_L39_006DA1C0);

INCLUDE_ASM("asm/levels", func_L39_006DA2A8);

INCLUDE_ASM("asm/levels", func_L39_006DA310);

INCLUDE_ASM("asm/levels", func_L39_006DA3F8);

INCLUDE_ASM("asm/levels", func_L39_006DA628);

INCLUDE_ASM("asm/levels", func_L39_006DA680);

INCLUDE_ASM("asm/levels", func_L39_006DA878);

INCLUDE_ASM("asm/levels", func_L39_006DA958);

INCLUDE_ASM("asm/levels", func_L39_006DAB18);

INCLUDE_ASM("asm/levels", func_L39_006DABF0);

INCLUDE_ASM("asm/levels", func_L39_006DAFC8);

INCLUDE_ASM("asm/levels", func_L39_006DB098);

INCLUDE_ASM("asm/levels", func_L39_006DB450);

INCLUDE_ASM("asm/levels", func_L39_006DB5B0);

INCLUDE_ASM("asm/levels", func_L39_006DB5D0);

INCLUDE_ASM("asm/levels", func_L39_006DB730);

INCLUDE_ASM("asm/levels", func_L39_006DB750);

INCLUDE_ASM("asm/levels", func_L39_006DB890);

INCLUDE_ASM("asm/levels", func_L39_006DB948);

INCLUDE_ASM("asm/levels", func_L39_006DBD58);

INCLUDE_ASM("asm/levels", func_L39_006DBEE0);

INCLUDE_ASM("asm/levels", func_L39_006DC148);
