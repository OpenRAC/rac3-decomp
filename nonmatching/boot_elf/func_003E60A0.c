/* US draft of func_003E60A0 (rac3-uya-decomp func_003E5F58, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003E60A0 */
extern s32 D_001D96D0[];
extern s32 func_003E6730();
extern s32 func_003E74D0();
extern void func_003E74C0();
s32 func_003E60A0(s32 *a0, u32 a1, s32 a2) {
    s32 *p;
    s32 *obj;
    s32 *s1;
    if (a1 < 0x23) {
        if (*(s32 *)(a1 * 4 + *a0 + 0x50) == 0) {
            obj = (s32 *)func_003E6730(a0, a2);
            if (obj != 0 && ((s32 (*)())(*(s32 *)(obj[2] + 0x10)))(obj, D_001D96D0[0]) != 0) s1 = obj; else s1 = 0;
            if (s1 != 0) {
                p = (s32 *)(a1 * 4 + *a0); p += 0x14;
                if (*p != 0) func_003E74D0(*p);
                *p = (s32)s1;
                func_003E74C0(s1);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_003E60A0 */
