#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 12A948.c's earlier functions (tools/port_from_us.py) */
extern s32 func_0012B098(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 D_15A140;
extern void *D_15A144;
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F934;
extern volatile int D_0013F960;
extern volatile int D_0013F964;
extern int D_15A140;
extern void func_0011EE50(s32);
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12AC40;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F92C;
extern volatile int D_0013F930;
extern volatile int D_0013F934;
extern char D_00151300[];
extern char D_00151310[];
extern char D_00151320[];
extern char D_00151330[];
extern int func_0011EE20();
extern s32 D_0013F924_0012AE20[];
extern s32 D_0013F948_0012AE20[];
extern void func_0012ADC8(void);
extern void func_00121B70();
extern s32 func_00124920(void);
extern s32 func_00124970(void);
typedef struct { u8 pad[0x24]; s32 x24; } S_12AEA8;
extern void func_0012AC40_0012AEA8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012AEA8();
extern s32 func_0012B098(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern volatile s32 D_0013F928;
extern s32 D_0013F910;
extern s32 D_0013F91C;
extern s32 D_0013F93C;
extern S_12AEA8 D_00140AD0;
extern char D_001513B8[];
extern char D_001513E0[];
extern u8 D_0013F980[];
extern s32 D_0013F910_0012B138[];
extern u8 D_00141480_0012B138[];
extern char D_00151408_0012B138[];
extern s32 func_00122A10(void *);
extern s32 func_0011FC78(s32);
extern void func_00121760_0012B1A8(const char *, ...);
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12B1A8;
extern volatile s32 D_0013F92C;
extern s32 D_0013F910;
extern s32 D_0013F918;
extern s32 D_0013F954;
extern Cd_12B1A8 D_00141480_0012B1A8;
extern char D_00151418[];
extern char D_00151440[];
extern void func_0012AC40_0012B1A8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012B1A8(const char *, ...);
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630_0012B1A8(Cd_12B1A8 *, u32, s32);
typedef struct { u8 pad[0x24]; s32 x24; } S_12B5E8;
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_00121760_0012B5E8();
extern void func_00121F38();
extern s32 func_00122810();
extern s32 func_00124920(void);
extern void func_00124970_0012B5E8(void);
extern void func_0012AC40_0012B5E8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 D_0013F910;
extern volatile s32 D_0013F92C;
extern s32 D_0013F940;
extern s32 D_0013F950;
extern S_12B5E8 D_15A390;
extern s32 D_15A3D0;
extern s32 D_00140B00_0012B5E8[];
extern char D_00151488[];
extern char D_001514A0[];
extern char D_001514C0[];
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x40 - 0x28];
} Cd_12B800;
extern int D_0013F910;
extern volatile int D_0013F930;
extern int D_0013F940;
extern int D_0013F950;
extern char D_001514A0[];
extern char D_001514C0[];
extern char D_001514D8[];
extern Cd_12B800 D_15A390_0012B800;
extern int D_15A3D0;
extern int D_00141380[];
extern int func_00121760();
extern int func_0011EE40();
extern int func_0011EE70();
extern int func_00121FE8_0012B800();
extern void func_00121F38();
extern int func_0012AC40();
extern int func_0012B5E8();
extern int func_00124920();
extern int func_00124970_0012B800();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();
extern s32 D_00140B00_0012BC00[];
extern u8 D_00141480_0012BC00[];
extern s32 D_0013F92C_0012BC00[];
extern volatile int D_0013F960;
extern u8 D_00141480[];
extern int D_00140B00_0012BC98[];
extern int func_0012B1A8(int n);
extern s32 D_00140F40;
extern s32 D_001414A8;
extern s32 D_001414AC;
extern s32 D_001414B0;
extern u8 D_00140B00[];
extern u8 D_00141480[];
extern s32 D_0013F92C_0012BD50;
extern s32 func_0012B1A8(s32);
extern void func_00121F38(void *, s32);
extern s32 func_00122810();
extern s32 func_0011EE40(s32);
typedef struct {
    u8 b[8];
} Clock_12BE28;
extern u8 D_00140B00[];
extern s32 D_0013F92C_0012BE28;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
typedef struct {
    s16 inter;
    s16 omode;
    s16 ffmode;
    u16 version;
    int vsc;
    int vscid;
} GParam_12BEE8;
GParam_12BEE8 *func_0012C078_0012BEE8(void);
u64 func_0011F160(u64 imr);
void func_0011F870(int n);
void func_0011EB20(int n, int id);
void func_0011EA20(int inter, int omode, int ffmode);
extern u8 D_001414D0[];
extern s32 func_00123430(void *, s32);
extern s32 func_00123840(s32, void *, s32);
extern void func_001236C0(s32);
extern s32 func_00117070(void *);
extern u8 D_00151540[];

