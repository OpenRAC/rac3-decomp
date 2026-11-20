#include "common.h"
#include "vu0.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    u8 pad0[208];
    s32 table[35];
    s32 index;
} Obj329158;

/* localdecomp:start func_L05_00328BF8 */
typedef struct {
    u8 pad0[208];
    s32 table[35];
    s32 index;
} Obj329158_00328BF8;
typedef struct {
    u8 pad0[144];
    s32 next[4];
    s32 ids[47];
    s32 cur;
} S_00328BF8;

extern void func_L05_0032AB50_00328BF8(u8 *, u8 *);
extern void func_L05_003298C0_00328BF8(u8 *, u8 *);
extern void func_L05_00328F00_00328BF8(u8 *o, u8 *s);
extern s32 func_L05_00328FF8_00328BF8(s32 a0);
extern void func_L05_00329A78_00328BF8(s32 a0, Obj329158_00328BF8 *obj);
extern s32 func_L05_00329AD0_00328BF8();
extern void func_L01_004450F0_00328BF8(void *, s32, s32);
extern s32 func_L05_00329050_00328BF8(u8 *a0, u8 *a1, s32 a2);
extern void func_L05_0032A0B0_00328BF8(u8 *a0, u8 *a1, s32 a2, s32 a3);
extern s32 func_L05_00329DA8_00328BF8(u8 *a0, u8 *a1);
extern void func_L05_00329ED0_00328BF8();
extern s32 func_L05_0032A4D8_00328BF8(u8 *, u8 *);
extern void func_L05_00329C68_00328BF8(s32 a0, u8 *a1);
extern void func_L05_00329C58_00328BF8(s32 arg0, void *arg1);
extern void func_L05_00329CA0_00328BF8(void *a0, u8 *a1, f32 *a2, f32 *a3, f32 *a4);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L05_00329BC8_00328BF8(s32 a0, u8 *a1);
extern void func_L05_00329120_00328BF8(u8 *m, u8 *v);
extern void func_L05_003293B0_00328BF8(u8 *, u8 *, Vec4 *);
extern void func_L05_003296F8_00328BF8(u8 *o, u8 *s);

void func_L05_00328BF8(u8 *self) {
    Vec4 pos;
    Vec4 rot;
    Vec4 delta;
    f32 dx;
    f32 dy;
    f32 dz;
    u8 *v;
    s32 n;
    f32 *rp;

    v = *(u8 **)(self + 104);
    if (self[32] == 0) {
        func_L05_0032AB50_00328BF8(self, v);
    }
    pos = *(Vec4 *)(self + 16);
    rot = *(Vec4 *)(self + 240);
    *(Vec4 *)(self + 16) = *(Vec4 *)(v + 432);
    *(Vec4 *)(self + 240) = *(Vec4 *)(v + 448);
    func_L05_003298C0_00328BF8(self, v);
    switch (self[32]) {
    case 1:
        func_L05_00328F00_00328BF8(self, v);
        if (*(s32 *)(v + 112) != 0) {
            func_L05_00329ED0_00328BF8(self, v, func_L05_00329DA8_00328BF8(self, v));
        }
        break;
    case 2:
        if (func_L05_00328FF8_00328BF8((s32)self) != 0) {
            func_L05_00329A78_00328BF8((s32)self, (Obj329158_00328BF8 *)v);
            if (func_L05_00329AD0_00328BF8(self, v) != 0) {
                func_L01_004450F0_00328BF8(self, 3, -1);
                n = func_L05_00329050_00328BF8(self, v, ((S_00328BF8 *)v)->ids[((S_00328BF8 *)v)->cur]);
                func_L05_0032A0B0_00328BF8(self, v, ((S_00328BF8 *)v)->ids[((S_00328BF8 *)v)->cur], ((S_00328BF8 *)v)->next[n]);
                *(s32 *)(v + 348) = n;
            }
        } else {
            func_L05_00329ED0_00328BF8(self, v, func_L05_00329DA8_00328BF8(self, v));
        }
        break;
    case 3:
        if (func_L05_0032A4D8_00328BF8(self, v) == 0) {
            func_L01_004450F0_00328BF8(self, 2, -1);
            func_L05_00329C68_00328BF8((s32)self, v);
        } else if (*(s32 *)(v + 128) == 0) {
            *(s32 *)(v + 128) = func_L05_00328FF8_00328BF8((s32)self);
            if (*(s32 *)(v + 128) == 0) {
                func_L05_00329C58_00328BF8((s32)self, v);
            }
        }
        break;
    }
    rp = (f32 *)(self + 240);
    *(Vec4 *)(v + 432) = *(Vec4 *)(self + 16);
    *(Vec4 *)(v + 448) = *(Vec4 *)rp;
    func_L05_00329CA0_00328BF8(self, v, &dx, &dy, &dz);
    *(f32 *)(self + 24) += dx;
    *(f32 *)(self + 240) = func_0038DAB8(*(f32 *)(self + 240), dy);
    *(f32 *)(self + 244) = func_0038DAB8(*(f32 *)(self + 244), dz);
    vec_sub_ba(&delta, self + 16, &pos);
    func_003C4DA8(v + 48, &delta, &rot, rp);
    if (func_L05_00328FF8_00328BF8((s32)self) != 0 && self[32] == 3) {
        func_L05_00329BC8_00328BF8((s32)self, v);
    }
    func_L05_00329120_00328BF8(self, v);
    func_L05_003293B0_00328BF8(self, v, &pos);
    func_L05_003296F8_00328BF8(self, v);
}
/* localdecomp:end func_L05_00328BF8 */

