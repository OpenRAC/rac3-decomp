/* US draft of func_003823D0 (rac3-uya-decomp func_003823F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003823D0 */
extern s32 func_00382360(s32);

s32 func_003823D0(s32 id) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_00382360(id);
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_003823D0 */
