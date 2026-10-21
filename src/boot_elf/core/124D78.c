#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 124988.c's earlier functions (tools/port_from_us.py) */
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; s32 f30; void *f34; } S_124988;
extern s32 D_0013E310[];
extern s32 D_0013E314[];
extern u8 D_00150DC0[];
extern u8 D_00150DD0[];
extern s32 func_0011EE20(void *);
extern u32 D_0013E300[4];
extern u32 D_0013E2F8;
extern void func_00124B80(u32, u32);
extern u32 func_00124A68(u32, u32, void *);
extern void func_00124A28(void);
extern void func_001249F0(void);
extern void func_0011EED0(s32 *);
extern void func_0011EEC0(s32 *);

/* localdecomp:start func_00124D78 */
s32 func_00124D78(u8 *dst, u8 *src, u32 n) {
    u32 i = 0;
    u32 more;
    if (n != 0) {
        do {
            u8 c = *src;
            i++;
            src++;
            more = i < n;
            *dst = c;
            dst++;
        } while (more);
    }
    return 0;
}
/* localdecomp:end func_00124D78 */
