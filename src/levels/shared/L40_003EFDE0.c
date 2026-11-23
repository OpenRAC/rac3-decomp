#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003EFDE0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    Vec4 pts[1];
} S_003EFDE0;
typedef struct {
    void *x;
    u8 pad4[0x14];
    s32 f18;
} S90_003EFDE0;
typedef struct {
    u8 pad0[0x24];
    f32 scale;
} SC_003EFDE0;
typedef struct {
    u8 pad0[0x24];
    SC_003EFDE0 *cls;
    u8 pad28[4];
    f32 scale;
    u8 pad30[0x60];
    S90_003EFDE0 *p90;
} SM_003EFDE0;

extern f32 D_L40_00246E18;
extern f32 D_L40_00246E0C;
extern s32 D_L40_00246D8C;
extern s32 D_L40_00246E24;
extern s32 D_L40_00246E28;
extern s32 D_L40_00246E2C;
extern s32 D_L40_00246E30;
extern s32 D_L40_00246E34;
extern s32 D_L40_00246E38;
extern f32 D_L40_00246E3C;
extern f32 D_L40_00246E40;
extern f32 D_L40_00246D9C;
extern f32 D_L40_00246E20;
extern Moby *D_L40_0024846C;
__asm__(".extern D_L40_00246E18, 4");
__asm__(".extern D_L40_00246E0C, 4");
__asm__(".extern D_L40_00246D8C, 4");
__asm__(".extern D_L40_00246E24, 4");
__asm__(".extern D_L40_00246E28, 4");
__asm__(".extern D_L40_00246E2C, 4");
__asm__(".extern D_L40_00246E30, 4");
__asm__(".extern D_L40_00246E34, 4");
__asm__(".extern D_L40_00246E38, 4");
__asm__(".extern D_L40_00246E3C, 4");
__asm__(".extern D_L40_00246E40, 4");
__asm__(".extern D_L40_00246D9C, 4");
__asm__(".extern D_L40_00246E20, 4");
__asm__(".extern D_L40_0024846C, 4");
extern Vec4 D_L40_00242960 __attribute__((section(".sdata")));
extern S_003EFDE0 *D_L40_0028FD80[];
extern Vec4 D_L40_0025B9A0;
extern s32 D_001A5DF8 __attribute__((section(".data")));

