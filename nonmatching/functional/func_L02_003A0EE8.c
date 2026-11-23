/* functional: medium. Written from PAL asm; compiles at level 02 (1257 diff, layout only). 5 states (jtbl_002BCC80): 1 wait, 2 flying, 3 bouncing, 4 landing, 5 free. Duplicated tails in retail are static helpers (sweep, spray, release). vadd.xyz position updates written as plain float adds (file has no VU0 flag), same xyz. Unsure: field names (raw offsets), D_L02_001E8080/001E8060/001A4C60 types. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A0EE8;
extern void func_L02_003A2320(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, f32, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_004471A8(void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern u8 *func_L01_00468A68(void *, void *, s32, s32);
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_L02_001E8080[];
extern u8 D_L02_001E8060[];
extern u8 D_L02_001E1300[];
extern u8 *D_L02_001EC0C0[];
extern f32 D_L02_002EF1F0[];
extern u8 *D_L02_0021E134[];
extern u8 D_L02_0021E0D8[];
extern u8 *D_L02_001E8058 __attribute__((section(".data")));
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");

/* pos/bounds test shared by states 2, 3: out of the 2..1021 box on any axis means state 5 */
static s32 outside_003A0EE8(u8 *self) {
    f32 x = *(f32 *)(self + 0x10), y = *(f32 *)(self + 0x14), z = *(f32 *)(self + 0x18);
    return x < 2.0f || 1021.0f < x || y < 2.0f || 1021.0f < y || z < 2.0f || 1021.0f < z;
}

/* the live moby sweep shared by states 2 and 3 (n = how many are listed in D_L02_001EC0C0) */
static void sweep_003A0EE8(u8 *self, u8 *st, u8 *fp) {
    s32 flag = 0, n, cnt;
    u8 **ptr;
    u8 buf[0x30] __attribute__((aligned(16)));
    V4_003A0EE8 v40;
    u8 *h = D_001A4BE0;
    f32 f;

    func_L01_004471A8(self, *(s16 *)(st + 6) == 0 ? 0.7f : 1.1f);
    n = func_003D4D00(fp, *(s16 *)(st + 6) == 0 ? 0.8f : 1.1f, 0, self, 0);
    if (n > 0) {
        ptr = D_L02_001EC0C0;
        cnt = n;
        do {
            s16 t = *(s16 *)(*ptr + 0xAA);
            if (t != 0x18C2) {
                if (t != 0) {
                    v40 = *(V4_003A0EE8 *)(st + 0x10);
                    func_0038CE20(&v40, &v40, 3.0f);
                    v40.w = 5627.9248f;
                    *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
                    f = func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f;
                    func_L01_00446760(buf, self, 0x10000, &v40, f);
                    flag = 1;
                } else if (*(s16 *)(h + 0x36E) != 0 && 0.5f < *(f32 *)(h + 0x33C)) {
                    v40 = *(V4_003A0EE8 *)(st + 0x10);
                    func_0038CE20(&v40, &v40, 3.0f);
                    v40.w = 5627.9248f;
                    *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
                    f = func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f;
                    func_L01_00446760(buf, self, 1, &v40, f);
                } else if (*(s32 *)(h + 0x25C4) != 0x91 && *(s32 *)(h + 0x2850) != 0) {
                    if (*(s16 *)(h + 0x1DC) != 0) {
                        *(s16 *)(h + 0x1DC) = 0;
                        *(s32 *)(self + 0x98) = 0;
                        func_L01_00446748(buf, self, 8, 0.0f);
                        flag = 1;
                    } else {
                        *(s32 *)(self + 0x98) = 0;
                        f = func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f;
                        func_L01_00446748(buf, self, 8, f);
                        flag = 1;
                    }
                }
                buf[0x19] = 1;
                *(u16 *)(buf + 0x1A) = *(u16 *)(self + 0xAA);
                buf[0x18] = 0;
                func_L01_00446978(*ptr, buf);
            }
            cnt--;
            ptr++;
        } while (cnt != 0);
    }
    if (flag != 0) {
        if (D_L02_001E8058 != *(u8 **)(h + 0x25C0) || *(s16 *)(h + 0x1DC) == 0) func_003A52A0(2, 0, self);
    }
}

