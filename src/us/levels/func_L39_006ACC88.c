#include "common.h"

/* NTSC-U counterpart of func_L39_006AF5D8 (src/levels/39_multiplayer_menu/L39_006AF5D8.c) */
typedef struct {
    u8 pad0[0x2C];
    u8 f2C;
} B_006AF570;
typedef struct {
    u8 pad0[0x30];
    B_006AF570 *f30;
    u8 pad34[0x54 - 0x34];
    void *f54;
} G_006AF570;
extern G_006AF570 *D_L39_0024D860;

/* localdecomp:start func_L39_006ACC88 */
typedef struct {
    u8 pad0[0xD8];
    void (*fD8)(void *, f32, f32);
} VT_006AF5D8;
typedef struct {
    u8 pad0[0x60];
    VT_006AF5D8 *vt;
} OBJ_006AF5D8;
extern s32 func_L39_00688350(void *, s32);
extern s32 func_L39_00685798(s32, s32, s32);
extern void func_L39_006ACE80(void *);
extern void func_L39_006ACE58(void *);
extern u8 D_001A5EC4 __attribute__((section(".data")));
typedef struct {
    char _p0[0x284];
    s32 f284;
} G_006AF5D8;
__asm__(".extern D_L39_00247A74_006ACC88, 16");
extern G_006AF5D8 *D_L39_00247A74_006ACC88;
__asm__(".extern D_001DD4EC_sda, 4");
extern f32 D_001DD4EC_sda;

s32 func_L39_006ACC88(u8 *self, s32 msg) {
    OBJ_006AF5D8 *obj;
    f32 lim;

    if (func_L39_00688350(self, msg) != 0) {
        return 1;
    }
    if (msg == 8) {
        func_L39_00685798(4, 0, 0);
        D_L39_0024D860->f30->f2C = 1;
        D_001A5EC4 = 1;
        D_L39_00247A74_006ACC88->f284 = 2;
        return 1;
    } else if (msg == 6) {
        func_L39_00685798(0x17, 0, 0);
        func_L39_006ACE80(self);
        func_L39_006ACE58(self);
        D_L39_00247A74_006ACC88->f284 = 0x2C;
        return 1;
    } else if (msg == 1 || msg == 14) {
        *(f32 *)(self + 0x2A8) += 0.03f;
        if (*(f32 *)(self + 0x2A8) > 0.0f) {
            *(f32 *)(self + 0x2A8) = 0.0f;
        }
        obj = *(OBJ_006AF5D8 **)(self + 0x114);
        obj->vt->fD8(obj, 0.0f, *(f32 *)(self + 0x2A8));
        return 1;
    } else if (msg == 2 || msg == 15) {
        if (*(f32 *)(self + 0x2A8) < -50.0f) {
            *(f32 *)(self + 0x2A8) = -50.0f;
        } else {
            lim = D_001DD4EC_sda;
            *(f32 *)(self + 0x2A8) -= 0.03f;
            if (*(f32 *)(self + 0x2A8) < lim) {
                *(f32 *)(self + 0x2A8) = lim;
            }
            obj = *(OBJ_006AF5D8 **)(self + 0x114);
            obj->vt->fD8(obj, 0.0f, *(f32 *)(self + 0x2A8));
        }
        return 1;
    } else {
        if (msg == 5) {
            return 1;
        }
        return 0;
    }
}
/* localdecomp:end func_L39_006ACC88 */
