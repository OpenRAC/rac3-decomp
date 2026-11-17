#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034A740 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034A740;
typedef struct {
    u8 pad0[0xAA];
    s16 xAA;
} Other_0034A740;
typedef struct {
    u8 pad0[0x10];
    V4_0034A740 x10;
    Other_0034A740 *x20;
    u8 pad24[0x2C - 0x24];
    f32 x2C;
} Hit_0034A740;
typedef struct {
    f32 x0;
    u8 pad4[0x40 - 0x4];
    u8 x40[7];
    u8 x47;
    u8 pad48[0x60 - 0x48];
    V4_0034A740 x60;
    u8 pad70[0x74 - 0x70];
    s32 x74;
    u8 pad78[0x80 - 0x78];
    void *x80;
    u8 pad84[0xA0 - 0x84];
    u8 xA0[0x80];
    u8 x120[0x10];
} Vars_0034A740;
typedef struct {
    u8 pad0[0x10];
    V4_0034A740 pos;
    u8 x20;
    u8 pad21[0x68 - 0x21];
    Vars_0034A740 *vars;
    u8 pad6C[0xA8 - 0x6C];
    u8 xA8;
} Moby_0034A740;

__asm__(".extern D_L31_001DD1A0, 4");
__asm__(".extern D_L31_001DD19C, 4");
__asm__(".extern D_L31_001DD164, 4");
__asm__(".extern D_L31_001DD160, 4");
__asm__(".extern D_L31_001DD178, 4");
__asm__(".extern D_L31_001DD150, 4");
__asm__(".extern D_L31_001DD140, 4");
extern f32 D_L31_001DD1A0;
extern f32 D_L31_001DD19C;
extern f32 D_L31_001DD164;
extern f32 D_L31_001DD160;
extern f32 D_L31_001DD178;
extern f32 D_L31_001DD150;
extern f32 D_L31_001DD140;
extern s32 D_001A71A0[];
extern Hit_0034A740 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L31_003A1270(void *);
extern void func_003C4A40(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_0034AA20(Moby_0034A740 *, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L31_003473F0(void *, f32, f32);

void func_L31_0034A740(Moby_0034A740 *m) {
    Vars_0034A740 *v = m->vars;
    Hit_0034A740 *hit = func_L01_00447490(m, 0x10000, 0);
    V4_0034A740 push;

    func_0038CAD0(&v->x74);
    func_L01_0044ABD0(m, v->x40);
    if (hit != 0) {
        m->xA8 = 0xFF;
        if (hit->x2C > 0.0f && m->x20 != 0x42 && m->x20 != 1 && v->x74 == 0) {
            if (v->x80 != 0) {
                func_L31_003A1270(v->x80);
                v->x80 = 0;
            }
            if (hit->x20 != 0 && hit->x20->xAA == 0x15C6) {
                v->x0 = 0.0f;
            } else {
                v->x0 -= hit->x2C;
            }
            v->x74 = 12;
            v->x47 = 0xFF;
            func_003C4A40(m, v->x40);
            func_003A52A0(5, 0, m);
            if (v->x0 <= 0.0f) {
                if ((s32)hit->x20 == D_001A71A0[0]) {
                    func_003A52A0(4, 0, m);
                    func_0038CF68(&push, &hit->x10, D_L31_001DD150);
                    vec_add_ab(&v->x60, &v->x60, &push);
                }
                func_L31_0034AA20(m, 1);
            } else {
                if ((s32)hit->x20 == D_001A71A0[0]) {
                    func_003A52A0(4, 0, m);
                    func_0038CF68(&push, &hit->x10, D_L31_001DD140);
                    vec_add_ab(&v->x60, &v->x60, &push);
                }
                func_L31_0034AA20(m, 4);
            }
        }
    }
    func_L01_0044E850(m, v->xA0, 4, D_L31_001DD1A0, D_L31_001DD19C);
    func_L01_0044E850(m, v->x120, 5, D_L31_001DD164, D_L31_001DD160);
    if (m->x20 != 0x42 && m->x20 != 1) {
        func_L31_003473F0(&m->pos, D_L31_001DD178, D_L31_001DD178);
    }
}
/* localdecomp:end func_L31_0034A740 */
