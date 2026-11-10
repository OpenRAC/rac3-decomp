/* func_L23_004C2CE8: near miss (w3 p2w3). Ported from rac2 func_L22_002AA480 (animation stepper). Only remaining diffs: two div.s need 2 nops before (divs_nops),
   plus lbu 0x43/lw 0x24 allocation (/ swap) in anim-table index; everything else matches (27 diff rows = cascade of shift).
    */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[0x28]; void *anims[1]; } AnimTbl_004C2CE8;
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L23_00254D40[];
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D590(void *, void *);
extern void func_003C48A8(void *, void *);
extern void *func_L01_004DFCC8(void *, s32, s32, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);

void func_L23_004C2CE8(void) {
    char matrix[64] __attribute__((aligned(16)));
    u8 *g;
    u8 *p;
    if (D_001D545C == 0x17) {
        return;
    }
    g = D_001A4BE0;
    p = *(u8 **)(g + 0xBF8);
    p[0x6F] = 0;
    if ((*(u8 *)(*(u8 **)(g + 0x25C0) + 0x34) ^ 1) & 1) {
        func_003C2EC0(*(void **)(g + 0x25C0), 5, matrix);
        *(u128_t *)(p + 0x10) = *(u128_t *)(matrix + 0x30);
        func_0038D590(p + 0xC0, matrix);
        func_003C48A8(p + 0xC0, p + 0xF0);
        *(u16 *)(p + 0x34) &= 0xFFBE;
        if (*(u8 *)(p + 0x43) != 0x65) {
            u8 *buf = D_L23_00254D40;
            p[0x40] = 1;
            p[0x42] = 0x65;
            p[0x43] = 0x65;
            *(void **)(p + 0x58) = func_L01_004DFCC8(p, 0x65, 1, buf);
            *(void **)(p + 0x5C) = func_L01_004DFCC8(p, *(u8 *)(p + 0x43), *(u8 *)(p + 0x41), buf + 0x600);
        } else if (*(u8 *)(p + 0x42) == *(u8 *)(p + 0x43)) {
            *(float *)(p + 0x44) += *(float *)(p + 0x48) * *(float *)(p + 0x4C);
        } else {
            *(float *)(p + 0x44) += *(float *)(p + 0x4C);
        }
        if (*(float *)(p + 0x44) >= 1.0f) {
            u8 *buf = D_L23_00254D40;
            p[0x40] = p[0x41];
            *(void **)(p + 0x58) = buf;
            func_0038CC88(buf, buf + 0x600, 0x600);
            ++*(u8 *)(p + 0x41);
            if (*(u8 *)(p + 0x41) >= *(u8 *)(*(u8 **)(*(u8 **)(p + 0x24) + 0x48 + *(u8 *)(p + 0x43) * 4) + 0x10))
                p[0x41] = 0;
            *(void **)(p + 0x5C) = func_L01_004DFCC8(p, *(u8 *)(p + 0x43), *(u8 *)(p + 0x41), buf + 0x600);
            *(float *)(p + 0x44) = (*(float *)(p + 0x44) - 1.0f) / *(float *)(p + 0x4C);
            *(float *)(p + 0x4C) = **(float **)(p + 0x58);
            *(float *)(p + 0x44) *= *(float *)(p + 0x4C);
        }
        func_003C7C38(p);
    } else {
        *(u16 *)(p + 0x34) |= 0x41;
    }
}
