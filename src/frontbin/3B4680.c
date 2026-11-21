#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0760(u8 *, u32);

/* localdecomp:start func_003B4680 */
s32 func_003B4680(void) {
    return 1;
}
/* localdecomp:end func_003B4680 */

/* localdecomp:start func_003B4688 */
s32 func_003B4688(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_003A0760((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
/* localdecomp:end func_003B4688 */

/* localdecomp:start func_003B46D8 */
s32 func_003B46D8(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003B46D8 */

/* localdecomp:start func_003B46F8 */
s32 func_003B46F8(void) {
    return 1;
}
/* localdecomp:end func_003B46F8 */

/* localdecomp:start func_003B4700 */
s32 func_003B4700(void) {
    return 2;
}
/* localdecomp:end func_003B4700 */

/* localdecomp:start func_003B4708 */
s32 func_003B4708(void) {
    return 0;
}
/* localdecomp:end func_003B4708 */

/* localdecomp:start func_003B4710 */
s32 func_003B4710(void) {
    return 1;
}
/* localdecomp:end func_003B4710 */

LINKER_REMNANT("asm/remnants", func_003B4718);

/* localdecomp:start func_003B4720 */
s32 func_003B4720(void) {
    return 0;
}
/* localdecomp:end func_003B4720 */

/* localdecomp:start func_003B4728 */
s32 func_003B4728(void) {
    return 1;
}
/* localdecomp:end func_003B4728 */

/* localdecomp:start func_003B4730 */
s32 func_003B4730(void) {
    return 0;
}
/* localdecomp:end func_003B4730 */

/* localdecomp:start func_003B4738 */
s32 func_003B4738(void) {
    return 0;
}
/* localdecomp:end func_003B4738 */

/* localdecomp:start func_003B4740 */
s32 func_003B4740(void) {
    return 0;
}
/* localdecomp:end func_003B4740 */

/* localdecomp:start func_003B4748 */
s32 func_003B4748(void) {
    return 1;
}
/* localdecomp:end func_003B4748 */

/* localdecomp:start func_003B4750 */
extern void func_00397D48(s32, s32);
 
void func_003B4750(void) {
    func_00397D48(0, 0);
}
/* localdecomp:end func_003B4750 */

/* localdecomp:start func_003B4770 */
extern void func_003BB7B0(s32);
extern void func_003B3228(void *);
extern void func_003B6508(s32);
extern s32 func_003B7F80(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern void func_003E6FF8(void *p);
extern u8 D_00240AF0[];
void func_003B4770(void) {
    func_003BB7B0(1);
    func_003B3228(D_00240AF0);
    func_003B6508(2);
    func_003E83C8(func_003B7F80());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B4770 */

/* localdecomp:start func_003B47C0 */
extern void func_003BB7B0(s32);
extern void func_003B6508(s32);
extern s32 func_003B7F80(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern void func_003E6FF8(void *p);
void func_003B47C0(void) {
    func_003B6508(1);
    func_003BB7B0(1);
    func_003E83C8(func_003B7F80());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B47C0 */

/* localdecomp:start func_003B4808 */
extern s32 func_003B51C8(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();   /* no prototype: func_003B5028 passes an arg */
extern void func_003E6FF8(void *p);
 
void func_003B4808(void) {
    func_003E83C8(func_003B51C8());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B4808 */

/* localdecomp:start func_003B4840 */
extern u8 D_00227400[];
extern s32 func_00392B20();
extern s32 func_00392C78(void *);
void func_003B4840(void) {
    func_00392B20(D_00227400, 0x2B);
    func_00392C78(D_00227400);
}
/* localdecomp:end func_003B4840 */
