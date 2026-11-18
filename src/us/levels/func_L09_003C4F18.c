#include "common.h"

typedef void (*fn_3C5D58)(u8 *);

typedef struct HrugisEffectCamera {
    char pad00[0x140];
    float position[4];
} HrugisEffectCamera;

typedef struct {
    f32 m[16];
} M_003CA6A8;
typedef struct {
    u8 pad0[0x1F0];
    M_003CA6A8 j[19];
    f32 a[4];
    f32 c[4];
} S_003CA6A8;

typedef struct {
    u8 p0[0x10];
    u8 f10[0x10];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 p2C[0x14];
} M_003CA7E8;
typedef struct {
    u8 pad[0x1E0];
    M_003CA7E8 m[4];
    u8 pad2[0x3D0];
    f32 a[4];
    f32 b[4];
} S_003CA7E8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C7568;

typedef int u128_t_003C7DF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C7DF8;
typedef struct { u8 pad00[0x8C]; u8 *f8C; } S_003C7DF8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003CA998;
typedef struct {
    u8 pad0[0xC0];
    V_003CA998 f270;
    u8 pad280[0x110 - 0xD0];
    s32 f2E8;
    u8 pad2EC[0x138 - 0x114];
    f32 f310;
} G_003CA998;
typedef struct {
    u8 pad0[0x2B0];
    u8 f2B0[0x100];
    u8 f3B0[0x6D0 - 0x3B0];
    G_003CA998 *f6D0;
    u8 pad6D4[0x6F0 - 0x6D4];
    f32 f6F0;
    f32 f6F4;
    u8 pad6F8[0x74C - 0x6F8];
    f32 f74C;
    f32 f750;
} P_003CA998;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x20 - 0x1C];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    P_003CA998 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 fBC;
    u8 padBD[3];
    V_003CA998 fC0;
    V_003CA998 fD0;
    V_003CA998 fE0;
    f32 fF0;
    f32 fF4;
} M_003CA998;

typedef struct {u8 a[0x19E0];int f19E0;short f19E4;u8 b[0x25C0-0x19E6];u8 *f25C0;int f25C4;u8 c[0x280C-0x25C8];int f280C;} Hero;
typedef struct {int a,b,c;} Other;

typedef int Q_003C5F38 __attribute__((mode(TI)));



/* localdecomp:start func_L09_003C4F18 */
typedef struct {
    u8 p0[0x20];
    f32 f20;
    u8 p24[4];
    s32 f28;
    s32 f2C;
    f32 f30;
    u8 p34[4];
    s32 f38;
    u8 p3C[4];
    f32 f40;
    u8 p44[4];
    s32 f48;
} G_003C6890;
extern G_003C6890 D_L09_001E2C00;
extern void func_L09_00409960(s32, s32);

void func_L09_003C4F18(void *a0) {
    ((s32 (*)(s32, s32))func_L09_00409960)(0x12, 0);
    D_L09_001E2C00.f20 = 0.3f;
    D_L09_001E2C00.f30 = 0.1f;
    D_L09_001E2C00.f40 = 0.01f;
    D_L09_001E2C00.f28 = 0x18;
    D_L09_001E2C00.f38 = 0x18;
    D_L09_001E2C00.f48 = 0x18;
    D_L09_001E2C00.f2C = 0;
}
/* localdecomp:end func_L09_003C4F18 */