/* localdecomp:start func_L05_00328E98 */

void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 432) = a;
    *(Vec4 *)(obj + 448) = b;
}
/* localdecomp:end func_L05_00328E98 */

/* localdecomp:start func_L05_00328EC0 */

extern void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b);

void func_L05_00328EC0(u8 *obj, u8 *target, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 16) = a;
    *(Vec4 *)(obj + 240) = b;
    func_L05_00328E98(target, a, b);
}
/* localdecomp:end func_L05_00328EC0 */

/* localdecomp:start func_L05_00328F00 */
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L05_00329618(s32, u8 *);
extern u8 D_001A4C60[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_L05_00328F00(u8 *o, u8 *s) {
    s32 t = *(s32 *)(s + 0x78);
    if (t == -1 || (D_001BBC40[t + D_001D545C * 16] & 0x80) == 0) {
        if (*(s32 *)(s + 0x74) == -1) {
            return;
        }
        if (func_00382380(D_001A4C60, *(s32 *)(s + 0x74), 0) == 0) {
            return;
        }
    }
    *(s32 *)(s + 0x70) = 1;
    *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
    *(u16 *)(o + 0x34) &= ~1;
    if (*(s32 *)(s + 0x74) != -1 && *(s32 *)(s + 0x78) != -1 && (D_001BBC40[*(s32 *)(s + 0x78) + D_001D545C * 16] & 0x80) == 0) {
        func_L01_0043B510(*(s32 *)(s + 0x78));
    }
    func_L05_00329618((s32)o, s);
}
/* localdecomp:end func_L05_00328F00 */

/* localdecomp:start func_L05_00328FF8 */
extern u8 D_001A4BE0[];

/* from rac2-decomp's func_L00_00324120, renamed, constants adapted */
s32 func_L05_00328FF8(s32 a0) {
    u8 *b = D_001A4BE0;
    if (*(s32 *)(b + 0x25cc) == 3 || *(s32 *)(b + 0x25c4) == 0x1B) {
        if (*(s32 *)(b + 0x538) != a0)
            goto Lzero;
        return 1;
    }
    if (*(short *)(b + 0x36e) != 0)
        goto Lzero;
    if (*(s32 *)(b + 0x35c) == a0) {
        return 1;
    }
Lzero:
    return 0;
}
/* localdecomp:end func_L05_00328FF8 */

/* localdecomp:start func_L05_00329050 */
extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF00(void *, void *);

s32 func_L05_00329050(u8 *a0, u8 *a1, s32 a2) {
    s32 best = -1;
    f32 bd = 9999.0f;
    s32 *tab = D_L05_0021ED80[a2];
    s32 i;
    f32 d;
    for (i = 0; i < 4; i++) {
        s32 t = *(s32 *)(a1 + 0x90 + i * 4);
        if (t != -1) {
            d = func_0038CF00((u8 *)tab + tab[0] * 16, D_L05_001DFC80 + (t << 7) + 0x30);
            if (d < bd) {
                bd = d;
                best = i;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L05_00329050 */

/* localdecomp:start func_L05_00329120 */
extern u8 D_001A30B0[];
extern u8 D_L05_001FEEB6_00329120[];
extern s32 func_L01_004AA710_00329120(void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004AAC98_00329120(s32, s32, void *, s32);

void func_L05_00329120(u8 *m, u8 *v) {
    if (*(s16 *)(m + 0xAA) == 0x1C82) {
        if (m[0x20] == 3 && *(f32 *)(v + 0x168) > 0.0f) {
            if (func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);
                u8 *e = D_001A30B0 + idx * 128;

                if (*(s16 *)(e + 0xCA) == 0) {
                    if (idx != -1) {
                        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                            func_003A4F28(idx);
                        }
                    }
                    *(s32 *)(v + 0x16C) = -1;
                }
            }
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);

                if (idx != -1) {
                    u8 *e = D_001A30B0 + idx * 128;

                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        return;
                    }
                }
                *(s32 *)(v + 0x16C) = func_003A52A0(1, 4, m);
            }
        } else {
            if (func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);
                u8 *e = D_001A30B0 + idx * 128;

                if (*(s16 *)(e + 0xCA) == 1) {
                    if (idx != -1) {
                        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                            func_003A4F28(idx);
                        }
                    }
                    *(s32 *)(v + 0x16C) = -1;
                }
            }
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);

                if (idx != -1) {
                    u8 *e = D_001A30B0 + idx * 128;

                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        return;
                    }
                }
                *(s32 *)(v + 0x16C) = func_003A52A0(0, 4, m);
            }
        }
    } else {
        if (m[0x20] == 3 && *(f32 *)(v + 0x168) > 0.0f) {
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                if (D_L05_001FEEB6_00329120[0] != 0xFF) {
                    *(s32 *)(v + 0x16C) = func_L01_004AAC98_00329120(0, 4, m, 0x1626);
                }
            }
        } else {
            s32 idx = *(s32 *)(v + 0x16C);

            if (idx != -1) {
                u8 *e = D_001A30B0 + idx * 128;

                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(v + 0x16C) = -1;
        }
    }
}
/* localdecomp:end func_L05_00329120 */

