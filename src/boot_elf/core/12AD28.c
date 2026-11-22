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

/* localdecomp:start func_0012AD28 */
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern int func_0011EE30();
extern int func_0011EE40();
extern void func_00121BE8(s32);
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F92C;
extern volatile int D_0013F930;
extern volatile int D_0013F960;

void func_0012AD28(void)
{
    s32 di;

    if (D_0013F914 != 0) {
        D_0013F960 = -1;
        func_0011EE40(D_0013F920);
    }
    func_0011EE30(D_0013F928);
    func_0011EE30(D_0013F92C);
    func_0011EE30(D_0013F930);
    func_0011EE30(D_0013F920);
    di = func_00124920();
    func_00121BE8(0x80000012);
    if (di) {
        func_00124970();
    }
}
/* localdecomp:end func_0012AD28 */

ASM_FUNC("asm/boot_elf/handwritten", func_0012ADC8);
