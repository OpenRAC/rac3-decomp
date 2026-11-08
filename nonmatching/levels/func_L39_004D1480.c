/* func_L39_004D1480: near miss (Sonnet w4 p2w2), 5 diff; prologue scheduling only (sd/sw/move a3 order) */
/* size 72, file src/levels/39_multiplayer_menu/L39_004CCE58.c, level 39 */
/* port twin wrong; written from asm */
extern s32 func_L39_004F6BF0(s32 a, s32 *b, s32 *c, s32 d, s32 e, s32 f);
extern void func_L39_004F4F18(s32 *p);

s32 func_L39_004D1480(s32 a0) {
    s32 buf[4];
    s32 v;
    s32 r;
    r = func_L39_004F6BF0(a0, buf, &v, 0, 0, 0);
    func_L39_004F4F18(&a0);
    return r;
}
