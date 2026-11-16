#include "common.h"

/* NTSC-U counterpart of func_L01_0039D938 (src/levels/shared/L01_00396B78.c) */
#include "vu0.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_0039C418 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1c[0xc];
    f32 height;
} Collision_0039D938;
extern Collision_0039D938 D_L01_001EAA80_0039C418;
extern f32 D_L01_001EAAA8_0039C418[];
void func_L01_0039C418(u8 *object)
{
    extern s32 func_L01_00448E90(void *);
    extern void func_L01_00441FB8(void *, s32, s32);
    extern void func_L01_00449720(void *, void *, void *, void *, void *, void *);
    extern void func_003BFD10(Vec4 *, Vec4 *, Vec4 *, f32);
    extern s32 func_003CE740(Vec4 *, s32 *, s32, s32, s32);
    extern s32 func_003BF5E0(void *);
    extern s32 func_003BF7E8(void *);
    extern void func_L01_004498A0(void *, void *, void *, void *, void *, void *);
    Vec4 bottom, top, zero;
    u8 *state = *(u8 **)(object + 0x68);
    Vec4 *position = (Vec4 *)(object + 0x10);
    s32 collided = 0;
    f32 ground;
    if (!func_L01_00448E90(position)) {
        func_L01_00441FB8(object, 5, -1);
        return;
    }
    if (*(void **)(state + 0xc)) {
        qzero(&zero);
        func_L01_00449720(object, *(void **)(state + 0xc), state + 0x60, &zero, position, &zero);
    }
    bottom = *position;
    func_003BFD10(position, &bottom, &bottom, -0.5f);
    top = bottom;
    func_003BFD10(position, &top, &top, 1.5f);
    if (func_003CE740(&bottom, (s32 *)&top, 2, (s32)object, 0)) {
        collided = 1;
        ground = D_L01_001EAAA8_0039C418[0];
    } else {
        ground = top.v[2];
    }
    if (collided && D_L01_001EAA80_0039C418.object) {
        if (func_003BF5E0(D_L01_001EAA80_0039C418.object)) {
            *(f32 *)(state + 0x10) = *(f32 *)(D_L01_001EAA80_0039C418.object + 0x10);
            *(f32 *)(object + 0x10) = *(f32 *)(state + 0x10);
            *(f32 *)(state + 0x14) = *(f32 *)(D_L01_001EAA80_0039C418.object + 0x14);
            *(f32 *)(object + 0x14) = *(f32 *)(state + 0x14);
            *(f32 *)(object + 0x18) = D_L01_001EAA80_0039C418.height;
            *(Vec4 *)(state + 0x10) = *(Vec4 *)(object + 0x10);
            func_003BFD10((Vec4 *)(object + 0x10), (Vec4 *)(state + 0x10), (Vec4 *)(state + 0x10), -0.5f);
        } else if (!*(void **)(state + 0xc) && func_003BF7E8(D_L01_001EAA80_0039C418.object)) {
            void *hit = D_L01_001EAA80_0039C418.object;
            *(void **)(state + 0xc) = hit;
            func_L01_004498A0(object, hit, object + 0x10, object + 0xf0, state + 0x60, &zero);
        }
    }
    if (*(f32 *)(object + 0x18) <= ground) {
        *(f32 *)(object + 0x18) = ground;
        object[0xbc] = 0;
        *(s32 *)(state + 0x40) = 0;
    } else {
        object[0xbc] = 1;
        if (*(void **)(state + 0xc)) *(f32 *)(state + 0x68) -= *(f32 *)(state + 0x40);
        else *(f32 *)(object + 0x18) -= *(f32 *)(state + 0x40);
        *(f32 *)(state + 0x40) += 0.0027222224f;
        *(f32 *)(state + 0x40) = *(f32 *)(state + 0x40) > 0.3f ? 0.3f : *(f32 *)(state + 0x40);
    }
}
/* localdecomp:end func_L01_0039C418 */
