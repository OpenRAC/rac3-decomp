/* functional: high. vadd.xyz (w kept from the first operand) is written as plain C because PAL's flags lack -mvu0-use-vf0-vf2. Veldin per-frame update of the "hero/camera replay" state (level reset overlay): counts frames, fades D_L01_001DF950, handles skip/exit input via D_001D4D40, steps 2-frame animation blends for every object in the object list, then runs the shared frame tail. Ported from the byte-exact NTSC-U draft with PAL names, constants (0x19, 0xF, 0xC1, 0.048, 20.0) and callees re-read from the PAL asm. */

typedef int u128_t __attribute__((mode(TI)));

typedef struct Ent_004BA278 {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x24];
    u16 h34;
    u8 pad36[0xA];
    u8 b40;
    u8 b41;
    u8 pad42[2];
    f32 f44;
    u8 pad48[0x19];
    u8 b61;
    u8 pad62;
    u8 b63;
    u8 pad64[4];
    u8 *p68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x3A];
    s16 hAA;
    u8 padAC[8];
    s16 hB4;
    u8 padB6[0x3A];
} Ent_004BA278;

typedef struct S_004BA278 {
    u8 pad0[0x34];
    s32 w34;
    s32 w38;
    s32 w3C;
    s16 h40;
    u8 pad42[2];
    s16 h44;
    u8 pad46[2];
    s16 h48;
    u8 pad4A[0x60 - 0x4A];
    s8 b60;
    u8 pad61[0x1A0 - 0x61];
    Ent_004BA278 *ents[8];
} S_004BA278;

extern S_004BA278 D_L01_001E6D80;
extern u8 D_L01_001EA7C0[];
extern f32 D_L01_001DF950;
extern f32 D_L01_001DF950_sda;
extern u32 D_001D4D40;
extern u32 D_001D4D40_sda;
extern u8 *D_001D52FC_sda;
extern s32 D_00143950;
extern s16 D_001CCFD4;
extern void func_00392C48(void *);
extern s32 func_00392C78(void *);
extern void func_003A0F98(s32, s32);
extern void func_003E5520(void);
extern void func_L01_00423A10(void);
extern void func_003CD058(void);
extern void func_L01_004AB0E0(void);
extern void func_L01_004E20E8(void);
extern void func_003CD350(void);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003A1798(void);
extern void func_003A2750(s32);
extern void func_0039A438(void);
extern void func_L01_0042C458(s32);
extern s32 func_003E56E0(void);
extern void func_003C29B0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_004472C0(void *);
extern void func_L01_00512A30(void *, s32);
extern void func_L01_004E2988(void *);
extern void func_L01_004241F0(void);
extern void func_003A4288(void);
extern void func_003D0B20(void);
extern void func_L01_0043AB98(void);
extern void func_003E55B8(void);

