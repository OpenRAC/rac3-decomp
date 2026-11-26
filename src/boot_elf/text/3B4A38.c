#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0B60(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0B60(u8 *, u32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B4A38 */
s32 func_003B4A38(void) {
    return 1;
}
/* localdecomp:end func_003B4A38 */

/* localdecomp:start func_003B4A40 */
s32 func_003B4A40(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_003A0B60((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
/* localdecomp:end func_003B4A40 */

/* localdecomp:start func_003B4A90 */
s32 func_003B4A90(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003B4A90 */

/* localdecomp:start func_003B4AB0 */
s32 func_003B4AB0(void) {
    return 1;
}
/* localdecomp:end func_003B4AB0 */

/* localdecomp:start func_003B4AB8 */
s32 func_003B4AB8(void) {
    return 2;
}
/* localdecomp:end func_003B4AB8 */

/* localdecomp:start func_003B4AC0 */
s32 func_003B4AC0(void) {
    return 0;
}
/* localdecomp:end func_003B4AC0 */

/* localdecomp:start func_003B4AC8 */
s32 func_003B4AC8(void) {
    return 1;
}
/* localdecomp:end func_003B4AC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B4AD0);

/* localdecomp:start func_003B4AD8 */
s32 func_003B4AD8(void) {
    return 0;
}
/* localdecomp:end func_003B4AD8 */

/* localdecomp:start func_003B4AE0 */
s32 func_003B4AE0(void) {
    return 1;
}
/* localdecomp:end func_003B4AE0 */

/* localdecomp:start func_003B4AE8 */
s32 func_003B4AE8(void) {
    return 0;
}
/* localdecomp:end func_003B4AE8 */

/* localdecomp:start func_003B4AF0 */
s32 func_003B4AF0(void) {
    return 0;
}
/* localdecomp:end func_003B4AF0 */

/* localdecomp:start func_003B4AF8 */
s32 func_003B4AF8(void) {
    return 0;
}
/* localdecomp:end func_003B4AF8 */

/* localdecomp:start func_003B4B00 */
s32 func_003B4B00(void) {
    return 1;
}
/* localdecomp:end func_003B4B00 */

/* localdecomp:start func_003B4B08 */
extern void func_00398128(s32, s32);
 
void func_003B4B08(void) {
    func_00398128(0, 0);
}
/* localdecomp:end func_003B4B08 */

/* localdecomp:start func_003B4B28 */
extern void func_003BBB68(s32);
extern void func_003B35E0(void *);
extern void func_003B68C0(s32);
extern s32 func_003B8338(void);
extern s32 func_003E8780();
extern void *func_003B5388();
extern void func_003E73B0(void *p);
extern u8 D_00240AF0[];
void func_003B4B28(void) {
    func_003BBB68(1);
    func_003B35E0(D_00240AF0);
    func_003B68C0(2);
    func_003E8780(func_003B8338());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4B28 */

/* localdecomp:start func_003B4B78 */
extern void func_003BBB68(s32);
extern void func_003B68C0(s32);
extern s32 func_003B8338(void);
extern s32 func_003E8780();
extern void *func_003B5388();
extern void func_003E73B0(void *p);
void func_003B4B78(void) {
    func_003B68C0(1);
    func_003BBB68(1);
    func_003E8780(func_003B8338());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4B78 */

/* localdecomp:start func_003B4BC0 */
extern s32 func_003B5580(void);
extern s32 func_003E8780();
extern void *func_003B5388();   /* no prototype: func_003B53E0 passes an arg */
extern void func_003E73B0(void *p);
 
void func_003B4BC0(void) {
    func_003E8780(func_003B5580());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4BC0 */

/* localdecomp:start func_003B4BF8 */
extern u8 D_00227400[];
extern s32 func_00392F00();
extern s32 func_00393058(void *);
void func_003B4BF8(void) {
    func_00392F00(D_00227400, 0x2B);
    func_00393058(D_00227400);
}
/* localdecomp:end func_003B4BF8 */
