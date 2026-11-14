#include "common.h"

/* localdecomp:start func_L30_0034E548 */
typedef struct {
    u8 pad0[3];
    u8 alpha;
    u32 colour;
    u8 frame;
    u8 pad9;
    s16 hA;
    f32 scale;
    f32 pos[4];
} S_0034E548_A;
typedef struct {
    u8 *moby;
    void *p4;
    s16 h8;
    u16 flags;
    u8 padC[4];
    f32 phase;
    f32 speed;
} S_0034E548_B;
extern u8 D_L30_001DD52C; __asm__(".extern D_L30_001DD52C, 1");
extern f32 D_L30_001DD538; __asm__(".extern D_L30_001DD538, 4");
extern f32 D_L30_001DD540; __asm__(".extern D_L30_001DD540, 4");
extern f32 D_L30_001DD544; __asm__(".extern D_L30_001DD544, 4");
extern f32 D_L30_001DD548; __asm__(".extern D_L30_001DD548, 4");
extern f32 D_L30_001DD554; __asm__(".extern D_L30_001DD554, 4");
extern void func_L30_0034E420(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
void func_L30_0034E548(void *arg0, void *arg1) {
    S_0034E548_A *a0 = arg0;
    S_0034E548_B *a1 = arg1;
    u8 *moby;
    void *p4;
    void *m68;
    f32 t;
    if (a1 != 0) {
        moby = a1->moby;
        p4 = a1->p4;
        m68 = *(void **)(moby + 0x68);
        if (moby != 0) {
            if (moby[0x20] < 0xFD && m68 != 0 && p4 != 0) {
                if (a1->flags & 1) {
                    func_L30_0034E420(moby, a0->pos);
                    a0->pos[1] += D_L30_001DD554;
                    a1->phase = func_003824E0(0.0f, 255.0f);
                    a1->speed = func_003824E0(D_L30_001DD544, D_L30_001DD540);
                    a0->frame = a1->phase;
                    a0->scale = D_L30_001DD548;
                    a0->alpha = D_L30_001DD52C;
                }
                a0->pos[1] -= D_L30_001DD554 / (f32)(a1->h8 + 2);
                t = func_L03_0034B440(1, 0, 0, (f32)a0->hA, (f32)a1->h8, 1.0f);
                a1->phase = a1->phase + a1->speed;
                if (a1->phase > 255.0f) {
                    a1->phase = a1->phase - 255.0f;
                }
                a0->frame = a1->phase;
                a0->colour = (func_L30_0034E4D0(moby, 0) & 0xFFFFFF) | ((s32)(D_L30_001DD538 * (1.0f - t)) << 24);
            }
        }
    }
}
/* localdecomp:end func_L30_0034E548 */
