#include "common.h"

/* localdecomp:start func_L39_00573DE0 */
#include "vu0.h"

typedef struct Ent_00573DE0 {
    f32 f0;
    f32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_00573DE0;

extern s32 D_L39_0024BB6C;
extern u8 D_L39_0024DE00[];
extern u8 D_001FE020[];
extern u8 D_001FE100[];
extern f32 func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern void func_L39_005F3088(s32);
extern s32 func_L39_005F3760(u32, s32);
extern s32 func_L39_005B4398(s32);

void func_L39_00573DE0(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 w;
    Ent_00573DE0 *ent;
    s32 inside;
    s32 flags;
    f32 scale;
    f32 len;
    s32 a;
    s32 b;
    vu0_q qa, qb;

    if (sub[6] == 0) return;
    if (sub[0] == -1) return;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)D_L39_0024DE00));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
    d.w = 0;
    inside = 1;
    func_0038D000(&v, &d, self + 0x50);
    if (v.x > 1.0f) {
        v.x = 1.0f;
        inside = 0;
    }
    if (v.x < -1.0f) {
        v.x = -1.0f;
        inside = 0;
    }
    if (v.y > 1.0f) {
        v.y = 1.0f;
        inside = 0;
    } else if (v.y < -1.0f) {
        v.y = -1.0f;
        inside = 0;
    }
    if (v.z > 1.0f) {
        v.z = 1.0f;
        inside = 0;
    } else if (v.z < -1.0f) {
        v.z = -1.0f;
        inside = 0;
    }
    ent = (Ent_00573DE0 *)(sub[0] * 32 + D_L39_0024BB6C);
    flags = 0;
    if (ent->f18) flags |= 4;
    if (inside == 1) {
        {
            s32 idx = sub[4];
            u8 *slot;

            if (idx != -1) {
                slot = D_001FE020 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F3088(idx);
            }
        }
        sub[4] = -1;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx == -1 || (slot = D_001FE020 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                if (func_0038CAD0(sub + 3)) {
                    sub[5] = func_L39_005F35D8(sub[0], flags | 0x110, self, 0x400);
                    if (sub[2] > 0) {
                        sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
                    }
                }
            } else {
                func_L39_005F3760(idx, ent->fC);
            }
        }
        return;
    }
    scale = 1.0f;
    func_0038D000(&v, &v, self + 0x10);
    {
        vu0_q pa, pb;

        __asm__("lqc2 %0, %1" : "=j"(pb) : "m"(*(vu0_v4 *)(self + 0x40)));
        __asm__("lqc2 %0, %1" : "=j"(pa) : "m"(v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(pa) : "j"(pa), "j"(pb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(pa));
    }
    {
        vu0_q ra, rb;

        __asm__("lqc2 %0, %1" : "=j"(ra) : "m"(*(vu0_v4 *)D_L39_0024DE00));
        __asm__("lqc2 %0, %1" : "=j"(rb) : "m"(v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(ra) : "j"(ra), "j"(rb));
        __asm__("sqc2 %1, %0" : "=m"(w) : "j"(ra));
    }
    len = func_0038CEA8(&w);
    if (ent->f4 < len) {
        {
            s32 idx = sub[4];
            u8 *slot;

            if (idx != -1) {
                slot = D_001FE020 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F3088(idx);
            }
        }
        sub[4] = -1;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx != -1) {
                slot = D_001FE020 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F3088(idx);
            }
        }
        sub[5] = -1;
    } else {
        scale = len * (scale / (ent->f4 - ent->f0));
    }
    if (scale < 0.2f) {
        f32 t = (0.2f - scale) * 5.0f;
        f32 u = 1.0f - t;
        f32 k = ent->fC / sqrt_asm(t * t + u * u);

        b = t * k;
        a = u * k;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx == -1 || (slot = D_001FE020 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                sub[5] = func_L39_005F35D8(sub[0], flags | 0x110, self, 0x400);
            }
        }
        func_L39_005F3760(sub[5], b);
    } else {
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx != -1) {
                slot = D_001FE020 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) {
                    func_L39_005F3088(idx);
                    sub[5] = -1;
                }
            }
        }
        a = ent->fC * (1.0f - scale);
    }
    {
        s32 idx = sub[4];
        u8 *slot;

        if (idx == -1 || (slot = D_001FE020 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
            if (a > 0) sub[4] = func_L39_005F35D8(sub[0], flags | 0x10, self, 0x400);
        }
    }
    if (sub[4] != -1) {
        *(vu0_q *)(D_001FE100 + (sub[4] << 7)) = *(vu0_q *)&v;
    }
    func_L39_005F3760(sub[4], a);
}
/* localdecomp:end func_L39_00573DE0 */

