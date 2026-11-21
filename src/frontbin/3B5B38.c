#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_00381FF0();
typedef struct { s32 type; s8 pad4[8]; s32 fC; s32 f10; s32 f14; s32 f18; } S_3AEF70;
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern void func_003E6FF8(void *p);
extern s32 func_003B51C8(void);
extern void func_003A5348();
extern s32 D_001D89BC;
extern void func_003B5B38();
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B5CD8(void);
extern void func_003B5BC0(s32, s32);
extern s32 *func_003B9BD0(s32);
extern void func_003B5B90(void);
extern void *func_003B42F8(s32 arg0);
extern s32 func_003B4528(S_3AEF70 *a, s32 b, s32 c, s32 d, s32 e);
extern void *func_003B4FD0();
extern void *func_003B5048(s32 i);
extern s32 func_003B51C8(void);

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern S_3B0580 D_00160C40[];
extern void *D_001D89D0;
extern void *D_001D89D4;
/* localdecomp:start func_003B5B38 */
extern void *func_003B5048(s32);
void func_003B5B38(void) {
    D_001D89D0 = func_003B5048(0);
    D_001D89D4 = func_003B5048(2);
    func_003B4528(func_003B42F8(0), (s32)D_001D89D0, (s32)D_001D89D4, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_003B5B38 */

/* localdecomp:start func_003B5B90 */
extern void *func_003B42F8(s32);
 
void func_003B5B90(void) {
    void *o = func_003B42F8(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B5B90 */

/* localdecomp:start func_003B5BC0 */
extern u8 D_0037F830_003B5BC0[];
extern u8 D_0037F690_003B5BC0[];
extern s32 D_001D89B8_003B5BC0;
extern s32 D_001D89E4_003B5BC0;
extern void func_003A5348();
extern s32 func_00381FF0();
extern void func_0011B2E8();
extern s32 func_003B9700();
extern void func_003B96D8();
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern s32 func_003B51C8(void);
extern void func_003E6FF8(void *p);
__asm__(".extern D_001D89B8_003B5BC0, 4");
__asm__(".extern D_001D89E4_003B5BC0, 4");
void func_003B5BC0(s32 a0, s32 a1) {
    s32 t;
    s32 u;
    u8 *g;
    if (a1 & 0x40) {
        func_003A5348(4, 0, 0);
        g = D_0037F830_003B5BC0;
        t = D_001D89B8_003B5BC0 * 16;
        if (((s32 *)(D_0037F830_003B5BC0 + t))[2] != 0) {
            ((void (*)(s32, u8 *))((s32 *)(g + t))[2])(t, g);
        }
    } else if (a1 & 8) {
        func_0011B2E8(D_0037F690_003B5BC0, func_00381FF0(0xB3B));
 u = func_00381FF0(0x8DE);
 func_003B9700(1, u, func_00381FF0(0x8DF), D_0037F690_003B5BC0, 0);
        func_003B96D8(0x40, 0x10);
        D_001D89E4_003B5BC0 = 5;
    }
    if (a1 & 0x10) {
        func_003A5348(4, 0, 0);
        func_003E83C8(func_003B4FD0());
        func_003E6FF8((void *)func_003B51C8());
    }
}
/* localdecomp:end func_003B5BC0 */

/* localdecomp:start func_003B5CD8 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037F830[];
extern s32 D_001D89B8;
extern s32 D_001D89BC;
extern s32 D_001D8A00;
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E7A18(s32 arg0, s32 arg1);
void func_003B5CD8(void) {
    s32 v = func_003B9C58(func_003B9BD0(0));
    D_001D89B8 = v;
    if (v < 0) return;
    if (D_001D89BC != v) {
        if (D_001D89BC >= 0) D_001D8A00 = 30;
        else D_001D8A00 = 1;
    }
    if (D_001D8A00 != 0) {
        if (--D_001D8A00 == 0) {
            func_003E7E48(0x1C0003, D_0037F830[D_001D89B8].d);
            func_003E7A18(0x1C0003, 1);
        }
    }
    D_001D89BC = D_001D89B8;
}
/* localdecomp:end func_003B5CD8 */
