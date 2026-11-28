#include "common.h"
/* localdecomp:start func_L01_0035FCB8 */
#include "vu0.h"
typedef struct {
    u8 pad00[0x18];
    f32 f18;
    u8 pad1C[0x14];
    f32 f30;
    f32 f34;
} S_00360A48;
typedef struct {
    vu0_v4 p[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long tag0, texture, tag1, tag2;
} Strip_00360A48;
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_00360A48;
extern f32 D_L01_001DD758;
extern f32 D_L01_001DD75C;
extern f32 D_L01_001DD760;
extern f32 D_L01_001DD764;
extern f32 D_L01_001DD768;
extern f32 D_L01_001DD76C;
__asm__(".extern D_L01_001DD758, 4");
__asm__(".extern D_L01_001DD75C, 4");
__asm__(".extern D_L01_001DD760, 4");
__asm__(".extern D_L01_001DD764, 4");
__asm__(".extern D_L01_001DD768, 4");
__asm__(".extern D_L01_001DD76C, 4");
extern u8 D_L01_001E2AC0[];
extern u8 D_001A4EC0[];

void func_L01_0035FCB8(u8 *o) {
    extern u8 D_00142637[];
    extern Gun_00360A48 D_L01_002C5640[];
    extern f32 func_0037E250(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004086B8(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32);
    extern f32 func_L01_0040C018(void *, void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_00388758(void *, void *, void *);
    extern void func_003886E8(void *, void *, f32);
    extern void func_003D3E40(void *, s32, s32, s32);
    extern void func_003CD830(void *, s32, s32);
    extern void func_003A3EF0(s32, unsigned long);
    extern void func_00384DA0(void *, f32 *, f32 *);
    vu0_v4 v00;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    Strip_00360A48 pk;
    S_00360A48 *s;
    s32 c2, c4, c5, c6, c7;
    s32 kind;
    f32 d, t, a, b, w, ang, sn, cs;
    f32 *px, *py;
    u8 *pq;
    u8 *pp;
    s32 i, j, k;

    c4 = 0x7F400505;
    c2 = 0x7F200505;
    c5 = 0x35FF0032;
    c6 = 0x35804020;
    c7 = 0x357F2020;
    s = *(S_00360A48 **)(o + 0x68);
    D_L01_001DD758 = func_00389380(D_L01_001DD758, func_0037E250(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DD764 = func_00389380(D_L01_001DD764, func_0037E250(-2.0f, -4.0f) * 0.017453292f);
    D_L01_001DD75C = func_00389380(D_L01_001DD75C, func_0037E250(-1.0f, -3.0f) * 0.017453292f);
    D_L01_001DD768 = func_00389380(D_L01_001DD768, func_0037E250(-3.0f, -5.0f) * 0.017453292f);
    D_L01_001DD760 = func_00389380(D_L01_001DD760, func_0037E250(-1.0f, -3.0f) * 0.017453292f);
    D_L01_001DD76C = func_00389380(D_L01_001DD76C, func_0037E250(-1.0f, -4.0f) * 0.017453292f);
    kind = ((Gun_00360A48 *)(D_00142637[0] * sizeof(Gun_00360A48) + (s32)D_L01_002C5640))->kind;
    if (kind == 2) {
        c4 = 0x7F050510;
        c2 = 0x7F050520;
        c5 = 0x35104080;
        c6 = 0x35204080;
        c7 = 0x354080FF;
    } else if (kind == 3) {
        c4 = 0x7F050540;
        c2 = 0x7F050520;
        c5 = 0x3532007F;
        c6 = 0x35204080;
        c7 = 0x3520207F;
    }
    pq = o + 0x10;
    func_003D3FA0(pq, 0x49, c4, 0, s->f18 * 1.2f * 2.0f, 0.01f, D_L01_001DD768);
    func_003D3FA0(pq, 0x49, c2, 0, s->f18 * 1.1f * 2.0f, 0.01f, -D_L01_001DD76C);
    func_003D3FA0(pq, 0x49, c4, 0, s->f18 * 0.9f * 2.0f, 0.01f, D_L01_001DD764);
    func_003D3FA0(pq, 0x49, c2, 0, s->f18 * 2.0f, 0.01f, -D_L01_001DD764);
    func_003D3FA0(pq, 0x4A, c4, 0, s->f18 * 1.2f * 2.0f, 0.01f, -D_L01_001DD768);
    func_003D3FA0(pq, 0x4A, c2, 0, s->f18 * 1.1f * 2.0f, 0.01f, D_L01_001DD76C);
    func_003D3FA0(pq, 0x4A, c4, 0, s->f18 * 0.9f * 2.0f, 0.01f, -D_L01_001DD764);
    func_003D3FA0(pq, 0x4A, c2, 0, s->f18 * 2.0f, 0.01f, D_L01_001DD764);
    func_L01_004086B8(pq, 0x47, 0x48, c5, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, D_L01_001DD758, -D_L01_001DD764, 0.0f, 0);
    func_L01_004086B8(pq, 0x47, 0x48, c6, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, -D_L01_001DD75C, D_L01_001DD768, 0.05f, 0);
    func_L01_004086B8(pq, 0x47, 0x48, c7, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, D_L01_001DD760, -D_L01_001DD76C, 0.1f, 0);
    d = func_L01_0040C018(D_L01_001E2AC0, pq);
    if (36.0f < d) {
        t = s->f34;
        if (1.0f < t) {
            s->f34 = 1.0f;
        } else if (t < 0.0f) {
            s->f34 = 0.0f;
        }
        a = func_00388960(t * 3.1415927f);
        vec_sub_ba(&v10, D_L01_001E2AC0, o + 0x10);
        w = (1.0f - a) * 0.5f * 0.6f;
        func_00388830(&v10, &v10, s->f34 + 2.0f);
        func_00388830(&v30, D_001A4EC0, 1.0f);
        func_00388758(&v30, &v10, &v30);
        func_00388830(&v30, &v30, s->f34 + 2.0f);
        func_00388758(&v20, &v30, &v10);
        func_00388830(&v20, &v20, s->f34 + 1.0f);
        func_00388830(&v00, &v30, -0.5f);
        vec_add_ba(&v40, o + 0x10, &v00);
        vec_add_ba(&v50, &v40, &v10);
        func_003886E8(&v00, &v10, 0.5f);
        vec_add_ab(&v40, &v40, &v10);
        s->f30 = func_00389380(s->f30, 0.0465421155f);
        ang = s->f30;
        i = 0;
        do {
            v70 = v40;
            sn = func_00388960(ang);
            cs = func_00388978(ang);
            if (sn != 0.0f) {
                func_003886E8(&v80, &v30, sn);
                vec_add_ab(&v70, &v70, &v80);
            }
            if (cs != 0.0f) {
                func_003886E8(&v80, &v20, cs);
                vec_add_ab(&v70, &v70, &v80);
            }
            if (i != 0) {
                func_003D3E40(&pk, 0x4D, 1, 0x80);
                pk.tag2 = 0x800000004AL;
                pk.p[0] = v60;
                pk.p[1] = v70;
                pk.c40 = pk.c44 = pk.c48 = pk.c4C = 0x80808080;
                pk.uv[0][0] = 0.0f;
                pk.uv[0][1] = 0.0f;
                pk.uv[1][0] = 1.0f;
                pk.uv[1][1] = 0.0f;
                pk.uv[2][0] = 0.0f;
                pk.uv[2][1] = 1.0f;
                pk.uv[3][0] = 1.0f;
                pk.uv[3][1] = 1.0f;
                pk.p[2] = v50;
                pk.p[3] = v50;
                func_003A3EF0(0x47, 0x31001);
                func_003CD830(&pk, 0, 0);
                for (j = 0; j < 4; j++) {
                    func_00384DA0(&pk.p[j], &pk.uv[j][0], &pk.uv[j][1]);
                }
                v80.x = (pk.uv[0][0] + pk.uv[1][0]) * 0.5f;
                v80.y = (pk.uv[0][1] + pk.uv[1][1]) * 0.5f;
                for (k = 0; k < 2; k++) {
                    pk.uv[2 + k][0] += (v80.x - pk.uv[2 + k][0]) * w;
                    pk.uv[2 + k][1] += (v80.y - pk.uv[2 + k][1]) * w;
                }
                func_003D3E40(&pk, -1, 1, 0x80);
                pk.tag0 = 5;
                pk.tag2 = 0x8000000054L;
                func_003A3EF0(0x47, 0x53001);
                func_003CD830(&pk, 0, 0);
                func_003A3EF0(0x47, 0x5360B);
            }
            v60 = v70;
            ang = func_00389380(ang, 0.19634955f);
            i++;
        } while (i < 33);
    }
}
/* localdecomp:end func_L01_0035FCB8 */
