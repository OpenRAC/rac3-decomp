#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003DF2E0(void);
extern void func_003DF1D8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003DF0D0 */
extern u32 *D_001DA050;
extern u32 *D_001DA760_003DF0D0;
extern s32 D_001DA764;
extern s32 D_001D4BB0;
extern s32 func_003E0C20(s32);
extern void func_003A99D0(void);
void func_003DF0D0(void) {
    u32 *save = D_001DA050;
    s32 r;
    D_001DA050 += 4;
    D_001DA760_003DF0D0[0] = 0x20000000;
    D_001DA760_003DF0D0[1] = (u32)D_001DA050;
    D_001DA760_003DF0D0[2] = 0;
    D_001DA760_003DF0D0[3] = 0;
    r = func_003E0C20(D_001D4BB0);
    func_003A99D0();
    if (D_001DA764 < r) { D_001DA764 = r; }
    D_001DA050[0] = 0x20000000;
    D_001DA050[1] = (u32)(D_001DA760_003DF0D0 + 4);
    D_001DA050[2] = 0;
    D_001DA050[3] = 0;
    D_001DA050 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA050;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003DF0D0 */

typedef struct { s16 h0; s16 h2; } S_98T;
extern s32 D_003063C0_003DF1D8[];
extern u8 *D_003059C0_003DF1D8[];
extern S_98T D_00305EC0_003DF1D8[];
/* localdecomp:start func_003DF1D8 */
void func_003DF1D8(void) {
    s32 *ip = D_003063C0_003DF1D8;
    u8 *obj;
    u8 *sub;
    u8 *e;
    u8 *q; u8 *tab;
    s32 j, k, off;
    S_98T *t;
    while (*ip >= 0) {
        obj = D_003059C0_003DF1D8[*ip];
        j = 0;
        if (*(s16 *)(obj + 0x28) > 0) {
            tab = obj + 0x40;
            do {
                off = j * 8;
                sub = *(u8 **)(tab + off);
                e = sub + 0x10;
                q = e + *(s32 *)(e + 4) * 16 + 0x10;
                for (k = 0; k < *(s32 *)e; k++, q += 0x40) {
                    t = &D_00305EC0_003DF1D8[q[0x13]];
                    if (t->h0 != 0) *(u32 *)(q + 0x30) = (*(u32 *)(q + 0x30) & 0xFFFFC000) | t->h0;
                    if (t->h2 != 0) *(u32 *)(q + 0x20) = (*(u32 *)(q + 0x20) & 0xFFFFC000) | t->h2;
                }
                j++;
            } while (j < *(s16 *)(obj + 0x28));
        }
        ip++;
    }
}
/* localdecomp:end func_003DF1D8 */

/* localdecomp:start func_003DF2E0 */
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
void func_0038D160(s32 *, s32, s32);
void func_003DF348();
void func_11F0A0(s32);
extern s32 D_001DA050_003DF2E0;
extern s32 D_001DA760;
extern u8 D_003064C0[];

void func_003DF2E0(void) {
    s32 t = D_001DA050_003DF2E0;
    D_001DA760 = t;
    t += 0x10;
    D_001D4BB0 = D_001D4BB4;
    D_001DA050_003DF2E0 = t;
    func_11F0A0(0);
    func_003DF348();
    func_0038D160(D_003064C0, 0x3200, 0x40);
    func_003DF0D0();
}
/* localdecomp:end func_003DF2E0 */
