/* functional: high. 43 diff at default flags (jump table dispatch order, small-data vs lui loads); cases 3 and 4 and out-of-range all return 0 as in retail's table (jtbl: 0->2EB8, 1->2F0C, 2->2F98, 3,4->default). */
extern s16 D_001CCFD4[];
extern u8 D_00143A07[];
extern u8 D_00160C40[];
extern s32 D_L01_001D96E8;
extern u32 D_L01_001D96F0;
extern s32 D_L01_001D96CC;
extern s32 D_L01_001D96D0;
extern s32 D_L01_001DFCC0[];
extern s32 D_L01_002E5F30[];
__asm__(".extern D_L01_001D96E8, 4");
__asm__(".extern D_L01_001D96F0, 4");
__asm__(".extern D_L01_001D96CC, 4");
__asm__(".extern D_L01_001D96D0, 4");
extern s32 func_003A26F0(s32, s32, s32);
extern void func_L01_004A2FC0(void);
s32 func_L01_004A2E88(void) {
    switch (D_L01_001D96F0) {
    case 0: {
        u8 *base;
        s32 r;
        if (D_001CCFD4[0] != 0) {
            return 1;
        }
        base = D_00160C40 + (D_00143A07[0] << 3);
        r = func_003A26F0(D_L01_001D96E8, *(s32 *)(base + 0x6188) + *(s32 *)(D_00160C40 + 0x4954),
                          *(s32 *)(base + 0x618C));
        D_L01_001D96F0 = (r == 0) ? 4 : 1;
        return 1;
    }
    case 1: {
        s32 *p;
        s32 n;
        s32 i;
        if (D_001CCFD4[0] != 0) {
            return 1;
        }
        p = (s32 *)D_L01_001D96E8;
        n = (u32)*p >> 4;
        D_L01_001D96CC = D_L01_001DFCC0[0];
        D_L01_001D96D0 = D_L01_002E5F30[11];
        D_L01_001DFCC0[0] = (s32)p;
        D_L01_002E5F30[11] = n;
        if (n != 0) {
            s32 *q = p;
            for (i = 0; i < D_L01_002E5F30[11]; i++) {
                *q += (s32)p;
                q += 4;
            }
        }
        D_L01_001D96F0 = 2;
        return 1;
    }
    case 2:
        func_L01_004A2FC0();
        D_L01_001D96F0 = 3;
        return 0;
    case 3:
    case 4:
    default:
        return 0;
    }
}
