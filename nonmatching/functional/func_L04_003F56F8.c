/* functional: high. Checked at L04 (file's own flags): every call, constant, offset, global and branch matches, callee-saved registers match; 223 diff lines are 1-instruction scheduling shifts (a li/lbu order, a lhu register, delay slot moves). Needs func_L04_003F5AF8 declared (defined later in file as u8 return). */
/* localdecomp:start func_L04_003F56F8 */
extern u8 D_001A4BE0[];
typedef int s128_003F56F8 __attribute__((mode(TI)));
extern u8 D_001D5530[];
extern u8 D_001BBC40[];
extern u8 D_001CCFD0[];
extern u8 D_001A4C60[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001DF75C_sda;
__asm__(".extern D_001DF75C_sda, 4");
__asm__(".extern D_L04_001DFB38, 4");
extern s32 D_L04_001DFB38;
extern void func_L01_00445F40(void *, s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_0043B510(s32);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern u8 func_L04_003F5AF8(u8 *);
extern void func_L04_003F5B78(u8 *);
extern void func_L04_003F5E38(u8 *);
extern void func_003A1798(void);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CB00(void *);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_0039EC28(s32, s32);

void func_L04_003F56F8(u8 *self) {
    u8 *m = *(u8 **)(self + 0x68);
    s32 state;
    if (self[0x20] == 0) {
        s32 k1, k2;
        switch ((s16)(*(u16 *)(self + 0xAA) - 0x1F4B)) {
        case 0: k1 = 0x21; break;
        case 1: k1 = 0x1F; break;
        case 2: k1 = 0x22; break;
        case 3: k1 = 0x20; break;
        case 4: k1 = 0x23; break;
        default: k1 = 0xFF; break;
        }
        m[0x1E] = k1;
        k2 = m[0x1E];
        if (k2 == 0xFF || D_001D5530[k2] != 0) {
            func_003C2880(self);
            return;
        }
        {
            state = *(s16 *)(self + 0xAA);
            if (state != 0x1F4B) {
                func_L01_00445F40(self, 0x1F4B);
                func_L01_00446058(self, state, 0x1F4B);
                *(u16 *)(self + 0x34) &= 0xFFBF;
                *(f32 *)(self + 0x48) = 1.0f;
            }
        }
        *(s128_003F56F8 *)m = *(s128_003F56F8 *)(self + 0x10);
        *(f32 *)(m + 0x10) = *(f32 *)(self + 0xF8);
        *(f32 *)(self + 0xF4) = -1.5707964f;
        *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + 1.0f;
        *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * 3.0f;
        if (m[0x1F] != 0) {
            self[0x31] = 0;
            *(u16 *)(self + 0x34) |= 1;
            func_L01_004450F0(self, 1, -1);
        } else {
            func_L01_004450F0(self, 2, -1);
        }
    }
    state = self[0x20];
    switch (state) {
    case 1:
        if (func_L01_00456250(self) == 0) {
            if (self[0xB0] == 0xFF) {
                return;
            }
            if (!(D_001BBC40[self[0xB0] + (D_001D545C_sda << 4)] & 0x80)) {
                return;
            }
        }
        if (self[0xB0] != 0xFF) {
            func_L01_0043B510(self[0xB0]);
        }
        self[0x31] = state;
        *(u16 *)(self + 0x34) &= 0xFFFE;
        func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (D_001D5530[m[0x1E]] != 0) {
            func_003C2880(self);
        } else {
            *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), 0.083333336f);
            if (func_L04_003F5AF8(self)) {
                func_L04_003F5B78(self);
            }
        }
        break;
    case 3: {
        u8 *g;
        if (*(s16 *)(D_001CCFD0 + 0x76) == 0) {
            if (*(s16 *)(D_001CCFD0 + 0x9E) == state && *(s16 *)(D_001CCFD0 + 0x98) < 0x1B58) {
                func_003A1798();
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        state = 1;
        D_L04_001DFB38 = state;
        func_L04_003F5E38(self);
        *(s128_003F56F8 *)(self + 0x10) = *(s128_003F56F8 *)(g + 0x80);
        *(s128_003F56F8 *)(self + 0xF0) = *(s128_003F56F8 *)(g + 0x90);
        if (*(s32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (self[0x42] == state) {
            if (self[0x60] & 2) {
                if (self[0x43]) {
                    func_003C3A10(self, 0, 0, 0);
                }
                self[0x31] = 0;
                *(u16 *)(self + 0x34) |= 1;
                func_L01_004450F0(self, 4, -1);
            }
        }
        break;
    }
    case 4:
        if (func_0038CB00(m + 0x1C)) {
            if (m[0x1E] != 0xFF) {
                func_L01_0044CCC8(m[0x1E]);
                func_0039EF28();
                func_L01_0044FC48(m[0x1E], 0);
            }
            D_001DF75C_sda = 0;
            func_L01_004F50C8(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_0039EC28(0, -1);
            func_003C2880(self);
        }
        break;
    }
}
/* localdecomp:end func_L04_003F56F8 */
