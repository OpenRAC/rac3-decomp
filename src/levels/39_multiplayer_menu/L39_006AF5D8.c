#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

/* declared by functions of L39_006AF570.c, which this file was cut from */
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
extern G_006AF570 *D_L39_0024D760;

/* localdecomp:start func_L39_006AF5D8 */
typedef struct {
    u8 pad0[0xD8];
    void (*fD8)(void *, f32, f32);
} VT_006AF5D8;
typedef struct {
    u8 pad0[0x60];
    VT_006AF5D8 *vt;
} OBJ_006AF5D8;
extern s32 func_L39_0068AEF8(void *, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern void func_L39_006AF7D0(void *);
extern void func_L39_006AF7A8(void *);
extern u8 D_001A5D44 __attribute__((section(".data")));
typedef struct {
    char _p0[0x284];
    s32 f284;
} G_006AF5D8;
__asm__(".extern D_L39_00247914, 16");
extern G_006AF5D8 *D_L39_00247914;
__asm__(".extern D_001DD524_sda, 4");
extern f32 D_001DD524_sda;

s32 func_L39_006AF5D8(u8 *self, s32 msg) {
    OBJ_006AF5D8 *obj;
    f32 lim;

    if (func_L39_0068AEF8(self, msg) != 0) {
        return 1;
    }
    if (msg == 8) {
        func_L39_00688340(4, 0, 0);
        D_L39_0024D760->f30->f2C = 1;
        D_001A5D44 = 1;
        D_L39_00247914->f284 = 2;
        return 1;
    } else if (msg == 6) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_006AF7D0(self);
        func_L39_006AF7A8(self);
        D_L39_00247914->f284 = 0x2C;
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
            lim = D_001DD524_sda;
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
/* localdecomp:end func_L39_006AF5D8 */
