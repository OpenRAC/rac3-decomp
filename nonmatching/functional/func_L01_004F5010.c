/* functional: high. 17 words differ: register allocation only */
extern s32 func_0038CB00(void *);
extern void func_L01_004E11C0(s32, s32, s32, s32);

void func_L01_004F5010(void) {
    u8 *tbl = (u8 *)&D_001A4BE0 + 0x2750;
    u8 *p = tbl;
    u8 *q = tbl + 2;
    s32 i;

    for (i = 7; i >= 0; i--) {
        if (func_0038CB00(p) == 2) {
            s32 t = *(s16 *)(q - 4);

            *(s16 *)(q - 6) = 0;
            if (t == 0x1B) {
                func_L01_004E11C0(((u8 *)&D_001A4BE0)[0x147F], 1, 1, 0x32);
            } else {
                func_L01_004F4E70(t, *(s16 *)q);
            }
        }
        p += 8;
        q += 8;
    }
}
