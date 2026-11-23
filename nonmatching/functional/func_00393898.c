/* functional: high. 3 words differ. Loop over 13 slots comparing id at +0x64. */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern s32 func_00393728(s32, s32, s32, s32, s32, s32, s32);
s32 func_00393898(s32 id) {
    S_38ED78 *p = D_00331AE0;
    s32 i;
    for (i = 0; i < 13; i++) {
        if (p[i].id == id) break;
    }
    if (i < 13) {
        func_00393728(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
