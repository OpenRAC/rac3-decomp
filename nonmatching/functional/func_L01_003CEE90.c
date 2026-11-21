/* functional: medium. functional: medium. All branches, calls, constants verified as multisets against retail; loops rolled where retail unrolled */
typedef int u128_3CEE90 __attribute__((mode(TI)));
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038D590(void *, void *);
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C7DD8(void *);
extern s32 func_L01_00513EF0(void);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003CF5E0(void *);
extern void func_L01_003CF918(void *);
extern u8 D_001A4BE0[];
extern u8 D_L01_002C5600[];
extern u8 D_001425C9[];
extern u8 D_001D5479[];
extern s32 D_001D6694_sda;
extern f32 D_001DF258_sda;
extern s32 D_001DF260_sda;
__asm__(".extern D_001D6694_sda, 4");
__asm__(".extern D_001DF258_sda, 4");
__asm__(".extern D_001DF260_sda, 4");

void func_L01_003CEE90(u8 *self) {
    u8 mat[0x40];
    u8 *pp;
    u8 *G;
    u8 *vars;
    u8 *tmpl;
    u8 *hero;
    u8 *e;
    u8 *slot;
    u8 info[0x30];
    f32 buf2[4];
    f32 v80[4];
    f32 v70[4];
    f32 v90[4];
    f32 f20;
    f32 fr[4];
    s32 cont;
    s32 n;
    s32 i;
    s32 r;
    s32 idx;
    s32 r3;
    u16 h;

    cont = 1;
    vars = *(u8 **)(self + 0x68);
    G = D_001A4BE0;
    if (self[0x20] == 0) {
        self[0x30] = 0xFF;
        G[0x25E6] = 1;
        if (*(s32 *)(G + 0x1228) != 9) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(self, 1);
            if (*(u8 **)(G + 0x28D0) != self) {
                *(u16 *)(self + 0x96) = 0;
            } else {
                *(s32 *)(G + 0x28D0) = 0;
                goto destroy;
            }
        } else {
            hero = *(u8 **)(G + 0x1200);
            *(u16 *)(hero + 0x34) |= 0x80;
            self[0x20] = 1;
            *(u16 *)(self + 0x34) |= 0x100;
            tmpl = *(u8 **)(self + 0x24);
            *(f32 *)(self + 0x2C) = *(f32 *)(tmpl + 0x24) * 0.3f * D_001DF258_sda;
            *(s32 *)(vars + 0x610) = 0x4096006B;
            *(s32 *)(vars + 0x614) = 0x450030;
            *(f32 *)(vars + 0x608) = 2.0f;
            *(f32 *)(vars + 0x604) = 2.0f;
            *(u16 *)(self + 0x96) = 0;
        }
    }
    if (self[0x20] != 1) {
        return;
    }
    h = *(u16 *)(self + 0x96);
    if (h < 200) {
        *(u16 *)(self + 0x96) = h + 1;
    }
    if (*(s32 *)(G + 0x1228) != 9) {
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(self, 1);
        if (*(u8 **)(G + 0x28D0) != self) {
            r3 = *(s32 *)(vars + 0x620);
            goto have_r3;
        }
        *(s32 *)(G + 0x28D0) = 0;
        goto destroy;
    }
    if (G[0x25E4] == 1) {
        goto kill;
    }
    if (D_001D6694_sda == 2) {
        goto kill;
    }
    if (G[0x25ED] != 0 && *(s32 *)(G + 0x25C4) != 0x37) {
        goto kill;
    }
    r = func_L01_00513EF0();
    if (r == 2 || *(s32 *)(G + 0x25C4) == 1 || *(s32 *)(G + 0x25C4) == 0x1D) {
        if (G[0x121A] == 0) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            cont = 0;
            func_L01_004AA7E8(self, 1);
            r3 = *(s32 *)(vars + 0x620);
            goto have_r3;
        }
    }
    if (G[0x25E4] == 3) {
kill:
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(self, 1);
        return;
    }
    if (D_001D5479[0] == 0) {
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(self, 1);
        hero = *(u8 **)(G + 0x1200);
        *(u16 *)(hero + 0x34) &= 0xFF7F;
        if (*(u8 **)(G + 0x28D0) != self) {
            r3 = *(s32 *)(vars + 0x620);
            goto have_r3;
        }
        *(s32 *)(G + 0x28D0) = 0;
destroy:
        func_003C2880((s32)self);
        return;
    }
    hero = *(u8 **)(G + 0x1200);
    *(u16 *)(hero + 0x34) |= 0x80;
    pp = G + 0x1E00;
    for (i = 3; i >= 0; i--) {
        e = *(u8 **)pp;
        if (e != 0) {
            *(u16 *)(e + 0x34) |= 0x80;
        }
        pp += 4;
    }
    tmpl = *(u8 **)(self + 0x24);
    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFBE) | (*(u16 *)(tmpl + 0x44) & 0x1000);
    *(s32 *)(self + 0x98) = *(s32 *)(tmpl + 0x10);
    r3 = *(s32 *)(vars + 0x620);
