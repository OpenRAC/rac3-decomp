#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D3938);

/* localdecomp:start func_L07_003D41D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D41D8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern u32 D_L07_001DE7B8[2];
__asm__(".extern D_L07_001DE7B8, 8");

u8 *func_L07_003D41D8(void *owner, V4_003D41D8 *pos, f32 *dir, u8 kind, f32 speed) {
    u8 *m = func_003C24B0(0x1C81, 0x80);
    u8 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(void **)(m + 0xB8) = owner;
        m[0x20] = 0;
        pv = *(u8 **)(m + 0x68);
        func_L01_0044A7D0(m);
        *(V4_003D41D8 *)(m + 0x10) = *pos;
        *(V4_003D41D8 *)(pv + 0x10) = *(V4_003D41D8 *)dir;
        *(f32 *)(pv + 0x8) = func_0038CEA8(dir);
        *(f32 *)(pv + 0x4) = speed;
        pv[0xC] = kind;
        func_L01_004450F0(m, 1, -1);
        *(s32 *)pv = 0x53;
        *(u16 *)(m + 0x34) |= 0x100;
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF8) = func_0038D160(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(dir), dir[2]);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.25f;
        func_0038CC88(pv + 0x30, D_L07_001DE7B8, 0x10);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L07_003D41D8 */

/* localdecomp:start func_L07_003D4330 */
#include "vu0.h"
typedef struct { u8 pad[0xC]; vu0_v4 *owner; } Link_003D4330;
typedef struct { u8 pad[0x68]; Link_003D4330 *link; } State_003D4330;
typedef struct { u8 pad[0xB8]; State_003D4330 *state; } Obj_003D4330;
typedef struct { u8 pad[0xC]; u8 flags; u8 padD[0x13]; vu0_v4 pos; } Out_003D4330;
extern vu0_v4 D_L07_001E8C20;
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L04_00455AF8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_00382538(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
s32 func_L07_003D4330(Obj_003D4330 *obj, Out_003D4330 *out) {
    vu0_v4 pos, delta, best, offset;
    vu0_v4 *origin;
    u8 *target;
    s32 i;
    f32 height;
    origin = obj->state->link->owner;
    if (out->flags & 1) {
        pos = *origin;
        if (func_L01_0040E570((u8 *)obj->state + 0x10, &pos) > 4.0f) {
            pos.z += 0.5f;
            if (func_L04_00455AF8(&pos) >= origin->z + 64.0f) {
                pos.z = func_003C3D30(&pos, 0, 0, 0.0f);
                out->pos = pos;
                out->pos.z += 0.1f;
                return 1;
            }
        }
    }
    best.z = -1.0f;
    i = 0; do {
        target = *(u8 **)((u8 *)origin + 0x10);
        if (target) {
            f32 distance, angle;
            func_0038CF68(&offset, target + 0xC0, -4.0f);
            distance = func_003824E0(0.0f, 15.0f);
            angle = func_0038DAB8(*(f32 *)(target + 0xF8), func_003824E0(-0.7853981853f, 0.7853981853f));
            pos.x = func_0038D098(angle) * distance;
            pos.y = func_0038D0B0(angle) * distance;
            pos.z = 0.0f;
            vec_add_ba(&pos, &offset, &pos);
            vec_add_ab(&pos, origin, &pos);
        } else {
            f32 angle = func_00382538();
            pos.x = func_0038D098(angle) * 5.0f;
            pos.y = func_0038D0B0(angle) * 5.0f;
            pos.z = 0.0f;
            vec_add_ab(&pos, &pos, origin);
        }
        if (func_L01_0040E570((u8 *)obj->state + 0x10, &pos) < 4.0f) continue;
        if (func_003D3CB0(origin, &pos, 2, 0, 0)) {
            vec_sub_ab(&delta, &pos, origin);
            func_0038CF68(&pos, &delta, -0.8f);
            vec_add_ab(&pos, &pos, &D_L07_001E8C20);
        }
        height = func_003C3D30(&pos, 0, 0, 0.0f);
        pos.z = height;
        if (origin->z - height > 2.5f && best.z < height) best = pos;
        out->pos = pos;
        out->pos.z += 0.1f;
        return 1;
    } while (++i < 8);
    if (best.z >= 0.0f) {
        out->pos = best;
        out->pos.z += 0.1f;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003D4330 */
