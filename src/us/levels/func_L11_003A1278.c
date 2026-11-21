#include "common.h"

/* NTSC-U counterpart of func_L11_003A2DB0 (src/levels/11_obani_moons/L11_003A2CD0.c) */
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
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L11_003A1278 */
#include "vu0.h"

typedef int q_3A2DB0 __attribute__((mode(TI)));

extern s32 D_001A71A4[];
extern u8 *D_L11_0021CB80_003A1278[];
extern s16 D_L11_002A2730_003A1278[];
__asm__(".extern D_L11_001D66B0_003A1278, 16");
extern u8 D_L11_001D66B0_003A1278;
__asm__(".extern D_001DE0F8_sda, 4");
extern s32 D_001DE0F8_sda;

extern s32 func_L11_003A2678(u8 *);
extern void func_003BD360(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003883C8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442AA8(s32, s32);
extern void func_L11_003A2A68(u8 *);
extern void func_L11_003A2B60(Moby_003A46C8 *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_0032FE90_003A1278(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern s32 func_L11_0042FDC8(u8 *, u8 *);
extern f32 func_L01_0044E300(void *);
extern void func_003BFD10(void *, void *, void *, f32);
extern f32 func_L01_0044E4B8(s32, void *, s32);
extern f32 func_L01_0044E480(s32, void *, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00459BC8(void *, void *);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_00388398(s32);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00436500(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern f32 func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_L05_003BB4D8(void *, void *, void *, void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);

void func_L11_003A1278(u8 *a0)
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

    if (func_L11_003A2678(a0) != 0) {
        func_003BD360(a0);
        return;
    }
    if (D_001A71A4[0] == 0x31) {
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(a0, 1);
        return;
    }
    p = *(u8 **)(a0 + 0x24);
    *(u16 *)(a0 + 0x34) &= 0xFFBE;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(p + 0x10);

    switch (a0[0x95]) {
    case 0:
        if (func_L01_00452EF0(a0) != 0) {
            *(u16 *)(v + 0x2D6) = func_0037E208(0, 0x1E);
        }
        if (*(s16 *)(v + 0x234) == 1) {
            if (((s32 (*)(void *))func_003883C8)(v + 0x2D6) != 0) {
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, 6);
                }
                func_L01_00441FB8(a0, 6, 2);
                if (*(s32 *)(v + 0x2F0) != -1) {
                    func_L01_00441FB8(a0, 4, -1);
                }
                break;
            }
        }
        if (*(s32 *)(v + 0x2D8) == 0) {
            break;
        }
        if (((s32 (*)(void *))func_003883C8)(v + 0x2D6) == 0) {
            break;
        }
        func_L01_00441FB8(a0, 3, 1);
        *(s32 *)(v + 0x2D8) = 0;
        if (*(s32 *)(v + 0x2D0) < 300) {
            *(s32 *)(v + 0x2D0) = func_0037E208(0x1E0, 0x258);
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 6);
            }
            func_L01_00441FB8(a0, 6, 2);
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_00441FB8(a0, 1, 0);
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 0);
            }
        }
        break;
    case 2:
        if (*(s16 *)(v + 0x234) != 1 && func_L01_00452EF0(a0) == 0) {
            func_L01_00441FB8(a0, 1, 0);
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 0);
            }
            *(s32 *)(v + 0x2D0) = func_0037E208(0x244, 0x258);
        }
        break;
    case 3:
        c = func_L01_00451078(a0, v + 0x160);
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            func_L11_003A2A68(a0);
            func_003BDA38(a0, 1, &vec);
            func_L01_0032FE90_003A1278(&vec, 0, 9, 9, 0xC, 0xC, 0x16, 0, 0.3f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38,
                              0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38, 0xF78E38, 0);
            func_003BD360(a0);
            return;
        }
        if (c & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_00441FB8(a0, 6, 2);
            } else {
                func_L01_00441FB8(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = func_0037E208(0x244, 0x258);
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
        e = D_L11_0021CB80_003A1278[*(s32 *)(v + 0x2F0)];
        if (func_L11_0042FDC8(a0, e) != 0) {
            func_L01_00441FB8(a0, 6, -1);
        }
        vec.z = func_L01_0044E300(a0 + 0x10);
        vec2.z = func_L01_0044E300(e + 0x10 + (*(s16 *)(v + 0x13A) << 4));
        if (vec.z < vec2.z) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec2.z - vec.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.008333334f) {
                *(f32 *)(v + 0x2DC) -= 0.0011111111f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.06666667f) {
            *(f32 *)(v + 0x2DC) += 0.00083333335f;
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, 0.0044444446f, 0.050000004f, 0.0069813174f, 0.20943953f);
            if (a0[0x21] != 0xFF) {
                func_L01_00442AA8(a0[0x21], 1);
            }
        }
        func_L01_00459BC8(a0, v + 0x220);
        vec.z = func_L01_0044E300(a0 + 0x10);
        vec2.z = func_L01_0044E300(*(u8 **)(v + 0x230) + 0x10);
        if (vec.z < vec2.z) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec2.z - vec.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.008333334f) {
                *(f32 *)(v + 0x2DC) -= 0.0011111111f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.06666667f) {
            *(f32 *)(v + 0x2DC) += 0.00083333335f;
        }
        vec_sub_ba(&vec3, v + 0x220, a0 + 0x10);
        d = func_L01_0044E4B8((s32)a0, &vec3, 0);
        if (func_003887C8(a0 + 0x10, v + 0x220) < 3.0f && d < 0.2617994f &&
            fabs_asm(vec2.z - vec.z) < 2.0f) {
            func_L01_00441FB8(a0, 7, -1);
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 10);
            }
        }
        break;
    case 9:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00440A88(&vec, 0.0f, 0.5f);
            vec_add_ab(v + 0x300, &vec, v + 0x310);
            *(s32 *)(v + 0x320) = func_0037E208(0x5A, 0x82);
        }
        func_L01_00459BC8(a0, v + 0x300);
        vec_sub_ba(&vec, a0 + 0x10, v + 0x300);
        d = func_L01_0044E4B8((s32)a0, &vec, 0);
        if (func_003887C8(a0 + 0x10, v + 0x300) < 3.0f || ((s32 (*)(void *))func_00388398)(v + 0x320) != 0) {
            func_L01_00441FB8(a0, 6, -1);
        }
        break;
    case 5:
        {
        f32 f5, g5;
        if (func_L01_00452EC8(a0) != 0) {
            f5 = func_0037E2A8();
            g5 = func_0037E250(4.0f, 8.0f);
            qzero(v + 0x2E0);
            *(f32 *)(v + 0x2E0) = func_00388960(f5) * g5;
            *(f32 *)(v + 0x2E4) = func_00388978(f5) * g5;
            vec_add_ab(v + 0x2E0, v + 0x2E0, v + 0x310);
            *(s16 *)(v + 0x2D4) = func_0037E208(0x12C, 0x212);
            func_L01_00458A70(a0, 0.0022222223f, 0.025000002f, 0.0069813174f, 0.20943953f);
        }
        func_L01_00459BC8(a0, v + 0x2E0);
        if (func_003887C8(a0 + 0x10, v + 0x2E0) < 0.75f) {
            f5 = func_0037E2A8();
            g5 = func_0037E250(2.0f, 6.0f);
            qzero(v + 0x2E0);
            *(f32 *)(v + 0x2E0) = func_00388960(f5) * g5;
            *(f32 *)(v + 0x2E4) = func_00388978(f5) * g5;
            vec_add_ab(v + 0x2E0, v + 0x2E0, v + 0x310);
        }
        if (a0[0xBC] == 0) {
            func_L01_00441FB8(a0, 6, -1);
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
        }
        }
        break;
    case 8:
        vec.z = func_L01_0044E300(a0 + 0x10);
        vec2.z = func_L01_0044E300(*(u8 **)(v + 0x230) + 0x10);
        if (vec2.z < vec.z && fabs_asm(vec.z - *(f32 *)(v + 0x100)) > 0.2f) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, 0.050000004f);
        }
        if (func_L01_0044AF40(a0, 4.0f) != 0) {
            *(q_3A2DB0 *)(v + 0x2E0) = *(q_3A2DB0 *)(v + 0x220);
        }
        if (func_L01_00436500(a0) < 6.0f || a0[0x42] != 4) {
            func_003BDA38(a0, 3, &vec3);
            {
                f32 f = func_0037E250(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00440918(1.0f, 4.0f);
                func_L01_00467DA8(&vec3, 3, *(f32 *)(v + 0x2F8), f, D_001DE0F8_sda, 0, n,
                          &D_L11_001D66B0_003A1278, 0.0f, 0);
            }
            {
                f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
                f32 g = func_0037E250(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00440918(1.0f, 4.0f);
                func_L01_00467DA8(&vec3, 3, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0_003A1278, 0.0f, 0);
            }
            func_003BDA38(a0, 4, &vec3);
            {
                f32 f = func_0037E250(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00440918(1.0f, 4.0f);
                func_L01_00467DA8(&vec3, 3, *(f32 *)(v + 0x2F8), f, D_001DE0F8_sda, 0, n,
                          &D_L11_001D66B0_003A1278, 0.0f, 0);
            }
            {
                f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
                f32 g = func_0037E250(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
                s32 n = func_L01_00440918(1.0f, 4.0f);
                func_L01_00467DA8(&vec3, 3, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0_003A1278, 0.0f, 0);
            }
            *(f32 *)(v + 0x2F8) += 0.021666666f;
        }
        if (func_L01_0044AF40(a0, 8.0f) != 0) {
            func_0039FE80(1, 0, a0);
            func_003BDA38(a0, 3, &vec3);
            vec_sub_ba(&vec4, v + 0x2E0, &vec3);
            func_003886E8(&vec4, &vec4, 1.5f);
            if (func_00388770(&vec4) > 2.75f) {
                func_00388830(&vec4, &vec4, 2.75f);
            }
            vec_add_ab(&vec4, &vec4, &vec3);
            idx = 0;
            for (i = 0; i < 10; i++) {
                if (D_L11_002A2730_003A1278[i * 4] == 0) {
                    idx = i;
                    break;
                }
            }
            func_L05_003BB4D8(&vec3, a0, *(u8 **)(v + 0x230), &vec4, 3, idx);
            func_003BDA38(a0, 4, &vec3);
            vec_sub_ba(&vec4, v + 0x2E0, &vec3);
            func_003886E8(&vec4, &vec4, 1.5f);
            if (func_00388770(&vec4) > 2.75f) {
                func_00388830(&vec4, &vec4, 2.75f);
            }
            vec_add_ab(&vec4, &vec4, &vec3);
            idx = 0;
            for (i = 0; i < 10; i++) {
                if (D_L11_002A2730_003A1278[i * 4] == 0) {
                    idx = i;
                    break;
                }
            }
            func_L05_003BB4D8(&vec3, a0, *(u8 **)(v + 0x230), &vec4, 4, idx);
        }
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x21] != 0xFF) {
                func_L01_00442AA8(a0[0x21], 0);
            }
            func_L01_00441FB8(a0, 9, -1);
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
        }
        break;
    case 7:
        vec_sub_ba(&vec, a0 + 0x10, v + 0x220);
        d = func_L01_0044E4B8((s32)a0, &vec, 0);
        if (d > 0.17453292f) {
            vec_sub_ba(&vec2, v + 0x220, a0 + 0x10);
            d = func_L01_0044E480((s32)a0, &vec2, 0);
            out[0] = 0;
            func_L01_00445758(out, d, v + 0x2FC, 0, 0.0069813174f, 0.0069813174f, 3.1415927f);
            qzero(&vec3);
            vec3.z = *(f32 *)(v + 0x2FC);
            func_00388BD0(mat, &vec3);
            func_00388EB8(a0 + 0xC0, a0 + 0xC0, mat);
        }
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(v + 0x2F8) = 0;
        }
        vec2.z = func_L01_0044E300(a0 + 0x10);
        vec3.z = func_L01_0044E300(*(u8 **)(v + 0x230) + 0x10);
        if (vec2.z < vec3.z) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, -*(f32 *)(v + 0x2DC));
        } else if (vec3.z < vec2.z && fabs_asm(vec2.z - *(f32 *)(v + 0x100)) > 0.1f) {
            func_003BFD10(a0 + 0x10, a0 + 0x10, a0 + 0x10, *(f32 *)(v + 0x2DC));
        }
        if (fabs_asm(vec3.z - vec2.z) < 1.0f) {
            if (*(f32 *)(v + 0x2DC) > 0.008333334f) {
                *(f32 *)(v + 0x2DC) -= 0.0011111111f;
            }
        } else if (*(f32 *)(v + 0x2DC) < 0.06666667f) {
            *(f32 *)(v + 0x2DC) += 0.00083333335f;
        }
        {
        func_003BDA38(a0, 4, &vec4);
        {
            f32 f = func_0037E250(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00440918(1.0f, 4.0f);
            func_L01_00467DA8(&vec4, 3, *(f32 *)(v + 0x2F8), f, D_001DE0F8_sda, 0, n,
                          &D_L11_001D66B0_003A1278, 0.0f, 0);
        }
        {
            f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
            f32 g = func_0037E250(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00440918(1.0f, 4.0f);
            func_L01_00467DA8(&vec4, 3, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0_003A1278, 0.0f, 0);
        }
        func_003BDA38(a0, 3, &vec4);
        {
            f32 f = func_0037E250(0.75f, 1.2f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00440918(1.0f, 4.0f);
            func_L01_00467DA8(&vec4, 3, *(f32 *)(v + 0x2F8), f, D_001DE0F8_sda, 0, n,
                          &D_L11_001D66B0_003A1278, 0.0f, 0);
        }
        {
            f32 f = *(f32 *)(v + 0x2F8) * 0.3f;
            f32 g = func_0037E250(0.3f, 0.65f) * *(f32 *)(v + 0x2F8);
            s32 n = func_L01_00440918(1.0f, 4.0f);
            func_L01_00467DA8(&vec4, 3, f, g, 0x7F7F7F7F, 0, n, &D_L11_001D66B0_003A1278, 0.0f, 0);
        }
        }
        if (*(u16 *)(a0 + 0x96) >= 0x51) {
            if (a0[0x43] != 4) {
                func_003BE4F0(a0, 4, 0, 10);
            }
            func_L01_00441FB8(a0, 8, -1);
        }
        *(f32 *)(v + 0x2F8) += 0.021666666f;
        break;
    }
    func_L11_003A2B60((Moby_003A46C8 *)a0);
}
/* localdecomp:end func_L11_003A1278 */
