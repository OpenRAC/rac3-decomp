/* functional: medium. Multiplayer-menu per-frame input/state handler; reconstructed from the retail assembly, control flow follows the branch structure (switch-like on event a1 = 7/8/5 and selected item). Differs from retail in register allocation, stack layout and scheduling only; callee names are catalogue names, struct layouts are local views. */
typedef struct VT_1730 {
    char pad0[0x30];
    void (*f30)(void *, s32 *, f32 *);
} VT_1730;

typedef struct O_1730 {
    char pad0[4];
    s32 f4;
    char pad8[0x58];
    VT_1730 *vt;
} O_1730;

typedef struct Q_1730 {
    char pad0[0x1C];
    s32 f1C;
} Q_1730;

typedef struct E_1730 {
    s32 f0;
    s32 count;
    Q_1730 **list;
} E_1730;

typedef struct T_1730 {
    u8 b0;
    char pad1[3];
    s32 f4;
    char pad8[0x20];
    E_1730 entries[1];
} T_1730;

typedef struct D_1730 {
    char pad0[0x40];
    T_1730 *f40;
} D_1730;

typedef struct M_1730 {
    char pad0[0x110];
    O_1730 *f110[0x60];
    s32 f290;
    char pad294[0x14];
    u8 b2A8;
    char pad2A9[0xF];
    s32 f2B8;
    s32 f2BC;
    char pad2C0[0xC];
    s32 f2CC;
    char pad2D0[4];
    s32 f2D4;
    u8 f2D8[8];
    s32 f2E0;
    u8 b2E4;
    u8 b2E5;
    char pad2E6[2];
    s32 f2E8;
    s32 f2EC;
    s32 f2F0;
    char pad2F4[0xC];
    u8 b300;
    u8 b301;
    u8 b302;
    u8 b303;
} M_1730;

typedef struct P_1730 {
    char pad0[0xE0];
    s16 eE0[8];
    s16 eF0[8];
    char pad100[0x50];
    s32 f150[8];
    char pad170[4];
    s32 f174;
} P_1730;

typedef struct G_1730 {
    char pad0[8];
    s32 w8;
    char padC[0x11C];
    s32 f128;
    char pad12C[4];
    s32 f130;
    char pad134[4];
    s32 f138;
    s32 f13C;
    char pad140[0x28];
    u8 b168;
    u8 b169;
    char pad16A[0x182];
    s32 f2EC;
    char pad2F0[0x304];
    s32 f5F4;
} G_1730;

typedef struct S_1730 {
    char pad0[0x274];
    s32 f274;
} S_1730;

__asm__(".extern D_L39_00241640, 16");
extern P_1730 *D_L39_00241640;
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_00247914;
extern D_1730 *D_L39_0024D760;
extern G_1730 D_001A5CD0 __attribute__((section(".data")));
extern u8 D_L39_00249550[];

