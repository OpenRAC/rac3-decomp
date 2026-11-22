/* US draft of func_003EE760 (rac3-uya-decomp func_003E91F8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */
/* Plain-C near miss (2026-11-22): the C below has no pins, barriers or volatile and is
   6 differences (tools/check.py, see nonmatching/README.md). The US draft's form, which reaches
   MATCH only with register pins and empty asm barriers (not allowed here), is kept as a study
   aid in the comment at the end of this file. */

/* localdecomp:start func_003EE760 */
extern void func_003ED988(void);
extern unsigned char D_001D9738[];

void *func_003EE760(unsigned char *object) {
    func_003ED988();
    *(float *)(object + 0x18) = 0.5f;
    *(int *)(object + 0x2C) = 0;
    *(float *)(object + 0x34) = 0.01f;
    *(float *)(object + 0x1C) = 0.5f;
    *(void **)(object + 8) = D_001D9738;
    *(int *)(object + 0x30) = 0x80F00000;
    *(float *)(object + 0x38) = 0.01f;
    return object;
}
/* localdecomp:end func_003EE760 */

/* The US draft's form (register pins and asm barriers; a study aid, never matched C):

extern void func_003ED988(void);
extern unsigned char D_001D9738[];

void *func_003EE760(unsigned char *object) {
    register float half __asm__("$f0");
    register float small __asm__("$f1");
    register void *vtable __asm__("$4");
    register void *result __asm__("$2");
    register int color __asm__("$3");

    func_003ED988();
    half = 0.5f;
    vtable = D_001D9738;
    small = 0.01f;
    color = 0x80F00000;
    result = object;
    __asm__ volatile("" : "+r"(result));
    *(void **)(object + 8) = vtable;
    *(int *)(object + 0x30) = color;
    *(float *)(object + 0x18) = half;
    *(float *)(object + 0x34) = small;
    *(float *)(object + 0x1C) = half;
    *(float *)(object + 0x38) = small;
    *(int *)(object + 0x2C) = 0;
    __asm__ volatile("" : "+r"(object));
    return result;
}
*/
