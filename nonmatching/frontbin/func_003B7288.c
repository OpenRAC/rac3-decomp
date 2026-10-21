/* US draft of func_003B7288 (rac3-uya-decomp func_003B1DA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B7288 */
__asm__(".extern D_001D8A18_003B7288, 4");
extern s32 D_001D8A18_003B7288;
extern s32 func_00381FF0();
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
void func_003B7288(void) {
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;
    switch (D_001D8A18_003B7288) {
    case 0:
        a = 0x143;
        b = 0x124;
        c = 0x100;
        break;
    case 1:
        a = 0x144;
        b = 0x124;
        c = 0x100;
        break;
    case 2:
        a = 0x14E;
        b = 0x124;
        c = 0x100;
        break;
    case 3:
        a = 0x1750;
        b = 0x124;
        c = 0x100;
        break;
    }
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 8.7f, 0xD0008, func_00381FF0(a), 0xD0006, b, 0xD0007, c);
}
/* localdecomp:end func_003B7288 */
