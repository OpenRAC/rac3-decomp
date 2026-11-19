/* functional: high. Builds the Veldin 16-byte-stride list (table D_L01_002446C0, count at +0x740) from the 10-row table D_L01_002F1C20 (rows with +8 == 0xFF are skipped; rows whose id fails func_L01_004BB0F0 get their +8 word zeroed first) and configures the list-menu object (func_003B9BD0(0) is the menu object accessor): size 0x320, row count, colours/floats from D_L01_001DABAC.., then draws via func_L01_004C4E60. Returns the number of rows. The leftover byte D_L01_001DABB8 loaded into a1 for func_003BABB0 is ignored by the callee. Field meanings are mine. */
extern u8 D_L01_002F1C20[];
extern s32 D_L01_002F1CC0[];
extern u8 D_L01_002F1900[];
extern u8 D_0014279F;
extern u8 D_L01_001DABC8_sda;
extern u8 *D_L01_001DABCC_sda;
extern f32 D_L01_001DABAC_sda;
extern f32 D_L01_001DABB0_sda;
extern f32 D_L01_001DABB4_sda;
extern f32 D_L01_001DABBC_sda;
extern f32 D_L01_001DABC0_sda;
extern f32 D_L01_001DABC4_sda;

extern s32 func_00381CB0(void);
extern void func_L01_004BB120(u32);
extern s32 func_L01_004BB0F0(s32);
extern u8 *func_003B9BD0(s32);
extern s32 func_003B9E90(u8 *);
extern s32 func_003B9C68(void *, void *);
extern void func_003BABB0(s32 *, f32, f32, f32, f32, f32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_L01_004C4E60(void);

s32 func_L01_004BB140(void) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *p;
    s32 i;
    s32 j;
    s32 cnt;
    s32 v;
    u8 *r;

    D_L01_001DABC8_sda = 0;
    *(s32 *)(T + 0x740) = 0;
    func_00381CB0();
    D_L01_001DABCC_sda = T;
    if (D_0014279F != 0) {
        *(s32 *)(D_L01_002F1C20 + 0x68) = 0;
        func_L01_004BB120(10);
    }
    p = D_L01_002F1C20 + 8;
    for (i = 0; i < 10; i++) {
        if (func_L01_004BB0F0(*(s32 *)(p + 4)) != 0) {
            *(s32 *)p = 0;
        }
        p += 0x10;
    }
    for (j = 0; j < 10; j++) {
        v = *(s32 *)(D_L01_002F1C20 + j * 0x10 + 8);
        if (v == 0xFF) {
            continue;
        }
        cnt = *(s32 *)(T + 0x740);
        *(s32 *)(T + 0x148 + cnt * 0x10) = *(s32 *)(D_L01_002F1C20 + j * 0x10 + 0xC);
        *(s32 *)(T + 0x144 + cnt * 0x10) = v;
        *(s32 *)(T + 0x140 + cnt * 0x10) = 0;
        *(s32 *)(T + 0x14C + cnt * 0x10) = j;
        *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
    }
    r = func_003B9BD0(0);
    func_003B9E90(r);
    D_L01_002F1CC0[1] = (s32)D_L01_002F1900;
    D_L01_002F1CC0[0] = 0x320;
    D_L01_002F1CC0[3] = *(s32 *)(T + 0x740);
    r = func_003B9BD0(0);
    func_003B9C68(r, D_L01_002F1CC0);
    r = func_003B9BD0(0);
    func_003BABB0((s32 *)r, D_L01_001DABAC_sda, D_L01_001DABB0_sda, D_L01_001DABB4_sda,
                  D_L01_001DABBC_sda, D_L01_001DABC0_sda);
    r = func_003B9BD0(0);
    func_003BABD0(r, 0.5f, 0.77f, D_L01_001DABC4_sda, 0.12f);
    func_L01_004C4E60();
    return *(s32 *)(T + 0x740);
}
