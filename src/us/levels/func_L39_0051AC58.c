#include "common.h"

/* localdecomp:start func_L39_0051AC58 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    s32 f1C;
    f32 f20;
    s32 f24;
    f32 f28;
    f32 f2C;
} State_L39_0051AC58;

typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[0x0B];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    State_L39_0051AC58 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 bBC;
    u8 padBD[0xD0 - 0xBD];
    f32 vD0[4];
    u8 padE0[0xF0 - 0xE0];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Obj_L39_0051AC58;

extern s32 D_001DF0BC_sda;
extern f32 D_001DF0B8_sda;
__asm__(".extern D_001DF0BC_sda, 4");
__asm__(".extern D_001DF0B8_sda, 4");

extern Obj_L39_0051AC58 *func_003BCFB0(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B25C8_0051AC58(void);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_0019D650(void);
extern void func_003886E8(void *, void *, f32);
extern void func_003C26C8(void *);
extern void func_L01_00438908(void *, s32, s32, s32);

Obj_L39_0051AC58 *func_L39_0051AC58(s32 unused, s128 *pos, f32 *vel) {
    Obj_L39_0051AC58 *obj;
    State_L39_0051AC58 *st;

    obj = func_003BCFB0(0x1AC, 0x80);
    if (obj != 0) {
        obj->b30 = 0x40;
        obj->h32 = 0x20;
        obj->b31 = 1;
        obj->h34 |= 0x1000;
        obj->b20 = 0;
        obj->bBC = 0;
        *(s128 *)&obj->x = *pos;
        st = obj->f68;
        obj->z += func_L39_005B2510(0.2f, 0.7f);
        obj->x += vel[0] * 3.0f;
        obj->y += vel[1] * 3.0f;
        *(s128 *)st = *(s128 *)vel;
        obj->fF4 = func_L39_005B2568(0.17453292f, 0.523598790f);
        obj->fF0 = func_L39_005B2510(0.17453292f, 0.785398185f);
        st->f2C = func_L39_005B2510(200.0f, 370.0f) * 0.0174532924f * 0.0166666675f;
        st->f24 = -1;
        if (func_0019D650() & 1) {
            st->f24 = 1;
            obj->fF4 = -obj->fF4;
        }
        obj->fF8 = func_L39_005B25C8_0051AC58();
        st->f28 = -(func_L39_005B2510(200.0f, 550.0f) * 0.0174532924f * 0.0166666675f);
        st->f10 = func_L39_005B25C8_0051AC58();
        st->f14 = func_L39_005B25C8_0051AC58();
        st->f1C = func_L39_005B24C8((s32)((f32)D_001DF0BC_sda * 0.7f), (s32)((f32)D_001DF0BC_sda * 1.2f));
        obj->f2C = obj->f2C * D_001DF0B8_sda;
        st->f20 = func_L39_005B2510(-1.2f, -0.4f) * 0.0166666675f;
        func_003886E8(obj->vD0, obj->vD0, 0.5f);
        func_003C26C8(obj);
        func_L01_00438908(obj, 0x90, 0x90, 0);
    }
    return obj;
}
/* localdecomp:end func_L39_0051AC58 */
