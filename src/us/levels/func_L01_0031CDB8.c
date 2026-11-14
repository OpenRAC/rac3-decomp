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
/* localdecomp:start func_L01_0031CDB8 */
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00440A88(f32 *, f32, f32);
extern u8 *func_L01_004633E8(f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32);
extern void func_00388830(f32 *, s32, f32);
extern void func_L01_00300650(u8 *, u8 *, s32, s32);
extern u8 D_L01_002AE940[];

/* bouncer_muzzle: spawns 20 smoke particles with random size and tint at a1, sets their life and
 * fade fields, then spawns a light moby at a vector scaled by 1.5 from a2. */
void func_L01_0031CDB8(u8 *a0, u8 *a1, u8 *a2)
{
    f32 local[4];
    f32 f;
    s32 i;
    u32 v;
    u32 w;
    u32 x;
    u8 *r;

    for (i = 19; i >= 0; i--) {
        func_0037E1D8(2);
        func_0037E1D8(2);
        f = func_0037E250(70000.0f, 150000.0f);
        v = func_0037E208(10, 127);
        w = (v << 8) | 0x7f000000U;
        x = (v << 16) | w;
        v = x | v;
        func_L01_00440A88(local, 1.66666687e-05f, 0.00666666729f);
        r = func_L01_004633E8(0.3f, 1.0f, 1.01f, f, a1, 0, local, v, 1);
        if (r != 0) {
            u8 *q = r + 32;

            *(s16 *)(r + 10) = 120;
            *(s32 *)(q + 4) = 2;
            *(u8 *)(q + 10) = 127;
            *(u8 *)(q + 11) = *(u8 *)(r + 10);
        }
    }
    func_00388830((f32 *)D_L01_002AE940, (s32)a2, 1.5f);
    func_L01_00300650(D_L01_002AE940, a1, 0, 0);
}
/* localdecomp:end func_L01_0031CDB8 */
