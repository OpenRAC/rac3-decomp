/* PAL draft (2026-11-21, Promises), from the NTSC-U draft of func_L03_003B4310 with PAL names and
 * PAL's constants (0.020000001f, 0x19/0x11). It needs split addresses and -mvu0-use-vf0-vf2 (a %hi
 * of D_L03_001E9200 shared across a branch, vu0.h's helpers), which its file
 * src/levels/shared/L03_003B5C78.c has only with the cut at 0x3B6180 (LV-R3, 2026-11-22; recipe in
 * nonmatching/README.md, not committed). Without the cut it does not compile with the file's line
 * (tools/check.py, level 03); with the cut, 6 differences (tools/check.py, level 03).
 * Left: in the last call retail sets
 * up func_L03_003B6370's %lo and 2.1f before the flag store and D_L03_001E1DC8's %hi after it;
 * ours has the %hi first and the %lo after the store. The flag store first, then the callback and
 * 2.1f in locals, gives 6 (was 7 with the call written directly); all 24 orders of the flag
 * store, callback, 2.1f and table locals give 6 to 8; a function-pointer type for the callback,
 * void * for the table and an explicit return give 6. Earlier: three prototypes (float position),
 * a (void *) cast, the flag store after the call, a struct-typed table, &table[0], !flag (7). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B5EF8 */
typedef int Q_003B5EF8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x18]; u8 *hit; } Collision_003B5EF8;
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
} State_003B5EF8;
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
    State_003B5EF8 *state;
    u8 pad6C[0x2C];
    s32 x98;
    u8 pad9C[0x1C];
    void *owner;
} Obj_003B5EF8;
extern Collision_003B5EF8 D_L03_001E9200[];
extern f32 D_L03_001DEA08_003B5EF8;
__asm__(".extern D_L03_001DEA08_003B5EF8, 4");
extern f32 D_L03_001DEA0C_003B5EF8;
__asm__(".extern D_L03_001DEA0C_003B5EF8, 4");
extern u8 D_L03_001E1DC8_003B6180[];
extern f32 D_L03_001DE9FC_003B6180;
__asm__(".extern D_L03_001DE9FC_003B6180, 4");
extern f32 D_L03_001DEA00_003B6180;
__asm__(".extern D_L03_001DEA00_003B6180, 4");
extern s32 D_L03_001DE9F8_003B5EF8;
__asm__(".extern D_L03_001DE9F8_003B5EF8, 4");
extern void func_L03_003B6370(void);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);

u8 *func_L03_003B5EF8(u8 *self, s32 joint, s32 kind, f32 speed) {
    vu0_v4 start, end, delta, point;
    u8 collision[0x30];
    u8 *owner = *(u8 **)(self + 0x68);
    Obj_003B5EF8 *object;
    State_003B5EF8 *state;

    func_003C2F58(*(void **)owner, joint, &start);
    func_003C2F58(*(void **)owner, joint + 0x20, &end);
    vec_sub_ba(&delta, &end, &start);
    func_0038CF68(&delta, &delta, D_L03_001DEA08_003B5EF8);
    vec_add_ab(&point, &start, &delta);
    func_L01_00446748(collision, self, 0, 0.0f);
    *(u16 *)(collision + 0x1A) = *(u16 *)(self + 0xAA);
    if (func_003D3CB0(&start, &point, 0, self, collision)) {
        if (D_L03_001E9200->hit && *(s16 *)(D_L03_001E9200->hit + 0xAA) == 0x1C06)
            return 0;
        if (kind == 0 || kind == 3 || kind == 6) {
            u8 *hit = D_L03_001E9200->hit;
            if (hit && *(s16 *)(hit + 0xAA) == 0x1C04) {
                s32 hit_kind = *(s32 *)(*(u8 **)(hit + 0x68) + 0x24);
                if (hit_kind == 0 || hit_kind == 3 || hit_kind == 6) return 0;
            }
        }
    }
    object = (Obj_003B5EF8 *)func_003C24B0(0x1C04, 0x80);
    if (object) {
        object->b30 = 0xFF;
        object->b31 = 1;
        object->h32 = 0x40;
        object->scale *= D_L03_001DEA0C_003B5EF8;
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
        state->speed = speed * 0.020000001f;
        state->joint = joint;
        state->x38 = D_L03_001DEA00_003B6180;
        state->x3C = D_L03_001DE9FC_003B6180;
        state->x28 = 0;
        state->x34 = 0;
        state->start = start;
        state->end = end;
        state->x2C = *(void **)owner;
        object->pos = state->start;
    }
    if (D_L03_001DE9F8_003B5EF8 == 0) {
        void *cb;
        f32 pitch;
        D_L03_001DE9F8_003B5EF8 = 1;
        cb = func_L03_003B6370;
        pitch = 2.1f;
        func_L03_0034B218(D_L03_001E1DC8_003B6180, 0x19, 0x11, pitch, 2, cb);
    }
    return (u8 *)object;
}
/* localdecomp:end func_L03_003B5EF8 */