have_r3:
    if (r3 < 6) {
        *(s32 *)(vars + 0x620) = r3 + 1;
    }
    if (*(s32 *)(G + 0x1228) == 9) {
        hero = *(u8 **)(G + 0x1200);
        *(u128_3CEE90 *)(self + 0x10) = *(u128_3CEE90 *)(hero + 0x10);
        hero = *(u8 **)(G + 0x1200);
        *(u128_3CEE90 *)(self + 0xC0) = *(u128_3CEE90 *)(hero + 0xC0);
        hero = *(u8 **)(G + 0x1200);
        *(u128_3CEE90 *)(self + 0xD0) = *(u128_3CEE90 *)(hero + 0xD0);
        hero = *(u8 **)(G + 0x1200);
        *(u128_3CEE90 *)(self + 0xE0) = *(u128_3CEE90 *)(hero + 0xE0);
        hero = *(u8 **)(G + 0x1200);
        *(u128_3CEE90 *)(self + 0xF0) = *(u128_3CEE90 *)(hero + 0xF0);
        func_L01_00448E10(self + 0xC0);
        func_003C7DD8(self);
    } else {
        func_003C2EC0(*(void **)(G + 0x25C0), 0, mat);
        *(u128_3CEE90 *)(self + 0x10) = *(u128_3CEE90 *)(mat + 0x30);
        func_0038D590(self + 0xC0, mat);
        func_L01_00448E10(self + 0xC0);
        func_003C7DD8(self);
    }
    n = *(s32 *)(G + 0x25C4);
    if ((u32)(n - 0x13) >= 2 && G[0x121A] == 0) {
        goto soft;
    }
    if (*(u16 *)(self + 0x96) < 9) {
        goto soft;
    }
    f20 = 0.120000005f;
    func_003C4138((f32 *)(vars + 0x604), 3.5f, f20);
    func_003C4138((f32 *)(vars + 0x608), 1.5f, f20);
    func_003C2F58(self, 2, (f32 *)mat);
    func_003C2F58(self, 3, v70);
    buf2[0] = *(f32 *)(mat + 0) - v70[0];
    buf2[1] = *(f32 *)(mat + 4) - v70[1];
    buf2[2] = *(f32 *)(mat + 8) - v70[2];
    buf2[3] = *(f32 *)(mat + 12);
    func_0038CF68(buf2, buf2, *(f32 *)(vars + 0x608));
    v70[0] = buf2[0] + *(f32 *)(mat + 0);
    v70[1] = buf2[1] + *(f32 *)(mat + 4);
    v70[2] = buf2[2] + *(f32 *)(mat + 8);
    idx = *(s32 *)(vars + 0x60C);
    n = D_001DF260_sda;
    slot = vars + (((idx + (n - 2)) % n) << 4);
    {
        f32 *a = (f32 *)(vars + (idx << 4));
        f32 *b = (f32 *)slot;
        *(f32 *)(mat + 0x30) = a[0] - b[0];
        *(f32 *)(mat + 0x34) = a[1] - b[1];
        *(f32 *)(mat + 0x38) = a[2] - b[2];
        *(f32 *)(mat + 0x3C) = a[3];
    }
    func_0038CF68((f32 *)(mat + 0x30), mat + 0x30, 2.5f);
    *(f32 *)(mat + 0x38) = 1.0f;
    *(f32 *)(mat + 0x3C) = 5627.9248f;
    {
        u8 *row = D_L01_002C5600 + D_001425C9[0] * 0xF0;
        f32 ff = *(f32 *)(row + 0x6C);
        if (*(s32 *)(G + 0x25C4) == 0x14) {
            ff = *(f32 *)(row + 0x70);
        }
        func_L01_00446760((L_3CC220 *)info, (M_3CC220 *)self, 0x10000, (f32 *)(mat + 0x30), ff);
    }
    info[0x18] = 0;
    info[0x19] = 1;
    *(u16 *)(info + 0x1A) = *(u16 *)(self + 0xAA);
    func_003D3CB0((int)mat, v70, 9, (M_3CC220 *)self, (L_3CC220 *)info);
    {
        f32 *s = (f32 *)slot;
        f32 *g = (f32 *)(G + 0x80);
        v90[0] = s[0] - g[0]; v90[1] = s[1] - g[1]; v90[2] = s[2] - g[2]; v90[3] = s[3];
        v70[0] = v70[0] - g[0]; v70[1] = v70[1] - g[1]; v70[2] = v70[2] - g[2];
        fr[0] = 0.2f; fr[1] = 0.4f; fr[2] = 0.6f; fr[3] = 0.8f;
        for (i = 0; i < 4; i++) {
            func_L01_0044C280(v80, v90, v70, 0, fr[i]);
            v80[0] += g[0]; v80[1] += g[1]; v80[2] += g[2];
            func_003D3CB0((int)mat, v80, 9, *(M_3CC220 **)(G + 0x25C0), (L_3CC220 *)info);
        }
    }
    func_003D3CB0((int)mat, slot, 9, *(M_3CC220 **)(G + 0x25C0), (L_3CC220 *)info);
    goto tail;
soft:
    f20 = 0.120000005f;
    func_003C4138((f32 *)(vars + 0x604), 1.75f, f20);
    func_003C4138((f32 *)(vars + 0x608), 2.0f, f20);
tail:
    if (*(s32 *)(G + 0x1228) == 9 && cont != 0) {
        func_L01_00404808(func_003CF5E0, self);
    }
    func_L01_003CF918(self);
}
