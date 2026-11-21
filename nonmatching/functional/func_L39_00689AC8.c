/* functional: high. If the byte flag D_001DC30A is set: sets the int at D_001DC310 to 150, calls func_L39_00611018(menu field 0x40, 1, 1), formats the text-table string 0xF69 with the argument into D_L39_0024D7B0 using format D_L39_00247A68, and hands the result to func_L39_00611650. Does nothing otherwise. (a0 unused.) */
extern u8 D_001DC30A_sda;
__asm__(".extern D_001DC30A_sda, 1");
extern s32 D_001DC310_sda_00689AC8;
__asm__(".extern D_001DC310_sda_00689AC8, 4");
extern s32 D_L39_003D2880[];
extern char D_L39_00247A68[];
extern char D_L39_0024D7B0[];
extern void func_L39_00611018(s32, s32, s32);
extern char *func_L39_0059A970(s32);
extern void func_L39_00611650(s32, char *);
extern s32 func_00120048(char *, char *, ...);

void func_L39_00689AC8(s32 a0, s32 val) {
    if (D_001DC30A_sda != 0) {
        D_001DC310_sda_00689AC8 = 0x96;
        func_L39_00611018(D_L39_003D2880[0x40 / 4], 1, 1);
        func_00120048(D_L39_0024D7B0, D_L39_00247A68, func_L39_0059A970(0xF69), val);
        func_L39_00611650(D_L39_003D2880[0x40 / 4], D_L39_0024D7B0);
    }
}
