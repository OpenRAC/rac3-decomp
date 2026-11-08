/* func_L02_004C2BA0: p2w3 near miss 5 diff (w6, default chk at home place; --target level_02 gives 33, check the place setup). Twin none used (from asm).
   Diffs: D_001DBC18 (gp 0xC98 below gp) compiled lui-form instead of $gp-relative (tried plain and _sda name);
   store order sw 0xBF4 / sw 0x25C0 / sb 0x25E4 and swc1 C00/C04 order. Needs maybe --as ps2as (inline 1.0f). */
extern u8 D_001A4BE0[];
extern f32 D_001DBC18;
extern void func_L02_004C2D20(s32);
extern void func_L01_004EAA80(void);
extern void func_L01_004ED188(void);
extern void func_L01_0044E740(void *);
extern void func_L01_005108C0(s32);
extern void func_L01_004E1560(void);
extern void func_L01_004E04E8(void);
extern void func_L02_004C3638(s32);
extern void func_L01_0050FED0(void);
extern void func_L01_004436F4(void *);
extern void func_L01_004E2ED0(void);
extern void func_L02_004D36C0(s32, s32);

void func_L02_004C2BA0(s32 mode, s32 arg, u8 *obj)
{
    u8 *g = D_001A4BE0;
    u8 *cur;

    if (g[0x25E4] == mode)
        return;
    if (g[0x25E4] != 0)
        func_L02_004C2D20(0);
    *(u16 *)(obj + 0x34) &= 0xFFBE;
    func_L01_004EAA80();
    g[0x25E6] = 1;
    func_L01_004ED188();
    *(u8 **)(g + 0x25C0) = *(u8 **)(g + 0xBF8);
    func_L01_0044E740(g + 0x1B90);
    func_L01_0044E740(g + 0x1CE0);
    *(s32 *)(*(u8 **)(g + 0x25C0) + 0x9C) = -1;
    func_L01_005108C0(1);
    func_L01_004E1560();
    func_L01_004E04E8();
    *(u8 **)(g + 0x25C0) = obj;
    g[0x25E4] = mode;
    *(u8 **)(g + 0xBF4) = obj;
    if ((mode & 0xFF) == 2)
        *(f32 *)(g + 0x16CC) = D_001DBC18;
    func_L02_004C3638(1);
    cur = *(u8 **)(g + 0x25C0);
    *(u16 *)(cur + 0x34) |= 6;
    *(f32 *)(g + 0xC04) = 1.0f;
    *(f32 *)(g + 0xC00) = 1.0f;
    func_L01_0050FED0();
    func_L01_004436F4(*(u8 **)(g + 0x25C0));
    func_L01_004E2ED0();
    func_L02_004D36C0(arg, 2);
}
