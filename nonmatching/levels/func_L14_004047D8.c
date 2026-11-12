/* func_L14_004047D8: near miss, 20 diff: same logic and block order as retail; left: retail merges the early return-1 into the epilogue (bnez to the end, v0=1 in the slot) and returns 0 from the loop exit's slot, keeps the table pointer in the $v1 of the lui and the D_001D5570 base in $a0; ours puts the return stubs after the loop and the pointer in $a0; about 10 wordings (for/do-while, result variable, goto-free returns) tried
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
typedef struct { s32 id; s32 v; } E_4047D8;
extern E_4047D8 D_L14_002D3240[];
extern u8 D_0014271D[];
extern u8 D_001D5570[];
extern s32 func_L01_0041A4F0(s32);
s32 func_L14_004047D8(s32 a, s32 b) {
    E_4047D8 *t;
    if (func_L01_0041A4F0(a) == 0) {
        if (a == 0x67) {
            return D_0014271D[0] != 0;
        }
        if (D_L14_002D3240[0].id == 0) {
            return 0;
        }
        t = D_L14_002D3240;
        do {
            if (a == t->id) {
                if (t->v == b || D_001D5570[t->v] != 0) {
                    return 1;
                }
                return 0;
            }
            t++;
        } while (t->id != 0);
        return 0;
    }
    return 1;
}
