/* functional: high. EXACT match. */
extern void func_L39_004F47F8(s32);

typedef struct S_00505F88 {
    s32 f0;
    s32 f4;
} S_00505F88;

void func_L39_00505F88(S_00505F88 *p) {
    if (p->f0 == 1) {
        func_L39_004F47F8(p->f4);
    }
}
