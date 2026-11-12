/* func_L24_00401EE0: level 24 near miss. 15 differences, all register allocation: retail keeps the table's lui in $v1 (the loaded id in $v0, pointer p = $v1, the u8 table base in $a0) and fills the first bne's slot with that lui; this C gives hi/p/base to $v0/$a0/$v1. Structure (call, 0x67 case, entry test, rotated search loop, return 1/0 exits) already equals retail; do-while with entry test, for loop, s32* version, index local and a result variable were tried (best 15, the others 26 or worse) */
typedef struct {
    s32 id;
    s32 idx;
} S_401EE0;

extern S_401EE0 D_L24_002CF500[];
extern u8 D_L24_001D5570[];
extern u8 D_0014271D[];
extern s32 func_L24_00402840(s32);

s32 func_L24_00401EE0(s32 a0, s32 a1) {
    S_401EE0 *p;
    if (func_L24_00402840(a0) != 0) {
        return 1;
    }
    if (a0 == 0x67) {
        return D_0014271D[0] != 0;
    }
    p = D_L24_002CF500;
    if (p->id == 0) {
        return 0;
    }
    do {
        if (p->id == a0) {
            if (p->idx != a1 && D_L24_001D5570[p->idx] == 0) {
                return 0;
            }
            return 1;
        }
        p++;
    } while (p->id != 0);
    return 0;
}
