#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


/* localdecomp:start func_L01_0033F388 */
typedef struct {
    s32 w0;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
} R_0033F388;
extern R_0033F388 D_L01_00278DA0[];
extern s32 D_L01_001E18C0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E18C4[] __attribute__((section(".sdata")));
extern s32 D_L01_001E18C8[] __attribute__((section(".sdata")));
extern f32 D_L01_001E18CC[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD050;
extern s32 D_L01_001DD054;
extern f32 D_L01_001DD058;
extern f32 D_L01_001DD094;
extern u16 D_L01_001DD098;
__asm__(".extern D_L01_001DD050, 4");
__asm__(".extern D_L01_001DD054, 4");
__asm__(".extern D_L01_001DD058, 4");
__asm__(".extern D_L01_001DD094, 4");
__asm__(".extern D_L01_001DD098, 2");
extern s32 func_L01_0040DFC0(s32 *);
extern s32 func_L01_0040DFF0(u8 *);

void func_L01_0033F388(void) {
    s32 i;
    s32 n;

    if (D_L01_001DD050 != 0) {
        for (i = 9; i >= 0; i--) {
            D_L01_00278DA0[i].h8 = 0;
        }
        D_L01_001DD050 = 0;
        D_L01_001E18C0[0] = 0;
        n = (s32)(D_L01_001DD058 / (D_L01_001DD094 * 0.020000001f));
        D_L01_001E18C8[0] = n;
        D_L01_001E18CC[0] = 1.0f / (f32)n;
    }
    if (D_L01_001E18C4[0] == 0) {
        if (func_L01_0040DFC0(D_L01_001E18C0) != 0) {
            for (i = 0; i < 10; i++) {
                if (D_L01_00278DA0[i].h8 == 0) {
                    D_L01_001E18C0[0] = (D_L01_001DD054 * 5 + 2) / 6;
                    D_L01_00278DA0[i].h8 = 1;
                    D_L01_00278DA0[i].h4 = D_L01_001E18C8[0];
                    D_L01_00278DA0[i].h6 = D_L01_001DD098;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (D_L01_00278DA0[i].h8 != 0) {
            if (func_L01_0040DFF0((u8 *)&D_L01_00278DA0[i].h4) != 0) {
                D_L01_00278DA0[i].h8 = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_0033F388 */

/* localdecomp:start func_L01_0033F530 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) V_0033F530;
typedef struct {
    V_0033F530 verts[4];
    u32 colors[4];
    f32 uv[8];
    unsigned long zero;
    unsigned long texture;
    unsigned long alpha;
    unsigned long prim;
} Packet_0033F530;
typedef struct {
    u8 pad[8];
    s16 age;
} P_0033F530;
typedef struct {
    u8 pad[0x10];
    V_0033F530 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    P_0033F530 *p;
} M_0033F530;
extern s32 D_L01_001DD040;
__asm__(".extern D_L01_001DD040, 4");
extern s32 D_L01_001DD098_0033F530;
__asm__(".extern D_L01_001DD098_0033F530, 4");
extern s32 D_L01_001DD09C;
__asm__(".extern D_L01_001DD09C, 4");
extern f32 D_L01_001DD0A0;
__asm__(".extern D_L01_001DD0A0, 4");
extern f32 D_L01_001DD0E0;
__asm__(".extern D_L01_001DD0E0, 4");
extern f32 D_L01_001DD0E4;
__asm__(".extern D_L01_001DD0E4, 4");
extern f32 D_L01_001DD0E8;
__asm__(".extern D_L01_001DD0E8, 4");
extern s32 D_L01_001DD0EC;
__asm__(".extern D_L01_001DD0EC, 4");
extern s32 D_L01_001DD0F0;
__asm__(".extern D_L01_001DD0F0, 4");
extern f32 D_L01_001DD0F4;
__asm__(".extern D_L01_001DD0F4, 4");
extern V_0033F530 D_L01_001E29C0[];
extern V_0033F530 D_001A4EC0[];
extern long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0033F920(void *, f32);
extern void func_L01_003405B8(void);

void func_L01_0033F530(M_0033F530 *m) {
    Packet_0033F530 packet;
    V_0033F530 normal;
    V_0033F530 tangent;
    V_0033F530 bitangent;
    V_0033F530 pos;
    V_0033F530 tmp;
    V_0033F530 *posptr;
    s32 i;
    s32 j;
    s32 next;
    V_0033F530 *source;
    V_0033F530 *dest;
    V_0033F530 *source2;
    V_0033F530 *dest2;
    s32 j2;
    u32 color;
    u32 color2;
    f32 fade;
    f32 ratio;
    f32 size;
    P_0033F530 *p = m->p;

    if (m->state != 2) {
        if (p->age >= ((D_L01_001DD040 - 30) * 5 + 2) / 6) {
            fade = (f32)((D_L01_001DD040 * 5 + 2) / 6 - p->age) / 25.0f;
        } else {
            fade = 1.0f;
        }
        packet.texture = func_00389598(8);
        packet.prim = 0x8000000048UL;
        packet.alpha = 0xff9000000260UL;
        packet.zero = 0;
        packet.uv[0] = 0;
        packet.uv[1] = 0;
        packet.uv[2] = 0;
        packet.uv[3] = 1;
        packet.uv[4] = 1;
        packet.uv[5] = 0;
        packet.uv[6] = 1;
        packet.uv[7] = 1;
        vec_sub_ba(&normal, D_L01_001E29C0, &m->pos);
        func_0038CF68(&normal, &normal, 1.0f);
        pos = m->pos;
        func_0038CE20(&bitangent, D_001A4EC0, -1.0f);
        func_0038CE90(&tangent, &normal, &bitangent);
        func_0038CF68(&tangent, &tangent, 1.0f);
        func_0038CE90(&bitangent, &tangent, &normal);
        posptr = &pos;
        i = 0;
        do {
            next = i + 1;
            if (D_L01_00278DA0[i].h8) {
                ratio = (f32)D_L01_00278DA0[i].h4 * D_L01_001E18CC[0];
                if (ratio > 1.0f) ratio = 1.0f;
                color = (D_L01_001DD09C & 0xffffff) | ((s32)(fade * ((f32)D_L01_001DD098_0033F530 + (0.0f - (f32)D_L01_001DD098_0033F530) * ratio)) << 24);
                size = D_L01_001DD0E0 + (D_L01_001DD0E4 - D_L01_001DD0E0) * ratio;
                packet.colors[3] = color;
                packet.colors[2] = color;
                packet.colors[1] = color;
                packet.colors[0] = color;
                for (j = 0; j < 4; j++) {
                    func_0038CE20(&tmp, &((V_0033F530 *)&D_L01_001DD0A0)[j], size);
                    func_0038D028(&packet.verts[j], &tmp, &normal);
                }
                func_003D2DA0(&packet, 0, 0);
            }
            i = next;
        } while (i < 10);
        packet.texture = func_00389598(11);
        color2 = (D_L01_001DD0F0 & 0xffffff) | D_L01_001DD0EC;
        packet.prim = 0x8000000044UL;
        packet.colors[3] = color2;
        packet.colors[2] = color2;
        packet.colors[1] = color2;
        packet.colors[0] = color2;
        func_0038CF68(posptr, &normal, D_L01_001DD0F4);
        vec_add_ab(&pos, &pos, &m->pos);
        size = D_L01_001DD0E8 + func_L01_00443A18(0.0f, 0.1f);
        for (j2 = 0; j2 < 4; j2++) {
            func_0038CE20(&tmp, &((V_0033F530 *)&D_L01_001DD0A0)[j2], size);
            func_0038D028(&packet.verts[j2], &tmp, &normal);
        }
        func_003D2DA0(&packet, 0, 0);
        func_L01_0033F920(m, fade);
    }
    func_L01_003405B8();
}
/* localdecomp:end func_L01_0033F530 */

/* localdecomp:start func_L01_0033F920 */
typedef unsigned int MeshQuad_0033F920 __attribute__((mode(TI)));
typedef union { MeshQuad_0033F920 q; f32 v[4]; } MeshVector_0033F920;
typedef struct { f32 x, y, z; } MeshPoint_0033F920;
extern s32 D_L01_001DD0F8;
__asm__(".extern D_L01_001DD0F8, 4");
extern s32 D_L01_001DD0FC[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD110;
__asm__(".extern D_L01_001DD110, 4");
extern s32 D_L01_001DD114[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD118;
__asm__(".extern D_L01_001DD118, 4");
extern f32 D_L01_001DD11C;
__asm__(".extern D_L01_001DD11C, 4");
extern f32 D_L01_001DD120;
__asm__(".extern D_L01_001DD120, 4");
extern f32 D_L01_001DD124;
__asm__(".extern D_L01_001DD124, 4");
extern u32 D_L01_001DD128;
__asm__(".extern D_L01_001DD128, 4");
extern s8 D_L01_001DD12F[] __attribute__((section(".sdata")));
extern f32 D_L01_002B1570[][3];
extern f32 D_L01_002B1C60[][3];
extern f32 D_L01_002B1F30[][2];
extern f32 D_L01_002B23D0[][2];
extern u32 D_L01_002B25B0[];
extern u32 D_L01_002B2800[];
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_003D3A24(s32, void *, s32, void *, s32);

#define MeshStorePoint_0033F920(point, value) \
    (point)->x = (value)->v[0]; \
    (point)->y = (value)->v[1]; \
    (point)->z = (value)->v[2]

/* Draws the four-sided glowing mesh that faces the camera, as eight flipped copies of two vertex
 * sets, fading with opacity: rac2's mesh_draw_four_signs_pal (rac2 src/pal/levels/shared/
 * L00_003B7FC0-cc-g8.c), with PAL's x1.2 scroll rate. */
void func_L01_0033F920(void *object, f32 opacity)
{
    MeshVector_0033F920 transform[4];
    MeshPoint_0033F920 positions[148];
    f32 uv[148][2];
    MeshVector_0033F920 temp;
    s32 alpha;
    u8 *origin;

    D_L01_001DD11C += D_L01_001DD120 * 1.2f;
    if (D_L01_001DD11C >= 7.0f) D_L01_001DD11C -= 7.0f;
    origin = (u8 *)object + 0x10;
    func_003A9440(6, func_00389598(D_L01_001DD118));
    func_003A9440(0x42, 0x8000000048UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_0038C750();
    vec_sub_ba(&transform[0], D_L01_001E29C0, origin);
    func_0038CF68(&transform[0], &transform[0], 1.0f);
    func_0038CE90(&transform[1], &transform[0], D_001A4EC0);
    func_0038CF68(&transform[1], &transform[1], -1.0f);
    func_0038CE90(&transform[2], &transform[1], &transform[0]);
    transform[3].q = *(MeshQuad_0033F920 *)origin;
    {
    s32 i;
    for (i = 0; i < 148; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = D_L01_002B1570[i][1] * D_L01_001DD124;
        temp.v[2] = D_L01_002B1570[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B1F30[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B1F30[i][0];
        if (D_L01_002B25B0[i] & 0xFF000000) {
            alpha = (s32)((f32)D_L01_001DD12F[0] * opacity);
            if (alpha < 1) alpha = 1;
            D_L01_002B25B0[i] = (alpha << 24) | D_L01_001DD128;
        } else {
            D_L01_002B25B0[i] = D_L01_001DD128;
        }
    }
    func_003D3A24(D_L01_001DD0F8, positions, D_L01_001DD110, uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 60; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = D_L01_002B1C60[i][1] * D_L01_001DD124;
        temp.v[2] = D_L01_002B1C60[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B23D0[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B23D0[i][0];
        if (D_L01_002B2800[i] & 0xFF000000) {
            alpha = (s32)((f32)D_L01_001DD12F[0] * opacity);
            if (alpha < 1) alpha = 1;
            D_L01_002B2800[i] = (alpha << 24) | D_L01_001DD128;
        } else {
            D_L01_002B2800[i] = D_L01_001DD128;
        }
    }
    func_003D3A24(D_L01_001DD0FC[0], positions, D_L01_001DD114[0], uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 148; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = -D_L01_002B1570[i][1] * D_L01_001DD124;
        temp.v[2] = D_L01_002B1570[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B1F30[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B1F30[i][0];
    }
    func_003D3A24(D_L01_001DD0F8, positions, D_L01_001DD110, uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 60; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = -D_L01_002B1C60[i][1] * D_L01_001DD124;
        temp.v[2] = D_L01_002B1C60[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B23D0[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B23D0[i][0];
    }
    func_003D3A24(D_L01_001DD0FC[0], positions, D_L01_001DD114[0], uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 148; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = D_L01_002B1570[i][1] * D_L01_001DD124;
        temp.v[2] = -D_L01_002B1570[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B1F30[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B1F30[i][0];
    }
    func_003D3A24(D_L01_001DD0F8, positions, D_L01_001DD110, uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 60; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = D_L01_002B1C60[i][1] * D_L01_001DD124;
        temp.v[2] = -D_L01_002B1C60[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B23D0[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B23D0[i][0];
    }
    func_003D3A24(D_L01_001DD0FC[0], positions, D_L01_001DD114[0], uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 148; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = -D_L01_002B1570[i][1] * D_L01_001DD124;
        temp.v[2] = -D_L01_002B1570[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B1F30[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B1F30[i][0];
    }
    func_003D3A24(D_L01_001DD0F8, positions, D_L01_001DD110, uv, 1);
    }
    {
    s32 i;
    for (i = 0; i < 60; ++i) {
        temp.v[0] = 0.0f;
        temp.v[1] = -D_L01_002B1C60[i][1] * D_L01_001DD124;
        temp.v[2] = -D_L01_002B1C60[i][0] * D_L01_001DD124;
        temp.v[3] = 1.0f;
        func_0038D028(&temp, &temp, transform);
        MeshStorePoint_0033F920(&positions[i], &temp);
        uv[i][0] = D_L01_002B23D0[i][1] + D_L01_001DD11C;
        uv[i][1] = D_L01_002B23D0[i][0];
    }
    func_003D3A24(D_L01_001DD0FC[0], positions, D_L01_001DD114[0], uv, 1);
    }
}
/* localdecomp:end func_L01_0033F920 */
