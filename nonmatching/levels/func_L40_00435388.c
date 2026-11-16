/* PAL near miss (Codex wave 7): near miss: 183 words differ with the file's flags.
 * Worker's note: 183 instruction differences in build/codex/w373/func_L40_00435388.03.log; complete packet/geometry reconstruction, float block matches, remaining loop induction/spills/register allocation (frame 0x390 vs 0x3B0). Switch labels 0,1,2,3 proven in ...
 */
#include "common.h"
/* localdecomp:start func_L40_00435388 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long zero, texture, tag, flags;
} Quad_00435388;
typedef struct { vu0_v4 rows[4]; } Matrix_00435388;
typedef struct { vu0_v4 rows[3]; } Rotation_00435388;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x48];
    f32 *time;
    u8 pad6C[0x54];
    Matrix_00435388 transform;
} Moby_00435388;
extern s32 D_001DC450_sda;
extern s32 D_001DC454_sda;
extern s32 D_001DC458_sda;
extern s32 D_001DC45C_sda;
extern s32 D_001DC460_sda;
extern u32 D_001DC468_sda[2];
extern f32 D_001DC470_sda[8];
extern f32 D_L40_00247B84[];
extern f32 D_001DC490_sda;
extern f32 D_001DC498_sda;
extern f32 D_L40_00247ED8;
__asm__(".extern D_001DC450_sda, 4");
__asm__(".extern D_001DC454_sda, 4");
__asm__(".extern D_001DC458_sda, 4");
__asm__(".extern D_001DC45C_sda, 4");
__asm__(".extern D_001DC460_sda, 4");
__asm__(".extern D_001DC468_sda, 8");
__asm__(".extern D_001DC470_sda, 4");
__asm__(".extern D_001DC490_sda, 4");
__asm__(".extern D_001DC498_sda, 4");
void func_L40_00435388(Moby_00435388 *moby) {
    extern void func_0038D570(void *, void *);
    extern unsigned long func_L39_00589890(s32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_L04_0041AE18(void *, s32, void *, s32, void *);
    Quad_00435388 quads[4];
    Matrix_00435388 world;
    Rotation_00435388 rotation;
    vu0_v4 angles;
    f32 *time;
    f32 alpha, width, t, a, b;
    s32 i, j;
    time = moby->time;
    func_0038D570(&world, &moby->transform);
    *(vu0_q *)&world.rows[3] = *(vu0_q *)&moby->pos;
    for (i = 0; i < 4; i++) {
        quads[i].texture = func_L39_00589890(D_001DC460_sda);
        quads[i].tag = 0xFF9000000260UL;
        quads[i].zero = 0;
        quads[i].flags = (long)D_001DC450_sda | ((long)D_001DC454_sda << 2) |
            ((long)D_001DC458_sda << 4) | ((long)D_001DC45C_sda << 6) | 0x8000000000UL;
    }
    width = 0.15f;
    alpha = (0.85f - *time) * 2.0f;
    if (alpha > 1.0f) alpha = 1.0f;
    else if (alpha < 0.0f) alpha = 0.0f;
    t = *time;
    if (t < 1.15f) {
        a = 1.15f - t;
        if (a < 0.0f) a = 0.0f;
        b = 0.2f;
        b = (b - t) / b;
        if (b < 0.0f) b = 0.0f;
        D_L40_00247ED8 = b;
        width = a + 0.15f;
    }
    for (i = 0; i < 4; i++) {
        f32 *u = D_001DC470_sda;
        f32 *v = D_L40_00247B84;
        for (j = 0; j < 4; j++) {
            quads[i].uv[j][0] = *u;
            quads[i].uv[j][1] = *v;
            quads[i].color[j] = D_001DC468_sda[i != 0];
            quads[i].color[j] = func_0038DBD8(quads[i].color[j] & 0xFFFFFF, quads[i].color[j], alpha);
            __asm__("sqc2 $vf0, 0(%1)" : "=m"(quads[i].pos[j]) : "r"(&quads[i].pos[j]));
            quads[i].pos[j].x = *time + (i ? 0.01f : 0.0f);
            if (j & 1) {
                switch (i) {
                case 0: quads[0].pos[j].z += D_001DC490_sda + width; break;
                case 1: quads[1].pos[j].z += D_001DC490_sda + D_001DC498_sda; break;
                case 2: quads[2].pos[j].z += (D_001DC490_sda - width * 0.8f) + D_001DC498_sda; break;
                case 3: quads[3].pos[j].z += (D_001DC490_sda + width * 0.8f) + D_001DC498_sda; break;
                }
            } else {
                switch (i) {
                case 0: quads[0].pos[j].z += D_001DC490_sda - width; break;
                case 1: quads[1].pos[j].z += D_001DC490_sda - D_001DC498_sda; break;
                case 2: quads[2].pos[j].z += (D_001DC490_sda - width * 0.8f) - D_001DC498_sda; break;
                case 3: quads[3].pos[j].z += (D_001DC490_sda + width * 0.8f) - D_001DC498_sda; break;
                }
            }
            u += 2;
            v += 2;
        }
    }
    *(vu0_q *)&angles = 0;
    angles.z = 0.19634954631328583f;
    func_0038D308(&rotation, &angles);
    func_L04_0041AE18(quads, 4, &rotation, 0x20, &world);
}
/* localdecomp:end func_L40_00435388 */
