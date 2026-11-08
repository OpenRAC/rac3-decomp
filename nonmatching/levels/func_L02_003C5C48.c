/* Near miss, ported from rac2-decomp's func_L06_0047AC68 (cross-game near pair). NEAR: structure right (donor shape, u16 tag, D_001A71C4 as u8[], context decls); gcc CSEs the sll of tag and adds move $a2,$v0 where retail recomputes sll at each use: one extra insn shifts rest */
typedef struct {
    u8 pad0[0x1C];
    u8 *st;
} Sp_003C5150;
typedef struct {
    char pad0[0x36C];
    s16 f36C;
    char pad1[0x280C - 0x36E];
    s32 f280C;
} S_003C5C48;
extern Sp_003C5150 *D_L02_001DE184;
extern s32 D_001A71AC[];
extern u8 D_001A71C4[];
extern S_003C5C48 D_001A4BE0;
extern s32 D_001D545C __attribute__((section(".sdata")));
extern void func_L02_003C5310(s32);

s32 func_L02_003C5C48(s32 a0) {
    u8 *st;
    u16 tag;

    st = D_L02_001DE184[*(s16 *)(a0 + 0x84)].st;
    if (*(s16 *)(st + 0x48) == 1 && *(s16 *)(st + 0x4A) != 0)
        return 0;
    tag = *(u16 *)(st + 0x2C);
    if (*(s16 *)(st + 0x2C) == 11 && D_001A71C4[0] != 2)
        return 0;
    switch ((s16)tag) {
    case 1:
    case 10:
        if (*(s16 *)(st + 0x2E) != 0)
            goto clear;
        if (D_001A4BE0.f36C != 0) {
            if (D_001D545C != 14)
                return 0;
            if (D_001A4BE0.f280C != 13)
                return 0;
        }
    }
clear:
    if ((s16)tag != 2)
        goto call;
    if (D_001A71AC[0] == 26)
        goto call;
    *(u16 *)(st + 0x2E) = 0;
    return 0;
call:
    func_L02_003C5310(a0);
    return 0;
}