/* localdecomp:start func_L05_003293B0 */
#include "vu0.h"

extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004669B0_003293B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L01_004668A0_003293B0(void *, void *, s32, s32, s32, f32);
extern u8 D_L05_001DC8F0_003293B0[8];
__asm__(".extern D_L05_001DC8F0_003293B0, 8");
extern f32 D_L05_001DC91C_003293B0;
__asm__(".extern D_L05_001DC91C_003293B0, 4");

void func_L05_003293B0(u8 *m, u8 *v, vu0_v4 src) {
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 off;
    s32 i;
    s32 c;
    s32 n;
    f32 sz;
    u32 color;

    if (m[0x20] == 3 && *(f32 *)(v + 0x168) > 0.0f) {
        for (i = 0; i < 2; i++) {
            pos = *(vu0_v4 *)(m + 0x10);
            func_0038D000(&off, (vu0_v4 *)D_L05_001DC8F0_003293B0 + i, m + 0xC0);
            vec_add_ab(&pos, &pos, &off);
            func_0038CE20(&vel, m + 0xC0, *(f32 *)(v + 0x168) * D_L05_001DC91C_003293B0);
            c = func_00382498(0x10, 0x20);
            color = 0x7F000000 | ((c + 8) << 16) | (c << 8) | c;
            n = func_00382498(0, 2) - 1;
            func_L01_004669B0_003293B0(&pos, 0.25f, 0.8f, 1.01f, func_003824E0(0.5f, 0.75f) * 210000.0f, n, &vel, color, 0);
            vec_sub_ba(&off, &src, m + 0x10);
            func_0038CE20(&off, &off, 0.5f);
            vec_add_ab(&pos, &pos, &off);
            c = func_00382498(0x20, 0x40);
            color = 0x40000000 | (c << 16) | (c << 8) | c;
            sz = func_003824E0(1.0f, 1.5f) * 210000.0f;
            func_L01_004668A0_003293B0(&pos, &vel, color, 0x101010, (func_00382498(0xF, 0x14) * 5 + 2) / 6, sz);
        }
    }
}
/* localdecomp:end func_L05_003293B0 */

