#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CD410();
/* --- end of declarations from other files --- */

/* declarations of 3CD1B0.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 p[0x24]; } T36_3C79F0;
typedef struct { s32 k; s32 f4; T36_3C79F0 *f8; } E12_3C79F0;
extern E12_3C79F0 D_00380F00[];
extern T36_3C79F0 D_00380F0C[];
extern s32 D_001DA480;
extern s32 D_001DA484;
extern s32 D_002DD190[];
extern u8 D_002DD390[];
extern s32 D_002DAB00[];
extern u8 D_002DAEC0[];

LINKER_REMNANT("asm/boot_elf/remnants", func_003CD400);

/* US draft of func_003CD410 (rac3-uya-decomp func_003CD2A8, commit 13cf5c5), names moved to PAL addresses
   where known. The unmapped US symbol func_003C7250 is the PAL function func_003C7398. */


/* localdecomp:start func_003CD410 */
typedef struct N_3C7AE8 { u8 p0[0x20]; s8 f20; u8 p21[0x7]; struct N_3C7AE8 *f28; u8 p2C[0x8]; u16 h34; u8 p36[0x2E]; void (*f64)(struct N_3C7AE8 *); } N_3C7AE8;
extern N_3C7AE8 *func_003C7908();
extern void func_003C7398();
extern void func_003C7FF0();
extern u8 D_001DA4AC[];
extern N_3C7AE8 *D_001DA4A8;
void func_003CD410(void) {
    N_3C7AE8 *n;
    n = D_001DA4A8 = func_003C7908(D_001DA4AC);
    while (n != 0) {
        if (n->f20 >= 0) {
            if ((n->h34 & 0x40) == 0) {
                func_003C7398(n);
            }
            if (n->f64 != 0 && (n->h34 & 2) == 0) {
                n->f64(n);
            }
            if ((n->h34 & 4) == 0) {
                func_003C7FF0(n);
            }
        }
        n = n->f28;
    }
}
/* localdecomp:end func_003CD410 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003CD4B8);
