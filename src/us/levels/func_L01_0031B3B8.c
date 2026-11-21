#include "common.h"

/* NTSC-U counterpart of func_L01_0031B810 (src/levels/shared/L01_00314158.c): func_L01_00466F98 gets 4 in place of 3 and the velocity scale is 1/15 in place of 0.08 (60 Hz) */
/* localdecomp:start func_L01_0031B3B8 */
#include "vu0.h"
extern u8 D_L01_001D66B0_0031B3B8[] __attribute__((section(".sdata")));
extern u8 *D_L01_001EAA98[];
typedef struct { u8 pad0[0x18]; u8 *object; u8 pad1C[4]; vu0_v4 position; } Hit_0031B3B8;
extern Hit_0031B3B8 D_L01_001EAA80;
extern f32 func_0037E2A8(void);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00388830(f32 *, f32 *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L01_0031B820(u8 *);
extern void func_L01_004026A0_0031B3B8(void (*)(u8 *), u8 *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_0031BCA8(void *, s32);
extern void func_L01_00452F40(void *, s32);
extern void func_003BD360(u8 *);
void func_L01_0031B3B8(u8 *obj) {
    vu0_v4 old, velocity;
    u8 info[0x30];
    vu0_v4 back, acceleration;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 power = *(f32 *)(state + 0x3C);
    vu0_v4 *point;
    s32 hit;
    s32 rotation;
    u8 *owner;
    *(f32 *)(state + 0x38) += 1.0f;
    if (*(f32 *)(state + 0x38) > 2.0f) old = *(vu0_v4 *)(state + 0x10);
    else old = *(vu0_v4 *)state;
    rotation = (s32)func_0037E2A8();
    func_L01_00466F98(state + 0x10, D_L01_001D66B0_0031B3B8, 4, 96, 0x406080, rotation, 168000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    if (*(f32 *)(state + 0x38) < 50.0f) {
        *(f32 *)(state + 0x34) += *(f32 *)(state + 0x44);
        func_00388830((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
        func_00388830((f32 *)&velocity, (f32 *)(state + 0x20), 0.06666667f);
        func_L01_00443628(info, obj, 0x10001, &velocity, power);
        *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
        vec_add_ba(state + 0x10, state, state + 0x10);
        func_00388830((f32 *)&back, (f32 *)(state + 0x20), -*(f32 *)(state + 0x44));
        vec_add_ab(&back, &back, state + 0x10);
        owner = *(u8 **)(obj + 0xB8);
        func_L01_004C76B8();
        hit = func_003CE740(state + 0x10, &old, 16, owner, info);
        if (hit) {
            u8 *contact = D_L01_001EAA98[0];
            if (contact && *(s16 *)(contact + 0xAA) == 0x186D && contact[0x20] != 2 && contact[0x20] != 5) contact[0x20] = 4;
        }
        func_L01_004C76F0();
        if (hit) {
            Hit_0031B3B8 *collision = &D_L01_001EAA80;
            if (collision->object == *(void **)(obj + 0xB8)) goto first_continue;
            {
                point = &collision->position;
                *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                if (!func_L01_00452F60(obj)) {
                    func_L01_0031BCA8(point, 20);
                    func_L01_00452F40(obj, 1);
                }
                func_003BD360(obj);
                return;
            }
        }
    first_continue:
        func_L01_004026A0_0031B3B8(func_L01_0031B820, obj);
    } else if (*(f32 *)(state + 0x38) >= 50.0f && *(f32 *)(state + 0x38) < 180.0f) {
        if (*(f32 *)(state + 0x44) < func_00388800(state, state + 0x10)) {
            *(f32 *)(state + 0x34) += *(f32 *)(state + 0x44);
            func_00388830((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
            func_00388830((f32 *)&velocity, (f32 *)(state + 0x20), 0.06666667f);
            func_L01_00443628(info, obj, 0x10001, &velocity, power);
            *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
            vec_add_ba(state + 0x10, state, state + 0x10);
            func_00388830((f32 *)&back, (f32 *)(state + 0x20), -*(f32 *)(state + 0x44));
            vec_add_ab(&back, &back, state + 0x10);
            func_L01_004C76B8();
            hit = func_003CE740(state + 0x10, &old, 16, obj, info);
            if (hit) {
                u8 *contact = D_L01_001EAA98[0];
                if (contact && *(s16 *)(contact + 0xAA) == 0x186D && contact[0x20] != 2 && contact[0x20] != 5) contact[0x20] = 4;
            }
            func_L01_004C76F0();
            {
                u8 *other;
                if (hit) {
                    Hit_0031B3B8 *collision = &D_L01_001EAA80;
                    other = collision->object;
                    if (other != *(u8 **)(obj + 0xB8) && (other == 0 || *(s16 *)(other + 0xAA) != 0x1625)) {
                        point = &collision->position;
                        *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                        {
                            if (!func_L01_00452F60(obj)) {
                                func_L01_0031BCA8(point, 20);
                                func_L01_00452F40(obj, 1);
                            }
                            func_003BD360(obj);
                            return;
                        }
                    }
                }
            }
            func_00388830((f32 *)&acceleration, (f32 *)(state + 0x20), *(f32 *)(state + 0x44));
            vec_add_ab(state, state, &acceleration);
            func_L01_004026A0_0031B3B8(func_L01_0031B820, obj);
        }
    } else {
        func_L01_0031BCA8(state + 0x10, 20);
        func_003BD360(obj);
    }
    return;
}
/* localdecomp:end func_L01_0031B3B8 */
