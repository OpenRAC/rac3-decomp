#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern void func_00393808(void *);
extern s32 D_001D5CAC;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern s32 func_003A5348(s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003934B8(s32);
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);
extern void func_00393808(void *arg);

/* US draft of func_00394F48 (rac3-uya-decomp func_003906E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00394F48 */
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00394F48(u8 *p) {
    D_001D9EE8[0] = 4;
    D_001D9EF0[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x19;
    D_001D5CAC = 0;
}
/* localdecomp:end func_00394F48 */
