#include "common.h"

/* localdecomp:start func_L39_0055F8D8 */
#include "vu0.h"
typedef struct { f32 x, y, z; s32 w; } __attribute__((aligned(16))) V_0055F8D8;
typedef struct {
    u8 pad0[0x1F8];
    f32 f1F8[1];
} T_0055F8D8;
__asm__(".extern D_L39_0024B3E0, 4");
__asm__(".extern D_L39_0024B3FC, 4");
__asm__(".extern D_L39_0024B400, 4");
extern f32 D_L39_0024B3E0;
extern f32 D_L39_0024B3FC;
extern f32 D_L39_0024B400;
extern T_0055F8D8 D_L39_00352940;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L39_0061D7B0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);

void func_L39_0055F8D8(void *a0, u8 *a1) {
    V_0055F8D8 v;
    V_0055F8D8 pos;
    V_0055F8D8 d;
    V_0055F8D8 q;
    u8 *r;
    u8 *m;
    f32 dist;
    f32 off;
    f32 len;
    s32 i;

    m = 0;
    q.x = ((f32 *)*(void **)(a1 + 0x220))[0] * 0.0009765625f;
    q.y = ((f32 *)*(void **)(a1 + 0x220))[1] * 0.0009765625f;
    q.z = ((f32 *)*(void **)(a1 + 0x220))[2] * 0.0009765625f;
    q.w = 0;
    func_003C2F58(a0, 2, &v);
    pos = q;
    r = func_L39_0061D7B0(*(void **)(a1 + 0x220));
    if (r != 0 && (r[3] & 0xF) == 0) {
        m = r;
    }
    if (m != 0) {
        dist = 23.0f;
        if (func_L01_0040E548(&q, &v) < 4.0f) {
            dist = 15.0f;
        }
        dist = dist + dist * *(f32 *)(a1 + 0x218);
        i = *(s32 *)(a1 + 0x22C);
        if (i >= 0) {
            off = D_L39_00352940.f1F8[i];
        } else {
            off = 0.0f;
        }
        len = func_0038CF00(&q, &v);
        func_0038CE20(&d, m + 0x140, len / (dist * 0.020000001f));
        func_0038CE20(&d, &d, off);
        vec_add_ab(&pos, &pos, &d);
    }
    vec_sub_ab(&d, &pos, &v);
    *(f32 *)(a1 + 0x210) = func_0038DAB8(func_0038D160(d.x, d.y), D_L39_0024B3E0 * 0.017453292f);
    *(f32 *)(a1 + 0x214) = -func_0038D160(func_0038CED8(&d), d.z);
    if (*(s32 *)(a1 + 0x230) != 0) {
        if (D_L39_0024B400 < *(f32 *)(a1 + 0x214)) {
            *(f32 *)(a1 + 0x214) = D_L39_0024B400;
        }
        if (*(f32 *)(a1 + 0x214) < D_L39_0024B3FC) {
            *(f32 *)(a1 + 0x214) = D_L39_0024B3FC;
        }
    }
}
/* localdecomp:end func_L39_0055F8D8 */
