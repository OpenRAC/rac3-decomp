#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* localdecomp:start func_L01_004A1910 */
extern E_49E5B8 D_L01_002ED850[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];

void func_L01_004A1910(void) {
    s32 i = 0;
    s32 n;
    while (D_L01_002ED850[i].x0 != 0) {
        switch (D_L01_002ED850[i].x10) {
        case 1: {
            s32 k;
            D_L01_002ED850[i].x14 = 1;
            n = i + 1;
            for (k = 0; ((u32 *)D_L01_002ED850[i].xC)[k] != 0; k++) {
                D_L01_002ED850[i].x14 = D_L01_002ED850[i].x14 && (D_00142BA0[((u32 *)D_L01_002ED850[i].xC)[k] >> 2] & (1 << (((u32 *)D_L01_002ED850[i].xC)[k] & 31))) != 0;
            }
            break;
        }
        case 0:
        case 2: {
            E_49E5B8 *e = &D_L01_002ED850[i];
            n = i + 1;
            e->x14 = (D_00142BA0[(u32)D_L01_002ED850[i].xC >> 2] & (1 << ((u32)D_L01_002ED850[i].xC & 31))) != 0;
            break;
        }
        case 3: {
            E_49E5B8 *e = &D_L01_002ED850[i];
            n = i + 1;
            e->x14 = D_00142693[0] != 0;
            break;
        }
        case 4:
        default: {
            E_49E5B8 *e = &D_L01_002ED850[i];
            n = i + 1;
            e->x14 = 1;
            break;
        }
        }
        i = n;
    }
}
/* localdecomp:end func_L01_004A1910 */

/* localdecomp:start func_L01_004A1AC8 */
extern s32 func_L01_0049F168(s32);
extern s32 D_L01_001D9660;
extern E_49E5B8 D_L01_002ED850[];
extern u8 D_L01_001EA7C0[];
extern s32 func_00392B20(void *, s32);
extern s32 func_L01_004A2240(void);
extern void func_L01_004A0A78_004A1AC8(s32);
extern s32 func_L01_00517748(s32);
extern void func_L01_00516090_004A1AC8(s32);
extern s32 func_L01_00499C80(void);

void func_L01_004A1AC8(s32 arg0) {
    s32 k;
    if (!D_L01_002ED850[D_L01_001D9660].x14) return;
    switch (D_L01_002ED850[D_L01_001D9660].x10) {
    case 0:
        func_00392B20(D_L01_001EA7C0, D_L01_002ED850[D_L01_001D9660].xC);
        break;
    case 1:
        k = 0;
        if (((s32 *)D_L01_002ED850[D_L01_001D9660].xC)[0] != 0) {
            do {
                func_00392B20(D_L01_001EA7C0, ((s32 *)D_L01_002ED850[D_L01_001D9660].xC)[k]);
                k++;
            } while (((s32 *)D_L01_002ED850[D_L01_001D9660].xC)[k] != 0);
        }
        break;
    case 2:
    case 3:
        break;
    case 4:
    default:
        if (D_L01_002ED850[D_L01_001D9660].x14) {
            switch (D_L01_002ED850[D_L01_001D9660].x0) {
            case 0x1CF:
                func_L01_00517748(func_L01_004A2240());
                func_L01_00516090_004A1AC8(arg0);
                break;
            case 0x112:
                func_L01_004A0A78_004A1AC8(1);
                func_L01_00517748(func_L01_0049F168(0));
                func_L01_00516090_004A1AC8(arg0);
                break;
            case 0x113:
                func_L01_00517748(func_L01_00499C80());
                func_L01_00516090_004A1AC8(arg0);
                break;
            }
        }
        break;
    }
}
/* localdecomp:end func_L01_004A1AC8 */

/* localdecomp:start func_L01_004A1CA8 */
extern s32 func_L01_0047EF58(s32);
extern s32 func_L01_00494160(s32);
extern void func_L01_00494390(s32, s32, s32, s32, void *);
extern s32 D_L01_001D9664;
extern s32 D_L01_001D9668;
extern u8 D_L01_00160C40[];

void func_L01_004A1CA8(void) {
    u8 *p;
    s32 v;

    D_L01_001D9664 = func_L01_0047EF58(0);
    D_L01_001D9668 = func_L01_0047EF58(0);
    v = func_L01_00494160(0);
    p = D_L01_00160C40;
    func_L01_00494390(v, D_L01_001D9664, D_L01_001D9668, *(s32 *)(p + 0x4954), p + 0x7070);
}
/* localdecomp:end func_L01_004A1CA8 */

