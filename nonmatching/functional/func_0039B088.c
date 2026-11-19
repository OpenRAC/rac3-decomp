/* functional: high. US draft re-verified against PAL asm (every offset, constant, global, bit field); its inline plzcw replaced by plzcw_asm() from include/vu0.h. Only diff vs retail: unsized D_ externs in the file context compile to lui/lw instead of $gp (66 words, addressing only). T_395EB8/E_395EB8/externs come from the file context (39AD90.c). */
long func_0039B088(u8 *p) {
    T_395EB8 t;
    s32 w, h, s, a, cbp, tbp;
    long r;
    E_395EB8 *e;
    w = *(s32 *)(p + 8);
    w = plzcw_asm(w);
    h = *(s32 *)(p + 0xC);
    h = plzcw_asm(h);
    t.tw = 0x1E - w;
    t.th = 0x1E - h;
    s = t.tw - 6;
    if (s < 0) s = 0;
    a = D_001D4BB0;
    cbp = a >> 8;
    a += 0x400;
    tbp = a >> 8;
    t.data = p + 0x20;
    t.clut = p + 0x420;
    t.f14 = 0x400;
    D_001D4BB0 = a + (1 << (t.tw + t.th));
    r = (long)tbp | ((long)(1 << s) << 14) | (0x13UL << 20) | ((long)t.tw << 26) | ((long)t.th << 30) | (1UL << 34) | ((long)cbp << 37) | (4UL << 61);
    if (D_001D9BFC < 0x40) {
        e = &D_00225C00[D_001D9BFC];
        e->data = t.data;
        e->f6 = cbp;
        e->f4 = 0;
        D_00225C00[D_001D9BFC].clut = t.clut;
        e->tw = t.tw;
        e->th = t.th;
        e->fE = tbp;
        D_001D9BFC++;
    }
    return r;
}
