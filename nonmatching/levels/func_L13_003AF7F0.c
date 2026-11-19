/* func_L13_003AF7F0: 48 diff with the file's flags (-O2 -G8, default assembler). Tried: the early returns and the flag-like loop variable; retail keeps a zero flag register (move $a3,$zero; bnez $a3 in the loop) that gcc folds away, and register/branch order differs. */
extern u16 *D_L13_0021C2A0[];
extern u8 D_L13_001DF59C[];
extern s32 D_L13_001DF5D8[];

u8 *func_L13_003AF7F0(s32 idx) {
    u16 *p;
    u8 *entity;
    u8 i8;
    s32 flag;

    if ((u8)idx == 0xFF) {
        return 0;
    }
    if (idx > D_L13_001DF5D8[0]) {
        return 0;
    }
    p = D_L13_0021C2A0[idx];
    if (p == 0) {
        return 0;
    }
    i8 = (u8)idx;
    flag = 0;
    while (1) {
        entity = D_L13_001DF59C + ((*p & 0x7FFF) << 8);
        if (entity == 0) {
            return 0;
        }
        if (*(s16 *)(entity + 0xAA) == 0x1B39) {
            if (entity[0x20] == 0x25) {
                return entity;
            }
        }
        if (i8 == 0xFF) {
            return 0;
        }
        p++;
        if (flag != 0) {
            return 0;
        }
        if (p == 0) {
            return 0;
        }
        if ((s16)p[-1] >= 0) {
            continue;
        }
        if (p == D_L13_0021C2A0[idx]) {
            continue;
        }
        return 0;
    }
}
