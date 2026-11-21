/* functional: medium. Written from PAL asm; compiles at level 02 (633 diff, regalloc/layout only). 5-state machine via jump table (states 1..5). Needs vu0.h; D_L02_001DDBF8 is the $gp float at +0x1348, D_001D545C_sda is $gp-0x7454. Unrun-risk: exact hero field names unknown (raw offsets used). */
extern void func_L02_0039E208(void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L02_004D36C0(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_L01_0044AE78(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern s32 func_L01_003F1F20(s32, s32);
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_L02_001E1300[];
extern u8 D_L02_0021E0D8[];
extern u8 *D_L02_001EC0C0[];
extern f32 D_L02_002EF1F0[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_L02_001DDBF8;
__asm__(".extern D_L02_001DDBF8, 4");

void func_L02_0039D7D0(u8 *self) {
    u8 *st;
    u8 *h = D_001A4BE0;
    vu0_v4 v0, v10, v20;
    u8 vC[0x30] __attribute__((aligned(16)));
    s32 flag, n, i, k, m, cnt, idx;
    u8 **ptr;
    u8 *p, *o;
    f32 d, a, t;

    func_L02_0039E208(self);
    st = *(u8 **)(self + 0x68);
    if (*(u8 **)(h + 0x35C) == self && *(s32 *)(h + 0x360) >= 2) {
        u8 s[0x30] __attribute__((aligned(16)));
        func_L01_00446748(s, self, 0x10001, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
        s[0x19] = 1;
        *(u16 *)(s + 0x1A) = *(u16 *)(self + 0xAA);
        s[0x18] = 0;
        func_L01_00446978(*(void **)(h + 0x25C0), s);
    }
    switch (self[0x20]) {
    case 1:
        if (st[0xF] == 0) return;
        if (st[0xE] == 0) {
            *(s32 *)(st + 4) = 0;
        } else {
            *(s32 *)(st + 4) = st[0xE] == 1 ? 0x1E : 0x3C;
        }
        self[0x20] = 2;
        st[0xF] = 0;
        return;
    case 2:
        if (func_0038CAD0(st + 4) != 0) {
            self[0x20] = 3;
            *(s32 *)(st + 4) = 0x1E;
        }
        return;
    case 3:
        if (func_0038CAD0(st + 4) != 0) {
            self[0x20] = 4;
            *(s32 *)(st + 4) = 0x14;
            st[0xC] = 0;
            *(f32 *)(st + 8) = 0.05f;
            *(s32 *)(st + 0x20) = func_003A52A0(0, 4, self);
        }
        return;
    case 4:
        if (func_0038CAD0(st + 4) != 0) {
            self[0x20] = 5;
            *(s32 *)(st + 4) = 0x5A;
            *(f32 *)(st + 8) = 0.011111111f;
        } else {
            v10 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
            v10.x = func_003C4088(4.6f, 0.0f, (f32)*(s32 *)(st + 4) * *(f32 *)(st + 8));
            v0 = v10;
            func_0038D000(&v0, &v0, self + 0xC0);
            vec_add_ab(self + 0x10, st + 0x10, &v0);
            if (*(s32 *)(st + 0x24) == 0) goto check5;
            if (st[0xC] != 0) {
                func_L02_004D36C0(0x31, 1);
                *(s32 *)(*(u8 **)(h + 0x25C0) + 0x9C) = -1;
                d = func_0038CE68(self + 0xF0, h + 0x90);
                *(f32 *)(h + 0x98) = func_0038DAB8(*(f32 *)(self + 0xF8), 0.0f < d ? 1.5707964f : -1.5707964f);
                *(u16 *)(h + 0x2888) = 1;
                *(f32 *)(h + 0x22D4) = 0.2f;
                *(f32 *)(h + 0x22D0) = 1.3f;
                *(f32 *)(h + 0x22D8) = 1.3f;
            }
        }
        if (*(s32 *)(st + 0x24) != 0) {
            v0 = (vu0_v4){7.5f, 0.0f, 1.5f, 0.0f};
            flag = 0;
            func_0038D000(&v0, &v0, self + 0xC0);
            vec_add_ab(&v10, st + 0x10, &v0);
            if (st[0xC] == 0 && *(s32 *)(st + 4) < 2 && *(s32 *)st != -1) {
                n = func_003D4D00(&v10, D_L02_001DDBF8, 0, *(void **)(self + 0xB8), 0);
                if (n != 0) {
                    v20 = (vu0_v4){-1.0f, 1.0f, 0.0f, 5627.9248f};
                    if (n > 0) {
                        ptr = D_L02_001EC0C0;
                        cnt = n;
                        do {
                            o = *ptr;
                            if (*(s16 *)(o + 0xAA) != 0x18BD && func_L01_00456500(o + 0x10, *(s32 *)st) != 0) {
                                if (*(s16 *)(*ptr + 0xAA) == 0) st[0xC] = 1;
                                func_L01_00446760(vC, self, 0x10001, &v20,
                                                  func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                                flag = 1;
                                *(u16 *)(vC + 0x1A) = *(u16 *)(self + 0xAA);
                                vC[0x18] = 0;
                                vC[0x19] = 1;
                                func_L01_00446978(*ptr, vC);
                            }
                            cnt--;
                            ptr++;
                        } while (cnt != 0);
                    }
                }
            }
            if (flag != 0) {
                func_003A52A0(3, 0, self);
                if (st[0xC] != 0) {
                    func_L01_004F4E70(0x14, 0);
                    func_L01_003F1F20(0x12, 0);
                    *(u16 *)(h + 0x20E) = 0x25;
                }
            }
        }
    check5:
        if (self[0x20] != 5) return;
        v0 = (vu0_v4){3.2f, 0.0f, 1.5f, 0.0f};
        func_0038D000(&v0, &v0, self + 0xC0);
        vec_add_ba(&v0, self + 0x10, &v0);
        n = 0x4B;
        if (20.0f < func_0038CF38(self + 0x10, D_L02_001E1300)) n = 0x19;
        for (i = 0; i < n; ) {
            f32 sp = func_003824E0(0.25f, 1.5f) * 210000.0f;
            t = func_L01_00443A18(0.0f, 0.06981317f);
            a = func_L01_0044AE78((f32)i * 0.41887903f + t);
            func_003C4840(vC, self + 0xC0, a);
            func_0038D850(&v20, self + 0xE0, vC);
            vec_add_ab(&v10, &v0, &v20);
            func_0038CE20(&v20, &v20, func_003824E0(3.0f, 5.0f) * 0.02f);
            k = func_00382468(3) - 1;
            m = func_00382498(0x28, 0x46);
            p = func_L01_0046FB40(&v10, &v20, (m * 5 + 2) / 6, 0x7F7F7F, k, 0x40, 0, 0, sp, sp, 0.0f);
            if (p != 0) {
                u8 c = **(u8 **)(D_L02_0021E0D8 + 0x5C);
                p[3] = 0x44;
                p[2] = c;
            }
            if (func_00382468(3) == 0) {
                func_0038CE20(&v20, &v20, 4.0f);
                func_003C4C18(&v20, 0.04f);
                m = func_00382498(10, 20);
                func_L01_00470668(&v10, &v20, (m * 5 + 2) / 6, 0.0f);
            }
            i++;
        }
        n = func_L01_004AA710(self, *(s32 *)(st + 0x20));
        if (n != 0) {
            idx = *(s32 *)(st + 0x20);
            if (idx != -1 && *(u8 **)(D_001A30B0 + (idx << 7) + 0xDC) == self && D_001A30B0[(idx << 7) + 0xD0] != 0) {
                func_003A4F28(idx);
            }
            *(s32 *)(st + 0x20) = -1;
        }
        func_003A52A0(1, 0, self);
        return;
    case 5:
        if (func_0038CAD0(st + 4) != 0) {
            if (st[0xF] != 0) {
                self[0x20] = 3;
                *(s32 *)(st + 4) = 0x1E;
            } else {
                self[0x20] = 1;
            }
            n = func_L01_004AA710(self, *(s32 *)(st + 0x20));
            if (n != 0) {
                idx = *(s32 *)(st + 0x20);
                if (idx != -1 && *(u8 **)(D_001A30B0 + (idx << 7) + 0xDC) == self && D_001A30B0[(idx << 7) + 0xD0] != 0) {
                    func_003A4F28(idx);
                }
                *(s32 *)(st + 0x20) = -1;
            }
        } else {
            if (func_L01_004AA710(self, *(s32 *)(st + 0x20)) == 0) {
                *(s32 *)(st + 0x20) = func_003A52A0(2, 4, self);
            }
            v10 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
            v10.x = func_003C3BE8(0.0f, 4.6f, (f32)*(s32 *)(st + 4) * *(f32 *)(st + 8));
            v0 = v10;
            func_0038D000(&v0, &v0, self + 0xC0);
            vec_add_ab(self + 0x10, st + 0x10, &v0);
        }
        if (*(s32 *)(st + 0x24) == 0) return;
        if (st[0xC] == 0) return;
        k = *(s32 *)(st + 4);
        if (k < 0x32) {
            if (k < 0x22) {
                func_L02_004D36C0(0, 1);
                *(s32 *)(*(u8 **)(h + 0x25C0) + 0x9C) = 0;
                *(u16 *)(h + 0x2888) = 0;
                st[0xC] = 0;
            } else {
                func_L02_004D36C0(0x74, 1);
                *(s32 *)(*(u8 **)(h + 0x25C0) + 0x9C) = -1;
                t = 1.0f / (f32)(*(s32 *)(st + 4) - 0x21);
                *(u16 *)(h + 0x2888) = 1;
                *(f32 *)(h + 0x22D4) = t * 0.8f + 0.2f;
                *(f32 *)(h + 0x22D0) = 1.3f - t * 0.3f;
                *(f32 *)(h + 0x22D8) = 1.3f - t * 0.3f;
            }
        } else {
            func_L02_004D36C0(0x31, 1);
            *(s32 *)(*(u8 **)(h + 0x25C0) + 0x9C) = -1;
            d = func_0038CE68(self + 0xF0, h + 0x90);
            *(f32 *)(h + 0x98) = func_0038DAB8(*(f32 *)(self + 0xF8), 0.0f < d ? 1.5707964f : -1.5707964f);
            *(u16 *)(h + 0x2888) = 1;
            *(f32 *)(h + 0x22D4) = 0.2f;
            *(f32 *)(h + 0x22D0) = 1.3f;
            *(f32 *)(h + 0x22D8) = 1.3f;
        }
        return;
    }
}
