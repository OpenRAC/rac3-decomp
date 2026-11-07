#include "common.h"

/* localdecomp:start func_L03_0032DB58 */
typedef struct S_0032DB58 {
    char pad0[0x1A];
    short h;
    unsigned char b1C;
    unsigned char b1D;
} S_0032DB58;
void *func_L03_0032F6A8();
extern int D_001DCF28_sda[2];
__asm__(".extern D_001DCF28_sda, 8");

int func_L03_0032DB58(void) {
    S_0032DB58 *s = func_L03_0032F6A8();
    int v = D_001DCF28_sda[s->b1D];
    if (v == -1) return 1;
    if ((unsigned)(s->b1C - 2) < 2) return 1;
    if (s->h != -1) return s->h < v;
    return 0;
}
/* localdecomp:end func_L03_0032DB58 */

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

INCLUDE_ASM("asm/levels", func_L03_0032EB30);

INCLUDE_ASM("asm/levels", func_L03_0032EBF0);

INCLUDE_ASM("asm/levels", func_L03_0032EC38);
