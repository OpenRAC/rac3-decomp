/* func_003B55D8: frontbin's matched func_003B5220 (src/frontbin/3B5220.c and its @ps2as file cut,
   both from 5757b8df), renamed to boot_elf's copy. Replaces the US draft of func_003B5428
   (rac3-uya-decomp commit 13cf5c5), which called func_003B6220 and passed 0xA where retail has
   func_003B63D0 and 8. Plain names, no per-function aliases.

   tools/check.py --target boot_elf (with and without --no-context): MATCH with --as ps2as,
   153 differences with the file's flags (3B3B08.c, no @ps2as: the float constants go through $gp).
   Recipe: give 0x003B55D8-0x003B5890 a file of its own with 3B3B08.c's flags plus @ps2as, as
   frontbin's 3B5220.c has, and a file from 0x003B5890 with 3B3B08.c's flags. Not done: that second
   file would move func_003B5C10 and func_003B6128, which another contributor's issue #3 comment
   claims. NTSC-U: no twin (config/us/map.tsv: its code differs). */

/* localdecomp:start func_003B55D8 */
__asm__(".extern D_001D89BC, 4");
__asm__(".extern D_001D89E4, 4");
extern s32 D_001D89BC;
extern s32 D_001D89E4;
extern u8 D_0037F880[];
extern f32 D_001D9698;
extern void func_003B5EF0();
extern void func_0038E530(s32);
extern s32 func_003823D0();
extern s32 func_0038E928(f32, s32, s32);
extern f32 func_003C4440(f32, f32, f32);
extern void func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern void func_003B5C10();
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E8B70(s32, s32, s32);
extern void func_003B6128();
extern void *func_003B46B0(s32);
extern void func_003B63D0(void);
void func_003B55D8(void) {
    s32 flag = 0;
    f32 lim = 0.49f;
    f32 scale = 0.0f;
    f32 base = 0.0f;
    f32 lo = 6.0f;
    f32 hi = 11.0f;
    f32 x, y;
    D_001D89BC = -1;
    D_001D89E4 = 0;
    func_003B5EF0();
    func_0038E530(0);
    x = (f32)func_0038E928(1.2f, func_003823D0(0x107), -1) / D_001D9698;
    if (lim < x) {
        flag = 1;
        scale = 0.588000059f / x;
        x = lim;
    }
    y = func_003C4440(lo, hi, (x - base) / lim);
    if (hi < y) y = hi;
    else if (y < lo) y = lo;
    func_003B9650(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, y, 0xD0008, func_003823D0(0x107), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    if (flag) func_003E85A8(0xD0005, scale, scale);
    func_003B5C10(D_0037F880);
    func_003E93A0(0x1C0004, func_003823D0(0x1EBD), 0x8066CCFF, 0.5f, 0.932f, 0.9f, 0.9f);
    func_003E7CE0(0x1C0004, 3, 3);
    func_003E7BF0(0x1C0004, 0x2040, 1);
    func_003E89E8(0x1C0000, 0x1C0004);
    func_003E8700(0x11, 0x1C0000);
    func_003E7DD0(0x1C0003, 0);
    func_003E8AC8(0x1C0003, func_003B46B0(0));
    func_003E8200(0x1C0003, 5);
    func_003E8B70(0x1C0003, 1, 8);
    func_003B6128();
    func_003B63D0();
}
/* localdecomp:end func_003B55D8 */