/* localdecomp:start func_L05_00329618 */
extern s32 func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern u8 D_L05_002B2100[];

void func_L05_00329618(s32 a0, u8 *a1) {
    u8 *e = D_L05_002B2100;
    s32 *slot = (s32 *)(a1 + 0x130);
    s32 i;
    for (i = 0; i < 8; i++) {
        if (*slot == 0) {
            if (*(s32 *)(a1 + 0x84) != 0 || *(s32 *)(e + 0x30) != 0) {
                *slot = func_L01_00470150(e + 0x10, a0, *(s32 *)(e + 0x28), -1, *(s32 *)e, -1,
                                          *(f32 *)(e + 0x24) * 210000.0f, *(f32 *)(e + 0x20), *(s32 *)(e + 0x2C), -1, 1.0f, 0, 0);
            }
        }
        slot++;
        e += 0x40;
    }
}
/* localdecomp:end func_L05_00329618 */

/* localdecomp:start func_L05_003296F8 */
extern s32 *D_L05_0021ED80[];
extern u8 D_L05_002B2100[];
__asm__(".extern D_L05_001DC8D8, 4");
extern s32 D_L05_001DC8D8;
__asm__(".extern D_L05_001DC8DC, 4");
extern s32 D_L05_001DC8DC;
__asm__(".extern D_L05_001DC8E0, 4");
extern s32 D_L05_001DC8E0;
__asm__(".extern D_L05_001DC8E4, 4");
extern f32 D_L05_001DC8E4;

void func_L05_003296F8(u8 *o, u8 *s) {
    s32 old = *(s32 *)(s + 0x88);
    s32 t;
    s32 st;
    s32 i;
    s32 v;
    f32 g;
    u8 *e;
    u8 **slot;
    u8 *x;

    if (*(s32 *)(s + 0x84) != 0) {
        *(s32 *)(s + 0x88) = 2;
    } else {
        *(s32 *)(s + 0x88) = 1;
    }
    t = o[0x20];
    if (t == 2) {
        *(s32 *)(s + 0x88) = 3;
    } else if (t == 3) {
        if (!((s32)*(f32 *)(s + 0x164) < *D_L05_0021ED80[*(s32 *)(s + 0x160)] - 2)) {
            *(s32 *)(s + 0x88) = 3;
        }
    }
    st = *(s32 *)(s + 0x88);
    if (st == old) {
        return;
    }
    switch (st) {
    case 1:
        v = D_L05_001DC8E0;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    case 2:
        v = D_L05_001DC8D8;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    case 3:
        v = D_L05_001DC8DC;
        g = D_L05_001DC8E4;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * g * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    }
}
/* localdecomp:end func_L05_003296F8 */

/* localdecomp:start func_L05_003298C0 */
typedef struct {
    u8 p0[0x90];
    s32 t90[4];
    s32 tA0[4];
    u8 pB0[0xD0 - 0xB0];
    s32 tD0[4];
    s32 tE0[4];
    s32 tF0[4];
    s32 t100[4];
    s32 t110[4];
    s32 t120[4];
} S_003298C0;

