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

/* localdecomp:start func_0012AC40 */
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

void func_0012AC40(void)
{
    SemaParam_12AC40 sp;

    if (D_0013F928 != -1 && D_0013F92C != -1 && D_0013F930 != -1) {
        return;
    }
    sp.init_count = 1;
    sp.max_count = 1;
    sp.option = (u32)D_00151300;
    D_0013F928 = func_0011EE20(&sp);
    sp.option = (u32)D_00151310;
    D_0013F92C = func_0011EE20(&sp);
    sp.option = (u32)D_00151320;
    D_0013F930 = func_0011EE20(&sp);
    sp.option = (u32)D_00151330;
    sp.init_count = 0;
    D_0013F920 = func_0011EE20(&sp);
    D_0013F934 = 0;
}
/* localdecomp:end func_0012AC40 */
