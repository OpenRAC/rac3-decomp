#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003DEF28(void);
extern void func_003DEE20(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003DED18 */
extern u32 *D_001DA050;
extern u32 *D_001DA760_003DED18;
extern s32 D_001DA764;
extern s32 D_001D4BB0;
extern s32 func_003E0868(s32);
extern void func_003A9618(void);
void func_003DED18(void) {
    u32 *save = D_001DA050;
    s32 r;
    D_001DA050 += 4;
    D_001DA760_003DED18[0] = 0x20000000;
    D_001DA760_003DED18[1] = (u32)D_001DA050;
    D_001DA760_003DED18[2] = 0;
    D_001DA760_003DED18[3] = 0;
    r = func_003E0868(D_001D4BB0);
    func_003A9618();
    if (D_001DA764 < r) { D_001DA764 = r; }
    D_001DA050[0] = 0x20000000;
    D_001DA050[1] = (u32)(D_001DA760_003DED18 + 4);
    D_001DA050[2] = 0;
    D_001DA050[3] = 0;
    D_001DA050 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA050;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003DED18 */

typedef struct { s16 h0; s16 h2; } S_98T;
extern s32 D_003063C0_003DEE20[];
extern u8 *D_003059C0_003DEE20[];
extern S_98T D_00305EC0_003DEE20[];
/* localdecomp:start func_003DEE20 */
void func_003DEE20(void) {
    s32 *ip = D_003063C0_003DEE20;
    u8 *obj;
    u8 *sub;
    u8 *e;
    u8 *q; u8 *tab;
    s32 j, k, off;
    S_98T *t;
    while (*ip >= 0) {
        obj = D_003059C0_003DEE20[*ip];
        j = 0;
        if (*(s16 *)(obj + 0x28) > 0) {
            tab = obj + 0x40;
            do {
                off = j * 8;
                sub = *(u8 **)(tab + off);
                e = sub + 0x10;
                q = e + *(s32 *)(e + 4) * 16 + 0x10;
                for (k = 0; k < *(s32 *)e; k++, q += 0x40) {
                    t = &D_00305EC0_003DEE20[q[0x13]];
                    if (t->h0 != 0) *(u32 *)(q + 0x30) = (*(u32 *)(q + 0x30) & 0xFFFFC000) | t->h0;
                    if (t->h2 != 0) *(u32 *)(q + 0x20) = (*(u32 *)(q + 0x20) & 0xFFFFC000) | t->h2;
                }
                j++;
            } while (j < *(s16 *)(obj + 0x28));
        }
        ip++;
    }
}
/* localdecomp:end func_003DEE20 */

/* localdecomp:start func_003DEF28 */
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
void func_0038CD80(s32 *, s32, s32);
void func_003DEF90();
void func_11F0A0(s32);
extern s32 D_001DA050_003DEF28;
extern s32 D_001DA760;
extern u8 D_003064C0[];

void func_003DEF28(void) {
    s32 t = D_001DA050_003DEF28;
    D_001DA760 = t;
    t += 0x10;
    D_001D4BB0 = D_001D4BB4;
    D_001DA050_003DEF28 = t;
    func_11F0A0(0);
    func_003DEF90();
    func_0038CD80(D_003064C0, 0x3200, 0x40);
    func_003DED18();
}
/* localdecomp:end func_003DEF28 */
