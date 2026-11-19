#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void * func_003AF0B8();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AD270.c's earlier functions */
extern s32 *func_003AAEB8();
extern u8 *func_003AED10(u8 *p);

extern u8 *D_001D5C78_003AEE38;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
extern s32 func_003ABDD8();
extern void func_003AB4A0();
extern void func_003ABD18();
extern void func_003ABBE0();
extern void func_003ABBE8();
extern void func_003AB530();
extern void func_003AB548();
extern void func_003ABD30();
extern void func_003ABD10();
extern void func_003AD7D8();
extern void func_003ABFA8();
extern void func_003AB778();
extern f32 *func_003AB820();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
/* localdecomp:start func_003AEE38 */
void func_003AEE38(void *p0, void *p1, void *p2) {
    S_3A9890 *sx = (S_3A9890 *)p0;
    s32 a1 = (s32)p1;
    s32 a2 = (s32)p2;
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003ABDD8(D_001D5C78_003AEE38 + 0x7090, 0xC);
        sx->b[k] = func_003ABDD8(D_001D5C78_003AEE38 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003AB4A0(b, 0x16, 1, D_001D8730, a2);
                func_003ABD18(b, 5);
                func_003ABBE0(b, 0x64);
                func_003ABBE8(b, 0);
                func_003AB530(b, 0x706EC8FF, 0x706EC8FF);
                func_003AB548(b, 0x80808080, 0x80808080);
                func_003ABD30(b, 0x80000000);
                func_003ABD10(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003AD7D8(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003ABFA8(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003AB778(q, D_001D8740, a2);
    *(f32 *)func_003AAEB8(q) = 2155905024.0f;
    *func_003AB820(q) = 60008.0f;
    ((s32 *)func_003AB820(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003ABFA8(s + 0x4ED0, a2);
}
/* localdecomp:end func_003AEE38 */

LINKER_REMNANT("asm/remnants", func_003AF058);

/* localdecomp:start func_003AF068 */
extern void func_003ACBC0(void *);
 
void func_003AF068(void *p, s32 i) {
    func_003ACBC0((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF068 */

/* localdecomp:start func_003AF090 */
extern void func_003AD278(void *);
 
void func_003AF090(void *p, s32 i) {
    func_003AD278((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF090 */

extern void *func_003ABE28(void *);
extern void func_00121760(void *, void *);
extern s32 func_003A26F0();
extern void func_003ABE30(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2750(s32);
extern void func_003ABD38(void *);
extern void func_003AEE38(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
/* localdecomp:start func_003AF0B8 */
void *func_003AF0B8(u8 *a0, s32 a1) {
    s32 i;
    s32 *p;
    s32 z;
    V8_3A9B10 v;
    u32 j;
    s32 sz;
    u8 *t;

    p = (s32 *)(a0 + 4);
    for (i = 0x707; i != -1; i--) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
    func_003ABE28(a0 + 0x1FC90);
    func_003AED10(a0 + 0x1FCA8);
    func_121760(D_001D8770, a1);
    sz = 0x24F10;
    D_001D5C78 = (s32)a0;
    *(s32 *)a0 = ((s32)a0 + sz + 3) & ~3;
    *(s32 *)(a0 + 0x24DC8) = sz;
    t = D_00160C40;
    func_003A26F0(a0 + 0x7090, *(s32 *)(t + 0x61C8) + *(s32 *)(t + 0x4954), *(s32 *)(t + 0x61CC));
    ((void (*)(void *, u32, s32, s32))func_003ABE30)(a0 + 0x1FC90, 0x10, (s32)(a0 + 4), 0x7080);
    *(s32 *)(a0 + 0x24DCC) = 0;
    *(s32 *)(a0 + 0x24DD0) = 0;
    *(s32 *)(a0 + 0x24DD4) = 0;
    *(s32 *)(a0 + 0x24DD8) = 0;
    *(s32 *)(a0 + 0x24DE4) = 0;
    *(s32 *)(a0 + 0x24DE8) = 0;
    *(s32 *)(a0 + 0x24DEC) = 0;
    func_11A264(a0 + 0x24DF0, 0, 0x20);
    func_11A264(a0 + 0x24E10, 0, 0x100);
    func_11F0A0(0);
    z = 0;
    do {
        v = *(V8_3A9B10 *)D_001D8790;
    } while (z);
    j = 0;
    do { j++; } while (j < 8);
    func_003A2750(1);
    func_003ABD38(a0 + 0x7090);
    func_003AEE38(a0 + 0x1FCA8, a0, a0 + 0x1FC90);
    return a0;
}
/* localdecomp:end func_003AF0B8 */

LINKER_REMNANT("asm/remnants", func_003AF290);
