/* functional: high. Near miss on PAL (only loop register assignment differs). Uses the file context declarations of D_L03_00281DA0/EA0/FA0 and D_L03_001E13C8. */
/* localdecomp:start func_L03_00348C18 */
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
/* localdecomp:end func_L03_00348C18 */