extern void func_L40_003F1568(Moby *);
extern void func_L39_0066C470(void *);
extern void func_L40_0053F6E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L40_003F1858(Moby *);
extern s32 func_L40_003F12A0(Moby *, s32);
extern void func_L40_003EDA10(u8 *, u8 *);
extern void func_L40_003ED980(u8 *m, s32 a1);
extern s32 func_L01_004561B8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00565750(Moby *, Vec4 *, Vec4 *, s32, s32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L40_003EEC40(u8 *, u8 *, f32);
extern void func_L40_003F1958(Moby *);
extern s32 func_L01_0045A9F0(void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A898(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L40_0053F018(void *);
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003EFC00(u8 *);
extern void func_L40_003F0E18(Moby *, void *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L40_003EFD50(u8 *a0);
extern void func_L40_003F1660(u8 *, s32, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L40_003F1688(void *);

void func_L40_003EFDE0(Moby *self) {
    u8 *v;
    u8 *m;
    void *x;
    S90_003EFDE0 *p90;
    u8 st;
    s32 k;
    s32 old;
    f32 ang;
    f32 z;
    f32 step;
    Vec4 save;
    Vec4 *pos;
    Vec4 a;
    Vec4 b;
    Vec4 c;
    Vec4 d;

    if (self == 0) {
        return;
    }
    v = self->pVar;
    p90 = ((SM_003EFDE0 *)self)->p90;
    x = p90->x;
    p90->f18 = *(s32 *)(v + 0x2C0);
    ((SM_003EFDE0 *)self)->scale = ((SM_003EFDE0 *)self)->cls->scale * D_L40_00246E18;

    if (v[0x3E] == 2) {
        func_L40_003F1568(self);
        func_L39_0066C470(x);
        func_L40_0053F6E0(self);
        func_L01_004450F0(self, 0x25, -1);
        *(s32 *)((u8 *)self + 0x98) = 0;
        *(u16 *)((u8 *)self + 0x34) = (*(u16 *)((u8 *)self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(self, 1);
        return;
    }
    if (*(s32 *)(v + 0x264) == 0x539) {
        func_L40_003F1858(self);
        if (*(s32 *)(v + 0x2FC) == 1) {
            func_L40_003F1568(self);
            func_L40_0053F6E0(self);
            func_L01_004450F0(self, 0x25, -1);
            *(s32 *)((u8 *)self + 0x98) = 0;
            *(u16 *)((u8 *)self + 0x34) = (*(u16 *)((u8 *)self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            return;
        }
    }
    if (func_L40_003F12A0(self, (s32)x) != 0) {
        return;
    }
    if (self->field_20 == 0xFD || self->field_20 == 0xFE || self->field_20 == 0x25) {
        return;
    }
    func_L40_003EDA10((u8 *)self, v);
    {
        f32 px = self->pos.x;
        if (!(px < 0.0f || self->pos.y < 0.0f)) {
            self->pos.x = px;
        } else {
            st = 0;
        }
    }
    func_L40_003ED980((u8 *)self, *(s32 *)(v + 0x2C0));
    st = self->field_20;
    save = self->pos;
    k = 0x50;
    *(u16 *)((u8 *)self + 0x32) = k;
    *((u8 *)self + 0x30) = k;

    switch (st) {
    case 12:
        if (func_L01_004561B8(self) != 0) {
            func_L40_003F1660((u8 *)self, 6, 0, 8);
        }
        if (*(s16 *)(v + 0x234) == 1) {
            func_L01_00448728((u8 *)self + 0xF8, func_0038D160(*(f32 *)(v + 0x220) - self->pos.x, *(f32 *)(v + 0x224) - self->pos.y), v + 0x274, 0.010053097f, 0.00083775813f, 0.50265485f, 0);
            if (func_L01_0044E1B8(self, D_L40_00246E0C) != 0) {
                if (*(s32 *)(v + 0x264) != 0x539) {
                    s32 s;
                    s32 k0;
                    s32 k1;
                    func_003C2F58(self, D_L40_00246D8C, &a);
                    c = *(Vec4 *)(v + 0x220);
                    if (*(s32 *)(v + 0x230) != 0) {
                        m = func_00382348(*(s32 *)(v + 0x230));
                        if (m != 0) {
                            func_0038CF68(&d, &D_L40_00242960, *(f32 *)(m + 0x10));
                            vec_add_ab(&c, &c, &d);
                        }
                    }
                    vec_sub_ab(&b, &c, &a);
                    func_0038CF68(&b, &b, 1.2f);
                    s = *(s32 *)(v + 0x2C0);
                    k0 = D_L40_00246E24;
                    k1 = D_L40_00246E30;
                    if (s == 0) {
                        k0 = D_L40_00246E28;
                        k1 = D_L40_00246E34;
                    } else if (s == 1) {
                        k0 = D_L40_00246E2C;
                        k1 = D_L40_00246E38;
                    }
                    func_L39_00565750(self, &a, &b, k0, k1, 2.0f, D_L40_00246E3C, D_L40_00246E40);
                }
                func_L01_004450F0(self, 0xD, -1);
            }
            if (v[0x33D] == 1 && *(s32 *)(v + 0x2B8) != -1) {
                S_003EFDE0 *path = D_L40_0028FD80[*(s32 *)(v + 0x2B8)];
                if (!(0.2f < func_0038CF38(&self->pos, &path->pts[*(s32 *)(v + 0x280)]))) {
                    if (*((u8 *)self + 0x43) != 6) {
                        func_003C3A10((u8 *)self, 6, 0, 8);
                    }
                }
            }
        } else {
            func_L40_003F1660((u8 *)self, 0, 0, 8);
        }
        if (*(u16 *)((u8 *)self + 0x96) >= 0x33) {
            func_L01_004450F0(self, 0xD, -1);
        }
        if (*(s32 *)(v + 0x354) == 1) {
            s32 old = *(s32 *)(v + 0xA8);
            *(s32 *)(v + 0xA8) = old | 0x10;
            func_L40_003EEC40((u8 *)self, v + 0x2E0, *(f32 *)(v + 0x350));
            *(s32 *)(v + 0xA8) = old;
            func_L40_003F1958(self);
        }
        func_L01_0045A9F0(self);
        break;
    case 13:
        if (func_L01_004561B8(self) != 0) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_003C3A10((u8 *)self, 7, 0, 0x11);
            } else {
                func_003C3A10((u8 *)self, 0, 0, 8);
            }
        } else if (*((u8 *)self + 0x60) & 2) {
            if (*((u8 *)self + 0x42) == 7) {
                func_003C3A10((u8 *)self, 5, 0, 0x11);
            } else if (*((u8 *)self + 0x42) == 5) {
                func_L01_004450F0(self, 0xC, -1);
            }
        }
        if (*(u16 *)((u8 *)self + 0x96) >= 0x3F) {
            func_L01_004450F0(self, 0xC, -1);
        }
        if (v[0x33D] == 1 && *(s32 *)(v + 0x2B8) != -1) {
            S_003EFDE0 *path = D_L40_0028FD80[*(s32 *)(v + 0x2B8)];
            if (!(0.2f < func_0038CF38(&self->pos, &path->pts[*(s32 *)(v + 0x280)]))) {
                if (*((u8 *)self + 0x43) != 6) {
                    func_003C3A10((u8 *)self, 6, 0, 8);
                }
            }
        }
        if (*(s32 *)(v + 0x354) == 1) {
            s32 old = *(s32 *)(v + 0xA8);
            *(s32 *)(v + 0xA8) = old | 0x10;
            func_L40_003EEC40((u8 *)self, v + 0x2E0, *(f32 *)(v + 0x350));
            *(s32 *)(v + 0xA8) = old;
            func_L40_003F1958(self);
        }
        break;
    case 23:
        if (func_L01_004561B8(self) != 0) {
            func_003C3A10((u8 *)self, 0, 0, 0x11);
        }
        *(s32 *)(v + 0xA8) |= 5;
        if (*(s32 *)(v + 0x264) == 0x539) {
            if (*(s32 *)(v + 0x354) != 0) {
                Vec4 *pos = &self->pos;
                u8 *dst = v + 0x2E0;
                if (func_0038CF38(pos, dst) > D_L40_00246D9C) {
                    s32 old = *(s32 *)(v + 0xA8);
                    *(s32 *)(v + 0xA8) = old | 0x10;
                    func_L40_003EEC40((u8 *)self, dst, *(f32 *)(v + 0x350));
                    *(s32 *)(v + 0xA8) = old;
                    if (func_0038CF38(pos, dst) > *(f32 *)(v + 0xA4) * 2.0f) {
                        func_L01_00448728((u8 *)self + 0xF8, *(f32 *)(v + 0x350), v + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
                    }
                }
            }
        } else {
            a = self->pos;
            pos = &self->pos;
            if (*(s32 *)(v + 0x354) != 0) {
                u8 *dst = v + 0x2E0;
                s32 old = *(s32 *)(v + 0xA8);
                *(s32 *)(v + 0xA8) = old | 0x10;
                func_L40_003EEC40((u8 *)self, dst, *(f32 *)(v + 0x350));
                *(s32 *)(v + 0xA8) = old;
                if (func_0038CF38(pos, dst) > *(f32 *)(v + 0xA4) * 2.0f) {
                    func_L01_00448728((u8 *)self + 0xF8, *(f32 *)(v + 0x350), v + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
                }
            }
        }
        func_L40_003F1958(self);
        break;
    case 25: {
        Vec4 *pp;
        a = self->pos;
        pp = &self->pos;
        if (func_L01_004561B8(self) != 0) {
            func_003C3A10((u8 *)self, 0, 0, 0x11);
            *(s32 *)(v + 0x2CC) = 0;
        }
        if (*(s32 *)(v + 0x264) == 0x539) {
            if (*(s32 *)(v + 0x354) != 0) {
                u8 *dst = v + 0x2E0;
                if (func_0038CF38(pp, dst) > D_L40_00246D9C) {
                    func_L40_003EEC40((u8 *)self, dst, *(f32 *)(v + 0x350));
                    goto moved;
                }
            }
        } else if (*(s32 *)(v + 0x354) != 0) {
            func_L40_003EEC40((u8 *)self, v + 0x2E0, *(f32 *)(v + 0x350));
            goto moved;
        }
        qzero(v + 0x110);
moved:
        func_L40_003F1958(self);
    }
    case 1:
        if (func_L01_004561B8(self) != 0 || (*((u8 *)self + 0x42) >= 2 && *((u8 *)self + 0x43) >= 2)) {
            func_L40_003F1660((u8 *)self, 0, 0, 0x11);
        }
        break;
    case 3:
        if (*(s32 *)((u8 *)self + 0x28) != 0 || self == D_L40_0024846C) {
            func_L01_0045BD78(self, 0.002f, 0.080000006f, 0.50265485f, 0.50265485f);
            vec_sub_ba(&c, v + 0x390, &self->pos);
            b = c;
            a = c;
            ang = func_0038D160(*(f32 *)(v + 0x390) - self->pos.x, *(f32 *)(v + 0x394) - self->pos.y);
            old = *(s32 *)(v + 0xA8);
            *(s32 *)(v + 0xA8) = old | 0x14;
            func_L01_0045A898(self, v + 0x390, ang);
            if (self->pos.z < *(f32 *)(v + 0x100) + 0.5f) {
                self->pos.z = *(f32 *)(v + 0x100) + 0.5f;
            }
            func_L01_00448728((u8 *)self + 0xF8, ang, v + 0x274, 0.010053097f, 0.010053097f, 0.20943952f, 0);
            if (self->pos.z < *(f32 *)(v + 0x398)) {
                self->pos.z += 0.20000002f;
            }
            *(s32 *)(v + 0xA8) = old;
        }
        break;
    case 22:
        if (func_L01_004561B8(self) != 0 && *((u8 *)self + 0x43) != 8) {
            func_003C3A10((u8 *)self, 8, 0, 8);
        }
        if (*(s32 *)(v + 0x354) != 0) {
            Vec4 *pos = &self->pos;
            u8 *dst = v + 0x2E0;
            if (func_0038CF38(pos, dst) > D_L40_00246D9C) {
                s32 old = *(s32 *)(v + 0xA8);
                *(s32 *)(v + 0xA8) = old | 0x10;
                func_L40_003EEC40((u8 *)self, dst, *(f32 *)(v + 0x350));
                *(s32 *)(v + 0xA8) = old;
                if (func_0038CF38(pos, dst) > *(f32 *)(v + 0xA4) * 2.0f) {
                    func_L01_00448728((u8 *)self + 0xF8, *(f32 *)(v + 0x350), v + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
                }
            }
        }
        if (*((u8 *)self + 0x60) & 2) {
            if (*(s32 *)(v + 0x308) == -1 || *(s32 *)(v + 0x308) == 0) {
                if (*(s32 *)(v + 0x29C) != 0) {
                    func_L01_004450F0(self, 0x17, -1);
                } else {
                    func_L01_004450F0(self, 1, -1);
                }
            } else {
                func_L01_004450F0(self, 0xC, -1);
            }
        }
        break;
    case 28:
        if (func_L01_004561B8(self) != 0) {
            f32 h;
            if (*((u8 *)self + 0x43) != 9) {
                func_003C3A10((u8 *)self, 9, 0, 8);
            }
            b = self->pos;
            a = self->pos;
            b.z += 1.0f;
            a.z -= 4.0f;
            if (func_003D3CB0(&b, &a, 0, self, 0) != 0) {
                h = D_L40_0025B9A0.z;
            } else if (*(s32 *)(v + 0x2C0) == -1) {
                h = self->pos.z;
            } else {
                h = a.z;
            }
            *(f32 *)(v + 0x260) = h;
            if (func_L40_0053F018(self) != 0) {
                s32 *n = func_L39_0066C2B8();
                if (n == 0) {
                    return;
                }
                *n = func_L39_0066C280(2, x, D_001A5DF8, x, n);
            }
        }
        z = self->pos.z;
        if (*(f32 *)(v + 0x260) < z) {
            step = D_L40_00246E20 * 0.020000001f;
            if (step < z - *(f32 *)(v + 0x260)) {
                self->pos.z = z - step;
            }
        }
        if (*((u8 *)self + 0x60) & 2) {
            u8 *e;
            func_L40_003F1568(self);
            func_L40_0053F6E0(self);
            e = (u8 *)func_L01_003303B8(&self->pos, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f,
                                       0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                                       0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (e != 0) {
                *(Moby **)(e + 0xB8) = self;
            }
            func_L01_004450F0(self, 0x25, -1);
            *(s32 *)((u8 *)self + 0x98) = 0;
            *(u16 *)((u8 *)self + 0x34) = (*(u16 *)((u8 *)self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            return;
        }
        break;
    case 24:
        func_L40_003EFC00((u8 *)self);
        break;
    }

    if (v[0x33D] == 1 && *(s32 *)(v + 0x2B8) == -1) {
        func_L40_003F0E18(self, x);
    }
    func_L40_003F1688(self);
    if (self->pos.x < 10.0f || self->pos.y < 10.0f || self->pos.z < 10.0f) {
        if (self->field_20 != 0x1C) {
            func_L39_0066C470(x);
        }
    }
    if (*(s32 *)(v + 0x264) == 0x539) {
        *(s32 *)((u8 *)self + 0x98) = 0;
        *(u16 *)((u8 *)self + 0x34) = (*(u16 *)((u8 *)self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(self, 1);
        return;
    }
    func_L40_003EFD50((u8 *)self);
}
/* localdecomp:end func_L40_003EFDE0 */
