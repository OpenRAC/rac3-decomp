/* Near miss of func_0038E1E8 with its file's own flags: tools/check.py reports 2 diff
   (the US draft it started from: 106).
   What differs: 2 words differ (loop base reload): retail's loop delay slot has `lw $v1,
   -0x72ec($gp)` (a $gp-relative reload of D_001D55C4) and its loop is one word longer
   (backward branch -0x6c vs our -0x74); ours has `nop` there because with the unsized
   declaration gcc hoists the base-pointer load out of the loop entirely (no reload after the
   `*h` store). Everything else matches byte for byte. The three `lui $vX,0x1d` + `lw
   $vX,0x55c4($vX)` accesses and the `lw $v0,0x20c($v0)` in the mode!=0 branch now match
   exactly.
*/

/* localdecomp:start func_0038E1E8 */
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E1E8l[];
s32 func_0038E1E8(f32 *w, f32 *h, s32 mode) {
    s32 r;
    *w = 0.0f;
    *h = 0.0f;
    r = 0;
    if (D_001D55C4_0038E1E8l[0] != 0) {
        E_3899B8 *d = D_001D55C4_0038E1E8l[0];
        if (mode != 0) {
            *w = (f32)((d[0x41].w4 >> 17) & 0x3F);
            *h = (f32)((D_001D55C4_0038E1E8l[0][0x41].w4 >> 9) & 0xFF) * 0.25f;
            r = 1;
        } else {
            s32 n = func_0038E1C8();
            if (n > 0) {
                s32 i;
                u32 mx = 0;
                for (i = 0; i < n; i++) {
                    u32 a = (D_001D55C4_0038E1E8l[0][i].w4 >> 17) & 0x3F;
                    if (mx < a) {
                        mx = a;
                        *h = (f32)((D_001D55C4_0038E1E8l[0][i].w4 >> 9) & 0xFF) * 0.25f;
                    }
                }
                *w = (f32)mx;
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_0038E1E8 */
