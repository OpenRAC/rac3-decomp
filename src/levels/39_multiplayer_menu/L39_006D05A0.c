#include "common.h"

typedef struct S_006CD768 {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006CD768;

/* declared by functions of L39_006CCE90.c, which this file was cut from */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
long func_0012DCB0(void);
long func_00130760(long, long);

/* localdecomp:start func_L39_006D05A0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} E_006D05A0;
typedef struct {
    u8 _p0[0x3B4];
    u8 f3B4;
    u8 _p3B5[3];
    s32 f3B8;
    u8 f3BC;
    u8 _p3BD[3];
    s32 f3C0;
    u8 _p3C4[0x3CC - 0x3C4];
    E_006D05A0 e[1];
    u8 _p3D8[0x3EC - 0x3D8];
    u8 f3EC;
    u8 _p3ED[7];
    u8 f3F4;
    u8 _p3F5[3];
    s32 f3F8;
    u8 _p3FC[0x424 - 0x3FC];
    u8 f424;
    u8 _p425[7];
    u8 f42C;
    u8 _p42D[3];
    s32 f430;
    u8 _p434[0x45C - 0x434];
    u8 f45C;
    u8 _p45D[7];
    u8 f464;
    u8 _p465[3];
    s32 f468;
    u8 _p46C[0x494 - 0x46C];
    s32 f494;
    s32 f498;
    u8 f49C;
    u8 _p49D[7];
    u8 f4A4;
    u8 _p4A5[3];
    s32 f4A8;
    u8 _p4AC[0x4D4 - 0x4AC];
    u8 f4D4;
    u8 _p4D5[3];
    s32 f4D8;
    u8 f4DC;
    u8 _p4DD[7];
    u8 f4E4;
    u8 _p4E5[3];
    s32 f4E8;
    u8 _p4EC[0x514 - 0x4EC];
    u8 f514;
    u8 f515;
    u8 _p516[0x51C - 0x516];
    u8 f51C;
    u8 _p51D[3];
    s32 f520;
} S_006D05A0;

long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_L39_006D08E8(u8 *);
s32 func_L39_006D0DD0(u8 *);
s32 func_L39_006D1658(u8 *);
s32 func_L39_006D1B40(u8 *);
s32 func_L39_006D2030();
void func_L39_006D2500(void *, s32, s32);
s32 func_L39_006D29F0();
void func_L39_006DF168(void);
extern u8 D_L39_0024A0E4;
extern s32 D_L39_002467DC __attribute__((section(".data")));
extern s32 D_L39_002467E0 __attribute__((section(".data")));

s32 func_L39_006D05A0(S_006D05A0 *a) {
    s32 r = 1;
    E_006D05A0 *e;

    if (a->f3B4 != 0 && a->f3BC != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f3C0 >= 15001) {
        a->f3BC = 0;
        r = 0;
        func_L39_006D08E8((u8 *)a);
    }
    if (a->f3EC != 0 && a->f3F4 != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f3F8 >= 15001) {
        a->f3F4 = 0;
        r = 0;
        func_L39_006D0DD0((u8 *)a);
    }
    if (a->f424 != 0 && a->f42C != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f430 >= 15001) {
        a->f42C = 0;
        r = 0;
        func_L39_006D1658((u8 *)a);
    }
    if (a->f45C != 0 && a->f464 != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f468 >= 15001) {
        a->f464 = 0;
        r = 0;
        func_L39_006D1B40((u8 *)a);
    }
    if (a->f49C != 0 && a->f4A4 != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f4A8 >= 15001) {
        a->f4A4 = 0;
        r = 0;
        func_L39_006D2030(a, a->f494, a->f498, 1);
    }
    if (a->f4DC != 0 && a->f4E4 != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f4E8 >= 15001) {
        a->f4E4 = 0;
        r = 0;
        func_L39_006D2500(a, a->f4D4, a->f4D8);
    }
    if (a->f515 != 0 && a->f51C != 0
        && (s32)func_00130760(func_0012DCB0(), 0x24000) - a->f520 >= 15001) {
        a->f51C = 0;
        r = 0;
        func_L39_006D29F0(a, a->f514);
    }
    if (D_L39_0024A0E4 != 0 && a->f3BC == 0 && D_L39_002467DC == 0 && D_L39_002467E0 == 0) {
        e = 0;
        if (a->f3B4 != 0 && a->f3B8 >= 0) {
            e = &a->e[a->f3B8];
        }
        if (e != 0 && e->f4 > 0) {
            func_L39_006DF168();
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D05A0 */