void func_L05_003298C0(u8 *o, S_003298C0 *s) {
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 4; i++) {
        if (s->tE0[i] != -1) {
            t = s->t110[i];
            if (t == -1 || (D_001BBC40[t + D_001D545C * 16] & 0x80) == 0) {
                if (s->t100[i] == -1) {
                    continue;
                }
                if (func_00382380(D_001A4C60, s->t100[i], 0) == 0) {
                    continue;
                }
            }
            for (j = 0; j < 4 && s->tE0[i] != s->t90[j]; j++) {
            }
            s->tA0[j] = s->tF0[i];
            s->tD0[j] = s->t120[i];
            s->tE0[i] = -1;
            if (s->t100[i] != -1 && (D_001BBC40[s->t110[i] + D_001D545C * 16] & 0x80) == 0) {
                func_L01_0043B510(s->t110[i]);
            }
        }
    }
}
/* localdecomp:end func_L05_003298C0 */

/* localdecomp:start func_L05_00329A78 */

extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
__asm__(".extern D_L05_001DC8A0, 8");
extern s32 D_L05_001DC8A0[2];

void func_L05_00329A78(s32 a0, Obj329158 *obj) {
    func_L01_00452560(0, 9, D_L05_001DC8A0[obj->table[obj->index]], 1, 0, 0, 0);
}
/* localdecomp:end func_L05_00329A78 */

/* localdecomp:start func_L05_00329AD0 */
extern s32 D_L05_002D3FB0[];
extern u8 *D_001D52FC;

s32 func_L05_00329AD0(void) {
    s32 r = 0;
    if (D_L05_002D3FB0[0] == 9) {
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_00329AD0 */

/* localdecomp:start func_L05_00329B00 */
extern void func_0038D000(void *, void *, void *);
extern s32 *D_L05_0021ED80[];
extern vu0_v4 D_L05_002B2090[];

void func_L05_00329B00(s32 a0, char *a1) {
    u8 *m = (u8 *)a0;
    vu0_v4 *dst = (vu0_v4 *)(D_L05_0021ED80[*(s32 *)(a1 + 0x7C)] + 4);
    vu0_v4 *src = D_L05_002B2090;
    s32 i;
    for (i = 0; i < 7; i++) {
        func_0038D000(dst, src, m + 0xC0);
        vec_add_ab(dst, dst, m + 0x10);
        dst++;
        src++;
    }
}
/* localdecomp:end func_L05_00329B00 */

/* localdecomp:start func_L05_00329B98 */
extern u16 D_001A7466[];
extern void func_L05_00329B00(s32, char *);
void func_L05_00329B98(s32 a0, char *a1) {
    func_L05_00329B00(a0, a1);
    D_001A7466[0] = *(u16 *)(a1 + 124);
}
/* localdecomp:end func_L05_00329B98 */

/* localdecomp:start func_L05_00329BC8 */
extern u8 D_001A4BE0[];
extern s32 *D_L05_0021ED80[];
extern void func_L05_00329B98(s32, char *);
extern void func_L05_00329C88(s32, u8 *);

void func_L05_00329BC8(s32 a0, u8 *a1) {
    u8 *h = D_001A4BE0;
    *(s16 *)(h + 0x212) = 5;
    *(s16 *)(h + 0x214) = 10;
    func_L05_00329B98(a0, (char *)a1);
    if ((s32)*(f32 *)(a1 + 0x164) >= *D_L05_0021ED80[*(s32 *)(a1 + 0x160)] - 2) {
        func_L05_00329C88(a0, a1);
    }
}
/* localdecomp:end func_L05_00329BC8 */

/* localdecomp:start func_L05_00329C58 */
void func_L05_00329C58(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x80) = 1;
}
/* localdecomp:end func_L05_00329C58 */

/* localdecomp:start func_L05_00329C68 */
extern void func_L05_00329C88(s32, u8 *);
void func_L05_00329C68(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 128) = 0;
    func_L05_00329C88(a0, a1);
}
/* localdecomp:end func_L05_00329C68 */

/* localdecomp:start func_L05_00329C88 */
/* from rac4-decomp's func_01EFDCD4 */
void func_L05_00329C88(s32 a0, u8 *a1) {
    if (*(s32 *)(a1 + 0x8C) != 0) {
        *(s32 *)(a1 + 0x8C) = 0;
    }
}
/* localdecomp:end func_L05_00329C88 */