/* clear the effect slot in st+0xC */
static void release_003A0EE8(u8 *self, u8 *st) {
    s32 idx = *(s32 *)(st + 0xC);
    if (idx != -1 && *(u8 **)(D_001A30B0 + (idx << 7) + 0xDC) == self && D_001A30B0[(idx << 7) + 0xD0] != 0) {
        func_003A4F28(idx);
    }
    *(s32 *)(st + 0xC) = -1;
}

static void spray_003A0EE8(V4_003A0EE8 *v10, s32 t1) {
    V4_003A0EE8 v20, v30;
    f32 sp;
    s32 m, k;
    u8 *r;
    v30 = (V4_003A0EE8){0.0f, 0.0f, 0.0f, 0.0f};
    v30.z = func_003824E0(0.05f, 0.5f) * 0.02f;
    v20 = v30;
    sp = func_003824E0(0.7f, 1.0f) * 210000.0f;
    m = func_00382498(0x23, 0x3C);
    k = func_00382468(2);
    r = func_L01_0046FB40(v10, &v20, (m * 5 + 2) / 6, 0x128090A0, k == 0 ? -1 : 1, t1, 0, 0, sp, sp, 0.0f);
    if (r != 0) {
        r[3] = 0x44;
        r[2] = *D_L02_0021E134[0];
    }
}

