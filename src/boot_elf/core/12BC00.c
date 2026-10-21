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

/* localdecomp:start func_0012BC00 */
extern s32 D_00140B00_0012BC00[];
extern u8 D_00141480_0012BC00[];
extern s32 D_0013F92C_0012BC00[];

s32 func_0012BC00(void) {
    s32 r;
    s32 *rb;
    s32 v;

    if (func_0012B1A8(3) == 0) {
        return -1;
    }
    rb = (s32 *)D_00140B00_0012BC00;
    r = func_00122810(D_00141480_0012BC00, 4, 0, 0, 0, rb, 4, 0, 0);
    if (r < 0) {
        func_0011EE40(D_0013F92C_0012BC00[0]);
        return -1;
    }
    v = *(s32 *)((u32)rb | 0x20000000);
    func_0011EE40(D_0013F92C_0012BC00[0]);
    return v;
}
/* localdecomp:end func_0012BC00 */

/* localdecomp:start func_0012BC98 */
extern volatile int D_0013F960;
extern u8 D_00141480[];
extern int D_00140B00_0012BC98[];
extern int func_0012B1A8(int n);

int func_0012BC98(void)
{
    int r;

    if (func_0012B1A8(0x1E) == 0) {
        return 0;
    }
    D_0013F960 = 8;
    if (func_00122810(D_00141480, 0x16, 0, 0, 0, D_00140B00_0012BC98, 4, 0, 0) < 0) {
        func_0011EE40(D_0013F92C);
        D_0013F960 = 0;
        return 0;
    }
    D_0013F960 = 0;
    r = *(int *)((u32)D_00140B00_0012BC98 | 0x20000000);
    func_0011EE40(D_0013F92C);
    return r;
}
/* localdecomp:end func_0012BC98 */

/* localdecomp:start func_0012BD50 */
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

s32 func_0012BD50(s32 arg)
{
    s32 *buf = &D_00140F40;
    s32 r;

    if (func_0012B1A8(0x22) == 0) {
        return 0;
    }
    *buf = arg;
    func_00121F38(buf, 4);
    if (func_00122810(D_00141480, D_001414A8, 0, buf, D_001414AC, D_00140B00, D_001414B0, 0, 0) < 0) {
        func_0011EE40(D_0013F92C_0012BD50);
        return 0;
    }
    r = *(s32 *)((u32)D_00140B00 | 0x20000000);
    func_0011EE40(D_0013F92C_0012BD50);
    return r;
}
/* localdecomp:end func_0012BD50 */