/* localdecomp:start func_L05_00329CA0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

void func_L05_00329CA0(void *a0, u8 *a1, f32 *a2, f32 *a3, f32 *a4) {
    f32 r = func_0038DAB8(*(f32 *)(a1 + 0x150), 0.0418879054f);
    *(f32 *)(a1 + 0x150) = r;
    *a2 = func_0038D0B0(r) * 0.2f;
    *a3 = func_0038D0B0(*(f32 *)(a1 + 0x154)) * 0.0785398185f * func_0038D0B0(*(f32 *)(a1 + 0x158));
    *a4 = func_0038D0B0(*(f32 *)(a1 + 0x154)) * 0.0785398185f * func_0038D098(*(f32 *)(a1 + 0x158));
    *(f32 *)(a1 + 0x154) = func_0038DAB8(*(f32 *)(a1 + 0x154), 0.0244346112f);
    *(f32 *)(a1 + 0x158) = func_0038DAB8(*(f32 *)(a1 + 0x158), 0.0349065885f);
}
/* localdecomp:end func_L05_00329CA0 */

/* localdecomp:start func_L05_00329DA8 */
typedef struct { s32 e[4]; } S_329DA8;
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFC80;

s32 func_L05_00329DA8(u8 *a0, u8 *a1) {
    s32 *p = (s32 *)(a1 + 0xC0);
    s32 *q = p;
    s32 i;
    s32 best;
    f32 bd;
    for (i = 0; i < 4; i++) {
        if (*q != -1) {
            if (func_00382380(D_001A4C60, *q, 0) != 0) {
                return i;
            }
        }
        q++;
    }
    bd = 9999.0f;
    best = -1;
    for (i = 0; i < 4; i++) {
        s32 t = *(s32 *)(a1 + 0x90 + i * 4);
        if (t != -1) {
            f32 d = func_0038CF00(D_001A4C60, D_L05_001DFC80 + (t << 7) + 0x30);
            if (d < bd) {
                bd = d;
                best = i;
            }
        }
    }
    if (((S_329DA8 *)p)->e[best] != -1) {
        return *(s32 *)(a1 + 0x15C);
    }
    return best;
}
/* localdecomp:end func_L05_00329DA8 */

/* localdecomp:start func_L05_00329ED0 */

typedef struct {
    u8 pad0[0x90];
    s32 n[8];
    s32 w[8];
    u8 padD0[0x15C - 0xD0];
    s32 cur;
} S_329ED0_00329ED0;

extern s32 *D_L05_0021ED80_00329ED0[];
extern u8 *D_L05_001DFC80_00329ED0;
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0_00329ED0(void *, s32, s32);
extern s32 func_L03_003F6A80_00329ED0(void *, void *, void *, s32, s32);
extern void func_L05_00328E98_00329ED0(u8 *obj, Vec4 a, Vec4 b);
extern void func_L05_0032A0B0_00329ED0(u8 *a0, u8 *a1, s32 a2, s32 a3);

void func_L05_00329ED0(u8 *a0, S_329ED0_00329ED0 *a1, s32 a2) {
    u8 *e = D_L05_001DFC80_00329ED0 + (a1->n[a2] << 7);
    Vec4 a;
    Vec4 b;
    s32 *tab;
    f32 lim;

    if (a2 == a1->cur) {
        if (a1->w[a2] != -1) {
            tab = D_L05_0021ED80_00329ED0[a1->w[a2]];
            lim = func_0038CF00(e + 0x30, tab + 4) + 5.0f;
        } else {
            lim = 10.0f;
        }
        if (func_0038CF00(e + 0x30, a0 + 0x10) <= lim) {
            return;
        }
    }
    if (a1->w[a2] != -1) {
        tab = D_L05_0021ED80_00329ED0[a1->w[a2]];
        a = *(Vec4 *)(tab + 4);
        qzero(&b);
        b.v[2] = func_0038D160(((f32 *)tab)[8] - ((f32 *)tab)[4], ((f32 *)tab)[9] - ((f32 *)tab)[5]);
        func_L01_004450F0_00329ED0(a0, 3, -1);
    } else {
        a = *(Vec4 *)(e + 0x30);
        b = *(Vec4 *)(e + 0x70);
        func_L01_004450F0_00329ED0(a0, 2, -1);
    }
    a1->cur = a2;
    func_L03_003F6A80_00329ED0(a0, &a, &b, 0, 0);
    func_L05_00328E98_00329ED0((u8 *)a1, a, b);
    if (a1->w[a2] != -1) {
        func_L05_0032A0B0_00329ED0(a0, (u8 *)a1, a1->w[a2], a1->n[a2]);
    }
}
/* localdecomp:end func_L05_00329ED0 */

