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

/* localdecomp:start func_0012BE28 */
typedef struct {
    u8 b[8];
} Clock_12BE28;

extern u8 D_00140B00[];
extern s32 D_0013F92C_0012BE28;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);

s32 func_0012BE28(Clock_12BE28 *clock) {
    s32 r;

    if (func_0012B1A8(0xF) == 0) {
        return 0;
    }
    if (func_00122810(&D_00141480, 1, 0, 0, 0, D_00140B00, 0x10, 0, 0) < 0) {
        func_0011EE40(D_0013F92C_0012BE28);
        return 0;
    }
    *clock = *(Clock_12BE28 *)((u32)(D_00140B00 + 4) | 0x20000000);
    r = *(s32 *)((u32)D_00140B00 | 0x20000000);
    func_0011EE40(D_0013F92C_0012BE28);
    return r;
}
/* localdecomp:end func_0012BE28 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BEE4);

/* localdecomp:start func_0012BEE8 */
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

void func_0012BEE8(short mode, short inter, short omode, short ffmode)
{
    GParam_12BEE8 *gp;

    switch (mode) {
    case 0:
        gp = func_0012C078_0012BEE8();
        *(volatile u64 *)0x12001000 = 0x200;
        gp->inter = inter;
        gp->omode = omode;
        gp->version = (*(volatile u64 *)0x12001000 >> 16) & 0xFF;
        func_0011F160(0xFF00);
        gp->ffmode = ffmode != 0;
        if (gp->vsc) {
            func_0011F870(2);
            func_0011EB20(2, gp->vscid);
            gp->vsc = 0;
            gp->vscid = 0;
        }
        func_0011EA20(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    case 1:
        *(volatile u64 *)0x12001000 = 0x100;
        break;
    case 5:
        gp = func_0012C078_0012BEE8();
        gp->inter = inter;
        gp->omode = omode;
        gp->ffmode = ffmode != 0;
        gp->version = (*(volatile u64 *)0x12001000 >> 16) & 0xFF;
        func_0011EA20(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    }
}
/* localdecomp:end func_0012BEE8 */
