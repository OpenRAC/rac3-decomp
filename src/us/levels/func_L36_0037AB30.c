#include "common.h"

/* NTSC-U counterpart of func_L36_0037BDF0 (src/levels/36_vidcomic_1_special_edition/L36_0037BDF0.c) */
#include "vu0.h"

/* localdecomp:start func_L36_0037AB30 */
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } Mover_37BDF0;
typedef struct { u8 pad[0x18]; u8 kind, count; u16 id; u8 tail[0x14]; } Hit_37BDF0;
typedef struct { vu0_v4 normal; vu0_v4 pad; vu0_v4 offset; } Contact_37BDF0;
typedef struct { f32 r,g,b,zero; vu0_v4 pos; } Light_37BDF0;
extern Contact_37BDF0 D_L36_001E9560_0037AB30[];
extern Light_37BDF0 D_L36_001F0580_0037AB30[];
extern f32 func_00388770(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00421FE0(s32);
extern void func_L01_0037B650(void *);
extern void func_003BD360(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_L01_00421F08(void *, f32, f32, f32, f32, f32);
extern s32 func_003894E8(void *, f32);
extern void func_L01_004026A0(void *, u8 *);
extern void func_L36_0037B5C0(u8 *);
extern void func_L36_0037B780(u8 *, vu0_v4 *, vu0_v4 *);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_0037B618(void);
extern void func_L01_0037B5E0(void *);
extern void func_L36_0037B480(u8 *, s32);
extern s32 func_00388398(void *);
void func_L36_0037AB30(u8 *a0) {
    vu0_v4 previous, temp, velocity;
    Hit_37BDF0 hit;
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i;
    f32 length;
    Mover_37BDF0 *m = (Mover_37BDF0 *)a0;

    switch (a0[0x20]) {
    case 0:
        previous = m->pos;
        length = func_00388770(s);
        vec_add_ab(&m->pos, s, &m->pos);
        *(f32 *)(s + 0x40) = func_00389380(*(f32 *)(s + 0x40), 0.58177644f);
        func_00388830(s + 0x10, s + 0x10, func_00388978(*(f32 *)(s + 0x40)) * 0.05f);
        func_00388830(s + 0x20, s + 0x20, func_00388978(*(f32 *)(s + 0x40)) * 0.05f);
        vec_add_ab(s, s + 0x10, s);
        vec_add_ab(s, s + 0x20, s);
        func_00388830(s, s, length);
        func_00388830(s, s, length * 0.800000012f);
        if (m->pos.x < 2.0f || m->pos.x > 1021.0f ||
            m->pos.y < 2.0f || m->pos.y > 1021.0f ||
            m->pos.z < 2.0f || m->pos.z > 1021.0f) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00421FE0(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037B650(a0);
            func_003BD360(a0);
            break;
        }
        (*(s32 *)(s + 0x34))++;
        if (func_003CE740(&previous, &m->pos, 0, a0, 0)) {
            m->pos = D_L36_001E9560_0037AB30[0].normal;
            temp = D_L36_001E9560_0037AB30[0].offset;
            func_00388830(&temp, &temp, 0.5f);
            vec_add_ab(&m->pos, &m->pos, &temp);
            *(s32 *)(s + 0x34) = 0;
            func_L01_00441FB8(a0, 1, -1);
            velocity = *(vu0_v4 *)s;
            func_003886E8(&velocity, &velocity, 3.0f);
            velocity.w = 5627.925f;
            func_L01_00443628(&hit, a0, 0x10000, &velocity, 5.0f);
            hit.count = 1;
            hit.id = *(u16 *)(a0 + 0xAA);
            hit.kind = 0;
            if (*(s32 *)((u8 *)D_L36_001E9560_0037AB30 - 8) != 0) {
                if (*(s32 *)((u8 *)D_L36_001E9560_0037AB30 - 8) != *(s32 *)(s + 0x38)) {
                    func_003CF790(D_L36_001E9560_0037AB30, 0, a0, &hit, 1.0f);
                }
            } else {
                func_003CF790(D_L36_001E9560_0037AB30, 0, a0, &hit, 1.0f);
            }
        }
        if (*(s32 *)(s + 0x48) == -1) {
            *(s32 *)(s + 0x48) = func_L01_00421F08(&m->pos, 5.0f, 0.0f, 0.5f, 0.25f, 0.125f);
        } else {
            Light_37BDF0 *light = &D_L36_001F0580_0037AB30[*(s32 *)(s + 0x48)];
            light->pos = m->pos;
            light->pos.w = 5.0f;
            light->r = 0.5f;
            light->g = 0.25f;
            light->b = 0.125f;
            light->zero = 0.0f;
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_003894E8(&temp, 96.0f) > 0) {
            func_L01_004026A0(func_L36_0037B5C0, a0);
            velocity = m->pos;
            func_L36_0037B780(a0, &velocity, &previous);
        }
        if (*(s32 *)(s + 0x34) > 120) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    case 1:
        for (i = 0; i < 28; i++) {
            temp.x = m->pos.x + func_0037E250(-0.5f, 0.5f);
            temp.y = m->pos.y + func_0037E250(-0.5f, 0.5f);
            temp.z = m->pos.z + func_0037E250(-0.5f, 0.5f);
            ((vu0_v4 *)(s + 0x60))[i] = temp;
            ((f32 *)(s + 0x220))[i] = func_0037E250(0.0872664675f, 0.159988523f);
        }
        if (!func_L01_0037B618()) func_L01_0037B5E0(a0);
        func_L01_00441FB8(a0, 2, -1);
        break;
    case 2:
        if (++*(s32 *)(s + 0x34) > 3000) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_00441FB8(a0, 4, -1);
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_003894E8(&temp, 96.0f) > 0) func_L36_0037B480(a0, 0);
        break;
    case 3:
        if (++*(s32 *)(s + 0x34) > 3000) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_00441FB8(a0, 4, -1);
        }
        if (func_00388398(s + 0x58)) {
            func_L01_00441FB8(a0, 2, -1);
            *(s32 *)(s + 0x58) = 30;
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_003894E8(&temp, 96.0f) > 0) func_L36_0037B480(a0, 1);
        break;
    case 4:
        if (++*(s32 *)(s + 0x34) > 20) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00421FE0(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037B650(a0);
            func_003BD360(a0);
        }
        break;
    }
}

/* localdecomp:end func_L36_0037AB30 */
