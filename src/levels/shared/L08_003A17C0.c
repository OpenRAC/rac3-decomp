#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

/* localdecomp:start func_L08_003A17C0 */
extern f32 D_L08_001DE25C;
__asm__(".extern D_L08_001DE25C, 4");
extern u8 *D_L08_0021EB18[];
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);

void func_L08_003A17C0(void *unused, void *owner, void *c) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    s32 i;
    s32 n;
    u8 *p;
    f32 speed;

    i = 0;
    do {
        func_0038CE20(&v50, (u8 *)c + 0x20, func_003824E0(0.0f, 0.75f));
        vec_add_ab(&v0, &v50, c);
        func_0038CE20(&v50, (u8 *)c + 0x10, func_L01_00443A18(0.0f, 0.5f));
        vec_add_ab(&v0, &v50, &v0);
        func_0038CE20(&v10, &v0, func_003824E0(D_L08_001DE25C * 0.25f, D_L08_001DE25C) * 0.020000001f);
        p = func_L01_004713C8(owner, &v10, (func_00382498(50, 70) * 5 + 2) / 6, 0x5A182, func_00382498(1, 4), 0x30, 0, 0,
                              63000.004f, 42000.0f, 0.002f);
        n = 3;
        if (p != 0) {
            p[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            p[2] = D_L08_0021EB18[0x69][0];
        }
        speed = D_L08_001DE25C;
        if (i < n * 4) {
            func_0038CE20(&v20, &v0, func_003824E0(speed * 0.12f, speed * 0.5f) * 0.020000001f);
            p = func_L01_004713C8(owner, &v20, (func_00382498(50, 70) * 5 + 2) / 6, 0x5A182, func_00382498(-1, -3), 0x20, 0, 0,
                                  84000.0f, 168000.0f, 0.002f);
            if (p != 0) {
                p[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
                p[2] = D_L08_0021EB18[0x17][0];
            }
            func_0038CE20(&v30, &v0, func_003824E0(D_L08_001DE25C * 0.3f, D_L08_001DE25C * 0.55f) * 0.020000001f);
            p = func_L01_004713C8(owner, &v30, (func_00382498(50, 70) * 5 + 2) / 6, 0xFFC8, -1, 0x60, 0, 0,
                                  126000.01f, 42000.0f, 0.0016000001f);
            if (p != 0) {
                p[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
                p[2] = D_L08_0021EB18[0x22][0];
            }
        }
        if (i < 9) {
            func_0038CE20(&v40, &v0, func_003824E0(D_L08_001DE25C * 0.12f, D_L08_001DE25C * 0.5f) * 0.020000001f);
            func_L01_00466F50(owner, &v40, 0x4000FFC8, -1.0f, -0.008f);
        }
    } while (++i < n * 4 + 3);
}
/* localdecomp:end func_L08_003A17C0 */
