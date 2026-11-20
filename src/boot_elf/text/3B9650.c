#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B9B68(void);
extern s32 func_003B9A88(void);
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern void func_003B9C48(void);
extern void func_003B9C58();
/* --- end of declarations from other files --- */

/* declarations of 3B8DF0.c's earlier functions */
extern void func_003A5748(s32, s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 func_003823D0();
extern s32 func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern void func_00382490(void);
extern void func_003AF7C0(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);

extern f32 D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC, D_001D8BB0, D_001D8BB4;
extern f32 D_001D8B60[2];
extern f32 D_001D8B64[];
extern f32 D_001D8B68[];
extern f32 D_001D8B6C[];
extern void func_003BB348(s32, void *, void *);
extern s32 func_003B5418(s32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8F50(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E8700(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B9650);

/* localdecomp:start func_003B9A80 */
extern s32 D_001D8BC0;
void func_003B9A80(void) {
    D_001D8BC0 = 0;
}
/* localdecomp:end func_003B9A80 */

/* localdecomp:start func_003B9A88 */
extern s32 D_001D8BC0;
s32 func_003B9A88(void) {
    return D_001D8BC0;
}
/* localdecomp:end func_003B9A88 */

/* localdecomp:start func_003B9A90 */
extern s32 D_001D8BD4;
extern s32 D_001D8BD8;
void func_003B9A90(s32 a0, s32 a1) {
    D_001D8BD4 = 0x40;
    D_001D8BD8 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D8BD4 = a0;
    }
    D_001D8BD8 = a1;
}
/* localdecomp:end func_003B9A90 */

/* localdecomp:start func_003B9AB8 */
extern void func_003B9A80(void);
extern void func_003B9A90(s32, s32);
extern void func_003B9B58(s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
s32 func_003B9AB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D8BBC != 1) {
        return 0;
    }
        D_001D8BBC = 0;
        func_003B9A80();
        D_001D8BB8 = arg0;
        D_001D8BC4 = arg1;
        D_001D8BC8 = arg2;
        D_001D8BCC = arg3;
        D_001D8BD0 = arg4;
        func_003B9B58(0x60, 0x1A0);
        func_003B9A90(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_003B9AB8 */

extern s32 D_001D8BDC;
extern s32 D_001D8BE0;

/* localdecomp:start func_003B9B58 */
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
void func_003B9B58(s32 a, s32 b) { D_001D8BDC = a; D_001D8BE0 = b; }
/* localdecomp:end func_003B9B58 */

/* localdecomp:start func_003B9B68 */
extern void func_00382490(void);
extern void func_003A5748(s32, s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B9B68[];
extern s32 D_001D8BD4;
extern s32 D_001D8BC0;
extern s32 D_001D8BD8;
s32 func_003B9B68(void) {
    s32 t;
    s32 m;
    if (D_001D8BBC == 1) {
        return 0;
    }
    func_00382490();
    t = D_001D8BB8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D8BD4) {
            D_001D8BC0 = 1;
            D_001D8BBC = 1;
            func_003A5748(4, 0, 0);
        } else if (m & D_001D8BD8) {
            D_001D8BBC = 1;
            D_001D8BC0 = 2;
            func_003A5748(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B9B68[0] + 0x1C4) & D_001D8BD4) {
            D_001D8BC0 = t;
            func_003A5748(0x12, 0, 0);
            D_001D8BBC = t;
        }
        break;
    }
    return 1;
}
/* localdecomp:end func_003B9B68 */

/* localdecomp:start func_003B9C48 */
extern s32 D_001D8BC0;
extern s32 D_001D8BBC;
void func_003B9C48(void) {
    D_001D8BC0 = 0;
    D_001D8BBC = 1;
}
/* localdecomp:end func_003B9C48 */

extern void func_0038E530(s32);
extern s32 func_003823D0(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003AF7C0(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
extern f32 D_001DA074;
extern s32 D_001DA070;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B9C58);
