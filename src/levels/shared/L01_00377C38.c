#include "common.h"

/* declared by functions of L01_003778D0.c, which this file was cut from */
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
typedef struct S_3738B0 S_3738B0;
typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;
struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};
extern S_3738B0 *D_L01_001E10E0;

/* localdecomp:start func_L01_00377C38 */
typedef int q128_77C38 __attribute__((mode(TI)));
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V4_77C38;
#include "structs/weapon.h"
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_L01_001E29C0[];
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1[4];
    u8 f20[1];
} E_77C38;
extern E_77C38 D_L01_001EAA00;
extern u8 D_L01_001F1B40[];
extern u8 D_L01_001E2880[];
extern u8 D_001A4C60[];
extern u8 D_00142DE0[];
extern u8 *D_L01_00221098[];
extern s32 D_L01_001D673C;
extern s32 D_00142668[4];
extern s32 D_L01_001EEA80[];
void func_L01_00377C38(u8 *obj) {
    extern void func_L01_004471A8(f32);
    extern void func_0038CF68(f32, void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB80(void *, void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_L01_004C8688(void *, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern void func_L01_00424D88(s32);
    extern void func_003A4F28(s32);
    extern s32 func_L01_0037C758_00377C38(s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10_00377C38(void *, void *);
    extern void func_L01_0037C3C8(void *, void *, void *);
    extern s32 func_L01_0037C720_00377C38(void);
    extern void func_L01_0037C6E8_00377C38(s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_L01_004AA710(void *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_L01_0034E558(void *, s32, void *, void *, s32);
    extern void func_L01_00373368(void *, void *, void *, f32);
    extern void func_L01_004C81F0(void *, void *, s32);
    extern s32 func_L01_004C8258(void *, void *);
    extern f32 *func_00382348(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_004C8598(void *);
    extern void func_L01_004C8668(void *);
    extern void func_003C2880(void *);
    extern void func_L01_004C84D8(void *);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003C7C38(void *);
    extern void func_L01_0037C208(void);
    extern void func_L01_00379398(void);
    extern void func_L01_00379B20(void);
    extern void func_L01_0037A880(void);
    extern void func_L01_0037A0F8(void);
    extern void func_L01_0037ADE0(void);
    extern void func_L01_0037B6C0(void);
    extern void func_L01_0037CC30(void *);
    extern void func_L01_0037CEC8(void);
    s32 wt;
    V4_77C38 old_pos, p10, p20, p30, p40, hit[3];
    u8 *o;
    f32 *hp;
    u8 *v;
    u8 *hero;
    u8 *ht1;
    u8 *ht2;
    u8 *h0;
    u8 *h2;
    u8 *e2;
    u8 *h3;
    u8 *e3;
    u8 *pd;
    u8 *tgt;
    u8 *cls;
    u8 *prt;
    f32 x, y, z, a, rr, rr2;
    s32 n, i, j, k, idx, life, rint, r1, r2, count, skip_8598;
    s32 col;
    u8 *hl;
    u8 *hx;
    u8 *pp, *pq;
    s32 idx_c4, idx_d;
    u32 col_c3;
    u32 col_c4;
    u8 *o_b11;
    s32 i_b1;
    f32 *hp_b29;
    s32 count_b18;
    s32 r1_b15;
    s32 n_b9;
    s32 i_b2;
    s32 r2_c3;
    s32 life_c3;
    s32 rint_c3;
    s32 life_c3a;
    s32 life_c2;
    s32 j_c3;
    s32 i_c3;
    s32 n_c3a, n_c4a;
    s32 r1_c3, k_c3;
    f32 rr_c3, rr2_c3;
    s32 i_c2;
    s32 n_c5;
    u8 *prt_c2;

    v = *(u8 **)(obj + 0x68);
    idx = D_001425C0[0x67];
    wt = D_L01_002C5600[idx].level;
    func_L01_004471A8(0.7f);
    if (func_L01_004CB2D8() != 0) {
        func_L01_004CAB80(obj + 0x10, obj + 0x10, obj + 0xF0, obj + 0xF0);
        func_0038D308(obj + 0xC0, obj + 0xF0);
        func_0038CF68(*(f32 *)(v + 0x18), obj + 0xD0, obj + 0xD0);
        func_0038CF68(*(f32 *)(v + 0x1C), obj + 0xE0, obj + 0xE0);
    }
    switch (obj[0x20]) {
    case 0:
        *(q128_77C38 *)&old_pos = *(q128_77C38 *)(obj + 0x10);
        func_L01_004C8688(*(void **)(v + 0x60), v, 0);
        func_L01_004C7D40(obj + 0x10, v, 0.0044f);
        vec_add_ab(obj + 0x10, v, obj + 0x10);
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f || *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f || *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
            s32 ci;
            u8 *co;
            if (*(s32 *)(v + 0x28) != -1) func_L01_00424D88(*(s32 *)(v + 0x28));
            ci = *(s32 *)(v + 0x5C);
            *(s32 *)(v + 0x28) = -1;
            if (ci != -1) {
                co = D_001A30B0 + ci * 0x80;
                if (*(u8 **)(co + 0xDC) == obj && co[0xD0] != 0) func_003A4F28(ci);
            }
            *(s32 *)(v + 0x5C) = -1;
            func_L01_0037C758_00377C38((s32)obj);
            if (wt >= 4) func_L01_004C8598(obj);
            func_L01_004C8668(*(void **)(v + 0x60));
            func_003C2880(obj);
            return;
        }
        *(s32 *)(v + 0x14) = *(s32 *)(v + 0x14) + 1;
        h0 = (u8 *)&D_001A4BE0;
        ht1 = *(u8 **)(h0 + 0x25C0);
        *(s32 *)(ht1 + 0x98) = 0;
        i = func_003D3CB0(&old_pos, obj + 0x10, 0x10, *(void **)(v + 0x58), 0);
        ht2 = *(u8 **)(h0 + 0x25C0);
        *(s32 *)(ht2 + 0x98) = *(s32 *)(*(u8 **)(ht2 + 0x24) + 0x10);
        if (i != 0) {
            tgt = D_L01_001EAA00.f18;
            if (tgt != 0) {
                cls = *(u8 **)(tgt + 0x24);
                if (cls == 0 || cls[0x46] != 5) {
                    *(q128_77C38 *)(v + 0x80) = *(q128_77C38 *)(tgt + 0x10);
                    *(u8 **)(v + 0x6C) = D_L01_001EAA00.f18;
                }
            }
            *(q128_77C38 *)(obj + 0x10) = *(q128_77C38 *)&old_pos;
            *(q128_77C38 *)(v + 0x70) = *(q128_77C38 *)&old_pos;
            func_L01_004C7D98(obj + 0x10, &p10);
            func_0038CE20(&p10, &p10, -0.25f);
            vec_add_ab(v + 0x70, v + 0x70, &p10);
            *(s32 *)(v + 0x14) = 0;
            func_L01_004450F0(obj, 1, -1);
            if (D_L01_001D673C != 0) {
                func_L01_004C7D98(obj + 0x10, &p20);
                vec_sub_ab(&p30, D_L01_001E29C0, obj + 0x10);
                func_0038CF68(1.0f, &p30, &p30);
                func_0038CE90(&p30, &p30, &p20);
                func_0038CE90(&p40, &p30, &p20);
                *(q128_77C38 *)(obj + 0xC0) = *(q128_77C38 *)&p40;
                *(q128_77C38 *)(obj + 0xD0) = *(q128_77C38 *)&p30;
                *(q128_77C38 *)(obj + 0xE0) = *(q128_77C38 *)&p20;
            }
            func_0038CF68(*(f32 *)(v + 0x18), obj + 0xD0, obj + 0xD0);
            func_0038CF68(*(f32 *)(v + 0x1C), obj + 0xE0, obj + 0xE0);
            *(q128_77C38 *)&p20 = *(q128_77C38 *)v;
            func_0038CE20(&p20, &p20, 3.0f);
            p20.w = 5627.9248f;
            func_L01_00446760(&hit[0], obj, 0x10000, &p20, 5.0f);
            ((u8 *)&hit[0])[0x18] = 0;
            ((u8 *)&hit[0])[0x19] = 1;
            *(u16 *)((u8 *)&hit[0] + 0x1A) = *(u16 *)(obj + 0xAA);
            func_003D4D00(D_L01_001EAA00.f20, 0, obj, &hit[0], 1.0f);
        }
        if (*(s32 *)(v + 0x28) == -1) {
            *(s32 *)(v + 0x28) = func_L01_00424CB0(obj + 0x10, 5.0f, 0.0f, 0.125f, 0.25f, 0.5f);
        } else {
            u8 *lo = D_L01_001F1B40 + *(s32 *)(v + 0x28) * 32;
            *(q128_77C38 *)(lo + 0x10) = *(q128_77C38 *)(obj + 0x10);
            *(f32 *)(lo + 0x1C) = 5.0f;
            *(f32 *)(lo + 0x0) = 0.125f;
            *(f32 *)(lo + 0x4) = 0.25f;
            *(f32 *)(lo + 0x8) = 0.5f;
            *(s32 *)(lo + 0xC) = 0;
        }
        *(q128_77C38 *)&p10 = *(q128_77C38 *)(obj + 0x10);
        p10.w = 4.0f;
        if (func_0038DC20(&p10, 80.0f) < 0) goto tail;
        func_L01_00404A10_00377C38(func_L01_0037C208, obj);
        *(q128_77C38 *)&p20 = *(q128_77C38 *)(obj + 0x10);
        func_L01_0037C3C8(obj, &p20, &old_pos);
        goto tail;
    case 1:
        if (func_L01_0037C720_00377C38() == 0) func_L01_0037C6E8_00377C38((s32)obj);
        *(s32 *)(v + 0x44) = 0;
        *(s32 *)(v + 0x48) = 0;
        *(s32 *)(v + 0x4C) = 0;
        *(s32 *)(v + 0x34) = 0;
        *(s32 *)(v + 0x38) = 0;
        *(s32 *)(v + 0x3C) = 0;
        *(s32 *)(v + 0x40) = 0;
        func_003A52A0(2, 0, obj);
        func_L01_004450F0(obj, 2, -1);
        goto tail;
    case 2:
        h2 = (u8 *)&D_001A4BE0;
        e2 = D_L01_001E2880;
        for (i_c2 = 0; i_c2 < 4; i_c2++) {
            a = func_0038D160(*(f32 *)(h2 + 0x80) - *(f32 *)(e2 + 0x140),
                              *(f32 *)(h2 + 0x84) - *(f32 *)(e2 + 0x144));
            func_L01_00443A18(1.0f, 2.0f);
            p10.x = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.15f);
            p10.y = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.15f);
            p10.z = *(f32 *)(obj + 0x18);
            a = func_0038DAB8(a, func_L01_00443A18(0.0f, -6.2831855f));
            p20.x = func_0038D098(a) * 0.0600000024f;
            p20.y = func_0038D0B0(a) * 0.0600000024f;
            p20.z = 0.0f;
            life_c2 = func_00382498(10, 30) * 5;
            life_c2 = life_c2 + 2;
            life_c2 = life_c2 / 6;
            rint = func_00382498(-2, -4);
            prt_c2 = func_L01_004713C8(&p10, &p20, life_c2, 0x804020, rint, 0x7F, 0, 210000.0f, 84000.0f, 0.0024f, 0);
            if (prt_c2 != 0) {
                prt_c2[2] = *D_L01_00221098[23];
                prt_c2[3] = func_00382468(8) != 0 ? 0x48 : 0x44;
            }
        }
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f || *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f || *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
            s32 ci;
            u8 *co;
            if (*(s32 *)(v + 0x28) != -1) func_L01_00424D88(*(s32 *)(v + 0x28));
            ci = *(s32 *)(v + 0x5C);
            *(s32 *)(v + 0x28) = -1;
            if (ci != -1) {
                co = D_001A30B0 + ci * 0x80;
                if (*(u8 **)(co + 0xDC) == obj && co[0xD0] != 0) func_003A4F28(ci);
            }
            *(s32 *)(v + 0x5C) = -1;
            func_L01_0037C758_00377C38((s32)obj);
            func_L01_004C8668(*(void **)(v + 0x60));
            func_003C2880(obj);
            return;
        }
        if (*(s32 *)(v + 0x28) == -1) {
            *(s32 *)(v + 0x28) = func_L01_00424CB0(obj + 0x10, 5.0f, 0.0f, 0.125f, 0.25f, 0.5f);
        } else {
            u8 *lo = D_L01_001F1B40 + *(s32 *)(v + 0x28) * 32;
            *(q128_77C38 *)(lo + 0x10) = *(q128_77C38 *)(obj + 0x10);
            *(f32 *)(lo + 0x1C) = 5.0f;
            *(f32 *)(lo + 0x0) = 0.125f;
            *(f32 *)(lo + 0x4) = 0.25f;
            *(f32 *)(lo + 0x8) = 0.5f;
            *(s32 *)(lo + 0xC) = 0;
        }
        if (*(f32 *)(v + 0x18) >= 2.0f && *(f32 *)(v + 0x1C) >= 1.2f) {
            func_L01_004450F0(obj, 3, -1);
        } else {
            if (*(f32 *)(v + 0x1C) < 1.2f) {
                *(f32 *)(v + 0x18) = *(f32 *)(v + 0x18) + 0.06f;
                *(f32 *)(v + 0x1C) = *(f32 *)(v + 0x1C) + 0.04f;
            } else {
                *(f32 *)(v + 0x18) = *(f32 *)(v + 0x18) + 0.06f;
            }
            func_0038CF68(*(f32 *)(v + 0x18), obj + 0xD0, obj + 0xD0);
            func_0038CF68(*(f32 *)(v + 0x1C), obj + 0xE0, obj + 0xE0);
            func_L01_004C7D98(obj + 0x10, &p10);
            func_0038CE20(&p10, &p10, 0.032f);
            vec_add_ab(obj + 0x10, obj + 0x10, &p10);
        }
        *(q128_77C38 *)&p10 = *(q128_77C38 *)(obj + 0x10);
        p10.w = 4.0f;
        if (func_0038DC20(&p10, 80.0f) < 0) goto tail;
        if (wt >= 2) func_L01_00404A10_00377C38(func_L01_00379398, obj);
        else func_L01_00404A10_00377C38(func_L01_00379B20, obj);
        *(q128_77C38 *)&p20 = *(q128_77C38 *)(obj + 0x10);
        func_L01_0037C3C8(obj, &p20, &old_pos);
        goto tail;
    case 3:
        n_c3a = *(s32 *)(v + 0x14) + 1;
        *(s32 *)(v + 0x14) = n_c3a;
        if (n_c3a >= 751 || *(s16 *)(v + 0x26) == 0 || func_L01_0040E548(obj + 0x10, D_001A4C60) > 1225.0f) {
            *(s32 *)(v + 0x14) = 0;
            func_L01_004450F0(obj, 5, -1);
        }
        if (func_L01_004AA710(obj, *(s32 *)(v + 0x5C)) == 0) *(s32 *)(v + 0x5C) = func_003A52A0(0, 4, obj);
        *(q128_77C38 *)&p10 = *(q128_77C38 *)(obj + 0x10);
        p10.w = 4.0f;
        if (func_0038DC20(&p10, 80.0f) < 0) goto tail;
        h3 = (u8 *)&D_001A4BE0;
        e3 = D_L01_001E2880;
        for (i_c3 = 0; i_c3 < 2; i_c3++) {
            a = func_0038D160(*(f32 *)(h3 + 0x80) - *(f32 *)(e3 + 0x140),
                              *(f32 *)(h3 + 0x84) - *(f32 *)(e3 + 0x144));
            func_L01_00443A18(1.0f, 2.0f);
            p20.x = *(f32 *)(v + 0x70) + func_L01_00443A18(0.0f, 0.15f);
            p20.y = *(f32 *)(v + 0x74) + func_L01_00443A18(0.0f, 0.15f);
            p20.z = *(f32 *)(v + 0x78);
            a = func_0038DAB8(a, func_L01_00443A18(0.0f, -6.2831855f));
            p30.x = func_0038D098(a) * 0.100000009f;
            p30.y = func_0038D0B0(a) * 0.100000009f;
            p30.z = 0.0f;
            life_c3a = func_00382498(10, 30) * 5;
            life_c3a = life_c3a + 2;
            life_c3a = life_c3a / 6;
            rint_c3 = func_00382498(-2, -4);
            prt = func_L01_004713C8(&p20, &p30, life_c3a, 0x804020, rint_c3, 0x5F, 0, 210000.0f, 84000.0f, 0.0f, 0);
            if (prt != 0) prt[2] = *D_L01_00221098[23];
        }
        if (wt > 0) {
            n = *(s16 *)(v + 0x24);
            if (n >= 5) n = 4;
            col_c3 = 0x204080;
            if (wt == 1) {
                col_c3 = 0x804020;
                n = 1;
            }
            for (j_c3 = 0; j_c3 < n; j_c3++) {
                r1_c3 = (s32)func_L01_00443A18(2.0f, 5.0f);
                r2_c3 = func_00382498(1, 12);
                k_c3 = r2_c3 + 1;
                if (r2_c3 == 12) k_c3 = 1;
                func_003C2F58(obj, r2_c3, &p40);
                func_003C2F58(obj, k_c3, &hit[0]);
                rr_c3 = func_003824E0(0.0f, 1.0f);
                func_0038CDF8(&p20, &p40, &hit[0], rr_c3);
                vec_sub_ab(&p30, obj + 0x10, &p20);
                rr_c3 = func_003824E0(1.5f, 2.0f);
                func_0038CF68(rr_c3 * 0.0200000014f, &p30, &p30);
                life_c3 = (func_00382498(20, 25) * 5 + 2) / 6;
                rr2_c3 = func_003824E0(0.04f, 0.06f);
                func_L01_004713C8(&p20, &p30, life_c3, col_c3, r1_c3, 0, 0x7F, 23100.0f, rr2_c3 * 210000.0f, 0.0f, 6);
            }
        }
        if (wt >= 2) func_L01_00404A10_00377C38(func_L01_00379398, obj);
        else func_L01_00404A10_00377C38(func_L01_00379B20, obj);
        if (wt >= 4) func_L01_004C84D8(obj);
        goto tail;
    case 4:
        n_c4a = *(s32 *)(v + 0x14) + 1;
        *(s32 *)(v + 0x14) = n_c4a;
        if (n_c4a >= 751) {
            *(s32 *)(v + 0x14) = 0;
            func_L01_004450F0(obj, 5, -1);
        }
        if (*(s32 *)(v + 0x30) == 25) {
            idx_c4 = D_001425C0[0x67];
            pp = (u8 *)D_L01_002C5600;
            r1_b15 = pp[idx_c4 * 0xF0 + 1] + 0x67;
            pd = D_00142DE0;
            *(s32 *)(pd + 0x19C) = *(s32 *)(pd + 0x19C) +
                (*(s32 *)(pp + r1_b15 * 0xF0 + 0x68) << 5) / 150;
            *(u16 *)(v + 0x24) = *(u16 *)(v + 0x24) + 1;
            n_b9 = *(u16 *)(v + 0x26) - *(u16 *)(v + 0x54);
            *(s16 *)(v + 0x26) = n_b9;
            if ((s32)(n_b9 << 16) < 0) *(s16 *)(v + 0x26) = 0;
            func_003A52A0(1, 0, obj);
        }
        if (wt >= 4 && *(s32 *)(v + 0x30) % 10 == 0) {
            o_b11 = (u8 *)&D_001A4BE0;
            count_b18 = func_003D4D00(obj + 0x10, 1, *(void **)(o_b11 + 0x25C0), 0, 16.0f);
            hl = (u8 *)&D_001A4BE0;
            for (i_b1 = 0; i_b1 < count_b18; i_b1++) {
                o_b11 = (u8 *)D_L01_001EEA80[i_b1];
                hp_b29 = func_00382348(o_b11);
                if (o_b11 == *(u8 **)(hl + 0x25C0)) continue;
                if (o_b11 == 0) continue;
                if (o_b11[0x20] == 0xFE) continue;
                if (o_b11[0x20] == 0xFD) continue;
                cls = *(u8 **)(o_b11 + 0x24);
                if (cls == 0) continue;
                if (cls[0x46] != 5) continue;
                if (!(*(u16 *)(o_b11 + 0x34) & 0x1000)) continue;
                if (func_L01_004C8258(obj, o_b11) == 0) continue;
                if (hp_b29 == 0) continue;
                if (!(0.0f < *hp_b29)) continue;
                if (*(u16 *)(o_b11 + 0x34) & 2) continue;
                func_L01_004C7D98(obj + 0x10, &p10);
                func_0038CF68(hp_b29[4], &p10, &p10);
                vec_add_ab(&p10, o_b11 + 0x10, &p10);
                vec_sub_ab(&p20, &p10, obj + 0x10);
                func_0038CF68(1.25f, &p20, &p20);
                func_L01_004C81F0(obj, o_b11, 0x23);
                pq = (u8 *)D_L01_002C5600;
                idx_d = D_001425C0[0x67];
                *(q128_77C38 *)&p30 = *(q128_77C38 *)(obj + 0x10);
                func_L01_00373368(obj, &p30, &p20,
                    0.25f * *(f32 *)(pq + idx_d * 0xF0 + 0x6C));
                break;
            }
        } else if ((u32)(wt - 2) < 2 && *(s32 *)(v + 0x30) == 12) {
            hx = (u8 *)&D_001A4BE0;
            count = func_003D4D00(obj + 0x10, 1, *(void **)(hx + 0x25C0), 0, 7.5f);
            for (i_b2 = 0; i_b2 < count; i_b2++) {
                o = (u8 *)D_L01_001EEA80[i_b2];
                hp = func_00382348(o);
                hl = (u8 *)&D_001A4BE0;
                if (o == *(u8 **)(hl + 0x25C0)) continue;
                if (o == 0) continue;
                if (o[0x20] == 0xFE) continue;
                if (o[0x20] == 0xFD) continue;
                cls = *(u8 **)(o + 0x24);
                if (cls == 0) continue;
                if (cls[0x46] != 5) continue;
                if (!(*(u16 *)(o + 0x34) & 0x1000)) continue;
                if (hp == 0) continue;
                if (!(0.0f < *hp)) continue;
                if (*(u16 *)(o + 0x34) & 2) continue;
                func_L01_004C7D98(obj + 0x10, &p10);
                func_0038CF68(hp[4], &p10, &p10);
                vec_add_ab(&p10, o + 0x10, &p10);
                vec_sub_ab(&p20, &p10, obj + 0x10);
                func_0038CF68(1.0f, &p20, &p20);
                func_L01_0034E558(o, 0x804020, &p10, obj, 0);
                *(u16 *)(v + 0x24) = 0;
                break;
            }
        }
        if (func_0038CAD0(v + 0x30) != 0) {
            func_003A52A0(2, 0, obj);
            func_L01_004450F0(obj, 2, -1);
            *(s32 *)(v + 0x40) = 0;
            *(s32 *)(v + 0x30) = 25;
        }
        *(q128_77C38 *)&p10 = *(q128_77C38 *)(obj + 0x10);
        p10.w = 4.0f;
        if (func_0038DC20(&p10, 80.0f) < 0) goto tail;
        if (wt > 0) {
            n = *(s16 *)(v + 0x24);
            if (n >= 5) n = 4;
            col_c4 = 0x204080;
            if (wt == 1) {
                col_c4 = 0x804020;
                n = 1;
            }
            for (j = 0; j < n; j++) {
                r1 = (s32)func_L01_00443A18(2.0f, 5.0f);
                r2 = func_00382498(1, 12);
                k = r2 + 1;
                if (r2 == 12) k = 1;
                func_003C2F58(obj, r2, &p40);
                func_003C2F58(obj, k, &hit[0]);
                rr = func_003824E0(0.0f, 1.0f);
                func_0038CDF8(&p20, &p40, &hit[0], rr);
                vec_sub_ab(&p30, obj + 0x10, &p20);
                rr = func_003824E0(1.5f, 2.0f);
                func_0038CF68(rr * 0.0200000014f, &p30, &p30);
                life = (func_00382498(20, 25) * 5 + 2) / 6;
                rr2 = func_003824E0(0.04f, 0.06f);
                func_L01_004713C8(&p20, &p30, life, col_c4, r1, 0, 0x7F, 23100.0f, rr2 * 210000.0f, 0.0f, 6);
            }
        }
        if (wt >= 2) func_L01_00404A10_00377C38(func_L01_0037A0F8, obj);
        else func_L01_00404A10_00377C38(func_L01_0037A880, obj);
        goto tail;
    case 5:
        n_c5 = *(s32 *)(v + 0x14) + 1;
        *(s32 *)(v + 0x14) = n_c5;
        if (n_c5 >= 18) {
            s32 ci;
            u8 *co;
            if (*(s32 *)(v + 0x28) != -1) func_L01_00424D88(*(s32 *)(v + 0x28));
            ci = *(s32 *)(v + 0x5C);
            *(s32 *)(v + 0x28) = -1;
            if (ci != -1) {
                co = D_001A30B0 + ci * 0x80;
                if (*(u8 **)(co + 0xDC) == obj && co[0xD0] != 0) func_003A4F28(ci);
            }
            *(s32 *)(v + 0x5C) = -1;
            func_L01_0037C758_00377C38((s32)obj);
            if (wt >= 4) func_L01_004C8598(obj);
            func_L01_004C8668(*(void **)(v + 0x60));
            func_003C2880(obj);
            return;
        }
        if (wt >= 2) func_L01_00404A10_00377C38(func_L01_0037ADE0, obj);
        else func_L01_00404A10_00377C38(func_L01_0037B6C0, obj);
        goto tail;
    default:
        goto tail;
    }
tail:
    if (obj[0x20] == 3 && *(s32 *)(v + 0x14) >= 0x227) {
        *(f32 *)(v + 0x68) = func_0038DAB8(*(f32 *)(v + 0x68), 0.0837758109f);
        rr = func_0038D0B0(*(f32 *)(v + 0x68)) * 0.5f + 0.5f;
        col = func_0038DBD8(0x7F808080, 0x7F103080, rr);
        { s32 cb = (col >> 16) & 0xFF; s32 cg = (col >> 8) & 0xFF; func_L01_0043B9E8(obj, col & 0xFF, cg, cb); }
    }
    if (*(u8 **)(v + 0x6C) != 0 && func_L01_004CB2D8() == 0) {
        vec_sub_ab(&p10, *(u8 **)(v + 0x6C) + 0x10, v + 0x80);
        *(q128_77C38 *)(v + 0x80) = *(q128_77C38 *)(*(u8 **)(v + 0x6C) + 0x10);
        vec_add_ab(obj + 0x10, obj + 0x10, &p10);
    }
    if (wt > 0 && *(s16 *)(v + 0x26) > 0 && *(s32 *)(D_001A4BE0 + 0x2850) < D_00142668[0]) {
        func_L01_0037CC30(obj);
        func_L01_00404A10_00377C38(func_L01_0037CEC8, obj);
    }
    rr = *(f32 *)(v + 0x18);
    a = *(f32 *)(obj + 0x2C);
    obj[0xA8] = 0xFF;
    *(f32 *)(obj + 0x2C) = rr * a;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    func_003C7C38(obj);
    *(f32 *)(obj + 0x2C) = a;
    *(s32 *)(obj + 0x98) = 0;
    return;
}
/* localdecomp:end func_L01_00377C38 */
