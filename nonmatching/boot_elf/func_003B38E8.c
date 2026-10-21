/* Near miss of func_003B38E8 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 20).
*/

/* PAL candidate for func_003B38E8 (boot_elf).

   Changes over the US draft:
   - the call the US made to func_003B3BF8 is func_003B3D98 in PAL;
   - the global at 0x001D4CE8 is read through the alias D_001D4CE8_003B3BF8
     declared as an incomplete array: gcc then emits no `.extern ..., 4` size
     hint, so the assembler reaches it through %hi/%lo (lui + lw) instead of
     $gp, which is what retail does.  Same address, same bytes; the file's own
     `extern s32 D_001D4CE8;` stays as it is and would force the $gp form.
     The project uses this idiom in e.g. src/boot_elf/text/39BCB0.c. */

/* localdecomp:start func_003B38E8 */
__asm__(".extern D_001D888C, 4");
__asm__(".extern D_001D8894, 4");
extern void func_0039C0E8();
extern void func_003B3D90(void);
extern void func_003B3D98();
extern void func_003B4218(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8_003B3BF8[];
void func_003B38E8(void) {
    s32 t;
    s32 v;
    switch (D_001D888C) {
    case 0:
        func_0039C0E8((void *)func_003B35E8, 0, 0);
        func_003B3D98();
        D_001D8894 = 0x1E;
        D_001D888C = D_001D888C + 1;
        break;
    case 1:
        func_003B3D98();
        v = D_001D8894;
        if (v > 0) { v = v - 1; D_001D8894 = v; }
        D_001D8894 = v;
        if (v == 0) func_003B4218();
        break;
    case 2:
        t = D_001D4CE8_003B3BF8[0];
        if (t == 1 || t == 0x12) func_0013D3C0(1);
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B38E8 */
