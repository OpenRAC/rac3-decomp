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
extern void func_11B2E8();
extern s32 D_001D89E4;
extern void func_003B5D70();
extern s32 D_001D89B0;
extern u8 D_0037F690[];
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern s32 *func_003B9BD0(s32);
extern void func_003B6018(void);
extern void *func_003B5048(s32);
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037F830[];
extern void *func_003B5048(s32 i);

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8;
extern s32 D_001D89C0;
extern s32 D_001D89C4;
extern s32 D_001D89C8;
extern s32 D_001D89CC;
extern f32 D_001D89D8;
extern f32 D_001D89DC;
extern f32 D_001D89E0;
extern char D_001D8A08[];
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358();
extern s32 func_003B9E30_003B5D70(void *, s32, s32);
extern s32 func_00381FF0();
extern void func_11B2E8();
INCLUDE_ASM("asm/nonmatchings/text", func_003B5D70);

/* localdecomp:start func_003B6018 */
extern u8 D_0037F790[];
extern s32 D_00143950_b[];
extern char D_001D8A08[];
extern char D_001D8A10[];
extern s32 func_003B64A8(void);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_003E7C90(s32, s32);

void func_003B6018(void) {
    s32 i = 0;
    u8 *base = D_0037F790;
    u8 *b = (u8 *)D_00143950_b;
    char *fmt = D_001D8A08;
    s32 yes = 0x175;
    s32 no;
    u8 *p1 = base + 0x20;
    u8 *p2 = base + 0x40;
    u8 *p3 = base + 0x60;
    E_37B870 *e;
    u8 *p;
    void *text;
    func_11B2E8(base, fmt, func_00381FF0(b[0xAD] == 0 ? 0x176 : yes));
    no = 0x176;
    func_11B2E8(p1, fmt, func_00381FF0(b[6] ? yes : no));
    func_11B2E8(p2, fmt, func_00381FF0(*(s32 *)(b + 8) ? 0x237 : 0x236));
    ((s32 (*)())func_11B2E8)(p3, fmt, func_00381FF0(func_003B64A8()));
    e = D_0037F830;
    if (e->a) {
      p = base;
      do {
        text = (void *)func_003B9E30(func_003B9BD0(0), 0, i);
        func_11B2E8(text, D_001D8A10, func_00381FF0(e->a));
        e++;
        text = (void *)func_003B9E30(func_003B9BD0(0), 1, i);
        i++;
        ((s32 (*)())func_11B2E8)(text, D_001D8A08, p);
        p += 0x20;
      } while (e->a);
    }
    func_003E7C90(0x1C0004, func_00381FF0(0x1EBD));
}
/* localdecomp:end func_003B6018 */

extern u8 D_0037F830_003B0A60[];
extern s32 *func_003B9BD0(s32);
extern u8 D_0037F790[];
extern u8 D_0037F810[1];
extern char D_001D8A08[];
extern char D_001D8A10[];
extern s32 D_00143950_b[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_003E7C90_003B0A60();
extern void *func_003B9E30_003B0A60();

/* localdecomp:start func_003B61D0 */
extern s32 D_00143950_b[];
extern void func_003873C0();
 
void func_003B61D0(void) {
    u8 *b = (u8 *)D_00143950_b;
    b[0xAD] = b[0xAD] == 0;
    func_003873C0();
}
/* localdecomp:end func_003B61D0 */

/* localdecomp:start func_003B6200 */
extern void func_003B6280(void);

void func_003B6200(void) {
    u8 *b = (u8 *)D_00143950_b;
    if (b[0xB7] == 0) {
        b[0xB7] = 1;
    }
    b[0xB7] = (b[0xB7] + 1) % 6;
    func_003B6280();
}
/* localdecomp:end func_003B6200 */

extern s32 D_001D5520_003B0C70;
extern s32 D_001D89B0;
extern s32 D_001D89E4;
extern u8 D_0037F690[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_003B6438(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern s32 D_00143950_b[];
extern void func_003B6280(void);

/* localdecomp:start func_003B6250 */
extern u8 D_00143950[];
s32 func_003B6250(void) {
    u8 *p = &D_00143950[0];
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B6250 */

/* localdecomp:start func_003B6268 */
extern s32 D_00143950_b[];

s32 func_003B6268(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B6268 */
