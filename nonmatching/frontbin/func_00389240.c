/* US draft of func_00389240 (rac3-uya-decomp func_00384B68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389240 */
extern s32 D_001D9BF4_00389240;
extern s32 D_001DA050_00389240;
extern s32 D_001D9C00;
extern long D_00226000_00389240[];
extern s32 D_001D9EA0_00389240;
extern s32 D_001D9EAC_00389240;
extern volatile s32 D_001D9EB0_00389240;
extern s32 D_001D9BFC;
extern s32 D_001D4BB4_00389240;
extern s32 D_001D4BB0_00389240;
extern unsigned long D_001D58E0, D_001D58E8;
extern s32 D_001D58F0;
extern s32 D_001A1ED0_00389240[];
__asm__(".extern D_001D9BFC, 4");
__asm__(".extern D_001D58E0, 8");
__asm__(".extern D_001D58E8, 8");
__asm__(".extern D_001D58F0, 4");
extern void func_0038E138(void);
void func_00389240(s32 a) {
    s32 n;
    s32 t;
    s32 u;
    s32 i;
    s32 c;
    s32 j;
    long *p;
    t = D_001DA050_00389240;
    D_001D9BF4_00389240 = t;
    t += 0x10;
    D_001DA050_00389240 = t;
    u = D_001D4BB4_00389240;
    n = D_001D9C00;
    D_001D4BB0_00389240 = u;
    D_001D9BFC = 0;
    if (n > 0) {
        p = D_00226000_00389240;
        for (c = n; c != 0; c--) {
            *p = 0;
            p += 2;
        }
    }
    D_001D58E0 = 0;
    D_001D58E8 = 0;
    D_001D58F0 = 0;
    if (a == 0) {
        for (i = 0; i < *(s32 *)(D_001D9EA0_00389240 + 0x44); i++) {
            u16 *h = (u16 *)((i << 3) + D_001D9EAC_00389240 + 4);
            if (*h >= (D_001A1ED0_00389240[1] >> 8)) {
                *h = 0;
            }
        }
        for (j = 0; j < *(s32 *)(D_001D9EA0_00389240 + 0x24); j++) {
            *(u16 *)(D_001D9EB0_00389240 + j * 8 + 4) = 0;
        }
    }
    func_0038E138();
}
/* localdecomp:end func_00389240 */
