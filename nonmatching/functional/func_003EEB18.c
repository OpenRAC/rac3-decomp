/* functional: high. Rewritten as plain C (draft used register asm). Passes object to func_003EDD40 explicitly (retail leaves a0 untouched across the call setup: register passthrough). Sets vtable D_001D9738 at +8, 0x80F00000 at +0x30, 0.5 at +0x18/+0x1C, 0.01 (0x3C23D70A) at +0x34/+0x38, 0 at +0x2C; returns object. 10 words differ (store order). */
extern void func_003EDD40(unsigned char *);
extern unsigned char D_001D9738[];
unsigned char *func_003EEB18(unsigned char *object) {
    func_003EDD40(object);
    *(void **)(object + 8) = D_001D9738;
    *(int *)(object + 0x30) = 0x80F00000;
    *(float *)(object + 0x18) = 0.5f;
    *(float *)(object + 0x34) = 0.01f;
    *(float *)(object + 0x1C) = 0.5f;
    *(float *)(object + 0x38) = 0.01f;
    *(int *)(object + 0x2C) = 0;
    return object;
}
