#include "common.h"

/* NTSC-U counterpart of func_L39_00574AF0 (src/levels/shared/L39_00574A10.c) */
extern u8 D_L39_0024DF00[];
extern u8 D_L39_001FE280[];
extern u8 D_L39_001FE1A0[];
extern s32 func_L39_005F0ED8(s32, s32, void *, s32);
extern void func_L39_005F0988(s32);
#include "vu0.h"
extern void func_003888C8(void *, void *, void *);

/* localdecomp:start func_L39_00573DC8 */
#include "vu0.h"

typedef struct Ent_00574AF0 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_00574AF0;

extern s32 D_L39_0024BC6C;
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern s32 func_L39_005EEBC0(void *, s32, f32, f32, f32);
extern s32 func_L39_005F1060(u32, s32);
extern s32 func_L39_005B2498(s32);

void func_L39_00573DC8(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 v;
    vu0_v4 w;
    f32 lw;
    f32 lv;
    f32 r;
    s32 flags;
    s32 id;
    u8 *slot;
    vu0_q qa, qb;
    vu0_v4 *camera = (vu0_v4 *)D_L39_0024DF00;

    s.z = s.y = s.x = *(f32 *)(self + 0xC);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*camera));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
    d.w = 0;
    func_003888C8(&v, &d, self + 0x50);
    func_003888C8(&w, &s, self + 0x50);
    lw = func_00388770(&w);
    lv = func_00388770(&v);
    if (lv < lw) {
        flags = 0x10;
        if (fabs_asm(v.x) <= 1.0f && fabs_asm(v.y) <= 1.0f && fabs_asm(v.z) <= 1.0f) {
            id = ((Ent_00574AF0 *)D_L39_0024BC6C)[sub[0]].fC;
        } else {
            if (v.x > 1.0f) {
                v.x = 1.0f;
            } else if (v.x < -1.0f) {
                v.x = -1.0f;
            }
            if (v.y > 1.0f) {
                v.y = 1.0f;
            } else if (v.y < -1.0f) {
                v.y = -1.0f;
            }
            if (v.z > 1.0f) {
                v.z = 1.0f;
            } else if (v.z < -1.0f) {
                v.z = -1.0f;
            }
            r = func_00388770(&v);
            id = func_L39_005EEBC0(&((Ent_00574AF0 *)D_L39_0024BC6C)[sub[0]], 0, lv, r, lw);
        }
        if (((Ent_00574AF0 *)D_L39_0024BC6C)[sub[0]].f18) {
            flags = 0x14;
        }
        slot = D_L39_001FE1A0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            if (func_00388398(sub + 3)) {
                sub[4] = func_L39_005F0ED8(sub[0], flags, self, id);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_L39_005B2498(sub[2] - sub[1])) * 60.0f);
                }
            } else {
                sub[4] = -1;
            }
        }
        if (sub[4] != -1) {
            func_L39_005F1060(sub[4], id);
            func_003888C8(&d, &v, self + 0x10);
            {
                vu0_q pa, pb, pr;

                __asm__("lqc2 %0, %1" : "=j"(pb) : "m"(*(vu0_v4 *)(self + 0x40)));
                __asm__("lqc2 %0, %1" : "=j"(pa) : "m"(d));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(pr) : "j"(pa), "j"(pb));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(pr));
            }
            *(vu0_q *)(D_L39_001FE280 + (sub[4] << 7)) = *(vu0_q *)&d;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_L39_001FE1A0 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) {
                func_L39_005F0988(index);
            }
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00573DC8 */
