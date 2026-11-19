#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3D41E8 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x3C4];
    s16 x3C4;
    s16 x3C6;
    u8 p3C8[8];
    u8 x3D0;
    u8 x3D1;
    u8 x3D2;
    u8 p3D3;
    f32 x3D4;
    f32 x3D8;
    f32 x3DC;
    u8 p3E0[0xC];
    s32 x3EC;
} V_3D41E8;
typedef struct {
    u8 p0[0x10];
    s128_3D41E8 x10;
    u8 p20[3];
    u8 x23;
    u8 p24[0xC];
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D41E8 *x68;
    u8 p6C[0x10];
    u16 x7C;
    u8 p7E[0x42];
    u8 xC0[1];
} M_3D41E8;
typedef struct {
    u8 pad0[0x40];
    u8 mtx[0x15];
    u8 alpha;
    u8 pad56[0x60 - 0x56];
} Elem_003D4478;
typedef struct {
    Elem_003D4478 elem[10];
    u8 pad[0x3C4 - 0x3C0];
    s16 h3C4;
    s16 h3C6;
    u8 pad3C8[0x3D0 - 0x3C8];
    u8 mode;
    u8 pad3D1;
    u8 count;
    u8 pad3D3[0x3D8 - 0x3D3];
    f32 w;
    f32 h;
    u8 pad3E0[0x3EC - 0x3E0];
    u32 color;
} Hdr_003D4478;
typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_003D4478;
typedef struct {
    u8 pad[0x68];
    Hdr_003D4478 *data;
} Moby_003D4478;
typedef int u128_3D6FB0 __attribute__((mode(TI)));
struct M_3D6FB0;
typedef struct { struct M_3D6FB0 *arr[15]; s16 h3C; u8 p3E[2]; f32 f40; f32 f44; u8 b48; u8 b49; u8 b4A; u8 b4B; } V_3D6FB0;
typedef struct M_3D6FB0 {
    u8 p0[0x10]; u128_3D6FB0 pos; u8 p20[0x10];
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_3D6FB0 *w68;
} M_3D6FB0;



/* localdecomp:start func_L01_003CFFB0 */
__asm__(".extern D_L01_001DF320, 4");
__asm__(".extern D_L01_001DF324, 4");
__asm__(".extern D_L01_001DF328, 4");
__asm__(".extern D_L01_001DF32C, 4");
__asm__(".extern D_L01_001DF330, 4");
__asm__(".extern D_L01_001DF334, 4");
typedef struct Particle_003D1900 {
    f32 pos[4];
    f32 size, age, angle, spin, scale;
    s32 color;
    struct Particle_003D1900 *next;
} Particle_003D1900;
extern f32 D_L01_001DF320;
extern f32 D_L01_001DF324;
extern f32 D_L01_001DF328;
extern f32 D_L01_001DF32C;
extern f32 D_L01_001DF330;
extern f32 D_L01_001DF334;
u8 *func_L01_003CFFB0(u8 *obj, u8 *state, f32 *pos, f32 scale) {
    extern f32 func_L01_00440978(void);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_L01_004408C0(f32, f32);
    extern s32 func_L01_0040D020(s32, s32, f32);
    Particle_003D1900 *p = *(Particle_003D1900 **)(state + 0x138);
    if (p == 0) return 0;
    *(Particle_003D1900 **)(state + 0x138) = p->next;
    *(u128_t *)p = *(u128_t *)pos;
    p->angle = func_L01_00440978();
    p->spin = func_L01_00440918(D_L01_001DF320 * 0.017453292f * 0.0166666675f, D_L01_001DF324 * 0.017453292f * 0.0166666675f);
    p->size = func_L01_004408C0(D_L01_001DF328, D_L01_001DF32C);
    p->scale = func_L01_004408C0(D_L01_001DF330, D_L01_001DF334) * scale;
    p->age = 0.0f;
    p->color = func_L01_0040D020(*(s32 *)(state + 0x14), *(s32 *)(state + 0x18), func_L01_004408C0(p->age, 1.0f));
    if (*(Particle_003D1900 **)(state + 0x13C)) {
        Particle_003D1900 *q = *(Particle_003D1900 **)(state + 0x13C);
        if (p->pos[2] < q->pos[2]) {
            p->next = q;
            *(Particle_003D1900 **)(state + 0x13C) = p;
        } else {
            while (q->next && q->next->pos[2] < p->pos[2]) q = q->next;
            p->next = q->next;
            q->next = p;
        }
    } else {
        *(Particle_003D1900 **)(state + 0x13C) = p;
        p->next = 0;
    }
    return (u8 *)p;
}
/* localdecomp:end func_L01_003CFFB0 */
