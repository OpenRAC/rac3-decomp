#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A88B8();


/* localdecomp:start func_003A87D8 */
extern s32 D_001D8000;
extern s32 D_001D8004;
extern s32 D_001D8008;
extern s32 D_001D800C;
extern s32 D_001D8010;
extern void func_0038CBC8(s32, s32);
void func_003A87D8(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001D8008 = c;
    D_001D800C = d;
    D_001D8000 = a;
    D_001D8004 = b;
    D_001D8010 = 0;
    func_0038CBC8(a, b);
    func_0038CBC8(D_001D8008, D_001D800C);
}
/* localdecomp:end func_003A87D8 */

/* localdecomp:start func_003A8830 */
extern u32 D_001D8010_003A8830;
extern u32 D_001D8004_003A8830;
extern s32 D_001D8000;
extern s32 D_001D8008;
u32 func_003A8830(s32 arg0, u32 arg1) {
    s32 temp_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_6;
    u32 var_2;
    u32 var_3;
    temp_2 = D_001D8010_003A8830;
    temp_6 = D_001D8004_003A8830;
    temp_4 = (arg0 + 0x3F) & 0xFFFFFFC0;
    if (temp_2 < temp_6) {
        if (temp_6 < (u32) (temp_2 + temp_4)) {
            D_001D8010_003A8830 = temp_6;
        }
        temp_2_2 = D_001D8010_003A8830;
        if (temp_2_2 < temp_6) {
            goto A;
        }
    }
    var_2 = (D_001D8010_003A8830 - D_001D8004_003A8830) + D_001D8008;
    goto done;
A:
    var_2 = temp_2_2 + D_001D8000;
done:
    var_3 = var_2 % arg1;
    if (var_3 != 0) {
        var_3 = arg1 - var_3;
        var_2 += var_3;
    }
    D_001D8010_003A8830 = (u32) (D_001D8010_003A8830 + (temp_4 + var_3));
    return var_2;
}
/* localdecomp:end func_003A8830 */

/* localdecomp:start func_003A88B8 */
extern s32 func_003A8770(s32);
extern s32 D_001DA034;
extern u8 D_00142BA0[];
extern s32 D_00227400[];
extern u8 D_00143A07[];
extern u8 D_00160C40_003A88B8[];
extern void func_00392BB8(s32 *);
extern void func_003A8980(s32, s32, s32, s32, s32);
void func_003A88B8(s32 arg) {
    u32 *p;
    s32 idx;
    s32 v;
    s32 d;
    s32 x;
    s32 arr;
    u8 *q;
    s32 f;
    if (arg < 0) {
        D_001DA034 = 0;
        return;
    }
    idx = func_003A8770(arg);
    p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
    *p |= 1 << (arg & 0x1F);
    func_00392BB8(D_00227400);
    q = D_00160C40_003A88B8;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    v = *(s32 *)(x + arr);
    d = D_00143A07[0];
    if (D_00227400[0]) d = 0;
    f = idx == 0x1F;
    func_003A8980(v + *(s32 *)(q + 4), *(s32 *)(D_00160C40_003A88B8 + x + 0xC), (idx << 4) + arr, d, f);
}
/* localdecomp:end func_003A88B8 */
