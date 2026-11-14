#include "common.h"

/* NTSC-U counterpart of func_L39_006D4D48 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern u8 D_001A5E50[];
extern u8 D_001A5E50[];
extern void func_00195500(void);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void func_00195500(void);
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; } G_006D4B98;
extern G_006D4B98 *D_001E1FD0_sda;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);

/* localdecomp:start func_L39_006D25C0 */
typedef struct {
    u8 pad0[3];
    u8 f3;
    u8 pad4[8];
    s32 fC;
    u8 pad10[2];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} T_006D4D48;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} G_006D4D48;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D4D48;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void func_00195500(void);

s32 func_L39_006D25C0(T_006D4D48 *a0) {
    s32 r1 = 1;
    s32 r2;
    G_006D4D48 *g = (G_006D4D48 *)D_001E1FD0_sda;

    if (a0->f3) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5E50;

        do {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r1 = 0;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->fC >= 0x3A99) {
            r1 = 0;
            break;
        }
        } while (a0->f3);
    }
    a0->f3 = 0;
    r2 = 1;
    if (a0->f12) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5E50;

        do {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r2 = 0;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->f18 >= 0x3A99) {
            r2 = 0;
            break;
        }
        } while (a0->f12);
    }
    a0->f12 = 0;
    return r1 || r2;
}
/* localdecomp:end func_L39_006D25C0 */
