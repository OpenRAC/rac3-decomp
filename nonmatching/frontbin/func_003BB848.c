/* Near miss of func_003BB848 with its file's own flags: tools/check.py reports 34 diff
   (the version it replaces: 35).
*/

/* PAL candidate for func_003BB848.
 *
 * The US draft (rac3-uya-decomp func_003B6368) only matched with @ps2as.
 * Retail materialises the addresses of the three table globals with
 * lui/addiu (%hi/%lo), i.e. they are *not* small data there, while the
 * count global D_001D8CE0 is loaded through $gp (small data, 4 bytes).
 * A global is small data for the compiler when its declared size fits in
 * -G8, so the three tables are declared as arrays of unknown size here
 * (the same way src/frontbin/3BB0D8.c declares D_001DA218/D_001DA240 for
 * func_003BB8F0, whose retail bytes also use lui/addiu).
 */

/* localdecomp:start func_003BB848 */
__asm__(".extern D_001D8CE0_003BB848, 4");
extern s32 D_001D8CE0_003BB848;
extern int D_001DA1F0[];
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BB848();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_003BB838();

void func_003BB848(s32 a) {
    s32 i;
    s32 *p;
    s32 *q;
    if (a >= 0 && a < D_001D8CE0_003BB848) {
        i = a * 4;
        q = D_001DA218;
        i += (int)q;
        i = *(s32 *)i * 4;
        q = D_001DA240;
        i += (int)q;
        p = (s32 *)i;
        *p = -1;
        func_13CA20();
        q = D_001DA1F0;
        i += (int)q;
        func_13C0B8(*(s32 *)i, 0, 0x400, 0, 0, 0, func_003BB838, (long)p);
        func_13CA28();
        func_13B620_003BB848();
    }
}
/* localdecomp:end func_003BB848 */
