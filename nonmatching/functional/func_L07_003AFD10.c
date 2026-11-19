/* functional: high. From the P03 reconstruction draft (marked 'needs behaviour review'); I reviewed all 7 states line by line against PAL asm and found ONE bug: in state 4, the release test when angle>pi/2 must still call func_L01_00456500(...,p[0x88]) (draft released immediately when p[0x88]==-1); fixed. Everything else (audio slot guard idx==-1/owner/active byte, 3A52A0 args 3/0/1/3, timers 50/50/10, thresholds, jump to states) matches. 455 diff lines = scheduling/frame. */
extern s32 func_L07_003B05B0(void *);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L07_003B0738(void *);
extern void func_L07_003B0660(void *);
extern void func_L01_00404A10(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_003AA018(void *, void *, void *, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003B0970(void *);
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
static __inline__ s32 active_AFD10(u8 *self, s32 index) {
    u8 *slot;
    if (index == -1) return 0;
    slot = D_001A30B0 + index * 128;
    return *(u8 **)(slot + 0xDC) == self && slot[0xD0] != 0;
}
static __inline__ void release_AFD10(u8 *self, u8 *p) {
    s32 index = *(s32 *)(p + 0x7C);
    if (index != -1) {
        u8 *slot = D_001A30B0 + index * 128;
        if (*(u8 **)(slot + 0xDC) == self && slot[0xD0]) func_003A4F28(index);
    }
    *(s32 *)(p + 0x7C) = -1;
}
void func_L07_003AFD10(u8 *self) {
    vu0_v4 position, direction;
    u8 *p = *(u8 **)(self + 0x68);
    f32 angle;
    if (func_L07_003B05B0(self)) {
        func_003C2880(self);
        return;
    }
    switch (self[0x20]) {
    case 1:
        if (func_L01_004561B8(self) && self[0x43] != 0) func_003C3A10(self, 0, 0, 8);
        if (*(s32 *)(p + 0x80) != -1) {
            if (func_L01_00456500(D_001A4C60, *(s32 *)(p + 0x80)))
                func_L01_004450F0(self, 2, -1);
        } else if (func_0038CF38(self + 0x10, D_001A4C60) < *(f32 *)(p + 0x84))
            func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(self)) {
            if (*(s32 *)(p + 0x7C) == -1 ||
                *(u8 **)(D_001A30B0 + *(s32 *)(p + 0x7C) * 128 + 0xDC) != self ||
                !(D_001A30B0 + *(s32 *)(p + 0x7C) * 128)[0xD0])
                *(s32 *)(p + 0x7C) = func_003A52A0(3, 4, self);
            if (self[0x43] != 1) func_003C3A10(self, 1, 0, 0);
        }
        if (self[0x60] & 2) {
            release_AFD10(self, p);
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) && self[0x43] != 2) func_003C3A10(self, 2, 0, 0);
        if (func_0038DBA0(*(f32 *)(self + 0xF8), *(f32 *)(p + 0x90)) <= 0.017453292f)
            func_L01_004450F0(self, 7, -1);
        else func_L01_00448890(self + 0xF8, p + 0x94, 0, *(f32 *)(p + 0x90),
                              0.004f, 0.004f, 0.6f);
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            if (*(s32 *)(p + 0x7C) == -1 ||
                *(u8 **)(D_001A30B0 + *(s32 *)(p + 0x7C) * 128 + 0xDC) != self ||
                !(D_001A30B0 + *(s32 *)(p + 0x7C) * 128)[0xD0])
                *(s32 *)(p + 0x7C) = func_003A52A0(0, 4, self);
            if (self[0x43] != 2) func_003C3A10(self, 2, 0, 0);
            *(s32 *)(p + 0xA0) = 50;
        }
        angle = func_0038DB00(func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(self + 0x10),
                                          *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(self + 0x14)),
                             *(f32 *)(p + 0x90));
        if (angle > 0.7853982f) angle = 0.7853982f;
        else if (angle < -0.7853982f) angle = -0.7853982f;
        angle = func_0038DAB8(*(f32 *)(p + 0x90), angle);
        func_L01_00448890(self + 0xF8, p + 0x94, 0, angle, 0.004f, 0.004f, 0.6f);
        func_L07_003B0738(self);
        func_L01_00404A10(func_L07_003B0660, self);
        if (func_0038CAD0(p + 0xA0)) {
            release_AFD10(self, p);
            func_L01_004450F0(self, 5, -1);
        } else {
            angle = func_0038DBA0(func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(self + 0x10),
                                              *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(self + 0x14)),
                                 *(f32 *)(p + 0x90));
            if (angle > 1.5707964f || *(s32 *)(p + 0x88) != -1
                    ? !func_L01_00456500(D_001A4BE0 + 0x80, *(s32 *)(p + 0x88))
                    : func_0038CF38(self + 0x10, D_001A4BE0 + 0x80) > *(f32 *)(p + 0x8C)) {
                release_AFD10(self, p);
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(self)) {
            if (*(s32 *)(p + 0x7C) == -1 ||
                *(u8 **)(D_001A30B0 + *(s32 *)(p + 0x7C) * 128 + 0xDC) != self ||
                !(D_001A30B0 + *(s32 *)(p + 0x7C) * 128)[0xD0])
                *(s32 *)(p + 0x7C) = func_003A52A0(1, 4, self);
            if (self[0x43] != 3) func_003C3A10(self, 3, 0, 0);
            *(s32 *)(p + 0xA0) = 50;
            func_0038CF68(&direction, self + 0xC0, 1.0000001f);
            func_003C2F58(self, 1, &position);
            func_L01_003AA018(self, &direction, &position, 1, (f32)p[0x44]);
        }
        if (func_0038CAD0(p + 0xA0)) {
            release_AFD10(self, p);
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(self)) {
            p[0xA8] = 1;
            if (self[0x43] != 4) func_003C3A10(self, 4, 0, 0);
        }
        if (self[0x60] & 2) func_L01_004450F0(self, 7, -1);
        break;
    case 7:
        if (func_L01_004561B8(self)) {
            if (*(s32 *)(p + 0x7C) == -1 ||
                *(u8 **)(D_001A30B0 + *(s32 *)(p + 0x7C) * 128 + 0xDC) != self ||
                !(D_001A30B0 + *(s32 *)(p + 0x7C) * 128)[0xD0])
                *(s32 *)(p + 0x7C) = func_003A52A0(3, 4, self);
            if (self[0x43] != 0) func_003C3A10(self, 0, 0, 8);
            *(s32 *)(p + 0xA0) = 10;
        }
        if (p[0xA8]) func_L07_003B0970(self);
        if (func_0038CAD0(p + 0xA0)) release_AFD10(self, p);
        break;
    }
}
