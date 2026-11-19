#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void * func_003AF0B8();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AD270.c's earlier functions */
extern s32 *func_003AAEB8();
extern u8 *func_003AED10(u8 *p);

extern u8 *D_001D5C78_003AEE38;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
extern s32 func_003ABDD8();
extern void func_003AB4A0();
extern void func_003ABD18();
extern void func_003ABBE0();
extern void func_003ABBE8();
extern void func_003AB530();
extern void func_003AB548();
extern void func_003ABD30();
extern void func_003ABD10();
extern void func_003AD7D8();
extern void func_003ABFA8();
extern void func_003AB778();
extern f32 *func_003AB820();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
INCLUDE_ASM("asm/nonmatchings/text", func_003AEE38);

LINKER_REMNANT("asm/remnants", func_003AF058);

/* localdecomp:start func_003AF068 */
extern void func_003ACBC0(void *);
 
void func_003AF068(void *p, s32 i) {
    func_003ACBC0((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF068 */

/* localdecomp:start func_003AF090 */
extern void func_003AD278(void *);
 
void func_003AF090(void *p, s32 i) {
    func_003AD278((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF090 */

extern void *func_003ABE28(void *);
extern void func_00121760(void *, void *);
extern s32 func_003A26F0();
extern void func_003ABE30(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2750(s32);
extern void func_003ABD38(void *);
extern void func_003AEE38(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF0B8);

LINKER_REMNANT("asm/remnants", func_003AF290);