/* localdecomp:start func_L05_0032A0B0 */
extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L05_001DC8BC, 4");
extern f32 D_L05_001DC8BC;

void func_L05_0032A0B0(u8 *a0, u8 *a1, s32 a2, s32 a3) {
    s32 *tab;
    f32 d;
    s32 off;

    *(s32 *)(a1 + 0x168) = 0;
    qzero(a1 + 0x170);
    *(s32 *)(a1 + 0x160) = a2;
    tab = D_L05_0021ED80[a2];
    if (func_0038CF00(a0 + 0x10, tab + 4) < 0.01f) {
        *(s32 *)(a1 + 0x164) = 0;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(tab + 4);
        *(f32 *)(a1 + 0x18C) = -1.0f;
    } else {
        *(f32 *)(a1 + 0x164) = -1.0f;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(a0 + 0x10);
        *(f32 *)(a1 + 0x18C) = func_0038CF00(a0 + 0x10, tab + 4);
    }
    off = a3 << 7;
    *(vu0_q *)(a1 + 0x190) = *(vu0_q *)((u8 *)(off + (s32)D_L05_001DFC80) + 0x30);
    d = func_0038CF00(D_L05_001DFC80 + off + 0x30, (u8 *)tab + tab[0] * 16);
    {
        f32 c = D_L05_001DC8BC;
        u8 *p = D_L05_001DFC80 + off;
        *(f32 *)((u8 *)tab + ((tab[0] - 1) << 4) + 0x1C) = d;
        func_0038CF68(a1 + 0x1A0, p, c);
    }
    vec_add_ab(a1 + 0x1A0, a1 + 0x1A0, (u8 *)(off + (s32)D_L05_001DFC80) + 0x30);
    d = func_0038CF00(a1 + 0x1A0, D_L05_001DFC80 + off + 0x30);
    {
        f32 t = D_L05_001DC8BC;
        *(f32 *)(a1 + 0x19C) = d;
        *(f32 *)(a1 + 0x1AC) = t;
    }
}
/* localdecomp:end func_L05_0032A0B0 */

/* localdecomp:start func_L05_0032A238 */
f32 func_L05_0032A238(u8 *a0, s32 *tab, s32 *out, f32 t, f32 spd) {
    f32 rem = 1.0f;
    f32 step;
    f32 d;
    f32 frac;
    s32 i;

    while (rem > 0.0f) {
        if (t < 0.0f) {
            *out = -1;
            step = spd / *(f32 *)(a0 + 0x18C) * rem;
            if (t + step >= 0.0f) {
                frac = (0.0f - t) / step;
                *out = 0;
                t = 0.0f;
                rem -= frac * rem;
            } else {
                t += step;
                rem = 0.0f;
            }
        } else {
            i = t;
            *out = i;
            step = spd / *(f32 *)((u8 *)tab + (i << 4) + 0x1C) * rem;
            d = t + step - (f32)i;
            if (d >= 1.0f && i < tab[0] - 1) {
                frac = (step - (d - 1.0f)) / step;
                t += step * frac;
                rem -= frac * rem;
                *out = t;
            } else {
                t += step;
                rem = 0.0f;
            }
        }
    }
    return t;
}
/* localdecomp:end func_L05_0032A238 */

INCLUDE_ASM("asm/levels", func_L05_0032A360);
