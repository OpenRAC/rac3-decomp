/* US draft of func_0013B620 (rac3-uya-decomp func_0013B620, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013B620 */
typedef struct { void (*fn)(s32, long); s32 pad; long arg; } E_13B620;
__asm__(".extern D_001D4DA0, 4");
__asm__(".extern D_001D4DB0, 4");
__asm__(".extern D_001D4DB4, 4");
__asm__(".extern D_001D4DB8, 4");
__asm__(".extern D_001D4DBC, 4");
__asm__(".extern D_001D4DC0, 8");
__asm__(".extern D_001D4DD0_0013B620, 8");
__asm__(".extern D_001D4DD8, 8");
__asm__(".extern D_001D4DE0, 4");
__asm__(".extern D_001D4DE4, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4E04, 4");
__asm__(".extern D_001D4E08, 8");
extern s32 *D_001D4DA0;
extern s32 D_001D4DB0;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_001D4DBC;
extern s32 *D_001D4DC0[2];
extern E_13B620 *D_001D4DD0_0013B620[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE0;
extern s32 D_001D4DE4;
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
extern s32 D_1D4A00;
extern void (*D_001D4E04)(s32, long);
extern long D_001D4E08;
extern s32 func_0013B818(void);
extern void func_11F0A0(s32);
extern void func_0013C908(void);
extern s32 func_0013CDF0(s32);
s32 func_0013B620(void) {
    if (D_001D4DA0 != 0 && func_0013B818() != 0) {
        if (D_001D4DBC != 0) {
            if (D_001D4E04 != 0) {
                D_001D4E04(*(s32 *)0x1D4944, D_001D4E08);
            }
            D_001D4E04 = 0;
            D_001D4DBC = 0;
        } else {
            s32 i = D_001D4DE0 != 1;
            s32 j;
            for (j = 0; j < *D_001D4DC0[i]; j++) {
                E_13B620 *e = (E_13B620 *)((j << 4) + (s32)D_001D4DD0_0013B620[i]);
                if (e->fn != 0) e->fn(((s32 *)D_001D4DD8[i])[j + 1], e->arg);
            }
        }
    }
    if (D_001D4DE8 != 0) {
        func_11F0A0(0);
        if ((u32)D_1D4A00 != 0xFFFFFFFF) {
            void (*fn)(s32, long) = (void (*)(s32, long))D_001D4DF0;
            if (fn != 0) {
                long a = *(long *)0x1D4DF8;
                D_001D4DF0 = 0;
                *(volatile long *)&D_001D4DF8 = 0;
                fn(D_1D4A00, a);
            }
            D_1D4A00 = 0;
            D_001D4DE8 = 0;
        }
    }
    if (D_001D4DA0 == 0) {
        if (*D_001D4DC0[D_001D4DE0] != 0 && D_001D4DE4 == 0) func_0013C908();
    }
    if (D_001D4DB4 != 0) {
        func_0013CDF0(1);
        if (D_001D4DB8 != 0) {
            D_001D4DB4 = 0;
            D_001D4DB8 = 0;
            if (D_001D4DB0 != 0) ((void (*)(s32))D_001D4DB0)(1);
        }
    }
    return D_001D4DA0 != 0 || D_001D4DE8 != 0;
}
/* localdecomp:end func_0013B620 */