extern void func_L39_006C20B0(void *);
extern void func_L39_006C3778(void *, s32, s32, s32);
extern void func_L39_006C3AA8(void *);
extern void func_L39_006C2C40(void *);
extern void func_L39_006C3670(void *);
extern s32 func_L39_006C40A8(void *);
extern s32 func_L39_006C30A0(void *);
extern void func_L39_006C4448(void *);
extern void func_0019CB10(s32, s32);
extern void func_L39_00688340(s32, s32, s32);
extern s32 func_L39_006C45C8(void *, s32, s32 *);
extern s32 func_L39_006C46F0(void *, s32);
extern s32 func_0059A970(s32);
extern s32 func_L39_006878A0(void *, s32, s32, s32);
extern void func_L39_006C4360(void *, s32);
extern s32 func_L39_006872E8(void *, s32, void *, s32, f32, s32);
extern s32 func_00120048(u8 *, s32, ...);
extern void func_L39_005B70A0(s32 *, s32, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_006C38E0(void *, s32, s32);
extern void func_L39_006C4308(void *, s32, s32);
extern s32 func_L39_006C4788(void *, s32);
extern void func_L39_006873F0(void *, void *, s32, s32);
extern s32 func_L39_006CC238(s32, s32);
extern void func_L39_006CC2A8(s32, s32 *, s32);
extern void func_0019B5E8(s32);
extern void func_00199A20(void);
extern void func_L39_00687640(void *, s32, s32, s32, u8, s32, s32, u8 *, u8, u8, u8, u8, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_006C1730(M_1730 *self, s32 a1)
{
    P_1730 *p;
    T_1730 *t;
    E_1730 *e;
    O_1730 *obj;
    u8 *mgr;
    s32 sel;
    s32 i19;
    s32 i20;
    s32 r17;
    s32 l130;
    s32 l134;
    f32 l138;
    u8 buf[0x100];
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 k;
    s32 first;
    s32 last;
    s32 flags;
    s32 do_send;

    {
        S_1730 *m = (S_1730 *)D_L39_00247914;
        O_1730 *cur;
        if (m->f274 >= 0) {
            cur = ((O_1730 **)((u8 *)m + 0x110))[m->f274];
        } else {
            cur = 0;
        }
        if (cur != 0) {
            func_L39_006C20B0(self);
            return 1;
        }
    }

    if (D_001A5CD0.b169 != 0 || D_001A5CD0.f2EC != 0) {
        func_L39_006C3778(self, 1, 0, -1);
        D_001A5CD0.b169 = 0;
        return 1;
    }

    if (a1 == 0) {
        self->f2BC = self->f2BC + 1;
    } else {
        self->f2BC = 0;
    }
    func_L39_006C3AA8(self);
    func_L39_006C2C40(self);
    func_L39_006C20B0(self);
    func_L39_006C3670(self);
    if (func_L39_006C40A8(self) != 0) {
        return 1;
    }

    p = D_L39_00241640;
    if (p != 0) {
        s32 skip = 0;
        if (p->eF0[0] < 7) {
            if (func_L39_006C30A0(self) != 0) {
                return 1;
            }
            p = D_L39_00241640;
            if (p->eF0[0] < 7) {
                skip = 1;
            }
        }
        if (!skip) {
            a = p->f174;
            b = D_001A5CD0.f128;
            if (b + 0x1388 < a || (p->eF0[0] >= 7 && a <= b)) {
                func_L39_006C4448(self);
                return 1;
            }
        }
        for (i = 0; i < 8; i++) {
            if (p->eE0[i] == D_001A5CD0.w8 && p->eF0[i] == 5) {
                func_L39_006C3778(self, 1, 0, 0x1600);
                return 1;
            }
        }
    }

    t = D_L39_0024D760->f40;
    e = 0;
    if (t->b0 != 0) {
        if (t->f4 >= 0) {
            e = &t->entries[t->f4];
        }
    }

    if (e != 0) {
        if (p != 0) {
            for (i = 0; i < 8; i++) {
                s32 id = D_L39_00241640->eE0[i];
                if (id >= 0) {
                    func_0019CB10(id, 0);
                    for (j = 0; j < e->count; j++) {
                        if (D_L39_00241640->f150[i] == e->list[j]->f1C) {
                            func_0019CB10(id, 1);
                            break;
                        }
                    }
                }
                p = D_L39_00241640;
            }
        }
    }

    if (p != 0 && p->eF0[0] >= 7) {
        return 1;
    }

    do_send = 0;
    if (a1 == 7 && p != 0) {
        func_L39_00688340(4, 0, 0);
        sel = self->f290;
        i19 = sel - 0xF;
        if ((u32)i19 < 0x28 && self->f2B8 == 0) {
            func_L39_006C45C8(self, i19, &l130);
            i20 = func_L39_006C46F0(self, i19);
            if (D_001A5CD0.b168 != 0 && i20 >= 0 && l130 < 0) {
                if (self->f2E0 == 2 && self->b2E5 == 0) {
                    r17 = 1;
                } else {
                    mgr = D_L39_00247914;
                    {
                        s32 s16 = func_0059A970(0x16CB);
                        s32 s2 = func_0059A970(0x15FE);
                        r17 = func_L39_006878A0(mgr, s16, s2, 0);
                    }
                }
                if (r17 == 0) {
                    func_L39_006C4360(self, i19);
                    mgr = D_L39_00247914;
                    func_L39_006872E8(mgr, func_0059A970(0x1720), D_L39_00249550, 4, 0.6f, 0);
                    return 1;
                }
                if (r17 != 1) {
                    return 1;
                }
                {
                    s32 s1 = func_0059A970(0x15FF);
                    func_00120048(buf, s1, (u8 *)D_L39_00241640 + (i20 << 4));
                }
                mgr = D_L39_00247914;
                {
                    s32 s2 = func_0059A970(0x1031);
                    if (func_L39_006872E8(mgr, (s32)buf, (void *)s2, 3, 0.6f, 0) == r17) {
                        D_L39_00241640->eF0[i20] = 5;
                    }
                }
                return 1;
            }
            if (D_001A5CD0.b168 != 0 && i20 < 0) {
                {
                    s32 *arg;
                    if (i19 - D_001A5CD0.f130 < D_001A5CD0.f138) {
                        arg = &D_001A5CD0.f138;
                    } else {
                        arg = &D_001A5CD0.f13C;
                    }
                    func_L39_005B70A0(arg, 0, 1);
                }
                if (!(i19 < D_001A5CD0.f130 + D_001A5CD0.f138 + D_001A5CD0.f13C)) {
                    func_L39_0068B2F8(self, self->f290 - 1, 0);
                }
            } else if (i20 >= 0 && l130 >= 0) {
                p = D_L39_00241640;
                if (p->eF0[0] < 7) {
                    s16 *ep = &p->eF0[i20];
                    s32 val = *ep;
                    if (val == 0) {
                        func_L39_006C38E0(self, i19, 1);
                        return 1;
                    }
                    if (val != 6) {
                        return 1;
                    }
                    if (D_001A5CD0.b168 == 0) {
                        func_L39_006C4308(self, l130 != 0 ? 3 : 1, l130);
                        return 1;
                    }
                    *ep = 0;
                    func_L39_006C38E0(self, i19, 1);
                    return 1;
                }
            }
        }

        sel = self->f290;
        if (sel == 3 && self->f2B8 == 0) {
            s32 r = func_L39_006C4788(self, 0);
            if (r >= 0) {
                k = func_L39_006C46F0(self, r);
                if (D_001A5CD0.b168 != 0 && k >= 0) {
                    D_L39_00241640->eF0[k] = 0;
                }
                p = D_L39_00241640;
                if (p->eF0[k] == 0 && k >= 0) {
                    func_L39_006873F0(D_L39_00247914, D_L39_00249550, 3, (u32)(self->f2CC - 1) < 2);
                    return 1;
                }
                func_L39_006C4308(self, 4, 0);
                return 1;
            }
        }
        sel = self->f290;
        if (sel == 5) {
            do_send = 1;
        } else if (sel == 4 && D_001A5CD0.b168 != 0) {
            s32 v;
            if (self->b2A8 == 0) {
                return 1;
            }
            v = func_L39_006CC238(3, D_001A5CD0.f5F4);
            if (v < 8) {
                func_L39_006CC2A8(3, &D_001A5CD0.f5F4, v + 8);
            }
            p = D_L39_00241640;
            p->eF0[0] = 7;
            p->f174 = D_001A5CD0.f128 + 0xFA0;
            func_0019B5E8(2);
            func_00199A20();
            return 1;
        }
    }

    if (do_send || a1 == 8) {
        func_L39_00687640(D_L39_00247914, self->f2E0, self->f2D4, self->f2E8, self->b2E4, self->f2EC,
                          self->f2F0, self->f2D8, self->b300, self->b301, self->b302, self->b303, self->b2E5);
        return 1;
    }

    if (a1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_006C3778(self, 0, 1, -1);
        return 1;
    }

    if (func_L39_0068AEF8(self, a1) != 0) {
        return 1;
    }

    sel = self->f290;
    obj = self->f110[sel];
    obj->vt->f30(obj, &l134, &l138);
    first = -1;
    last = -1;
    if ((u32)(sel - 0xF) < 0x28) {
        for (i = 0xF; i < 0x37; i++) {
            s32 ty = self->f110[i]->f4;
            if (ty == 3 || ty == 4 || ty == 5) {
                last = i;
                if (first == -1) {
                    first = i;
                }
            }
        }
        flags = (sel != first);
        if (sel != last) {
            flags = flags | 2;
        }
        func_L39_00689F00(self, flags, 3, 3, 0.5f, l138, 0.805f, 0.035f, 0.041f, 1.0f);
    } else {
        for (i = 3; i < 5; i++) {
            s32 ty = self->f110[i]->f4;
            if (ty == 3 || ty == 4 || ty == 5) {
                last = i;
                if (first == -1) {
                    first = i;
                }
            }
        }
        flags = (sel != first);
        if (sel != last) {
            flags = flags | 2;
        }
        func_L39_00689F00(self, flags, 3, 3, 0.287f, l138, 0.38f, 0.035f, 0.041f, 1.0f);
    }
    return 0;
}
