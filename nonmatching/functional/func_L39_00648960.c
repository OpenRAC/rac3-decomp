/* functional: high. 6-word near miss (order of the last load group only); ported from the NTSC-U draft with PAL data/callee names; gp words D_001D5A1C_sda and D_001DA9C0_sda verified against PAL gp offsets. */


/* NTSC-U counterpart of the PAL function at the same position (L39 shared) */
/* localdecomp:start func_L39_00648960 */
typedef struct {
    s32 f00;
    u8 pad_04[0x20];
    s32 f24;
    s32 f28;
    u8 pad_2C[0x14];
    s32 f40;
    s32 f44;
} Req_648960;

typedef struct {
    u8 pad_00[0x24];
    s32 f24;
    u8 pad_28[0x44];
    s32 f6C;
    u8 pad_70[0x24];
    s32 f94;
} Src_648960;

typedef struct {
    s32 first;
    s32 second;
} Ent_648960;

extern u8 D_001A5815 __attribute__((section(".data")));
extern s32 D_001D5A1C_sda;
__asm__(".extern D_001D5A1C_sda, 4");
extern s32 D_001DA9C0_sda;
__asm__(".extern D_001DA9C0_sda, 4");
extern Req_648960 D_L39_004989E0;
extern Src_648960 D_L39_00225660;
extern s32 D_L39_0047AA68[];
extern void func_L39_006488E8(u8 *, s32);

void func_L39_00648960(u8 *obj, s32 idx) {
    if (D_001A5815 != 0 && obj[0x1A14] != 0 && D_001D5A1C_sda >= 10 && D_L39_004989E0.f00 == 0 &&
        D_L39_004989E0.f24 == -1 && D_L39_00225660.f6C == 0 && D_L39_00225660.f24 == D_L39_004989E0.f24 &&
        D_L39_00225660.f94 == 0) {
        D_L39_004989E0.f28 = D_L39_0047AA68[idx * 2 + 1];
        D_L39_004989E0.f24 = D_L39_0047AA68[idx * 2];
        D_L39_004989E0.f40 = D_001DA9C0_sda;
        D_L39_004989E0.f44 = 0;
        func_L39_006488E8(obj, idx);
    }
}
