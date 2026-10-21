/* US draft of func_003B3440 (rac3-uya-decomp func_003B32A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003B3440 */
extern u8 D_001D8880;
extern void func_003E86B0();
extern void *func_003E6FC0();
extern void func_003E6E18();
extern s32 func_003E68D0();
extern s32 func_003E72D0();
void func_003B3440(void) {
    register void *object __asm__("$2");
    register void *base __asm__("$4");
    register u8 *page __asm__("$3");
    if (D_001D8880 == 0) {
        func_003E86B0();
        page = (u8 *)0x1E0000;
        __asm__ volatile("" : "+r"(page));
        base = page - 0x5648;
        if (*(s32 *)((u8 *)base + 4) != 0) {
            object = base;
        } else {
            object = func_003E6FC0(base);
        }
        func_003E6E18(object);
        object = (void *)func_003E68D0(0);
        func_003E72D0(object, 0x14);
    }
}
/* localdecomp:end func_003B3440 */
