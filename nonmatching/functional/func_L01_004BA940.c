/* functional: high. Initialises a 0x14-byte slot of the table at D_L01_002446C0 (+0x140; the file context declares D_L01_002446C0 as S_00244740[]) from a mode value: stores it, sets flag bytes for mode==0 and mode==1, constant 0xCDB, other bytes cleared. */
void func_L01_004BA940(s32 idx, s32 mode) {
    u8 *e = (u8 *)D_L01_002446C0 + idx * 0x14;
    u8 isZero = (mode == 0);
    u8 isOne = (mode == 1);
    *(s32 *)(e + 0x140) = mode;
    e[0x152] = isZero;
    e[0x153] = isOne;
    e[0x144] = isZero;
    e[0x150] = 0;
    *(s32 *)(e + 0x14C) = 0xCDB;
    e[0x151] = 0;
}
