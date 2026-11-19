/* functional: high. Retail reads the pad words as one 64-bit ld at +0x1C0 with masks 0x8004<<32 and 0x2008<<32; I use the equivalent 32-bit read of the high word at +0x1C4 (2.95 rejects the wide mask); loop bodies match the asm; reg alloc/frame differ */
typedef struct { u8 pad0[0x1C4]; u32 w1C4; } Pad_0049E228;
extern Pad_0049E228 *D_001D52FC[];
extern E_49E5B8 D_L01_002EC758[];
extern s32 D_001D94C8_sda;
__asm__(".extern D_001D94C8_sda, 4");
extern s32 D_001D94C4_sda;
__asm__(".extern D_001D94C4_sda, 4");
extern void func_L01_0049E000(void *);
extern s32 func_L01_0049B550(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(void *);

void func_L01_0049E228(void *arg) {
    s32 orig = D_001D94C8_sda;
    s32 go = 1;

    if (orig >= 0) {
        if (D_001D52FC[0]->w1C4 & 0x8004) {
            do {
                D_001D94C8_sda = D_001D94C8_sda - 1;
                if (D_001D94C8_sda < 0) {
                    D_001D94C8_sda = orig;
                    go = 0;
                } else if (D_L01_002EC758[D_001D94C8_sda].x14 != 0 || D_001D94C4_sda != 0) {
                    go = 0;
                }
            } while (go);
        } else if (D_001D52FC[0]->w1C4 & 0x2008) {
            do {
                D_001D94C8_sda = D_001D94C8_sda + 1;
                if (D_L01_002EC758[D_001D94C8_sda].x0 == 0) {
                    D_001D94C8_sda = orig;
                    go = 0;
                } else if (D_L01_002EC758[D_001D94C8_sda].x14 != 0 || D_001D94C4_sda != 0) {
                    go = 0;
                }
            } while (go);
        } else if (D_001D52FC[0]->w1C4 & 0x40) {
            func_L01_0049E000(arg);
        }
    }
    if (D_001D52FC[0]->w1C4 & 0x910) {
        func_L01_00517748(func_L01_0049B550());
        func_L01_00516090(arg);
    }
}
