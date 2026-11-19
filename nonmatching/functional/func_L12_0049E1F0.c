/* functional: high. Same routine as the L13 copy (func_L13_0047CDC0), with level 12 table D_L12_002EC348; callee 0041BF88 is the L12 copy of func_L01_0041A4F0; asm structure (0x18 entries, modes 0-4, flag at +0x14) verified. */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_47CDC0;
extern E_47CDC0 D_L12_002EC348[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L12_0049E1F0(void) {
    s32 i = 0;
    s32 n;
    while (D_L12_002EC348[i].f0 != 0) {
        switch (D_L12_002EC348[i].mode) {
        case 0: {
            E_47CDC0 *e = &D_L12_002EC348[i];
            u8 v = 0;
            if ((D_00142BA0[D_L12_002EC348[i].c.bit >> 2] & (1 << (D_L12_002EC348[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L12_002EC348[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L12_002EC348[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L12_002EC348[i].flag || (D_00142BA0[D_L12_002EC348[i].c.list[k] >> 2] & (1 << (D_L12_002EC348[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L12_002EC348[i].flag = v;
            }
            break;
        }
        case 2: {
            E_47CDC0 *e = &D_L12_002EC348[i];
            u8 v = 0;
            if ((D_00142BA0[D_L12_002EC348[i].c.bit >> 2] & (1 << (D_L12_002EC348[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3:
        case 4:
        default: {
            E_47CDC0 *e = &D_L12_002EC348[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        }
        i = n;
    }
}
