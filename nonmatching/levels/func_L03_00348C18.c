/* Near miss, ported from rac2-decomp's func_L30_00413528 (cross-game near pair). NEAR: (19 at level_03) 64-slot register-menu add; all stores/loads right, only loop pointer register assignment differs (retail a0=DA0,v1=EA0,t3=FA0,t2=i; ours t2,a0,v1,t3); 8 wordings tried. Uses new extern char *D_L03_00281EA0[]; file decls DA0=s32*[] FA0=s32[][2] and u8 001E13C8[] */
extern char *D_L03_00281EA0[];

void func_L03_00348C18(char *menu, s32 *value, char *label, s32 type, s32 low, s32 high) {
    s32 *st = *(s32 **)(menu + 0x68);
    s32 i;
    for (i = 0; i < 64; i++) {
        if (D_L03_00281DA0[i] == 0) {
            D_L03_00281DA0[i] = value;
            D_L03_00281EA0[i] = label;
            D_L03_001E13C8[i] = type;
            D_L03_00281FA0[i][0] = low;
            D_L03_00281FA0[i][1] = high;
            st[1] += 1;
            return;
        }
    }
}