/* localdecomp:start func_L39_00574308 */
#include "vu0.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} Sub_00574308;
typedef struct { f32 x, y, z; s32 w; } __attribute__((aligned(16))) V_00574308;

extern u8 D_L39_0024DE00[];
extern u8 D_001FE020[];
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern f32 func_0038D000(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);

void func_L39_00574308(u8 *self) {
    V_00574308 a;
    V_00574308 b;
    V_00574308 ra;
    V_00574308 rb;
    V_00574308 v;
    vu0_q qa, qs, qv, qp;
    Sub_00574308 *sub;
    f32 s;
    u8 *slot;
    s32 n;

    __asm__("lqc2 %0, %1" : "=j"(qs) : "m"(*(vu0_v4 *)D_L39_0024DE00));
    sub = *(Sub_00574308 **)(self + 8);
    s = *(f32 *)(self + 0xC);
    b.x = s;
    b.y = s;
    b.z = s;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qs) : "j"(qs), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qs));
    a.w = 0;
    func_0038D000(&ra, &a, self + 0x50);
    func_0038D000(&rb, &b, self + 0x50);
    if (fabs_asm(rb.x) + 1.0f >= fabs_asm(ra.x)
        && fabs_asm(rb.y) + 1.0f >= fabs_asm(ra.y)
        && fabs_asm(rb.z) + 1.0f >= fabs_asm(ra.z)) {
        slot = D_001FE020 + (sub->w10 << 7);
        if (*(u8 **)(slot + 0x100) == self && *(slot + 0xD0) != 0) {
            return;
        }
        if (func_0038CAD0(&sub->wC) != 0) {
            n = func_L39_005F35D8(sub->w0, 0, self, 0x400);
            sub->w10 = n;
            if (n != -1) {
                v.x = func_L39_005B4410(-1.0f, 1.0f);
                v.y = func_L39_005B4410(-1.0f, 1.0f);
                v.z = func_L39_005B4410(-1.0f, 1.0f);
                func_0038D000(&v, &v, self + 0x10);
                __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(self + 0x40)));
                __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
                __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qv));
                *(vu0_q *)(D_001FE020 + (sub->w10 << 7) + 0xE0) = *(vu0_q *)&v;
            }
            if (sub->w8 > 0) {
                sub->wC = (s32)((f32)(sub->w4 + func_L39_005B4398(sub->w8 - sub->w4)) * 50.0f);
            }
        } else {
            sub->w10 = -1;
        }
    }
}
/* localdecomp:end func_L39_00574308 */

/* localdecomp:start func_L39_00574518 */
#include "vu0.h"

extern s32 D_002412DC;
__asm__(".extern D_002412DC, 16");
extern s32 *D_00241120;
extern u8 *func_L39_0061BF38(s32);
extern f32 func_0038D000(void *, void *, void *);
extern void func_L39_005F38D0(s32, s32, s32, s32, s32);