void func_L02_003A0EE8(u8 *self) {
    u8 *st;
    u8 *fp;
    V4_003A0EE8 v0, v10, v20, v30;
    s32 i, n, k, m;
    f32 d, a, b, sp, z, h;
    u8 *r;

    func_L02_003A2320(self);
    st = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        if (*(s32 *)st == -1) return;
        if (func_L01_00456500(D_001A4C60, *(s32 *)st) != 0) self[0x20] = 2;
        return;
    case 2:
        v0 = *(V4_003A0EE8 *)(self + 0x10);
        *(f32 *)(st + 0x18) -= *(f32 *)(st + 8);
        *(f32 *)(self + 0x10) += *(f32 *)(st + 0x10);
        *(f32 *)(self + 0x14) += *(f32 *)(st + 0x14);
        *(f32 *)(self + 0x18) += *(f32 *)(st + 0x18);
        *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), *(f32 *)(st + 0x28));
        if (*(s16 *)(st + 6) == 1) *(f32 *)(self + 0xF8) = 2.3561945f;
        if (outside_003A0EE8(self)) self[0x20] = 5;
        fp = self + 0x10;
        if (func_0038CB00(st + 0x2C) != 0) {
            s32 hit = func_003D3CB0(&v0, fp, 2, self, 0);
            if (hit == 0) hit = func_L01_003FB640(fp, 2, self, *(f32 *)(st + 0x24));
            if (hit != 0) {
                if (st[4] != 0) {
                    func_L01_0040E790(st + 0x10, st + 0x10, D_L02_001E8080);
                    *(f32 *)(st + 0x28) = func_0038CEA8(st + 0x10);
                } else {
                    func_L01_0040E790(st + 0x10, st + 0x10, D_L02_001E8080);
                    *(f32 *)(st + 0x18) = *(f32 *)(st + 0x18) * 0.7f;
                    *(s32 *)(st + 0x10) = 0;
                    *(f32 *)(st + 0x14) = *(f32 *)(st + 0x14) * 1.15f;
                    d = func_0038CEA8(st + 0x10) * 0.6f;
                    if (*(f32 *)(st + 0x14) < -0.120000005f) *(f32 *)(st + 0x14) = -0.18f;
                    *(f32 *)(st + 0x28) = d;
                    if (1.32f < *(f32 *)(st + 0x28)) *(f32 *)(st + 0x28) = 1.32f;
                }
                v10 = *(V4_003A0EE8 *)D_L02_001E8060;
                v10.z += 0.15f;
                n = *(s16 *)(st + 0x2E) * 6;
                for (i = n; i > 0; i--) {
                    sp = func_003824E0(0.3f, 0.6f) * 210000.0f;
                    v20.x = func_L01_00443A18(0.0f, 0.02f);
                    v20.y = func_L01_00443A18(0.0f, 0.02f);
                    v20.z = func_003824E0(0.25f, 0.8f) * 0.02f;
                    v30 = v10;
                    v30.x += func_L01_00443A18(0.0f, 0.6f);
                    v30.y += func_L01_00443A18(0.0f, 0.6f);
                    v30.z += func_L01_00443A18(0.0f, 0.2f);
                    m = func_00382498(0x23, 0x3C);
                    m = (m * 5 + 2) / 6;
                    k = func_00382468(2);
                    r = func_L01_0046FB40(&v30, &v20, m, 0x128090A0, k == 0 ? -1 : 1, 0x32, 0, 0, sp, sp, 0.0f);
                    if (r != 0) {
                        r[3] = 0x44;
                        r[2] = *D_L02_0021E134[0];
                    }
                    if (st[4] != 0) {
                        self[0x20] = 3;
                        *(f32 *)(st + 0x18) = 0.0f;
                        *(f32 *)(self + 0x18) = *(f32 *)(D_L02_001E8060 + 8) + 0.98f;
                        *(f32 *)(st + 8) = 0.008f;
                    }
                }
                func_003A52A0(0, 0, self);
                d = func_0038CF00(fp, D_001A4C60);
                {
                    f32 prod = (f32)*(s16 *)(st + 0x2E) * d;
                    f32 val = prod == 0.0f ? 1.0f : 0.5f / d;
                    *(f32 *)(D_L02_001E1300 + 0x20) = val;
                    *(s32 *)(D_L02_001E1300 + 0x28) = 0x15;
                    *(s32 *)(D_L02_001E1300 + 0x2C) = 0;
                }
                *(u16 *)(st + 0x2E) = *(u16 *)(st + 0x2E) - 1;
                if (*(s16 *)(st + 0x2E) == 0) self[0x20] = 3;
            }
        }
        sweep_003A0EE8(self, st, fp);
        if (*(s16 *)(st + 6) == 0 && *(f32 *)(self + 0x14) < 248.0f) goto to4;
        if (22.0f < *(f32 *)(self + 0x18)) return;
    to4:
        self[0x20] = 4;
        release_003A0EE8(self, st);
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
        return;
    case 3:
        v0 = *(V4_003A0EE8 *)(self + 0x10);
        *(f32 *)(st + 0x18) -= *(f32 *)(st + 8);
        *(f32 *)(self + 0x10) += *(f32 *)(st + 0x10);
        *(f32 *)(self + 0x14) += *(f32 *)(st + 0x14);
        *(f32 *)(self + 0x18) += *(f32 *)(st + 0x18);
        *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), *(f32 *)(st + 0x28));
        if (*(s16 *)(st + 6) == 1) *(f32 *)(self + 0xF8) = 2.3561945f;
        if (outside_003A0EE8(self)) self[0x20] = 5;
        if (func_L01_004AA710(self, *(s32 *)(st + 0xC)) == 0) {
            *(s32 *)(st + 0xC) = func_003A52A0(1, 4, self);
        }
        fp = self + 0x10;
        if (func_0038CB00(st + 0x2C) != 0) {
            s32 hit = func_003D3CB0(&v0, fp, 2, self, 0);
            if (hit == 0) hit = func_L01_003FB640(fp, 2, self, *(f32 *)(st + 0x24));
            if (hit != 0) {
                if (st[4] != 0) {
                    u8 *g = D_L02_001E8058;
                    if (g != 0 && *(s16 *)(g + 0xAA) == 0x18C2) {
                        *(f32 *)(self + 0x18) += 0.2f;
                    } else {
                        func_L01_0040E790(st + 0x10, st + 0x10, D_L02_001E8080);
                        *(f32 *)(st + 0x28) = func_0038CEA8(st + 0x10);
                        if (0.0f < *(f32 *)(st + 0x18)) *(f32 *)(st + 0x18) = 0.0f;
                    }
                } else {
                    func_L01_0040E790(st + 0x10, st + 0x10, D_L02_001E8080);
                    *(f32 *)(st + 0x18) = *(f32 *)(st + 0x18) * 0.15999997f;
                    *(s32 *)(st + 0x10) = 0;
                    *(f32 *)(st + 0x14) = *(f32 *)(st + 0x14) * 1.18f;
                    d = func_0038CEA8(st + 0x10) * 0.52f;
                    if (*(f32 *)(st + 0x14) < -0.120000005f) *(f32 *)(st + 0x14) = -0.18f;
                    *(f32 *)(st + 0x28) = d;
                    if (1.32f < *(f32 *)(st + 0x28)) *(f32 *)(st + 0x28) = 1.32f;
                }
                v10 = *(V4_003A0EE8 *)D_L02_001E8060;
                func_003C4C18(&v10, 0.2f);
                spray_003A0EE8(&v10, 0x32);
                if (st[4] != 0) *(f32 *)(self + 0x18) = *(f32 *)(D_L02_001E8060 + 8) + 0.98f;
            }
        }
        sweep_003A0EE8(self, st, fp);
        if (*(s16 *)(st + 6) == 0 && *(f32 *)(self + 0x14) < 248.0f) goto to4;
        h = func_003C3D30(fp, 0, 0, 0.5f);
        z = *(f32 *)(self + 0x18);
        if (z + 20.0f < h) goto to4;
        if (22.0f < z) return;
        goto to4;
    case 4:
        v0 = *(V4_003A0EE8 *)(self + 0x10);
        fp = self + 0x10;
        *(f32 *)(st + 0x18) -= *(f32 *)(st + 8);
        *(f32 *)(self + 0x10) += *(f32 *)(st + 0x10);
        *(f32 *)(self + 0x14) += *(f32 *)(st + 0x14);
        *(f32 *)(self + 0x18) += *(f32 *)(st + 0x18);
        *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), *(f32 *)(st + 0x28));
        if (*(s16 *)(st + 6) == 1) *(f32 *)(self + 0xF8) = 2.3561945f;
        k = *(f32 *)(self + 0x18) <= 22.0f ? 0xB20 : 0;
        if (func_0038CB00(st + 0x2C) != 0) {
            s32 hit = func_003D3CB0(&v0, fp, k, self, 0);
            if (hit == 0) hit = func_L01_003FB640(fp, k, self, *(f32 *)(st + 0x24));
            if (hit != 0) {
                func_L01_0040E790(st + 0x10, st + 0x10, D_L02_001E8080);
                *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * 0.88f;
                *(f32 *)(st + 0x14) = *(f32 *)(st + 0x14) * 0.88f;
                v10 = *(V4_003A0EE8 *)D_L02_001E8060;
                func_003C4C18(&v10, 0.2f);
                spray_003A0EE8(&v10, 0x10);
                func_003A52A0(0, 0, self);
            }
        }
        if (st[5] == 0 && *(f32 *)(self + 0x18) < 21.0f) {
            u8 *e = func_L01_003016B0(fp, 9, *(s16 *)(st + 6) == 1 ? 2.5f : 2.0f, 1.1f);
            if (e != 0) func_L01_0043B9E8(e, 0x7F, 0x30, 0x1F);
            for (i = 20; i != 0; i--) {
                a = func_00382538();
                b = func_003824E0(0.0f, 0.06f);
                v10.x = func_0038D098(a) * b;
                v10.y = func_0038D0B0(a) * b;
                v10.z = func_003824E0(0.06f, 0.16f);
                k = func_00382468(2);
                m = func_00382498(0x5A, 0x78);
                r = func_L01_00468A68(fp, &v10, k, m);
                if (r != 0) r[2] = **(u8 **)(D_L02_0021E0D8 + 0x16C);
            }
            st[5] = 1;
        }
        if (func_0038CAD0(st + 0x20) != 0) { self[0x20] = 5; return; }
        z = *(f32 *)(self + 0x18);
        if (z < 17.0f || *(f32 *)(self + 0x10) < 2.0f || 1021.0f < *(f32 *)(self + 0x10) ||
            *(f32 *)(self + 0x14) < 2.0f || 1021.0f < *(f32 *)(self + 0x14) || z < 2.0f || 1021.0f < z) {
            self[0x20] = 5;
        }
        return;
    case 5:
        func_003C2880(self);
        return;
    }
}
