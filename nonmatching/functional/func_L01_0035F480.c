/* functional: medium. Written from the asm with no earlier draft; every branch, constant and call arg was traced, but the prototypes of a few callees are inferred from registers; byte layout differs (frame 0xE0 vs 0xD0). */
typedef struct { u8 p0; u8 kind; u8 pad2[0x6A]; f32 damage; u8 pad70[0x80]; } Row_0035F480;
typedef struct { u8 pad[0x5C]; u8 *id; } Runtime_0035F480;
typedef struct { S_38C110v vec; u8 *attacker; u8 pad14[4]; u8 b18; u8 b19; s16 source_class; s32 pad1C; s32 flag; u8 pad24[0x0C]; } Info_0035F480;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Row_0035F480 D_L01_002C5600[];
extern Runtime_0035F480 D_L01_00221098;
extern u8 D_L01_001E2880[];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_001EEA80[];
extern f32 D_L01_001DD704;
extern f32 D_L01_001DD708;
extern f32 D_L01_001DD70C;

void func_L01_0035F480(u8 *m)
{
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00404808(void (*)(u8 *), u8 *);
    extern void func_L01_00360A48(u8 *);
    extern void func_L01_00361690(u8 *);
    extern void func_L01_00360A00(u8 *);
    extern void func_L01_003609D0(u8 *);
    extern void func_L01_00360170(u8 *);
    extern void func_L01_0035FEC8(u8 *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_0039B478(void *, void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_00474390(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
    extern void func_L01_00470C78(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void *func_00382348(void *);
    extern void func_L01_00446760(Info_0035F480 *, u8 *, s32, void *, f32);
    extern void func_L01_00446978(u8 *, Info_0035F480 *);
    extern void func_L01_0031B090(u8 *, s32, s32);
    extern void func_003C2880(u8 *);
    u8 *v = *(u8 **)(m + 0x68);
    S_38C110v pos, vel, d;
    Info_0035F480 info;
    u32 colour, c1, c2, c3, c4;
    s32 i, n, kind, life;
    f32 ang, len;
    u8 *p;
    u8 **mp;
    u8 *mob;

    if (func_L01_004CB2D8()) func_L01_004CAB30(m + 0x10, m + 0x10);
    switch (m[0x20]) {
    case 0:
        func_0038CAD0(v + 0x14);
        *(f32 *)(v + 0x18) -= 0.12999999523162842f;
        if (*(s32 *)(v + 0x14) < 0x4C) {
            func_L01_00404808(func_L01_00361690, m);
            m[0x20] = 1;
        } else {
            *(f32 *)(v + 0x34) += 0.1f;
            func_L01_00404808(func_L01_00360A48, m);
        }
        break;
    case 1:
        func_0038CAD0(v + 0x14);
        if (*(s32 *)(v + 0x14) >= 0x49) {
            func_L01_00404808(func_L01_00361690, m);
            colour = 0x606060;
            func_L01_00404808(func_L01_00360A00, m);
            if (D_L01_002C5600[D_001425C0[0x77]].kind >= 2) colour = 0x406080;
            for (i = 0x31; i >= 0; i--) {
                ang = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(D_L01_001E2880 + 0x140),
                                    *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(D_L01_001E2880 + 0x144));
                func_L01_00443A18(1.0f, 2.0f);
                pos.x = *(f32 *)v + func_L01_00443A18(0.0f, 0.15000000596046448f);
                pos.y = *(f32 *)(v + 4) + func_L01_00443A18(0.0f, 0.15000000596046448f);
                pos.z = *(f32 *)(v + 8) + 0.1f;
                ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, -6.2831854820251465f));
                vel.x = func_0038D098(ang) * 0.20000001788139343f;
                vel.y = func_0038D0B0(ang) * 0.20000001788139343f;
                vel.z = 0.0f;
                life = func_00382498(20, 40);
                p = func_L01_004713C8(&pos, &vel, (life * 5 + 2) / 6, colour, func_00382498(-2, -4), 0x40, 0, 0,
                                      126000.0078125f, 231000.0f, 0.0f);
                if (p) p[2] = D_L01_00221098.id[0];
            }
        } else {
            d.x = *(f32 *)D_L01_001E2A40 - *(f32 *)(m + 0x10);
            d.y = *(f32 *)(D_L01_001E2A40 + 4) - *(f32 *)(m + 0x14);
            d.z = *(f32 *)(D_L01_001E2A40 + 8) - *(f32 *)(m + 0x18);
            d.w = *(f32 *)(D_L01_001E2A40 + 0xC);
            len = func_0038CEA8(&d);
            if (len < 20.0f) *(f32 *)(D_L01_001E2A40 + 0x20) = 0.4000000059604645f - len * 0.019999999552965164f;
            else *(s32 *)(D_L01_001E2A40 + 0x20) = 0;
            *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
            *(s32 *)(D_L01_001E2A40 + 0x28) = 0x15;
            kind = D_L01_002C5600[D_001425C0[0x77]].kind;
            if (kind != 0) func_L01_0039B478(m + 0x10, m, 0);
            c1 = 0xBF804020; c2 = 0xBF604020; c3 = 0x80FF8040; c4 = 0xFF8040;
            if (kind >= 2) {
                c1 = 0xBF204080; c2 = 0xBF2040A0; c3 = 0x804080FF; c4 = 0x4080FF;
            }
            if (D_L01_002C5600[D_001425C0[0x77]].kind != 0) {
                for (i = 0x31; i >= 0; i--) {
                    func_00382580(&vel, 0.40000003576278687f, 0.5000000596046448f);
                    life = func_00382498(20, 35);
                    func_L01_00474390(m + 0x10, &vel, (life * 5 + 2) / 6, c3, c4, 0x14, 0,
                                      0.1599999964237213f, 1.0f, 2.0f, 0.1f);
                }
            }
            func_L01_0046B458(m + 0x10, 0x14, c1, 2, 2, D_L01_001D66B0, 1, 17.5f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, c2, 2, -2, D_L01_001D66B0, 1, 12.5f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, 0xC0FFFFFF, 2, 2, D_L01_001D66B0, 1, 8.75f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, 0xB0FFFFFF, 2, -2, D_L01_001D66B0, 1, 6.25f, 0.1f, 0.0f);
            func_L01_00470C78(m + 0x10, 0x14, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1, 2.6999998092651367f, 2.0999999046325684f);
            func_L01_00470C78(m + 0x10, 0x14, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1, 5.100000381469727f, 2.0999999046325684f);
            func_L01_00470C78(m + 0x10, 0x14, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1, 6.0f, 4.5f);
            m[0x20] = 2;
        }
        break;
    case 2:
        {
            f32 a = *(f32 *)(v + 0x18) + 0.4000000059604645f;
            f32 b = D_L01_001DD708 + 0.5f;
            f32 c = D_L01_001DD70C + 0.699999988079071f;
            *(f32 *)(v + 0x18) = a;
            D_L01_001DD708 = b;
            D_L01_001DD70C = c;
            if (1.600000023841858f < a) *(f32 *)(v + 0x18) = 1.600000023841858f;
        }
        if (func_0038CAD0(v + 0x1C)) {
            m[0x20] = 3;
            break;
        }
        *(s128 *)&pos = *(s128 *)(m + 0x10);
        pos.w = 2.0f;
        if (func_0038DC20(&pos, 100.0f) != -1) {
            D_L01_001DD704 += 0.800000011920929f;
            *(s32 *)(v + 0x20) -= 4;
            if (*(s32 *)(v + 0x20) < 0) *(s32 *)(v + 0x20) = 0;
            func_L01_00404808(func_L01_003609D0, m);
            func_L01_00404808(func_L01_00361690, m);
            func_L01_00404808(func_L01_00360170, m);
        }
        func_L01_0035FEC8(m);
        {
            f32 mult, t;
            if (D_L01_002C5600[D_001425C0[0x77]].kind >= 3) mult = 5.0f;
            else mult = 4.0f;
            t = (f32)*(s32 *)(v + 0x1C) / 17.0f;
            n = func_003D4D00(m + 0x10, 0, m, 0, (1.0f - t) * mult + 2.0f);
        }
        mp = D_L01_001EEA80;
        for (; n > 0; n--, mp++) {
            if (func_00382348(*mp) == 0) {
                if (!(*(u16 *)(*mp + 0x34) & 0x4000)) continue;
            }
            mob = *mp;
            if (mob == *(u8 **)(D_001A4BE0 + 0x25C0)) {
                if (*(s16 *)(mob + 0xAA) != 0x1865) continue;
            }
            if (*(s16 *)(mob + 0xAA) == 0x185A) continue;
            d.x = *(f32 *)(mob + 0x10) - *(f32 *)(m + 0x10);
            d.y = *(f32 *)(mob + 0x14) - *(f32 *)(m + 0x14);
            d.z = *(f32 *)(mob + 0x18) - *(f32 *)(m + 0x18);
            d.w = *(f32 *)(mob + 0x1C);
            func_0038CF68(&d, &d, 1.5f);
            func_0038CF68(&info, &info, 1.0f); /* retail scales this still-unset local by 1.0 before filling it */
            func_L01_00446760(&info, m, 0x1030000, &d,
                              *(s32 *)(v + 0x38) ? 2000.0f : D_L01_002C5600[D_001425C0[0x77]].damage);
            info.vec = d;
            info.flag = 1;
            info.vec.w = 5627.9248046875f;
            info.b18 = 5;
            info.b19 = 3;
            info.attacker = m;
            info.source_class = *(s16 *)(*mp + 0xAA);
            if (*(s32 *)(v + 0x38) != 0) info.attacker = 0;
            func_L01_00446978(*mp, &info);
            func_L01_0031B090(*mp, 0x77, *(s32 *)(v + 0x28));
        }
        break;
    case 3:
        func_003C2880(m);
        break;
    }
}
