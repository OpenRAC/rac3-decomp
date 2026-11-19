#include "common.h"

/* NTSC-U version of func_003B5D70 (frontbin): 0.0847467 -> 0.06356 */
#include "common.h"





extern s32 func_U_0037DF98();
extern void func_11B2E8();
extern void func_U_003B07B8();
extern s32 *func_U_003B46F0(s32);
extern void *func_U_003AFA90(s32);
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_U_0037B870[];
extern void *func_U_003AFA90(s32 i);
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8;
extern s32 D_U_001D89F0;
extern s32 D_U_001D89F4;
extern s32 D_U_001D89F8;
extern s32 D_U_001D89FC;
extern f32 D_U_001D8A08;
extern f32 D_U_001D8A0C;
extern f32 D_U_001D8A10;
extern char D_U_001D8A38[];
extern s32 *func_U_003B46F0(s32);
extern s32 func_U_003B4788();
extern void func_U_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_U_003B56F0(void *, f32, f32, f32, f32);
extern void func_U_003B5000(void *, s32, f32, f32, f32);
extern void func_U_003B4E78();
extern s32 func_U_003B4950_003B5D70(void *, s32, s32);
extern s32 func_U_0037DF98();
extern void func_11B2E8();
/* localdecomp:start func_U_003B07B8 */
__asm__(".extern D_U_001D89F0, 4");
__asm__(".extern D_U_001D89F4, 4");
__asm__(".extern D_U_001D89F8, 4");
__asm__(".extern D_U_001D89FC, 4");
__asm__(".extern D_U_001D8A08, 4");
__asm__(".extern D_U_001D8A0C, 4");
__asm__(".extern D_U_001D8A10, 4");
void func_U_003B07B8(void) {
    S_3B07B8 s;
    s32 n, i, j;
    f32 c1 = 0.572f;
    f32 c2 = 0.0635600016f;
    i = 0;
    D_U_001D89F8 = -1;
    D_U_001D89FC = -1;
    D_U_001D89F0 = -1;
    D_U_001D89F4 = -1;
    for (n = 0; D_U_0037B870[n].a > 0; n++);
    s.f0 = 0x9000;
    s.f4 = (s32)func_U_003AFA90(4);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 7 ? n : 6;
    s.f14 = 2;
    s.f18 = 1.0f;
    s.f1C = c1;
    s.f20 = c2;
    s.a24[0] = D_U_001D8A08;
    s.a24[1] = D_U_001D8A0C;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = D_U_001D8A10;
    s.a34[1] = D_U_001D8A0C - D_U_001D8A08 - D_U_001D8A10;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_U_003B4788(func_U_003B46F0(0), &s);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_U_003B56D0)(func_U_003B46F0(0), 0, 0.500369f, 0.816536f, 0.045f, 0.0425f, 0.35f);
    func_U_003B56F0(func_U_003B46F0(0), 0.500369f, 0.698703f, 0.816536f, 0.314706f);
    func_U_003B5000(func_U_003B46F0(0), 1, 0.033f, 0.00666f, 0.03f);
    func_U_003B4E78(func_U_003B46F0(0), 0, 1, 3);
    func_U_003B4E78(func_U_003B46F0(0), 1, 2, 3);
    for (j = 0; j < n; j++) {
        func_11B2E8(func_U_003B4950_003B5D70(func_U_003B46F0(0), 0, i++), D_U_001D8A38, func_U_0037DF98(D_U_0037B870[j].a));
    }
}
/* localdecomp:end func_U_003B07B8 */
