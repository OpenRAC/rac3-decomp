#include "common.h"


/* localdecomp:start func_L04_0035A050 */
__asm__(".extern D_L04_001DD4E8, 4");
__asm__(".extern D_L04_001DD4EC, 4");
__asm__(".extern D_L04_001DD4F0, 4");
__asm__(".extern D_L04_001DD4F4, 4");
extern s32 D_001D545C;
extern f32 D_L04_001DD4E8;
extern s32 D_L04_001DD4EC;
extern f32 D_L04_001DD4F0;
extern s32 D_L04_001DD4F4;
extern s32 func_L01_0044C108(void *);
extern void func_L04_0035A158(void *, void *);
extern void func_L04_0035BC10(void *, void *);
extern void func_L04_0035C9C8(void);
extern void func_L01_00404A10_0035A050(void *, void *);
void func_L04_0035A050(u8 *o) {
    u8 *m = *(u8 **)(o + 0x68);
    if (D_001D545C == 11 && D_L04_001DD4E8 != 255.0f) {
        D_L04_001DD4E8 = 255.0f;
        D_L04_001DD4F0 = 255.0f;
        D_L04_001DD4EC = 255;
        D_L04_001DD4F4 = 255;
    } else if (D_001D545C == 19 && D_L04_001DD4E8 != 255.0f) {
        D_L04_001DD4E8 = 64.0f;
        D_L04_001DD4F0 = 64.0f;
        D_L04_001DD4EC = 64;
        D_L04_001DD4F4 = 64;
    }
    if (func_L01_0044C108(o + 0x10)) {
        if (o[0x20] == 0) func_L04_0035A158(o, m);
        if (o[0x20] == 1) {
            func_L04_0035BC10(o, m);
            func_L01_00404A10_0035A050(func_L04_0035C9C8, o);
        }
    }
}
/* localdecomp:end func_L04_0035A050 */

INCLUDE_ASM("asm/levels", func_L04_0035A158);

/* localdecomp:start func_L04_0035A4F8 */
__asm__(".extern D_L04_001DF940_0035A4F8, 4");
extern s32 D_L04_001DF940_0035A4F8;

void func_L04_0035A4F8(s32 *a, s32 *b) {
    if (a[8] == 1) {
        s32 t = D_L04_001DF940_0035A4F8;
        a[8] = 2;
        a[9] = t;
        b[0] = 0;
        b[2] = 0;
        b[3] = 0;
    }
}
/* localdecomp:end func_L04_0035A4F8 */

/* localdecomp:start func_L04_0035A528 */
extern s32 D_L04_001DF940;

void func_L04_0035A528(s32 *a, s32 *b) {
    if (a[8] != 1) {
        if (a[8] == 2) {
            a[9] = 0;
        } else {
            a[9] = D_L04_001DF940;
        }
        a[8] = 1;
    }
    b[1] = D_L04_001DF940;
}
/* localdecomp:end func_L04_0035A528 */

/* localdecomp:start func_L04_0035A568 */
extern u8 *D_L04_001DFD9C;
u8 *func_L04_0035A568(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a0 + 104);
    if ((*(s32 *)(p + 36) != -1 && a1 == D_L04_001DFD9C + (*(s32 *)(p + 36) << 8)) ||
        (*(s32 *)(p + 40) != -1 && a1 == D_L04_001DFD9C + (*(s32 *)(p + 40) << 8))) {
        return a1;
    }
    return 0;
}
/* localdecomp:end func_L04_0035A568 */

/* localdecomp:start func_L04_0035A5B8 */
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;
extern u8 D_L04_001E95A0[];
extern s32 func_003D3CB0(void *, Vec4 *, s32, s32, s32);
extern void func_L01_00446630(Vec4 *, void *, void *, void *);
extern float func_L01_0040E548(void *, Vec4 *);
s32 func_L04_0035A5B8(void *a, Vec4 *pos, void *b) {
    Vec4 tmp;
    if (func_003D3CB0(a, pos, 2, 0, 0)) {
        func_L01_00446630(&tmp, a, D_L04_001E95A0, b);
    } else {
        tmp = *pos;
    }
    if (func_L01_0040E548(b, &tmp) > 0.16000001f) return 0;
    return 1;
}
/* localdecomp:end func_L04_0035A5B8 */

/* localdecomp:start func_L04_0035A660 */
s32 func_L04_0035A660(u8 **arr, s32 *n, u8 *o) {
    if (*n >= 15) {
        return 0;
    }
    arr[*n] = o;
    (*n)++;
    *(s32 *)(o + 152) = 0;
    return 1;
}
/* localdecomp:end func_L04_0035A660 */

/* localdecomp:start func_L04_0035A6A0 */
void func_L04_0035A6A0(u8 **arr, s32 *n) {
    s32 i;
    for (i = 0; i < *n; i++) {
        u8 *o = arr[i];
        *(s32 *)(o + 152) = *(s32 *)(*(u8 **)(o + 36) + 16);
    }
    *n = 0;
}
/* localdecomp:end func_L04_0035A6A0 */
