/* func_L36_003553B8: near miss, level 36 (Vidcomic 1 Special Edition). about 62-78 differences: needs the divs_nops row 'func_L36_003553B8 2 2' (not committed); loop and calls are right, but retail keeps lo/hi in $f22/$f21 swapped from ours (div.s of a3 first into $f22), keeps i<<2 in its own saved register $s2 and the table pointer in $s5 (frame 0x70, ours 0x60); several wordings of the slot index and the lo/hi order tried */
__asm__(".extern D_L36_001DD7F8, 8");
extern f32 D_L36_001DD7F8[2];
extern f32 D_L36_001DD87C;
extern f32 D_L36_001DD92C;
extern f32 D_L36_001DD930;
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L36_00353F58(u8 *, f32 *, s32, f32);
typedef struct { u8 pad0[0x80]; s32 f80; u8 pad84[8]; u8 *arr[6]; } S_3553B8;
void func_L36_003553B8(u8 *a0, f32 *a1, f32 a2, f32 a3) {
    S_3553B8 *s = *(S_3553B8 **)(a0 + 0x68);
    s32 i;
    f32 *q;
    f32 lo;
    f32 hi;
    f32 ang;
    s32 off;
    f32 v[4];
    if (a2 != a3) {
        i = 0;
        q = D_L36_001DD7F8;
        lo = a3 / (f32)*(s16 *)((u8 *)s + 4);
        hi = a2 / (f32)*(s16 *)((u8 *)s + 4);
        for (; i < 6; i++, q++) {
            if (lo < *q && *q <= hi) {
                off = i << 2;
                s->f80 &= ~(1 << i);
                ang = func_0038D160(a1[0], a1[2]);
                v[0] = func_0038D098(func_0038DB48(ang + func_003824E0(-D_L36_001DD92C, D_L36_001DD92C))) * D_L36_001DD87C;
                v[1] = 0.0f;
                v[2] = func_0038D0B0(func_0038DB48(ang + func_003824E0(-D_L36_001DD92C, D_L36_001DD92C))) * D_L36_001DD87C;
                *(u8 **)((u8 *)s + off + 0x8C) = func_L36_00353F58(a0, v, i, func_003824E0(-D_L36_001DD930, D_L36_001DD930));
            }
        }
    }
    *(s16 *)(a0 + 0x7C) = *(u16 *)((u8 *)s + 0x80) & 0x3F;
}
