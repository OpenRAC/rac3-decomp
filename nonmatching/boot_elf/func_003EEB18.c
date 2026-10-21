/* US draft of func_003EEB18 (rac3-uya-decomp func_003EE9B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003EEB18 */
extern void func_003EDD40(void);
extern unsigned char D_001D9738[];

void *func_003EEB18(unsigned char *object) {
    register float half __asm__("$f0");
    register float small __asm__("$f1");
    register void *vtable __asm__("$4");
    register void *result __asm__("$2");
    register int color __asm__("$3");

    func_003EDD40();
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
/* localdecomp:end func_003EEB18 */
