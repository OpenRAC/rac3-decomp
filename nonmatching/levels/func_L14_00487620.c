/* func_L14_00487620: near miss, 28 diff, one cause: same trigger-table walk as func_L02_00473410 (flag = bit test || func_L01_0041A4F0()); retail increments i in place in case 1 ($s2) once the &D[i].c / &D[i] addresses are taken, this C keeps n = i + 1 in $s3 and ends with move $s2,$s3, which also shifts the flag temporary; a while loop with i++ (and continue) in case 1, pointer locals taken before i++, and three placements of n = i + 1 tried (28 to 112)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_487620;
extern E_487620 D_L14_002EE128[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);
void func_L14_00487620(void) {
    s32 i = 0;
    s32 n;
    while (D_L14_002EE128[i].f0 != 0) {
        switch (D_L14_002EE128[i].mode) {
        case 0: {
            E_487620 *e = &D_L14_002EE128[i];
            u8 v = 0;
            if ((D_00142BA0[D_L14_002EE128[i].c.bit >> 2] & (1 << (D_L14_002EE128[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L14_002EE128[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L14_002EE128[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L14_002EE128[i].flag || (D_00142BA0[D_L14_002EE128[i].c.list[k] >> 2] & (1 << (D_L14_002EE128[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L14_002EE128[i].flag = v;
            }
            break;
        }
        case 2: {
            E_487620 *e = &D_L14_002EE128[i];
            u8 v = 0;
            if ((D_00142BA0[D_L14_002EE128[i].c.bit >> 2] & (1 << (D_L14_002EE128[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3:
        case 4:
        default: {
            E_487620 *e = &D_L14_002EE128[i];
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
