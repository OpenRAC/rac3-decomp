/* functional: high. Selects entry idx of the 0x1F0-byte table D_001FC6B0 for slot: records idx in the per-slot and current-index globals, copies three per-entry triples (byte, byte, word) into the D_001A5810 per-slot arrays, and sets two flags, a word and a per-slot byte from the entry. */
extern u8 D_001FC6B0[];
extern u8 D_001A5810[];
extern s32 D_L39_00240370[] __attribute__((section(".sdata")));
extern void *D_L39_00241444 __attribute__((section(".data")));
extern s32 D_001A5CEC;

void func_L39_0059A660(void *idxp, s32 slot) {
    s32 idx = (s32)idxp;
    u8 *e = D_001FC6B0 + idx * 0x1F0;
    u8 *p;
    s32 i;
    s32 v6;
    u8 off;

    D_L39_00240370[slot] = idx;
    D_001A5CEC = *(s32 *)e;
    D_L39_00241444 = idxp;
    p = D_001A5810 + slot * 4;
    for (i = 0; i < 3; i++) {
        if (i == 0) {
            v6 = e[4];
        } else {
            v6 = e[4 + i * 8] ^ 1;
        }
        *(s32 *)(p + 0x44 + i * 16) = v6;
        *(s32 *)(p + 0x14 + i * 16) = e[5 + i * 8];
        *(s32 *)(p + 0x74 + i * 16) = *(s32 *)(e + 8 + i * 8);
    }
    off = e[0x171];
    D_001A5810[4] = e[0x4F] == 0;
    *(s32 *)(D_001A5810 + 0xC) = *(s16 *)(e + 0x172);
    D_001A5810[5] = e[0x4F] == 0;
    D_001A5810[0xAE + slot] = off;
}
