/* US draft of func_003B6B90 (rac3-uya-decomp func_003B16B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B6B90 */
__asm__(".extern D_001D8A68, 4");
__asm__(".extern D_001D8A6C, 4");
__asm__(".extern D_001D8A70, 4");
__asm__(".extern D_001D8A74, 4");
__asm__(".extern D_001D8A78, 4");
__asm__(".extern D_001D8A7C, 4");
__asm__(".extern D_001D8A80, 4");
__asm__(".extern D_001D8A84, 4");
__asm__(".extern D_001D8A88, 4");
__asm__(".extern D_001D8A8C, 4");
__asm__(".extern D_001D8A90, 4");
__asm__(".extern D_001D8A94, 4");
__asm__(".extern D_001D8A98, 4");
__asm__(".extern D_001D8AD0, 4");
__asm__(".extern D_001D8AD4, 4");
__asm__(".extern D_001D8AD8, 4");
__asm__(".extern D_001D8ADC, 4");
__asm__(".extern D_001D8AE0, 4");
__asm__(".extern D_001D8AC0, 8");
extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A70;
extern f32 D_001D8A74;
extern f32 D_001D8A78;
extern f32 D_001D8A7C;
extern f32 D_001D8A80;
extern f32 D_001D8A84;
extern f32 D_001D8A88;
extern f32 D_001D8A8C;
extern f32 D_001D8A90;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
extern f32 D_001D8AD0;
extern f32 D_001D8AD4;
extern f32 D_001D8AD8;
extern f32 D_001D8ADC;
extern f32 D_001D8AE0;
extern s32 D_001D8AC0[2];
extern void func_003BB180(void);
extern void func_003E9450();
extern s32 func_003BB118(u32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E9138_003B6B90(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E8348(s32, s32);

void func_003B6B90(void) {
    s32 i;
    s32 id4, id8, idC;
    s32 *tp;
    s32 off;
    f32 fi;
    s32 id23, id22, id21, id20, id18, idfp, id19, id17, id16;
    f32 w;
    f32 h;
    f32 *nv = &D_001D8A94;
    s32 r;

    func_003BB180();
    func_003E9450(0x4C003C);
    i = 0;
    tp = D_001D8AC0;
    off = 0;
    for (; i < 4; i++) {
        fi = i;
        id4 = 0x4C0034 + i;
        func_003E9450(id4);
        id8 = 0x4C0010 + i;
        r = func_003BB118(0);
        func_003E8FE8(id8, r + off, 0x8066CCFF, D_001D8A70, D_001D8A74 + D_001D8A6C + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id8, 1);
        func_003E7AC8(id8, 1);
        id23 = 0x4C0044 + i;
        func_003E8FE8(id23, (s32)tp, 0x8066CCFF, 0.66f, D_001D8A8C + D_001D8A6C + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id23, 1);
        func_003E7AC8(id23, 1);
        func_003E7A18(id23, 0);
        func_003E7928(id23, 1, 3);
        idC = 0x4C0048 + i;
        func_003E9138_003B6B90(idC, 0x706EC8FF, 0.638f, D_001D8A90 + D_001D8A68 * fi, 0.033203f, 0.04086523f, 0xEAA6);
        func_003E7A18(idC, 0);
        id22 = 0x4C0040 + i;
        r = func_00381FF0(0x238);
        func_003E8FE8(id22, r, 0x8066CCFF, 0.3475f, D_001D8A6C + 0.2195f + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id22, 1);
        func_003E7AC8(id22, 1);
        func_003E7A18(id22, 0);
        id21 = 0x4C0014 + i;
        r = func_003BB118(1);
        func_003E8FE8(id21, r + off, 0x8066CCFF, D_001D8A78, D_001D8A7C + D_001D8A6C + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id21, 1);
        func_003E7AC8(id21, 1);
        func_003E7928(id21, 2, 3);
        id20 = 0x4C0018 + i;
        r = func_003BB118(2);
        func_003E8FE8(id20, r + off, 0x8066CCFF, D_001D8A80, D_001D8A84 + D_001D8A6C + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id20, 1);
        func_003E7AC8(id20, 1);
        func_003E7928(id20, 2, 3);
        id18 = 0x4C001C + i;
        r = func_003BB118(3);
        func_003E8FE8(id18, r + off, 0x8066CCFF, D_001D8A88, D_001D8A8C + D_001D8A6C + D_001D8A68 * fi, 1.0f, 1.0f);
        func_003E7F20(id18, 1);
        func_003E7AC8(id18, 1);
        func_003E7928(id18, 2, 3);
        idfp = 0x4C0008 + i;
        w = (D_001D8AD0 + D_001D8AD4) * 0.5f;
        h = D_001D8ADC - 0.007f;
        func_003E9138_003B6B90(idfp, 0, w, D_001D8A6C + D_001D8A98 + D_001D8A68 * fi + 0.001953f, h, D_001D8AD8 - 0.012f - 0.001953f, 0);
        func_003E7838(idfp, 0x8000, 1);
        id19 = 0x4C0000 + i;
        func_003E9270(id19, 0x331465B7, w, D_001D8A6C + D_001D8A98 + D_001D8A68 * fi, D_001D8ADC, D_001D8AD8, 0.0035f, 0.006f);
        id17 = 0x4C0004 + i;
        func_003E9270(id17, 0x331465B7, 0.7618f, D_001D8A6C + D_001D8A98 + D_001D8A68 * fi, D_001D8AE0, D_001D8AD8, 0.0035f, 0.006f);
        id16 = 0x4C0020 + i;
        func_003E9138_003B6B90(id16, 0x8066CCFF, 0.883907f, D_001D8A90 + D_001D8A68 * fi, 0.033203f, 0.04086523f, 0);
        func_003E7E48(id16, 0xED26);
        func_003E8C68(id4, id8, id21, id20, id18, idfp, id19, id17);
        func_003E8A58(id4, id16, id22, id23, idC);
        func_003E8630(0x4C003C, id4);
        if (i < 4) {
            func_003E8710(idfp, (s32)func_003B42F8(i));
            func_003E7E48(idfp, 0);
        }
        tp++;
        off += 0x20;
    }
    func_003E9138_003B6B90(0x4C0038, 0x331465B7, *nv, D_001D8A6C + D_001D8A98, 0.2925f, 0.16f, 0);
    func_003E8630(0xD000B, 0x4C0038);
    func_003E8348(0x11, 0x4C003C);
}
/* localdecomp:end func_003B6B90 */
