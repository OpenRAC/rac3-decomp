#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00122810();
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

/* localdecomp:start func_0012AE20 */
extern s32 D_0013F924_0012AE20[];
extern s32 D_0013F948_0012AE20[];
extern void func_0012ADC8(void);
extern void func_00121B70();
extern s32 func_00124920(void);
extern s32 func_00124970(void);

s32 func_0012AE20(void) {
    s32 r;
    D_0013F924_0012AE20[0] = 1;
    r = func_00124920();
    func_00121B70(0x80000012, func_0012ADC8, 0);
    if (r != 0) {
        func_00124970();
    }
    D_0013F924_0012AE20[0] = 0;
    D_0013F948_0012AE20[0] = 1;
    return 1;
}
/* localdecomp:end func_0012AE20 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AE98);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AEA0);

/* localdecomp:start func_0012AEA8 */
/* libcdvd: init-style RPC bind under the sema (D_0013F928); 2.9-ee-991111 */
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

s32 func_0012AEA8(s32 mode) {
    func_0012AC40_0012AEA8();
    if (D_0013F928 != func_0011EE70(D_0013F928)) {
        if (D_0013F910 > 0) {
            func_00121760_0012AEA8(D_001513B8, mode, D_0013F91C);
        }
        return 0;
    }
    D_0013F91C = mode;
    if (func_0012B098(1) != 0) {
        func_0011EE40(D_0013F928);
        return 0;
    }
    func_00121FE8(0);
    if (D_0013F93C < 0) {
        while (1) {
            s32 i;
            if (func_00122630(&D_00140AD0, 0x80000595, 0) < 0) {
                if (D_0013F910 > 0) {
                    func_00121760_0012AEA8(D_001513E0);
                }
                i = 0x100000;
                while (--i != -1) {
                }
            } else if (D_00140AD0.x24 != 0) {
                D_0013F93C = 0;
                break;
            } else {
                i = 0x100000;
                while (--i != -1) {
                }
            }
        }
    }
    return 1;
}
/* localdecomp:end func_0012AEA8 */

/* localdecomp:start func_0012B000 */
extern u8 D_0013F980[];
s32 func_0012B000(void) {
    s32 r;
    s32 v;

    if (func_0012AEA8(2) == 0) {
        return 0;
    }
    r = func_00122810(&D_00140AD0, 0xE, 0, 0, 0, D_0013F980, 4, 0, 0);
    if (r < 0) {
        func_0011EE40(*(s32 *)&D_0013F928);
        return 0;
    }
    v = *(s32 *)((u32)D_0013F980 | 0x20000000);
    func_0011EE40(*(s32 *)&D_0013F928);
    return v;
}
/* localdecomp:end func_0012B000 */
