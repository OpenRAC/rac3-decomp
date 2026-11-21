/* functional: high. Byte-exact at level 02 (check.py MATCH); needs the extern for func_L02_00352208 declared before it. */
extern void func_L02_00352208(u8 *);
/* localdecomp:start func_L02_00352418 */
typedef struct { vu0_v4 v0, v1, v2; f32 pad[2]; u8 b38, b39; u16 h3a; } St_352418;
extern u8 D_001A30B0[];
extern u8 D_001A30B0_00352418[];
typedef struct { u8 pad0[0xD0]; vu0_v4 vD0; u8 pad1[0x25C0 - 0xE0]; s32 f25C0; } G_352418;
extern G_352418 D_001A4BE0;
extern u8 *D_L02_001DFA50;
__asm__(".extern D_L02_001DFA50, 16");
extern s32 D_L02_001DE4C0;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_00382348(void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2880(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_003D4D00(void *, f32, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00404808(void (*)(void *), void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_L01_004CB358(void);
extern void func_L01_00456160(u8 *, u8 *);

void func_L02_00352418(u8 *self) {
    u8 *m;
    St_352418 st;
    vu0_v4 t40, v50, v60, v70;
    s32 i;
    u8 **tbl;
    f32 len;
    s32 ub;
    u8 **p;
    u8 *tgt, *pos;

    *(u16 *)(self + 0x34) |= 0x100;
    m = *(u8 **)(self + 0x68);
    if (self[0x20] == 1 && func_0038CF38(self + 0x10, m + 0x30) < 1.5f && *(u16 *)(self + 0x96) >= 3) {
        func_003C2EC0(*(u8 **)(self + 0xB8), 0, &st);
        t40 = *(vu0_v4 *)(self + 0xE0);
        v50 = st.v2;
        func_003C4098(self + 0xE0, &t40, &v50, 0.25f);
        func_0038CF68(self + 0xE0, self + 0xE0, 1.0f);
        func_0038D890(self + 0xC0, self + 0xC0, self + 0xE0, -0.76794493f);
        func_0038D890(self + 0xD0, self + 0xD0, self + 0xE0, -0.76794493f);
    } else {
        st.v0 = *(vu0_v4 *)D_L02_001D66B0;
        st.v0.z = 1.0f;
        st.v1 = *(vu0_v4 *)(self + 0xE0);
        func_003C4098(self + 0xE0, &st.v1, &st.v0, 0.041f);
        func_0038CF68(self + 0xE0, self + 0xE0, 1.0f);
        func_0038D890(self + 0xC0, self + 0xC0, self + 0xE0, -0.76794493f);
        func_0038D890(self + 0xD0, self + 0xD0, self + 0xE0, -0.76794493f);
    }
    {
        s32 id = *(s32 *)(m + 0x24);
        u8 *e;
        if (id == -1 || (e = D_001A30B0 + (id << 7), *(u8 **)(e + 0xDC) != self) || e[0xD0] == 0) {
            *(s32 *)(m + 0x24) = func_003A52A0(0, 4, self);
        }
    }
    func_003C2F58(self, 0, &st);
    func_0038CF68(&st.v1, m, 0.5f);
    func_0038CE20(&st.v1, &st.v1, 2.0f);
    st.v1.w = 5627.9248f;
    ub = func_00382348(*(u8 **)(self + 0xB8))[0x15];
    func_L01_00446760(&st.v2, self, 0x10001, &st.v1, (f32)ub);
    st.b39 = 1;
    st.h3a = *(u16 *)(self + 0xAA);
    st.b38 = 0;
    func_003D4D00(&st, 0.35f, 0, *(u8 **)(self + 0xB8), &st.v2);
    if (self[0x20] == 0) {
        *(u16 *)(self + 0x96) += 1;
        func_003C4138((f32 *)(m + 0x14), 0.1f, 0.0075f);
        len = func_0038CEA8(m);
        *(f32 *)(m + 8) = func_L01_00447878(self + 0x10, m + 0x30, 0, len, 0.0f);
        tbl = &D_L02_001DFA50;
        func_0038CF68(m, m, func_0038CEA8(m));
        vec_add_ba(self + 0x10, self + 0x10, m);
        vec_sub_ba(&v50, m + 0x30, self + 0x10);
        v50.z = 0.0f;
        func_0038CF68(&v60, m, 1.0f);
        func_L01_0044C280(m, m, &v50, 0, *(f32 *)(m + 0x14));
        p = tbl;
        for (i = 3; i >= 0; i--) {
            if (*p != 0) {
                *(s32 *)(*p + 0x98) = *(s32 *)(*(u8 **)(*p + 0x24) + 0x10);
                func_003C7C38(*p);
            }
            p++;
        }
        if (func_0038CF38(self + 0x10, m + 0x30) < 1.5f || func_L01_003FB640(&st, 2, self, 0.25f) != 0) {
            *(u16 *)(self + 0x96) = 0;
            self[0x20] = 1;
            *(vu0_v4 *)(m + 0x30) = *(vu0_v4 *)(*(u8 **)(self + 0xB8) + 0x10);
            *(f32 *)(m + 0x14) = 0.0025f;
        }
        p = tbl;
        for (i = 3; i >= 0; i--) {
            if (*p != 0) {
                *(s32 *)(*p + 0x98) = *(s32 *)(*(u8 **)(*p + 0x24) + 0x10);
                func_003C7C38(*p);
            }
            p++;
        }
        if (func_L01_003FB640(&st, 2, self, 0.25f) != 0) {
            *(u16 *)(self + 0x96) = 0;
            self[0x20] = 1;
            *(vu0_v4 *)(m + 0x30) = *(vu0_v4 *)(*(u8 **)(self + 0xB8) + 0x10);
            *(f32 *)(m + 0x14) = 1.0f;
        }
        func_L01_004CB358();
        if (func_0038CF38(self + 0x10, m + 0x30) > 4.0f) {
            if (*(s32 *)(m + 0x20) == D_001A4BE0.f25C0) {
                *(vu0_v4 *)(m + 0x30) = D_001A4BE0.vD0;
            } else {
                u8 *o = func_00382348(*(u8 **)(m + 0x20));
                *(vu0_v4 *)(m + 0x30) = *(vu0_v4 *)(*(u8 **)(m + 0x20) + 0x10);
                if (o != 0) *(f32 *)(m + 0x38) += *(f32 *)(o + 0x10);
            }
        }
    } else if (self[0x20] == 1) {
        *(u16 *)(self + 0x96) += 1;
        tgt = m + 0x30;
        pos = self + 0x10;
        func_003C4138((f32 *)(m + 0x14), 0.35f, 0.0075f);
        func_003C2F58(*(u8 **)(self + 0xB8), 0, &v50);
        *(vu0_v4 *)(m + 0x30) = v50;
        func_0038CF68(m, m, func_0038CEA8(m));
        vec_add_ba(self + 0x10, self + 0x10, m);
        vec_sub_ba(&v60, m + 0x30, self + 0x10);
        v60.z = 0.0f;
        func_0038CF68(&v70, m, 1.0f);
        func_L01_0044C280(m, m, &v60, 0, *(f32 *)(m + 0x14));
        *(f32 *)(m + 8) = func_L01_00447878(pos, tgt, 0, func_0038CEA8(m), 0.0f);
        if (func_0038CF38(pos, tgt) < 3.0f || *(u16 *)(self + 0x96) >= 0x12D) {
            s32 id;
            u8 *e;
            self[0x20] = 0;
            *(u16 *)(self + 0x96) = 0;
            if (*(u8 **)(m + 0x18) != 0) {
                func_003C2880(*(u8 **)(m + 0x18));
                *(s32 *)(m + 0x18) = 0;
            }
            if (*(u8 **)(m + 0x1C) != 0) {
                func_003C2880(*(u8 **)(m + 0x1C));
                *(s32 *)(m + 0x1C) = 0;
            }
            (*(u8 **)(self + 0xB8))[0xBC] = 0;
            id = *(s32 *)(m + 0x24);
            if (id != -1) {
                e = D_001A30B0_00352418 + (id << 7);
                if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(id);
                }
            }
            *(s32 *)(m + 0x24) = -1;
            *(u16 *)(self + 0x34) |= 2;
            return;
        }
    }
    if (*(u8 **)(m + 0x18) == 0) {
        *(u8 **)(m + 0x18) = func_003C24B0(0x175C, 0x80);
        func_L01_00456160(*(u8 **)(m + 0x18), self);
        *(u16 *)(*(u8 **)(m + 0x18) + 0x34) |= 2;
        *(u16 *)(*(u8 **)(m + 0x18) + 0x34) |= 4;
        *(u16 *)(*(u8 **)(m + 0x18) + 0x34) |= 0x100;
        (*(u8 **)(m + 0x18))[0x23] = 0x20;
        *(u8 **)(m + 0x1C) = func_003C24B0(0x175C, 0x80);
        func_L01_00456160(*(u8 **)(m + 0x1C), self);
        *(u16 *)(*(u8 **)(m + 0x1C) + 0x34) |= 2;
        *(u16 *)(*(u8 **)(m + 0x1C) + 0x34) |= 4;
        *(u16 *)(*(u8 **)(m + 0x1C) + 0x34) |= 0x100;
        (*(u8 **)(m + 0x1C))[0x23] = 0x10;
    } else {
        *(vu0_v4 *)(*(u8 **)(m + 0x18) + 0xC0) = *(vu0_v4 *)(self + 0xC0);
        *(vu0_v4 *)(*(u8 **)(m + 0x18) + 0xD0) = *(vu0_v4 *)(self + 0xD0);
        *(vu0_v4 *)(*(u8 **)(m + 0x18) + 0xE0) = *(vu0_v4 *)(self + 0xE0);
        *(vu0_v4 *)(*(u8 **)(m + 0x18) + 0x10) = *(vu0_v4 *)(self + 0x10);
        func_0038CF68(&v50, m, -0.5f);
        vec_add_ba(*(u8 **)(m + 0x18) + 0x10, *(u8 **)(m + 0x18) + 0x10, &v50);
        func_003C7C38(*(u8 **)(m + 0x18));
        *(vu0_v4 *)(*(u8 **)(m + 0x1C) + 0xC0) = *(vu0_v4 *)(self + 0xC0);
        *(vu0_v4 *)(*(u8 **)(m + 0x1C) + 0xD0) = *(vu0_v4 *)(self + 0xD0);
        *(vu0_v4 *)(*(u8 **)(m + 0x1C) + 0xE0) = *(vu0_v4 *)(self + 0xE0);
        vec_add_ba(*(u8 **)(m + 0x1C) + 0x10, *(u8 **)(m + 0x18) + 0x10, &v50);
        func_003C7C38(*(u8 **)(m + 0x1C));
    }
    if ((D_L02_001DE4C0 & 1) == 0) func_L02_00352320((void *)self);
    func_L01_00404808((void (*)(void *))func_L02_00352208, self);
}
/* localdecomp:end func_L02_00352418 */
