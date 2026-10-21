/* US draft of func_00392F08 (rac3-uya-decomp func_0038E6D0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00392F08 */
extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
__asm__(".extern D_0022758C, 16");
__asm__(".extern D_001DA058, 16");
s32 func_00392F08(u32 value, s32 *result) {
    register u32 amount __asm__("$6") = value;
    register s32 page __asm__("$2");
    register s32 base __asm__("$4");
    register s32 total __asm__("$3");
    if (amount > 0x40000) {
        *result = 0;
        return -1;
    }
    page = D_001D5BDC;
    if (page != 0) {
        page = 0x220000;
        goto calculate;
    }
    page = D_001D5C90;
    if (page != 0) {
        goto cached;
    }
    page = 0x220000;
calculate:
    base = D_001DA058;
    __asm__ volatile("" : "+r"(base));
    total = *(s32 *)(page + 0x760C);
    total += base;
    total -= amount;
    *result = total;
    goto done;
cached:
    *result = page;
done:
    return 0;
}
/* localdecomp:end func_00392F08 */
