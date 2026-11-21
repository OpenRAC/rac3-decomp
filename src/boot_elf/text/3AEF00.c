#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AEF00(void *, s32);
extern void func_003AB2B8(void *, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AEF00 */

void func_003AEF00(void *arg0, s32 arg1) {
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_s5;

    (*(s32 *)((u8 *)(arg0) + 0xB38)) = arg1;
    if ((*(s32 *)((u8 *)(arg0) + 0xB3C)) != 0) {
        (*(s32 *)((u8 *)(arg0) + 0xB3C)) = 0;
        temp_s4 = arg0 + 0x7E8;
        func_003AB2B8(arg0 + 0x628, 0);
        temp_s5 = arg0 + 0x870;
        func_003AD948(temp_s4, 1);
        temp_s3 = arg0 + 0x8F8;
        func_003AD948(temp_s5, 1);
        temp_s2 = arg0 + 0x980;
        func_003AD948(temp_s3, 1);
        temp_s1 = arg0 + 0xA08;
        func_003AD948(temp_s2, 1);
        temp_s0 = arg0 + 0xA90;
        func_003AD948(temp_s1, 1);
        func_003AD948(temp_s0, 1);
        func_003AD8B8(temp_s4);
        func_003AD8B8(temp_s5);
        func_003AD8B8(temp_s3);
        func_003AD8B8(temp_s2);
        func_003AD8B8(temp_s1);
        func_003AD8B8(temp_s0);
    }
}
/* localdecomp:end func_003AEF00 */

/* Draft of func_003AEFF8 (from the US rac3-uya-decomp func_003AEE58), names moved to PAL
   addresses: the US symbol func_003829F8 is the PAL func_003829D8. */


/* localdecomp:start func_003AEFF8 */
typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_003829D8(s32, s32, s32, s32, s32, s32);
extern s32 *func_003AB270();
extern f32 *func_003AB748();
extern void func_003AB2B8();
void func_003AEFF8(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_003829D8(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_003AB270(p);
    *r = func_003829D8(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_003AB748(p);
    *q = f;
    func_003AB2B8(p, b);
}
/* localdecomp:end func_003AEFF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF0B8);
