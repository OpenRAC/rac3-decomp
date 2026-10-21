/* US draft of func_003C19B8 (rac3-uya-decomp func_003C18B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C19B8 */
extern s32 func_003823D0(s32);
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0(s32, s32);
extern s32 func_0011B754(void *, s32);
__asm__(".extern D_001D9088, 1");
extern u8 D_001D9088;
extern volatile s32 D_001D4B4C;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002D2060[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0[];
s32 func_003C19B8(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002D2060;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_003823D0(0x1645));
    func_0011B754(p->n1, func_003823D0(0x1646));
    func_0011B754(p->n2, func_003823D0(0xF07));
    p->f30 = 0;
    q = D_001A4BE0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002D2060->f44 = arg0;
    D_002D2060->f60 = 0;
    func_003BBDC0(0, 0);
    if (D_002D2060->f40 == 0) {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x3C;
        D_002D2060->f50 = 0;
        D_001D4B4C = 0;
    } else {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x3C;
        func_003BC7C0(3, (s32)&D_001D9088);
    }
    return 1;
}
/* localdecomp:end func_003C19B8 */
