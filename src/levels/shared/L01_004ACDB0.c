#include "common.h"

/* localdecomp:start func_L01_004ACDB0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004ACDB0;
typedef struct {
    u8 pad0[0x2A];
    s16 h2A;
    u8 pad2C[0x70 - 0x2C];
    u8 b70[0x10];
    V4_004ACDB0 v80;
} S_004ACDB0;
typedef struct {
    u8 pad0[0x25E5];
    u8 b25E5;
} Hero_004ACDB0;

extern Hero_004ACDB0 D_001A4BE0;
extern S_004ACDB0 D_0016C580;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D673C_004ACDB0;
__asm__(".extern D_L01_001D673C_004ACDB0, 4");
extern u8 D_001439F4[];

extern void func_003A1D00(void);
extern void func_L01_00510AD0(void);
extern void func_L01_00504E38(s32);
extern void func_L01_00512D38(void);
extern void func_L01_003F5498(s32, f32);
extern void func_L01_004606A8(s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);

void func_L01_004ACDB0(void) {
    V4_004ACDB0 pos;
    u8 *a;
    S_004ACDB0 *s;
    u8 m;

    func_003A1D00();
    D_001A4BE0.b25E5 = 0;
    func_L01_00510AD0();
    s = &D_0016C580;
    if (s->h2A != 0) {
        func_L01_00504E38(1);
        D_001A4BE0.b25E5 = 0;
        func_L01_00510AD0();
        if (D_L01_001D673C == 0) {
            func_L01_00512D38();
        }
        func_L01_003F5498(0, 7.0f);
        func_L01_004606A8(0);
        return;
    }
    if (D_L01_001D673C_004ACDB0 == 0) {
        *(u128_t *)&pos = *(u128_t *)&s->v80;
        m = D_001439F4[0];
        if (m == 0) {
            a = s->b70;
            pos.z = func_0038DAB8(s->v80.z, -1.08f);
            func_L01_004F50C8(a, &pos, 0, 1);
            pos.z = func_0038DAB8(s->v80.z, 1.22f);
            func_L01_004F50C8(a, &pos, 0, 0);
        } else {
            if (m == 2) {
                pos.z = func_0038DAB8(s->v80.z, -0.15f);
                func_L01_004F50C8(s->b70, &pos, 0, 1);
            } else {
                pos.z = func_0038DAB8(s->v80.z, -0.95f);
                func_L01_004F50C8(s->b70, &pos, 0, 1);
            }
        }
    } else {
        func_L01_004F50C8(s->b70, &s->v80, 0, 1);
    }
    func_L01_003F5498(0, 7.0f);
    func_L01_004606A8(0);
}
/* localdecomp:end func_L01_004ACDB0 */
