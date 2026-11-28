#include "common.h"
/* localdecomp:start func_L01_00323518 */
#include "vu0.h"
typedef int Q_00323A18 __attribute__((mode(TI)));
typedef union { Q_00323A18 q; f32 f[4]; } V_00323A18;
typedef struct { u8 pad[0xD4]; u8 *texture; } Textures_00323A18;
extern Textures_00323A18 D_L01_00221118[];
extern s32 D_L01_001DCA40_00323518;
__asm__(".extern D_L01_001DCA40_00323518, 4");
extern s32 D_L01_001DCA20_00323518;
__asm__(".extern D_L01_001DCA20_00323518, 4");
extern u8 D_L01_001D66B0[8];
void func_L01_00323518(u8 *obj) {
    extern void func_003886E8(void *, void *, f32);
    extern f32 func_L01_00440918(f32, f32);
    extern s32 func_0037E1D8(s32);
    extern u8 *func_L01_0046C468(void *, u8 *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    V_00323A18 pos, delta, step, jitter;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 size, spread;
    s32 i, spin;
    u8 *p;
    if (D_L01_001DCA40_00323518) {
        pos.q = *(Q_00323A18 *)(vars + 0x10);
    }
    else {
        pos.q = *(Q_00323A18 *)(vars + 0x20);
    }
    func_003886E8(&delta, obj + 0xD0, -0.1f);
    vec_add_ba(&pos, &pos, &delta);
    func_003886E8(&step, obj + 0xE0, 0.15f);
    vec_add_ab(&pos, &pos, &step);
    func_003886E8(&step, obj + 0xE0, -0.033333335f);
    if (D_L01_001DCA20_00323518) { size = 0.2f; spread = 0.15f; }
    else { size = 0.175f; spread = 0.1f; }
    for (i = 0; i < 9; i++) {
        jitter.f[0] = pos.f[0] + func_L01_00440918(0.0f, spread);
        jitter.f[1] = pos.f[1] + func_L01_00440918(0.0f, spread);
        jitter.f[2] = pos.f[2] + func_L01_00440918(0.0f, spread);
        spin = func_0037E1D8(255);
        func_L01_0046C468(&jitter, D_L01_001D66B0, 4, 0x808080, spin, 127, 127,
                          size * 210000.0f, size * 210000.0f, 0.0f, 1);
        p = func_L01_0046C468(&pos, D_L01_001D66B0, 4, 0x203080, spin, 16, 16,
                             262500.0f, 262500.0f, 0.0f, 1);
        if (p) {
            p[2] = *D_L01_00221118[0].texture;
        }
        vec_add_ab(&pos, &pos, &step);
    }
}
/* localdecomp:end func_L01_00323518 */