void func_L01_004BA278(void) {
    s32 flagA;
    s32 flagB;
    s32 v;
    s32 i;
    s32 r;
    Ent_004BA278 *e;
    u8 *tbl;
    f32 f20;
    f32 f21;
    u8 L[0x20] __attribute__((aligned(16)));

    if (D_L01_001E6D80.b60 == 0) {
        if (D_L01_001E6D80.h40 == 0) {
            func_00392C48(D_L01_001EA7C0);
            D_L01_001E6D80.b60 = 1;
            func_003A0F98(0, 0);
            return;
        }
        if (D_L01_001E6D80.h40 < D_L01_001E6D80.w34 + 0xF) {
            D_L01_001DF950 = (f32)(D_L01_001E6D80.w34 - (D_L01_001E6D80.h40 - 0xF)) * 0.06666667f;
        }
        func_003E5520();
        func_L01_00423A10();
        func_003CD058();
        func_L01_004AB0E0();
        func_L01_004E20E8();
        func_003CD350();
        D_L01_001E6D80.w34 = D_L01_001E6D80.w34 + 1;
        D_L01_001E6D80.w38 = D_L01_001E6D80.w38 + 1;
        if (D_L01_001E6D80.w34 < 0x19) {
            func_003C4138(&D_L01_001DF950, 0.0f, 0.048f);
            if (1.0f < D_L01_001DF950) {
                D_L01_001DF950_sda = 1.0f;
            }
        }
        if (!(D_L01_001E6D80.w34 < D_L01_001E6D80.h48)) {
            func_003A1798();
        }
        flagA = 0;
        flagB = !(D_L01_001E6D80.w34 < D_L01_001E6D80.h40);
        if (!(D_L01_001E6D80.w34 < 0xF)) {
            if (D_L01_001DF950 == 0.0f) {
                v = D_001D4D40_sda;
                if (!(v & 0x80)) {
                    v = v & ~0xC1;
                    if (v != 2) {
                        if (v == 0 && (*(s32 *)(D_001D52FC_sda + 0x1A4) & 0x9FF) != 0) {
                            flagA = 1;
                        } else {
                            flagA = (*(s32 *)(D_001D52FC_sda + 0x1A4) & 0x800) != 0;
                        }
                    }
                }
            }
        }
        if (flagA != 0) {
            D_001D4D40 = D_001D4D40_sda & ~0x80;
            D_L01_001EA7C0[0x64] = 1;
            func_00392C48(D_L01_001EA7C0);
            D_L01_001E6D80.b60 = 1;
            func_003A0F98(0, 0);
        } else if (flagB != 0) {
            D_L01_001E6D80.b60 = 1;
            D_001D4D40_sda = D_001D4D40_sda & ~0x80;
            if (func_00392C78(D_L01_001EA7C0) == 0) {
                func_003A0F98(0, 0);
            }
        } else {
            if (!(D_L01_001E6D80.w38 < (D_00143950 ? 0x50 : 0x60))) {
                D_L01_001E6D80.w3C = D_L01_001E6D80.w3C + 1;
                if (D_001CCFD4 != 0) {
                    func_003A2750(1);
                }
                func_0039A438();
                func_L01_0042C458(D_L01_001E6D80.w3C + 1);
            }
            r = func_003E56E0();
            i = 0;
            if (D_L01_001E6D80.h44 > 0) {
                do {
                    e = D_L01_001E6D80.ents[i];
                    v = D_L01_001E6D80.w38 >> 1;
                    e->b41 = v + 1;
                    e->b40 = v;
                    func_003C29B0(e);
                    e->f44 = (f32)(D_L01_001E6D80.w38 & 1) * 0.5f;
                    if (r != 0) {
                        if ((D_L01_001E6D80.w38 & 1) != 0 && e->hB4 == 0) {
                            e->f44 = 1.0f;
                        }
                    }
                    tbl = e->p68;
                    func_0038CE20(L, tbl + (e->b40 << 4), 1.0f - e->f44);
                    func_0038CE20(L + 0x10, tbl + (e->b41 << 4), e->f44);
                    {
                        f32 *dv = (f32 *)((u8 *)e + 0x10);
                        f32 *va = (f32 *)L;
                        f32 *vb = (f32 *)(L + 0x10);
                        dv[0] = va[0] + vb[0];
                        dv[1] = va[1] + vb[1];
                        dv[2] = va[2] + vb[2];
                        dv[3] = va[3];
                    }
                    e->b61 = 0xFF;
                    func_003C7C38(e);
                    if (e->b63 != 0) {
                        if (D_L01_001E6D80.w3C == 0) {
                            *(u128_t *)((u8 *)e + 0xF0) = *(u128_t *)e;
                            e->h34 = e->h34 | 0x100;
                        } else if (D_L01_001E6D80.w38 < 0x10) {
                            f21 = func_0038CF00(e, (u8 *)e + 0xF0);
                            if (f21 < 20.0f) {
                                f20 = (f32)D_L01_001E6D80.w38 * 0.0625f;
                                func_0038CDF8(e, (u8 *)e + 0xF0, e, f20);
                                e->fC = e->fC + f21 * (1.0f - f20);
                            }
                        } else {
                            *(u128_t *)((u8 *)e + 0xF0) = *(u128_t *)e;
                            e->h34 = e->h34 | 0x100;
                        }
                    }
                    if (e->b6F != 0) {
                        func_L01_004472C0(e);
                    }
                    if (e->hAA == 0 || e->hAA == 0xF6B) {
                        func_L01_00512A30(e, 0);
                    }
                    if (e->hAA == 10 || e->hAA == 0x19C9 || e->hAA == 0x1159 || e->hAA == 0x1F6B || e->hAA == 0x57 || e->hAA == 0x259 || e->hAA == 0x1F6B) {
                        func_L01_004E2988(e);
                    }
                    i++;
                } while (i < D_L01_001E6D80.h44);
            }
        }
        func_L01_004241F0();
        func_003A4288();
        func_003D0B20();
        func_L01_0043AB98();
        func_003E55B8();
    }
}
