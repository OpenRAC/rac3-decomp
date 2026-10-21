/* US draft of func_003C1848 (rac3-uya-decomp func_003C1740, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003A7DB0. */


/* localdecomp:start func_003C1848 */
extern void func_003A6B90(void *);
extern void func_003A7DB0(void *);
extern void func_003A8850();
void func_003C1848(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A6B90(p);
    func_003A7DB0(p);
    func_003A8850();
}
/* localdecomp:end func_003C1848 */