ASM_FUNC("asm/boot_elf/handwritten", func_0012C128);

/* localdecomp:start func_0012C138 */
/* libgraph sceGsSetDefDispEnv (graph003.o), as rac1-decomp and rac2-decomp have it */
typedef struct {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 bgcolor;
} DispEnv_12C138;
extern char D_00151550[];

void func_0012C138(DispEnv_12C138 *disp, s16 psm, s16 w, s16 h, s16 dx, s16 dy) {
    extern s32 func_0012C088(void);
    extern void func_0012C128(s32, s32 *, s32 *, s32 *, s32 *);
    GParam_12BEE8 *gp;
    int dx1, dy1, dx2, dy2;
    int mode;
    short omode;
    unsigned short imode;

    gp = func_0012C078_0012BEE8();
    if (gp->omode != 2 && gp->omode != 3 && func_0012C088() != 0) {
        func_0012C128(gp->omode, &dx1, &dy1, &dx2, &dy2);
    } else {
        dy2 = 0;
        dx2 = 0;
        dy1 = 0;
        dx1 = 0;
    }
    imode = gp->inter;
    disp->pmode = 0x66;
    if (gp->inter != 0) {
        if (gp->ffmode != 0) {
            disp->smode2 = 3;
        } else {
            disp->smode2 = 1;
        }
    } else {
        disp->smode2 = 2;
    }
    disp->dispfb = ((unsigned long)(psm & 0xF) << 15) | ((unsigned long)(((w + 63) >> 6) & 0x3F) << 9);
    omode = gp->omode;
    if (omode == 2) {
        if ((short)imode == 1) {
            int magh = (w + 2559) / w;
            unsigned long dxo = (unsigned long)dx1 + 636;
            disp->display =
                ((((unsigned long)(magh - 1) << 23) |
                  (((dx * magh + dxo) & 0xFFF) | ((unsigned long)(gp->ffmode ? (h << 1) - 1 : h - 1) << 44))) |
                 (((unsigned long)(dy + dy1 + 50) & 0xFFF) << 12)) |
                ((unsigned long)(magh * w - 1) << 32);
        } else {
            int magh = (w + 2559) / w;
            unsigned long dxo = (unsigned long)dx1 + 636;
            magh = (w + 2559) / w;
            disp->display = ((((unsigned long)((w + 2559) / w - 1) << 23) |
                              (((dx * ((w + 2559) / w) + dxo) & 0xFFF) | ((unsigned long)(h - 1) << 44))) |
                             (((unsigned long)(dy + dy1 + 25) & 0xFFF) << 12)) |
                            ((unsigned long)((w + 2559) / w * w - 1) << 32);
        }
    } else if (omode == 3) {
        if ((short)imode == 1) {
            int magh = (w + 2559) / w;
            unsigned long dxo = (unsigned long)dx1 + 656;
            disp->display =
                ((((unsigned long)(magh - 1) << 23) |
                  (((dx * magh + dxo) & 0xFFF) | ((unsigned long)(gp->ffmode ? (h << 1) - 1 : h - 1) << 44))) |
                 (((unsigned long)(dy + dy1 + 72) & 0xFFF) << 12)) |
                ((unsigned long)(magh * w - 1) << 32);
        } else {
            int magh = (w + 2559) / w;
            unsigned long dxo = (unsigned long)dx1 + 656;
            magh = (w + 2559) / w;
            disp->display = ((((unsigned long)((w + 2559) / w - 1) << 23) |
                              (((dx * ((w + 2559) / w) + dxo) & 0xFFF) | ((unsigned long)(h - 1) << 44))) |
                             (((unsigned long)(dy + dy1 + 36) & 0xFFF) << 12)) |
                            ((unsigned long)((w + 2559) / w * w - 1) << 32);
        }
    } else if (omode == 0x50) {
        unsigned long dxo = (unsigned long)(dx * 2) + 232;
        disp->display =
            ((((unsigned long)(h - 1) << 44) | ((((720 - w) / 2 * 2 + (unsigned long)dx1 + dxo) & 0xFFF) | 0x800000)) |
             (((unsigned long)(dy + dy1 + 35) & 0xFFF) << 12)) |
            ((unsigned long)(w * 2 - 1) << 32);
    } else {
        func_00121760(D_00151550);
    }
    disp->bgcolor = 0;
}
/* localdecomp:end func_0012C138 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C4AC);
