#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void *func_003AF470();
extern void * func_003AF470();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AF0C8 */
u8 *func_003AF0C8(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_003AB820(q); q += 0x3C; }
        base += 0x618;
    }
    func_003AB820(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_003AD9C0(q); q += 0xB50; }
    func_003ABAF0(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_003AC328(q); q += 0x230; }
    func_003AC328(p + 0x4ED0);
    return p;
}
/* localdecomp:end func_003AF0C8 */

extern u8 *D_001D5C78_003AF1F0;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
extern s32 func_003AC190();
extern void func_003AB858();
extern void func_003AC0D0();
extern void func_003ABF98();
extern void func_003ABFA0();
extern void func_003AB8E8();
extern void func_003AB900();
extern void func_003AC0E8();
extern void func_003AC0C8();
extern void func_003ADB90();
extern void func_003AC360();
extern void func_003ABB30();
extern f32 *func_003ABBD8();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
/* localdecomp:start func_003AF1F0 */
extern s32 *func_003AB270();
extern u8 *D_001D5C78_003AF1F0;
extern s32 D_001D545C;
extern u8 D_001D8730[];
__asm__(".extern D_001D5C78_003AF1F0, 16");
__asm__(".extern D_001D545C, 16");
void func_003AF1F0(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003AC190(D_001D5C78_003AF1F0 + 0x7090, 0xC);
        sx->b[k] = func_003AC190(D_001D5C78_003AF1F0 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003AB858(b, 0x16, 1, D_001D8730, a2);
                func_003AC0D0(b, 5);
                func_003ABF98(b, 0x64);
                func_003ABFA0(b, 0);
                func_003AB8E8(b, 0x706EC8FF, 0x706EC8FF);
                func_003AB900(b, 0x80808080, 0x80808080);
                func_003AC0E8(b, 0x80000000);
                func_003AC0C8(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003ADB90(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003AC360(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003ABB30(q, D_001D8740, a2);
    *(f32 *)func_003AB270(q) = 2155905024.0f;
    *func_003ABBD8(q) = 60008.0f;
    ((s32 *)func_003ABBD8(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003AC360(s + 0x4ED0, a2);
}
/* localdecomp:end func_003AF1F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF410);

/* localdecomp:start func_003AF420 */
extern void func_003ACF78(void *);
 
void func_003AF420(void *p, s32 i) {
    func_003ACF78((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF420 */

/* localdecomp:start func_003AF448 */
extern void func_003AD630(void *);
 
void func_003AF448(void *p, s32 i) {
    func_003AD630((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF448 */

extern void *func_003AC1E0(void *);
extern void func_00121760(void *, void *);
extern s32 func_003A2AF0();
extern void func_003AC1E8(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2B50(s32);
extern void func_003AC0F0(void *);
extern void func_003AF1F0(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
/* localdecomp:start func_003AF470 */
void *func_003AF470(u8 *a0, s32 a1) {
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
    func_003AC1E0(a0 + 0x1FC90);
    func_003AF0C8(a0 + 0x1FCA8);
    func_121760(D_001D8770, a1);
    sz = 0x24F10;
    D_001D5C78 = (s32)a0;
    *(s32 *)a0 = ((s32)a0 + sz + 3) & ~3;
    *(s32 *)(a0 + 0x24DC8) = sz;
    t = D_00160C40;
    func_003A2AF0(a0 + 0x7090, *(s32 *)(t + 0x61C8) + *(s32 *)(t + 0x4954), *(s32 *)(t + 0x61CC));
    ((void (*)(void *, u32, s32, s32))func_003AC1E8)(a0 + 0x1FC90, 0x10, (s32)(a0 + 4), 0x7080);
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
    func_003A2B50(1);
    func_003AC0F0(a0 + 0x7090);
    func_003AF1F0(a0 + 0x1FCA8, a0, a0 + 0x1FC90);
    return a0;
}
/* localdecomp:end func_003AF470 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF648);
