#include "common.h"

/* NTSC-U counterpart of func_L03_003B5EF8 (src/levels/shared/L03_003B5C78.c) */
/* localdecomp:start func_L03_003B4310 */
#include "vu0.h"

typedef struct { u8 pad[0x18]; u8 *hit; } Collision_003B4310;
typedef struct {
    vu0_v4 end;
    vu0_v4 start;
    f32 speed;
    s32 kind;
    s32 x28;
    void *x2C;
    s32 joint;
    s32 x34;
    f32 x38;
    f32 x3C;
} State_003B4310;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x4];
    u8 *x24;
    u8 pad28[0x4];
    f32 scale;
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 pad36[0x32];
    State_003B4310 *state;
    u8 pad6C[0x2C];
    s32 x98;
    u8 pad9C[0x1C];
    void *owner;
} Obj_003B4310;
extern Collision_003B4310 D_L03_001E9280[];
extern f32 D_L03_001DEA48_003B4310;
__asm__(".extern D_L03_001DEA48_003B4310, 4");
extern f32 D_L03_001DEA4C_003B4310;
__asm__(".extern D_L03_001DEA4C_003B4310, 4");
extern s32 D_L03_001E1E48;
extern f32 D_L03_001DEA3C_003B4310;
__asm__(".extern D_L03_001DEA3C_003B4310, 4");
extern f32 D_L03_001DEA40_003B4310;
__asm__(".extern D_L03_001DEA40_003B4310, 4");
extern s32 D_L03_001DEA38;
__asm__(".extern D_L03_001DEA38, 4");
extern void func_L03_003B4788(void);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L03_0034A658(u8 *, s32, s32, f32, s32, void *);

u8 *func_L03_003B4310(u8 *self, s32 joint, s32 kind, f32 speed) {
    vu0_v4 start, end, delta, point;
    u8 collision[0x30];
    u8 *owner = *(u8 **)(self + 0x68);
    Obj_003B4310 *object;
    State_003B4310 *state;

    func_003BDA38(*(void **)owner, joint, &start);
    func_003BDA38(*(void **)owner, joint + 0x20, &end);
    vec_sub_ba(&delta, &end, &start);
    func_00388830(&delta, &delta, D_L03_001DEA48_003B4310);
    vec_add_ab(&point, &start, &delta);
    func_L01_00443610(collision, self, 0, 0.0f);
    *(u16 *)(collision + 0x1A) = *(u16 *)(self + 0xAA);
    if (func_003CE740(&start, &point, 0, self, collision)) {
        if (D_L03_001E9280->hit && *(s16 *)(D_L03_001E9280->hit + 0xAA) == 0x1C06)
            return 0;
        if (kind == 0 || kind == 3 || kind == 6) {
            u8 *hit = D_L03_001E9280->hit;
            if (hit && *(s16 *)(hit + 0xAA) == 0x1C04) {
                s32 hit_kind = *(s32 *)(*(u8 **)(hit + 0x68) + 0x24);
                if (hit_kind == 0 || hit_kind == 3 || hit_kind == 6) return 0;
            }
        }
    }
    object = (Obj_003B4310 *)func_003BCFB0(0x1C04, 0x80);
    if (object) {
        object->b30 = 0xFF;
        object->b31 = 1;
        object->h32 = 0x40;
        object->scale *= D_L03_001DEA4C_003B4310;
        object->owner = self;
        state = object->state;
        if (kind == 0 || kind == 3 || kind == 6) {
            object->b31 = 0;
            object->h34 |= 1;
        } else {
            object->b31 = 1;
            object->h34 &= 0xFFFE;
        }
        object->x98 = *(s32 *)(object->x24 + 0x10);
        state->kind = kind;
        state->speed = speed * 0.016666668f;
        state->joint = joint;
        state->x38 = D_L03_001DEA40_003B4310;
        state->x3C = D_L03_001DEA3C_003B4310;
        state->x28 = 0;
        state->x34 = 0;
        state->start = start;
        state->end = end;
        state->x2C = *(void **)owner;
        object->pos = state->start;
    }
    if (D_L03_001DEA38 == 0) {
        D_L03_001DEA38 = 1;
        func_L03_0034A658((u8 *)&D_L03_001E1E48, 0x1E, 0x14, 2.1f, 2, func_L03_003B4788);
    }
    return (u8 *)object;
}
/* localdecomp:end func_L03_003B4310 */
