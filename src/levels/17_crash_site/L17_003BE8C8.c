#include "common.h"
#include "vu0.h"

typedef struct S_003BED98 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x75];
    u16 f96;
} S_003BED98;

/* localdecomp:start func_L17_003BE8C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE8C8;
extern s32 D_L17_001D66B0[2];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L17_003BE8C8(u8 *self, s32 id, s32 snd, f32 speed, f32 scale, s32 fx1, s32 fx2, s32 fx3, s32 col1, s32 col2, s32 col3, s32 col4, s32 col5, u8 flag) {
    V4_3BE8C8 pos, vel;
    V4_3BE8C8 *pt;

    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, id, D_L17_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (snd != 0) func_L05_003DC520(self, snd);
    pt = &pos;
    pos = *(V4_3BE8C8 *)(self + 0x10);
    vel = *(V4_3BE8C8 *)(self + 0xE0);
    func_0038CF68(&vel, &vel, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * speed);
    vec_add_ab(&pos, &pos, &vel);
    if (fx1 != 0) {
        func_L02_00429840(self, pt, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * 4.0f, 0x14, 0,
                          D_L17_001D66B0, 0.20000002f, 1.0f, 1.5f, col1, 0, 0x4B);
    }
    if (fx2 != 0) {
        func_L02_003E2E38(self, pt, 1.0f, D_L17_001D66B0, 0xF, 0, 0.050000004f, 2.5f, 5.0f, 1.0f, 1);
    }
    if (fx3 != 0) {
        func_L01_003303B8((u8 *)pt, 0, 0, 0, 0, 4, 5, 0,
                          *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * scale, 0.0f, 0.0f, 0.0f,
                          flag, 1, 0, 0, 0, 0, 0x1000000, 0, col2, col3, 0, 0, 0, 0, col4, col5, 0, 0);
    }
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
/* localdecomp:end func_L17_003BE8C8 */
