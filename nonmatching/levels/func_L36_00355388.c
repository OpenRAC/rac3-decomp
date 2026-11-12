/* func_L36_00355388: near miss, level 36 (Vidcomic 1 Special Edition). 10 differences: two 16-byte copies (lq/sq) from a1 into a0->0x68; retail copies a1 into $v1 (move) in the beqz delay slot and loads both quadwords from $v1 while reusing $a1 for the constant 2, ours loads from $a1 directly; typedef, struct, long, local-pointer wordings tried */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad[0x20]; V4 a; V4 b; } O;
void func_L36_00355388(u8 *a0, V4 *a1) {
    O *p;
    if (a0 != 0) {
        p = *(O **)(a0 + 0x68);
        p->a = *a1;
        *(s32 *)((u8 *)p + 0x5C) = 2;
        p->b = *a1;
    }
}
