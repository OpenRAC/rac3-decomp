/* Near miss of func_003C3BE8 with its file's own flags: tools/check.py reports 4 diff
   (the version it replaces: 19).
   What differs: 4 diffs left, all in the pi constant: retail builds it inline (`lui $at,0x4049
   / ori $at,$at,0xfdb / mtc1 $at,$f12`) into the argument register $f12 and multiplies `mul.s
   $f12,$f14,$f12`; the candidate gets the same inline lui/ori/mtc1 form but with the wrong
   scratch/copy registers (`lui $v0 / ori $v0 / mtc1 $v0,$f0`) and the multiply operands
   swapped (`mul.s $f12,$f0,$f14`). A plain float literal cannot do it with the file's flags:
   SN ee-gcc 2.95.3 pools any float constant with non-zero low 16 bits into .lit4 (the draft's
   `lwc1 $f12,-0x4000($gp)`), while only lui-form constants (1.0f,...
*/

/* PAL candidate for func_003C3BE8 (4 diffs).

   Retail materialises the pi constant inline:
       lui   $at, 0x4049
       ori   $at, $at, 0xfdb
       mtc1  $at, $f12
       jal   func_0038D098
         mul.s $f12, $f14, $f12
   A plain float literal cannot produce that with this file's flags: SN ee-gcc
   2.95.3 pools every float constant whose low 16 bits are non-zero into .lit4
   (the draft's "lwc1 $f12,-0x4000($gp)"); only lui-form constants (1.0f, 0.5f)
   are built inline.  Building the constant from its bit pattern through a union
   avoids the pool and reproduces retail's inline lui/ori/mtc1 form; what is
   left is the scratch register ($v0 vs $at), the copy target ($f0 vs $f12) and
   the multiply's operand order ($f0,$f14 vs $f14,$f12). */

extern f32 func_0038D098(f32);
f32 func_003C3BE8(f32 a, f32 b, f32 t) {
    union { u32 i; f32 f; } pi;
    if (t == 0.0f) return a;
    if (t == 1.0f) return b;
    pi.i = 0x40490FDB;
    return a + (b - a) * ((1.0f - func_0038D098(t * pi.f)) * 0.5f);
}
