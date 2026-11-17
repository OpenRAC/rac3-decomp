#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    s32 vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby_003A46C8;

/* localdecomp:start func_L11_003A2CD0 */
#include "vu0.h"
typedef int q_3A2CD0 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE098, 4");
__asm__(".extern D_L11_001DE0A8, 1");
__asm__(".extern D_L11_001DE0B8, 4");
extern f32 D_L11_001DE098;
extern u8 D_L11_001DE0A8;
extern f32 D_L11_001DE0B8;
extern void func_003C6680(void *, void *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, u8 *, s32);
extern void func_003C6990(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L11_003A2CD0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *r;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 d;

    if (v != 0) {
        r = a0 + 0xF0;
        pos = *(vu0_v4 *)(a0 + 0x10);
        rot = *(vu0_v4 *)r;
        if (a0[0x20] == 0) {
            func_003C6680(a0, v + 0x70, 0, 0, &D_L11_001DE098, 0, 0, 0, &D_L11_001DE0B8, &D_L11_001DE0A8, 0);
            func_L01_004450F0(a0, 1, -1);
        }
        func_003C6990(a0, v + 0x70, 0);
        vec_sub_ba(&d, &pos, a0 + 0x10);
        func_003C4DA8(v + 0x30, &d, &rot, r);
    }
}
/* localdecomp:end func_L11_003A2CD0 */

/* localdecomp:start func_L11_003A2DB0 */
#include "vu0.h"

typedef int q_3A2DB0 __attribute__((mode(TI)));

extern s32 D_001A71A4[];
extern u8 *D_L11_0021CB80[];
extern s16 D_L11_002A2730[];
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
__asm__(".extern D_001DE0C8_sda, 4");
extern s32 D_001DE0C8_sda;

