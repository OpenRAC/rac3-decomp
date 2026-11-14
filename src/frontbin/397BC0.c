#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_00397CC0();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


LINKER_REMNANT("asm/remnants", func_00397BC0);

/* localdecomp:start func_00397BD0 */
extern u8 D_001D5EDC;
void func_00397BD0(void) { D_001D5EDC = 1; }
/* localdecomp:end func_00397BD0 */

extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_0038AE20();
INCLUDE_ASM("asm/nonmatchings/text", func_00397BE0);

LINKER_REMNANT("asm/remnants", func_00397C78);

/* localdecomp:start func_00397C80 */
extern u8 D_001D5EDD;
void func_00397C80(void) {
    D_001D5EDD = 0;
}
/* localdecomp:end func_00397C80 */

/* localdecomp:start func_00397C88 */
extern s32 D_001D5EE0;
void func_00397C88(void) {
    D_001D5EE0 = 0;
}
/* localdecomp:end func_00397C88 */

/* localdecomp:start func_00397C90 */
extern s32 D_001D5EE0;
void func_00397C90(void) {
    if (D_001D5EE0 == 0) D_001D5EE0 = 1;
}
/* localdecomp:end func_00397C90 */

/* localdecomp:start func_00397CA8 */
extern s32 D_001D5EE0;
s32 func_00397CA8(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00397CA8 */

LINKER_REMNANT("asm/remnants", func_00397CB8);

/* localdecomp:start func_00397CC0 */
extern void func_0038A238(s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_003A5430(void);
extern void func_003A2558(void);
extern void func_003A1C28(void);
extern void func_12EF10(void);
extern void func_121B38(void);
extern void func_124ED8(s32, s32, s32);
void func_00397CC0(s32 a, s32 b, s32 c) {
    func_0038A238(5);
    func_13CA28();
    func_13B620();
    func_003A5430();
    func_003A2558();
    func_003A1C28();
    func_12EF10();
    func_121B38();
    func_124ED8(a, b, c);
}
/* localdecomp:end func_00397CC0 */
