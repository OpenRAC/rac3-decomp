#include "common.h"

/* NTSC-U counterpart of func_L39_00561FF8 (src/levels/shared/L39_00561FF8.c) */
/* localdecomp:start func_L39_00561500 */
#include "vu0.h"

typedef struct { u8 *g; s32 pad; f32 v[4]; } S_00561FF8;

extern u8 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern S_00561FF8 D_L39_0025F858;
extern u8 D_L39_00242AB0[] __attribute__((section(".sdata")));
extern u8 D_L39_002FB100[];
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005FD6D8(void);
extern f32 func_003887C8(void *, void *);
extern void func_L07_003CA7C0(void *);
extern void func_L39_00561D48(void *, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L07_003C9808(void *);

static __inline__ void step_00561FF8(vu0_v4 *out, u8 *pos, u8 *vel) {
    if (*(f32 *)(vel + 0x20) < func_00388770(vel)) {
        vec_add_ab(out, pos, vel);
    } else {
        func_00388830(out, vel, *(f32 *)(vel + 0x20));
        vec_add_ab(out, out, pos);
    }
}

static __inline__ s32 coll_00561FF8(void *from, void *to, s32 flags, void *ign, void *info, s32 player) {
    u8 *p = D_L39_0024CF20[player];
    s32 hit;

    player = -1;
    if (p != 0) {
        player = *(s32 *)(p + 0x2548);
    }
    func_L39_005FD658(player);
    hit = func_003CE740(from, to, flags, ign, info);
    func_L39_005FD6D8();
    return hit;
}

void func_L39_00561500(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    vu0_v4 old;
    vu0_v4 v;
    u8 b[0x30] __attribute__((aligned(16)));
    s32 hit;
    s32 n;
    f32 f;

    old = *(vu0_v4 *)(o + 0x10);
    if (o[0x20] == 0) {
        if (func_L01_00452EC8(o) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, st);
        }
        if (func_00388398(st + 0x24) != 0) {
            func_003BD360(o);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            step_00561FF8(&v, o + 0x10, st);
            func_L01_00443628(b, o, 0x10001, D_L39_00242AB0, *(f32 *)(st + 0x34));
            *(s32 *)(b + 0x28) = *(s32 *)(st + 0x44);
            hit = coll_00561FF8(o + 0x10, &v, 0x10, *(void **)(o + 0xB8), b, *(s32 *)(st + 0x40));
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)D_L39_0025F858.v;
                f = func_003887C8(o + 0x10, st + 0x10) / func_00388770(st);
                n = (s32)f;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / n;
                if (D_L39_0025F858.g == 0) {
                    func_L07_003CA7C0(o);
                } else {
                    func_L39_00561D48(st + 0x10, D_L39_002FB100);
                }
            }
        }
        func_L01_004026A0(func_L07_003C9808, o);
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L39_00561500 */
