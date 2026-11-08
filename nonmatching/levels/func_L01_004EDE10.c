/* Near miss: func_L01_004EDE10 (open-rac-engine names it hero_death_done), in
 * src/levels/shared/L01_004E7338.c (@ps2as). Checked with tools/check.py at level 01.
 * What still differs: retail rematerialises the hero address for the per-area count
 * (D_001D4CA8) into $v1, apart from the area check's copy in $v0 (one more `addiu`),
 * and that block then has $v0/$v1 swapped; everything before it matches.
 * Tried: `+= 1`, `++x`, x = x + 1, a local for the area. D_L01_001DFB40 must stay a sized
 * extern (no hint): retail's `lui $v0; lw $v0` is the assembler's macro.
 */
typedef struct {
    u8 pad0[0x234];
    s32 f234;
    u8 pad238[0x25C4 - 0x238];
    s32 state;
    u8 pad25C8[0x25F2 - 0x25C8];
    u8 respawn;
    u8 pad25F3[0x25F7 - 0x25F3];
    u8 area; /* 0xFF for none */
    u8 pad25F8[0x28C9 - 0x25F8];
    u8 f28C9;
    u8 pad28CA[0x28CC - 0x28CA];
    S_4E8698o *f28CC;
} Hero_4EDE10;
typedef struct {
    u8 pad0[0x40];
    u16 h40;
    u8 pad42[0x5A - 0x42];
    u8 b5A;
    u8 b5B;
    u8 pad5C[0x78 - 0x5C];
    u16 h78;
} Stats_4EDE10;
extern u8 D_001A4BE0[];
extern s32 D_00143D70[];
extern s32 D_001D4CA0;
extern s32 D_001D545C;
extern s32 D_L01_001DFB40;
extern u8 D_001BBC40[][16];
extern s32 D_001C5290[][16];
extern s32 D_001D4CA8[];
extern Stats_4EDE10 D_00142660;
extern void func_L01_0041A7D0(void);
extern void func_0038A238(s32);
extern void func_L01_00425A08(s32 restore);
extern void func_003C2880(S_4E8698o *a0);
extern s32 func_L01_0041A4F0(void);

/* hero_death_done: counts the death in the stats and asks the level to bring him back */
void func_L01_004EDE10(void) {
    s32 from;
    u8 area;

    D_00143D70[D_001D545C]++;
    D_001D4CA0++;
    func_L01_0041A7D0();
    if (((Hero_4EDE10 *)D_001A4BE0)->area != 0xFF) {
        if (((Hero_4EDE10 *)D_001A4BE0)->state == 0x79 || ((Hero_4EDE10 *)D_001A4BE0)->state == 0x7E) {
            from = 1500;
        } else {
            from = 750;
        }
        if (D_L01_001DFB40 >= from) {
            area = ((Hero_4EDE10 *)D_001A4BE0)->area;
            if (!(D_001BBC40[D_001D545C][area] & 0x80)) {
                D_001C5290[D_001D545C][area & 0xF]++;
            }
        }
        D_001D4CA8[((Hero_4EDE10 *)D_001A4BE0)->area & 0xF]++;
    }
    func_0038A238(13);
    if (((Hero_4EDE10 *)D_001A4BE0)->f234 != 0) {
        D_00142660.h40 = D_00142660.h78;
        func_L01_00425A08(0);
        ((Hero_4EDE10 *)D_001A4BE0)->f28C9 = 0;
        if (((Hero_4EDE10 *)D_001A4BE0)->f28CC != 0) {
            func_003C2880(((Hero_4EDE10 *)D_001A4BE0)->f28CC);
            ((Hero_4EDE10 *)D_001A4BE0)->f28CC = 0;
        }
    }
    if (func_L01_0041A4F0() != 0) {
        D_00142660.b5A = 0;
        D_00142660.b5B = 0;
    }
    ((Hero_4EDE10 *)D_001A4BE0)->respawn = 1;
}
