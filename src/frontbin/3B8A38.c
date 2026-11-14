#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B96D8();
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B9890(void);
extern void func_003B98A0();
extern void func_003B8A38(s32);
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);


INCLUDE_ASM("asm/nonmatchings/text", func_003B8A38);

extern f32 D_001D8BA0, D_001D8BA4, D_001D8BA8, D_001D8BAC, D_001D8BB0, D_001D8BB4;
extern f32 D_001D8B60[2];
extern f32 D_001D8B64[];
extern f32 D_001D8B68[];
extern f32 D_001D8B6C[];
extern void func_003BAF90(s32, void *, void *);
extern s32 func_003B5060(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8348(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B9298);

/* localdecomp:start func_003B96C8 */
extern s32 D_001D8BC0;
void func_003B96C8(void) {
    D_001D8BC0 = 0;
}
/* localdecomp:end func_003B96C8 */

/* localdecomp:start func_003B96D0 */
extern s32 D_001D8BC0;
s32 func_003B96D0(void) {
    return D_001D8BC0;
}
/* localdecomp:end func_003B96D0 */

/* localdecomp:start func_003B96D8 */
extern s32 D_001D8BD4;
extern s32 D_001D8BD8;
void func_003B96D8(s32 a0, s32 a1) {
    D_001D8BD4 = 0x40;
    D_001D8BD8 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D8BD4 = a0;
    }
    D_001D8BD8 = a1;
}
/* localdecomp:end func_003B96D8 */

/* localdecomp:start func_003B9700 */
extern void func_003B96C8(void);
extern void func_003B96D8(s32, s32);
extern void func_003B97A0(s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
s32 func_003B9700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D8BBC != 1) {
        return 0;
    }
        D_001D8BBC = 0;
        func_003B96C8();
        D_001D8BB8 = arg0;
        D_001D8BC4 = arg1;
        D_001D8BC8 = arg2;
        D_001D8BCC = arg3;
        D_001D8BD0 = arg4;
        func_003B97A0(0x60, 0x1A0);
        func_003B96D8(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_003B9700 */

extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
/* localdecomp:start func_003B97A0 */
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
void func_003B97A0(s32 a, s32 b) { D_001D8BDC = a; D_001D8BE0 = b; }
/* localdecomp:end func_003B97A0 */

/* localdecomp:start func_003B97B0 */
extern void func_003820B0(void);
extern void func_003A5348(s32, s32, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B97B0[];
extern s32 D_001D8BD4;
extern s32 D_001D8BC0;
extern s32 D_001D8BD8;
s32 func_003B97B0(void) {
    s32 t;
    s32 m;
    if (D_001D8BBC == 1) {
        return 0;
    }
    func_003820B0();
    t = D_001D8BB8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D8BD4) {
            D_001D8BC0 = 1;
            D_001D8BBC = 1;
            func_003A5348(4, 0, 0);
        } else if (m & D_001D8BD8) {
            D_001D8BBC = 1;
            D_001D8BC0 = 2;
            func_003A5348(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B97B0[0] + 0x1C4) & D_001D8BD4) {
            D_001D8BC0 = t;
            func_003A5348(0x12, 0, 0);
            D_001D8BBC = t;
        }
        break;
    }
    return 1;
}
/* localdecomp:end func_003B97B0 */

/* localdecomp:start func_003B9890 */
extern s32 D_001D8BC0;
extern s32 D_001D8BBC;
void func_003B9890(void) {
    D_001D8BC0 = 0;
    D_001D8BBC = 1;
}
/* localdecomp:end func_003B9890 */

extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003AF408(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
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
INCLUDE_ASM("asm/nonmatchings/text", func_003B98A0);
