/* functional: high. EXACT with --no-context. In the file's own context it clashes: src/levels/39_multiplayer_menu/L39_00517308.c declares it 'extern void func_L39_00517510(void *, s32)' but retail returns s32 (0 / 0x206 / 0x217 / callee error), so that declaration (and the other files declaring it void) must become s32. */
extern s32 func_L39_0050C568(void *, u32 *);
extern void *func_L39_004F75B0(void *, u32);
extern void func_L39_004F74E8(void *, s32, s32);

typedef struct S_00517510 {
    char pad0[0x30];
    void *f30;
    u32 f34;
    s32 f38;
    s32 f3C;
} S_00517510;

s32 func_L39_00517510(void *arg0, s32 flag) {
    S_00517510 *p = arg0;
    u32 sz;
    s32 r;
    void *buf;

    r = func_L39_0050C568(p, &sz);
    if (r != 0) {
        return r;
    }
    if (sz < 12) {
        return 0x217;
    }
    p->f3C = flag ? sz - 11 : sz;
    p->f38 = 0;
    func_L39_004F74E8(p->f30, 0, p->f34);
    buf = func_L39_004F75B0(p->f30, sz);
    p->f30 = buf;
    if (buf == 0) {
        p->f34 = 0;
        return 0x206;
    }
    p->f34 = sz;
    return 0;
}
