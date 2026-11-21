/* functional: high. Re-derived from PAL assembly using the NTSC-U twin as a guide; VU0 xyz ops written as plain C (w kept from first operand), no byte match tried beyond a compile check (224 differing lines). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00541F78;
typedef struct { u8 p0[0x14]; s32 x14; u8 x18; u8 x19; u16 x1A; u8 p1C[0xC]; s32 x28; u8 p2C[0x14]; } S_00541F78;
typedef struct { V_00541F78 v; s32 x10; f32 x14; u8 p18[0xC]; s32 x24; s32 x28; s32 x2C; s32 x30; u8 p34[4]; f32 x38; f32 x3C; } M_00541F78;
typedef struct { u8 p0[0x10]; V_00541F78 pos; u8 b20; u8 p21[0x89]; u16 xAA; u8 pAC[0x14]; u8 xC0[0x10]; u8 xD0[0x10]; u8 xE0[0x10]; } O_00541F78;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1C[4]; u8 x20[0x10]; } G_00541F78;
extern u8 *D_L39_0024CE1C;
extern G_00541F78 D_L39_0025F740;
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L39_005FFE78(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L04_00354AE8(void *, s32, s32, s32, s32, s32, f32);
extern void func_L04_00355678(void);

void func_L39_00541F78(O_00541F78 *o) {
    M_00541F78 *m = *(M_00541F78 **)((u8 *)o + 0x68);
    u8 *tgt = (u8 *)o;
    V_00541F78 v0, v40;
    S_00541F78 s, s2;
    s32 hit, a;

    if (m->x30 != -1) {
        tgt = (u8 *)m->x10;
    }
    m->x24 = m->x24 + 1;
    if (m->x24 >= 0x3A) {
        func_003C2880(o);
        return;
    }
    switch (o->b20) {
    case 0:
        m->x38 = m->x38 + m->x3C;
        {
            f32 w = o->pos.w;
            v0.x = o->pos.x + m->v.x; v0.y = o->pos.y + m->v.y; v0.z = o->pos.z + m->v.z; v0.w = w;
        }
        func_L01_00446760(&s, o, m->x2C, m, m->x14);
        s.x1A = o->xAA;
        s.x18 = 0;
        s.x28 = m->x30;
        s.x19 = 1;
        a = -1;
        if (D_L39_0024CE1C != 0) {
            a = *(s32 *)(D_L39_0024CE1C + 0x2548);
        }
        func_L39_005FFDF8(a);
        hit = func_003D3CB0(&o->pos, &v0, 0, tgt, &s);
        func_L39_005FFE78();
        if (hit != 0) {
            if (D_L39_0025F740.x18 != 0) {
                if (D_L39_0025F740.x18 != m->x10) {
                    v40 = m->v;
                    func_0038CE20(&v40, &v40, 2.0f);
                    v40.w = 5627.9248f;
                    func_L01_00446760(&s2, o, m->x2C, &v40, m->x14);
                    s2.x1A = o->xAA;
                    s2.x14 = 0x10001;
                    s2.x19 = 1;
                    s2.x18 = 0;
                    a = -1;
                    if (D_L39_0024CE1C != 0) {
                        a = *(s32 *)(D_L39_0024CE1C + 0x2548);
                    }
                    s2.x28 = m->x30;
                    func_L39_005FFDF8(a);
                    func_003D4D00(D_L39_0025F740.x20, 0, o, &s2, 1.0f);
                    func_L39_005FFE78();
                    func_L01_004450F0(o, 1, -1);
                    return;
                }
            } else {
                v40 = m->v;
                func_0038CE20(&v40, &v40, 3.0f);
                v40.w = 5627.9248f;
                func_L01_00446760(&s2, o, m->x2C, &v40, m->x14);
                s2.x19 = 1;
                s2.x1A = o->xAA;
                s2.x18 = 0;
                a = -1;
                if (D_L39_0024CE1C != 0) {
                    a = *(s32 *)(D_L39_0024CE1C + 0x2548);
                }
                s2.x28 = m->x30;
                func_L39_005FFDF8(a);
                func_003D4D00(D_L39_0025F740.x20, 0, tgt, &s2, 2.0f);
                func_L39_005FFE78();
                func_L01_004450F0(o, 1, -1);
                return;
            }
        }
        o->pos = v0;
        func_0038CE20(&v40, m, -0.5f);
        *(u32 *)&s2 = 0; *((u32 *)&s2 + 1) = 0; *((u32 *)&s2 + 2) = 0; *((u32 *)&s2 + 3) = 0;
        break;
    case 1:
        func_L04_00354AE8((u8 *)o + 0x10, 0x803B0612, 0x80DA5615, 0x64FFFFFF, 0x507030FF, 0x320000FF, 5.85f);
        func_003C2880(o);
        return;
    default:
        break;
    }
    func_0038D890(o->xE0, o->xE0, o->xD0, 0.0f);
    func_0038D890(o->xC0, o->xC0, o->xD0, 0.0f);
    func_L01_00404A10(func_L04_00355678, o);
}
