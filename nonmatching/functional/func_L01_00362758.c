/* functional: medium. 619 words differ (structure/registers); written from asm by tracing every branch, delay slot and gp access; all float constants checked from hex. Unsure: callee prototypes (func_L01_00363D90/DD0 passed self like asm; 004EAA80/004BA800 void), w30 temp layout, D_L01_001DD7A0/A4/A8 float names, kinds of func_L01_00364C20/3631C8 args (self, vars+0x10 / self) */
/* VU0 helpers written with named vf clobbers (this file's flags lack the "j" register class) */
static __inline__ void qv_sub(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
static __inline__ void qv_add(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
typedef int Q_00362758 __attribute__((mode(TI)));
extern u8 D_001A4BE0_00362758[];
extern u8 D_001A30B0[];
extern u8 D_00142647[];
extern u8 *D_001D52FC;
extern s32 D_001D6694;
extern s32 D_L01_001DD790;
extern s32 D_L01_001DD798;
extern s32 D_L01_001DD79C;
extern f32 D_L01_001DD7A0;
extern f32 D_L01_001DD7A4;
extern f32 D_L01_001DD7A8;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1B24;
extern s32 D_L01_001E1B28;
extern s16 D_L01_001E1B12[];
extern f32 D_L01_001E1B34[];
extern f32 D_L01_001E1AE4[];
extern Q_00362758 D_L01_0028E3A0[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E29E0[];
static void slot_free_00362758(u8 *self, u8 *vars) {
    extern void func_003A4F28(s32);
    s32 idx = *(s32 *)(vars + 4);
    if (idx != -1) {
        u8 *slot = D_001A30B0 + (idx << 7);
        if (*(u8 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(vars + 4) = -1;
}
void func_L01_00362758(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_00382538(void);
    extern s32 func_L01_004572B0(void *, s32, void *);
    extern void *func_L01_00457480(s32, void *);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern s32 func_L01_00363D90(void *);
    extern s32 func_L01_00363DD0(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_004BA800(void);
    extern void func_L01_004EA7D8(s32);
    extern void func_L01_00364C20(void *, void *);
    extern s32 func_L01_004AA710(void *, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_003631C8(void *);
    extern void func_L01_00363BF0(void *);
    extern void func_L01_00366240(void *);
    extern void func_L01_005003D0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern u32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_00363170(s32 *);
    extern void func_L01_00363468(void *);
    extern void func_L01_003968F8(void *, s32, void *, void *, s32, s32);
    extern void func_L01_003839C8(f32, void *, void *, void *, void *, s32, s32);
    extern s32 func_L01_00363138(void *);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_L01_00451D38(void *, s32, s32, f32);
    extern void func_L01_00421988(s32, s32, s32, s32, f32);
    extern void func_L01_00363690(void *);
    u8 *vars = *(u8 **)(self + 0x68);
    u8 *hb = D_001A4BE0_00362758;
    u8 *hero;
    u8 *handle;
    s32 row_kind;
    s32 hs;
    s32 i;
    s32 r;
    s32 w30[4];
    S_38C110v t0, t1, t2;

    if (self[0x20] == 0) {
        *(f32 *)(vars + 0x20) = 0.6000000238418579f;
        self[0x20] = 1;
        func_003C2F58(self, 0, vars + 0x10);
        D_L01_0028E3A0[0] = *(Q_00362758 *)(vars + 0x10);
        hero = *(u8 **)(hb + 0x25C0);
        D_L01_001E1B28 = 0x11;
        t0 = *(S_38C110v *)(hero + 0xC0);
        for (i = 0; i < 9; i++) {
            D_L01_001E1B12[i] = 0;
            qv_add(&D_L01_0028E3A0[i + 1], &D_L01_0028E3A0[i], &t0);
            D_L01_001E1AE4[0] = 1.0f;
            D_L01_001E1B34[i] = func_00382538();
        }
        *(s32 *)(vars + 0x50) = func_L01_004572B0(self, 0, w30);
        *(void **)(vars + 0x54) = func_L01_00457480(*(s16 *)(self + 0xAA), *(void **)(vars + 0x50));
    }

    row_kind = D_L01_002C5600[D_00142647[0]].kind;
    if (row_kind == 0) {
        D_L01_001DD790 = 10;
    } else if (row_kind == 1) {
        D_L01_001DD790 = 12;
    } else if (row_kind == 2) {
        D_L01_001DD790 = 15;
    } else {
        D_L01_001DD790 = 20;
    }
    if (row_kind == 2) {
        *(s16 *)(self + 0x7C) = 3;
    } else if (row_kind == 1) {
        *(s16 *)(self + 0x7C) = 1;
    } else if (row_kind >= 3) {
        *(s16 *)(self + 0x7C) = 0x13;
    }

    if (self[0x42] == self[0x43]) {
        if (self[0x60] & 2) {
            func_L01_00444F38(self, 1, 0, 2, 0);
        }
    }
    if ((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(hb + 0x1210)) == 0 && *(s32 *)(hb + 0x25C4) != 0x7D) {
        if (func_L01_00363D90(self) != 0 || func_L01_00363DD0(self) != 0) {
            func_L01_004450F0(self, 1, -1);
        } else {
            slot_free_00362758(self, vars);
            func_L01_004EAA80();
            func_L01_004450F0(self, 2, -1);
        }
    }
    if (D_001D6694 == 6 || func_L01_004BA800() != 0 || (*(s32 *)(hb + 0x25C4) == 0x65 || *(s32 *)(hb + 0x25C4) == 0x74)) {
        slot_free_00362758(self, vars);
    }

    if (self[0x20] == 1) {
        if ((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(hb + 0x1210)) != 0
            && D_001D6694 == 0
            && *(s32 *)(hb + 0x25C4) != 0x74
            && (*(unsigned long *)(hb + 0x25E8) & 0xFF00000000FFUL) == 0
            && *(s32 *)(hb + 0x1220) >= 0xD
            && *(s32 *)(hb + 0x25C4) != 0x7D) {
            func_003C2F58(self, 0, vars + 0x10);
            if (D_L01_001E1B28 == 0x13) {
                func_L01_004EA7D8(-1);
            }
            func_L01_00364C20(self, vars + 0x10);
            if (func_L01_004AA710(self, *(s32 *)(vars + 4)) == 0 && D_001D6694 == 0) {
                if (*(s32 *)(hb + 0x25C4) != 0x74) {
                    *(s32 *)(vars + 4) = func_003A52A0(0, 4, self);
                }
            }
            if (self[0x43] != 2) {
                func_003C3A10(self, 2, 0, 0);
            }
            if (func_0038CAD0(&D_L01_001E1B28) != 0) {
                if ((D_L01_001DFB40 & 3) == 0) {
                    func_L01_003631C8(self);
                }
                func_L01_00363BF0(self);
            }
        } else {
            slot_free_00362758(self, vars);
            func_L01_004EAA80();
            D_L01_001E1B28 = 0x11;
            func_L01_00366240(self);
        }
    }

    func_0038CAD0(vars + 0x34);
    if (self[0x20] == 2) {
        if (*(s32 *)(hb + 0x25C4) == 1) {
            func_L01_005003D0(0x1D, 1);
        }
        func_L01_00366240(self);
        func_003C2F58(self, 0, vars + 0x10);
        func_0038CF68(&t0, *(u8 **)(hb + 0x25C0) + 0xC0, 1.0f);
        handle = func_L01_00450BB0(vars + 0x10, &t0, 0.12217304855585098f, 0.13962633907794952f, 35.0f, 0.7853981852531433f, 0.6108652353286743f, 0);
        if (handle != 0) {
            D_L01_001E1B24 = (s32)handle;
            func_L01_004CB128(&t1, handle, 0);
            qv_sub(&t0, &t1, vars + 0x10);
            func_0038CF68(&t0, &t0, 20.0f);
            qv_add(vars + 0x40, &t0, vars + 0x10);
            if (*(s32 *)(hb + 0x25C4) != 0x1D && *(s32 *)(hb + 0x16B0) == 0) {
                f32 ratio = func_0038CF00(D_L01_001E29C0, &t1) / 150.0f;
                f32 turn = func_0038DAB8(*(f32 *)(vars + 0x58), 0.03490658476948738f);
                *(f32 *)(vars + 0x58) = turn;
                ratio = ratio * 0.6499999761581421f;
                func_L01_003F6F20(0, self, 0x600FFF0F, &t1, 0x26, -1, 4,
                                  fabs_asm(0.8999999761581421f - ratio), -turn, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        } else {
            D_L01_001E1B24 = 0;
        }
        if (*(s32 *)(hb + 0x25C4) == 0x1D || *(s32 *)(hb + 0x16B0) != 0) {
            func_0038CF68(&t0, D_L01_001E29E0, 20.0f);
            r = (s32)func_L01_004CB1F0(0.9700000286102295f, 150.0f);
            if (0.9800000190734863f < *(f32 *)(hb + 0x15F0)) {
                D_L01_001E1B24 = *(s32 *)(hb + 0x15CC);
            } else {
                D_L01_001E1B24 = 0;
            }
            func_L01_003F6F20(0, self, r, 0, 0x44, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        } else if (handle != 0) {
            *(s32 *)(hb + 0x16D8) = 0;
            *(s32 *)(hb + 0x16D4) = 0;
        } else {
            *(s32 *)(hb + 0x16D4) = 0;
            func_0038CF68(&t0, *(u8 **)(hb + 0x25C0) + 0xC0, 20.0f);
            *(s32 *)(hb + 0x16D8) = 0;
        }
        qv_add(vars + 0x40, &t0, vars + 0x10);
        if ((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(hb + 0x1210)) != 0
            && *(s32 *)(vars + 0x34) <= 0
            && (*(unsigned long *)(hb + 0x25E8) & 0xFF00000000FFUL) == 0) {
            func_0038CF68(&t1, &t0, 0.5f);
            qv_add(&t2, vars + 0x10, &t1);
            func_0038CF68(&t0, &t0, 0.8000000715255737f);
            r = func_L01_00363170(&w30[1]);
            if (r == -1) {
                func_L01_004450F0(self, 1, -1);
            } else {
                u8 *row;
                func_L01_00363468(self);
                func_003A52A0(2, 0, self);
                row = (u8 *)&D_L01_002C5600[D_00142647[0]];
                if (row[1] >= 4) {
                    func_L01_003968F8(self, *(s32 *)(vars + 0x50), &t2, &t0, 0, D_L01_001E1B24);
                    D_L01_001E1B24 = 0;
                } else {
                    func_L01_003839C8(*(f32 *)(row + 0x6C), self, &t0, &t2, hb + 0x90, r, D_L01_001E1B24);
                    D_L01_001E1B24 = 0;
                }
            }
            *(s32 *)(vars + 0x34) = 0x19;
        }
    }

    {
        s32 cnt = func_L01_00363138(self);
        f32 frac = 1.0f - (f32)cnt / (f32)D_L01_001DD790;
        D_L01_001DD7A8 = frac;
        r = func_L01_00451D38(vars + 0x38, D_L01_001DD798, D_L01_001DD79C,
                              func_003C4088(D_L01_001DD7A0, D_L01_001DD7A4, frac) * 0.01745329238474369f * 0.020000001415610313f);
        func_L01_00421988(1, r, 0, 0, D_L01_001DD7A8);
    }
    func_L01_00363690(self);
}
