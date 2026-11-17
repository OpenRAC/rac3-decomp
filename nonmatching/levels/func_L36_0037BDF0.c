/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 398 positional differences with the owner's unchanged
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as flags.
 * The 0xB0 frame agrees; saved-register roles, position-pointer lifetime,
 * VU0 allocation, state-body scheduling and jump-table relocation still differ.
 * The switch states were read from the five retail jump-table entries.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
#include "vu0.h"
typedef struct { u8 pad[0x18]; u8 kind, count; u16 id; u8 tail[0x14]; } Hit_37BDF0;
typedef struct { vu0_v4 normal; vu0_v4 pad; vu0_v4 offset; } Contact_37BDF0;
typedef struct { f32 r,g,b,zero; vu0_v4 pos; } Light_37BDF0;
extern Contact_37BDF0 D_L36_001E9560[];
extern Light_37BDF0 D_L36_001F0580[];
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00424D88(s32);
extern void func_L01_0037C758(void *);
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L36_0037C880(u8 *);
extern void func_L36_0037CA40(u8 *, vu0_v4 *, vu0_v4 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_0037C720(void);
extern void func_L01_0037C6E8(void *);
extern void func_L36_0037C740(u8 *, s32);
extern s32 func_0038CAD0(void *);
void func_L36_0037BDF0(u8 *a0) {
    vu0_v4 previous, temp, velocity;
    Hit_37BDF0 hit;
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i;
    f32 length;
    vu0_v4 *pos = (vu0_v4 *)(a0 + 0x10);
    switch (a0[0x20]) {
    case 0:
        previous = *pos;
        length = func_0038CEA8(s);
        vec_add_ab(pos, s, pos);
        *(f32 *)(s + 0x40) = func_0038DAB8(*(f32 *)(s + 0x40), 0.69813174f);
        func_0038CF68(s + 0x10, s + 0x10, func_0038D0B0(*(f32 *)(s + 0x40)) * 0.05f);
        func_0038CF68(s + 0x20, s + 0x20, func_0038D0B0(*(f32 *)(s + 0x40)) * 0.05f);
        vec_add_ab(s, s + 0x10, s);
        vec_add_ab(s, s + 0x20, s);
        func_0038CF68(s, s, length);
        func_0038CF68(s, s, length * 0.76f);
        if (pos->x < 2.0f || pos->x > 1021.0f ||
            pos->y < 2.0f || pos->y > 1021.0f ||
            pos->z < 2.0f || pos->z > 1021.0f) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00424D88(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037C758(a0);
            func_003C2880(a0);
            break;
        }
        (*(s32 *)(s + 0x34))++;
        if (func_003D3CB0(&previous, pos, 0, a0, 0)) {
            *pos = D_L36_001E9560[0].normal;
            temp = D_L36_001E9560[0].offset;
            func_0038CF68(&temp, &temp, 0.5f);
            vec_add_ab(pos, pos, &temp);
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 1, -1);
            velocity = *(vu0_v4 *)s;
            func_0038CE20(&velocity, &velocity, 3.0f);
            velocity.w = 5627.925f;
            func_L01_00446760(&hit, a0, 0x10000, &velocity, 5.0f);
            hit.count = 1;
            hit.id = *(u16 *)(a0 + 0xAA);
            hit.kind = 0;
            if (*(s32 *)((u8 *)D_L36_001E9560 - 8) == 0 ||
                *(s32 *)((u8 *)D_L36_001E9560 - 8) != *(s32 *)(s + 0x38)) {
                func_003D4D00(D_L36_001E9560, 0, a0, &hit, 1.0f);
            }
        }
        if (*(s32 *)(s + 0x48) == -1) {
            *(s32 *)(s + 0x48) = func_L01_00424CB0(pos, 5.0f, 0.0f, 0.5f, 0.25f, 0.125f);
        } else {
            Light_37BDF0 *light = &D_L36_001F0580[*(s32 *)(s + 0x48)];
            light->pos = *pos;
            light->pos.w = 5.0f;
            light->r = 0.5f;
            light->g = 0.25f;
            light->b = 0.125f;
            light->zero = 0.0f;
        }
        temp = *pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) {
            func_L01_00404A10(func_L36_0037C880, a0);
            velocity = *pos;
            func_L36_0037CA40(a0, &velocity, &previous);
        }
        if (*(s32 *)(s + 0x34) > 100) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 1:
        for (i = 0; i < 28; i++) {
            temp.x = pos->x + func_003824E0(-0.5f, 0.5f);
            temp.y = pos->y + func_003824E0(-0.5f, 0.5f);
            temp.z = pos->z + func_003824E0(-0.5f, 0.5f);
            ((vu0_v4 *)(s + 0x60))[i] = temp;
            ((f32 *)(s + 0x220))[i] = func_003824E0(0.10471976f, 0.19198623f);
        }
        if (!func_L01_0037C720()) func_L01_0037C6E8(a0);
        func_L01_004450F0(a0, 2, -1);
        break;
    case 2:
        if (++*(s32 *)(s + 0x34) > 2500) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 4, -1);
        }
        temp = *pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) func_L36_0037C740(a0, 0);
        break;
    case 3:
        if (++*(s32 *)(s + 0x34) > 2500) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 4, -1);
        }
        if (func_0038CAD0(s + 0x58)) {
            func_L01_004450F0(a0, 2, -1);
            *(s32 *)(s + 0x58) = 25;
        }
        temp = *pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) func_L36_0037C740(a0, 1);
        break;
    case 4:
        if (++*(s32 *)(s + 0x34) > 17) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00424D88(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037C758(a0);
            func_003C2880(a0);
        }
        break;
    }
}