/* localdecomp:start func_L01_004A1D00 */
extern void *D_L01_001D9664_004A1D00;
extern void *D_L01_001D9668_004A1D00;
extern void *func_L01_00494160_004A1D00(s32);
extern void func_L01_0047F018(s32);
void func_L01_004A1D00(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_L01_00494160_004A1D00)(0);
    o->vt->fn(o);
    func_L01_0047F018((*(s32 *)&D_L01_001D9664_004A1D00));
    func_L01_0047F018((*(s32 *)&D_L01_001D9668_004A1D00));
}
/* localdecomp:end func_L01_004A1D00 */

INCLUDE_ASM("asm/levels", func_L01_004A1D40);

/* localdecomp:start func_L01_004A1E18 */
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 D_L01_001D9660;
extern s32 D_L01_001D9658;
extern s32 D_L01_001D96AC;
extern E_49E5B8 D_L01_002ED850[];
extern char D_L01_001D96B0[];

void func_L01_004A1E18(void) {
    D_L01_001D9660 = func_003B9C58(func_003B9BD0(0));
    if (D_L01_001D9660 < 0) {
        return;
    }
    if (D_L01_001D9658 != D_L01_001D9660) {
        if (D_L01_002ED850[D_L01_001D9660].x14) {
            func_L01_00516FD8(0x570005, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x0));
            func_L01_00516FD8(0x570006, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x4));
        } else {
            func_L01_00516FD8(0x570005, func_00381FF0(456));
            func_L01_00516FD8(0x570006, (s32)D_L01_001D96B0);
        }
        D_L01_001D96AC = 30;
    }
    if (D_L01_001D96AC != 0) {
        if (--D_L01_001D96AC == 0) {
            if (D_L01_002ED850[D_L01_001D9660].x14) {
                ((s32 (*)(s32, s32))func_L01_00517190)(0x570009, D_L01_002ED850[D_L01_001D9660].x8 + 1);
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 1);
            } else {
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 0);
            }
        }
    }
    D_L01_001D9658 = D_L01_001D9660;
}
/* localdecomp:end func_L01_004A1E18 */

INCLUDE_ASM("asm/levels", func_L01_004A1F78);

/* localdecomp:start func_L01_004A2240 */
extern s32 func_L01_004A2240(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0D18;
extern s32 D_L01_001E0D00[2];
extern void func_L01_004A2298();
extern void func_L01_004A2360();
extern void func_L01_004A22C8();
extern void func_L01_004A23D8_004A2240(void);
extern void func_L01_004A23F8();
s32 func_L01_004A2240(void) {
    if (D_L01_001E0D18 == 0) {
        func_003E6FA0(D_L01_001E0D00, (s32)func_L01_004A2298, (s32)func_L01_004A2360, (s32)func_L01_004A22C8, (s32)func_L01_004A23D8_004A2240, (s32)func_L01_004A23F8);
        D_L01_001E0D18 = 1;
    }
    return (s32)D_L01_001E0D00;
}
/* localdecomp:end func_L01_004A2240 */

/* localdecomp:start func_L01_004A2298 */
extern void *func_003BB3A8(s32);
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001D96F0;

void func_L01_004A2298(void) {
    D_L01_001D96E8 = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96EC = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96F0 = 0;
}
/* localdecomp:end func_L01_004A2298 */

INCLUDE_ASM("asm/levels", func_L01_004A22C8);

/* localdecomp:start func_L01_004A2360 */
typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x1C];
} S_004A2360;
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96C8;
extern s32 D_L01_001D96CC;
extern s32 D_L01_001D96D0;
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001DFCC0_004A2360[] __attribute__((section(".sdata")));
extern S_004A2360 D_L01_002E5F30_004A2360;
extern s32 func_003BB468(s32);
extern s32 func_L01_00517918(s32);
extern void func_L01_004A2848(void);
extern s32 func_003A2750(s32);

void func_L01_004A2360(void) {
    D_L01_001D96C8 = -1;
    func_003BB468(D_L01_001D96E8);
    func_003BB468(D_L01_001D96EC);
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    if (D_L01_001D96C0 != 0) {
        func_L01_00517918(0x14);
    }
    func_L01_004A2848();
    func_003A2750(1);
    D_L01_001DFCC0_004A2360[0] = D_L01_001D96CC;
    D_L01_002E5F30_004A2360.f2C = D_L01_001D96D0;
}
/* localdecomp:end func_L01_004A2360 */

/* localdecomp:start func_L01_004A23D8 */
extern void func_L01_0047E4B8_004A23D8();

void func_L01_004A23D8(void) {
    func_L01_0047E4B8_004A23D8();
}
/* localdecomp:end func_L01_004A23D8 */

INCLUDE_ASM("asm/levels", func_L01_004A23F8);
