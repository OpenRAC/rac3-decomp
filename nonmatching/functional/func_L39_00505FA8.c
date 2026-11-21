/* functional: high. EXACT match. */
extern void func_L39_004F4818(s32);

typedef struct S_00505FA8 {
    s32 f0;
    s32 f4;
} S_00505FA8;

void func_L39_00505FA8(S_00505FA8 *p) {
    if (p->f0 == 1) {
        func_L39_004F4818(p->f4);
    }
}
