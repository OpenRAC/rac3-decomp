#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* localdecomp:start func_L01_0049A348 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_0049A348;
extern s32 D_L01_001D92EC;
__asm__(".extern D_L01_001D92EC, 4");
extern E_496DC0 *D_L01_001D92E8;
__asm__(".extern D_L01_001D92E8, 4");
extern char D_L01_001D9338[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, char *);

void func_L01_0049A348(void) {
    S_0049A348 s;
    s32 i = 0;
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = D_L01_001D92EC;
    s.f10 = D_L01_001D92EC < 7 ? D_L01_001D92EC : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = 0.563596f;
    s.f20 = 0.054f;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.795206f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536f, 0.045f, 0.0425f, 0.35f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.700703f, 0.816536f, 0.312706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0265f, 0.00666f, 0.03f);
    for (; i < D_L01_001D92EC; i++) {
        func_0011B2E8((char *)func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D9338, (char *)func_00381FF0(D_L01_001D92E8[i].x0));
    }
}
/* localdecomp:end func_L01_0049A348 */
