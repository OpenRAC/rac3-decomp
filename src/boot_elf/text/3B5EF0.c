#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003B46B0(s32);
extern void *func_003B46B0();
extern void func_003B5EF0();
extern void func_003B6090(void);
extern void func_003B5F78(s32, s32);
extern void func_003B5F48(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B5EF0 */

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern S_3B0580 D_00160C40[];
extern void *D_001D89D0;
extern void *D_001D89D4;
extern void *func_003B5400(s32);
void func_003B5EF0(void) {
    D_001D89D0 = func_003B5400(0);
    D_001D89D4 = func_003B5400(2);
    func_003B48E0(func_003B46B0(0), (s32)D_001D89D0, (s32)D_001D89D4, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_003B5EF0 */

/* localdecomp:start func_003B5F48 */
extern void *func_003B46B0(s32);
 
void func_003B5F48(void) {
    void *o = func_003B46B0(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B5F48 */

/* localdecomp:start func_003B5F78 */
extern u8 D_0037F830_003B5F78[];
extern u8 D_0037F690_003B5F78[];
extern s32 D_001D89B8_003B5F78;
extern s32 D_001D89E4_003B5F78;
extern void func_003A5748();
extern s32 func_003823D0();
extern void func_0011B2E8();
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern s32 func_003E8780();
extern void *func_003B5388();
extern s32 func_003B5580(void);
extern void func_003E73B0(void *p);
__asm__(".extern D_001D89B8_003B5F78, 4");
__asm__(".extern D_001D89E4_003B5F78, 4");
void func_003B5F78(s32 a0, s32 a1) {
    s32 t;
    s32 u;
    u8 *g;
    if (a1 & 0x40) {
        func_003A5748(4, 0, 0);
        g = D_0037F830_003B5F78;
        t = D_001D89B8_003B5F78 * 16;
        if (((s32 *)(D_0037F830_003B5F78 + t))[2] != 0) {
            ((void (*)(s32, u8 *))((s32 *)(g + t))[2])(t, g);
        }
    } else if (a1 & 8) {
        func_0011B2E8(D_0037F690_003B5F78, func_003823D0(0xB3B));
 u = func_003823D0(0x8DE);
 func_003B9AB8(1, u, func_003823D0(0x8DF), D_0037F690_003B5F78, 0);
        func_003B9A90(0x40, 0x10);
        D_001D89E4_003B5F78 = 5;
    }
    if (a1 & 0x10) {
        func_003A5748(4, 0, 0);
        func_003E8780(func_003B5388());
        func_003E73B0((void *)func_003B5580());
    }
}
/* localdecomp:end func_003B5F78 */

/* localdecomp:start func_003B6090 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037F830[];
extern s32 D_001D89B8;
extern s32 D_001D89BC;
extern s32 D_001D8A00;
extern s32 *func_003B9F88(s32);
extern s32 func_003BA010(s32 *);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
void func_003B6090(void) {
    s32 v = func_003BA010(func_003B9F88(0));
    D_001D89B8 = v;
    if (v < 0) return;
    if (D_001D89BC != v) {
        if (D_001D89BC >= 0) D_001D8A00 = 30;
        else D_001D8A00 = 1;
    }
    if (D_001D8A00 != 0) {
        if (--D_001D8A00 == 0) {
            func_003E8200(0x1C0003, D_0037F830[D_001D89B8].d);
            func_003E7DD0(0x1C0003, 1);
        }
    }
    D_001D89BC = D_001D89B8;
}
/* localdecomp:end func_003B6090 */
