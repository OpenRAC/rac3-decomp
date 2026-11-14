#include "common.h"

/* localdecomp:start func_L39_004F4FD8 */
extern s32 D_L39_0046D814[];
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

s32 func_L39_004F4FD8(S_004F4FD8 *p) {
    s32 r;

    if (p == 0) goto fail;
    if (p->b != p) goto fail;
    r = 0;
    if (p->b->a == D_L39_0046D814) goto done;
fail:
    r = 0x204;
done:
    return r;
}
/* localdecomp:end func_L39_004F4FD8 */

/* localdecomp:start func_L39_004F5010 */
s32 func_L39_004F5010(void *p) {
    s32 r = 0;
    if (p != 0) {
        r = func_L39_004F4FD8((S_004F4FD8 *)p) != 0 ? 0x21B : 0;
    }
    return r;
}
/* localdecomp:end func_L39_004F5010 */

/* localdecomp:start func_L39_004F5040 */
s32 func_L39_004F5040(s32 *out) {
    *out = 0x10;
    return 0;
}
/* localdecomp:end func_L39_004F5040 */

INCLUDE_ASM("asm/levels", func_L39_004F5050);

INCLUDE_ASM("asm/levels", func_L39_004F5100);

INCLUDE_ASM("asm/levels", func_L39_004F5320);

INCLUDE_ASM("asm/levels", func_L39_004F5540);

INCLUDE_ASM("asm/levels", func_L39_004F5570);

/* localdecomp:start func_L39_004F5588 */
extern u8 D_L39_004F55A0[];

s32 func_L39_004F5588(u8 *p) {
    *(void **)(p + 8) = D_L39_004F55A0;
    return 0;
}
/* localdecomp:end func_L39_004F5588 */

INCLUDE_ASM("asm/levels", func_L39_004F55A0);

INCLUDE_ASM("asm/levels", func_L39_004F5630);

/* localdecomp:start func_L39_004F5670 */
s32 func_L39_004F5670(s32 *out) {
    *out = 0x80;
    return 0;
}
/* localdecomp:end func_L39_004F5670 */

/* localdecomp:start func_L39_004F5680 */
extern void func_L39_004F63B8(void);

s32 func_L39_004F5680(void) {
    func_L39_004F63B8();
    return 0;
}
/* localdecomp:end func_L39_004F5680 */

/* localdecomp:start func_L39_004F56A0 */
extern s32 *func_L39_004F66E8();
s32 func_L39_004F56A0(void) {
    func_L39_004F66E8();
    return 0;
}
/* localdecomp:end func_L39_004F56A0 */

/* localdecomp:start func_L39_004F56C0 */
s32 func_L39_004F56C0(void) {
    return 9;
}
/* localdecomp:end func_L39_004F56C0 */

/* localdecomp:start func_L39_004F56C8 */
s32 func_L39_004F56C8(s32 a0, s32 *a1) {
    *a1 = 8;
    return 0;
}
/* localdecomp:end func_L39_004F56C8 */

/* localdecomp:start func_L39_004F56D8 */
s32 func_L39_004F56D8(s32 *p) {
    *p = 0x80;
    return 0;
}
/* localdecomp:end func_L39_004F56D8 */

/* localdecomp:start func_L39_004F56E8 */
/* func_L39_004F6420 is the DES key-schedule setup (destination schedule, 8-byte key) */
extern void func_L39_004F6420(void *schedule, void *key);

s32 func_L39_004F56E8(void *schedule, void *key) {
    func_L39_004F6420(schedule, key);
    return 0;
}
/* localdecomp:end func_L39_004F56E8 */

/* localdecomp:start func_L39_004F5708 */
extern s32 *func_L39_004F66E8();
s32 func_L39_004F5708(void) {
    func_L39_004F66E8();
    return 0;
}
/* localdecomp:end func_L39_004F5708 */

/* localdecomp:start func_L39_004F5728 */
s32 func_L39_004F5728(void) {
    return 9;
}
/* localdecomp:end func_L39_004F5728 */

/* localdecomp:start func_L39_004F5730 */
s32 func_L39_004F5730(void *arg0, s32 *arg1) {
    *arg1 = 8;
    return 0;
}
/* localdecomp:end func_L39_004F5730 */

/* localdecomp:start func_L39_004F5740 */
s32 func_L39_004F5740(s32 *out) {
    *out = 0x180;
    return 0;
}
/* localdecomp:end func_L39_004F5740 */

INCLUDE_ASM("asm/levels", func_L39_004F5750);

/* localdecomp:start func_L39_004F57A0 */
extern s32 *func_L39_004F6A30();

s32 func_L39_004F57A0(void) {
    func_L39_004F6A30();
    return 0;
}
/* localdecomp:end func_L39_004F57A0 */

/* localdecomp:start func_L39_004F57C0 */
s32 func_L39_004F57C0(void) {
    return 9;
}
/* localdecomp:end func_L39_004F57C0 */

/* localdecomp:start func_L39_004F57C8 */
s32 func_L39_004F57C8(void *arg0, s32 *out) {
    *out = 8;
    return 0;
}
/* localdecomp:end func_L39_004F57C8 */

/* localdecomp:start func_L39_004F57D8 */
s32 func_L39_004F57D8(s32 *out) {
    *out = 0x180;
    return 0;
}
/* localdecomp:end func_L39_004F57D8 */

INCLUDE_ASM("asm/levels", func_L39_004F57E8);

/* localdecomp:start func_L39_004F5838 */
extern s32 *func_L39_004F6A30();
s32 func_L39_004F5838(void) {
    func_L39_004F6A30();
    return 0;
}
/* localdecomp:end func_L39_004F5838 */

/* localdecomp:start func_L39_004F5858 */
s32 func_L39_004F5858(void) {
    return 9;
}
/* localdecomp:end func_L39_004F5858 */

/* localdecomp:start func_L39_004F5860 */
s32 func_L39_004F5860(s32 a0, s32 *a1) {
    *a1 = 8;
    return 0;
}
/* localdecomp:end func_L39_004F5860 */

/* localdecomp:start func_L39_004F5870 */
s32 func_L39_004F5870(s32 *p) {
    *p = 8;
    return 0;
}
/* localdecomp:end func_L39_004F5870 */

INCLUDE_ASM("asm/levels", func_L39_004F5880);

INCLUDE_ASM("asm/levels", func_L39_004F58D0);

INCLUDE_ASM("asm/levels", func_L39_004F5A78);

/* localdecomp:start func_L39_004F5C20 */
s32 func_L39_004F5C20(void) {
    return 0;
}
/* localdecomp:end func_L39_004F5C20 */

INCLUDE_ASM("asm/levels", func_L39_004F5C28);

/* localdecomp:start func_L39_004F5C40 */
extern u8 D_L39_004F5C58[];

s32 func_L39_004F5C40(u8 *p) {
    *(void **)(p + 8) = D_L39_004F5C58;
    return 0;
}
/* localdecomp:end func_L39_004F5C40 */

INCLUDE_ASM("asm/levels", func_L39_004F5C58);

/* localdecomp:start func_L39_004F5CA8 */
s32 func_L39_004F5CA8(void) {
    return 9;
}
/* localdecomp:end func_L39_004F5CA8 */
