/* functional: medium. NOTE: the file context declares `extern void func_L01_00452FB0();` (the wrapper's), which conflicts with the s32 return and the real 5-argument signature (callers use (void *, void *, s32, s32, s32)); the lead fixes that declaration when landing; checked with --no-context. Control-flow translation of the assembly block by block (register $21 is the returned state 0..6); the three 3-argument calls reached with leftover registers are passed explicitly. Constants and offsets checked against the retail words; D_L01_001E001C is read as a plain word (lw 0x376C($gp)). Bytes differ (scheduling). */
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_001A4C60[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E001C;
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00452E60(void *, void *);
extern void *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_00452F30(void *, void *);
extern void func_L01_00455E18(void *, void *, void *);
extern void func_L01_00459BE8(f32, void *, s32);
extern f32 func_L01_004510F8(s32, s32, s32);
extern s32 func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00454370(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_00451048(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

typedef struct { f32 x, y, z, w; } V4_00452FB0;

s32 func_L01_00452FB0(void *self_, void *ai_, s32 o, s32 flag, s32 flag2) {
    u8 *self = self_;
    u8 *ai = ai_;
    V4_00452FB0 tgt;
    u8 *t, *cfg, *obj, *tm;
    u8 *e;
    f32 prog, f21, f2, f20, f3, f0;
    s32 st, mode, ok, dmg, thr, a, b;
    u8 *row;
    s32 i;

    st = 0;
    if ((*(u16 *)(self + 0x34) & 0x20) == 0) {
        return 0;
    }
    t = *(u8 **)(self + 0x68);
    tm = *(u8 **)(t + 0x20);
    if (ai == 0) {
        return 0;
    }
    cfg = *(u8 **)t;
    if (cfg == 0) {
        return 0;
    }
    func_L01_0044ABD0(self, ai);
    func_L01_00452E60(self, ai);
    f21 = 0.0f;
    obj = func_L01_00447490(self, flag != 0 ? 1 : 0x10000, 0);
    mode = 0;
    if (func_0038CB00(cfg + 6) == 0) {
        obj = 0;
    }
    func_0038CAD0(ai + 0xBC);
    if (obj != 0) {
        mode = 1;
        f21 = *(f32 *)(obj + 0x2C);
        mode = (obj[0x28] == 0xA) ? 1 : 0;
        f2 = f21;
        if (mode != 0) {
            if (*(s16 *)(self + 0xAA) == 0x1B39) {
                if (*(f32 *)cfg <= 0.0f) {
                    mode = 0;
                }
            }
        }
        if (*(f32 *)(ai + 0xA8) != 0.0f) {
            if (*(u8 **)(obj + 0x20) != 0) {
                if (*(s16 *)(*(u8 **)(obj + 0x20) + 0xAA) == *(s16 *)(self + 0xAA)) {
                    *(f32 *)(obj + 0x2C) = f2 * *(f32 *)(ai + 0xA8);
                }
            }
        }
        if (o != 0) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) * *(f32 *)(ai + 0xAC);
        }
    }
    f20 = func_L01_004474E8(self, obj);
    self[0xA8] = 0xFF;
    if (func_L01_00452F30(self, ai) != 0) {
        f20 = *(f32 *)cfg;
        obj = 0;
    } else if (*(f32 *)(self + 0x18) < *(f32 *)(ai + 0x40)) {
        f20 = *(f32 *)cfg;
        obj = 0;
    }
    if (mode == 0) {
        *(f32 *)cfg = *(f32 *)cfg - f20;
    }
    row = D_L01_002C5600 + D_001425C0[0x37] * 0xF0;
    if (row[1] != 0 && obj != 0) {
        u8 *p3 = *(u8 **)(obj + 0x20);
        if (p3 != 0 && (*(u16 *)(p3 + 0x34) & 0x20) != 0) {
            u8 *p2 = *(u8 **)(p3 + 0x68);
            if (p2 != 0) {
                u8 *p1 = *(u8 **)p2;
                if (p1 != 0 && p1[0x2F] != 0) {
                    if (*(f32 *)cfg <= (f32)*(s16 *)(cfg + 4) * 0.75f) {
                        cfg[0x2F] = 1;
                    }
                }
            }
        }
    }
    if (tm != 0) {
        func_L01_00455E18(self, tm, cfg);
    }
    if (f20 == 0.0f) {
        return 0;
    }
    func_L01_00459BE8(f20, self, cfg[0x17]);
    *(s16 *)(ai + 0x70) = -1;
    if (obj != 0 && *(u8 **)(obj + 0x20) != 0) {
        *(s16 *)(ai + 0x70) = (s16)((*(s32 *)(obj + 0x20) - D_L01_001E001C) >> 8);
    }
    row = D_L01_002C5600 + D_001425C0[cfg[0x17]] * 0xF0;
    f0 = (f32)*(s16 *)(cfg + 4) * *(f32 *)(ai + 0x58);
    f3 = f20 * *(f32 *)(row + 0x50);
    thr = (f0 <= f3) ? 0x5A : 0x12C;
    if (ai[0x77] == 0) {
        a = D_L01_001DFB40 - *(s32 *)(ai + 0x44);
        if (a <= 0) {
            a = -a;
        }
        if ((thr * 5 + 2) / 6 < a) {
            if (f20 < f0) {
                f20 = f0;
            }
        }
    }
    f0 = 0.0f;
    if (mode != 0) {
        st = 3;
    } else {
        f3 = *(f32 *)cfg;
        f0 = 0.0f;
        if (f3 <= 0.0f) {
            st = 4;
        } else {
            f2 = (f32)*(s16 *)(cfg + 4);
            if (f2 * *(f32 *)(ai + 0x5C) <= f20) {
                st = 3;
            } else if (f2 * *(f32 *)(ai + 0x58) <= f20) {
                st = 2;
            } else if (f20 != 0.0f && ai[0x77] == 0 && obj != 0 && *(u8 **)(obj + 0x20) != 0
                       && *(s16 *)(*(u8 **)(obj + 0x20) + 0xAA) == 0x47) {
                st = 2;
            } else if (f21 != 0.0f) {
                st = 1;
            }
        }
        if (f3 <= f0) {
            if ((*(s16 *)(self + 0xAA) ^ 0x19DB) == 0) {
                st = 5;
            }
        }
        if (obj != 0 && *(u8 **)(obj + 0x20) != 0) {
            if (*(s16 *)(*(u8 **)(obj + 0x20) + 0xAA) == 0x1843 && *(s32 *)(ai + 0xB8) == 0) {
                st = (f3 <= f0) ? 4 : 2;
            }
        }
        if (o != 0) {
            if ((u32)(st - 1) <= 2) {
                st = 6;
            }
        }
    }
    if (st >= 2 && obj != 0 && cfg[0x17] == 9) {
        f20 = func_L01_004510F8((s32)self, (s32)(obj + 0x10), 0);
        *(V4_00452FB0 *)(obj + 0x10) = *(V4_00452FB0 *)(self + 0x10);
        ((f32 *)(obj + 0x10))[0] -= ((f32 *)D_001A4C60)[0];
        ((f32 *)(obj + 0x10))[1] -= ((f32 *)D_001A4C60)[1];
        ((f32 *)(obj + 0x10))[2] -= ((f32 *)D_001A4C60)[2];
        ((void (*)(void *, void *, void *, s32, f32))func_L01_00451048)(self, obj + 0x10, obj + 0x10, 0, f20);
    }
    if (st == 0) {
        return 0;
    }
    if ((*(u16 *)(ai + 0x38) & 3) != 0) {
        return 0;
    }
    if (self[0x95] == ai[0x48] && st < 4) {
        if (ai[0x75] != 0) {
            return 0;
        }
        if (ai[0x1A] < 2) {
            return 0;
        }
    }
    if (obj != 0 && (*(u32 *)(obj + 0x30) & 1) != 0) {
        tgt = *(V4_00452FB0 *)(obj + 0x10);
    } else {
        func_0038CE20(&tgt, self + 0xC0, -1.0f);
        tgt.z = 1.0f;
        ((u32 *)&tgt)[3] = 0x45AFDF66;
    }
    ok = 1;
    if ((*(u32 *)(ai + 0xB4) & 1) != 0) {
        a = ai[0x10];
        b = ai[0x48];
        if (a == 0xFF || self[0x20] == a) {
            if (b == 0xFF || self[0x95] == b) {
                ok = (st == 4) ? 1 : 0;
            }
        }
    }
    if (*(s32 *)(ai + 0xBC) != 0 || flag2 != 0) {
        if (*(f32 *)cfg <= 0.0f) {
            goto call;
        }
        goto notdone;
    }
call:
    if (ok != 0) {
        if (func_003C56E0(self, ai, &tgt, st, -1) != 0) {
            *(s32 *)(ai + 0x44) = D_L01_001DFB40;
            if (ai[0x48] == 0xFF || ai[0x48] == 0) {
                if (ai[0x10] != 0xFF && ai[0x10] != 0) {
                    func_L01_004450F0(self, ai[0x10], -1);
                }
            } else {
                func_L01_004450F0(self, ai[0x10], ai[0x48]);
            }
            ai[0x1A] = 0;
            func_L01_00454370(self, ai);
        }
        return st;
    }
notdone:
    ai[7] = 0xFF;
    func_003C4A40(self, ai);
    return st;
}
