/* functional: medium. Same calls/arguments/order as retail. Retail reuses one stack area for the spark temps and the collision query record; here the query record is its own struct and, on the path where retail reads the uninitialised spark position (flag && D_001DFB40 & 1), its position is zeroed first. */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    s16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[12];
} Q_003036D8 __attribute__((aligned(16)));

extern f32 D_001DFB4C;
extern f32 D_001DFB50;
extern s32 D_001DFB40;
extern u8 D_001D66B0;
extern u8 *D_L01_001EAA18;

extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);

void func_L01_003036D8(u8 *self) {
    Q_003036D8 q;
    vu0_v4 p;
    vu0_v4 v40;
    vu0_v4 v50;
    u8 *st;
    u8 *target;
    s32 flag;
    s32 hit;
    f32 len;
    f32 r;
    f32 f;

    if (self[0x20] != 0) {
        return;
    }
    st = *(u8 **)(self + 0x68);
    *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), 0.12566371f);
    flag = 0;
    vec_add_ba(&p, self + 0x10, st);
    if (0.9f < D_001DFB4C) {
        flag = 1;
    } else if (0.9f < D_001DFB50) {
        flag = 1;
    }
    q.pos.x = 0.0f;
    q.pos.y = 0.0f;
    q.pos.z = 0.0f;
    q.pos.w = 0.0f;
    if (flag == 0 || (D_001DFB40 & 1) == 0) {
        len = func_0038CEA8(st);
        qzero(&v50);
        v50.x = func_003824E0(-1.0f, 1.0f);
        v50.y = func_003824E0(-1.0f, 1.0f);
        v50.z = func_003824E0(-1.0f, 1.0f);
        v40 = v50;
        r = func_003824E0(0.04f, 0.08f);
        func_0038CF68(&v40, &v40, r * 0.02f);
        f = func_003824E0(0.2f, 0.99f);
        func_0038CE20(&q.pos, st, f);
        vec_add_ba(&v40, &v40, &q.pos);
        r = func_003824E0(0.0f, 1.0f);
        func_0038CF68(&q.pos, st, r * len);
        vec_add_ab(&q.pos, &q.pos, self + 0x10);
        func_L01_0046A610(self + 0x10, &v40, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        qzero(&v50);
        v50.z = 0.01f;
        func_0038D000(&v50, &v50, self + 0xC0);
        r = func_00382538();
        func_0038D890(&v50, &v50, self + 0xC0, r);
        if ((func_0013D3E0() & 1) != 0) {
            func_L01_00466588(&q.pos, &v50, 0x4F007FFF, 0x1FFFFFFF, 0xB, 1, 25000.0f);
        }
    }
    func_L01_00446760(&q.pos, *(u8 **)(st + 0x3C), 0x10001, st, *(f32 *)(st + 0x40));
    q.h1A = *(u16 *)(self + 0xAA);
    vec_sub_ab(&q.pos, self + 0x10, *(u8 **)(st + 0x3C) + 0x10);
    *(f32 *)((u8 *)&q.pos + 8) = 0.0f;
    func_0038CF68(&q.pos, &q.pos, 2.0000002f);
    q.b18 = 4;
    *(f32 *)((u8 *)&q.pos + 0xC) = 5627.9248f;
    q.flags = q.flags | 1;
    func_L01_004CB320();
    hit = func_003D3CB0(self + 0x10, &p, 0, *(u8 **)(st + 0x3C), &q);
    if (hit != 0) {
        target = D_L01_001EAA18;
        if (target != 0 && *(s16 *)(target + 0xAA) == 0x186D && target[0x20] != 2 && target[0x20] != 5) {
            target[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit == 0) {
        if (func_L01_003FB640(self + 0x10, 1, *(u8 **)(st + 0x3C), 0.3f) == 0) {
            if (func_0038CAD0(st + 0x38) == 0) {
                *(vu0_v4 *)(self + 0x10) = p;
                return;
            }
        }
    }
    target = D_L01_001EAA18;
    if (target != 0) {
        if (target == *(u8 **)(st + 0x3C)) {
            *(vu0_v4 *)(self + 0x10) = p;
            return;
        }
        if (*(s16 *)(target + 0xAA) != 0x4E) {
            func_003D4D00(self + 0x10, 0, *(u8 **)(st + 0x3C), &q, 0.5f);
        }
        func_L01_0044AF78(self, &D_001D66B0, 0, 0, 2, 0xA, -1, 0, 1, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.666f, 0.0f);
    } else {
        func_L01_0044AF78(self, &D_001D66B0, 0, 0, 2, 8, -1, 0, 1, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.5f, 0.0f);
    }
    func_003A52A0(0, 0, self);
    func_003C2880(self);
}
