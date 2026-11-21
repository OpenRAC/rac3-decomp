/* functional: medium. functional: medium. State machine reconstructed from the asm; jump table order inferred (not read); duplicated state blocks merged into shared code with a state test, behaviour identical */
typedef int u128_3CFB08 __attribute__((mode(TI)));
extern s32 func_L01_003D0530(u8 *, u8 *);
extern s32 func_L01_003D06E0(u8 *, u8 *);
extern void func_L01_003D0850(u8 *, u8 *);
extern void func_L01_003D09D0(u8 *, u8 *);
extern void func_L01_003D0B70(u8 *, u8 *);
extern void func_L01_003D0BD0(u8 *, u8 *);
extern void func_L01_003D0D48(u8 *, u8 *, s32);
extern void func_L01_003D1210(u8 *, u8 *);
extern void func_L01_003D1848(u8 *, u8 *);
extern void func_L01_003D18C0(u8 *, u8 *);
extern void func_L01_003D1A50(u8 *, u8 *);
extern void func_L01_003D1C60(u8 *, u8 *);
extern void func_L01_003D2158(u8 *, u8 *);
extern void func_L01_003D2278(u8 *, u8 *);
extern void func_L01_003D3090(u8 *, u8 *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00511A40(void *, f32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_0043B510(void);
extern void func_003A4F28(s32);
extern s32 func_0038CAD0(void *);
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 *D_L01_001E0100[];
extern u8 *D_L01_001E001C[];
extern s32 D_L01_001DFB40[];
extern s32 D_001DFB40_sda;
extern u8 *D_001E0100_sda;
extern u8 *D_001E001C_sda;
extern f32 D_001DF2A8_sda;
extern f32 D_001DF2BC_sda;
extern f32 D_001DF2C0_sda;
extern f32 D_001DF2C4_sda;
__asm__(".extern D_001DFB40_sda, 4");
__asm__(".extern D_001E0100_sda, 4");
__asm__(".extern D_001E001C_sda, 4");
__asm__(".extern D_001DF2A8_sda, 4");
__asm__(".extern D_001DF2BC_sda, 4");
__asm__(".extern D_001DF2C0_sda, 4");
__asm__(".extern D_001DF2C4_sda, 4");

void func_L01_003CFB08(u8 *self) {
    u8 *obj;
    u8 *G;
    u8 *e;
    u8 *p;
    u8 *ent;
    s32 st;
    s32 t;
    s32 r;
    s32 idx;
    f32 vec[4];
    f32 d, diff;

    obj = *(u8 **)(self + 0x68);
    st = self[0x20];
    if (st == 0) {
        func_L01_003D0530(self, obj);
        return;
    }
    if ((u32)(st - 1) >= 12) {
        return;
    }
    G = D_001A4BE0;
    switch (st) {
    case 1:
        if (*(s32 *)(obj + 0x2C) == -1 && *(s32 *)(obj + 0x40) == -1) {
            goto set2;
        }
        if (func_L01_003D06E0(self, obj) == 0) {
            return;
        }
set2:
        func_L01_004450F0((M3C7568 *)self, 2, -1);
        return;
    case 2:
        t = *(s32 *)(G + 0x25C4);
        if (t == 0x74 || t == 0x31 || t == 0x65) {
            return;
        }
        if (*(s32 *)(obj + 0xB4) != D_001DFB40_sda - 1) {
            if (*(s32 *)(obj + 0x6C) != -1 && func_00382380(G + 0x80, *(s32 *)(obj + 0x6C), 0) != 0) {
                goto reset;
            }
            if (func_00382380(G + 0x80, *(s32 *)obj, 0) == 0) {
                goto stamp;
            }
reset:
            func_L01_003D22A8((s32)self);
stamp:
            obj[0xB1] = 0;
            *(s32 *)(obj + 0xB4) = D_001DFB40_sda;
            return;
        }
        if (*(s32 *)(obj + 0x6C) != -1 && func_00382380(G + 0x80, *(s32 *)(obj + 0x6C), 0) != 0) {
            ent = D_001E0100_sda + (*(s32 *)(obj + 0x68) << 7);
            if (*(s32 *)(obj + 0x60) != 0) {
                func_L01_003D2158(self, obj);
                func_L01_004F50C8(ent + 0x30, ent + 0x70, 0x74, 1);
                func_L01_003D1848(self, obj);
                func_L01_003D09D0(self, obj);
                func_L01_003D1C60(self, obj);
                func_L01_003D0B70(self, obj);
                func_L01_003D0BD0(self, obj);
                func_L01_004450F0((M3C7568 *)self, 6, -1);
                return;
            }
            if (*(s32 *)(obj + 0x64) != -1) {
                func_L01_003D2158(self, obj);
            }
            func_L01_004F50C8(ent + 0x30, ent + 0x70, 0xB0, 1);
            func_L01_003D1848(self, obj);
            func_L01_003D09D0(self, obj);
            func_L01_003D0B70(self, obj);
            self[0x30] = 0xFF;
            *(s32 *)(obj + 0x44) = 0;
            *(s32 *)(obj + 0x38) = 0;
            *(u128_3CFB08 *)(obj + 0x150) = *(u128_3CFB08 *)(obj + 0x140);
            *(f32 *)(obj + 0x134) = *(f32 *)(obj + 0x54);
            func_L01_004450F0((M3C7568 *)self, 9, -1);
            return;
        }
        if (func_00382380(D_001A4C60, *(s32 *)obj, 0) == 0) {
            return;
        }
        func_L01_003D1848(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D1A50(self, obj);
        func_L01_003D0B70(self, obj);
        func_L01_004450F0((M3C7568 *)self, 3, -1);
        return;
    case 3:
    case 6:
        if (func_L01_004561B8(self) != 0) {
            t = *(s32 *)(obj + 0x28);
            if (t != -1) {
                p = D_L01_001E001C[0] + (t << 8) + 0x10;
            } else {
                p = self + 0x10;
            }
            *(f32 *)(obj + 0x130) = func_0038CE68(p, self + 0xC0);
            if (st == 6) {
                *(s32 *)(obj + 0xB4) = 0x43;
            }
        }
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        if (st == 3) {
            d = func_0038CE68(D_001A4C60, self + 0xC0);
            if (!(D_001DF2BC_sda < d - *(f32 *)(obj + 0x130))) {
                return;
            }
        } else {
            if (func_0038CAD0(obj + 0xB4) == 0) {
                return;
            }
        }
        func_0038CE20(vec, self + 0xC0, 20.0f);
        ent = D_L01_001E0100[0] + (*(s32 *)obj << 7);
        vec[0] = vec[0] + *(f32 *)(ent + 0x30);
        vec[1] = vec[1] + *(f32 *)(ent + 0x34);
        vec[2] = vec[2] + *(f32 *)(ent + 0x38);
        func_L01_00511A40(vec, *(f32 *)(self + 0xF8), 0);
        if (st == 3) {
            func_L01_003D0850(self, obj);
            func_L01_004450F0((M3C7568 *)self, 4, -1);
        } else {
            func_L01_004450F0((M3C7568 *)self, 7, -1);
        }
        return;
    case 4:
    case 7:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        if (st == 7) {
            func_L01_003D09D0(self, obj);
        }
        func_L01_003D18C0(self, obj);
        diff = func_0038CE68(D_001A4C60, self + 0xC0) - *(f32 *)(obj + 0x130);
        if (D_001DF2C0_sda < diff || (*(s32 *)(obj + 0x60) != 0 && D_001DF2C4_sda < diff)) {
            func_L01_005003D0(0x69, 1);
            func_L01_004450F0((M3C7568 *)self, st + 1, -1);
        }
        return;
    case 5:
    case 8:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        if (st == 8) {
            func_L01_003D09D0(self, obj);
        }
        func_L01_003D18C0(self, obj);
        ent = D_L01_001E0100[0] + (*(s32 *)obj << 7);
        if (!(*(f32 *)(G + 0x88) < *(f32 *)(ent + 0x38))) {
            return;
        }
        if (!(3.0f < *(f32 *)(G + 0x33C))) {
            return;
        }
        if (st == 8) {
            func_L01_003D2278(self, obj);
        }
        func_L01_005003D0(0xB0, 1);
        self[0x30] = 0xFF;
        func_L01_004450F0((M3C7568 *)self, st == 5 ? 10 : 9, -1);
        *(u128_3CFB08 *)(obj + 0x150) = *(u128_3CFB08 *)(obj + 0x140);
        *(f32 *)(obj + 0x134) = *(f32 *)(obj + 0x54);
        *(s32 *)(obj + 0x44) = 0;
        *(s32 *)(obj + 0x38) = 0;
        return;
    case 9:
        func_L01_003D1848(self, obj);
        if (func_L01_004561B8(self) != 0) {
            *(s32 *)(obj + 0xB4) = *(s32 *)(obj + 0xB8);
            func_L01_003D1A50(self, obj);
        }
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        func_L01_003D1210(self, obj);
        func_L01_003D0D48(self, obj, 1);
        if (func_0038CAD0(obj + 0xB4) != 0) {
            func_L01_003D0850(self, obj);
            func_L01_004450F0((M3C7568 *)self, 10, -1);
        }
        return;
    case 10:
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        func_L01_003D1848(self, obj);
        t = *(s32 *)(G + 0x25C4);
        if (t == 0xB0 || t == 0x16 || t == 0x39) {
            func_L01_003D1210(self, obj);
            if (D_001DF2A8_sda < *(f32 *)(G + 0x33C) ||
                (*(u8 **)(G + 0x35C) != 0 && (u32)(*(u16 *)(*(u8 **)(G + 0x35C) + 0xAA) - 0x191F) < 2)) {
                func_L01_003D0D48(self, obj, 1);
                idx = *(s32 *)(obj + 0x4C);
                if (idx != -1) {
                    e = D_001A30B0 + (idx << 7);
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                        goto call3090;
                    }
                }
                *(s32 *)(obj + 0x4C) = func_L01_004AAC98(2, 4, self, 0x1D84);
            } else {
                func_L01_003D0D48(self, obj, 0);
                idx = *(s32 *)(obj + 0x4C);
                if (idx != -1) {
                    e = D_001A30B0 + (idx << 7);
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(idx);
                    }
                }
                *(s32 *)(obj + 0x4C) = -1;
            }
call3090:
            func_L01_003D3090(self, obj);
            func_L01_003D18C0(self, obj);
            return;
        }
        if (*(s32 *)(obj + 0x24) != -1 && *(s32 *)(G + 0x2850) > 0) {
            func_L01_0043B510();
        }
        func_L01_003D0D48(self, obj, 0);
        idx = *(s32 *)(obj + 0x4C);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(obj + 0x4C) = -1;
        func_L01_004450F0((M3C7568 *)self, 12, -1);
        return;
    case 11:
        t = *(s32 *)(obj + 0x40);
        if (t != -1) {
            if ((*(u16 *)(D_001E001C_sda + (t << 8) + 0x34) & 2) == 0) {
                return;
            }
        }
        func_L01_004450F0((M3C7568 *)self, 1, -1);
        return;
    case 12:
        if (*(s32 *)(G + 0x360) != 0 && *(s16 *)(G + 0x36E) == 0) {
            if (obj[0xB0] == 0 && *(s32 *)(obj + 0x40) == -1) {
                func_003C2880((s32)self);
                return;
            }
            func_L01_004450F0((M3C7568 *)self, 11, -1);
            return;
        }
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        return;
    }
}
