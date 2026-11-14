#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B3228(void *);
extern void func_003B3050(void);
extern void func_003B3088();
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B3218();
/* --- end of declarations from other files --- */

typedef struct { s32 f0; s32 f4; } S_003AD8A8;
extern u8 D_001DA938_003AD8A8[];
extern void func_003A9CA8();
extern void func_003E9470_003AD8A8();
extern void *func_003E6C08();
extern void *func_003B2DC8();
extern void func_003E5AA0_003AD8A8();
extern void func_003E6CD8_003AD8A8();
extern s32 *func_003B42C0();
extern s32 *func_003B4380();
extern s32 func_003E69B0();
extern s32 func_003E6D10();
extern void func_003E6E10_003AD8A8();

/* localdecomp:start func_003B3050 */
extern void *func_003E6C08();
extern void func_003E69F8(void *);
extern u8 D_001DA938[];
 
void func_003B3050(void) {
    void *x = D_001DA938;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E69F8(x);
}
/* localdecomp:end func_003B3050 */

extern u8 D_001D8880;
extern void func_003E82F8();
extern void *func_003E6C08();
extern void func_003E6A60();
extern s32 func_003E6518();
extern s32 func_003E6F18();
INCLUDE_ASM("asm/nonmatchings/text", func_003B3088);

/* localdecomp:start func_003B30E8 */
extern u8 D_001DA938[];
extern void *func_003E6C08();
extern void func_003E6A98();
 
void func_003B30E8(void) {
    void *x = D_001DA938;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6A98(x);
}
/* localdecomp:end func_003B30E8 */

/* localdecomp:start func_003B3120 */
extern u8 D_001DA938[];
extern void *func_003E6C08();
extern void func_003E6B28(void *);

void func_003B3120(void) {
    void *x = D_001DA938;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6B28(x);
}
/* localdecomp:end func_003B3120 */

extern void func_003A9CA8();
extern void func_003E6E10_003B3158();
extern void func_003E6BB8();
extern void *func_003E6C08();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3158;
INCLUDE_ASM("asm/nonmatchings/text", func_003B3158);

LINKER_REMNANT("asm/remnants", func_003B3210);

extern s32 D_001D8888;
extern s32 D_001D888C;
/* localdecomp:start func_003B3218 */
extern s32 D_001D8888;
extern s32 D_001D888C;
void func_003B3218(s32 a) { D_001D8888 = a; D_001D888C = 0; }
/* localdecomp:end func_003B3218 */

/* localdecomp:start func_003B3228 */
extern void *D_001D8890;
void func_003B3228(void *a) {
    D_001D8890 = a;
}
/* localdecomp:end func_003B3228 */

/* localdecomp:start func_003B3230 */
extern void *D_001D8890;
extern void func_003B3258(void *, s32);
void func_003B3230(void) {
    if (D_001D8890 != 0) func_003B3258(D_001D8890, 0);
}
/* localdecomp:end func_003B3230 */
