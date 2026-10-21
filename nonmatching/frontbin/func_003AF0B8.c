/* US draft of func_003AF0B8 (rac3-uya-decomp func_003A9B10, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


extern void *func_003ABE28(void *);
extern u8 *func_003AED10(u8 *);
extern void func_00121760(void *, void *);
extern s32 func_003A26F0();
extern void func_003ABE30(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2750(s32);
extern void func_003ABD38(void *);
extern void func_003AEE38(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
/* localdecomp:start func_003AF0B8 */
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
void *func_003AF0B8(u8 *a0, s32 a1) {
    s32 i;
    s32 *p;
    s32 z;
    V8_3A9B10 v;
    u32 j;
    s32 sz;
    u8 *t;

    p = (s32 *)(a0 + 4);
    for (i = 0x707; i != -1; i--) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
    func_003ABE28(a0 + 0x1FC90);
    func_003AED10(a0 + 0x1FCA8);
    func_121760(D_001D8770, a1);
    sz = 0x24F10;
    D_001D5C78 = (s32)a0;
    *(s32 *)a0 = ((s32)a0 + sz + 3) & ~3;
    *(s32 *)(a0 + 0x24DC8) = sz;
    t = D_00160C40;
    func_003A26F0(a0 + 0x7090, *(s32 *)(t + 0x61C8) + *(s32 *)(t + 0x4954), *(s32 *)(t + 0x61CC));
    ((void (*)(void *, u32, s32, s32))func_003ABE30)(a0 + 0x1FC90, 0x10, (s32)(a0 + 4), 0x7080);
    *(s32 *)(a0 + 0x24DCC) = 0;
    *(s32 *)(a0 + 0x24DD0) = 0;
    *(s32 *)(a0 + 0x24DD4) = 0;
    *(s32 *)(a0 + 0x24DD8) = 0;
    *(s32 *)(a0 + 0x24DE4) = 0;
    *(s32 *)(a0 + 0x24DE8) = 0;
    *(s32 *)(a0 + 0x24DEC) = 0;
    func_11A264(a0 + 0x24DF0, 0, 0x20);
    func_11A264(a0 + 0x24E10, 0, 0x100);
    func_11F0A0(0);
    z = 0;
    do {
        v = *(V8_3A9B10 *)D_001D8790;
    } while (z);
    j = 0;
    do { j++; } while (j < 8);
    func_003A2750(1);
    func_003ABD38(a0 + 0x7090);
    func_003AEE38(a0 + 0x1FCA8, a0, a0 + 0x1FC90);
    return a0;
}
/* localdecomp:end func_003AF0B8 */
