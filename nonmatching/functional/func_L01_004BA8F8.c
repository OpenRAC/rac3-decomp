/* functional: high. Fills one 0x14-byte entry of the table at D_L01_002446C0 (+0x140; the file context declares D_L01_002446C0 as S_00244740[]): word value, byte kind, flag bytes cleared, constant 0xCDB, byte arg3. Field meaning unknown (entry layout of a small slot table). */
void func_L01_004BA8F8(s32 idx, s32 value, s32 kind, s32 extra) {
    u8 *e = (u8 *)D_L01_002446C0 + idx * 0x14;
    *(s32 *)(e + 0x140) = value;
    e[0x144] = kind;
    e[0x152] = 0;
    *(s32 *)(e + 0x14C) = 0xCDB;
    e[0x150] = 0;
    *(s32 *)(e + 0x148) = 0;
    e[0x151] = extra;
}
