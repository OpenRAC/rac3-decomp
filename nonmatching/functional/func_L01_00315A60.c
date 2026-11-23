/* functional: medium. Control flow, calls and branch order follow retail (state 0 init, state 1 run, gp state machine 0/1/2); hero struct accessed by offset; some callee argument meanings (func_L01_003F6F20 effect spawner's 14 args, func_L01_0030D408) are copied from the register setup, not named. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_315A60;
typedef int s128_315A60 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x4C];
    f32 f4C;
    u8 pad50[0xF0 - 0x50];
} Tbl_315A60;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0x4C - 2];
    f32 f4C;
    u8 pad50[0xF0 - 0x50];
} Ent_315A60;
typedef struct {
    f32 f0;
    s32 w4, w8, wC;
    f32 f10;
    f32 f14;
    u8 pad18[0x20 - 0x18];
    u8 pad20[0x14];
    f32 f34;
    u8 pad38[4];
    f32 f3C;
} Vars_315A60;
typedef struct {
    u8 pad0[0x6F0];
    u8 a6F0[0xBD8 - 0x6F0];
    s32 wBD8;
    u8 padBDC[0x1210 - 0xBDC];
    s32 w1210;
    u8 pad1214[0x1220 - 0x1214];
    s32 w1220;
    u8 pad1224[0x1430 - 0x1224];
    s32 w1430;
    u8 pad1434[0x16B0 - 0x1434];
    s32 w16B0;
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 w16D4;
    s32 w16D8;
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *p25C0;
    s32 w25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
    u8 pad25EE[0x2874 - 0x25EE];
    s16 h2874;
    u8 pad2876[0x28BC - 0x2876];
    s32 w28BC;
} Hero_315A60;
typedef struct {
    u8 pad0[0x1A0];
    s32 w1A0;
    s32 w1A4;
} Ctl_315A60;
extern u8 D_001425D0;
extern u8 D_00142A60[];
extern Ent_315A60 D_L01_002C5600[];
extern Hero_315A60 D_001A4BE0;
extern Ctl_315A60 *D_001D52FC;
extern f32 D_L01_001E176C;
extern s32 D_L01_001E1750;
extern V_315A60 D_L01_001E29C0;
extern V_315A60 D_L01_001E29E0;
extern u8 *D_L01_001EEA80[];
extern u8 D_L01_00272340[];
extern s32 D_L01_001DC798;
extern f32 D_L01_001DC79C;
extern f32 D_L01_001DC7A0;
extern f32 D_L01_001DC7A4;
extern f32 D_L01_001DC7A8;
extern f32 D_L01_001DC7AC;
extern s32 D_L01_001DC7B0;
extern void *D_L01_001DC7B4;
extern s32 D_L01_001DC7B8;
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0043A430(void *, s32, void *);
extern s32 func_L01_004572B0(void *, s32, void *);
extern s32 func_L01_00457480(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0030D688(void);
extern void func_L01_005003D0(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004CB1F0(f32, f32);
extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00457588(f32, void *, void *, void *);
extern u8 *func_L01_00450D20(void *, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_005119E0(s32);
extern f32 func_0038CF00(void *, void *);
extern void *func_00382348(void *);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0040E050(void *);
extern s32 func_L01_0030D678(void);
extern s32 func_L01_005118D0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00451290(void *, void *, s32);
extern void *func_L01_0030D408(void *, s32, void *, void *);
extern void func_L01_00404A10(void (*)(u8 *), u8 *);
extern void func_L01_003163D0(u8 *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

void func_L01_00315A60(u8 *obj) {
    Ent_315A60 *tbl;
    Vars_315A60 *vars;
    Hero_315A60 *hero;
    f32 f20, f12v;
    s32 i, n, flag, st;
    V_315A60 sp0, v10, v20, v30, v40;
    u8 buf50[16];
    u8 *fp;
    u8 *m;
    u8 *r17;
    s32 r;

    tbl = &D_L01_002C5600[D_001425D0];
    f20 = tbl->f4C * 0.020000001415610313f;
    vars = *(Vars_315A60 **)(obj + 0x68);
    if (tbl->b1 >= 2) {
        D_00142A60[0x10] |= 0x20;
    }
    if (obj[0x20] == 0) {
        if (obj[0x43] != 0 || (obj[0x60] & 2) != 0) {
            func_003C3A10(obj, 1, 0, 0);
        }
        func_L01_0043A430(obj, 0, (u8 *)vars + 0x20);
        vars->wC = -1;
        vars->f0 = 0.36666667461395264f;
        vars->f10 = 0;
        vars->f14 = 0;
        obj[0x20] = 1;
        D_L01_001E176C = -1.0f;
        D_L01_001DC7B0 = 0;
        D_L01_001DC798 = 0;
        vars->w4 = func_L01_004572B0(obj, 0, buf50);
        vars->w8 = func_L01_00457480(*(s16 *)(obj + 0xAA), vars->w4);
        for (i = 0; i < 4; i++) {
            s32 *e = (s32 *)(D_L01_00272340 + i * 0x80);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
            ((f32 *)e)[3] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[4] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[5] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[6] = func_003824E0(0.25f, 0.75f);
            ((f32 *)e)[7] = func_003824E0(0.25f, 0.75f);
            ((f32 *)e)[8] = func_003824E0(0.25f, 0.75f);
            e[9] = 0;
            e[10] = 0;
            e[11] = 0;
            ((f32 *)e)[12] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[13] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[14] = func_L01_00443A18(0.05000000074505806f, 0.30000001192092896f);
            ((f32 *)e)[15] = func_003824E0(0.25f, 0.75f);
            ((f32 *)e)[16] = func_003824E0(0.25f, 0.75f);
            ((f32 *)e)[17] = func_003824E0(0.25f, 0.75f);
            *(s128_315A60 *)((u8 *)D_L01_00272340 + 0x50 + i * 0x80) = 0;
            *(s128_315A60 *)((u8 *)e + 0x60) = 0;
        }
        func_L01_0030D688();
        return;
    }
    if (obj[0x20] != 1) {
        return;
    }
    hero = &D_001A4BE0;
    D_L01_001E176C = -1.0f;
    if (hero->w1430 != 0) {
        hero->wBD8 = hero->w1430;
    }
    if (D_L01_001DC798 == 0) {
        D_L01_001DC798 = 1;
    }
    if (hero->w25C4 == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    flag = 1;
    if (hero->w25C4 == 0x1D || hero->w16B0 != 0) {
        r = func_0038CAD0(&hero->w28BC);
        flag = (r != 0) ? 1 : 0;
        func_L01_003F6F20(0, obj, func_L01_004CB1F0(1.0f, 150.0f), 0, 0x21, -1, 4,
                          0.800000011920929f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    } else {
        hero->w16D4 = 0;
        hero->w28BC = 0x21;
        hero->w16D8 = 0;
    }
    func_003C2F58(obj, 0, &v10);
    if (hero->wBD8 != 0) {
        func_L01_00457588(f20, (void *)hero->wBD8, &v10, &sp0);
        fp = (u8 *)hero->wBD8;
    } else {
        fp = func_L01_00450D20(hero->a6F0, 0, 0.17453292012214661f, 0.17453292012214661f, 20.0f,
                               0.7853981852531433f, 0.7853981852531433f);
    }
    if (vars->f0 == 0.0f && fp != 0 && func_L01_005119E0(-1) != 0) {
        v20 = *(V_315A60 *)(fp + 0x10);
        r17 = func_00382348(fp);
        if (r17 != 0) {
            func_003C5180(fp + 0x10, &v30, 1);
            func_0038CE20(&v30, &v30, *(f32 *)(r17 + 0x10));
            v20.x = v30.x + *(f32 *)(fp + 0x10);
            v20.y = v30.y + *(f32 *)(fp + 0x14);
            v20.z = v30.z + *(f32 *)(fp + 0x18);
        }
        f12v = func_0038CF00(&D_L01_001E29C0, &v20);
        f12v = f12v / 150.0f;
        func_L01_003F6F20(0, obj, (s32)0xFF0FFF0F, &v20, 0x26, -1, 4,
                          __builtin_fabsf(0.8999999761581421f - f12v * 0.6499999761581421f), 0.0f, 90.0f,
                          0.5f, 0.5f, 40.0f, 40.0f);
    }
    if (func_L01_0040E050(vars) != 0) {
        if (hero->b25ED == 0 && (D_001D52FC->w1A0 & hero->w1210) != 0 && flag != 0 &&
            func_L01_0030D678() == 0 && hero->w1220 >= 0x13) {
            if (func_L01_005118D0(-1, 1) != 0) {
                D_L01_001E1750 = 1;
                func_003A52A0(2, 0, obj);
                if (D_L01_001DC7B0 == 0) {
                    vars->f10 = D_L01_001DC7A4;
                    D_L01_001DC7B0 = 1;
                    vars->f0 = 0.5f;
                } else if (D_L01_001DC7B0 == 2) {
                    D_L01_001DC7B0 = 1;
                    vars->f0 = 0.5f;
                }
            } else if ((D_001D52FC->w1A4 & hero->w1210) != 0 || D_L01_001E1750 == 1) {
                func_003A52A0(7, 0, obj);
                D_L01_001E1750 = 0;
            }
        }
    }
    st = D_L01_001DC7B0;
    if (st == 0) {
        if (vars->f10 < D_L01_001DC7A4) {
            vars->f10 = vars->f10 + D_L01_001DC7A8;
            if (D_L01_001DC7A4 < vars->f10) {
                vars->f10 = D_L01_001DC7A4;
            }
        }
    } else if (st == 1) {
        vars->f10 = vars->f10 + D_L01_001DC79C;
        if (D_L01_001DC7AC < vars->f10) {
            func_003C2F58(obj, 0, &v20);
            if (hero->h2874 == 1) {
                func_0038CF68(&sp0, obj + 0xD0, -f20);
            } else if (hero->w16B0 == 1) {
                func_0038CF68(&sp0, &D_L01_001E29E0, f20);
            } else {
                func_0038CF68(&sp0, hero->a6F0, f20);
            }
            n = func_003D4D00(&v20, 0, obj, 0, 1.0f);
            for (i = 0; i < n; i++) {
                m = D_L01_001EEA80[i];
                r17 = func_00382348(m);
                if (m == hero->p25C0) {
                    continue;
                }
                if ((*(u16 *)(m + 0x34) & 0x1000) == 0) {
                    continue;
                }
                if (*(s16 *)(m + 0xAA) == 0xC87) {
                    continue;
                }
                if (*(s16 *)(m + 0xAA) == 0xECC) {
                    continue;
                }
                v40 = *(V_315A60 *)(m + 0x10);
                if (r17 != 0) {
                    func_L01_00451290(m, &v30, 1);
                    func_0038CE20(&v30, &v30, *(f32 *)(r17 + 0x10));
                    v40.x = v30.x + v40.x;
                    v40.y = v30.y + v40.y;
                    v40.z = v30.z + v40.z;
                }
                sp0.x = v40.x - v20.x;
                sp0.y = v40.y - v20.y;
                sp0.z = v40.z - v20.z;
                func_0038CF68(&sp0, &sp0, f20);
                break;
            }
            if (fp != 0) {
                v30 = *(V_315A60 *)(fp + 0x10);
                r17 = func_00382348(fp);
                if (r17 != 0) {
                    func_003C5180(fp + 0x10, &v40, 1);
                    func_0038CE20(&v40, &v40, *(f32 *)(r17 + 0x10));
                    v30.x = v40.x + *(f32 *)(fp + 0x10);
                    v30.y = v40.y + *(f32 *)(fp + 0x14);
                    v30.z = v40.z + *(f32 *)(fp + 0x18);
                }
                sp0.x = v30.x - v20.x;
                sp0.y = v30.y - v20.y;
                sp0.z = v30.z - v20.z;
                func_0038CF68(&sp0, &sp0, f20);
            }
            D_L01_001DC7B4 = func_L01_0030D408(obj, vars->w4, &v20, &sp0);
            if (D_L01_001DC7B4 != 0) {
                *(u8 **)((u8 *)D_L01_001DC7B4 + 0xB8) = obj;
            }
            D_L01_001DC7B8 = 0x2A;
            D_L01_001DC7B0 = 2;
        }
    } else if (st == 2) {
        vars->f10 = vars->f10 - D_L01_001DC7A0;
        if (vars->f10 <= D_L01_001DC7A4) {
            vars->f10 = D_L01_001DC7A4;
            D_L01_001DC7B0 = 0;
        }
    }
    if (obj[0x31] != 0) {
        func_L01_00404A10(func_L01_003163D0, obj);
    }
    vars->f14 = func_0038DB00(vars->f14, vars->f10 * 0.3769911527633667f);
    vars->f34 = func_0038D0B0(vars->f14 * 0.5f);
    vars->f3C = func_0038D098(vars->f14 * 0.5f);
}
