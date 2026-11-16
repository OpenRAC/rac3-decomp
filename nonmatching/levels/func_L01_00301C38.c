/* NTSC-U draft (Claude wave K): C of func_L01_00301A90, the NTSC-U twin of func_L01_00301C38, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 198 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L01_00301A90", whose code is not the PAL one).
 * Worker's note: 198 diff words with the two extras the PAL line lacks (vu0 vec_* + @ps2as float immediates) and divs row 'func_L01_00301A90 2 2' injected; same 210 words, opcode similarity 0.82 (33 hunks). Left: loop-invariant placement (retail keeps addiu $gp array address ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00301A90 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags
   (PAL line: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses), and the divs row
   'func_L01_00301A90 2 2' (checked: the two div.s have 2 nops each).
   k26 medium notes: 198 diff words, opcode similarity 0.82, 33 hunks, same length (210 words). Decode: tmp = D_L01_001E2A40 -
   (obj+0x10) scaled -0.3 then *0.1 into vb, 4 sparkles (loop count 3..0 via bgez), per sparkle two
   func_L01_00468C38 calls and vec_add_ab(va, va, vb); `found` is a PLAIN local (if (h >= 0x31) found = 1 becomes movz and
   the pseudo spills to sp+0x20, as in retail; a struct field gives a branch instead). D_001DC5x0_sda arrays are
   declared [2] with .extern 8 so cc1 treats them as small (addiu gp form). Open: retail keeps `addiu $v1,$gp,-0x340`
   and the st+0x58/st+0x60 bases INSIDE the loop (not hoisted), and uses both s6 (i*2) and s7 (&h[i]) as ivs plus
   fp as down counter; mine hoists the array address into a saved reg and shifts the s-register numbering. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00301A90;
typedef struct {
    V4_00301A90 a;
    V4_00301A90 b;
    s32 found;
} Loc_00301A90;

extern V4_00301A90 D_L01_001E2A40;
extern u8 *D_L01_00221118[];
extern f32 D_001DC570_sda[2];
__asm__(".extern D_001DC570_sda, 8");
extern f32 D_001DC580_sda[2];
__asm__(".extern D_001DC580_sda, 8");
extern f32 D_001DC590_sda[2];
__asm__(".extern D_001DC590_sda, 8");
extern s32 D_001DC558_sda;
__asm__(".extern D_001DC558_sda, 4");
extern s32 D_001DC55C_sda;
__asm__(".extern D_001DC55C_sda, 4");
extern s32 D_001DC560_sda;
__asm__(".extern D_001DC560_sda, 4");
extern s32 D_001DC564_sda;
__asm__(".extern D_001DC564_sda, 4");
extern s32 D_001DC568_sda;
__asm__(".extern D_001DC568_sda, 4");
extern s32 D_001DC56C_sda;
__asm__(".extern D_001DC56C_sda, 4");
extern s32 D_001DC50C_sda;
__asm__(".extern D_001DC50C_sda, 4");

extern void func_00388830(void *, void *, f32);
extern s32 func_003883C8(void *);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L01_00301A90(u8 *obj) {
    V4_00301A90 va;
    V4_00301A90 vb;
    s32 found;
    u8 *st;
    s16 *h;
    f32 *fa;
    s32 i;
    s32 col;
    s32 al;
    s32 ah;
    f32 f1;
    f32 z;
    f32 d;
    f32 t;
    f32 keep;
    u8 *r;

    st = *(u8 **)(obj + 0x68);
    vec_sub_ab(&va, &D_L01_001E2A40, obj + 0x10);
    func_00388830(&va, &va, -0.3f);
    found = 0;
    func_00388830(&vb, &va, 0.1f);
    vec_add_ba(&va, &va, obj + 0x10);
    z = va.z;
    for (i = 0; i < 4; i++) {
        if (func_003883C8(st + 0x58 + i * 2) != 0) {
            continue;
        }
        h = (s16 *)(st + 0x58);
        fa = (f32 *)(st + 0x60);
        f1 = fa[i] + D_001DC570_sda[i];
        if (h[i] >= 0x31) {
            found = 1;
        }
        fa[i] = f1;
        if (255.0f <= f1) {
            fa[i] = f1 - 255.0f;
        } else if (f1 <= 0.0f) {
            fa[i] = f1 + 255.0f;
        }
        keep = fabs_asm(0.5f - (f32)(255 - h[i]) / 255.0f);
        if (st[0x57] != 0) {
            col = func_003894A0(D_001DC560_sda, D_001DC564_sda, keep);
        } else {
            col = func_003894A0(D_001DC558_sda, D_001DC55C_sda, keep);
        }
        d = 1.0f - (f32)h[i] / (f32)D_001DC50C_sda;
        al = col >> 24;
        va.z = z + D_001DC590_sda[i];
        t = 1.0f - d;
        ah = (s32)((f32)al * t) << 24;
        r = func_L01_00468C38(&va, (col & 0xFFFFFF) | ah,
                              (u8)(s32)fa[i], D_001DC56C_sda, 0, 2, 1, 0,
                              D_001DC580_sda[i] * d);
        if (r != 0) {
            r[2] = *D_L01_00221118[0xF8 / 4];
        }
        r = func_L01_00468C38(&va, ah | 0xFFFFFF,
                              (u8)(s32)fa[i], D_001DC56C_sda, D_001DC568_sda, 2, 1, 0,
                              D_001DC580_sda[i] * (d * 0.7f));
        if (r != 0) {
            r[2] = *D_L01_00221118[0xF8 / 4];
        }
        vec_add_ab(&va, &va, &vb);
    }
    return found;
}
/* localdecomp:end func_L01_00301A90 */
