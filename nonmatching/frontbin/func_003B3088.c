/* US draft of func_003B3088 (rac3-uya-decomp func_003ADAE0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003B3088 */
extern u8 D_001D8880;
extern void func_003E82F8();
extern void *func_003E6C08();
extern void func_003E6A60();
extern s32 func_003E6518();
extern s32 func_003E6F18();
void func_003B3088(void) {
    register void *object __asm__("$2");
    register void *base __asm__("$4");
    register u8 *page __asm__("$3");
    if (D_001D8880 == 0) {
        func_003E82F8();
        page = (u8 *)0x1E0000;
        __asm__ volatile("" : "+r"(page));
        base = page - 0x5648;
        if (*(s32 *)((u8 *)base + 4) != 0) {
            object = base;
        } else {
            object = func_003E6C08(base);
        }
        func_003E6A60(object);
        object = (void *)func_003E6518(0);
        func_003E6F18(object, 0x14);
    }
}
/* localdecomp:end func_003B3088 */
