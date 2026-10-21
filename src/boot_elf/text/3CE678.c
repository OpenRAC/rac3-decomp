#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CE678(void);
/* --- end of declarations from other files --- */

/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);
extern s32 func_003CE450(s32, s32);
s32 func_003CE798_003CE568(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE568;
extern s32 D_001DA650;
typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;
extern int D_001DA050;
extern Config_003C8CE0 *D_001DA5F0_003CE608;
extern int D_001DA600;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9BFC;

/* localdecomp:start func_003CE678 */
extern u32 *D_001DA050_003CE678;
extern u32 *D_001DA600_003CE678;
extern u32 *D_001DA604_003CE678;
extern s32 D_001D4BB0_003CE678;
extern s32 D_001D4BB4_003CE678;
__asm__(".extern D_001DA600_003CE678, 16");
__asm__(".extern D_001DA050_003CE678, 16");
__asm__(".extern D_001DA604_003CE678, 16");
__asm__(".extern D_001D4BB0_003CE678, 16");
__asm__(".extern D_001D4BB4_003CE678, 16");
extern void func_003A06E8();
extern s32 func_003A99D0();
void func_003CE678(void) {
    D_001DA604_003CE678 = D_001DA050_003CE678;
    D_001DA050_003CE678 += 4;
    D_001DA600_003CE678[0] = 0x20000000;
    { u32 *q = D_001DA600_003CE678; q[1] = (u32)D_001DA050_003CE678; D_001DA600_003CE678[2] = 0; D_001DA600_003CE678[3] = 0; func_003A06E8(q); }
    func_003A99D0();
    D_001DA050_003CE678[0] = 0x20000000;
    D_001DA050_003CE678[1] = (u32)(D_001DA600_003CE678 + 4);
    D_001DA050_003CE678[2] = 0;
    D_001DA050_003CE678[3] = 0;
    D_001DA050_003CE678 += 4;
    D_001DA604_003CE678[0] = 0x20000000;
    D_001DA604_003CE678[1] = (u32)D_001DA050_003CE678;
    D_001DA604_003CE678[2] = 0;
    D_001DA604_003CE678[3] = 0;
    D_001D4BB0_003CE678 = D_001D4BB4_003CE678;
}
/* localdecomp:end func_003CE678 */
