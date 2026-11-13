#include "common.h"

/* declared by functions of L39_00573DE0.c, which this file was cut from */
extern u8 D_L39_0024DE00[];
extern u8 D_001FE100[];
extern u8 D_001FE020[];
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern void func_L39_005F3088(s32);

/* localdecomp:start func_L39_00574A10 */
#include "vu0.h"

extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045F1E8(s32 a0, s32 a1);

void func_L39_00574A10(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    vu0_v4 d;
    vu0_v4 v;
    vu0_q qa, qb, qr;

    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)D_L39_0024DE00));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qr));
    d.w = 0;
    func_0038D000(&v, &d, self + 0x50);
    if (fabs_asm(v.x) <= 1.0f && fabs_asm(v.y) <= 1.0f && fabs_asm(v.z) <= 1.0f) {
        sub[2] = 1;
    } else if (sub[2] != 0) {
        if (v.x < 0.0f) {
            func_L01_0045F1E8(sub[1], sub[4]);
        } else {
            func_L01_0045F1E8(sub[0], sub[3]);
        }
        sub[2] = 0;
    }
}
/* localdecomp:end func_L39_00574A10 */

/* localdecomp:start func_L39_00574AF0 */
#include "vu0.h"

typedef struct Ent_00574AF0 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_00574AF0;

extern s32 D_L39_0024BB6C;
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F1130(void *, s32, f32, f32, f32);
extern s32 func_L39_005F3760(u32, s32);
extern s32 func_L39_005B4398(s32);

void func_L39_00574AF0(u8 *self) {
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

    s.z = s.y = s.x = *(f32 *)(self + 0xC);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)D_L39_0024DE00));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
    d.w = 0;
    func_0038D000(&v, &d, self + 0x50);
    func_0038D000(&w, &s, self + 0x50);
    lw = func_0038CEA8(&w);
    lv = func_0038CEA8(&v);
    if (lv < lw) {
        flags = 0x10;
        if (fabs_asm(v.x) <= 1.0f && fabs_asm(v.y) <= 1.0f && fabs_asm(v.z) <= 1.0f) {
            id = ((Ent_00574AF0 *)D_L39_0024BB6C)[sub[0]].fC;
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
            r = func_0038CEA8(&v);
            id = func_L39_005F1130(&((Ent_00574AF0 *)D_L39_0024BB6C)[sub[0]], 0, lv, r, lw);
        }
        if (((Ent_00574AF0 *)D_L39_0024BB6C)[sub[0]].f18) {
            flags = 0x14;
        }
        slot = D_001FE020 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            if (func_0038CAD0(sub + 3)) {
                sub[4] = func_L39_005F35D8(sub[0], flags, self, id);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
                }
            } else {
                sub[4] = -1;
            }
        }
        if (sub[4] != -1) {
            func_L39_005F3760(sub[4], id);
            func_0038D000(&d, &v, self + 0x10);
            {
                vu0_q pa, pb, pr;

                __asm__("lqc2 %0, %1" : "=j"(pb) : "m"(*(vu0_v4 *)(self + 0x40)));
                __asm__("lqc2 %0, %1" : "=j"(pa) : "m"(d));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(pr) : "j"(pa), "j"(pb));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(pr));
            }
            *(vu0_q *)(D_001FE100 + (sub[4] << 7)) = *(vu0_q *)&d;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001FE020 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) {
                func_L39_005F3088(index);
            }
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00574AF0 */
