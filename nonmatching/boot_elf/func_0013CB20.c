/* NTSC-U draft (Claude wave E): C of func_0013CB20 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 2 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_0013CB20").
 * Worker's note: 2 diff (from 18) through the asm_filter sq_ra rewrite: it needs 13C8D0.c's line WITHOUT -fopt-stack (`-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division`, a localdecomp_flags.txt row for func_0013CB20) plus a `func_0013CB20` row in ...
 */
/* localdecomp:start func_0013CB20 */
extern char D_001D52C8[];

s32 func_0013CB20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, long l) {
    s32 pkt[8];
    if (a == 0) {
        func_0011AF48(D_001D52C8);
    }
    pkt[0] = a;
    pkt[1] = b;
    pkt[2] = (e << 16) | (c & 0xFFFF);
    pkt[3] = (f << 16) | (d & 0xFFFF);
    pkt[4] = g;
    pkt[5] = h;
    pkt[6] = i;
    pkt[7] = j;
    return func_0013C578(0x2C, 0x20, pkt, k, l);
}
/* localdecomp:end func_0013CB20 */
