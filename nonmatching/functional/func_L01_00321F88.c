/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 69 words differ in saved-register allocation and loop scheduling; state tests folded into range; not byte-identical, behaviour as retail. */
extern u8 *D_L01_001E17B8[];
s32 func_L01_00321F88(u8 *obj) {
    extern f32 *func_00382348(u8 *);
    s32 i;
    s32 j;
    for (i = 0; i < 7; i++) {
        f32 *health = func_00382348(obj);
        if (D_L01_001E17B8[i] == obj) return 0;
        if (obj == 0) return 0;
        if (obj[0x20] == 0xFE || obj[0x20] == 0xFD) return 0;
        if (health == 0) return 0;
        if (*health <= 0.0f) return 0;
        if (*(u16 *)(obj + 0x34) & 2) return 0;
        if (obj[0x31] == 0) return 0;
    }
    for (j = 0; j < 7; j++) {
        if (D_L01_001E17B8[j] == 0) {
            D_L01_001E17B8[j] = obj;
            return 1;
        }
    }
    return 0;
}
