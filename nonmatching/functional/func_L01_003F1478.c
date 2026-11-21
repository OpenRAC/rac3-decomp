/* functional: high. 17 instruction positions differ at L01 (prologue load order and branch offsets only); same state machine, reads and calls. Timer count read as a volatile hardware register. */
extern s32 D_00143950[];
extern s32 D_001D56C0_sda;
extern s32 D_001D56C4_sda;
__asm__(".extern D_001D56C0_sda, 4");
__asm__(".extern D_001D56C4_sda, 4");
extern s32 D_L01_001DF948;
extern s32 D_L01_001D6694;
extern s8 D_L01_001E6DE1[];
extern void func_L01_00461818(void);
extern void func_L01_004B8ED0(void);
extern void func_L01_004BA278(void);
extern void func_L01_003F26E0(void);
extern s32 func_0012C908(s32);

void func_L01_003F1478(void) {
    s32 limit = 0x2580;
    s32 now = *(volatile s32 *)0x10000800;
    if (D_00143950[0] != 0) {
        limit = 0x2D00;
    }
    if (D_001D56C0_sda == 0) {
        if (limit < now) {
            D_001D56C4_sda = 0;
            D_001D56C0_sda = 1;
        }
    } else if (D_001D56C0_sda == 1) {
        if (D_001D56C4_sda >= 2) {
            D_001D56C4_sda = 0;
            D_001D56C0_sda = 2;
        }
    } else if (D_001D56C0_sda == 2) {
        if (D_001D56C4_sda >= 4 && !(limit < now)) {
            D_001D56C4_sda = 0;
            D_001D56C0_sda = 3;
        }
    } else if (D_001D56C0_sda == 3) {
        D_001D56C0_sda = 0;
        D_001D56C4_sda = 0;
    }
    D_001D56C4_sda++;
    if (D_001D56C0_sda == 0) {
        func_0012C908(0);
        D_L01_001DF948++;
    } else if (D_001D56C0_sda == 1) {
        D_L01_001DF948++;
    } else if (D_001D56C0_sda == 2) {
        if (limit < now) {
            D_001D56C4_sda = 0;
        }
        if (D_L01_001D6694 == 0) {
            func_L01_00461818();
            func_L01_004B8ED0();
        } else if (D_L01_001D6694 == 2) {
            if (D_L01_001E6DE1[0] == 0) {
                func_L01_00461818();
                func_L01_004BA278();
            }
        }
        func_L01_003F26E0();
        func_0012C908(0);
        D_L01_001DF948++;
    } else if (D_001D56C0_sda == 3) {
        func_0012C908(0);
        func_0012C908(0);
        D_L01_001DF948++;
    }
}
