/* US draft of func_003C5110 (rac3-uya-decomp func_003C4FA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003C5110 */
int func_003C5110(unsigned char *object) {
    unsigned char *link;
    int flags;

    if (object != 0)
        goto check_flags;
failure:
    return 0;
check_flags:
    flags = *(unsigned short *)(object + 0x34) & 0x20;
    __asm__ volatile(".word 0");
    if (flags == 0)
        goto failure;
    link = *(unsigned char **)(object + 0x68);
    if (link == 0)
        goto failure;
    return *(int *)(link + 8);
}
/* localdecomp:end func_003C5110 */
