#include "common.h"

/* localdecomp:start func_L08_003C73B8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C73B8;
typedef struct { u8 pad0[0x10]; u8 *f10; } S_003C73B8;
__asm__(".extern D_L08_001DE878, 4");
__asm__(".extern D_L08_001DE87C, 4");
__asm__(".extern D_L08_001DE880, 4");
__asm__(".extern D_L08_001DE884, 4");
__asm__(".extern D_L08_001DE888, 4");
__asm__(".extern D_L08_001DE88C, 4");
__asm__(".extern D_L08_001DE890, 4");
__asm__(".extern D_L08_001DE894, 4");
__asm__(".extern D_L08_001DE898, 4");
__asm__(".extern D_L08_001DE89C, 4");
__asm__(".extern D_L08_001DE8A0, 4");
extern s32 D_L08_001DE878;
extern s32 D_L08_001DE87C;
extern s32 D_L08_001DE880;
extern s32 D_L08_001DE884;
extern s32 D_L08_001DE888;
extern s32 D_L08_001DE88C;
extern f32 D_L08_001DE890;
extern f32 D_L08_001DE894;
extern f32 D_L08_001DE898;
extern f32 D_L08_001DE89C;
extern f32 D_L08_001DE8A0;
extern S_003C73B8 D_L08_0021EB18;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L08_003C73B8(u8 *m, V4_003C73B8 *a, V4_003C73B8 *b) {
    V4_003C73B8 pos;
    V4_003C73B8 vel;
    u8 *p;
    s32 i;
    s32 col;
    u8 alpha;
    f32 t;
    u8 *e;

    p = *(u8 **)(m + 0x68);
    pos = *a;
    if (*(s32 *)(p + 0x10) < 50) {
        alpha = (*(s32 *)(p + 0x10) * 127.0f) / 50.0f;
    } else {
        alpha = 127;
    }
    for (i = 0; i < D_L08_001DE878; i++) {
        t = D_L08_001DE898 * *(f32 *)(p + 0x14);
        func_00382580(&vel, t * 0.5f, t);
        vec_add_ab(&vel, &vel, b);
        func_0038CF68(&vel, &vel, func_003824E0(D_L08_001DE89C * 0.5f, D_L08_001DE89C) * 0.020000001f);
        if (func_00382468(4) != 0) {
            col = D_L08_001DE88C;
        } else {
            col = D_L08_001DE884;
        }
        col |= alpha << 24;
        e = func_L01_00475C60(&pos, &vel, (D_L08_001DE87C * 5 + 2) / 6, func_00382498(-2, 2), col, D_L08_001DE888,
                              D_L08_001DE890 * 210000.0f, D_L08_001DE894 * 210000.0f,
                              func_003824E0(D_L08_001DE8A0 * 0.3f, D_L08_001DE8A0), 0);
        if (e != 0) {
            e[2] = *D_L08_0021EB18.f10;
            e[3] = func_00382468(2) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(6) == 0) {
        func_L01_00470668(&pos, &vel, (func_00382498(D_L08_001DE880 - 5, D_L08_001DE880) * 5 + 2) / 6, func_003824E0(40.0f, 80.0f) * 0.00040000002f);
    }
}
/* localdecomp:end func_L08_003C73B8 */
