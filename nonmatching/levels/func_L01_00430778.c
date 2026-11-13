/* func_L01_00430778: 21 diff in L01_0042DB28.c (@ps2as), 7 per call of func_L01_00430660: retail loads
   the arguments y, w, h first and x last, so x lands in the jal delay slot (where Ps2EeAs turns the
   lw macro into a $gp load); gcc loads x first and puts h in the slot. No .extern hints are needed.
   The rect words are separate scalars because retail reads each with its own lui/lw macro.
   Array/sized/unsigned forms of x change nothing. Everything else matches. */
extern s32 D_001D545C;
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern u8 D_001BBB80[];
extern s32 D_L01_001D71F8;
extern s32 D_L01_001D71FC;
extern s32 D_L01_001D7200;
extern s32 D_L01_001D7204;
extern s32 D_L01_001D7208;
extern s32 D_L01_001D720C;
extern s32 D_L01_001D7210;
extern s32 D_L01_001D7214;
extern s32 D_L01_001D7218;
extern s32 D_L01_001D721C;
extern s32 D_L01_001D7220;
extern s32 D_L01_001D7224;
extern void func_L01_00430660(s32 x0, s32 y0, s32 w, s32 h);

s32 func_L01_00430778(void) {
    if (D_001D545C == 13) {
        if (D_001426E0[0xE9] == 0 && D_00142CA0[5] != 0 && D_001BBB80[3] == 0) {
            func_L01_00430660(D_L01_001D71F8, D_L01_001D71FC, D_L01_001D7200, D_L01_001D7204);
            D_001426E0[0xE9] = 1;
        }
        if (D_001426E0[0xEA] == 0 && D_00142CA0[5] != 0 && D_001426E0[0xB1] == 0) {
            func_L01_00430660(D_L01_001D7208, D_L01_001D720C, D_L01_001D7210, D_L01_001D7214);
            D_001426E0[0xEA] = 1;
        }
        if (D_001426E0[0xEB] == 0 && D_00142CA0[5] != 0 && D_001BBB80[1] == 0) {
            func_L01_00430660(D_L01_001D7218, D_L01_001D721C, D_L01_001D7220, D_L01_001D7224);
            D_001426E0[0xEB] = 1;
        }
    }
    return 0;
}
