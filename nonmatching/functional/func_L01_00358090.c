/* functional: high. same reads/writes/calls; only register allocation and loop counter form differ */
extern u8 D_L01_00284320[];
extern u8 D_L01_002843C0[];
extern s32 D_L01_001E1A20[];
extern f32 D_001DD650_sda;
extern f32 D_001DD684_sda;
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);

void func_L01_00358090(u8 *a0) {
    u8 tmp[0x30] __attribute__((aligned(16)));
    u8 *obj = *(u8 **)(a0 + 0x68);
    u8 *pos = D_L01_00284320 + 0x10;
    u8 *goal = D_L01_002843C0 + 0x10;
    s32 i, k = 0;
    for (i = 8; i >= 0; i--) {
        if (D_001DD650_sda <= *(f32 *)(obj + 0x14)) {
            func_003C2F58((void *)D_L01_001E1A20[k], 0, tmp);
            vec_sub_ba(tmp + 0x10, pos, tmp);
            vec_sub_ba(tmp + 0x20, goal, tmp);
            func_0038CF68(tmp + 0x20, tmp + 0x20, *(f32 *)(obj + 0x14));
            func_0038CF68(tmp + 0x10, tmp + 0x10, *(f32 *)(obj + 0x14));
            if (*(f32 *)(tmp + 0x18) == 0.0f && *(f32 *)(tmp + 0x10) == 0.0f && *(f32 *)(tmp + 0x14) == 0.0f)
                *(vu0_q *)(tmp + 0x10) = *(vu0_q *)(tmp + 0x20);
            func_L01_0044C280(tmp + 0x20, tmp + 0x10, tmp + 0x20, 0, D_001DD684_sda + *(f32 *)(obj + 0x1C));
            vec_add_ab(pos, tmp, tmp + 0x20);
            if (func_L01_004CB2D8()) func_L01_004CAB30(pos, pos);
        } else {
            *(vu0_q *)pos = *(vu0_q *)goal;
            if (func_L01_004CB2D8()) func_L01_004CAB30(pos, pos);
        }
        goal += 0x10; pos += 0x10; k++;
    }
}
