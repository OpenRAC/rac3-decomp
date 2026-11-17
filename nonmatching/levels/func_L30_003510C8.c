/* PAL near miss (Codex wave 7): near miss: 195 words differ with the file's flags.
 * Worker's note: 38 diff: build/codex/w341/func_L30_003510C8.v2.log with experimental divs 2,0. Float allocation/scheduling and VU load interleaving remain; one complete VU block with memory operands and clobbers retained. Fixed flags do not enable existing j helpers; no ...
 */
#include "common.h"
/* localdecomp:start func_L30_003510C8 */
#include "vu0.h"
typedef struct { u8 pad[0x18]; f32 angle; } Data_003510C8;
typedef struct { u8 pad[0x10]; vu0_v4 pos; vu0_v4 prev; u8 pad30[0xC]; f32 scale; u8 pad40[0x28]; Data_003510C8 *data; } Object_003510C8;
typedef struct { Object_003510C8 *object; s32 active; u16 duration, flags; s32 padC; f32 x, z, phase; } State_003510C8;
extern f32 D_L30_001DD898, D_L30_001DD864, D_L30_001DD8A0, D_L30_001DD8A4;
extern f32 D_L30_001DD860, D_L30_001DD874, D_L30_001DD8E8, D_L30_001DD8EC;
extern f32 D_L30_001DD8E4, D_L30_001DD8E0, D_L30_001DD884, D_L30_001DD8A8;
extern f32 D_L30_001DD880, D_L30_001DD890;
extern s32 D_L30_001DD87C, D_L30_001DD878;
extern s32 D_L30_001E9018[];
extern s16 D_L30_001E1382[];
extern s16 D_L30_001E1380_003510C8;
extern s32 D_L30_001E138C[];
__asm__(".extern D_L30_001DD898, 4");
__asm__(".extern D_L30_001DD864, 4");
__asm__(".extern D_L30_001DD8A0, 4");
__asm__(".extern D_L30_001DD8A4, 4");
__asm__(".extern D_L30_001DD860, 4");
__asm__(".extern D_L30_001DD874, 4");
__asm__(".extern D_L30_001DD8E8, 4");
__asm__(".extern D_L30_001DD8EC, 4");
__asm__(".extern D_L30_001DD8E4, 4");
__asm__(".extern D_L30_001DD8E0, 4");
__asm__(".extern D_L30_001DD884, 4");
__asm__(".extern D_L30_001DD8A8, 4");
__asm__(".extern D_L30_001DD880, 4");
__asm__(".extern D_L30_001DD890, 4");
__asm__(".extern D_L30_001DD87C, 4");
__asm__(".extern D_L30_001DD878, 4");
__asm__(".extern D_L30_001E1380_003510C8, 2");
void func_L30_003510C8(u8 *arg0, u8 *arg1) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern Object_003510C8 *func_L30_00442950(void *, void *, s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    State_003510C8 *st = (State_003510C8 *)arg1;
    Object_003510C8 *obj;
    Data_003510C8 *data;
    Object_003510C8 *spawn;
    vu0_v4 pos, vel, offset;
    f32 angle, speed, progress, initialAngle, alpha;
    s32 active;
    vu0_v4 *position;
    if (!st) return;
    obj = st->object;
    active = st->active;
    data = obj->data;
    if (!obj || !active) return;
    if (st->flags & 1) {
        initialAngle = func_0038DB48(func_003824E0(0.0f, 6.283185482f));
        *(vu0_v4 *)(arg0 + 0x10) = obj->pos;
        offset.x = func_0038D098(initialAngle) * D_L30_001DD898;
        offset.z = func_0038D0B0(initialAngle) * D_L30_001DD898;
        offset.y = 0.0f;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*(vu0_v4 *)(arg0 + 0x10)) : "m"(*(vu0_v4 *)(arg0 + 0x10)), "m"(offset) : "vf1", "vf2");
        angle = func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD864, D_L30_001DD864)), data->angle);
        st->phase = func_003824E0(0.0f, 1.0f);
        speed = func_003824E0(D_L30_001DD8A0, D_L30_001DD8A4);
        vel.x = func_0038D098(angle) * speed;
        vel.z = func_0038D0B0(angle) * speed;
        vel.y = 0.0f;
        st->x = vel.x;
        st->z = vel.z;
        st->duration += (s32)(5.0f / speed);
        *(s16 *)(arg0 + 0xA) = st->duration;
    }
    position = (vu0_v4 *)(arg0 + 0x10);
    progress = func_L03_0034B148(*(s16 *)(arg0 + 0xA), (s16)st->duration, 0.0f);
    pos = *position;
    pos.x += st->x;
    pos.z += st->z;
    if ((D_L30_001DF2C0 & 15) == (((s32)arg0 >> 8) & 15)) {
        if (func_003D3CB0(position, &pos, 1, obj, 0) && D_L30_001E9018[0]) {
            qzero(&vel);
            vel.x = st->x;
            vel.z = st->z;
            func_L30_0034CB68(st->object, &vel, 0, -1, position, 0, D_L30_001DD860, D_L30_001DD874);
        }
    }
    *position = pos;
    st->phase += func_003C4088(D_L30_001DD8E8, D_L30_001DD8EC, progress);
    if (st->phase >= 1.0f) {
        angle = func_0038DB48(func_003824E0(0.0f, 6.283185482f));
        speed = func_003824E0(0.0f, func_003C4088(D_L30_001DD8E4, D_L30_001DD8E0, progress));
        st->phase -= 1.0f;
        spawn = func_L30_00442950(obj, &D_L30_001E1380, func_00382498(D_L30_001E1382[0], D_L30_001E1380_003510C8), D_L30_001E138C[0]);
        if (spawn) {
            vel.x = func_0038D098(angle) * speed;
            vel.z = func_0038D0B0(angle) * speed;
            vel.y = 0.0f;
            spawn->pos.x = vel.x + *(f32 *)(arg0 + 0x10);
            spawn->pos.y = *(f32 *)(arg0 + 0x14);
            spawn->pos.z = vel.z + *(f32 *)(arg0 + 0x18);
            spawn->prev.x = spawn->pos.x;
            spawn->prev.y = spawn->pos.y;
            spawn->prev.z = spawn->pos.z;
            spawn->scale = st->x * D_L30_001DD8A8;
        }
    }
    st->z += D_L30_001DD884;
    *(s32 *)(arg0 + 4) = func_0038DBD8(D_L30_001DD87C, D_L30_001DD878, (f32)*(s16 *)(arg0 + 0xA) / (f32)(s16)st->duration);
    alpha = func_L03_0034B148((s16)st->duration - *(s16 *)(arg0 + 0xA), (s16)st->duration, D_L30_001DD880) * 128.0f;
    arg0[8] = 0;
    *(f32 *)(arg0 + 0xC) = D_L30_001DD890;
    *(s32 *)(arg0 + 4) = (*(s32 *)(arg0 + 4) & 0xFFFFFF) + ((s32)alpha << 24);
}
/* localdecomp:end func_L30_003510C8 */
