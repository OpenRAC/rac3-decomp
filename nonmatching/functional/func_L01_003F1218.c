/* functional: high. EXACT at level 01 (adapted from the matched L39 copy of the same routine). Uses alias D_L01_001DF780_003F1218 because the file context declares D_L01_001DF780 as u8[]. */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x148];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
} S_003F1218;
extern S_003F1218 D_00142430;
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern s32 D_001DF780_sda;
__asm__(".extern D_001DF780_sda, 4");
extern s32 D_L01_001DF780_003F1218;
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern u16 D_001A7E18[];
extern u16 D_001A7F38[];
extern s32 D_L01_001DF948;
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern s32 func_00396968(s32, s32);
extern void func_00396C60(s32, s32, s32, s32, s32, s32);
extern long func_00396A38(int);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);

void func_L01_003F1218(void) {
    s32 v;
    s32 n;
    f32 big;
    f32 ang;

    if ((u32)(D_00142430.f15C - 0xF) >= 2 && D_00142430.f164 != 0xF && D_001DF780_sda == 0) {
        return;
    }
    if (D_00142430.f16C != 0 || D_00142430.f10 != 0) {
        D_00142430.f17C = 0;
        D_001D4CE8 = 0x18;
        D_001D4CEC = 0x40;
        D_001DF780_sda = 0;
        if (D_001D6694_sda == 0) {
            func_003A0EC0(4, 1, 1, 0, 0);
        } else {
            func_003A0EC0(4, 2, 1, 0, 0);
        }
        return;
    }
    v = D_001DF780_sda;
    if (v == -1) {
        if (D_001D6694_sda != 0) {
            return;
        }
        if (D_001A7E18[0x90] == 0) {
            D_001A7E18[0x90] = 1;
        } else {
            D_001DF780_sda = 0;
            return;
        }
    } else {
        if (D_001D6694_sda == 0 && D_001A7F38[0] == 0) {
            func_003A0EC0(4, 1, 2, 0, 0);
            D_001DF780_sda = -1;
            return;
        }
        if ((u32)(D_00142430.f15C - 0xF) < 2 || D_00142430.f164 == 0xF) {
            D_L01_001DF780_003F1218 = 0x19;
        } else {
            D_L01_001DF780_003F1218 = v - 1;
        }
        func_00389240(0);
        n = 0x37;
        big = 272.0f;
        func_003A9440(0x47, 0x2004B);
        func_00396C60(func_00396968(0x755D, 0), 0x1A9, 0xFA, 0x40, 0x40, 0x80);
        ang = (f32)(D_L01_001DF948 % n) * -6.2831855f / (f32)n;
        func_00397638(7312.0f, 4512.0f, big, big, ang, 0x40, 0x40, func_00396A38(func_00396968(0x755D, 1)));
        func_00389370();
        if (D_001D4CE8 != 3) {
            return;
        }
    }
    D_L01_001DF780_003F1218 = 0;
}
