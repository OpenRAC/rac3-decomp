/* near miss (level 11, Obani Moons): func_L11_003A2DB0, 0x1308 bytes (1218 words), 428 diff
 * positional with the owning file's flags (L11_003A2CD0.c: -mvu0-use-vf0-vf2 ... @ps2as); this C
 * is 1214 words. Round 3 (down from 1034): the case-1 tail shares case 0's (6,2)+check, the
 * rand store sits inside the else, the f/g compare pairs live in the .z of stack vectors and the
 * matrix is a vu0_v4[3]. Left: float register allocation and the f/g spills to 0x98/0xA8,
 * the idx loops (retail recomputes base+idx*8 every pass, gcc strength-reduces to a pointer),
 * and a duplicated move from reorg in case 3. VU0 through include/vu0.h only. */
#include "common.h"
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
extern s32 func_003E7938(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L11_003A45D0(u8 *);
extern void func_L11_003A46C8(void *);
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
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0046B458(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
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
            if (func_003E7938(v + 0x2D6) != 0) {
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
        if (func_003E7938(v + 0x2D6) == 0) {
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
        } else if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.2f) {
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
        if (func_0038CF00(a0 + 0x10, v + 0x300) < 3.0f || func_0038CAD0(v + 0x320) != 0) {
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
            f32 f, g;
            func_003C2F58(a0, 3, &vec3);
            f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            c = (s32)func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec3, 2, D_001DE0C8_sda, 0, c, &D_L11_001D66B0, 0,
                              *(f32 *)(v + 0x2F8), f, 0.0f);
            f = *(f32 *)(v + 0x2F8) * 0.3f;
            g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            c = (s32)func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec3, 2, 0x7F7F7F7F, 0, c, &D_L11_001D66B0, 0, f, g, 0.0f);
            func_003C2F58(a0, 4, &vec3);
            f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            c = (s32)func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec3, 2, D_001DE0C8_sda, 0, c, &D_L11_001D66B0, 0,
                              *(f32 *)(v + 0x2F8), f, 0.0f);
            f = *(f32 *)(v + 0x2F8) * 0.3f;
            g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            c = (s32)func_L01_00443A18(1.0f, 4.0f);
            func_L01_0046B458(&vec3, 2, 0x7F7F7F7F, 0, c, &D_L11_001D66B0, 0, f, g, 0.0f);
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
            if (D_L11_002A2730[0] != 0) {
                do {
                    idx++;
                    if (idx >= 10) {
                        break;
                    }
                } while (D_L11_002A2730[idx * 4] != 0);
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
            if (D_L11_002A2730[0] != 0) {
                do {
                    idx++;
                    if (idx >= 10) {
                        break;
                    }
                } while (D_L11_002A2730[idx * 4] != 0);
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
        f32 f, g;
        func_003C2F58(a0, 4, &vec4);
        f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
        c = (s32)func_L01_00443A18(1.0f, 4.0f);
        func_L01_0046B458(&vec4, 2, D_001DE0C8_sda, 0, c, &D_L11_001D66B0, 0,
                          *(f32 *)(v + 0x2F8), f, 0.0f);
        f = *(f32 *)(v + 0x2F8) * 0.3f;
        g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
        c = (s32)func_L01_00443A18(1.0f, 4.0f);
        func_L01_0046B458(&vec4, 2, 0x7F7F7F7F, 0, c, &D_L11_001D66B0, 0, f, g, 0.0f);
        func_003C2F58(a0, 3, &vec4);
        f = func_003824E0(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
        c = (s32)func_L01_00443A18(1.0f, 4.0f);
        func_L01_0046B458(&vec4, 2, D_001DE0C8_sda, 0, c, &D_L11_001D66B0, 0,
                          *(f32 *)(v + 0x2F8), f, 0.0f);
        f = *(f32 *)(v + 0x2F8) * 0.3f;
        g = func_003824E0(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
        c = (s32)func_L01_00443A18(1.0f, 4.0f);
        func_L01_0046B458(&vec4, 2, 0x7F7F7F7F, 0, c, &D_L11_001D66B0, 0, f, g, 0.0f);
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
    func_L11_003A46C8(a0);
}
