#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0032DB58);

/* localdecomp:start func_L03_0032DBC0 */
s32 func_L03_0032DBC0(void) {
    return 0x10001;
}
/* localdecomp:end func_L03_0032DBC0 */

/* localdecomp:start func_L03_0032DBD0 */
void *func_L03_0032F6A8();

s32 func_L03_0032DBD0(s32 arg0, s32 arg1) {
    return (((*(u8 *)((u8 *)(func_L03_0032F6A8()) + 0x1C)) ^ 3) == 0) ? arg1 : 0xA;
}
/* localdecomp:end func_L03_0032DBD0 */

INCLUDE_ASM("asm/levels", func_L03_0032DC08);

INCLUDE_ASM("asm/levels", func_L03_0032DDC8);

/* localdecomp:start func_L03_0032DF10 */
void *func_L03_0032F6A8();
void func_L01_004443E8(void *, s32, s32);
void func_L03_0032F6F8(s32, void *);

void func_L03_0032DF10(void *arg0) {
    void *p;

    p = func_L03_0032F6A8(arg0);
    if (p != 0) {
        func_L01_004443E8(arg0, 0, 3);
        func_L03_0032F6F8(*(s32 *)((u8 *)p + 0x8), arg0);
    }
}
/* localdecomp:end func_L03_0032DF10 */

INCLUDE_ASM("asm/levels", func_L03_0032DF60);

INCLUDE_ASM("asm/levels", func_L03_0032E0D8);

INCLUDE_ASM("asm/levels", func_L03_0032E640);

/* localdecomp:start func_L03_0032E6F0 */
extern u8 D_L03_002AE4D0[];
extern s32 D_00142660[];
extern s32 func_L03_0032E7A0(void *a0, s32 a1);
extern s32 func_L03_0032F948(s32 a0);
extern void func_L03_0032FA18(s32 a0);
extern void func_0039EC28(s32 a0, s32 a1);

s32 func_L03_0032E6F0(void *arg0, s32 arg1) {
    s32 r;
    s32 r2;
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    r = func_L03_0032E7A0(arg0, D_L03_002AE4D0[arg1 * 0x28 + 0x10]);
    if (r != 0) {
        *(s32 *)(p + 0x108) = -1;
    } else {
        r2 = func_L03_0032F948(arg1);
        if (r2 != 0) {
            *(s32 *)(p + 0x108) = r2;
        } else {
            *(s32 *)(p + 0x108) = -2;
        }
        D_00142660[0] += r2;
    }
    func_L03_0032FA18(arg1);
    func_0039EC28(1, -1);
    return r;
}
/* localdecomp:end func_L03_0032E6F0 */

INCLUDE_ASM("asm/levels", func_L03_0032E7A0);

INCLUDE_ASM("asm/levels", func_L03_0032E7E8);

/* localdecomp:start func_L03_0032E8D8 */
void func_L03_0032E8D8(void *arg0, s32 arg1) {
    u8 temp_a1;
    u8 temp_v0;
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = arg1 & 0xFF;
    temp_v0 = *(u8 *)((u8 *)temp_v1 + 0xF6);
    *(u8 *)((u8 *)temp_v1 + 0xF6) = temp_a1;
    *(s8 *)((u8 *)temp_v1 + 0xF7) = (s8) (temp_a1 & ~temp_v0 & 0x1F);
}
/* localdecomp:end func_L03_0032E8D8 */

INCLUDE_ASM("asm/levels", func_L03_0032E900);

/* localdecomp:start func_L03_0032EB30 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern void func_L02_003A02D8(u8 *a0, s32 a1);

void func_L03_0032EB30(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    p = D_L03_0021C620[*(s32 *)(s + 0xC0)];
    while ((*(s32 *)(s + 0xC0) & 0xFF) != 0xFF && *(s32 *)(s + 0xC0) <= D_L03_001DF9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L03_0021C620[*(s32 *)(s + 0xC0)])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        func_L02_003A02D8(e, 0);
        p++;
    }
}
/* localdecomp:end func_L03_0032EB30 */

/* localdecomp:start func_L03_0032EBF0 */
__asm__(".extern D_001D7C20, 4");
extern int D_001D7C20;
extern void func_L03_0032EC38(int);
extern void func_L03_0032ED88(int);
extern void func_L03_0032EDE0(int);
extern void func_L03_0032EF78(int);

void func_L03_0032EBF0(int a0) {
    D_001D7C20 = -1;
    func_L03_0032EC38(a0);
    func_L03_0032ED88(a0);
    func_L03_0032EDE0(a0);
    func_L03_0032EF78(a0);
}
/* localdecomp:end func_L03_0032EBF0 */

INCLUDE_ASM("asm/levels", func_L03_0032EC38);
