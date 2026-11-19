/* functional: medium-high. Written from the PAL asm only (no draft); 24-state boss/enemy state machine via the jump table at 0x2C0210 (state-1 indexes it, states 21-23 share a target); spawn burst of state 5 mirrors the matched twin in L07_003BC4D8.c. Notes: (1) retail passes a float in $f12 to func_L07_003535E8 (25.0/30.0/15.5) which the callee forwards to func_L01_0044E1B8, so its C must take (u8 *, f32); (2) shot[3] (w) is left unset as in retail. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[];
extern void func_L01_0045A9F0(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L06_003584D0(u8 *, void *, void *, void *, s32, s32, f32);
extern void func_L07_003315B0(void *);
extern void func_L07_00352E88(u8 *);
extern void func_L07_00352F30(u8 *, f32);
extern void func_L07_00352FF0(u8 *, f32);
extern void func_L07_003532D0(u8 *);
extern void func_L07_003538A0(u8 *);
extern void func_L07_00353980(u8 *);
extern void func_L07_00353AB0(u8 *);
extern void func_L07_00353178(u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003537B0(u8 *);
extern void func_L07_003535E8(u8 *, f32);

void func_L07_00351C58(u8 *self) {
    u8 *v;
    s32 r;
    f32 f, ang, clamp;
    f32 pos[4] __attribute__((aligned(16)));
    f32 shot[4] __attribute__((aligned(16)));
    f32 hand[4] __attribute__((aligned(16)));

    if (self[0x20] == 0) {
        func_L07_00352510(self);
    }
    func_L07_00352758(self);
    v = *(u8 **)(self + 0x68);
    if ((u32)(self[0x20] - 1) >= 0x18) {
        return;
    }
    switch (self[0x20]) {
    case 1:
        return;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(v + 0x24E)) {
            func_L07_00352AC8((s32)self, 3);
        }
        return;
    case 3:
        func_L01_0045A9F0(self);
        func_L07_00352AC8((s32)self, 4);
        return;
    case 4:
        func_L01_0045A748(self, *(u8 **)(v + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(v + 0x240) + 0x10, self + 0x10) < 484.0f) {
            v[0x25E] = 1;
            func_L07_00352AC8((s32)self, 6);
        }
        return;
    case 5:
        func_L01_0045A9F0(self);
        r = func_L01_00454370(self, v + 0x70);
        if (r & 1) {
            *(u128_t *)pos = *(u128_t *)(self + 0x10);
            pos[2] += *(f32 *)(v + 0x40);
            func_L01_003303B8(pos, 0, 0xA, 5, 4, 0xA, 0xF, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00451FE0(self, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L07_003315B0(self);
            func_003A52A0(9, 0, self);
            return;
        }
        if (r & 2) {
            if (v[0x25E] == 0) {
                func_L07_00352AC8((s32)self, 4);
            } else if (self[0x94] < 7) {
                func_L07_00352AC8((s32)self, 6);
            } else {
                func_L07_00352AC8((s32)self, 7);
            }
        }
        return;
    case 6:
        func_L01_0045A9F0(self);
        if (func_L07_00331008(*(s32 *)(v + 0x240), (s32)self)) {
            func_L07_00352AC8((s32)self, 7);
        } else {
            func_L07_00352AC8((s32)self, 0x18);
        }
        return;
    case 7:
        func_L01_0045A9F0(self);
        r = func_L07_00353378(self, 0);
        if (r == -1) {
            return;
        }
        v[0x466] = 0;
        v[0x465] = 1;
        v[0x464] = r;
        func_L07_003532D0(self);
        return;
    case 8:
        func_L07_00352FF0(self, 6.0f);
        return;
    case 9:
        func_L07_00352FF0(self, 10.0f);
        return;
    case 10:
        func_L07_00352E88(self);
        if (self[0x60] & 2) {
            func_L07_00352AC8((s32)self, 0xB);
        }
        return;
    case 11:
        func_L07_00352FF0(self, -1.0f);
        return;
    case 12:
        if (self[0x60] & 2) {
            func_L07_00352AC8((s32)self, v[0x464] + 0xD);
        }
        return;
    case 13:
        ang = func_0038D160(*(f32 *)(v + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(v + 0x134) - *(f32 *)(self + 0x14));
        func_L01_0045AA10(self, ang);
        if (v[0x466] == 0) {
            f = func_L01_004395E0(self);
            if (14.0f <= f && f <= 24.0f) {
                func_L07_003538A0(self);
            }
        }
        func_L07_003535E8(self, 25.0f);
        return;
    case 14:
        func_L01_0045A9F0(self);
        if (v[0x466] == 0) {
            f = func_L01_004395E0(self);
            if (12.0f <= f && f <= 20.0f) {
                func_L07_00353980(self);
            }
        }
        func_L07_003535E8(self, 25.0f);
        return;
    case 15:
        func_L01_0045A9F0(self);
        if (v[0x466] == 0) {
            f = func_L01_004395E0(self);
            if (15.0f <= f && f <= 21.0f) {
                func_L07_00353AB0(self);
            }
        }
        func_L07_003535E8(self, 30.0f);
        return;
    case 16:
        if (v[0x466] == 0) {
            f = func_L01_004395E0(self);
            if (22.0f <= f && f <= 26.0f) {
                func_L07_00353AB0(self);
            }
        }
        func_L07_00353178(self, 13, 0, 1, func_L01_004395E0(self), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        ang = func_0038D160(*(f32 *)(v + 0x130) - *(f32 *)(self + 0x10), *(f32 *)(v + 0x134) - *(f32 *)(self + 0x14));
        func_L01_00448890(self + 0xF8, v + 0x204, ang, *(f32 *)(v + 0x164), *(f32 *)(v + 0x168), *(f32 *)(v + 0x16C), 0);
        func_L07_003535E8(self, 30.0f);
        return;
    case 17:
        func_L01_0045A9F0(self);
        if (func_L01_0044E1B8(self, 14.0f) && self[0x42] == 14) {
            func_003C2F58(self, 4, hand);
            ang = func_0038D160(*(f32 *)(v + 0x130) - hand[0], *(f32 *)(v + 0x134) - hand[1]);
            clamp = func_0038DB00(ang, *(f32 *)(self + 0xF8));
            if (clamp > 0.7853982f) {
                clamp = 0.7853982f;
            } else if (clamp < -0.7853982f) {
                clamp = -0.7853982f;
            }
            clamp = func_0038DAB8(*(f32 *)(self + 0xF8), clamp);
            shot[0] = func_0038D098(clamp) * 1.0000001f;
            shot[1] = func_0038D0B0(clamp) * 1.0000001f;
            *(s32 *)&shot[2] = 0;
            func_L06_003584D0(self, shot, hand, self + 0xF0, 0x10001, 1, 1.0f);
        }
        func_L07_003535E8(self, 15.5f);
        return;
    case 18:
        func_L07_00353178(self, 8, 1, 1, func_L01_004395E0(self), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_00353730((s32)self);
        return;
    case 19:
        func_L07_00353178(self, 7, 1, -1, func_L01_004395E0(self), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_00353730((s32)self);
        return;
    case 20:
        func_L07_00353178(self, 9, 0, -1, func_L01_004395E0(self), 1.5f, 3.0f, 8.0f, 24.0f, 16.0f);
        func_L07_00353730((s32)self);
        return;
    case 21:
    case 22:
    case 23:
        func_L07_003537B0(self);
        return;
    case 24:
        func_L07_00352F30(self, 5.5f);
        if (func_L07_00331008(*(s32 *)(v + 0x240), (s32)self)) {
            func_L07_00352AC8((s32)self, 6);
        } else if (func_L01_0040E570(self + 0x10, v + 0x130) < 36.0f) {
            func_L07_00353498((s32)self);
        }
        return;
    }
}
