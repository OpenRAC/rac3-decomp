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

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B300);
