/* functional: medium-high. Multiplayer menu per-frame input handler (a1 = event: 5 = back, 7 = select). Syncs the focus state to the focused widget, runs the two screen handlers, then for select events dispatches on the focused row (0x290): start timer, pick/cycle a server id and join, open sub-menus (menu state 0xC/0xF/0x23/4/9/6/8/0x26/0x1B); finally positions the focus cursor and sets the help text string for the row. Jump tables decoded from data.data.s. func_L39_006B29A8 receives (self, a1) as retail passes $a1 through. Float constants decoded from lui/ori words. Not byte exact (385 words differ, frame size matches). */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_0024D760;
extern u8 *D_L39_00247914;
extern s32 D_001A5CD0[];
extern u8 D_L39_00248EA0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern u8 *func_00381FF0(s32);
extern void func_L39_006B29A8(void *, s32);
extern s32 func_L39_006B2498(void *);
extern s32 func_L39_006B2120(void *, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_006872E8(void *, void *, void *, s32, s32, f32);
extern void func_L39_006B2CE0(void *);
extern void func_L39_006B2D18(void *);
extern s32 func_L39_006877B0(void *, s32);
extern s32 func_L39_006B22B0(void *, void *, s32 *, s32);
extern s32 func_L39_006B2450(void *, s32, s32);
extern void func_L39_0069B960(void *, s32, s32, s32, s32);
extern void func_L39_006A2138(void *, s32, s32);
extern void func_L39_006C69B8(void *, s32);
extern void func_L39_006CEA18(void *, s32);
extern void func_L39_006B5288(void *, s32, s32);
extern void func_L39_00689F00(void *, s32, s32, f32, f32, f32, f32, f32, f32, s32);

typedef void (*Vfn2)(void *, s32, s32);

s32 func_L39_006B19E0(u8 *self, s32 a1) {
    s32 s;
    s32 v;
    s32 i;
    s32 first;
    s32 last;
    s32 flags;
    s32 out0;
    s32 out1;
    f32 pt[2];
    s32 r;
    u8 *o;
    u8 *p;

    func_L39_006B29A8(self, a1);
    if (func_L39_006B2498(self) != 0) {
        return 1;
    }
    s = *(s32 *)(self + 0x290);
    if (s != 0xA && s >= 0) {
        *(s32 *)(self + 0x2B0) = s;
        switch (s) {
        case 0: v = 0; break;
        case 1: v = 1; break;
        case 2: v = 2; break;
        case 3: v = 3; break;
        case 4: v = 4; break;
        case 5: v = 5; break;
        case 6:
        case 7: v = 6; break;
        default: v = -1; break;
        }
        o = *(u8 **)(self + 0x130);
        (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0xDC))(o, v);
    }
    if (func_L39_006B2120(self, a1) != 0) {
        func_L39_00688340(3, 0, 0);
        return 1;
    }
    if (func_L39_0068AEF8(self, a1) != 0) {
        return 1;
    }
    if (a1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        {
            u8 *menu = D_L39_00247914;
            u8 *t1 = func_00381FF0(0xF64);
            u8 *t2 = func_00381FF0(0x1031);
            if (func_L39_006872E8(menu, t1, t2, 3, 0, 0.6f) != 1) {
                return 1;
            }
        }
        func_L39_006B2CE0(self);
        func_L39_006B2D18(self);
    }
    if (a1 == 7) {
        func_L39_00688340(4, 0, 0);
        s = *(s32 *)(self + 0x290);
        if ((u32)s <= 10) {
            switch (s) {
            case 0:
                *(s32 *)(self + 0x2A8) = (s32)func_00130760(func_0012DCB0(), 0x24000);
                *(s32 *)(self + 0x2AC) = 1;
                return 1;
            case 1:
                v = D_001A5CD0[0x7C / 4];
                if ((u32)(v - 0x28) >= 0x3C) {
                    v = *(s32 *)(*(u8 **)(D_L39_0024D760 + 0x30) + 0x28);
                    D_001A5CD0[0x7C / 4] = v;
                }
                while ((u32)(v - 0x28) >= 0x3C) {
                    v = func_L39_006877B0(D_L39_00247914, 1);
                    if (v < 0) {
                        return 1;
                    }
                    D_001A5CD0[0x7C / 4] = v;
                }
                out0 = -1;
                if (func_L39_006B22B0(self, D_L39_00248EA0, &out0, v != 0x63 ? v : 0x28) == 0) {
                    return 1;
                }
                if (func_L39_006B2450(self, out0, 0) == 0) {
                    return 1;
                }
                func_L39_0069B960(*(u8 **)(D_L39_00247914 + 0x94), 0, -1, -1, -1);
                *(s32 *)(D_L39_00247914 + 0x284) = 0xC;
                return 1;
            case 2:
                v = D_001A5CD0[0x7C / 4];
                if (v == -1) {
                    v = *(s32 *)(*(u8 **)(D_L39_0024D760 + 0x30) + 0x28);
                    o = D_L39_00247914;
                } else {
                    o = D_L39_00247914;
                }
                func_L39_006A2138(*(u8 **)(o + 0xA0), 0, v);
                *(s32 *)(D_L39_00247914 + 0x284) = 0xF;
                return 1;
            case 3:
                v = D_001A5CD0[0x7C / 4];
                if (v == -1) {
                    v = *(s32 *)(*(u8 **)(D_L39_0024D760 + 0x30) + 0x28);
                }
                while ((u32)(v - 0x28) >= 0x3C) {
                    v = func_L39_006877B0(D_L39_00247914, 1);
                    if (v < 0) {
                        return 1;
                    }
                    D_001A5CD0[0x7C / 4] = v;
                }
                out1 = -1;
                if (func_L39_006B22B0(self, D_L39_00248EA0, &out1, v != 0x63 ? v : 0x28) == 0) {
                    return 1;
                }
                func_L39_006B2450(self, out1, 1);
                return 1;
            case 4:
                *(s32 *)(D_L39_00247914 + 0x284) = 4;
                return 1;
            case 5:
                p = *(u8 **)(D_L39_0024D760 + 0x38);
                func_L39_006CEA18(p, 0);
                if (p[0x34] != 0) {
                    v = 9;
                } else if (*(s32 *)p != -1) {
                    v = 6;
                } else {
                    v = 8;
                }
                *(s32 *)(D_L39_00247914 + 0x284) = v;
                return 1;
            case 6:
                func_L39_006C69B8(*(u8 **)(D_L39_00247914 + 0xF0), 1);
                *(s32 *)(D_L39_00247914 + 0x284) = 0x23;
                return 1;
            case 7:
                *(s32 *)(D_L39_00247914 + 0x284) = 0x26;
                return 1;
            case 10:
                o = *(u8 **)(self + 0x138);
                v = (*(s32 (**)(void *))(*(u8 **)(o + 0x60) + 0x8C))(o);
                if (v == -1) {
                    return 1;
                }
                func_L39_006B5288(*(u8 **)(D_L39_00247914 + 0xD0), *(s32 *)(self + 0x498 + v * 4), 1);
                *(s32 *)(D_L39_00247914 + 0x284) = 0x1B;
                return 1;
            default:
                break;
            }
        }
    }
    s = *(s32 *)(self + 0x290);
    if (s == 0xA) {
        o = *(u8 **)(self + 0x138);
        (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(o + 0x60) + 0x9C))(o, &pt[0], &pt[1]);
        o = *(u8 **)(self + 0x110 + *(s32 *)(self + 0x290) * 4);
        r = (*(s32 (**)(void *))(*(u8 **)(o + 0x60) + 0x8C))(o);
        flags = 0 < r;
        if (r < *(s32 *)(self + 0x494) - 1) {
            flags |= 2;
        }
        func_L39_00689F00(self, flags, 3, 0.728f, pt[1] + 0.0035f, 0.327f, 0.032f, 0.041f, 1.0f, 3);
    } else {
        o = *(u8 **)(self + 0x110 + s * 4);
        (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(o + 0x60) + 0x30))(o, &pt[0], &pt[1]);
        first = -1;
        last = -1;
        for (i = 0; i < 8; i++) {
            v = *(s32 *)(*(u8 **)(self + 0x110 + i * 4) + 4);
            if (v == 3 || v == 4 || v == 5) {
                last = i;
                if (first == -1) {
                    first = i;
                }
            }
        }
        s = *(s32 *)(self + 0x290);
        flags = s != first;
        if (s != last) {
            flags |= 2;
        }
        func_L39_00689F00(self, flags, 3, pt[0], pt[1] + 0.0f, 0.332f, 0.034f, 0.041f, 1.0f, 3);
    }
    s = *(s32 *)(self + 0x290);
    switch (s) {
    case 0: v = 0x10DC; break;
    case 1: v = 0x11F0; break;
    case 2: v = 0x10DD; break;
    case 3: v = 0x10DE; break;
    case 4: v = 0x10DF; break;
    case 5: v = 0x10E0; break;
    case 6: v = 0x10E1; break;
    default: v = -1; break;
    }
    o = *(u8 **)(self + 0x13C);
    if (v < 0) {
        (*(Vfn2 *)(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
        return 0;
    }
    (*(void (**)(void *, void *))(*(u8 **)(o + 0x60) + 0xB8))(o, func_00381FF0(v));
    o = *(u8 **)(self + 0x13C);
    (*(Vfn2 *)(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
    return 0;
}
