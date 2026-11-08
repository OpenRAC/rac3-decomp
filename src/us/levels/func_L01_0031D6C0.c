#include "common.h"

typedef struct {
    u8 pad[104];
    s32 f68;
} Moby_0031BEF0;
typedef struct {
    u8 pad0[0x24];
    u8 *x24;
    u8 pad28[0xC];
    u16 h34;
} T_31DB28;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x14];
} H_31DB28;
typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0x80];
} G_31DB28;
typedef struct {
    u8 pad0[0x18];
    T_31DB28 *x18;
} D_31DB28;
typedef struct { u8 b[320]; } E320_321CB8;
typedef struct { u8 b[160]; } E160_321CB8;
typedef struct { u8 x0; u8 x1; u8 pad[238]; } E240_321CB8;
typedef struct { u8 pad[80]; s32 idx; } Sub_00322E00;
typedef struct { u8 pad[104]; Sub_00322E00 *sub; } Moby_00322E00;

extern s32 fe_func_0038CAD0(s32);
extern void fe_func_003C2880(Moby_0031BEF0 *);
void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3);
#define CHK(m) ((m) != 0 && *(u8 **)((m) + 36) != 0 && (*(u8 **)((m) + 36))[70] == 18)
extern void fe_func_003C2880(Moby_0031BEF0 *);
extern s32 fe_func_00382468(s32);
extern s32 fe_func_00382498(s32, s32);
extern f32 fe_func_003824E0(f32, f32);
extern void fe_func_0038CF68(f32 *, s32, f32);
/* localdecomp:start func_L01_0031D6C0 */
extern void func_0039FE80(s32, s32, u8 *);
extern void func_L01_0032FE90(float, u8 *,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              float, float, float);
extern void func_L01_004C41E8(u8 *, float *);
extern void func_00388830(f32 *, s32, f32);
extern void func_00388758(float *, float *, float *);
extern float func_0037E2A8(void);
extern float func_0037E250(float, float);
extern void func_0037E4B8(float *, float, float, float);
extern void func_003888C8(float *, float *, float *);
extern u8 *func_L01_0031E2D8(u8 *, float *, s32, s32, s32);
extern void func_L01_004C4AB8(s32);
extern s32 D_L01_001DB02C;
__asm__(".extern D_L01_001DC8B4, 4");
extern s32 D_L01_001DC8B4;

void func_L01_0031D6C0(u8 *object) {
    int i;
    float basis[3][4];
    float perpendicular[4];
    float direction[4];
    u8 *state = *(u8 **)(object + 0x68);
    u8 *fragment;
    float strength;
    float heading;
    float elevation;
    float speed;
    int j;

    func_0039FE80(0, 0, object);
    strength = 0.7f;
    for (j = 0; j < 2; j++) {
        func_L01_0032FE90(strength, object + 0x10, 1, 14, 10, 15, 10, 20, 0,
                          1, 0, 1, 0, 0, 0, 0, D_L01_001DB02C, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0, 0.0f, 0.0f, 0.0f);
        strength += 0.3f;
    }
    func_L01_004C41E8(object + 0x10,basis[2]);
    perpendicular[0] = basis[2][2];
    perpendicular[1] = basis[2][2];
    perpendicular[2] = -(basis[2][0] + basis[2][1]);
    func_00388830(basis[0], (s32)perpendicular, 1.0f);
    func_00388758(basis[1], basis[0], basis[2]);
    basis[0][3] = basis[1][3] = basis[2][3] = 0.0f;
    for (i = 0; i < D_L01_001DC8B4; i++) {
        heading = func_0037E2A8();
        if (*(s32 *)(state + 0x2C) != 0) {
            elevation = func_0037E250(0.69813168f, 1.30899692f);
            speed = func_0037E250(4.0f, 12.0f) * 0.0166666675f;
        } else {
            elevation = func_0037E250(0.87266463f, 1.57079637f);
            speed = func_0037E250(4.0f, 9.0f) * 0.0166666675f;
        }
        func_0037E4B8(direction, speed, heading, elevation);
        direction[3] = 0.0f;
        func_003888C8(direction, direction, basis[0]);
        fragment = func_L01_0031E2D8(object + 0x10,direction, i, *(s32 *)(state + 0x2C), 0);
        if (fragment != 0) *(s32 *)(fragment + 0xB8) = *(s32 *)(object + 0xB8);
    }
    func_L01_004C4AB8(*(s32 *)(state + 0x30));
}
/* localdecomp:end func_L01_0031D6C0 */