extern s32 func_L11_003A41E0(u8 *);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CB00(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L11_003A45D0(u8 *);
extern void func_L11_003A46C8(Moby_003A46C8 *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern s32 func_L11_00433210(u8 *, u8 *);
extern f32 func_L01_00451580(void *);
extern void func_003C5278(void *, void *, void *, f32);
extern f32 func_L01_00451738(s32, void *, s32);
extern f32 func_L01_00451700(s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045CED0(void *, void *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CAD0(s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L05_003BD448(void *, void *, void *, void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L11_003A2DB0(u8 *a0)
{
    vu0_v4 vec;
    vu0_v4 vec2;
    vu0_v4 vec3;
    vu0_v4 vec4;
    vu0_v4 mat[3];
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *p;
    u8 *e;
    f32 d;
    f32 r;
    s32 i;
    s32 idx;
    s32 n;
    s32 k;
    s32 c;
    s32 out[4];

    if (func_L11_003A41E0(a0) != 0) {
        func_003C2880(a0);
        return;
    }
    if (D_001A71A4[0] == 0x31) {
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
        return;
    }
    p = *(u8 **)(a0 + 0x24);
    *(u16 *)(a0 + 0x34) &= 0xFFBE;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(p + 0x10);

    switch (a0[0x95]) {
    case 0:
        if (func_L01_004561E0(a0) != 0) {
            *(u16 *)(v + 0x2D6) = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (*(s16 *)(v + 0x234) == 1) {
            if (((s32 (*)(void *))func_0038CB00)(v + 0x2D6) != 0) {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 5);
                }
                func_L01_004450F0(a0, 6, 2);
                if (*(s32 *)(v + 0x2F0) != -1) {
                    func_L01_004450F0(a0, 4, -1);
                }
                break;
            }
        }
        if (*(s32 *)(v + 0x2D8) == 0) {
            break;
        }
        if (((s32 (*)(void *))func_0038CB00)(v + 0x2D6) == 0) {
            break;
        }
        func_L01_004450F0(a0, 3, 1);
        *(s32 *)(v + 0x2D8) = 0;
        if (*(s32 *)(v + 0x2D0) < 250) {
            *(s32 *)(v + 0x2D0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 5);
            }
            func_L01_004450F0(a0, 6, 2);
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_004450F0(a0, 1, 0);
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 0);
            }
        }
        break;
    case 2:
        if (*(s16 *)(v + 0x234) != 1 && func_L01_004561E0(a0) == 0) {
            func_L01_004450F0(a0, 1, 0);
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 0);
            }
            *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        c = func_L01_00454370(a0, v + 0x160);
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            func_L11_003A45D0(a0);
            func_003C2F58(a0, 1, &vec);
            func_L01_003303B8(&vec, 0, 9, 9, 0xC, 0xC, 0x16, 0, 0.3f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38,
                              0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38, 0);
            func_003C2880(a0);
            return;
        }
        if (c & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_004450F0(a0, 6, 2);
            } else {
                func_L01_004450F0(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        e = D_L11_0021CB80[*(s32 *)(v + 0x2F0)];
        if (func_L11_00433210(a0, e) != 0) {
            func_L01_004450F0(a0, 6, -1);
        }
        vec.z = func_L01_00451580(a0 + 0x10);
        vec2.z = func_L01_00451580(e + 0x10 + (*(s16 *)(v + 0x13A) << 4));
        if (vec.z < vec2.z) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec2.z - vec.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.010000001f) {
                *(f32 *)(v + 0x2DC) -= 0.0016000001f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.080000006f) {
            *(f32 *)(v + 0x2DC) += 0.0012f;
        }
        break;
    case 6:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, 0.0064000003f, 0.060000002f, 0.010053097f, 0.25132743f);
            if (a0[0x21] != 0xFF) {
                func_L01_00445BE0(a0[0x21], 1);
            }
        }
        func_L01_0045CED0(a0, v + 0x220);
        vec.z = func_L01_00451580(a0 + 0x10);
        vec2.z = func_L01_00451580(*(u8 **)(v + 0x230) + 0x10);
        if (vec.z < vec2.z) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec2.z - vec.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.010000001f) {
                *(f32 *)(v + 0x2DC) -= 0.0016000001f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.080000006f) {
            *(f32 *)(v + 0x2DC) += 0.0012f;
        }
        vec_sub_ba(&vec3, v + 0x220, a0 + 0x10);
        d = func_L01_00451738((s32)a0, &vec3, 0);
        if (func_0038CF00(a0 + 0x10, v + 0x220) < 3.0f && d < 0.2617994f &&
            fabs_asm(vec2.z - vec.z) < 2.0f) {
            func_L01_004450F0(a0, 7, -1);
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
        }
        break;
    case 9:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_00443B88(&vec, 0.0f, 0.5f);
            vec_add_ab(v + 0x300, &vec, v + 0x310);
            *(s32 *)(v + 0x320) = func_00382498(0x5A, 0x82);
        }
        func_L01_0045CED0(a0, v + 0x300);
        vec_sub_ba(&vec, a0 + 0x10, v + 0x300);
        d = func_L01_00451738((s32)a0, &vec, 0);
        if (func_0038CF00(a0 + 0x10, v + 0x300) < 3.0f || ((s32 (*)(void *))func_0038CAD0)(v + 0x320) != 0) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 5:
        {
        f32 f5, g5;
        if (func_L01_004561B8(a0) != 0) {
            f5 = func_00382538();
            g5 = func_003824E0(4.0f, 8.0f);
            qzero(v + 0x2E0);
            *(f32 *)(v + 0x2E0) = func_0038D098(f5) * g5;
            *(f32 *)(v + 0x2E4) = func_0038D0B0(f5) * g5;
            vec_add_ab(v + 0x2E0, v + 0x2E0, v + 0x310);
            *(s16 *)(v + 0x2D4) = func_00382498(0x12C, 0x212);
            func_L01_0045BD78(a0, 0.0032000002f, 0.030000001f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045CED0(a0, v + 0x2E0);
        if (func_0038CF00(a0 + 0x10, v + 0x2E0) < 0.75f) {
            f5 = func_00382538();
            g5 = func_003824E0(2.0f, 6.0f);
            qzero(v + 0x2E0);
            *(f32 *)(v + 0x2E0) = func_0038D098(f5) * g5;
            *(f32 *)(v + 0x2E4) = func_0038D0B0(f5) * g5;
            vec_add_ab(v + 0x2E0, v + 0x2E0, v + 0x310);
        }
        if (a0[0xBC] == 0) {
            func_L01_004450F0(a0, 6, -1);
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
        }
        }
        break;
    case 8:
        vec.z = func_L01_00451580(a0 + 0x10);
        vec2.z = func_L01_00451580(*(u8 **)(v + 0x230) + 0x10);
        if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.2f) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, 0.060000002f);
        }
        if (func_L01_0044E1B8(a0, 4.0f) != 0) {
            *(q_3A2DB0 *)(v + 0x2E0) = *(q_3A2DB0 *)(v + 0x220);
        }
        if (func_L01_004395E0(a0) < 6.0f || a0[0x42] != 4) {
            func_003C2F58(a0, 3, &vec3);
            {
                f32 f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00443A18(1.0f, 4.0f);
                func_L01_0046B458(&vec3, 2, *(f32 *)(v + 0x2F8), f, D_001DE0C8_sda, 0, n,
                          &D_L11_001D66B0, 0.0f, 0);
            }
            {
                f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
                f32 g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00443A18(1.0f, 4.0f);
                func_L01_0046B458(&vec3, 2, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0, 0.0f, 0);
            }
            func_003C2F58(a0, 4, &vec3);
            {
                f32 f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00443A18(1.0f, 4.0f);
                func_L01_0046B458(&vec3, 2, *(f32 *)(v + 0x2F8), f, D_001DE0C8_sda, 0, n,
                          &D_L11_001D66B0, 0.0f, 0);
            }
            {
                f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
                f32 g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00443A18(1.0f, 4.0f);
                func_L01_0046B458(&vec3, 2, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0, 0.0f, 0);
            }
            *(f32 *)(v + 0x2F8) += 0.026f;
        }
        if (func_L01_0044E1B8(a0, 8.0f) != 0) {
            func_003A52A0(1, 0, a0);
            func_003C2F58(a0, 3, &vec3);
            vec_sub_ba(&vec4, v + 0x2E0, &vec3);
            func_0038CE20(&vec4, &vec4, 1.5f);
            if (func_0038CEA8(&vec4) > 2.75f) {
                func_0038CF68(&vec4, &vec4, 2.75f);
            }
            vec_add_ab(&vec4, &vec4, &vec3);
            idx = 0;
            for (i = 0; i < 10; i++) {
                if (D_L11_002A2730[i * 4] == 0) {
                    idx = i;
                    break;
                }
            }
            func_L05_003BD448(&vec3, a0, *(u8 **)(v + 0x230), &vec4, 3, idx);
            func_003C2F58(a0, 4, &vec3);
            vec_sub_ba(&vec4, v + 0x2E0, &vec3);
            func_0038CE20(&vec4, &vec4, 1.5f);
            if (func_0038CEA8(&vec4) > 2.75f) {
                func_0038CF68(&vec4, &vec4, 2.75f);
            }
            vec_add_ab(&vec4, &vec4, &vec3);
            idx = 0;
            for (i = 0; i < 10; i++) {
                if (D_L11_002A2730[i * 4] == 0) {
                    idx = i;
                    break;
                }
            }
            func_L05_003BD448(&vec3, a0, *(u8 **)(v + 0x230), &vec4, 4, idx);
        }
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x21] != 0xFF) {
                func_L01_00445BE0(a0[0x21], 0);
            }
            func_L01_004450F0(a0, 9, -1);
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
        }
        break;
    case 7:
        vec_sub_ba(&vec, a0 + 0x10, v + 0x220);
        d = func_L01_00451738((s32)a0, &vec, 0);
        if (d > 0.17453292f) {
            vec_sub_ba(&vec2, v + 0x220, a0 + 0x10);
            d = func_L01_00451700((s32)a0, &vec2, 0);
            out[0] = 0;
            func_L01_00448890(out, d, v + 0x2FC, 0, 0.010053097f, 0.010053097f, 3.1415927f);
            qzero(&vec3);
            vec3.z = *(f32 *)(v + 0x2FC);
            func_0038D308(mat, &vec3);
            func_0038D5F0(a0 + 0xC0, a0 + 0xC0, mat);
        }
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(v + 0x2F8) = 0;
        }
        vec2.z = func_L01_00451580(a0 + 0x10);
        vec3.z = func_L01_00451580(*(u8 **)(v + 0x230) + 0x10);
        if (vec2.z < vec3.z) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec3.z < vec2.z && fabs_asm(vec2.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003C5278(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec3.z - vec2.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.010000001f) {
                *(f32 *)(v + 0x2DC) -= 0.0016000001f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.080000006f) {
            *(f32 *)(v + 0x2DC) += 0.0012f;
        }
        {
        func_003C2F58(a0, 4, &vec4);
        {
            f32 f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec4, 2, *(f32 *)(v + 0x2F8), f, D_001DE0C8_sda, 0, n,
                          &D_L11_001D66B0, 0.0f, 0);
        }
        {
            f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
            f32 g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec4, 2, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0, 0.0f, 0);
        }
        func_003C2F58(a0, 3, &vec4);
        {
            f32 f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec4, 2, *(f32 *)(v + 0x2F8), f, D_001DE0C8_sda, 0, n,
                          &D_L11_001D66B0, 0.0f, 0);
        }
        {
            f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
            f32 g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec4, 2, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0, 0.0f, 0);
        }
        }
        if (*(u16 *)(a0 + 0x96) >= 0x44) {
            if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, 8);
            }
            func_L01_004450F0(a0, 8, -1);
        }
        *(f32 *)(v + 0x2F8) += 0.026f;
        break;
    }
    func_L11_003A46C8((Moby_003A46C8 *)a0);
}
/* localdecomp:end func_L11_003A2DB0 */

