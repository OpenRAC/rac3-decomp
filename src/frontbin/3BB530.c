#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003BB7B0(s32);
extern s32 func_12C908(s32);
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
void func_003A0760(u8 *, u32);
extern void func_003BB5D0();
extern void func_003BB590(s32);
extern void func_003A0760();
extern s32 func_003BB530(s32);


extern s32 D_001DA1B0_003BB530[];
extern s32 D_001DA1B4_003BB530[];
/* localdecomp:start func_003BB530 */
extern int D_001DA1B0[] __attribute__((section(".sdata")));
typedef struct {
    int key;
    int flags;
} ChunkSlot;
extern int D_001DA1B4[] __attribute__((section(".sdata")));

int func_003BB530(int key)
{
    int count = 0;
    unsigned int large = 0x4F000;
    int *flags = D_001DA1B4;
    int *keys = D_001DA1B0;
    do {
        count++;
        if (*keys == key)
            return (*flags & 1) ? large : 0x12C00;
        flags += 2;
        keys += 2;
    } while (count < 7);
    return -1;
}
/* localdecomp:end func_003BB530 */

/* localdecomp:start func_003BB590 */
extern f32 D_001D8C2C;
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_003E7D70(s32, s32);
void func_003BB590(s32 a) {
    func_003E7D70(a, ((s32 (*)(s32, s32, f32))func_0038DBD8)(0x20000000, 0x402299DE, D_001D8C2C));
}
/* localdecomp:end func_003BB590 */
