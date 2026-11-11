#include "common.h"

typedef struct {
    u8 f[28];
} V7;

INCLUDE_ASM("asm/levels", func_L24_003CB5A8);

INCLUDE_ASM("asm/levels", func_L24_003CB7C0);

INCLUDE_ASM("asm/levels", func_L24_003CB900);

/* localdecomp:start func_L24_003CB990 */
extern s32 D_L24_002A2D50[];
extern s32 D_L24_002A2E50[];
extern u8 D_L24_001E1BB0[8];

void func_L24_003CB990(u8 *a0, s32 a1, s32 a2, s32 a3) {
    s32 *t = *(s32 **)(a0 + 0x68);
    s32 i;
    for (i = 0; i < 0x40; i++) {
        if (D_L24_002A2D50[i] == 0) {
            D_L24_002A2D50[i] = a1;
            D_L24_002A2E50[i] = a2;
            D_L24_001E1BB0[i] = a3;
            t[1]++;
            break;
        }
    }
}
/* localdecomp:end func_L24_003CB990 */

/* localdecomp:start func_L24_003CBA10 */
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00421738(s32, s32, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L03_00400000(s32, s32, long, s32, s32);
extern void func_11B2E8();
extern s32 func_129A18(f32);

__asm__(".extern D_L24_001DEAD8, 4");
__asm__(".extern D_L24_001DEAE8, 4");
__asm__(".extern D_L24_001DEAEC, 4");
__asm__(".extern D_L24_001DEAF0, 4");
__asm__(".extern D_L24_001DEAF4, 4");
__asm__(".extern D_L24_001DEB04, 4");
extern s32 D_L24_001DEAD8;
extern s32 D_L24_001DEAE8;
extern s32 D_L24_001DEAEC;
extern s32 D_L24_001DEAF0;
extern s32 D_L24_001DEAF4;
extern s32 D_L24_001DEB04;
extern s32 D_L24_001DEADC;
extern s32 D_L24_001DEAE0;
extern s32 D_L24_001DEAFC;
extern char D_L24_001DEB08[];
extern char D_L24_001DEB10[];
extern char D_L24_001DEB18[];
extern char D_L24_001DEB20[];
extern char D_L24_001DEB28[];
extern u8 D_L24_001E1BB0[];
extern void *D_L24_002A2D50[];
extern s32 D_L24_002A2E50[];

void func_L24_003CBA10(char *obj) {
    char text[256];
    int *st;
    int i, count;
    st = *(int **)(obj + 0x68);
    count = 0;
    func_003A9440(0x42, 0x8000000044UL);
    func_L01_00421738(D_L24_001DEAD8, D_L24_001DEADC, D_L24_001DEAE0, D_L24_001DEADC + D_L24_001DEAE8 * (st[1] < 17 ? st[1] : 16), D_L24_001DEB04, 0);
    func_L03_00400000(D_L24_001DEAEC, 8, D_L24_001DEAFC, func_00381FF0(0x10AA), -1);
    for (i = 0; i < 0x40 - st[2] && count < st[1] && count < 16; i++) {
        if (D_L24_002A2D50[i + st[2]]) {
            count++;
            if (D_L24_002A2E50[i]) {
                func_11B2E8(text, D_L24_001DEB08, D_L24_002A2E50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAF0, D_L24_001DEAF4 + i * D_L24_001DEAE8, D_L24_001DEAFC, (s32)text, -1);
            }
            if (st[0] == i + st[2]) {
                func_11B2E8(text, D_L24_001DEB10);
                func_L03_00400000(D_L24_001DEAF0 - 16, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008000UL, (s32)text, -1);
            }
            switch (D_L24_001E1BB0[i + st[2]]) {
            case 0:
                func_11B2E8(text, D_L24_001DEB18, *(int *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 1:
                func_11B2E8(text, D_L24_001DEB20, func_129A18(*(f32 *)D_L24_002A2D50[i + st[2]]));
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 2:
                func_11B2E8(text, D_L24_001DEB18, *(u8 *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 3:
                func_11B2E8(text, D_L24_001DEB18, *(s16 *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 5: {
                u32 *p = (u32 *)D_L24_002A2D50[i + st[2]];
                func_11B2E8(text, D_L24_001DEB28, *p >> 16, ((u8 *)p)[1], *p & 0xFF);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            }
            case 4:
            default:
                break;
            }
        } else if (D_L24_002A2E50[i]) {
            count++;
            func_11B2E8(text, D_L24_001DEB08, D_L24_002A2E50[i + st[2]]);
            func_L03_00400000(D_L24_001DEAF0, D_L24_001DEAF4 + i * D_L24_001DEAE8, D_L24_001DEAFC, (s32)text, -1);
        }
    }
}
/* localdecomp:end func_L24_003CBA10 */

/* localdecomp:start func_L24_003CBDC8 */
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(s32);
extern f32 func_0038CF00(void *, void *);
extern f32 D_1A4C60[];

void func_L24_003CBDC8(u8 *a0) {
    s32 *q = *(s32 **)(a0 + 0x68);
    s32 *g;

    if (a0[0x20] == 0) {
        if (func_L01_00456250(a0) > 0) {
            func_003C2880((s32)a0);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
    } else {
        if (func_L01_00456250(a0) > 0) {
            func_0038CF00(a0 + 0x10, D_1A4C60);
            g = (s32 *)0x140000;
            g[0x998] = g[0x998] + *q;
            func_003C2880((s32)a0);
        }
    }
}
/* localdecomp:end func_L24_003CBDC8 */

INCLUDE_ASM("asm/levels", func_L24_003CBE68);

/* localdecomp:start func_L24_003CC248 */
extern u8 D_L24_001DEB58[];
extern s32 D_001DEB40_sda[2];
__asm__(".extern D_001DEB40_sda, 8");
extern s32 func_00381FF0(s32);
extern void func_003AF408(void *, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_003CC248(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    V7 buf;
    s32 v;
    buf = *(V7 *)D_L24_001DEB58;
    v = func_00381FF0(D_001DEB40_sda[*(s32 *)st]);
    func_003AF408(&buf, 0x80F0F0F0, v, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_003CC248 */