/* localdecomp:start func_L11_003A40B8 */
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003A40B8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108010, 0x40042004, 0.16755162f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 6 || st == 8 || st == 7) {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40101080, 0x40040420, 0.16755162f);
        } else {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
        }
    } else {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
    }
    *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(v + 0x324), *(s32 *)(a0 + 0x78), 0.90400004f);
    func_003C2F58(a0, 0, buf);
    func_003D9508(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003A40B8 */

/* localdecomp:start func_L11_003A41E0 */
extern u8 D_001A30B0[];
extern s32 func_L11_003A4410(u8 *);
extern void func_L11_003A45D0(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L11_003A41E0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx;
    u8 *e;

    if (a0[0x20] == 0 && func_L11_003A4410(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (0.0f < *(f32 *)(v + 0x30)) {
        idx = *(s32 *)(v + 0x2F4);
        if (idx == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            *(s32 *)(v + 0x2F4) = func_003A52A0(0, 4, a0);
        }
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_L01_003A6BB0(a0);
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5E] != 0) {
die:
        func_L11_003A45D0(a0);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00404A10(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00404A10(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003A41E0 */

/* localdecomp:start func_L11_003A4410 */
typedef int q_3A4410 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4410;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003A4410(u8 *a0)
{
    u8 *v;
    V4_3A4410 m[4];

    *(s32 *)(a0 + 0x78) = 0x7F7F1010;
    v = *(u8 **)(a0 + 0x68);
    *(q_3A4410 *)(v + 0x310) = *(q_3A4410 *)(a0 + 0x10);
    func_003C5180(a0 + 0x10, m, 0);
    func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
    v[0x170] = 0xA;
    v[0x1A8] = 3;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(f32 *)(v + 0x194) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(v + 0x9C) = 0.0f;
    *(s32 *)(v + 0xA8) |= 1;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 60.0f;
    *(f32 *)(v + 0x80) = 1.3089969f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    func_L01_0045BD78(a0, 0.0064000003f, 0.060000002f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 1;
        *(f32 *)(v + 0x30) = 1.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 0.75f;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A4410 */

/* localdecomp:start func_L11_003A45D0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A45D0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx = *(s32 *)(v + 0x2F4);
    u8 *e;

    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 0x2F4) = -1;
    func_003A52A0(5, 0, a0);
    func_L01_00451FE0(a0, 0x7FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A45D0 */

/* localdecomp:start func_L11_003A46C8 */
extern u8 D_L11_001E1780[];
extern void func_0038CAD0(s32);
extern void func_0038CB00(s32);
extern void func_L11_003A40B8(u8 *);
extern void func_L01_00404808(void (*)(u8 *), void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);

void func_L11_003A46C8(Moby_003A46C8 *m) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = m->vars;
    func_0038CAD0(temp_s1 + 0x2D0);
    func_0038CB00(temp_s1 + 0x2D4);
    temp_v1 = m->timer;
    if (temp_v1 <= 0xFFFEU) {
        m->timer = (u16) (temp_v1 + 1);
    }
    func_L01_00404808(func_L11_003A40B8, m);
    func_L01_00451DF8(m, (u8 *)temp_s1 + 0x240, 2, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L11_001E1780, &m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->state = 30;
    }
}
/* localdecomp:end func_L11_003A46C8 */
