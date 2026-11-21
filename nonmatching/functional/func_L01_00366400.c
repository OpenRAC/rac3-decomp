/* functional: medium. 493 words differ; jump table read from the level ELF (6 entries 3665C0, 3666D8, 366724, 366834, 3669D8, 366A38), every state traced from asm incl. delay-slot stores; unsure: D_L01_001E1CC4 vtable call (func_L01_0043B568 result +4 called with (D_1E1CC4, self, 0)), types of D_L01_001E1Cxx globals, weapon identity guessed */
typedef int Q_00366400 __attribute__((mode(TI)));
extern u8 D_001A4BE0_00366400[];
extern u8 D_001A30B0[];
extern u8 *D_L01_001E1CC4;
extern s32 D_L01_001E1CC0, D_L01_001E1CC8, D_L01_001E1CCC, D_L01_001E1CD0, D_L01_001E1CD4, D_L01_001E1D00;
extern s32 D_L01_001E1B60[], D_L01_001E1B70[], D_L01_001E1B80[];
extern f32 D_L01_001E1C20, D_L01_001E1C28, D_L01_001E1C68;
extern s32 D_L01_001E1C24, D_L01_001E1C60, D_L01_001E1C6C;
extern u8 D_L01_001E1C70[], D_L01_001E1C74[], D_L01_001E1C80[];
extern Q_00366400 D_L01_001E1CE0, D_L01_001E1CF0;
static void slot_free_00366400(u8 *self, s32 *p) {
    extern void func_003A4F28(s32);
    s32 idx = *p;
    if (idx != -1) {
        u8 *slot = D_001A30B0 + (idx << 7);
        if (*(u8 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *p = -1;
}
static s32 slot_bad_00366400(u8 *self, s32 idx) {
    u8 *slot;
    if (idx == -1) {
        return 1;
    }
    slot = D_001A30B0 + (idx << 7);
    return *(u8 **)(slot + 0xDC) != self || slot[0xD0] == 0;
}
void func_L01_00366400(u8 *self) {
    extern void *func_L01_0043B568(s32, s32, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00366E48(void *, void *, void *, void *, s32);
    extern void func_L01_00366EA8(void *, void *, void *, s32, s32);
    extern void func_L01_00366DE0(void);
    extern void func_L01_00366BE0(void *);
    extern void func_L01_00366CD0(void);
    extern void func_L01_00367780(void *);
    extern void func_L01_00367EE0(void *);
    extern void func_L01_00368B30(void);
    extern void func_L01_00404A10(void *, void *);
    u8 *hb = D_001A4BE0_00366400;
    s32 *sA = (s32 *)(hb + 0x27D4);
    s32 *sB = (s32 *)(hb + 0x27D8);
    s32 *sC = (s32 *)(hb + 0x27DC);
    s32 i;
    s32 any;
    f32 t;

    if (*(s32 *)(hb + 0x1224) == 3 || *(s32 *)(hb + 0x25C4) == 0x74) {
        if (D_L01_001E1CC4 != 0) {
            void **vt = (void **)func_L01_0043B568(0x1860, 0, 8);
            ((void (*)(void *, void *, s32))vt[1])(D_L01_001E1CC4, self, 0);
            D_L01_001E1CC4 = 0;
        }
        slot_free_00366400(self, sA);
        slot_free_00366400(self, sB);
        slot_free_00366400(self, sC);
        return;
    }
    if (slot_bad_00366400(self, *sA)) {
        *sA = func_003A52A0(1, 4, self);
    }
    switch (self[0x20] < 6 ? self[0x20] : 6) {
    case 0:
        for (i = 0; i < 4; i++) {
            D_L01_001E1B60[i] = 0;
            D_L01_001E1B70[i] = -1;
            D_L01_001E1B80[i] = 0;
        }
        D_L01_001E1C28 = 0.75f;
        D_L01_001E1C68 = 1.0f;
        D_L01_001E1C20 = 0.0f;
        D_L01_001E1C24 = 0;
        D_L01_001E1C60 = 0;
        func_L01_00366E48(self, D_L01_001E1C70, D_L01_001E1C74, D_L01_001E1C80, 0);
        D_L01_001E1CC0 = 0;
        D_L01_001E1CC4 = 0;
        D_L01_001E1CC8 = 0;
        D_L01_001E1CCC = 0;
        D_L01_001E1CD0 = 0;
        D_L01_001E1CD4 = 0;
        D_L01_001E1D00 = 0;
        D_L01_001E1CE0 = *(Q_00366400 *)(self + 0x10);
        D_L01_001E1C6C = 12;
        D_L01_001E1CF0 = *(Q_00366400 *)(self + 0x10);
        func_003A52A0(0, 0, self);
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        if (func_0038CAD0(&D_L01_001E1C6C) != 0) {
            func_L01_004450F0(self, 2, -1);
        } else {
            if ((u32)(*(s32 *)(hb + 0x25C4) - 0x17) >= 4) {
                return;
            }
            func_L01_004450F0(self, 5, -1);
            return;
        }
        break;
    case 2:
        if ((u32)(*(s32 *)(hb + 0x25C4) - 0x17) < 4) {
            func_L01_004450F0(self, 4, -1);
        } else {
            if (D_L01_001E1C28 < 1.2000000476837158f) {
                t = D_L01_001E1C28 + 0.03999999910593033f;
                D_L01_001E1C28 = t;
                if (1.2000000476837158f < t) {
                    D_L01_001E1C28 = 1.2000000476837158f;
                }
            }
            if (D_L01_001E1C68 < 14.0f) {
                t = D_L01_001E1C68 + 0.48000001907348633f;
                D_L01_001E1C68 = t;
                if (14.0f < t) {
                    D_L01_001E1C68 = 14.0f;
                }
            }
            if (D_L01_001E1C28 == 1.2000000476837158f && D_L01_001E1C68 == 14.0f) {
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 3:
        if (D_L01_001E1D00 == 1) {
            if (slot_bad_00366400(self, *sB)) {
                *sB = func_003A52A0(2, 4, self);
            }
        } else {
            slot_free_00366400(self, sB);
        }
        any = D_L01_001E1B80[0] != 0;
        for (i = 1; !any && i < 4; i++) {
            if (D_L01_001E1B80[i] != 0) {
                any = 1;
            }
        }
        if (any) {
            if (slot_bad_00366400(self, *sC)) {
                *sC = func_003A52A0(3, 4, self);
            }
        } else {
            slot_free_00366400(self, sC);
        }
        if ((u32)(*(s32 *)(hb + 0x25C4) - 0x17) < 4) {
            func_L01_004450F0(self, 4, -1);
            t = D_L01_001E1C68 - 0.8400000333786011f;
            D_L01_001E1C68 = t;
            if (t < 1.0f) {
                D_L01_001E1C68 = 1.0f;
                D_L01_001E1C28 = 0.75f;
                func_L01_004450F0(self, 5, -1);
            }
        }
        break;
    case 4:
        t = D_L01_001E1C68 - 0.8400000333786011f;
        D_L01_001E1C68 = t;
        if (t < 1.0f) {
            D_L01_001E1C68 = 1.0f;
            D_L01_001E1C28 = 0.75f;
            func_L01_004450F0(self, 5, -1);
        }
        break;
    case 5:
        slot_free_00366400(self, sA);
        slot_free_00366400(self, sB);
        slot_free_00366400(self, sC);
        if ((u32)(*(s32 *)(hb + 0x25C4) - 0x17) < 4) {
            return;
        }
        D_L01_001E1C6C = 12;
        func_L01_004450F0(self, 1, -1);
        break;
    default:
        break;
    }
    func_0038CAD0(&D_L01_001E1CC0);
    func_L01_00366EA8(D_L01_001E1C70, D_L01_001E1C74, D_L01_001E1C80, 1, D_L01_001E1C20 > 0.0f);
    func_L01_00366DE0();
    func_L01_00366BE0(self);
    func_L01_00366CD0();
    func_L01_00367780(self);
    func_L01_00367EE0(self);
    func_L01_00404A10(func_L01_00368B30, *(u8 **)(hb + 0x25C0));
}
