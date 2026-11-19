/* functional: medium. Compiles at level 01 with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack); about 300 diff rows are only s1/s2 register naming plus a 2-instruction tail difference, control flow read block by block against the asm. Needs its own file split at 0x3A33C0 with the same flags as func_L01_003A0778 (the lq/sq copy relies on the 128-bit type). Note long long is 128-bit here, so 64-bit uses unsigned long. */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x500]; s8 c[0x500]; s16 h[0x280]; u16 uh[0x280]; s32 i[0x140]; u32 u[0x140]; f32 f[0x140]; u8 *ptr[0x140]; u128_t q[0x50]; } Obj;
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
extern Hero D_001A4BE0;
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_L01_001D66B0;
extern s32 D_L01_001DFB40;
extern u8 *D_L01_001E0100;
extern u8 D_L01_001E2A40[];
extern s32 func_L01_003A39A0(Obj *);
extern void func_L01_003A3F68(Obj *);
extern void func_L01_003A4320(Obj *);
extern void func_0043C710(void *);
extern void func_00439300(void *);
extern void func_004AABF0(s32, s32, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(Obj *);
extern s32 func_L01_00452FB0(Obj *, void *, s32, s32, s32);
extern void func_L01_00452860(Obj *, void *, s32);
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L01_00456BD0(Obj *, s32);
extern void func_L01_00456C98(Obj *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);

s32 func_L01_003A33C0(Obj *m) {
    Obj *pv;
    s32 i;
    s32 t;
    s32 r;
    s32 a5;
    s32 b;
    u8 *o;
    Obj *p;

    pv = (Obj *)m->ptr[0x68 / 4];
    if (m->b[0x20] == 0 && func_L01_003A39A0(m) != 0) {
        return 1;
    }
    t = pv->i[0x3B0 / 4];
    if (t != -1) {
        o = D_L01_001E0100 + (t << 7);
        if (m->f[0x18 / 4] < *(f32 *)(o + 0x38)) {
            f32 d = m->f[0x18 / 4] - *(f32 *)(o + 0x38);
            if (4.0f < __builtin_fabsf(d)) {
                pv->i[0x3B0 / 4] = -1;
            }
        }
    }
    if (0.0f < pv->f[0x30 / 4]) {
        for (i = 0; i < 8; i++) {
            p = (Obj *)pv->ptr[0x3F0 / 4 + i];
            if (p != 0) {
                p->i[0x98 / 4] = *(s32 *)(p->ptr[0x24 / 4] + 0x10);
                func_0043C710(pv->ptr[0x3F0 / 4 + i]);
            }
        }
    }
    if (pv->i[0x3C0 / 4] != 0 || pv->i[0x42C / 4] != 0) {
        if (D_001D545C == 1) {
            m->h[0x7C / 2] = 0;
        }
    }
    if (pv->ptr[0x3B8 / 4] != 0) {
        b = pv->ptr[0x3B8 / 4][0x20];
        if (b == 0xFE || b == 0xFD) {
            pv->i[0x3B8 / 4] = 0;
        }
    }
    if (m->b[0x31] != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, &m->b[0x10]) < 4096.0f) {
            func_L01_004472C0(m);
            m->b[0x6F] = 0x3C;
        }
    }
    if (pv->b[0x3E] == 2) {
        func_L01_003A3F68(m);
        return 1;
    }
    r = func_L01_00452FB0(m, &pv->b[0x160], 0, 0, 0);
    if (r != 0) {
        if (r >= 2) {
            if (pv->ptr[0x2F0 / 4] != 0) {
                if (*(s16 *)(pv->ptr[0x2F0 / 4] + 0xAA) == 0x1939) {
                    func_L01_00367260(pv->ptr[0x2F0 / 4], 0, 0, &D_L01_001D66B0, &D_L01_001D66B0, 0x2F2020FF);
                    func_00439300(pv->ptr[0x2F0 / 4]);
                    pv->i[0x2F0 / 4] = 0;
                }
            }
            if (pv->ptr[0x2F4 / 4] != 0) {
                if (*(s16 *)(pv->ptr[0x2F4 / 4] + 0xAA) == 0x1939) {
                    func_L01_00367260(pv->ptr[0x2F4 / 4], 0, 0, &D_L01_001D66B0, &D_L01_001D66B0, 0x2F2020FF);
                    func_00439300(pv->ptr[0x2F4 / 4]);
                    pv->i[0x2F4 / 4] = 0;
                }
            }
        }
        func_004AABF0(6, 0, m);
        for (i = 0; i < 8; i++) {
            p = (Obj *)pv->ptr[0x3F0 / 4 + i];
            if (p != 0) {
                p->i[0x98 / 4] = 0;
                func_0043C710(pv->ptr[0x3F0 / 4 + i]);
            }
        }
        if (m->b[0x21] != 0xFF) {
            func_L01_00445BE0(m->b[0x21], 0);
        }
        func_L01_003A4320(m);
    }
    if (pv->b[0x5E] != 0) {
        func_L01_003A3F68(m);
        return 1;
    }
    func_L01_00452860(m, &pv->b[0x30], 0);
    if (((*(unsigned long *)&m->b[0x30] & 0x104100000000L) != 0x4100000000L || m->i[0x98 / 4] != 0)
        && 0.0f < pv->f[0x30 / 4]) {
        if (pv->b[0x5F] != 0) {
            func_L01_00456BD0(m, 5);
        } else if (D_001D545C != 9 || m->h[0xB2 / 2] == 0xC8 || m->b[0x95] == 2 || m->b[0x95] == 4) {
            func_L01_00456BD0(m, 3);
        }
    }
    a5 = D_L01_001DFB40;
    if ((m->h[0xB2 / 2] + 8) % 8 == a5 % 8) {
        if (pv->b[0x5F] != 0) {
            if (m->b[0x95] == 0) {
                func_L01_00456C98(m, pv->i[0x2D0 / 4], 0, 0, 0, 0, 3, 0, 0, 0, pv->f[0x2D4 / 4], 10.0f, 1.0f);
            } else {
                func_L01_00456C98(m, pv->i[0x2D8 / 4], 0, 0, 0, 0, 3, 0, 0, 0, pv->f[0x2DC / 4], 10.0f, 1.0f);
            }
        } else if (m->b[0x95] == 0) {
            func_L01_00456C98(m, pv->i[0x2D0 / 4], 0, 0, 0, 0, 1, pv->i[0x424 / 4] != 0, 0, 0, pv->f[0x2D4 / 4], 10.0f, 1.0f);
            if (pv->h[0x234 / 2] == 1) {
                func_L01_00456C98(m, pv->i[0x2D0 / 4], 0, 0, 0, 0, 1, pv->i[0x424 / 4] != 0, 0, 0, pv->f[0x2D4 / 4], 10.0f, 1.0f);
            }
        } else {
            func_L01_00456C98(m, pv->i[0x2D8 / 4], 0, 0, 0, 0, 1, pv->i[0x424 / 4] != 0, 0, 0, pv->f[0x2DC / 4], 10.0f, 1.0f);
        }
    }
    if (pv->i[0x410 / 4] == -1) {
        return 0;
    }
    if (pv->i[0x414 / 4] == -1) {
        return 0;
    }
    if (pv->h[0x234 / 2] == 1 && D_001D545C != 0x1D) {
        return 0;
    }
    b = m->b[0x95];
    if (b != 0 && b != 3 && b != 1) {
        if (D_001D545C != 0x1D || b != 2) {
            return 0;
        }
    }
    if (func_L01_00456500(D_001A4C60, pv->i[0x410 / 4]) != 0) {
        pv->i[0x418 / 4] = 1;
        pv->i[0x230 / 4] = D_001A4BE0.i[0x25C0 / 4];
        *(u128_t *)&pv->b[0x220] = *(u128_t *)&D_001A4BE0.b[0xD0];
    } else {
        pv->i[0x418 / 4] = 0;
    }
    return 0;
}
