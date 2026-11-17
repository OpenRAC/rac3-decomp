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
/* localdecomp:start func_003B5D70 */
__asm__(".extern D_001D89C0, 4");
__asm__(".extern D_001D89C4, 4");
__asm__(".extern D_001D89C8, 4");
__asm__(".extern D_001D89CC, 4");
__asm__(".extern D_001D89D8, 4");
__asm__(".extern D_001D89DC, 4");
__asm__(".extern D_001D89E0, 4");
void func_003B5D70(void) {
    S_3B07B8 s;
    s32 n, i, j;
    f32 c1 = 0.572f;
    f32 c2 = 0.08474667f;
    i = 0;
    D_001D89C8 = -1;
    D_001D89CC = -1;
    D_001D89C0 = -1;
    D_001D89C4 = -1;
    for (n = 0; D_0037F830[n].a > 0; n++);
    s.f0 = 0x9000;
    s.f4 = (s32)func_003B5048(4);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 7 ? n : 6;
    s.f14 = 2;
    s.f18 = 1.0f;
    s.f1C = c1;
    s.f20 = c2;
    s.a24[0] = D_001D89D8;
    s.a24[1] = D_001D89DC;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = D_001D89E0;
    s.a34[1] = D_001D89DC - D_001D89D8 - D_001D89E0;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003BABB0)(func_003B9BD0(0), 0, 0.500369f, 0.816536f, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.698703f, 0.816536f, 0.314706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.033f, 0.00666f, 0.03f);
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 2, 3);
    for (j = 0; j < n; j++) {
        func_11B2E8(func_003B9E30_003B5D70(func_003B9BD0(0), 0, i++), D_001D8A08, func_00381FF0(D_0037F830[j].a));
    }
}
/* localdecomp:end func_003B5D70 */

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