void func_L39_00574518(u8 *a0)
{
    u8 *s = *(u8 **)(a0 + 8);
    vu0_v4 d;
    vu0_v4 o;
    vu0_v4 t;
    s32 v;

    if (D_002412DC == 0x30 || D_002412DC == 0x15) {
        func_L39_005F38D0(0, s[0], *(s32 *)(s + 4), s[1], s[2]);
        return;
    }
    if (*D_00241120 < 2) {
        *(vu0_q *)&t = *(vu0_q *)(func_L39_0061BF38(0) + 0xA0);
        vec_sub_ba(&d, &t, a0 + 0x40);
        d.w = 0.0f;
        func_0038D000(&o, &d, a0 + 0x50);
        if (fabs_asm(o.x) <= 1.0f && fabs_asm(o.y) <= 1.0f && fabs_asm(o.z) <= 1.0f) {
            v = (f32)*(s32 *)(s + 4) * ((o.x + 1.0f) * 0.5f);
            if (*(s32 *)(s + 4) < v) {
                v = *(s32 *)(s + 4);
            }
            func_L39_005F38D0((s32)a0, s[0], v, s[1], s[2]);
            s[3] = 1;
        } else if (s[3] != 0) {
            if (o.x > 0.0f) {
                func_L39_005F38D0(0, s[0], *(s32 *)(s + 4), s[1], s[2]);
            } else {
                func_L39_005F38D0((s32)a0, 0, 0, 0, 0);
            }
            s[3] = 0;
        }
    }
}
/* localdecomp:end func_L39_00574518 */

/* localdecomp:start func_L39_005746B8 */
#include "vu0.h"

typedef struct {
    s32 w0;
    f32 f4;
    s32 w8;
} Sub_005746B8;

typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xF];
    vu0_v4 posE0;
    u8 padF0[0x10];
    void *p100;
} Slot_005746B8;

extern u8 D_L39_0024DE00[];
extern u8 D_001FE020[];
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
__asm__(".extern D_L39_0024B798, 4");
__asm__(".extern D_001D5A8C_sda, 4");
extern f32 D_L39_0024B798 __attribute__((section(".sdata")));   /* level data: $gp + 0x37D8 in level 39 */
extern f32 D_001D5A8C_sda;
typedef struct {
    u8 pad0[0x148];
    f32 f148;
} G_005746B8;
extern G_005746B8 D_L39_0024DCC0;
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00451768(vu0_v4 *);
extern s32 func_L39_005F3760(u32, s32);

void func_L39_005746B8(u8 *self) {
    vu0_v4 pt;
    vu0_v4 a;
    vu0_v4 axis;
    Sub_005746B8 *sub;
    Slot_005746B8 *slot;
    Slot_005746B8 *cur;
    vu0_v4 *pos;
    vu0_q qp, qc;
    f32 count;
    f32 angle;

    sub = *(Sub_005746B8 **)(self + 8);
    count = 0.0f;
    a.x = 4.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    angle = 0.0f;
    do {
        pos = (vu0_v4 *)D_L39_0024DE00;
        func_0038D890(&pt, &a, &axis, angle);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(pt));
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(pt) : "j"(qc));
        if (func_L01_00451768(&pt) < D_L39_0024DCC0.f148) {
            count += 0.05f;
        }
        angle += 0.31415927f;
    } while (angle < 6.2831855f);
    if (D_L39_0024B798 < count) {
        D_L39_0024B798 = D_L39_0024B798 + D_001D5A8C_sda * 0.2f;
    } else {
        D_L39_0024B798 = D_L39_0024B798 - D_001D5A8C_sda * 0.75f;
    }
    if (1.0f < D_L39_0024B798) {
        D_L39_0024B798 = 1.0f;
    } else if (D_L39_0024B798 < 0.0f) {
        D_L39_0024B798 = 0.0f;
    }
    slot = (Slot_005746B8 *)(D_001FE020 + (sub->w8 << 7));
    if (slot->p100 == self && slot->bD0 != 0) {
        func_L39_005F3760(sub->w8, (s32)((sub->f4 + D_L39_0024B798) / (sub->f4 + 1.0f) * 1024.0f));
    }
    pos = &((Slot_005746B8 *)(D_001FE020 + (sub->w8 << 7)))->posE0;
    *(vu0_q *)pos = *(vu0_q *)D_L39_0024DE00;
    cur = (Slot_005746B8 *)(D_001FE020 + (sub->w8 << 7));
    if (cur->p100 != self || cur->bD0 == 0) {
        sub->w8 = func_L39_005F35D8(sub->w0, 0x15, self, 0x400);
    }
}
/* localdecomp:end func_L39_005746B8 */
