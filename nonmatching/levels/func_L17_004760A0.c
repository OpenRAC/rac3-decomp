/* Level 17 (Crash Site), PAL. 13 diff with check.py. The same code as func_L02_00473410 (other data, same open problem): retail increments `i` in place in case 1 (`addiu $s2,$s2,1` before the inner loop) and keeps `&D[i]` / `&D[i].c` in $s1/$s0; this C (the level-2 draft renamed) gives `addiu $s4,$s2,1` ... `move $s2,$s4`, so `j` and the flag temporary move up one register. Also tried here: `S *e = &D[i++]` in case 1 (118 diff: one pointer instead of two), `int k = i++` with `D[k]` (37: `i` in place but $s2..$s4 rotated and an extra `move`), `i++` before the inner loop with `D[i - 1]` (145). The jump table is jtbl_002C4990 (five entries).
 * Round 16 (b27-k2b, 2026-11-20): the in-place `i++` needs the PRE temporary (reg 339 in gcse's dump) to share `$s2` with `i`, which happens only when its global-alloc priority (floor_log2(refs) * refs / live length: 4 refs over the whole inner loop, about 0.2) beats the flag temporary's (9 refs, about 0.75), and neither the flag temporary's nor the PRE temporary's reference counts can be moved by any source form found. Tried again (all 148 to 158 diff, so the draft's shape stays the best): `S *e = &D[i]` plus an early `i++` with `e->c`/`e->flag` (148), `&D[i++]` (149), `i++` before the loop with `D[i - 1]` (158), a `u8 v` flag variable with an early `i++` (148); `--all-modes`: S 13, N 151 (the file has no split-addresses difference). func_L04_004AC5A0 (13 with this shape) and func_L12_0049E1F0 share the cause; a fix for one fixes all of them.
 */
typedef struct S_4760A0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4760A0;
extern S_4760A0 D_L17_002F3CE8[];
__asm__(".extern D_L17_002F3CE8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L17_004760A0(void) {
    int i;
    int j;
    i = 0;
    while (D_L17_002F3CE8[i].a0) {
        switch (D_L17_002F3CE8[i].kind) {
        case 0:
            D_L17_002F3CE8[i].flag = (D_00142BA0[D_L17_002F3CE8[i].c >> 2] & (1 << (D_L17_002F3CE8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L17_002F3CE8[i].flag = 0;
            for (j = 0; ((unsigned *)D_L17_002F3CE8[i].c)[j]; j++) {
                D_L17_002F3CE8[i].flag = D_L17_002F3CE8[i].flag ||
                    (D_00142BA0[((unsigned *)D_L17_002F3CE8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L17_002F3CE8[i].c)[j] & 0x1F))) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L17_002F3CE8[i].flag = (D_00142BA0[D_L17_002F3CE8[i].c >> 2] & (1 << (D_L17_002F3CE8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L17_002F3CE8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}
