/* func_L39_0050D838: near miss (Sonnet w4 p2w2), 5 diff */
/* 88 bytes, level 39, src/levels/39_multiplayer_menu/L39_0050D5B0.c; written from asm + jtbl_004798D0 (0x800..0x804 -> 6,5,10,16,2; default returns a0) */
/* remaining diff is only the jtbl address-load shape (lui/addiu split vs retail folded %lo; delay-slot nop) */
s32 func_L39_0050D838(s32 a0) {
    switch (a0) {
    case 0x800: return 6;
    case 0x801: return 5;
    case 0x802: return 10;
    case 0x803: return 16;
    case 0x804: return 2;
    }
    return a0;
}
