/* functional: high. Delay loop kept as an empty loop (retail uses raw branch to avoid ee-as padding); 32 diff only in scheduling */
extern u8 D_001D5530[];
extern s32 D_00143050[];

void func_L01_0044CCC8(s32 id) {
    s32 i;
    s32 n;
    if (D_001D5530[id] == 0) {
        /* retail spins a short delay loop (60 iterations) here */
        for (i = 1; i < 0x3C; i++) {
        }
        D_001D5530[id] = 1;
        if (id < 0x1E && id != 0x18) {
            n = 0;
            for (i = 0; i < 0x3C; i++) {
                if (D_00143050[i] != 0) {
                    n++;
                }
            }
            D_00143050[n] = id;
        }
    }
}
