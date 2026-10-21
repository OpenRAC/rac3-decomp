/* Near miss of func_003CF0F0 with its file's own flags: tools/check.py reports 10 diff
   (the version it replaces: 50).
   What differs: Only the four global accesses and one zero argument still differ. Retail
   reaches D_001DA050 (load), D_001D4BB4 (load), D_001DA68C (store) and D_001D4BB0 (store) with
   the *assembler macro* form - `lui $v0; lw $v0, %lo(D)($v0)` for the loads (high half reused
   as the destination) and `lui $at; sw $v0, %lo(D)($at)` for the stores ($at) - while eegcc
   2.95.3 in this file's S-mode flags always emits gcc's split form with a separate high-half
   register (`lui $v1; lw $v0, %lo(D)($v1)`, `lui $a1; sw ...`) and hoists those `lui`s to the
   top of the function. That extra `lui` also pushes `addiu...
*/

/* PAL candidate for func_003CF0F0 (frontbin).
   - the globals retail reaches with lui/lo are declared as unsized arrays (aliases),
     the one retail reaches through $gp keeps the file's sized declaration;
   - the callee retail passes a 64-bit zero to is called through an alias whose
     parameter is `long` (64-bit here). */

/* localdecomp:start func_003CF0F0 */
extern u32 *D_001DA050_003CF0F0[];
extern s32 D_001D4BB4_003CF0F0[];
extern u32 *D_001DA68C_003CF0F0[];
extern s32 D_001D4BB0_003CF0F0[];
extern void func_11F0A0_003CF0F0(long);
extern void func_003CF1C8();
void func_003CF0F0(void) {
    u8 v[0x40];
    u32 *o = D_001DA050_003CF0F0[0];
    s32 t = D_001D4BB4_003CF0F0[0];
    D_001DA68C_003CF0F0[0] = o;
    o += 4;
    D_001D4BB0_003CF0F0[0] = t;
    D_001DA050 = o;
    func_0038D2A0(v);
    func_0038CE20((f32 *)(v + 0x30), D_00222400, -1024.0f);
    *(f32 *)(v + 0x3C) = 1.0f;
    func_0038D640(v, D_00222400 - 0x100, v);
    func_003A9390(5, (s32)v, 4);
    func_003A9390(0x14D, (s32)v, 4);
    func_11F0A0_003CF0F0(0L);
    func_003CF1C8();
    func_003CEF40();
    func_0038CD80(D_002FDC00, 0x3000, 0x40);
}
/* localdecomp:end func_003CF0F0 */
TEXT_PADDING(2);
