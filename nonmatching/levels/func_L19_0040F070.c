/* func_L19_0040F070: 14 diff; table search, loop and flag path match in shape */
typedef struct { s32 id; s32 off; } S_40F070;
extern S_40F070 D_L19_002D3F80[];
extern u8 D_001D5570[];
extern u8 D_0014271D[];
extern s32 func_L01_0041A4F0(s32);

s32 func_L19_0040F070(s32 a, s32 b) {
    S_40F070 *p;
    s32 id;
    if (func_L01_0041A4F0(a)) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    p = D_L19_002D3F80;
    id = p->id;
    if (id == 0) return 0;
    do {
        if (a == p->id) {
            if (p->off != b && D_001D5570[p->off] == 0) return 0;
            return 1;
        }
        p++;
    } while (p->id != 0);
    return 0;
}
