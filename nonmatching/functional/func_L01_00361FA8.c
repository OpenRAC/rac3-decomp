/* functional: medium. 391 words differ (not byte exact, same frame size 0x110). Written from asm; all branches, constants and delay-slot stores traced. Unsure: func_0038D810 output size (declared s128[4]), exact prototypes of func_L01_0035F340/0038B9A8 (extra unread args/floats passed as in asm; gate should check), D_L01_001EAA18 treated as pointer var, D_001A4BE0_00361FA8 alias, local D_L01_ externs may need unifying */
/* VU0 helpers written with named vf clobbers (this file's flags lack the "j" register class) */
static __inline__ void qv_sub(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
static __inline__ void qv_add(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
extern u8 D_001A4BE0_00361FA8[];
extern u8 *D_L01_001EAA18;
extern u8 D_L01_001EAA20[];
extern u8 D_L01_001EAA40[];
extern u8 D_L01_001DAFF0;
extern u8 D_L01_001DD750[];
extern s32 D_L01_001E10F8;
extern s32 D_001D545C;
void func_L01_00361FA8(u8 *self) {
    extern void func_L01_004471A8(void *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_L01_004C8688(s32, void *, void *);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_0040E790(void *, void *, void *);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern s32 func_003C4B50(void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern f32 func_003824E0(f32, f32);
    extern void *func_L01_0035F340(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
    extern void *func_L01_0038B9A8(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_003C2880(void *);
    u8 *vars = *(u8 **)(self + 0x68);
    u8 *pos;
    u8 *hero;
    S_38C110v t0, t1, t2, t3, t4, prev;
    S_38C110v m[4];
    f32 half;

    func_L01_004471A8(self, 0.75f);
    switch (self[0x20]) {
    case 0:
        pos = self + 0x10;
        *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), 0.08377581089735031f);
        *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), 0.22689281404018402f);
        func_L01_004C7D98(pos, &t0);
        func_0038CF68(&t1, self + 0xE0, 1.0f);
        func_0038CE90(&t2, &t1, &t0);
        half = func_0038CE68(&t1, &t0) * 0.5f;
        func_0038CE20((s128 *)&t3, (s128 *)&t2, func_0038D0B0(half));
        t3.w = func_0038D098(half);
        func_0038D810(&t3, m);
        func_0038D5F0(self + 0xC0, m, self + 0xC0);
        prev = *(S_38C110v *)pos;
        qv_add(pos, pos, vars);
        func_L01_004C8688(*(s32 *)(vars + 0x44), vars, 0);
        func_L01_004C7D40(pos, vars, 0.004800000227987766f);
        if (func_L01_004CB2D8()) {
            func_L01_004CAB30(pos, pos);
        }
        hero = *(u8 **)(D_001A4BE0_00361FA8 + 0x25C0);
        *(s32 *)(hero + 0x98) = 0;
        if (func_003D3CB0(&prev, pos, 0, self, 0)) {
            s32 wall = 0;
            if (D_L01_001EAA18 == 0) {
                wall = 1;
            } else {
                s32 cls = *(s16 *)(D_L01_001EAA18 + 0xAA);
                if (cls == 0x1865 || cls == 0 || cls == 0x1885) {
                    func_L01_004450F0(self, 0, -1);
                } else if (func_003C4B50(D_L01_001EAA18)) {
                    wall = 1;
                } else {
                    func_L01_004450F0(self, 1, -1);
                }
            }
            if (wall) {
                func_L01_004450F0(self, 2, -1);
                *(s32 *)(vars + 0x4C) = 8;
                *(S_38C110v *)(vars + 0x30) = *(S_38C110v *)D_L01_001EAA40;
                func_L01_0040E790(vars, vars, vars + 0x30);
            }
        }
        hero = *(u8 **)(D_001A4BE0_00361FA8 + 0x25C0);
        *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
        if (func_L01_003FB640(pos, 0, *(u8 **)(D_001A4BE0_00361FA8 + 0x25C0), 1.5f)) {
            u8 *p = D_L01_001EAA18;
            if (p != 0 && !func_003C4B50(p) && p != 0 && *(u8 **)(p + 0x24) != 0
                && (*(u8 **)(p + 0x24))[0x46] == 5 && *(s16 *)(p + 0xAA) != 0x1AE6) {
                func_L01_004450F0(self, 1, -1);
            }
        }
        if (D_L01_001DAFF0 != 0 && D_001D545C == 5) {
            if (*(f32 *)(self + 0x18) <= 32.5f) {
                func_L01_004450F0(self, 1, -1);
            } else if (400.0f < func_L01_0040E570(D_L01_001DD750, pos)) {
                func_L01_004450F0(self, 1, -1);
            }
        }
        func_L01_004C7D98(pos, &t4);
        func_0038CF68(&t4, &t4, -1.0f);
        qv_add(&t4, pos, &t4);
        func_0038CAD0(vars + 0x48);
        if (*(s32 *)(vars + 0x48) < 10) {
            if (func_003D3CB0(pos, &t4, 0, self, 0)) {
                func_L01_004450F0(self, 1, -1);
            }
        }
        break;
    case 1:
        pos = self + 0x10;
        func_L01_004C7D98(pos, &t4);
        func_0038CF68(&t4, &t4, -20.0f);
        qv_add(&t4, &t4, pos);
        if (func_003D3CB0(pos, &t4, 2, self, 0)) {
            *(S_38C110v *)&t4 = *(S_38C110v *)D_L01_001EAA20;
        }
        if (*(s32 *)(vars + 0x50) == 0) {
            func_003824E0(0.01745329424738884f, 0.03490658849477768f);
            func_L01_0035F340(*(void **)(vars + 0x54), pos, &t4, 0x18, 0x41, 0x1AFF2020, 0x1AFF2020, 0xFF2020, 0xFF2020, 100, *(s32 *)(vars + 0x58),
                              0.09000000357627869f, 5.0f, 1.5f, 0.0f);
        } else {
            func_003824E0(0.01745329424738884f, 0.03490658849477768f);
            func_L01_0038B9A8(pos, &t4, vars, 0x18, 0x41, 0x1AFF2020, 0x1AFF2020, 0xFF2020, 0xFF2020, 100,
                              0.09000000357627869f, 5.0f, 1.5f, 0.0f);
        }
        func_003A52A0(0, 0, self);
        D_L01_001E10F8 = 0;
        func_003C2880(self);
        break;
    case 2:
        if (func_0038CAD0(vars + 0x4C) != 0) {
            func_L01_004450F0(self, 1, -1);
        } else {
            pos = self + 0x10;
            qv_add(pos, pos, vars);
            func_L01_004C8688(*(s32 *)(vars + 0x44), vars, 0);
            func_L01_004C7D40(pos, vars, 0.004800000227987766f);
            func_L01_004CAB30(pos, pos);
        }
        break;
    case 3:
        D_L01_001E10F8 = 0;
        func_003C2880(self);
        break;
    }
}
