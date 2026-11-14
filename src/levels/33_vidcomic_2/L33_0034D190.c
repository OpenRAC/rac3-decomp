#include "common.h"

/* localdecomp:start func_L33_0034D190 */
#include "vu0.h"

extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00369C48(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
typedef struct { u8 pad[0x25C0]; void *f25C0; } S_1A4BE0_0034D190;
extern S_1A4BE0_0034D190 D_001A4BE0;
extern vu0_v4 D_L33_001E9620;
extern u8 D_L33_001E2700[];
extern u8 *D_L33_0021F598[];
extern f32 D_L33_001DD7B8;
__asm__(".extern D_L33_001DD7B8, 4");

void func_L33_0034D190(u8 *p, vu0_v4 *pos, vu0_v4 *vel) {
    vu0_v4 dir __attribute__((aligned(16)));
    vu0_v4 cur __attribute__((aligned(16)));
    vu0_v4 col __attribute__((aligned(16)));
    vu0_v4 end __attribute__((aligned(16)));
    s32 count = 2;
    s32 i;
    s32 j, k;
    u8 *r;
    f32 f;

    *(vu0_q *)&dir = 0;
    cur = *pos;
    dir.z = -5.0f;
    cur.x += *(f32 *)(p + 0xC0) * 2.5f;
    cur.z += 1.5f;
    for (j = 0; j < 10; j++) {
        vec_add_ab(&end, &cur, &dir);
        if (func_003D3CB0(&cur, &end, 2, D_001A4BE0.f25C0, 0) != 0) {
            col = D_L33_001E9620;
            col.y += func_003824E0(-0.5f, 0.5f);
            func_L01_00369C48(&col);
        }
        cur.x -= *(f32 *)(p + 0xC0) * 0.5f;
    }

    for (i = 0; i < count * 4 + 2; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.004f, 42000.0f, 0.002f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x1A4 / 4];
        }
    }

    for (i = 0; i < count * 4; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-0.5f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-1.0f, 1.0f) * 0.017453292f);
        f = D_L33_001DD7B8;
        func_0038CF68(vel, vel, func_003824E0(f * 0.25f, f - 0.1f));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, func_00382498(-1, -3), 0x20, 0, 0, 84000.0f, 168000.0f, 0.002f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x5C / 4];
        }
    }

    for (i = 0; i < count * 2 + 2; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, -1, 0x30, 0, 0, 63000.004f, 21000.0f, 0.00160000008f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x88 / 4];
        }
        f = D_L33_001DD7B8;
        func_0038CF68(vel, vel, func_003824E0(f * 0.25f, f - 0.1f));
    }

    for (k = 0; k < count * 2 + 2; k++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8 - 0.1f));
        func_L01_00466F50(pos, vel, 0x4005A182, -1.0f, -0.008f);
    }
}
/* localdecomp:end func_L33_0034D190 */

INCLUDE_ASM("asm/levels", func_L33_0034D838);
