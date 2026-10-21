/* US draft of func_003B5D70 (rac3-uya-decomp func_003B07B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B5D70 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8;
__asm__(".extern D_001D89C0, 4");
__asm__(".extern D_001D89C4, 4");
__asm__(".extern D_001D89C8, 4");
__asm__(".extern D_001D89CC, 4");
__asm__(".extern D_001D89D8, 4");
__asm__(".extern D_001D89DC, 4");
__asm__(".extern D_001D89E0, 4");
extern s32 D_001D89C0;
extern s32 D_001D89C4;
extern s32 D_001D89C8;
extern s32 D_001D89CC;
extern f32 D_001D89D8;
extern f32 D_001D89DC;
extern f32 D_001D89E0;
extern char D_001D8A08[];
extern void *func_003B5048(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358();
extern s32 func_003B9E30_003B5D70(void *, s32, s32);
extern s32 func_00381FF0();
extern void func_11B2E8();
void func_003B5D70(void) {
    S_3B07B8 s;
    s32 n, i, j;
    f32 c1 = 0.572f;
    f32 c2 = 0.06356f;
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
