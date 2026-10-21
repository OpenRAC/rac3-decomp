/* Near miss of func_003BFD60 with its file's own flags: tools/check.py reports 48 diff
   (the version it replaces: 54).
   What differs: 44 diff: (1) the two float constants 210000.0f (0x484D1400) and 0.016666668f
   (0x3CA3D70B) are materialised by the compiler through the `.lit4` pool (`lwc1
   $f20/-0x4000($gp)`, `lwc1 $f1/-0x3ffc($gp)`) instead of retail's inline `lui $at / ori $at /
   mtc1` - with the file's flags (default assembler `ee-as`) every float literal whose low 16
   bits are non-zero goes to `.lit4`, only literals with a zero low half (e.g. 1.0f) come out
   inline; (2) the base of the pointer array is built in no-split form (`lui $v1, 0x1e; addiu
   $s0, $v1, -0x5ce4`) where retail has split form (`lui $s0, 0x1e; addiu $s0,...
*/

/* US draft of func_003BFD60 (rac3-uya-decomp func_003BA850, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BFD60 */
__asm__(".extern D_001D8E64, 4");
__asm__(".extern D_001D8E68, 4");
__asm__(".extern D_001D8E6C, 4");
__asm__(".extern D_001D8E70, 4");
extern u8 *D_001DA31C[6];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern S_3BA850 D_001DA318_003BFD60;
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFAC8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003BFD60(S_3BA368 *a) {
    s32 i;
    u8 *e = D_00380060;
    u8 **p = D_001DA31C;
    u8 *r;
    f32 k = 420000.0f / 2.0f;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_003BFAC8(e, (s32)a, D_001D8E68, 0, 0, -1, 0, -1, 0, 0, D_001D8E6C * k, D_001D8E70, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850 *q = &D_001DA318_003BFD60; f32 k2 = 1.0f / 60.0f; q->f1C = D_001D8E64 * k2; }
}
/* localdecomp:end func_003BFD60 */
