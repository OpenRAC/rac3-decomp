/* functional: high. Jump table (0..4, 2 and 3 empty, >=5 default) read from the level-02 copy; written from asm, no draft */
extern E_49E5B8 D_L01_002EC758[];
extern u8 D_L01_001EA7C0[];
extern s32 D_001D94C8_sda;
__asm__(".extern D_001D94C8_sda, 4");
extern s32 func_00392B20(void *, s32);
extern void func_00392C78(void *);
extern s32 func_L01_0049C630(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(void *);

void func_L01_0049E000(void *arg) {
    s32 i;
    s32 *list;

    if (D_L01_002EC758[D_001D94C8_sda].x14 != 0) {
        switch (D_L01_002EC758[D_001D94C8_sda].x10) {
        case 0:
            func_00392B20(D_L01_001EA7C0, D_L01_002EC758[D_001D94C8_sda].xC);
            func_00392C78(D_L01_001EA7C0);
            break;
        case 1:
            i = 0;
            list = (s32 *)D_L01_002EC758[D_001D94C8_sda].xC;
            if (list[0] != 0) {
                do {
                    func_00392B20(D_L01_001EA7C0, ((s32 *)D_L01_002EC758[D_001D94C8_sda].xC)[i]);
                    i++;
                } while (((s32 *)D_L01_002EC758[D_001D94C8_sda].xC)[i] != 0);
            }
            func_00392C78(D_L01_001EA7C0);
            break;
        case 2:
        case 3:
            break;
        default:
            if (D_L01_002EC758[D_001D94C8_sda].x14 != 0) {
                if (D_L01_002EC758[D_001D94C8_sda].x0 == 0x1C2) {
                    func_L01_00517748(func_L01_0049C630());
                    func_L01_00516090(arg);
                }
            }
            break;
        }
    }
}
