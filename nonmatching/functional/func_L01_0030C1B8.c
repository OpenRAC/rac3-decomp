/* functional: medium. Decoded by hand from PAL asm incl. jump table; all handlers traced; vu0 adds via vec_add_ab; func_003D4D00 returns count in v0 though the context declares it void (called via cast). */
typedef struct { s32 a, b, c; } V12_0030C1B8;
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001EAA20[];
extern u8 *D_L01_001EEA80[];
extern V12_0030C1B8 D_001DC658;
extern s32 D_001DC64C_sda;
__asm__(".extern D_001DC64C_sda, 4");
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004AB048(s32, s32);
extern u8 *func_00382348(void *);
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0030E630(void *, s32, s32);
extern void func_L01_0031B090(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8(void *, void *, void *, void *, s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_0030C878(u8 *, u8 *, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L01_0030D6B8(u8 *);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern void func_L01_0030CB20(u8 *);
extern void func_L01_0030D0D8(s32);
extern s32 func_L01_00457458(s32, s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_0030D928(u8 *);

void func_L01_0030C1B8(u8 *obj) {
    u8 *vars;
    u8 *rec;
    u8 *cand;
    u8 *st;
    u8 *P;
    s32 *Q;
    s32 i, k, n, r, t, state;
    f32 tmp20[4] __attribute__((aligned(16)));
    f32 tmp30[4] __attribute__((aligned(16)));
    u8 *hits[8] __attribute__((aligned(16)));
    s32 excl[2];
    s32 count;
    s32 hitq[8] __attribute__((aligned(16)));

    vars = *(u8 **)(obj + 0x68);
    if (func_L01_004CB2D8() != 0) {
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
    }
    state = obj[0x20];
    if (state <= 4) {
        switch (state) {
        case 0:
            obj[0x20] = 1;
            *(s32 *)(vars + 0x24) = -1;
            *(s32 *)(vars + 0x20) = -1;
            /* fall into state 1 */
        case 1:
            *(s128_003068B8 *)tmp20 = *(s128_003068B8 *)(obj + 0x10);
            func_L01_004C8688(*(s32 *)(vars + 0x44), vars, 0);
            vec_add_ab(obj + 0x10, obj + 0x10, vars);
            P = obj + 0x10;
            t = *(s32 *)(vars + 0x20);
            if (t != -1) {
                rec = D_001A30B0 + (t << 7);
                if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                    r = func_00382498(-200, 200);
                    func_L01_004AB048(*(s32 *)(vars + 0x20), *(s32 *)(vars + 0x24) + r);
                }
            }
            Q = (s32 *)(vars + 0x10);
            n = ((s32 (*)(void *, s32, void *, void *, f32))func_003D4D00)(P, 0, obj, 0, 0.45f); /* returns the hit count in v0; the file context declares it void */
            for (i = 0; i < n;) {
                cand = D_L01_001EEA80[i];
                st = func_00382348(cand);
                if (*(s16 *)(cand + 0xAA) != 0xC4A) {
                    if (cand != *(u8 **)(D_001A4BE0 + 0x25C0)) {
                        i++;
                        if (*(u16 *)(cand + 0x34) & 0x1000) {
                            if (st != 0) {
                                *(s128_003068B8 *)(obj + 0x10) = *(s128_003068B8 *)(cand + 0x10);
                                func_L01_00451290(cand, tmp30, 1);
                                func_0038CE20(tmp30, tmp30, *(f32 *)(st + 0x10));
                                vec_add_ab(obj + 0x10, obj + 0x10, tmp30);
                            }
                            *(u8 **)(vars + 0x38) = cand;
                            *(s32 *)(vars + 0x10) = 12;
                            obj[0x20] = 2;
                            *(s128_003068B8 *)tmp30 = *(s128_003068B8 *)vars;
                            *(s128_003068B8 *)vars = 0;
                            func_0038CF68(tmp30, tmp30, 0.04f);
                            func_L01_00446760(hitq, obj, 0x410000, tmp30,
                                              *(f32 *)(D_L01_002C5600 + D_001425C0[0x10] * 0xF0 + 0x6C));
                            ((u8 *)hitq)[0x18] = 1;
                            ((u8 *)hitq)[0x19] = 3;
                            *(u16 *)((u8 *)hitq + 0x1A) = *(u16 *)(obj + 0xAA);
                            func_L01_00446978(cand, hitq);
                            func_L01_0030E630(P, 10, 1);
                            func_L01_0031B090(cand, 0x10, *(void **)(obj + 0xB8));
                            break;
                        }
                        continue;
                    }
                }
                i++;
            }
            if (*(s32 *)(vars + 0x38) == 0) {
                r = func_003D3CB0(tmp20, P, 2, obj, 0);
                if (r != 0) {
                    t = 1;
                } else {
                    t = func_L01_003FB640(P, 2, obj, 0.1f) != 0;
                }
                if (t == 1) {
                    *(s128_003068B8 *)(obj + 0x10) = *(s128_003068B8 *)D_L01_001EAA20;
                    func_0038CE20(tmp30, (f32 *)(D_L01_001EAA20 + 0x20), 1.0f / 1024.0f);
                    func_0038CF68(tmp30, tmp30, 0.1f);
                    vec_add_ab(obj + 0x10, tmp30, obj + 0x10);
                    *(s32 *)(vars + 0x10) = 12;
                    obj[0x20] = 2;
                    func_L01_0030E630(P, 15, 0);
                }
            }
            if (func_0038CAD0(Q) != 0) {
                obj[0x20] = 4;
                *(s32 *)(vars + 0x10) = 0x86;
            }
            break;
        case 2:
            if (*(s32 *)(vars + 0x38) != 0) {
                st = func_00382348(*(void **)(vars + 0x38));
                if (st != 0) {
                    func_L01_00451290(*(void **)(vars + 0x38), tmp30, 1);
                    func_0038CE20(tmp30, tmp30, *(f32 *)(st + 0x10));
                    vec_add_ab(obj + 0x10, tmp30, *(u8 **)(vars + 0x38) + 0x10);
                }
            }
            if (func_0038CAD0(vars + 0x10) != 0) {
                obj[0x20] = 4;
                *(V12_0030C1B8 *)tmp30 = D_001DC658;
                excl[0] = *(s32 *)(vars + 0x38);
                excl[1] = 0;
                func_L01_004501E8(obj + 0x10, obj + 0xC0, &count, hits, 3, excl, 0, tmp30, 1, -1, 0,
                                  6.2831855f, 6.2831855f, 10.0f, 0.0f, 0.0f);
                if (count > 0) {
                    for (i = 0; i < count; i++) {
                        for (k = 4; k >= 0; k--) {
                            func_L01_0030C878(obj, hits[i], 10);
                        }
                        func_003A52A0(1, 0, obj);
                    }
                }
            }
            break;
        case 4:
            if (*(s32 *)(vars + 0x38) != 0) {
                if (D_001DC64C_sda == 0) {
                    D_001DC64C_sda = 1;
                    func_003A52A0(3, 0, obj);
                }
                st = func_00382348(*(void **)(vars + 0x38));
                if (st != 0) {
                    func_L01_00451290(*(void **)(vars + 0x38), tmp30, 1);
                    func_0038CE20(tmp30, tmp30, *(f32 *)(st + 0x10));
                    vec_add_ab(obj + 0x10, tmp30, *(u8 **)(vars + 0x38) + 0x10);
                }
            }
            if (*(s32 *)(vars + 0x1C) == 0) {
                func_L01_0030D6B8(obj);
                if (*(s32 *)(vars + 0x38) == 0) {
                    func_L01_0030E630(obj + 0x10, 10, 1);
                    func_003A52A0(2, 0, obj);
                }
            }
            break;
        default:
            break;
        }
    }

    if (obj[0x20] != 4) {
        if (func_L01_004AA710(obj, *(s32 *)(vars + 0x20)) == 0) {
            *(s32 *)(vars + 0x20) = func_003A52A0(0, 4, obj);
        }
        if (*(s32 *)(vars + 0x24) == -1) {
            *(s32 *)(vars + 0x24) = *(s32 *)(D_001A30B0 + (*(s32 *)(vars + 0x20) << 7) + 0xD4);
        }
    } else {
        t = *(s32 *)(vars + 0x20);
        if (t != -1) {
            rec = D_001A30B0 + (t << 7);
            if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                func_003A4F28(t);
            }
            *(s32 *)(vars + 0x20) = -1;
        }
    }
    func_L01_0030CB20(obj);
    func_L01_0030D0D8((s32)obj);
    if (func_L01_00457458(*(s32 *)(vars + 0x40), *(s32 *)(vars + 0x3C)) == 0) {
        func_L01_004C8668(*(s32 *)(vars + 0x44));
        func_003C2880(obj);
    } else {
        func_L01_00404A10(func_L01_0030D928, obj);
    }
}
