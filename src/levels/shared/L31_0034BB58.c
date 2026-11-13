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

INCLUDE_ASM("asm/levels", func_L31_0034BB58);

INCLUDE_ASM("asm/levels", func_L31_0034BCA8);

INCLUDE_ASM("asm/levels", func_L31_0034BF90);

INCLUDE_ASM("asm/levels", func_L31_0034C5A0);

/* localdecomp:start func_L31_0034CA18 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034CA18;

typedef struct {
    u8 pad0[0x120];
    V4_0034CA18 pos;
    u8 pad130[0x138 - 0x130];
    s32 w138;
    f32 f13C;
} Vars_0034CA18;

typedef struct {
    u8 pad0[0x68];
    Vars_0034CA18 *vars;
} Moby_0034CA18;

__asm__(".extern D_L31_001DD27C, 4");
__asm__(".extern D_L31_001DD28C, 4");
__asm__(".extern D_L31_001DD288, 4");
__asm__(".extern D_L31_001DD274, 4");
__asm__(".extern D_L31_001DD298, 4");
__asm__(".extern D_L31_001DD294, 4");
__asm__(".extern D_L31_001DD270, 4");
__asm__(".extern D_L31_001DD284, 4");
__asm__(".extern D_L31_001DD280, 4");
__asm__(".extern D_L31_001DD290, 4");
__asm__(".extern D_L31_001DD278, 4");
__asm__(".extern D_L31_001DD26C, 4");
__asm__(".extern D_L31_001DD264, 4");
extern s32 D_001A71A0[];
extern f32 D_L31_001DD27C;
extern f32 D_L31_001DD28C;
extern f32 D_L31_001DD288;
extern f32 D_L31_001DD274;
extern f32 D_L31_001DD298;
extern f32 D_L31_001DD294;
extern f32 D_L31_001DD270;
extern f32 D_L31_001DD284;
extern f32 D_L31_001DD280;
extern f32 D_L31_001DD290;
extern s32 D_L31_001DD278;
extern f32 D_L31_001DD26C;
extern s32 D_L31_001DD264;
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
/* the definition (L31_003ABC08.c) lists its ints first; ints and floats take registers apart, and
 * this interleaving gives retail's argument-move order */
extern u8 *func_L31_003AC0B0(vu0_q *, vu0_q *, s32, s32, f32, f32, s32, s32, f32, f32);

void func_L31_0034CA18(Moby_0034CA18 *m) {
    Vars_0034CA18 *v = m->vars;
    V4_0034CA18 dir;
    V4_0034CA18 pos;
    f32 r;
    f32 t;
    f32 s;

    if (v->w138 == 0) {
        return;
    }
    func_L01_004AAC98(1, 0, D_001A71A0[0], 0x165E);
    v->f13C += D_L31_001DD27C;
    if (!(1.0f < v->f13C)) {
        return;
    }
    r = func_003824E0(D_L31_001DD28C, D_L31_001DD288);
    v->f13C -= 1.0f;
    pos = v->pos;
    pos.z += func_003824E0(-D_L31_001DD274, D_L31_001DD274);
    qzero(&dir);
    if (v->w138 == 1) {
        dir.x = func_003824E0(D_L31_001DD298, D_L31_001DD294);
        pos.x += D_L31_001DD270;
    } else {
        dir.x = -func_003824E0(D_L31_001DD298, D_L31_001DD294);
        pos.x -= D_L31_001DD270;
    }
    t = func_003C4088(D_L31_001DD284, D_L31_001DD280,
                      (r - D_L31_001DD28C) / (D_L31_001DD288 - D_L31_001DD28C));
    s = func_003824E0(-D_L31_001DD290, D_L31_001DD290);
    func_L31_003AC0B0((vu0_q *)&pos, (vu0_q *)&dir, D_L31_001DD278, 0, r, D_L31_001DD26C, D_L31_001DD264, (s32)m, t, s);
}
/* localdecomp:end func_L31_0034CA18 */
