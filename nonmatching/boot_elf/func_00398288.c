/* US draft of func_00398288 (rac3-uya-decomp func_003981A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00398288 */
extern u8 D_00227580_00398288[];
extern u8 D_3F3777[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_001DA058;
extern s32 func_0011A264(s32, s32, s32);
void func_00398288(void) {
    u32 *s = (u32 *)D_00227580_00398288;
    u32 c;
    func_0011A264((s32)s, 0, 0xA0);
    c = (u32)D_01FFC000;
    s[0] = 0;
    s[1] = 0x100000;
    s[2] = (u32)D_3F3777 & 0xFFFFF000;
    s[3] = s[2];
    s[4] = s[3] + D_001DA058;
    s[5] = s[4] + D_001DA058;
    s[6] = s[5] + 0x100000;
    s[0x22] = (u32)D_01FF8000;
    s[0x21] = s[0x22] - 0x40000;
    s[0x20] = s[0x21] - 0x64000;
    s[0x1F] = s[0x20];
    s[0x1E] = s[0x1F] - 0x2C000;
    s[0x1D] = s[0x1E] - 0x8000;
    s[0x1C] = s[0x1D] - 0x14000;
    s[0x1A] = s[6];
    s[0x23] = c;
    s[0x1B] = s[0x1C];
    s[0x24] = 0x7000000;
    s[0x25] = 0x7100000;
    s[0x26] = 0x7180000;
    s[0x27] = 0x7200000;
}
/* localdecomp:end func_00398288 */
