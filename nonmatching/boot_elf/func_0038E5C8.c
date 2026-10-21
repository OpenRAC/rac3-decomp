/* Near miss of func_0038E5C8 with its file's own flags: tools/check.py reports 4 diff
   (the US draft it started from: 106).
   What differs: Best candidate (work/func_0038E5C8.c) is down from 106 to 4 diffs by declaring
   the global as an unsized array (`extern E_3899B8 *D_001D55C4_arr[];`, the "declaration rule"
   in docs/us/compiler_matrix_findings.md), which puts GCC's loads of it in the `lui`/`%lo`
   form retail uses. Two things still differ: (1) the delay slot of the loop's back-branch -
   retail reloads the global there through `$gp` (`lw $v1, -0x72EC($gp)`) while our reload
   expands to `lui`+`lw`, which does not fit a delay slot, so ours has a `nop` and a 4-byte-off
   branch offset (2 words); (2) the destination register of the...
*/

/* US draft of func_0038E5C8 (rac3-uya-decomp func_0038E510, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_0038E5C8 */
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_arr[];
s32 func_0038E5C8(f32 *w, f32 *h, s32 mode) {
    s32 r;
    *w = 0.0f;
    *h = 0.0f;
    r = 0;
    if (D_001D55C4_arr[0] != 0) {
        if (mode != 0) {
            *w = (f32)((D_001D55C4_arr[0][0x41].w4 >> 17) & 0x3F);
            *h = (f32)((D_001D55C4_arr[0][0x41].w4 >> 9) & 0xFF) * 0.25f;
            r = 1;
        } else {
            s32 n = func_0038E5A8();
            if (n > 0) {
                s32 i;
                u32 mx = 0;
                for (i = 0; i < n; i++) {
                    u32 a = (D_001D55C4_arr[0][i].w4 >> 17) & 0x3F;
                    if (mx < a) {
                        mx = a;
                        *h = (f32)((D_001D55C4_arr[0][i].w4 >> 9) & 0xFF) * 0.25f;
                    }
                }
                *w = (f32)mx;
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_0038E5C8 */
